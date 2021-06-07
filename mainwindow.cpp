#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&addDialog, SIGNAL(gameCreated(Game&)), this, SLOT(addGame(Game&)));
    connect(&filterDialog, SIGNAL(filterCreated(Game&)), this, SLOT(filterGame(Game&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addGame(Game& game)
{
    games.append(game);
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(game.id));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(game.rated ? "TRUE" : "FALSE"));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(game.victoryStatus));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(game.winner));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(game.whiteId));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(game.whiteRating)));    
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(game.blackId));    
    ui->tableWidget->setItem(row, 7, new QTableWidgetItem(QString::number(game.blackRating)));   
    ui->tableWidget->setItem(row, 8, new QTableWidgetItem(game.allMoves));
}

void MainWindow::deleteGame(int row)
{

    if (row >= ui->tableWidget->rowCount())
        return;

    games.removeAt(row);

    ui->tableWidget->removeRow(row);
}

void MainWindow::filterGame(Game& game)
{

    int row = 0;
    while (row < games.count())
    {

        if (game.victoryStatus.compare(games[row].victoryStatus) != 0)
        {

            deleteGame(row);
        }

        else
        {

            row++;
        }
    }
}

void MainWindow::on_pushButtonOpen_clicked()
{
    ui->tableWidget->clearContents();
    games.clear();
    QString filePath = QFileDialog::getOpenFileName(this, "Read From...", "/", tr("CVS File (*.csv);;"));
    QFile file(filePath);
    if (!filePath.isEmpty() && file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        QString line = stream.readLine();
        while (!file.atEnd())
        {

            line = stream.readLine();  
            QStringList values = line.split(",");
            if (values.count() != 16)
                break;
            Game game;
            game.id = values[0];
            game.rated = (values[1].toUpper().compare("TRUE") == 0 ? true : false);
            game.victoryStatus = values[5];
            game.winner = values[6];
            game.whiteId = values[8];
            game.whiteRating = values[9].toInt();
            game.blackId = values[10];
            game.blackRating = values[11].toInt();
            game.allMoves = values[12];
            addGame(game);
        }
        file.close();
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save To...", nullptr, "CSV File (*.csv);;");
    QFile file(filePath);
    if (!filePath.isEmpty() && file.open(QFile::WriteOnly))
    {

        QTextStream stream(&file);

        stream << "id,rated,victory_status,winner,white_id,white_rating,black_id,black_rating,moves" << endl;

        for (Game game : games)
        {
            stream << game.id << ",";
            stream << (game.rated ? "TRUE," : "FALSE,");
            stream << game.victoryStatus << ",";
            stream << game.winner << ",";
            stream << game.whiteId << ",";
            stream << game.whiteRating << ",";
            stream << game.blackId << ",";
            stream << game.blackRating << ",";
            stream << game.allMoves << endl;
        }

        file.close();
    }
}

void MainWindow::on_pushButtonAdd_clicked()
{
    addDialog.show();
    addDialog.raise();
    addDialog.clearContents();
}

void MainWindow::on_pushButtonDelete_clicked()
{
    int row = ui->tableWidget->selectedItems().first()->row();
    deleteGame(row);
}

void MainWindow::on_pushButtonFilter_clicked()
{
    filterDialog.show();
    filterDialog.raise();
}
