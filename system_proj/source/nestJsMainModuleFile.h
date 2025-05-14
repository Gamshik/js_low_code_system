#define _CRT_SECURE_NO_WARNINGS

#ifndef NESTJSMAINMODULEFILE_H
#define NESTJSMAINMODULEFILE_H

#include <vector>

#include "nestJsProjectFile.h"
#include "stringHelper.h"

using namespace std;

class NestJsMainModuleFile : public NestJsProjectFile
{
private:
    const char* NAME_VARIABLE_PATTERN = "{moduleName}";
    const char* IMPORT_MODULES_VARIABLE_PATTERN = "{importModules}";
    const char* MODULES_LIST_VARIABLE_PATTERN = "{modulesList}";

    const char* MODULE_NAME_VARIABLE_PATTERN = "{moduleName}";
    const char* MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{moduleNameCamelCase}";

    char* _name;
    char* import_module_instance_file_path;

    vector<const char*> _modulesName;

public:
    NestJsMainModuleFile(const char* name):
        _modulesName(0),
        NestJsProjectFile("mainModule.ts.txt")
    {
        _name = StringHelper::Duplicate_String(name);
        if (!_name) throw std::bad_alloc();

        const char* instanceFilePath = "importModule.txt";
        size_t pathLength = strlen(INSTANCES_DIR_PATH) + strlen(instanceFilePath) + 1;
        import_module_instance_file_path = (char*)malloc(pathLength);

        strcpy(import_module_instance_file_path, INSTANCES_DIR_PATH);
        strcat(import_module_instance_file_path, instanceFilePath);
    }
    virtual ~NestJsMainModuleFile() 
    {
        free(_name);
        free(import_module_instance_file_path);
    }

    void addModule(const char* name)
    {
        _modulesName.push_back(name);
    }
    void createFile(const char* path)
    {
        char* import_module_pattern = FileSystemProvider::Read_File(import_module_instance_file_path);
        char* file_content = FileSystemProvider::Read_File(instance_file_path);

        char* temp_content = StringHelper::Set_variable_in_text(NAME_VARIABLE_PATTERN, _name, file_content);

        free(file_content);

        file_content = temp_content;
        
        char* import_modules = (char*)malloc(1);
        import_modules[0] = '\0';

        char* modules_list = (char*)malloc(1);
        modules_list[0] = '\0';

        unsigned int count_modules = _modulesName.size();

        for (unsigned int i = 0; i < count_modules; i++)
        {
            const char* current_module_name = _modulesName[i];

            char* temp_import = StringHelper::Set_variable_in_text(MODULE_NAME_VARIABLE_PATTERN, current_module_name, import_module_pattern);

            size_t new_import_len = strlen(import_modules) + strlen(temp_import) + 1;
            char* new_import_modules = (char*)realloc(import_modules, new_import_len);

            import_modules = new_import_modules;
            strcat(import_modules, temp_import);

            free(temp_import);

            char* lower_module_name = StringHelper::To_lower_case_first_letter(current_module_name);

            temp_import = StringHelper::Set_variable_in_text(MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN, lower_module_name, import_modules);

            free(lower_module_name);

            new_import_len = strlen(temp_import) + 1;
            new_import_modules = (char*)realloc(import_modules, new_import_len);

            import_modules = new_import_modules;
            strcat(import_modules, temp_import);

            free(temp_import);

            const char* suffix = (i < count_modules - 1) ? "Module,\n\t\t" : "Module,";
            size_t new_list_len = strlen(modules_list) + strlen(current_module_name) + strlen(suffix) + 1;
            char* new_modules_list = (char*)realloc(modules_list, new_list_len);

            modules_list = new_modules_list;
            strcat(modules_list, current_module_name);
            strcat(modules_list, suffix);
        }

        temp_content = StringHelper::Set_variable_in_text(IMPORT_MODULES_VARIABLE_PATTERN, import_modules, file_content);

        free(file_content);

        file_content = temp_content;

        temp_content = StringHelper::Set_variable_in_text(MODULES_LIST_VARIABLE_PATTERN, modules_list, file_content);

        free(file_content);

        file_content = temp_content;

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
        free(import_modules);
        free(modules_list);
        free(import_module_pattern);
    }
};

#endif // NESTJSMAINMODULEFILE_H
