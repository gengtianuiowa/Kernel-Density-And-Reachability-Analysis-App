#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cspfile.h"
#include"cspmap.h"
#include<QDialog>
#include<QFileDialog>
#include<qdebug.h>
#include <stdio.h>
#include<qbytearray.h>
#include<QTextCodec>
#include<QPainter>
#include"csproute.h"
#include<cspmap.h>
#include<qtooltip.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());//设置不可调窗口大小

}

MainWindow::~MainWindow()
{
    delete ui;
}

CSpFile cspmap::drawdata=CSpFile();//在C++中静态变量一定要在使用前初始化！构造函数不能初始化静态变量，否则编译报错。
CSpCities cspmap::searchCity=CSpCities();
bool cspmap::searchingState=0;

void MainWindow::on_importData_clicked()
{
//    QString fileName1=QFileDialog::getOpenFileName(this,tr("选取DAT文件"),"E:");
//    QString fileName2=QFileDialog::getOpenFileName(this,tr("选取OPT文件"),"E:");
//    QString fileName3=QFileDialog::getOpenFileName(this,tr("选取TXT文件"),"E:");
    QStringList filenames=QFileDialog::getOpenFileNames(this,tr("选取DAT、OPT、TXT文件"),"E:");//同时读取三个文件的窗口
    if(filenames.length()==3)
    {
        QByteArray name1=filenames[0].toLatin1();//下面两步为：QSting类型转为char* 类型
        char* chname1=name1.data();
//        qDebug()<<chname1<<endl; ;//输出第一个文件名
        QByteArray name2=filenames[1].toLatin1();
        char* chname2=name2.data();
//         qDebug()<<chname2<<endl;
        QByteArray name3=filenames[2].toLatin1();
        char* chname3=name3.data();
        myfile.DAT=(const char *)chname1;//把读取到的文件名复制给myfile，启用便于启用读取函数
        myfile.OPT=(const char *)chname2;
        myfile.TXT=(const char *)chname3;
        if (myfile.LoadFile())//启用读取函数
        {
            QPalette p;//设置样式为红色，并且居中
            p.setColor(QPalette::WindowText,Qt::red);
            ui->loadfile->setPalette(p);
            ui->loadfile->setAlignment(Qt::AlignCenter);
            ui->loadfile->setText("读取成功");
            myfile.createIndex();//创建索引
            cspmap::drawdata=myfile;//myfile变量完全赋给drawdata，以便于在cspmap中调用
//            myfile.Database.GEOLayer[0].GEOObject[0].ShowObject();
            //cout<<"Loading Complete!"<<endl;
        }
        else
        {
            QPalette p;
            p.setColor(QPalette::WindowText,Qt::red);
            ui->loadfile->setPalette(p);
            ui->loadfile->setAlignment(Qt::AlignCenter);
            ui->loadfile->setText("读取失败，请检查输入路径和文件是否正确");
        }
        //myfile.ShowCities();
        //myfile.ShowProperties();
        //ui->map->repaint();
    }
    else
    {
        QPalette p;
        p.setColor(QPalette::WindowText,Qt::red);
        ui->loadfile->setPalette(p);
        ui->loadfile->setAlignment(Qt::AlignCenter);
        ui->loadfile->setText("读取失败，请检查输入路径和文件是否正确");
    }

}

void MainWindow::on_confirmSearching_clicked()
{
    if(myfile.txtState==true)
    {
        QString searchContext_qstring=ui->searchContext->text();
        this->findcitycoordinate=false;
        string searchContext =  searchContext_qstring.toStdString();//下面直至for函数前为将qstring转为string类型，并解决乱码问题
        QTextCodec* code = QTextCodec::codecForName("gb2312");
        if (code)// 如果code为0，表示在运行的机器上没有装gb2312字符集。不过一般的中文windows系统中都安装了这一字符集
              searchContext= code->fromUnicode(searchContext_qstring).data();
        for(int i=0;i<myfile.CityCapacity;i++)
        {
            if(myfile.Cities[i].CityName==searchContext)
            {
//                this->xCoordinate=myfile.Cities[i].Position.X;
//                this->yCoordinate=myfile.Cities[i].Position.Y;
//                QString xCoordinate_qstring=QString::number(xCoordinate, 10);//将两个int转变为QString输出
//                QString yCoordinate_qstring=QString::number(yCoordinate, 10);
//                ui->xCoordinate->setText(xCoordinate_qstring);
//                ui->yCoordinate->setText(yCoordinate_qstring);
                cspmap::searchCity.CityName=searchContext;
                cspmap::searchCity.Position.X=myfile.Cities[i].Position.X;
                cspmap::searchCity.Position.Y=myfile.Cities[i].Position.Y;
//                cout<<searchContext<<" has been found."<<endl;
                this->findcitycoordinate=true;
                cspmap::searchingState=true;//用以在map中重绘城市
                ui->map->repaint();
                break;
            }
        }
        if(this->findcitycoordinate==false)
        {
            QPalette p;
            p.setColor(QPalette::WindowText,Qt::red);
            ui->loadfile->setPalette(p);
            ui->loadfile->setAlignment(Qt::AlignCenter);
            ui->loadfile->setText("未查询到对应城市\n请重新输入");
        }
    }
    else
        {
            QPalette p;
            p.setColor(QPalette::WindowText,Qt::red);
            ui->loadfile->setPalette(p);
            ui->loadfile->setAlignment(Qt::AlignCenter);
            ui->loadfile->setText("请先读入文件");
        }
}


//void MainWindow::on_routeFile_clicked()
//{
//    QStringList filenames=QFileDialog::getOpenFileNames(this,tr("选取E00文件"),"E:");//同时读取E00文件的窗口
//    if(filenames.length()==1)
//    {
//        QByteArray name1=filenames[0].toLatin1();//下面两步为：QSting类型转为char* 类型
//        char* chname1=name1.data();
////        qDebug()<<chname1<<endl; ;//输出第一个文件名
//        myfile.E00=(const char *)chname1;//把读取到的文件名复制给myfile，启用便于启用读取函数
//        if (myfile.LoadE00())//启用读取函数
//        {
////            myfile.showArcs();
//            QPalette p;//设置样式为红色，并且居中
//            p.setColor(QPalette::WindowText,Qt::red);
//            ui->loadfile->setPalette(p);
//            ui->loadfile->setAlignment(Qt::AlignCenter);
//            CSpRoute::drawdata=myfile;
//            ui->loadfile->setText("E00读取成功");
//        }
//        else
//        {
//            QPalette p;
//            p.setColor(QPalette::WindowText,Qt::red);
//            ui->loadfile->setPalette(p);
//            ui->loadfile->setAlignment(Qt::AlignCenter);
//            ui->loadfile->setText("读取失败，请检查\n输入路径和文件是否正确");
//        }
//        //myfile.ShowCities();
//        //myfile.ShowProperties();
//        //ui->map->repaint();
//    }
//    else
//    {
//        QPalette p;
//        p.setColor(QPalette::WindowText,Qt::red);
//        ui->loadfile->setPalette(p);
//        ui->loadfile->setAlignment(Qt::AlignCenter);
//        ui->loadfile->setText("读取失败，请检查\n输入路径和文件是否正确");
//    }

//}
