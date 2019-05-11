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
    ui->frame->setVisible(false);
    ui->background->setPixmap(QPixmap(":/images/tlo1.png"));
}

SDL_Surface* Load_image(const char *file_name)
{
	/* Open the image file */
	SDL_Surface* tmp = IMG_Load(file_name);
	if (tmp == NULL) {
		const char* a = SDL_GetError();
		fprintf(stderr, "Couldn't load %s: %s\n",
			file_name, SDL_GetError());
		exit(0);
	}
	return tmp;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::createFromSurface(SDL_Surface * surf)
{
	QImage img(static_cast<uchar*>(surf->pixels), surf->w, surf->h, QImage::Format_RGB32);
	return img;
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
	image = Load_image("bmp_icon.png");
	ui->bitmapa->setPixmap(QPixmap::fromImage(createFromSurface(image)));
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

