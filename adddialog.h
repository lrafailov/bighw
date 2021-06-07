#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "common.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();
    void clearContents();

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

signals:
    void gameCreated(Game& game);

private:
    Ui::AddDialog *ui;
};

#endif
