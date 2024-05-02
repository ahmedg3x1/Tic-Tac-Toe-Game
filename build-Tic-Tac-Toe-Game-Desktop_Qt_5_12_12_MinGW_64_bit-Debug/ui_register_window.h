/********************************************************************************
** Form generated from reading UI file 'register_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_WINDOW_H
#define UI_REGISTER_WINDOW_H

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

class Ui_register_window
{
public:
    QWidget *centralwidget;
    QLineEdit *user;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *register_button;
    QPushButton *cancel_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *register_window)
    {
        if (register_window->objectName().isEmpty())
            register_window->setObjectName(QString::fromUtf8("register_window"));
        register_window->resize(385, 221);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(register_window->sizePolicy().hasHeightForWidth());
        register_window->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(register_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        user = new QLineEdit(centralwidget);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(120, 30, 161, 22));
        password = new QLineEdit(centralwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(120, 60, 161, 22));
        password->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 71, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 60, 55, 16));
        register_button = new QPushButton(centralwidget);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setGeometry(QRect(20, 110, 211, 51));
        cancel_button = new QPushButton(centralwidget);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(240, 110, 131, 51));
        register_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(register_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 385, 26));
        register_window->setMenuBar(menubar);
        statusbar = new QStatusBar(register_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        register_window->setStatusBar(statusbar);

        retranslateUi(register_window);

        QMetaObject::connectSlotsByName(register_window);
    } // setupUi

    void retranslateUi(QMainWindow *register_window)
    {
        register_window->setWindowTitle(QApplication::translate("register_window", "register", nullptr));
        label->setText(QApplication::translate("register_window", "user", nullptr));
        label_2->setText(QApplication::translate("register_window", "password", nullptr));
        register_button->setText(QApplication::translate("register_window", "register", nullptr));
        cancel_button->setText(QApplication::translate("register_window", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register_window: public Ui_register_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_WINDOW_H
