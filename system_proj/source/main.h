#ifndef MAIN_H
#define MAIN_H

#include "iostream"

#include "nestJsProjectCreator.h"

NestJsProjectCreator* nest_proj_creator;

const char* ts_conf_build_inst_file_name = "tsconfig.build.json.txt";
const char* nest_cli_conf_inst_file_name = "nest-cli.json.txt";

const char* service_inst_file_name = "app.service.ts.txt";
const char* controller_inst_file_name = "app.controller.ts.txt";
const char* module_inst_file_name = "app.module.ts.txt";

const char* main_inst_file_name = "main.ts.txt";

#endif // MAIN_H