#include "rawindow.h"
#include "ui_rawindow.h"

RAWindow::RAWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RAWindow)
{
    ui->setupUi(this);
}

RAWindow::~RAWindow()
{
    delete ui;
}

CSpShp* CSpRA::shp=new CSpShp[2];
bool CSpRA::drawLineStatus=false;

void RAWindow::on_shpInput_clicked()
{
    QStringList filenames=QFileDialog::getOpenFileNames(this,QStringLiteral("选取小区点shp"),"E:");//同时读取E00文件的窗口
    if(filenames.length()==1)
    {
        QByteArray name1=filenames[0].toLatin1();//下面两步为：QSting类型转为char* 类型
        char* chname1=name1.data();
//        qDebug()<<chname1<<endl; ;//输出第一个文件名
        this->shp[0].shpPath=(const char *)chname1;//把读取到的文件名复制给shp，启用便于启用读取函数

        //下面开始获取图层名，输入给shp.layerName
        QFileInfo shpfile(filenames[0]);//这样初始化，便于提取文件名
        QString layerNameQ= shpfile.fileName();//提取到文件名
        std::string strStd= layerNameQ.toStdString();//qstring转string
        std::size_t pos = strStd.find(".");//找到.的位置
        std::string temp=strStd.substr(0,pos);//提取从开始到.的内容，即layername
        this->shp[0].layerName= const_cast<char*>(temp.c_str());//强制类型转换后赋给shp的属性

        if (this->shp[0].LoadShp())//启用读取函数
        {
//            myfile.showArcs();
//            myfile.showLinks();
            this->shp[0].loadStatus=true;
            QPalette p;//设置样式为红色，并且居中
            p.setColor(QPalette::WindowText,Qt::red);
            ui->infoBox->setPalette(p);
            ui->infoBox->setAlignment(Qt::AlignCenter);
            CSpRA::shp[0]=this->shp[0];
            ui->infoBox->setText(QStringLiteral("shp读取成功"));
        }
        else
        {
            this->shp[0].loadStatus=false;
            QPalette p;
            p.setColor(QPalette::WindowText,Qt::red);
            ui->infoBox->setPalette(p);
            ui->infoBox->setAlignment(Qt::AlignCenter);
            ui->infoBox->setText(QStringLiteral("读取失败，请检查输入\n路径和文件是否正确"));
        }
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

void RAWindow::on_shp2Input_clicked()
{
    QStringList filenames=QFileDialog::getOpenFileNames(this,QStringLiteral("选取公园shp"),"E:");//同时读取E00文件的窗口
    if(filenames.length()==1)
    {
        QByteArray name1=filenames[0].toLatin1();//下面两步为：QSting类型转为char* 类型
        char* chname1=name1.data();
//        qDebug()<<chname1<<endl; ;//输出第一个文件名
        this->shp[1].shpPath=(const char *)chname1;//把读取到的文件名复制给shp，启用便于启用读取函数

        //下面开始获取图层名，输入给shp.layerName
        QFileInfo shpfile(filenames[0]);//这样初始化，便于提取文件名
        QString layerNameQ= shpfile.fileName();//提取到文件名
        std::string strStd= layerNameQ.toStdString();//qstring转string
        std::size_t pos = strStd.find(".");//找到.的位置
        std::string temp=strStd.substr(0,pos);//提取从开始到.的内容，即layername
        this->shp[1].layerName= const_cast<char*>(temp.c_str());//强制类型转换后赋给shp的属性

        if (this->shp[1].LoadShp())//启用读取函数
        {
//            myfile.showArcs();
//            myfile.showLinks();
            this->shp[1].loadStatus=true;
            QPalette p;//设置样式为红色，并且居中
            p.setColor(QPalette::WindowText,Qt::red);
            ui->infoBox->setPalette(p);
            ui->infoBox->setAlignment(Qt::AlignCenter);
            CSpRA::shp[1]=this->shp[1];
            ui->infoBox->setText(QStringLiteral("shp读取成功"));
        }
        else
        {
            this->shp[1].loadStatus=false;
            QPalette p;
            p.setColor(QPalette::WindowText,Qt::red);
            ui->infoBox->setPalette(p);
            ui->infoBox->setAlignment(Qt::AlignCenter);
            ui->infoBox->setText(QStringLiteral("读取失败，请检查输入\n路径和文件是否正确"));
        }
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

void RAWindow::on_lineShow_clicked()
{
    if(CSpRA::drawLineStatus==false)
    {
        CSpRA::drawLineStatus=true;
        ui->RAShow->repaint();
    }else
    {
        CSpRA::drawLineStatus=false;
        ui->RAShow->repaint();
    }

}
