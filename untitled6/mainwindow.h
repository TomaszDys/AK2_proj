#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	SDL_Surface *screen, *image;

	QImage MainWindow::createFromSurface(SDL_Surface * surf);
	
private slots:
    void on_but_wyj_clicked();

    void on_but_start_clicked();

    void on_but_e1_clicked();

    void on_but_e3_clicked();

    void on_but_e2_clicked();

    void on_but_e4_clicked();

    void on_but_e5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
