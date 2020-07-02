/********************************************************************************
** Form generated from reading UI file 'rawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAWINDOW_H
#define UI_RAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "cspra.h"

QT_BEGIN_NAMESPACE

class Ui_RAWindow
{
public:
    QPushButton *shpInput;
    QPushButton *shp2Input;
    QLabel *infoBox;
    CSpRA *RAShow;
    QPushButton *lineShow;

    void setupUi(QWidget *RAWindow)
    {
        if (RAWindow->objectName().isEmpty())
            RAWindow->setObjectName(QStringLiteral("RAWindow"));
        RAWindow->resize(749, 535);
        shpInput = new QPushButton(RAWindow);
        shpInput->setObjectName(QStringLiteral("shpInput"));
        shpInput->setGeometry(QRect(30, 20, 121, 31));
        shp2Input = new QPushButton(RAWindow);
        shp2Input->setObjectName(QStringLiteral("shp2Input"));
        shp2Input->setGeometry(QRect(160, 20, 101, 31));
        infoBox = new QLabel(RAWindow);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(450, 10, 141, 41));
        RAShow = new CSpRA(RAWindow);
        RAShow->setObjectName(QStringLiteral("RAShow"));
        RAShow->setGeometry(QRect(40, 70, 681, 441));
        lineShow = new QPushButton(RAWindow);
        lineShow->setObjectName(QStringLiteral("lineShow"));
        lineShow->setGeometry(QRect(280, 20, 141, 31));

        retranslateUi(RAWindow);

        QMetaObject::connectSlotsByName(RAWindow);
    } // setupUi

    void retranslateUi(QWidget *RAWindow)
    {
        RAWindow->setWindowTitle(QApplication::translate("RAWindow", "\345\217\257\350\276\276\346\200\247\345\210\206\346\236\220", Q_NULLPTR));
        shpInput->setText(QApplication::translate("RAWindow", "\350\257\267\345\257\274\345\205\245\345\260\217\345\214\272\347\202\271shp", Q_NULLPTR));
        shp2Input->setText(QApplication::translate("RAWindow", "\350\257\267\345\257\274\345\205\245\345\205\254\345\233\255shp", Q_NULLPTR));
        infoBox->setText(QString());
        RAShow->setText(QString());
        lineShow->setText(QApplication::translate("RAWindow", "\346\230\276\347\244\272\345\205\254\345\233\255\346\234\215\345\212\241\350\214\203\345\233\264\350\277\236\347\272\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RAWindow: public Ui_RAWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAWINDOW_H
