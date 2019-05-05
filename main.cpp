#include "mainwindow.h"
#include <QApplication>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include "conventerGlobals.h"

using namespace std;

int main(int argc, char *argv[])
{
	/* Initialize the SDL library */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		return(255);
	}
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
