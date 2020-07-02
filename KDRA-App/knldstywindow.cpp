#include "knldstywindow.h"
#include "ui_knldstywindow.h"
#include <QTextCodec>
KnldstyWindow::KnldstyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KnldstyWindow)
{
    ui->setupUi(this);
}

KnldstyWindow::~KnldstyWindow()
{
    delete ui;
}
CSpShp CSpKernel::shp=CSpShp();
void KnldstyWindow::on_pushButton_clicked()
{
    QStringList filenames=QFileDialog::getOpenFileNames(this,QStringLiteral("选取shp文件"),"E:");//同时读取E00文件的窗口
    if(filenames.length()==1)
    {
        QByteArray name1=filenames[0].toLatin1();//下面两步为：QSting类型转为char* 类型
        char* chname1=name1.data();
//        qDebug()<<chname1<<endl; ;//输出第一个文件名
        this->shp.shpPath=(const char *)chname1;//把读取到的文件名复制给shp，启用便于启用读取函数

        //下面开始获取图层名，输入给shp.layerName
        QFileInfo shpfile(filenames[0]);//这样初始化，便于提取文件名
        QString layerNameQ= shpfile.fileName();//提取到文件名
        std::string strStd= layerNameQ.toStdString();//qstring转string
        std::size_t pos = strStd.find(".");//找到.的位置
        std::string temp=strStd.substr(0,pos);//提取从开始到.的内容，即layername
        this->shp.layerName= const_cast<char*>(temp.c_str());//强制类型转换后赋给shp的属性

        if (this->shp.LoadShp())//启用读取函数
        {
//            myfile.showArcs();
//            myfile.showLinks();
            this->shp.loadStatus=true;
            QPalette p;//设置样式为红色，并且居中
            p.setColor(QPalette::WindowText,Qt::red);
            ui->infoBox->setPalette(p);
            ui->infoBox->setAlignment(Qt::AlignCenter);
            //CSpRoute::drawdata=myfile;
            CSpKernel::shp=this->shp;
            ui->infoBox->setText(QStringLiteral("shp读取成功"));
        }
        else
        {
            this->shp.loadStatus=false;
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
