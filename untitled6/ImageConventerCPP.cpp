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
	int lenghtInPixels = image->h * image->w;
	int bytesPerPixel = image->format->BytesPerPixel;
	int lenghtInBytes = lenghtInPixels * bytesPerPixel;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	int Amask = image->format->Amask;
	//If the image is color keyed
	void *pixels2 = image->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = global.startTimer();
	for (int i = 0; i < lenghtInBytes; i += 3) {
		pixels2 = (void*)((char*)pixels2 + 3);
		int pixelData = *(int*)pixels2;
		int r = pixelData & Rmask;
		int g = pixelData & Gmask;
		g = g >> 8;
		int b = pixelData & Bmask;
		b = b >> 16;
		int brightness = (r + g + b);
		if (brightness >= 381) {
			pixelData |= 0x00ffffff;
		}
		else {
			pixelData &= (int)0xff000000;
		}
		*((int*)pixels2) = pixelData;
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
OperationResult* ImagesConventerCPP::EnforceRedImage(SDL_Surface *image) {
	int lenghtInPixels = image->h * image->pitch;
	int bytesPerPixel = image->format->BytesPerPixel;
	int lenghtInBytes = lenghtInPixels * bytesPerPixel;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
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
	or ->image = image;
	or ->time = tm;
	return or ;
}

OperationResult * ImagesConventerCPP::Negative(SDL_Surface * image)
{
	int lenghtInPixels = image->h * image->w;
	int bytesPerPixel = image->format->BytesPerPixel;
	int lenghtInBytes = lenghtInPixels * bytesPerPixel;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	int Amask = image->format->Amask;
	//If the image is color keyed
	
	void *pixels2 = image->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = global.startTimer();
	for (int i = 0; i < lenghtInBytes/4; i++) {
		pixels2 = (void*)((int*)pixels2 + 1);
		int pixelData = *(int*)pixels2;
		pixelData = ~pixelData;
		*((int*)pixels2) = pixelData;
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
	return or;
}

OperationResult * ImagesConventerCPP::Brighten(SDL_Surface * image)
{
	int lenghtInPixels = image->h * image->w;
	int bytesPerPixel = image->format->BytesPerPixel;
	int lenghtInBytes = lenghtInPixels * bytesPerPixel;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	int Amask = image->format->Amask;
	//If the image is color keyed

	void *pixels2 = image->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = global.startTimer();
	for (int i = 0; i < lenghtInBytes; i+=3) {
		pixels2 = (void*)((char*)pixels2 + 3);
		int pixelData = *(int*)pixels2;

		int pixelCData = pixelData & Rmask;
		//R
		if(pixelCData + 0b1111111 < 0b11111111)
			pixelCData += 0b1111111;
		else
			pixelCData = 0b11111111;
		pixelCData &= Rmask;
		pixelCData = (pixelCData | ~Rmask);
		pixelData = pixelData | Rmask;
		pixelData &= pixelCData;
		//G
		pixelCData = pixelData & Gmask;
		pixelCData = pixelCData >> 8;
		if (pixelCData + 0b1111111 < 0b11111111)
			pixelCData += 0b1111111;
		else
			pixelCData = 0b11111111;
		pixelCData = pixelCData << 8;
		pixelCData &= Gmask;
		pixelCData = (pixelCData | ~Gmask);
		pixelData = pixelData | Gmask;
		pixelData &= pixelCData;
		////B
		pixelCData = pixelData & Bmask;
		pixelCData = pixelCData >> 16;
		if (pixelCData + 0b1111111 < 0b11111111)
			pixelCData += 0b1111111;
		else
			pixelCData = 0b11111111;
		pixelCData = pixelCData << 16;
		pixelCData &= Bmask;
		pixelCData = (pixelCData | ~Bmask);
		pixelData = pixelData | Bmask;
		pixelData &= pixelCData;
		*((int*)pixels2) = pixelData;
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