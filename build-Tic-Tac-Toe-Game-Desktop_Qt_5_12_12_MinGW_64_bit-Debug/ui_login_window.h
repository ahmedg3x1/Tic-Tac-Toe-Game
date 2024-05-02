/********************************************************************************
** Form generated from reading UI file 'login_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WINDOW_H
#define UI_LOGIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_window
{
public:
    QWidget *centralwidget;
    QPushButton *login_button;
    QLineEdit *password_line_edit;
    QLabel *label;
    QLabel *label_2;
    QComboBox *username_combobox;
    QPushButton *register_button;
    QLabel *warning_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login_window)
    {
        if (login_window->objectName().isEmpty())
            login_window->setObjectName(QString::fromUtf8("login_window"));
        login_window->resize(414, 283);
        centralwidget = new QWidget(login_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        login_button = new QPushButton(centralwidget);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(50, 170, 321, 41));
        password_line_edit = new QLineEdit(centralwidget);
        password_line_edit->setObjectName(QString::fromUtf8("password_line_edit"));
        password_line_edit->setGeometry(QRect(140, 80, 191, 22));
        password_line_edit->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 55, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 80, 55, 16));
        username_combobox = new QComboBox(centralwidget);
        username_combobox->setObjectName(QString::fromUtf8("username_combobox"));
        username_combobox->setGeometry(QRect(140, 50, 191, 22));
        register_button = new QPushButton(centralwidget);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setGeometry(QRect(60, 120, 121, 41));
        warning_label = new QLabel(centralwidget);
        warning_label->setObjectName(QString::fromUtf8("warning_label"));
        warning_label->setEnabled(true);
        warning_label->setGeometry(QRect(220, 120, 55, 16));
        warning_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        login_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 414, 26));
        login_window->setMenuBar(menubar);
        statusbar = new QStatusBar(login_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        login_window->setStatusBar(statusbar);

        retranslateUi(login_window);

        QMetaObject::connectSlotsByName(login_window);
    } // setupUi

    void retranslateUi(QMainWindow *login_window)
    {
        login_window->setWindowTitle(QApplication::translate("login_window", "login", nullptr));
        login_button->setText(QApplication::translate("login_window", "login", nullptr));
        password_line_edit->setInputMask(QString());
        password_line_edit->setText(QString());
        label->setText(QApplication::translate("login_window", "user", nullptr));
        label_2->setText(QApplication::translate("login_window", "password", nullptr));
        register_button->setText(QApplication::translate("login_window", "new account", nullptr));
        warning_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login_window: public Ui_login_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WINDOW_H
