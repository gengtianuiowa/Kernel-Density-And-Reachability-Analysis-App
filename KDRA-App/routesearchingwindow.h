#ifndef ROUTESEARCHINGWINDOW_H
#define ROUTESEARCHINGWINDOW_H

#include <QDialog>
#include"cspfile.h"
#include"qfiledialog.h"
#include"csproute.h"

namespace Ui {
class RouteSearchingWindow;
}

class RouteSearchingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RouteSearchingWindow(QWidget *parent = 0);
    ~RouteSearchingWindow();
    CSpFile myfile;

private slots:
    void on_inportFile_clicked();

private:
    Ui::RouteSearchingWindow *ui;
};

#endif // ROUTESEARCHINGWINDOW_H
