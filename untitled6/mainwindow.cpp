#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Includes.h"
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

QImage* MainWindow::createFromSurface(SDL_Surface * surf)
{
	QImage* img = new QImage((uchar*)(surf->pixels), surf->w, surf->h, QImage::Format_RGB888);
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
    ui->bitmapa->setPixmap(QPixmap("obraz.jpg"));
}

void MainWindow::on_but_e1_clicked()
{
	image = Load_image("obraz.jpg");


	OperationResult* r = (conventerASM_XMM.EnforceRedImage(image));
	int timeXmm = r->time;

	int timeASM = (conventerASM.EnforceRedImage(image))->time;
	r = (conventerCPP.EnforceRedImage(image));
	int timeCPP = r->time;

	SDL_Surface * surface = r->image;
	ui->bitmapa->setPixmap(QPixmap::fromImage(*createFromSurface(surface)));
    ui->asmTimer->display(timeASM);
    ui->cppTimer->display(timeCPP);
	ui->xmmTimer->display(timeXmm);
	delete r;
}

void MainWindow::on_but_e2_clicked()
{
	image = Load_image("obraz.jpg");

	OperationResult *r1 = (conventerASM_XMM.Negative(image));
	int timeXmm = r1->time;
	image = Load_image("obraz.jpg");
	OperationResult* r2 = (conventerCPP.Negative(image));
	int timeCPP = r2->time;
	image = Load_image("obraz.jpg");
	OperationResult* r3 = (conventerASM.Negative(image));
	int timeASM = r3->time;
	SDL_Surface * surface = r1->image;
	ui->bitmapa->setPixmap(QPixmap::fromImage(*createFromSurface(surface)));
	ui->asmTimer->display(timeASM);
	ui->cppTimer->display(timeCPP);
	ui->xmmTimer->display(timeXmm);
	delete r1;
	delete r2;
	delete r3;

}

void MainWindow::on_but_e3_clicked()
{
	image = Load_image("obraz.jpg");

	OperationResult* r2 = (conventerCPP.Brighten(image));
	int timeCPP = r2->time;
	image = Load_image("obraz.jpg");
	OperationResult *r1 = (conventerASM.Brighten(image));
	int timeASM = r1->time;
	image = Load_image("obraz.jpg");
	OperationResult* r3 = (conventerASM_XMM.Brighten(image));
	int timeXmm = r3->time;
	SDL_Surface * surface = r3->image;
	ui->bitmapa->setPixmap(QPixmap::fromImage(*createFromSurface(surface)));
	ui->asmTimer->display(timeASM);
	ui->cppTimer->display(timeCPP);
	ui->xmmTimer->display(timeXmm);
	delete r1;
	delete r2;
	delete r3;
}

void MainWindow::on_but_e4_clicked()
{
	image = Load_image("obraz.jpg");

	OperationResult* r2 = (conventerCPP.BinarizeImage(image));
	int timeCPP = r2->time;
	image = Load_image("obraz.jpg");
	OperationResult *r1 = (conventerASM.BinarizeImage(image));
	int timeASM = r1->time;
	image = Load_image("obraz.jpg");
	OperationResult* r3 = (conventerASM_XMM.BinarizeImage(image));
	int timeXmm = r3->time;
	SDL_Surface * surface = r1->image;
	ui->bitmapa->setPixmap(QPixmap::fromImage(*createFromSurface(surface)));
	ui->asmTimer->display(timeASM);
	ui->cppTimer->display(timeCPP);
	ui->xmmTimer->display(timeXmm);
	delete r1;
	delete r2;
	delete r3;
}

void MainWindow::on_but_e5_clicked()
{
    ui->asmTimer->display(12.32);
    ui->cppTimer->display(21.42);
}

