#include <QCoreApplication>

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


    mainWnd->show();

    return a.exec();
}
