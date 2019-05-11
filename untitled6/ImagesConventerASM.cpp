#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Globals.cpp"

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
	Globals global;
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

	void *pixels2 = image->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = global.startTimer();
	_asm {
		mov eax, pixels2
		mov esi, 0
		wyjasniaj:
			inc eax
			inc eax
			inc eax
			mov ebx, [eax]
			// zmieniaj to a zobaczysz magiê XD
			or ebx, Rmask
			mov [eax], ebx
			add esi, 3
			cmp lenghtInPixels, esi
			ja wyjasniaj
	}
	performanceCountEnd = global.endTimer();
	tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	if (SDL_MUSTLOCK(image))
	{
		SDL_UnlockSurface(image);
	}
	OperationResult * or = new OperationResult();
	or ->image = image;
	or ->time = tm;
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
