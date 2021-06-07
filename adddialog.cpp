#include "adddialog.h"
#include "ui_adddialog.h"
#include <QMessageBox>


AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}


AddDialog::~AddDialog()
{
    delete ui;
}


void AddDialog::clearContents()
{
    ui->lineEditGameId->setText("");
    ui->lineEditWhiteId->setText("");
    ui->lineEditWhiteRating->setText("0");
    ui->lineEditBlackId->setText("");
    ui->lineEditBlackRating->setText("0");
}

void AddDialog::on_pushButtonOk_clicked()
{
    Game game;
    if (ui->lineEditGameId->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "ID cannot be empty.");
        return;
    }
    game.id = ui->lineEditGameId->text();
    game.rated = (ui->comboBoxRated->currentText().compare("TRUE") == 0 ? true : false);
    game.victoryStatus = ui->comboBoxVictoryStatus->currentText();
    game.winner = ui->comboBoxWinner->currentText();
    if (ui->lineEditWhiteId->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "White ID cannot be empty.");
        return;
    }
    game.whiteId = ui->lineEditWhiteId->text();
    if (ui->lineEditWhiteRating->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "White rating cannot be empty.");
        return;
    }
    bool ok = true;
    game.whiteRating = ui->lineEditWhiteRating->text().toInt(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "Warning", "White rating must be an integer.");
        return;
    }
    if (ui->lineEditBlackId->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Black ID cannot be empty.");
        return;
    }
    game.blackId = ui->lineEditBlackId->text();
    if (ui->lineEditBlackRating->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Black rating cannot be empty.");
        return;
    }
    ok = true;
    game.blackRating = ui->lineEditBlackRating->text().toInt(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "Warning", "Black rating must be an integer.");
        return;
    }
    if (ui->lineEditAllMoves->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "All moves cannot be empty.");
        return;
    }
    game.allMoves = ui->lineEditAllMoves->text();
    emit gameCreated(game);
    this->hide();
}

void AddDialog::on_pushButtonCancel_clicked()
{
    this->hide();
}
