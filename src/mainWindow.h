#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Qwidget>
#include <QString>
#include <QSize>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr): QWidget(parent) {}
    MainWindow(QString title, QWidget *parent = nullptr): QWidget(parent) {
        this->setWindowTitle(title);
    }
    MainWindow(int width, int height, QWidget *parent = nullptr): QWidget(parent) {
        this->setWndSize(width, height);
    }
    MainWindow(int width, int height, QString title, QWidget *parent = nullptr): QWidget(parent) {
        this->setWndSize(width, height);

        this->setWindowTitle(title);
    }
    MainWindow(QSize size, QString title, QWidget *parent = nullptr): QWidget(parent) {
        this->setWndSize(size.width(), size.height());

        this->setWindowTitle(title);
    }
    virtual ~MainWindow() {}

private:
    void setWndSize(int width, int height) {
        this->setMinimumSize(width, height);
        this->setMaximumSize(width, height);
    }
};

#endif // MAINWINDOW_H
