#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Globals.cpp"

class ImagesConventerCPP
{
public:
	ImagesConventerCPP();
	~ImagesConventerCPP();
	OperationResult* BinarizeImage(SDL_Surface *image);
	OperationResult* EnforceRedImage(SDL_Surface *image);
	OperationResult* Negative(SDL_Surface *image);
	OperationResult* Brighten(SDL_Surface *image);
private:
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	int tm;
	Globals global;
};

ImagesConventerCPP::ImagesConventerCPP()
{
}

ImagesConventerCPP::~ImagesConventerCPP()
{
}
OperationResult* ImagesConventerCPP::BinarizeImage(SDL_Surface *image) {
	return nullptr;
}
OperationResult* ImagesConventerCPP::EnforceRedImage(SDL_Surface *image) {
	int lenghtInPixels = image->h * image->pitch;
	int bytesPerPixel = image->format->BytesPerPixel;
	int lenghtInBytes = lenghtInPixels * bytesPerPixel;
	SDL_Surface *helper = NULL;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	//If the image is color keyed
	helper = SDL_CreateRGBSurface(SDL_SWSURFACE,
		image->w, image->h, image->format->BitsPerPixel,
		image->format->Rmask, image->format->Gmask, image->format->Bmask, 0);
	helper->pixels = image->pixels;
	void *pixels2 = image->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = global.startTimer();
	for (int i = 0; i < lenghtInPixels; i+=3) {
		pixels2 = (void*)((char*)pixels2 +1);
		pixels2 = (void*)((char*)pixels2 +1);
		pixels2 = (void*)((char*)pixels2 +1);
		int pixelData = *((char*)pixels2);
		pixelData = pixelData | Rmask;
		*((char*)pixels2) = pixelData;
	}
	performanceCountEnd = global.endTimer();
	tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	if (SDL_MUSTLOCK(image))
	{
		SDL_UnlockSurface(image);
	}
	OperationResult * or = new OperationResult();
	SDL_UnlockSurface(helper);
	or ->image = helper;
	or ->time = tm;
	return or ;
}

OperationResult * ImagesConventerCPP::Negative(SDL_Surface * image)
{
	return nullptr;
}

OperationResult * ImagesConventerCPP::Brighten(SDL_Surface * image)
{
	return nullptr;
}