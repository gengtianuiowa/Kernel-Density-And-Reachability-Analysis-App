/********************************************************************************
** Form generated from reading UI file 'knldnsywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KNLDNSYWINDOW_H
#define UI_KNLDNSYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KnlDnsyWindow
{
public:
    QPushButton *pushButton;
    QLabel *infoBox;
    QLabel *knldShow;

    void setupUi(QWidget *KnlDnsyWindow)
    {
        if (KnlDnsyWindow->objectName().isEmpty())
            KnlDnsyWindow->setObjectName(QStringLiteral("KnlDnsyWindow"));
        KnlDnsyWindow->resize(853, 632);
        pushButton = new QPushButton(KnlDnsyWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 91, 31));
        infoBox = new QLabel(KnlDnsyWindow);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(180, 10, 131, 41));
        knldShow = new QLabel(KnlDnsyWindow);
        knldShow->setObjectName(QStringLiteral("knldShow"));
        knldShow->setGeometry(QRect(30, 60, 781, 531));

        retranslateUi(KnlDnsyWindow);

        QMetaObject::connectSlotsByName(KnlDnsyWindow);
    } // setupUi

    void retranslateUi(QWidget *KnlDnsyWindow)
    {
        KnlDnsyWindow->setWindowTitle(QApplication::translate("KnlDnsyWindow", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("KnlDnsyWindow", "PushButton", Q_NULLPTR));
        infoBox->setText(QApplication::translate("KnlDnsyWindow", "TextLabel", Q_NULLPTR));
        knldShow->setText(QApplication::translate("KnlDnsyWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KnlDnsyWindow: public Ui_KnlDnsyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNLDNSYWINDOW_H
