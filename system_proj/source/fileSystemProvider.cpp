#define _CRT_SECURE_NO_WARNINGS

#include "fileSystemProvider.h"

BOOL FileSystemProvider::Create_Directory_If_Not_Exist(char* path)
{
    if (!CreateDirectoryA(path, NULL)) {
        DWORD err = GetLastError();

        if (err != ERROR_ALREADY_EXISTS)
            return FALSE;
    }

    return TRUE;
}

BOOL FileSystemProvider::Create_Directories_If_Not_Exist_Recursively(char* path)
{
    char temp[MAX_PATH];
    strcpy_s(temp, path);

    size_t len = strlen(temp);

    if (temp[len - 1] == '\\' || temp[len - 1] == '/')
        temp[len - 1] = '\0';

    for (char* symbol = temp; *symbol; symbol++) {
        if (*symbol == '\\' || *symbol == '/') {
            char old_symbol = *symbol;

            *symbol = '\0';

            if (!Create_Directory_If_Not_Exist(temp)) 
                return FALSE;

            *symbol = old_symbol;
        }
    }

    return TRUE;
}

char* FileSystemProvider::Read_Instance_File(char* name)
{
    size_t pathLegth = strlen(INSTANCE_FILES_DIR) + strlen(name) + 1;
    char* full_path = (char*)malloc(pathLegth);

    strcpy(full_path, INSTANCE_FILES_DIR);
    strcat(full_path, name);

    HANDLE hFile = CreateFileA(
        full_path, 
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_READONLY,
        NULL
    );

    free(full_path);

    if (hFile == INVALID_HANDLE_VALUE)
        return nullptr;

    DWORD file_size = GetFileSize(hFile, nullptr);

    if (file_size == INVALID_FILE_SIZE) {
        CloseHandle(hFile);
        return nullptr;
    }

    char* buffer = (char*)malloc(file_size + 1);

    if (!buffer) {
        CloseHandle(hFile);
        return nullptr;
    }

    DWORD bytes_read;

    BOOL read_result = ReadFile(
        hFile,
        buffer,
        file_size,
        &bytes_read,
        nullptr
    );

    if (!read_result || bytes_read != file_size) {
        free(buffer);
        CloseHandle(hFile);
        return nullptr;
    }

    CloseHandle(hFile);

    buffer[file_size] = '\0';
    return buffer;
}

BOOL FileSystemProvider::Create_File(char* path, char* content)
{
    char temp_path[MAX_PATH];
    strcpy_s(temp_path, path);

    size_t len = strlen(temp_path);

    for (char* symbol = &temp_path[len - 1]; *symbol; symbol--) {
        if (*symbol == '\\' || *symbol == '/') {
            char old_symbol = *symbol;

            *symbol = '\0';

            if (!Create_Directories_If_Not_Exist_Recursively(temp_path))
                return FALSE;
            *symbol = old_symbol;
            break;
        }
    }

    HANDLE hFile = CreateFileA(
        path,
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_WRITE,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    DWORD err = GetLastError();

    if (hFile == INVALID_HANDLE_VALUE || (err != 0 && err != ERROR_ALREADY_EXISTS))
        return FALSE;

    size_t content_size = strlen(content);
    DWORD writed_bytes;

    BOOL result = WriteFile(
        hFile,
        content,
        (DWORD)content_size,
        &writed_bytes,
        nullptr
    );

    if (!result) {
        CloseHandle(hFile);
        return FALSE;
    }

    CloseHandle(hFile);
    return TRUE;
}
