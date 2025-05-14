//// ----- QT ELEMENTS -----
//#include "QApplication"
//#include "QObject"
//#include "QGridLayout"
//#include "QTextEdit"
//#include "QPushButton"
//#include "QVBoxLayout"
//#include "QLabel"
//#include "QMessageBox"
//
//// ----- BUILT-IN LIBRARY -----
//
//#include "iostream"
//#include "fstream"
//#include "filesystem"
//
//// ----- PROJECT CLASSES -----
//
//#include "mainWindow.h"
//#include "nestJsProjectCreator.h"
//
//using namespace std;
//namespace fs = std::filesystem;
//
//MainWindow *mainWnd;
//NestJsProjectCreator *nestJsProjectCreator;
//
//// ----- LAYOUTS -----
//
//QGridLayout *mainLayout;
//QGridLayout *projNameInputLayout;
//QGridLayout *projRootDirInputLayout;
//
//// ----- COMPONENTS -----
//
//QPushButton *createProjBtn;
//QTextEdit *projNameTxtEditor;
//QTextEdit *projRootDirTxtEditor;
//
//// ----- ON EVENT FUNCTIONS -----
//
//void onCreateProjBtnClick();
//void onProjRootDirTxtEditorChange();
//void onProjNameTxtEditorChange();
//
//// ---- FUNCTIONS -----
//
//QString strToQString(string str);
//void showMessageBox(QString text);
//void createPackageJsonFile();
//
//// ----- CONSTANTS -----
//
//const string fileInstancesDirPath = "../../../file_instances/";
//
//const string tsConfBuildInstanceFilePath = fileInstancesDirPath + "tsconfig.build.json.txt";
//const string nestCliConfInstanceFilePath = fileInstancesDirPath + "nest-cli.json.txt";
//
//const string serviceInstanceFilePath = fileInstancesDirPath + "app.service.ts.txt";
//const string controllerInstanceFilePath = fileInstancesDirPath + "app.controller.ts.txt";
//const string moduleInstanceFilePath = fileInstancesDirPath + "app.module.ts.txt";
//
//const string mainInstanceFilePath = fileInstancesDirPath + "main.ts.txt";
//
//// ----- VARIABLES -----
//
//QString projRootDirName;
//QString projName;
//
//
//
//int main(int argc, char *argv[])
//{
//    // -------------------------- INIT/CREATE --------------------------
//    QApplication a(argc, argv);
//
//    QSize wndSize{600, 500};
//
//    mainWnd = new MainWindow(wndSize, "Js Low Code");
//
//    mainLayout = new QGridLayout(mainWnd);
//    projNameInputLayout = new QGridLayout();
//    projRootDirInputLayout = new QGridLayout();
//
//    QLabel *projNameInputLabel = new QLabel(QString::fromStdString("Project name*:"));
//    QLabel *projRootDirInputLabel = new QLabel(QString::fromStdString("Project root directory name*:"));
//
//    createProjBtn = new QPushButton("Ctreate proj");
//
//    projRootDirTxtEditor = new QTextEdit();
//
//    projNameTxtEditor = new QTextEdit();
//
//
//    // -------------------------- ACTION BINDING --------------------------
//
//    QObject::connect(createProjBtn, QPushButton::clicked, onCreateProjBtnClick);
//    QObject::connect(projNameTxtEditor, QTextEdit::textChanged, onProjNameTxtEditorChange);
//    QObject::connect(projRootDirTxtEditor, QTextEdit::textChanged, onProjRootDirTxtEditorChange);
//
//
//
//    // -------------------------- VIEW STYLE --------------------------
//
//    projNameInputLabel->setMaximumHeight(30);
//
//    projNameTxtEditor->setMaximumHeight(30);
//    projNameTxtEditor->setMaximumWidth(200);
//
//    projNameInputLayout->setVerticalSpacing(15);
//
//    projRootDirInputLabel->setMaximumHeight(30);
//
//    projRootDirTxtEditor->setMaximumHeight(30);
//    projRootDirTxtEditor->setMaximumWidth(200);
//
//    projRootDirInputLayout->setVerticalSpacing(15);
//
//    createProjBtn->setMinimumHeight(30);
//
//    // mainWnd->setStyleSheet("QWidget {border : 2px solid red}");
//
//
//
//    // -------------------------- PLACEMENT ELEMENTS --------------------------
//
//    projNameInputLayout->addWidget(projNameInputLabel);
//    projNameInputLayout->addWidget(projNameTxtEditor);
//
//    projRootDirInputLayout->addWidget(projRootDirInputLabel);
//    projRootDirInputLayout->addWidget(projRootDirTxtEditor);
//
//    mainLayout->addLayout(projNameInputLayout, 0, 0);
//    mainLayout->addLayout(projRootDirInputLayout, 1, 0);
//    mainLayout->addWidget(createProjBtn, 2, 0);
//
//
//
//    // -------------------------- START --------------------------
//
//    mainWnd->show();
//
//    return a.exec();
//}
//
//void onCreateProjBtnClick()
//{
//    if (projName.length() < 1 || projRootDirName.length() < 1)
//    {
//        showMessageBox(strToQString("All field is required"));
//        return;
//    }
//
//    try
//    {
//        nestJsProjectCreator = new NestJsProjectCreator("D:/LOW_CODE/", projName.toStdString(), projRootDirName.toStdString());
//
//        nestJsProjectCreator->addModule("Gleb");
//        nestJsProjectCreator->addModule("Test");
//
//        nestJsProjectCreator->createProject();
//
//        showMessageBox(strToQString("Project " + projName.toStdString() + " is created"));
//    } catch(exception &exception)
//    {
//        showMessageBox(QString("Something went wront: %1").arg(exception.what()));
//    }
//}
//
//void onProjRootDirTxtEditorChange()
//{
//    projRootDirName = projRootDirTxtEditor->toPlainText();
//}
//
//void onProjNameTxtEditorChange()
//{
//    projName = projNameTxtEditor->toPlainText();
//}
//
//QString strToQString(string str)
//{
//    return QString::fromStdString(str);
//}
//
//void showMessageBox(QString text)
//{
//    QMessageBox msgBox;
//
//    msgBox.setText(text);
//    msgBox.exec();
//}
