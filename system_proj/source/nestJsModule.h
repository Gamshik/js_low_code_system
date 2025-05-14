#define _CRT_SECURE_NO_WARNINGS

#ifndef NESTJSMODULE_H
#define NESTJSMODULE_H

#include "nestJsServiceFile.h"
#include "nestJsControllerFile.h"
#include "nestJsModuleFile.h"
#include "stringHelper.h"

class NestJsModule
{
private:
    NestJsServiceFile* _service_file;
    NestJsControllerFile* _controller_file;
    NestJsModuleFile* _module_file;

    char* _name;
    char* _proj_root_dir_path;

    char* _service_file_path;
    char* _controller_file_path;
    char* _module_file_path;

public:
    NestJsModule(const char* name, const char* projRootDirPath):
        _service_file(nullptr),
        _controller_file(nullptr),
        _module_file(nullptr)
    {
        _name = StringHelper::Duplicate_String(name);
        if (!_name) throw std::bad_alloc();

        _proj_root_dir_path = StringHelper::Duplicate_String(projRootDirPath);
        if (!_proj_root_dir_path) throw std::bad_alloc();

        char* name_camel_case = StringHelper::To_lower_case_first_letter(_name);

        const char* modules_path = "/modules/";
        const char* slash = "/";
        size_t module_dir_len = strlen(_proj_root_dir_path) + strlen(modules_path) + strlen(name_camel_case) + strlen(slash) + 1;
        char* module_dir = (char*)malloc(module_dir_len);

        module_dir[0] = '\0';
        strcat(module_dir, _proj_root_dir_path);
        strcat(module_dir, modules_path);
        strcat(module_dir, name_camel_case);
        strcat(module_dir, slash);

        const char* service_suffix = ".service.ts";
        const char* controller_suffix = ".controller.ts";
        const char* module_suffix = ".module.ts";

        size_t service_path_len = strlen(module_dir) + strlen(name_camel_case) + strlen(service_suffix) + 1;
        _service_file_path = (char*)malloc(service_path_len);

        _service_file_path[0] = '\0';
        strcat(_service_file_path, module_dir);
        strcat(_service_file_path, name_camel_case);
        strcat(_service_file_path, service_suffix);

        size_t controller_path_len = strlen(module_dir) + strlen(name_camel_case) + strlen(controller_suffix) + 1;
        _controller_file_path = (char*)malloc(controller_path_len);

        _controller_file_path[0] = '\0';
        strcat(_controller_file_path, module_dir);
        strcat(_controller_file_path, name_camel_case);
        strcat(_controller_file_path, controller_suffix);

        size_t module_path_len = strlen(module_dir) + strlen(name_camel_case) + strlen(module_suffix) + 1;
        _module_file_path = (char*)malloc(module_path_len);

        _module_file_path[0] = '\0';
        strcat(_module_file_path, module_dir);
        strcat(_module_file_path, name_camel_case);
        strcat(_module_file_path, module_suffix);

        free(name_camel_case);
        free(module_dir);

        _service_file = new NestJsServiceFile(name);
        _controller_file = new NestJsControllerFile(name, name);
        _module_file = new NestJsModuleFile(name);
    }
    NestJsModule() : NestJsModule("", "")
    {}
    virtual ~NestJsModule()
    {
        delete _service_file;
        delete _controller_file;
        delete _module_file;

        free(_name);
        free(_proj_root_dir_path);
        free(_service_file_path);
        free(_controller_file_path);
        free(_module_file_path);
    }

    void createModule()
    {
        _service_file->createFile(_service_file_path);
        _controller_file->createFile(_controller_file_path);
        _module_file->createFile(_module_file_path);
    }
};

#endif // NESTJSMODULE_H
