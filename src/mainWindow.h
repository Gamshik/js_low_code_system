#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Qwidget>
#include <QString>
#include <QSize>

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    void _setWndSize(int width, int height) {
        setMinimumSize(width, height);
        setMaximumSize(width, height);
    }

public:
    MainWindow(QWidget *parent = nullptr): QWidget(parent) {}
    MainWindow(QString title, QWidget *parent = nullptr): QWidget(parent)
    {
        setWindowTitle(title);
    }
    MainWindow(int width, int height, QWidget *parent = nullptr): QWidget(parent)
    {
        _setWndSize(width, height);
    }
    MainWindow(int width, int height, QString title, QWidget *parent = nullptr): QWidget(parent)
    {
        _setWndSize(width, height);

        setWindowTitle(title);
    }
    MainWindow(QSize size, QString title, QWidget *parent = nullptr): QWidget(parent)
    {
        _setWndSize(size.width(), size.height());

        setWindowTitle(title);
    }
    virtual ~MainWindow() {}
};

#endif // MAINWINDOW_H
