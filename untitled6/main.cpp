#include "mainwindow.h"
#include <QApplication>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



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
void changeSthInImage(SDL_Surface *image) {
	int lenght = image->h * image->pitch;
	char tab[4000];
	SDL_Surface *flipped = NULL;

	//If the image is color keyed
			flipped = SDL_CreateRGBSurface(SDL_SWSURFACE, 
			image->w, image->h, image->format->BitsPerPixel, 
			image->format->Rmask, image->format->Gmask, image->format->Bmask, 0);
	void *pixels2 = flipped->pixels;

	if (SDL_MUSTLOCK(image))
	{
		//Lock the surface
		SDL_LockSurface(image);
	}
	_asm {
		mov eax, pixels2
		mov ecx, [eax]
		mov [eax], 999999999999
		mov [eax+12], 99919999999999
		mov [eax+123], 99992134999999999
		mov [eax+121], 999999999999999
		mov [eax+12121], 999999999999999
		mov [eax+20], 999999999999999
		mov [eax+16], 99999999213499
		mov [eax+24], 999999999999999
		mov pixels2, eax
	}
	if (SDL_MUSTLOCK(image))
	{
		//Lock the surface
		SDL_UnlockSurface(image);
	}
	SDL_SaveBMP(flipped, "bmp_icon2.png");
}

int main(int argc, char *argv[])
{
	Uint32 flags;
	SDL_Surface *screen, *image;
	int depth, done;
	SDL_Event event;

	/* Initialize the SDL library */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		return(255);
	}

	flags = SDL_SWSURFACE;
	image = Load_image("bmp_icon.png");
	changeSthInImage(image);
	unsigned nPixels = image->w * image->h;	
	unsigned nBytes = nPixels * image->format->BytesPerPixel;
	void * tmpBuf = calloc(nPixels, image->format->BytesPerPixel);
    QApplication a(argc, argv);
	string pictureData = "BitsPerPixel =" + (image->format->BitsPerPixel);
	pictureData.append("BytesPerPixel = " + image->format->BytesPerPixel);
	pictureData.append("\nwidth " + image->w);
	pictureData += "height " + image->h;	
    MainWindow w;
    w.show();

    return a.exec();
}
