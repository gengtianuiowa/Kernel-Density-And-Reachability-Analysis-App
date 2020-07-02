/********************************************************************************
** Form generated from reading UI file 'knldstywindow_copy.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KNLDSTYWINDOW_COPY_H
#define UI_KNLDSTYWINDOW_COPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KnlDstyWindow
{
public:
    QLabel *infoBox;
    QPushButton *inputShpBt;
    QLabel *knldShow;

    void setupUi(QWidget *KnlDstyWindow)
    {
        if (KnlDstyWindow->objectName().isEmpty())
            KnlDstyWindow->setObjectName(QStringLiteral("KnlDstyWindow"));
        KnlDstyWindow->resize(582, 460);
        infoBox = new QLabel(KnlDstyWindow);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(220, 10, 101, 31));
        inputShpBt = new QPushButton(KnlDstyWindow);
        inputShpBt->setObjectName(QStringLiteral("inputShpBt"));
        inputShpBt->setGeometry(QRect(40, 20, 101, 23));
        knldShow = new QLabel(KnlDstyWindow);
        knldShow->setObjectName(QStringLiteral("knldShow"));
        knldShow->setGeometry(QRect(40, 50, 511, 381));

        retranslateUi(KnlDstyWindow);

        QMetaObject::connectSlotsByName(KnlDstyWindow);
    } // setupUi

    void retranslateUi(QWidget *KnlDstyWindow)
    {
        KnlDstyWindow->setWindowTitle(QApplication::translate("KnlDstyWindow", "Form", Q_NULLPTR));
        infoBox->setText(QApplication::translate("KnlDstyWindow", "TextLabel", Q_NULLPTR));
        inputShpBt->setText(QApplication::translate("KnlDstyWindow", "\350\257\267\345\257\274\345\205\245shp\346\226\207\344\273\266", Q_NULLPTR));
        knldShow->setText(QApplication::translate("KnlDstyWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KnlDstyWindow: public Ui_KnlDstyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNLDSTYWINDOW_COPY_H
