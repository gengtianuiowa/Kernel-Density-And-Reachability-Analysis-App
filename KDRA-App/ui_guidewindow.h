/********************************************************************************
** Form generated from reading UI file 'guidewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDEWINDOW_H
#define UI_GUIDEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuideWindow
{
public:
    QWidget *centralwidget;
    QPushButton *simpleGIS;
    QPushButton *routeSearching;
    QPushButton *knldBt;
    QPushButton *RABt;

    void setupUi(QMainWindow *GuideWindow)
    {
        if (GuideWindow->objectName().isEmpty())
            GuideWindow->setObjectName(QStringLiteral("GuideWindow"));
        GuideWindow->resize(600, 294);
        centralwidget = new QWidget(GuideWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        simpleGIS = new QPushButton(centralwidget);
        simpleGIS->setObjectName(QStringLiteral("simpleGIS"));
        simpleGIS->setGeometry(QRect(110, 80, 121, 41));
        routeSearching = new QPushButton(centralwidget);
        routeSearching->setObjectName(QStringLiteral("routeSearching"));
        routeSearching->setGeometry(QRect(320, 80, 121, 41));
        knldBt = new QPushButton(centralwidget);
        knldBt->setObjectName(QStringLiteral("knldBt"));
        knldBt->setGeometry(QRect(110, 160, 121, 41));
        RABt = new QPushButton(centralwidget);
        RABt->setObjectName(QStringLiteral("RABt"));
        RABt->setGeometry(QRect(320, 160, 121, 41));
        GuideWindow->setCentralWidget(centralwidget);

        retranslateUi(GuideWindow);

        QMetaObject::connectSlotsByName(GuideWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GuideWindow)
    {
        GuideWindow->setWindowTitle(QApplication::translate("GuideWindow", "\346\254\242\350\277\216\344\275\277\347\224\250MrFrost\347\232\204\347\225\214\351\235\242", Q_NULLPTR));
        simpleGIS->setText(QApplication::translate("GuideWindow", "\350\277\233\345\205\245\347\256\200\347\211\210GIS\347\263\273\347\273\237", Q_NULLPTR));
        routeSearching->setText(QApplication::translate("GuideWindow", "\350\277\233\345\205\245\350\267\257\345\276\204\350\247\204\345\210\222\347\263\273\347\273\237", Q_NULLPTR));
        knldBt->setText(QApplication::translate("GuideWindow", "\346\240\270\345\257\206\345\272\246\345\210\206\346\236\220", Q_NULLPTR));
        RABt->setText(QApplication::translate("GuideWindow", "\345\217\257\350\276\276\346\200\247\345\210\206\346\236\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuideWindow: public Ui_GuideWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDEWINDOW_H
