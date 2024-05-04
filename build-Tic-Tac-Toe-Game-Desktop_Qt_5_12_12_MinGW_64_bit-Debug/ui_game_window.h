/********************************************************************************
** Form generated from reading UI file 'game_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_WINDOW_H
#define UI_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_window
{
public:
    QWidget *centralwidget;
    QPushButton *Play_Again;
    QFrame *gridFrame;
    QGridLayout *Game_Grid;
    QPushButton *Slot_4;
    QPushButton *Slot_8;
    QFrame *line_3;
    QPushButton *Slot_7;
    QPushButton *Slot_2;
    QFrame *line_8;
    QFrame *line_7;
    QFrame *line_2;
    QPushButton *Slot_6;
    QPushButton *Slot_3;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_9;
    QPushButton *Slot_5;
    QFrame *line;
    QPushButton *Slot_9;
    QFrame *line_4;
    QPushButton *Slot_1;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QPushButton *Home;

    void setupUi(QMainWindow *game_window)
    {
        if (game_window->objectName().isEmpty())
            game_window->setObjectName(QString::fromUtf8("game_window"));
        game_window->resize(518, 559);
        game_window->setMinimumSize(QSize(518, 559));
        game_window->setMaximumSize(QSize(518, 559));
        centralwidget = new QWidget(game_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Play_Again = new QPushButton(centralwidget);
        Play_Again->setObjectName(QString::fromUtf8("Play_Again"));
        Play_Again->setGeometry(QRect(130, 510, 111, 41));
        QFont font;
        font.setPointSize(12);
        Play_Again->setFont(font);
        gridFrame = new QFrame(centralwidget);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(11, 11, 496, 496));
        Game_Grid = new QGridLayout(gridFrame);
        Game_Grid->setSpacing(8);
        Game_Grid->setObjectName(QString::fromUtf8("Game_Grid"));
        Game_Grid->setSizeConstraint(QLayout::SetFixedSize);
        Game_Grid->setContentsMargins(4, 4, 4, 4);
        Slot_4 = new QPushButton(gridFrame);
        Slot_4->setObjectName(QString::fromUtf8("Slot_4"));
        Slot_4->setMinimumSize(QSize(150, 150));
        Slot_4->setMaximumSize(QSize(150, 150));
        QFont font1;
        font1.setPointSize(80);
        Slot_4->setFont(font1);
        Slot_4->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_4, 2, 0, 1, 1);

        Slot_8 = new QPushButton(gridFrame);
        Slot_8->setObjectName(QString::fromUtf8("Slot_8"));
        Slot_8->setMinimumSize(QSize(150, 150));
        Slot_8->setMaximumSize(QSize(150, 150));
        Slot_8->setFont(font1);
        Slot_8->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_8, 4, 2, 1, 1);

        line_3 = new QFrame(gridFrame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setFrameShape(QFrame::VLine);

        Game_Grid->addWidget(line_3, 4, 1, 1, 1);

        Slot_7 = new QPushButton(gridFrame);
        Slot_7->setObjectName(QString::fromUtf8("Slot_7"));
        Slot_7->setMinimumSize(QSize(150, 150));
        Slot_7->setMaximumSize(QSize(150, 150));
        Slot_7->setFont(font1);
        Slot_7->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_7, 4, 0, 1, 1);

        Slot_2 = new QPushButton(gridFrame);
        Slot_2->setObjectName(QString::fromUtf8("Slot_2"));
        Slot_2->setMinimumSize(QSize(150, 150));
        Slot_2->setMaximumSize(QSize(150, 150));
        Slot_2->setFont(font1);
        Slot_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_2, 0, 2, 1, 1);

        line_8 = new QFrame(gridFrame);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setFrameShape(QFrame::HLine);

        Game_Grid->addWidget(line_8, 3, 2, 1, 1);

        line_7 = new QFrame(gridFrame);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setFrameShape(QFrame::HLine);

        Game_Grid->addWidget(line_7, 3, 0, 1, 1);

        line_2 = new QFrame(gridFrame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);

        Game_Grid->addWidget(line_2, 0, 1, 1, 1);

        Slot_6 = new QPushButton(gridFrame);
        Slot_6->setObjectName(QString::fromUtf8("Slot_6"));
        Slot_6->setMinimumSize(QSize(150, 150));
        Slot_6->setMaximumSize(QSize(150, 150));
        Slot_6->setFont(font1);
        Slot_6->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_6, 2, 4, 1, 1);

        Slot_3 = new QPushButton(gridFrame);
        Slot_3->setObjectName(QString::fromUtf8("Slot_3"));
        Slot_3->setMinimumSize(QSize(150, 150));
        Slot_3->setMaximumSize(QSize(150, 150));
        Slot_3->setFont(font1);
        Slot_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_3, 0, 4, 1, 1);

        line_5 = new QFrame(gridFrame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setFrameShape(QFrame::VLine);

        Game_Grid->addWidget(line_5, 2, 3, 1, 1);

        line_6 = new QFrame(gridFrame);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setFrameShape(QFrame::VLine);

        Game_Grid->addWidget(line_6, 4, 3, 1, 1);

        line_9 = new QFrame(gridFrame);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShadow(QFrame::Plain);
        line_9->setFrameShape(QFrame::HLine);

        Game_Grid->addWidget(line_9, 3, 4, 1, 1);

        Slot_5 = new QPushButton(gridFrame);
        Slot_5->setObjectName(QString::fromUtf8("Slot_5"));
        Slot_5->setMinimumSize(QSize(150, 150));
        Slot_5->setMaximumSize(QSize(150, 150));
        Slot_5->setFont(font1);
        Slot_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_5, 2, 2, 1, 1);

        line = new QFrame(gridFrame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::VLine);

        Game_Grid->addWidget(line, 2, 1, 1, 1);

        Slot_9 = new QPushButton(gridFrame);
        Slot_9->setObjectName(QString::fromUtf8("Slot_9"));
        Slot_9->setMinimumSize(QSize(150, 150));
        Slot_9->setMaximumSize(QSize(150, 150));
        Slot_9->setFont(font1);
        Slot_9->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_9, 4, 4, 1, 1);

        line_4 = new QFrame(gridFrame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::VLine);

        Game_Grid->addWidget(line_4, 0, 3, 1, 1);

        Slot_1 = new QPushButton(gridFrame);
        Slot_1->setObjectName(QString::fromUtf8("Slot_1"));
        Slot_1->setMinimumSize(QSize(150, 150));
        Slot_1->setMaximumSize(QSize(150, 150));
        Slot_1->setFont(font1);
        Slot_1->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        Game_Grid->addWidget(Slot_1, 0, 0, 1, 1);

        line_10 = new QFrame(gridFrame);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShadow(QFrame::Plain);
        line_10->setFrameShape(QFrame::HLine);

        Game_Grid->addWidget(line_10, 1, 0, 1, 1);

        line_11 = new QFrame(gridFrame);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShadow(QFrame::Plain);
        line_11->setFrameShape(QFrame::HLine);

        Game_Grid->addWidget(line_11, 1, 2, 1, 1);

        line_12 = new QFrame(gridFrame);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShadow(QFrame::Plain);
        line_12->setFrameShape(QFrame::HLine);

        Game_Grid->addWidget(line_12, 1, 4, 1, 1);

        Home = new QPushButton(centralwidget);
        Home->setObjectName(QString::fromUtf8("Home"));
        Home->setGeometry(QRect(280, 510, 111, 41));
        Home->setFont(font);
        game_window->setCentralWidget(centralwidget);
        Home->raise();
        gridFrame->raise();
        Play_Again->raise();

        retranslateUi(game_window);

        QMetaObject::connectSlotsByName(game_window);
    } // setupUi

    void retranslateUi(QMainWindow *game_window)
    {
        game_window->setWindowTitle(QApplication::translate("game_window", "game_window", nullptr));
        Play_Again->setText(QApplication::translate("game_window", "Play Again", nullptr));
        Slot_4->setText(QString());
        Slot_8->setText(QString());
        Slot_7->setText(QString());
        Slot_2->setText(QString());
        Slot_6->setText(QString());
        Slot_3->setText(QString());
        Slot_5->setText(QString());
        Slot_9->setText(QString());
        Slot_1->setText(QString());
        Home->setText(QApplication::translate("game_window", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_window: public Ui_game_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_WINDOW_H
