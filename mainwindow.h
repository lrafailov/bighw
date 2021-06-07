#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QList>
#include "common.h"
#include "adddialog.h"
#include "filterdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOpen_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonAdd_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonFilter_clicked();
    void addGame(Game& game);
    void deleteGame(int row);
    void filterGame(Game& game);

private:
    Ui::MainWindow *ui;

    QList<Game> games;

    AddDialog addDialog;

    FilterDialog filterDialog;
};
#endif
