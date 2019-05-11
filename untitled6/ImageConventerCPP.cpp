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
	return nullptr;
}

OperationResult * ImagesConventerCPP::Negative(SDL_Surface * image)
{
	return nullptr;
}

OperationResult * ImagesConventerCPP::Brighten(SDL_Surface * image)
{
	return nullptr;
}