#ifndef NESTJSMAINMODULEFILE_H
#define NESTJSMAINMODULEFILE_H

#include "nestJsProjectFile.h"
#include "stringHelper.h"

#include "iostream"

using namespace std;

class NestJsMainModuleFile : public NestJsProjectFile
{
private:
    const string IMPORT_MODULE_INSTANCE_FILE_PATH;

    const string NAME_VARIABLE_PATTERN = "{moduleName}";
    const string IMPORT_MODULES_VARIABLE_PATTERN = "{importModules}";
    const string MODULES_LIST_VARIABLE_PATTERN = "{modulesList}";

    const string MODULE_NAME_VARIABLE_PATTERN = "{moduleName}";
    const string MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{moduleNameCamelCase}";

    string _name;
    vector<string> _modulesName;

public:
    NestJsMainModuleFile(string name):
        _name(name),
        _modulesName(0),
        IMPORT_MODULE_INSTANCE_FILE_PATH(INSTANCES_DIR_PATH+"importModule.txt"),
        NestJsProjectFile("mainModule.ts.txt")
    {}
    virtual ~NestJsMainModuleFile() {}

    void addModule(string name)
    {
        _modulesName.push_back(name);
    }
    void createFile(string path)
    {
        string importModulePattern = FileSystemProvider::readFile(IMPORT_MODULE_INSTANCE_FILE_PATH);
        string fileContent = FileSystemProvider::readFile(INSTANCE_FILE_PATH);

        fileContent = StringHelper::setVariableInText(NAME_VARIABLE_PATTERN, _name, fileContent);

        string importModules = "";
        string modulesList = "";
        unsigned int countModules = _modulesName.size();

        for (unsigned int i = 0; i < countModules; i++)
        {
            string currentModuleName = _modulesName[i];

            importModules += StringHelper::setVariableInText(MODULE_NAME_VARIABLE_PATTERN, currentModuleName, importModulePattern);
            importModules = StringHelper::setVariableInText(MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN, StringHelper::toLowerCaseFirstLetter(currentModuleName), importModules);

            modulesList += currentModuleName + "Module,";

            if (i < countModules - 1) {
                modulesList += "\n\t\t";
            }
        }

        fileContent = StringHelper::setVariableInText(IMPORT_MODULES_VARIABLE_PATTERN, importModules, fileContent);
        fileContent = StringHelper::setVariableInText(MODULES_LIST_VARIABLE_PATTERN, modulesList, fileContent);

        FileSystemProvider::createFile(path, fileContent);
    }
};

#endif // NESTJSMAINMODULEFILE_H
