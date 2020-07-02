#ifndef GUIDEINTERFACE_H
#define GUIDEINTERFACE_H

#include <QDialog>
#include"mainwindow.h"
#include"routesearchingwindow.h"

namespace Ui {
class GuideInterface;
}

class GuideInterface : public QDialog
{
    Q_OBJECT

public:
    explicit GuideInterface(QWidget *parent = 0);
    ~GuideInterface();

private slots:

    void on_simpleGIS_clicked();

    void on_RouteSearching_clicked();

private:
    Ui::GuideInterface *ui;
    RouteSearchingWindow routeSearchingWindow;
    MainWindow mainWindow;
};

#endif // GUIDEINTERFACE_H
