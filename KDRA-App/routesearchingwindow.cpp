#include "routesearchingwindow.h"
#include "ui_routesearchingwindow.h"

RouteSearchingWindow::RouteSearchingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RouteSearchingWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());//设置不可调窗口大小
}

RouteSearchingWindow::~RouteSearchingWindow()
{
    delete ui;
}

CSpFile CSpRoute::drawdata=CSpFile();

void RouteSearchingWindow::on_inportFile_clicked()
{
    QStringList filenames=QFileDialog::getOpenFileNames(this,QStringLiteral("选取E00文件"),"E:");//同时读取E00文件的窗口
    if(filenames.length()==1)
    {
        QByteArray name1=filenames[0].toLatin1();//下面两步为：QSting类型转为char* 类型
        char* chname1=name1.data();
//        qDebug()<<chname1<<endl; ;//输出第一个文件名
        myfile.E00=(const char *)chname1;//把读取到的文件名复制给myfile，启用便于启用读取函数
        if (myfile.LoadE00())//启用读取函数
        {
            myfile.showArcs();
            myfile.showLinks();
            QPalette p;//设置样式为红色，并且居中
            p.setColor(QPalette::WindowText,Qt::red);
            ui->infoBox->setPalette(p);
            ui->infoBox->setAlignment(Qt::AlignCenter);
            CSpRoute::drawdata=myfile;
            ui->infoBox->setText(QStringLiteral("E00读取成功"));
        }
        else
        {
            QPalette p;
            p.setColor(QPalette::WindowText,Qt::red);
            ui->infoBox->setPalette(p);
            ui->infoBox->setAlignment(Qt::AlignCenter);
            ui->infoBox->setText(QStringLiteral("读取失败，请检查输入\n路径和文件是否正确"));
        }
        //myfile.ShowCities();
        //myfile.ShowProperties();
        //ui->map->repaint();
    }
    else
    {
        QPalette p;
        p.setColor(QPalette::WindowText,Qt::red);
        ui->infoBox->setPalette(p);
        ui->infoBox->setAlignment(Qt::AlignCenter);
        ui->infoBox->setText(QStringLiteral("读取失败，请检查输入\n路径和文件是否正确"));
    }
}
