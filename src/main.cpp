#include <QApplication>
#include <QPushButton>
#include <QObject>

#include <iostream>
#include <fstream>
#include <filesystem>

#include <mainWindow.h>

using namespace std;
namespace fs = std::filesystem;

MainWindow *mainWnd;
QPushButton *createProjBtn;

void createEmptyNestJsProj();
string readFile(string path);
void createFile(string path, string content);
void createParentDirectoriesIfNotExist(string path);

const string fileInstancesFolderPath = "../../../file_instances/";
const string serviceInstanceFilePath = fileInstancesFolderPath + "app.service.ts.txt";
const string controllerInstanceFilePath = fileInstancesFolderPath + "app.controller.ts.txt";
const string moduleInstanceFilePath = fileInstancesFolderPath + "app.module.ts.txt";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize wndSize{600, 500};

    mainWnd = new MainWindow(wndSize, "Js Low Code");

    createProjBtn = new QPushButton("Ctreate proj", mainWnd);

    QSize createProjBtnSize{100, 50};

    int createProjBtnXPos = (wndSize.width() / 2) - (createProjBtnSize.width() / 2);
    int createProjBtnYPos = (wndSize.height() / 2) - (createProjBtnSize.height() / 2);

    createProjBtn->setGeometry(createProjBtnXPos, createProjBtnYPos, createProjBtnSize.width(), createProjBtnSize.height());

    QObject::connect(createProjBtn, QPushButton::clicked, createEmptyNestJsProj);

    mainWnd->show();

    return a.exec();
}

void createEmptyNestJsProj()
{
    string serviceFileContent = readFile(serviceInstanceFilePath);
    string controllerFileContent = readFile(serviceInstanceFilePath);
    string moduleFileContent = readFile(serviceInstanceFilePath);

    string projFolderPath = "../../../nest/src/";
    string serviceFilePath = projFolderPath + "app.service.ts";
    string controllerFilePath = projFolderPath + "app.controller.ts";
    string moduleFilePath = projFolderPath + "app.module.ts";

    createFile(serviceFilePath, serviceFileContent);
    createFile(controllerFilePath, controllerFileContent);
    createFile(moduleFilePath, moduleFileContent);
}

string readFile(string path)
{
    string fileContent;

    string contentLine;

    ifstream file(path);

    if (file.is_open())
    {
        while(getline(file, contentLine))
            fileContent += contentLine + '\n';
    }

    file.close();

    return fileContent;
}

void createFile(string path, string content)
{
    createParentDirectoriesIfNotExist(path);

    ofstream file;

    file.open(path, ios::out);

    if (file.is_open())
        file << content;

    file.close();
}

void createParentDirectoriesIfNotExist(string path)
{
    fs::path filePath(path);

    if (!filePath.parent_path().empty())
    {
        fs::create_directories(filePath.parent_path());
    }

}
