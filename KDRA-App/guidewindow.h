#ifndef GUIDEWINDOW_H
#define GUIDEWINDOW_H

#include <QMainWindow>
#include"routesearchingwindow.h"
#include"mainwindow.h"
#include"knldstywindow.h"
#include"rawindow.h"

namespace Ui {
class GuideWindow;
}

class GuideWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuideWindow(QWidget *parent = 0);
    ~GuideWindow();

private slots:

    void on_simpleGIS_clicked();

    void on_routeSearching_clicked();

    void on_knldBt_clicked();

    void on_RABt_clicked();

private:
    Ui::GuideWindow *ui;
    MainWindow mainWindow;
    RouteSearchingWindow routeSearchingWindow;
    KnldstyWindow knldstyWindow;
    RAWindow rAWindow;
};

#endif // GUIDEWINDOW_H
