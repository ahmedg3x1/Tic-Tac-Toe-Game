#include <QString>

#include "../ui/ui_profile_menu.h"
#include "profile_menu.h"

extern UserData loggedInHost, loggedInGuest;

extern QString player_1_name, player_2_name;

profile_menu::profile_menu(QWidget *parent, bool history) : QMainWindow(parent), ui(new Ui::profile_menu) {
  ui->setupUi(this);
  myparent = parent;

  if (history) {
    ui->replay->setEnabled(false);

    // create the hitory table
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Date", "Time", "Opponent", "Winner", "Starting Player"});

    if (loggedInHost.games.empty()) {
      QList<QStandardItem *> emptyRow;
      emptyRow.append(new QStandardItem("No Previous Match"));
      model->appendRow(emptyRow);
    } else {
      for (const auto &match : loggedInHost.games) {
        QList<QStandardItem *> row;
        row.append(new QStandardItem(QString::fromStdString(match.date)));
        row.append(new QStandardItem(QString::fromStdString(match.time)));
        row.append(new QStandardItem(QString::fromStdString(match.opponentName)));
        row.append(new QStandardItem(
            (match.won == 0)
                ? "Tie"
                : ((match.won == match.accountHolder) ? "YOU" : QString::fromStdString(match.opponentName))));
        row.append(new QStandardItem(match.accountHolderStarted ? "YOU" : QString::fromStdString(match.opponentName)));
        model->appendRow(row);
      }
    }

    ui->match_list->setModel(model);
    ui->match_list->resizeColumnsToContents();

    ui->stackedWidget->setCurrentWidget(ui->history_page);
  } else {
    ui->user_textbox->setText(player_1_name);
    ui->wins_label->setText(QString::number(wins(player_1_name.toStdString())));
    ui->lose_label->setText(QString::number(loses(player_1_name.toStdString())));
    ui->draw_label->setText(QString::number(ties(player_1_name.toStdString())));

    ui->stackedWidget->setCurrentWidget(ui->profile_page);
  }
}

profile_menu::~profile_menu() { delete ui; }

void profile_menu::on_profile_menu_destroyed() {}

\
void profile_menu::closeEvent(QCloseEvent *event)
{
    // Schedule the window for deletion after the event loop has processed all events
    this->deleteLater();
    // Optionally, call the base class implementation if needed
    QWidget::closeEvent(event);
}


void profile_menu::on_profile_menu_destroyed(QObject *arg1) {}

void profile_menu::on_replay_clicked() {
  my_history_window = new game_window(this, false, false, selected_match);
  my_history_window->setWindowModality(Qt::ApplicationModal);
  hide();
  my_history_window->show();
}

void profile_menu::on_back_clicked() { close(); }

void profile_menu::on_match_list_clicked(const QModelIndex &index) {
  ui->replay->setEnabled(true);
  selected_match = loggedInHost.games[index.row()];
}
