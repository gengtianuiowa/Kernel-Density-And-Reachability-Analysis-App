#ifndef RAWINDOW_H
#define RAWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "cspshp.h"
#include "cspra.h"
#include <QMainWindow>
#include <QWidget>
#include "cspshp.h"
#include "cspra.h"
#include"qfiledialog.h"
namespace Ui {
class RAWindow;
}

class RAWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RAWindow(QWidget *parent = 0);
    ~RAWindow();
    CSpShp shp[2];

private slots:

    void on_shpInput_clicked();

    void on_shp2Input_clicked();

    void on_lineShow_clicked();

private:
    Ui::RAWindow *ui;
};

#endif // RAWINDOW_H
