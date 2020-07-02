#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"cspfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CSpFile myfile;
    string city;
//    int xCoordinate;//通过城市名称查到的坐标
//    int yCoordinate;
    bool findcitycoordinate;
//    string cityname;//通过坐标查到的城市名称
    bool findcityname;
private slots:
     void on_importData_clicked();

     void on_confirmSearching_clicked();

     //void on_confirmSearching_2_clicked();

private:
    Ui::MainWindow *ui;
protected:
//    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
