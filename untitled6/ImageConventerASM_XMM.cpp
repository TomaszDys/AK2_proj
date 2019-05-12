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
	Globals global;
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
			add eax, 12

			movups xmm0, [eax]
			movlps xmm1, Rmask
			shufps xmm1, xmm1, 0xaa
			orps xmm0, xmm1
			movsd [eax], xmm0
			add esi, 12
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

OperationResult * ImagesConventerASM_XMM::Negative(SDL_Surface * image)
{
	return nullptr;
}

OperationResult * ImagesConventerASM_XMM::Brighten(SDL_Surface * image)
{
	return nullptr;
}
