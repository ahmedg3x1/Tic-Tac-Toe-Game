/********************************************************************************
** Form generated from reading UI file 'entry_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRY_MENU_H
#define UI_ENTRY_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_entry_menu
{
public:
    QWidget *centralwidget;
    QPushButton *profile_button;
    QPushButton *history_button;
    QPushButton *pvp_button;
    QPushButton *pvai_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *entry_menu)
    {
        if (entry_menu->objectName().isEmpty())
            entry_menu->setObjectName(QString::fromUtf8("entry_menu"));
        entry_menu->resize(600, 364);
        centralwidget = new QWidget(entry_menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        profile_button = new QPushButton(centralwidget);
        profile_button->setObjectName(QString::fromUtf8("profile_button"));
        profile_button->setGeometry(QRect(50, 50, 111, 51));
        history_button = new QPushButton(centralwidget);
        history_button->setObjectName(QString::fromUtf8("history_button"));
        history_button->setGeometry(QRect(420, 50, 111, 51));
        pvp_button = new QPushButton(centralwidget);
        pvp_button->setObjectName(QString::fromUtf8("pvp_button"));
        pvp_button->setGeometry(QRect(110, 140, 381, 71));
        pvai_button = new QPushButton(centralwidget);
        pvai_button->setObjectName(QString::fromUtf8("pvai_button"));
        pvai_button->setGeometry(QRect(110, 230, 381, 71));
        entry_menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(entry_menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        entry_menu->setMenuBar(menubar);
        statusbar = new QStatusBar(entry_menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        entry_menu->setStatusBar(statusbar);

        retranslateUi(entry_menu);

        QMetaObject::connectSlotsByName(entry_menu);
    } // setupUi

    void retranslateUi(QMainWindow *entry_menu)
    {
        entry_menu->setWindowTitle(QApplication::translate("entry_menu", "Tic Tac Toe", nullptr));
        profile_button->setText(QApplication::translate("entry_menu", "profile", nullptr));
        history_button->setText(QApplication::translate("entry_menu", "history", nullptr));
        pvp_button->setText(QApplication::translate("entry_menu", "Player vs Player", nullptr));
        pvai_button->setText(QApplication::translate("entry_menu", "Player vs AI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class entry_menu: public Ui_entry_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRY_MENU_H
