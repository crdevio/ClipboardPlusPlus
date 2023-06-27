#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <stdio.h>
#include <QTimer>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    std::string getClipBoardData();
    void type(char p);
    ~MainWindow();

public slots:
    void mainLoop();
    void onElementClicked(QListWidgetItem*);

private slots:
    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    bool running;
    std::string last;
    QTimer* timerAction;
    QListWidgetItem* lastWid;

};
#endif // MAINWINDOW_H
