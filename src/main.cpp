#include <QApplication>
#include <QObject>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>

#include <iostream>
#include <fstream>
#include <filesystem>

#include <mainWindow.h>

using namespace std;
namespace fs = std::filesystem;

MainWindow *mainWnd;

QGridLayout *mainGridLayout;
QPushButton *createProjBtn;
QTextEdit *projNameTxtEditor;
QTextEdit *projRootDirTxtEditor;

void onCreateProjBtnClick();
void onProjRootDirTxtEditorChange();
void onProjNameTxtEditorChange();

string readFile(string path);
void createFile(string path, string content);
void createParentDirectoriesIfNotExist(string path);
string setVariableInText(string varName, string varPattern, string varVal, string txt);

const string fileInstancesFolderPath = "../../../file_instances/";
const string serviceInstanceFilePath = fileInstancesFolderPath + "app.service.ts.txt";
const string controllerInstanceFilePath = fileInstancesFolderPath + "app.controller.ts.txt";
const string moduleInstanceFilePath = fileInstancesFolderPath + "app.module.ts.txt";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize wndSize{600, 500};

    mainWnd = new MainWindow(wndSize, "Js Low Code");

    mainGridLayout = new QGridLayout(mainWnd);

    createProjBtn = new QPushButton("Ctreate proj");

    projRootDirTxtEditor = new QTextEdit();

    projRootDirTxtEditor->setMaximumHeight(30);
    projRootDirTxtEditor->setMaximumWidth(200);

    projNameTxtEditor = new QTextEdit();

    projNameTxtEditor->setMaximumHeight(30);
    projNameTxtEditor->setMaximumWidth(200);

    QObject::connect(createProjBtn, QPushButton::clicked, onCreateProjBtnClick);
    QObject::connect(projNameTxtEditor, QTextEdit::textChanged, onProjNameTxtEditorChange);
    QObject::connect(projRootDirTxtEditor, QTextEdit::textChanged, onProjRootDirTxtEditorChange);

    mainGridLayout->addWidget(projNameTxtEditor);
    mainGridLayout->addWidget(projRootDirTxtEditor);
    mainGridLayout->addWidget(createProjBtn);

    mainWnd->show();

    return a.exec();
}

void onCreateProjBtnClick()
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
void onProjRootDirTxtEditorChange()
{
    projRootDirName = projRootDirTxtEditor->toPlainText();
}

void onProjNameTxtEditorChange()
{
    projName = projNameTxtEditor->toPlainText();
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

string setVariableInText(string varName, string varPattern, string varVal, string txt)
{
    QString pattern = QString::fromStdString(varPattern);

    pattern.replace(QString::fromStdString("%v"), QString::fromStdString(varName));

    QString qTxt = QString::fromStdString(txt);

    qTxt.replace(pattern, QString::fromStdString(varVal));

    return qTxt.toStdString();
}
