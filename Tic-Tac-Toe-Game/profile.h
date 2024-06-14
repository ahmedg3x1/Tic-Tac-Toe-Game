#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>

namespace Ui {
class profile;
}

class profile : public QWidget
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    ~profile();

private slots:
    void on_save_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
