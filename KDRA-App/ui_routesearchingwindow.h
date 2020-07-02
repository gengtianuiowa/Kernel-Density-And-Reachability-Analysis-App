/********************************************************************************
** Form generated from reading UI file 'routesearchingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTESEARCHINGWINDOW_H
#define UI_ROUTESEARCHINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "csproute.h"

QT_BEGIN_NAMESPACE

class Ui_RouteSearchingWindow
{
public:
    QPushButton *inportFile;
    QLabel *infoBox;
    CSpRoute *label;

    void setupUi(QDialog *RouteSearchingWindow)
    {
        if (RouteSearchingWindow->objectName().isEmpty())
            RouteSearchingWindow->setObjectName(QStringLiteral("RouteSearchingWindow"));
        RouteSearchingWindow->resize(712, 544);
#ifndef QT_NO_WHATSTHIS
        RouteSearchingWindow->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        inportFile = new QPushButton(RouteSearchingWindow);
        inportFile->setObjectName(QStringLiteral("inportFile"));
        inportFile->setGeometry(QRect(30, 10, 91, 21));
        infoBox = new QLabel(RouteSearchingWindow);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(220, 20, 91, 21));
        label = new CSpRoute(RouteSearchingWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 641, 451));

        retranslateUi(RouteSearchingWindow);

        QMetaObject::connectSlotsByName(RouteSearchingWindow);
    } // setupUi

    void retranslateUi(QDialog *RouteSearchingWindow)
    {
        RouteSearchingWindow->setWindowTitle(QApplication::translate("RouteSearchingWindow", "\350\267\257\345\276\204\350\247\204\345\210\222\347\263\273\347\273\237", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        RouteSearchingWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        inportFile->setText(QApplication::translate("RouteSearchingWindow", "\345\257\274\345\205\245e00\346\226\207\344\273\266", Q_NULLPTR));
        infoBox->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RouteSearchingWindow: public Ui_RouteSearchingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTESEARCHINGWINDOW_H
