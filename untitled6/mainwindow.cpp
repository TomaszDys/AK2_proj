#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->but_e1->setVisible(false);
    ui->but_e2->setVisible(false);
    ui->but_e3->setVisible(false);
    ui->but_e4->setVisible(false);
    ui->but_e5->setVisible(false);
    ui->frame->setVisible(true);
    ui->background->setPixmap(QPixmap(":/images/tlo1.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_but_wyj_clicked()
{
    QMessageBox::StandardButton odp;
    odp = QMessageBox::warning(this, "Wyjście", "Czy na pewno chcesz wyjść?", QMessageBox::Yes | QMessageBox::No );

    if (odp == QMessageBox::Yes) exit(0);
}

void MainWindow::on_but_start_clicked()
{
    ui->but_e1->setVisible(true);
    ui->but_e2->setVisible(true);
    ui->but_e3->setVisible(true);
    ui->but_e4->setVisible(true);
    ui->but_e5->setVisible(true);
    ui->frame->setVisible(true);
    ui->bitmapa->setPixmap(QPixmap(":/images/bmp_icon.png"));
}

void MainWindow::on_but_e1_clicked()
{
    //ui->bitmapa->setPixmap(QPixmap::fromImage(createFromSurface(surface)));
    ui->cTimer->display(12.32);
    ui->asmTimer->display(21.42);
}

void MainWindow::on_but_e2_clicked()
{
    ui->cTimer->display(12.32);
    ui->asmTimer->display(21.42);
}

void MainWindow::on_but_e3_clicked()
{
    ui->cTimer->display(12.32);
    ui->asmTimer->display(21.42);
}

void MainWindow::on_but_e4_clicked()
{
    ui->cTimer->display(12.5/4.21);
    ui->asmTimer->display(21.42);
}

void MainWindow::on_but_e5_clicked()
{
    ui->cTimer->display(12.32);
    ui->asmTimer->display(21.42);
}

