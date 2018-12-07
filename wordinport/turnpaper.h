#ifndef TURNPAPER_H
#define TURNPAPER_H

#include <QWidget>

namespace Ui {
class TurnPaper;
}

class TurnPaper : public QWidget
{
    Q_OBJECT

public:
    explicit TurnPaper(QWidget *parent = 0);
    ~TurnPaper();

private slots:
    void on_radioButton_school_clicked();

    void on_radioButton_public_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::TurnPaper *ui;
};

#endif // TURNPAPER_H
