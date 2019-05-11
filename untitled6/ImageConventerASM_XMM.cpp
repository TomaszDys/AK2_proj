#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Globals.cpp"

class ImagesConventerASM_XMM
{
public:
	ImagesConventerASM_XMM();
	~ImagesConventerASM_XMM();
	OperationResult* BinarizeImage(SDL_Surface *image);
	OperationResult* EnforceRedImage(SDL_Surface *image);
	OperationResult* Negative(SDL_Surface *image);
	OperationResult* Brighten(SDL_Surface *image);
private:
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	int tm;
};

ImagesConventerASM_XMM::ImagesConventerASM_XMM()
{
}

ImagesConventerASM_XMM::~ImagesConventerASM_XMM()
{
}
OperationResult* ImagesConventerASM_XMM::BinarizeImage(SDL_Surface *image) {
	return nullptr;
}
OperationResult* ImagesConventerASM_XMM::EnforceRedImage(SDL_Surface *image) {
	return nullptr;
}

OperationResult * ImagesConventerASM_XMM::Negative(SDL_Surface * image)
{
	return nullptr;
}

OperationResult * ImagesConventerASM_XMM::Brighten(SDL_Surface * image)
{
	return nullptr;
}
