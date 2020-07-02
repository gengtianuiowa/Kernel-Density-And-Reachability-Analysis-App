#include "guidewindow.h"
#include "ui_guidewindow.h"

GuideWindow::GuideWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuideWindow)
{
    ui->setupUi(this);
}

GuideWindow::~GuideWindow()
{
    delete ui;
}



void GuideWindow::on_simpleGIS_clicked()
{
    mainWindow.show();
}

void GuideWindow::on_routeSearching_clicked()
{
    routeSearchingWindow.setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//取消右上角的帮助按钮（来源百度）
    routeSearchingWindow.show();
}

void GuideWindow::on_knldBt_clicked()
{
    knldstyWindow.setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//取消右上角的帮助按钮（来源百度）
    knldstyWindow.show();
}

void GuideWindow::on_RABt_clicked()
{
    rAWindow.setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//取消右上角的帮助按钮（来源百度）
    rAWindow.show();
}
