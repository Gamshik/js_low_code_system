#include <QApplication>
#include <QObject>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

#include <iostream>
#include <fstream>
#include <filesystem>

#include <mainWindow.h>

using namespace std;
namespace fs = std::filesystem;

MainWindow *mainWnd;

// ----- LAYOUTS -----

QGridLayout *mainLayout;
QGridLayout *projNameInputLayout;
QGridLayout *projRootDirInputLayout;

// ----- COMPONENTS -----

QPushButton *createProjBtn;
QTextEdit *projNameTxtEditor;
QTextEdit *projRootDirTxtEditor;

// ----- ON EVENT FUNCTIONS -----

void onCreateProjBtnClick();
void onProjRootDirTxtEditorChange();
void onProjNameTxtEditorChange();

// ---- FUNCTIONS -----

string readFile(string path);
void createFile(string path, string content);
void createParentDirectoriesIfNotExist(string path);
string setVariableInText(string varName, string varPattern, string varVal, string txt);
QString strToQString(string str);

// ----- CONSTANTS -----

const string fileInstancesDirPath = "../../../file_instances/";

const string packageJsonInstanceFilePath = fileInstancesDirPath + "package.json.txt";
const string tsConfInstanceFilePath = fileInstancesDirPath + "tsconfig.json.txt";
const string tsConfBuildInstanceFilePath = fileInstancesDirPath + "tsconfig.build.json.txt";
const string nestCliConfInstanceFilePath = fileInstancesDirPath + "nest-cli.json.txt";

const string serviceInstanceFilePath = fileInstancesDirPath + "app.service.ts.txt";
const string controllerInstanceFilePath = fileInstancesDirPath + "app.controller.ts.txt";
const string moduleInstanceFilePath = fileInstancesDirPath + "app.module.ts.txt";

const string mainInstanceFilePath = fileInstancesDirPath + "main.ts.txt";

// ----- VARIABLES -----

QString projRootDirName;
QString projName;



int main(int argc, char *argv[])
{
    // -------------------------- INIT/CREATE --------------------------
    QApplication a(argc, argv);

    QSize wndSize{600, 500};

    mainWnd = new MainWindow(wndSize, "Js Low Code");

    mainLayout = new QGridLayout(mainWnd);
    projNameInputLayout = new QGridLayout();
    projRootDirInputLayout = new QGridLayout();

    QLabel *projNameInputLabel = new QLabel(QString::fromStdString("Project name*:"));
    QLabel *projRootDirInputLabel = new QLabel(QString::fromStdString("Project root directory name*:"));

    createProjBtn = new QPushButton("Ctreate proj");

    projRootDirTxtEditor = new QTextEdit();

    projNameTxtEditor = new QTextEdit();



    // -------------------------- ACTION BINDING --------------------------

    QObject::connect(createProjBtn, QPushButton::clicked, onCreateProjBtnClick);
    QObject::connect(projNameTxtEditor, QTextEdit::textChanged, onProjNameTxtEditorChange);
    QObject::connect(projRootDirTxtEditor, QTextEdit::textChanged, onProjRootDirTxtEditorChange);



    // -------------------------- VIEW STYLE --------------------------

    projNameInputLabel->setMaximumHeight(30);

    projNameTxtEditor->setMaximumHeight(30);
    projNameTxtEditor->setMaximumWidth(200);

    projNameInputLayout->setVerticalSpacing(15);

    projRootDirInputLabel->setMaximumHeight(30);

    projRootDirTxtEditor->setMaximumHeight(30);
    projRootDirTxtEditor->setMaximumWidth(200);

    projRootDirInputLayout->setVerticalSpacing(15);

    createProjBtn->setMinimumHeight(30);

    // mainWnd->setStyleSheet("QWidget {border : 2px solid red}");



    // -------------------------- PLACEMENT ELEMENTS --------------------------

    projNameInputLayout->addWidget(projNameInputLabel);
    projNameInputLayout->addWidget(projNameTxtEditor);

    projRootDirInputLayout->addWidget(projRootDirInputLabel);
    projRootDirInputLayout->addWidget(projRootDirTxtEditor);

    mainLayout->addLayout(projNameInputLayout, 0, 0);
    mainLayout->addLayout(projRootDirInputLayout, 1, 0);
    mainLayout->addWidget(createProjBtn, 2, 0);



    // -------------------------- START --------------------------

    mainWnd->show();

    return a.exec();
}

void onCreateProjBtnClick()
{
    QMessageBox msgBox;

    if (projName.length() < 1 || projRootDirName.length() < 1)
    {
        msgBox.setText("All field is required");
        msgBox.exec();

        return;

    }

    try
    {
        string packageJsonConfFileContent = readFile(packageJsonInstanceFilePath);
        string tsConfFileContent = readFile(tsConfInstanceFilePath);
        string tsConfBuildFileContent = readFile(tsConfBuildInstanceFilePath);
        string nestCliConfFileContent = readFile(nestCliConfInstanceFilePath);

        string serviceFileContent = readFile(serviceInstanceFilePath);
        string controllerFileContent = readFile(controllerInstanceFilePath);
        string moduleFileContent = readFile(moduleInstanceFilePath);

        string mainFileContent = readFile(mainInstanceFilePath);

        packageJsonConfFileContent = setVariableInText("projName", "{%v}", projName.toStdString(), packageJsonConfFileContent);
        packageJsonConfFileContent = setVariableInText("rootDir", "{%v}", projRootDirName.toStdString(), packageJsonConfFileContent);
        nestCliConfFileContent = setVariableInText("rootDir", "{%v}", projRootDirName.toStdString(), nestCliConfFileContent);

        string projFolderPath = "../../../" + projName.toStdString() + "/";
        string projRootDirPath = projFolderPath + projRootDirName.toStdString() + "/";

        string serviceFilePath = projRootDirPath + "app.service.ts";
        string controllerFilePath = projRootDirPath + "app.controller.ts";
        string moduleFilePath = projRootDirPath + "app.module.ts";
        string mainFilePath = projRootDirPath + "main.ts";

        string packageJsonConfFilePath = projFolderPath + "package.json";
        string tsConfFilePath = projFolderPath + "tsconfig.json";
        string tsConfBuildFilePath = projFolderPath + "tsconfig.build.json";
        string nestCliConfFilePath = projFolderPath + "nest-cli.json";

        createFile(serviceFilePath, serviceFileContent);
        createFile(controllerFilePath, controllerFileContent);
        createFile(moduleFilePath, moduleFileContent);

        createFile(mainFilePath, mainFileContent);

        createFile(packageJsonConfFilePath, packageJsonConfFileContent);
        createFile(tsConfFilePath, tsConfFileContent);
        createFile(tsConfBuildFilePath, tsConfBuildFileContent);
        createFile(nestCliConfFilePath, nestCliConfFileContent);

        msgBox.setText(strToQString("Project " + projName.toStdString() + " is created"));
        msgBox.exec();
    } catch(exception &exception)
    {
        msgBox.setText(QString("Something went wront: %1").arg(exception.what()));
        msgBox.exec();
    }
}

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

QString strToQString(string str)
{
    return QString::fromStdString(str);
}
