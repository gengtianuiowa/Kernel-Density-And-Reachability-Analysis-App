/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "cspmap.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    cspmap *map;
    QLabel *loadfile;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *importData;
    QLabel *searchLabel;
    QLineEdit *searchContext;
    QPushButton *confirmSearching;
    QPushButton *pushButton_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(769, 635);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(false);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        map = new cspmap(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        map->setGeometry(QRect(60, 50, 641, 561));
        loadfile = new QLabel(centralWidget);
        loadfile->setObjectName(QStringLiteral("loadfile"));
        loadfile->setGeometry(QRect(620, 10, 131, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 591, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        importData = new QPushButton(layoutWidget);
        importData->setObjectName(QStringLiteral("importData"));

        horizontalLayout->addWidget(importData);

        searchLabel = new QLabel(layoutWidget);
        searchLabel->setObjectName(QStringLiteral("searchLabel"));

        horizontalLayout->addWidget(searchLabel);

        searchContext = new QLineEdit(layoutWidget);
        searchContext->setObjectName(QStringLiteral("searchContext"));

        horizontalLayout->addWidget(searchContext);

        confirmSearching = new QPushButton(layoutWidget);
        confirmSearching->setObjectName(QStringLiteral("confirmSearching"));

        horizontalLayout->addWidget(confirmSearching);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\234\260\345\233\276\344\272\244\344\272\222\347\225\214\351\235\242", Q_NULLPTR));
        map->setText(QString());
        loadfile->setText(QString());
        importData->setText(QApplication::translate("MainWindow", "\350\257\267\345\220\214\346\227\266\345\257\274\345\205\245\344\270\211\344\270\252\346\226\207\344\273\266", Q_NULLPTR));
        searchLabel->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\237\245\350\257\242\346\202\250\350\246\201\346\237\245\350\257\242\347\232\204\345\234\260\345\220\215\357\274\232", Q_NULLPTR));
        confirmSearching->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\252\227\345\217\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
