#include <QMessageBox>
#include "filterdialog.h"
#include "ui_filterdialog.h"

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

void FilterDialog::on_pushButtonOk_clicked()
{
    Game game;
    game.victoryStatus = ui->comboBoxVictoryStatus->currentText();
    emit filterCreated(game);
    this->hide();
}

void FilterDialog::on_pushButtonCancel_clicked()
{
    this->hide();
}
