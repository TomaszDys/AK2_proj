#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <windows.h>
#include "conventerGlobals.h"

class ImagesConventerASM
{
public:
	ImagesConventerASM();
	~ImagesConventerASM();
	OperationResult* BinarizeImage(SDL_Surface *image);
	OperationResult* EnforceRedImage(SDL_Surface *image);
	OperationResult* Negative(SDL_Surface *image);
	OperationResult* Brighten(SDL_Surface *image);
private:
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	int tm;
};

ImagesConventerASM::ImagesConventerASM()
{
}

ImagesConventerASM::~ImagesConventerASM()
{
}
OperationResult* ImagesConventerASM::BinarizeImage(SDL_Surface *image) {
	return nullptr;
}
OperationResult* ImagesConventerASM::EnforceRedImage(SDL_Surface *image) {
	int lenghtInPixels = image->h * image->pitch;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
	SDL_Surface *helper = NULL;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	//If the image is color keyed
	helper = SDL_CreateRGBSurface(SDL_SWSURFACE,
		image->w, image->h, image->format->BitsPerPixel,
		image->format->Rmask, image->format->Gmask, image->format->Bmask, 0);
	helper->pixels = image->pixels;
	void *pixels2 = helper->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = startTimer();
	_asm {
		mov eax, pixels
		mov esi, 0
		wyjasniaj:
		mov ecx, [eax + esi]
			// zmieniaj to a zobaczysz magiê XD
			sub ecx, 120

			mov[eax + esi], ecx

			add esi, 1
			cmp lenghtInPixels, esi
			jg wyjasniaj
	}
	performanceCountEnd = endTimer();
	tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	if (SDL_MUSTLOCK(image))
	{
		SDL_UnlockSurface(image);
	}
	OperationResult * or = new OperationResult();
	or ->image = helper;
	or ->time = tm;
	SDL_SaveBMP(helper, "bmp_icon2.png");
	return or ;
}

OperationResult * ImagesConventerASM::Negative(SDL_Surface * image)
{
	return nullptr;
}

OperationResult * ImagesConventerASM::Brighten(SDL_Surface * image)
{
	return nullptr;
}
