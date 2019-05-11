#include "mainwindow.h"
#include <QApplication>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



//SDL_Surface* Load_image(const char *file_name)
//{
//	/* Open the image file */
//	SDL_Surface* tmp = IMG_Load(file_name);
//	if (tmp == NULL) {
//		const char* a = SDL_GetError();
//		fprintf(stderr, "Couldn't load %s: %s\n",
//			file_name, SDL_GetError());
//		exit(0);
//	}
//	return tmp;
//}
//
//void changeSthInImage(SDL_Surface *image) {
//	int lenghtInPixels = image->h * image->pitch;
//	int bitsPerPixel = image->format->BitsPerPixel;
//	int lenghtInBits = lenghtInPixels * bitsPerPixel;
//	SDL_Surface *helper = NULL;
//	int Rmask = image->format->Rmask;
//	int Gmask = image->format->Gmask;
//	int Bmask = image->format->Bmask;
//	//If the image is color keyed
//	helper = SDL_CreateRGBSurface(SDL_SWSURFACE, 
//	image->w, image->h, image->format->BitsPerPixel, 
//	image->format->Rmask, image->format->Gmask, image->format->Bmask, 0);
//	helper->pixels = image->pixels;
//	void *pixels2 = helper->pixels;
//
//	if (SDL_MUSTLOCK(image))
//	{
//		SDL_LockSurface(image);
//	}
//	_asm {
//		mov eax, pixels2
//		mov esi, 0
//		wyjasniaj:
//		mov ecx, [eax +esi]
//		mov ebx, ecx
//		mov edx, ecx
//
//		and ecx, Rmask
//		and ebx, Gmask
//		and edx, Bmask
//		// zmieniaj to a zobaczysz magie XD
//		add ecx, 150
//		add ebx, 50
//		add edx, 50
//			
//		add ecx, ebx
//		add edx, ecx
//		mov [eax +esi], edx
//		add esi, 2
//		cmp lenghtInPixels, esi
//		jne wyjasniaj
//		mov pixels2, eax
//	}
//	if (SDL_MUSTLOCK(image))
//	{
//		SDL_UnlockSurface(image);
//	}
//	SDL_SaveBMP(helper, "bmp_icon2.png");
//}

int main(int argc, char *argv[])
{
	//Uint32 flags;
	//SDL_Surface *screen, *image;
	//int depth, done;
	//SDL_Event event;

	/* Initialize the SDL library */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		return(255);
	}

	//flags = SDL_SWSURFACE;
	//image = Load_image("bmp_icon.png");
	//changeSthInImage(image);
	//unsigned nPixels = image->w * image->h;	
	//unsigned nBytes = nPixels * image->format->BytesPerPixel;
	//void * tmpBuf = calloc(nPixels, image->format->BytesPerPixel);
    QApplication a(argc, argv);
/*	string pictureData = "BitsPerPixel =" + (image->format->BitsPerPixel);
	pictureData.append("BytesPerPixel = " + image->format->BytesPerPixel);
	pictureData.append("\nwidth " + image->w);
	pictureData += "height " + image->h;*/	
    MainWindow w;
    w.show();

    return a.exec();
}