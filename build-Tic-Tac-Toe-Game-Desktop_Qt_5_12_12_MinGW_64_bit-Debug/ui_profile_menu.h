/********************************************************************************
** Form generated from reading UI file 'profile_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_MENU_H
#define UI_PROFILE_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profile_menu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *user_textbox;
    QLineEdit *lineEdit_2;
    QPushButton *cancel_button;
    QPushButton *save_button;
    QLabel *label_3;
    QLabel *wins_label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lose_label;
    QLabel *draw_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *profile_menu)
    {
        if (profile_menu->objectName().isEmpty())
            profile_menu->setObjectName(QString::fromUtf8("profile_menu"));
        profile_menu->resize(475, 413);
        centralwidget = new QWidget(profile_menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(58, 60, 55, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(58, 100, 55, 16));
        user_textbox = new QLineEdit(centralwidget);
        user_textbox->setObjectName(QString::fromUtf8("user_textbox"));
        user_textbox->setEnabled(false);
        user_textbox->setGeometry(QRect(168, 60, 121, 22));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 100, 121, 22));
        cancel_button = new QPushButton(centralwidget);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(290, 290, 131, 51));
        save_button = new QPushButton(centralwidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(40, 290, 131, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 170, 101, 16));
        wins_label = new QLabel(centralwidget);
        wins_label->setObjectName(QString::fromUtf8("wins_label"));
        wins_label->setGeometry(QRect(170, 170, 55, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 200, 101, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 230, 101, 16));
        lose_label = new QLabel(centralwidget);
        lose_label->setObjectName(QString::fromUtf8("lose_label"));
        lose_label->setGeometry(QRect(170, 200, 55, 16));
        draw_label = new QLabel(centralwidget);
        draw_label->setObjectName(QString::fromUtf8("draw_label"));
        draw_label->setGeometry(QRect(170, 230, 55, 16));
        profile_menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(profile_menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 475, 26));
        profile_menu->setMenuBar(menubar);
        statusbar = new QStatusBar(profile_menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        profile_menu->setStatusBar(statusbar);

        retranslateUi(profile_menu);

        QMetaObject::connectSlotsByName(profile_menu);
    } // setupUi

    void retranslateUi(QMainWindow *profile_menu)
    {
        profile_menu->setWindowTitle(QApplication::translate("profile_menu", "MainWindow", nullptr));
        label->setText(QApplication::translate("profile_menu", "user", nullptr));
        label_2->setText(QApplication::translate("profile_menu", "password", nullptr));
        user_textbox->setText(QApplication::translate("profile_menu", "username", nullptr));
        cancel_button->setText(QApplication::translate("profile_menu", "cancel", nullptr));
        save_button->setText(QApplication::translate("profile_menu", "save", nullptr));
        label_3->setText(QApplication::translate("profile_menu", "number of wins:", nullptr));
        wins_label->setText(QApplication::translate("profile_menu", "0", nullptr));
        label_5->setText(QApplication::translate("profile_menu", "number of loses:", nullptr));
        label_6->setText(QApplication::translate("profile_menu", "number of draws:", nullptr));
        lose_label->setText(QApplication::translate("profile_menu", "0", nullptr));
        draw_label->setText(QApplication::translate("profile_menu", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profile_menu: public Ui_profile_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_MENU_H
