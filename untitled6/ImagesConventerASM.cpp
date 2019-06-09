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
	int lenghtInPixels = image->h * image->w;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
	int limit = lenghtInPixels * image->format->BytesPerPixel;
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
		mov esi, limit
		wyjasniaj :
			inc eax
			inc eax
			inc eax
			mov ebx, [eax]
			mov ecx, ebx
			and ecx, Rmask
			mov edx, ebx
			and edx, Gmask
			shr edx, 8
			add ecx, edx
			mov edx, ebx
			and edx, Bmask
			shr edx, 16
			add ecx, edx
			cmp ecx, 381
				jb dalej
				or ebx, 0x00ffffff
				jmp dalej2
				dalej:
				and ebx, 0xff000000
				dalej2:
			mov[eax], ebx
			dec esi
			dec esi
			dec esi
			jnz wyjasniaj
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
OperationResult* ImagesConventerASM::EnforceRedImage(SDL_Surface *image) {
	int lenghtInPixels = image->h * image->pitch;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
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
	int lenghtInPixels = image->h * image->w;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
	int limit = lenghtInPixels * image->format->BytesPerPixel / 4;
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
		mov esi, limit
		wyjasniaj:
			inc eax
			inc eax
			inc eax
			inc eax
			mov ebx, [eax]
			not ebx
			mov [eax], ebx
			dec esi
			jnz wyjasniaj
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

OperationResult * ImagesConventerASM::Brighten(SDL_Surface * image)
{
	int lenghtInPixels = image->h * image->w;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
	int limit = lenghtInPixels * image->format->BytesPerPixel;
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
		mov esi, limit
		wyjasniaj :
			inc eax
			inc eax
			inc eax
			mov ebx, [eax]
			//R
			mov ecx, ebx
			and ecx, Rmask
			add ecx, 1111111b
			cmp ecx, 11111111b
			jb dalej
			mov ecx, 11111111b
			dalej:
			and ecx, Rmask
			mov edx, Rmask
			not edx
			or ecx, edx
			or ebx, Rmask
			and ebx, ecx
			//G
				mov ecx, ebx
				and ecx, Gmask
				shr ecx, 8d
				add ecx, 1111111b
				cmp ecx, 11111111b
				jb dalej2
				mov ecx, 11111111b
				dalej2:
				shl ecx, 8d
					and ecx, Gmask
					mov edx, Gmask
				not edx
				or ecx, edx
				or ebx, Gmask
				and ebx, ecx
			//B
					mov ecx, ebx
					and ecx, Bmask
					shr ecx, 16d
					add ecx, 1111111b
					cmp ecx, 11111111b
					jb dalej3
					mov ecx, 11111111b
					dalej3 :
					shl ecx, 16d
					and ecx, Bmask
					mov edx, Bmask
					not edx
					or ecx, edx
					or ebx, Bmask
					and ebx, ecx
			mov[eax], ebx
			dec esi
			dec esi
			dec esi
			jnz wyjasniaj
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
