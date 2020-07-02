#include "guideinterface.h"
#include "ui_guideinterface.h"

GuideInterface::GuideInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuideInterface)
{
    ui->setupUi(this);
}

GuideInterface::~GuideInterface()
{
    delete ui;
}

void GuideInterface::on_simpleGIS_clicked()
{
    this->mainWindow.show();//显示上学期简版GIS系统的界面。注意在头文件中先声明mainwindow。（来自百度）
}

void GuideInterface::on_RouteSearching_clicked()
{
    routeSearchingWindow.setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    this->routeSearchingWindow.show();
}
