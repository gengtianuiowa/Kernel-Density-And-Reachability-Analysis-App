#include"guidewindow.h"
#include <QApplication>
#include <cspfile.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   GuideWindow g;
   g.show();
//    CSpFile* FILE = new CSpFile;
//    if (FILE->LoadFile())
//        cout<<"Loading Complete!"<<endl;
    return a.exec();
}
