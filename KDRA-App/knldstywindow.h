#ifndef KNLDSTYWINDOW_H
#define KNLDSTYWINDOW_H

#include <QWidget>
#include "cspshp.h"
#include"qfiledialog.h"
#include "cspkernel.h"

namespace Ui {
class KnldstyWindow;
}

class KnldstyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit KnldstyWindow(QWidget *parent = 0);
    ~KnldstyWindow();
     CSpShp shp;

private slots:
    void on_pushButton_clicked();

private:
    Ui::KnldstyWindow *ui;
};

#endif // KNLDSTYWINDOW_H
