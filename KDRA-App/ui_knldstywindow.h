/********************************************************************************
** Form generated from reading UI file 'knldstywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KNLDSTYWINDOW_H
#define UI_KNLDSTYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "cspkernel.h"

QT_BEGIN_NAMESPACE

class Ui_KnldstyWindow
{
public:
    QPushButton *pushButton;
    QLabel *infoBox;
    CSpKernel *knldShow;

    void setupUi(QWidget *KnldstyWindow)
    {
        if (KnldstyWindow->objectName().isEmpty())
            KnldstyWindow->setObjectName(QStringLiteral("KnldstyWindow"));
        KnldstyWindow->resize(864, 681);
        pushButton = new QPushButton(KnldstyWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 20, 111, 31));
        infoBox = new QLabel(KnldstyWindow);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(220, 10, 121, 41));
        knldShow = new CSpKernel(KnldstyWindow);
        knldShow->setObjectName(QStringLiteral("knldShow"));
        knldShow->setGeometry(QRect(20, 60, 800, 600));

        retranslateUi(KnldstyWindow);

        QMetaObject::connectSlotsByName(KnldstyWindow);
    } // setupUi

    void retranslateUi(QWidget *KnldstyWindow)
    {
        KnldstyWindow->setWindowTitle(QApplication::translate("KnldstyWindow", "\346\240\270\345\257\206\345\272\246\344\274\260\350\256\241", Q_NULLPTR));
        pushButton->setText(QApplication::translate("KnldstyWindow", "\350\257\267\345\257\274\345\205\245.shp\346\226\207\344\273\266", Q_NULLPTR));
        infoBox->setText(QString());
        knldShow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KnldstyWindow: public Ui_KnldstyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNLDSTYWINDOW_H
