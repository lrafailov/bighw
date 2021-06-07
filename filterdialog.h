#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include "common.h"

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

signals:
    void filterCreated(Game& game);

private:
    Ui::FilterDialog *ui;
};

#endif
