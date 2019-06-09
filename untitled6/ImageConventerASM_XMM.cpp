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
	int lenghtInPixels = image->h * image->w;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
	SDL_Surface *helper = NULL;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	int limit = lenghtInPixels;
	int dodatek = 0;
	int maxi = 381;
	int maskA = 0x00ffffff;
	int maskB = 0xff000000;
	int ma = 0xffffffff;
	int mini = 0;
	void *pixels2 = image->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = global.startTimer();
	_asm {
		mov eax, pixels2
		mov esi, 0
		movlps xmm2, Rmask
		shufps xmm2, xmm2, 0x00

		movlps xmm3, mini
		shufps xmm3, xmm3, 0x00
		movlps xmm4, maxi
		shufps xmm4, xmm4, 0x00
		wyjasniaj:
		add eax, 9
			movupd xmm0, [eax]
			movsd xmm1, xmm0
			andps xmm1, xmm2
			movsd xmm3, xmm0
			psrlq xmm3, 8d
			andps xmm3, xmm2
			paddq xmm1, xmm3
			movsd xmm3, xmm0
			psrlq xmm3, 16d
			andps xmm3, xmm2
			paddq xmm1, xmm3
			movlps xmm3, mini
			shufps xmm3, xmm3, 0x00

			comiss xmm1, xmm4
			jb dalej
			movlps xmm3, maskA
			movhps xmm3, mini
			shufps xmm3, xmm3, 0xa8
			orps xmm0, xmm3
			jmp ddalej
			dalej:
			movlps xmm3, maskB
				movhps xmm3, ma
			shufps xmm3, xmm3, 0xa8
				andps xmm0, xmm3
			ddalej :
			shufps xmm1, xmm1, 11100001b
			comiss xmm1, xmm4
				jb dalej2
				movlps xmm3, maskA
				movhps xmm3, mini
				shufps xmm3, xmm3, 0xa8
				orps xmm0, xmm3
				jmp ddalej2
				dalej2 :
			movlps xmm3, maskB
				movhps xmm3, ma
				shufps xmm3, xmm3, 0xa8
				andps xmm0, xmm3
				ddalej2 :
		shufps xmm1, xmm1, 11010010b
			comiss xmm1, xmm4
			jb dalej3
			movlps xmm3, maskA
			movhps xmm3, mini
			shufps xmm3, xmm3, 0xa8
			orps xmm0, xmm3
			jmp ddalej3
			dalej3 :
		movlps xmm3, maskB
			movhps xmm3, ma
			shufps xmm3, xmm3, 0xa8
			andps xmm0, xmm3
			ddalej3 :
		shufps xmm1, xmm1, 10000111b
			comiss xmm1, xmm4
			jb dalej4
			movlps xmm3, maskA
			movhps xmm3, mini
			shufps xmm3, xmm3, 0xa8
			orps xmm0, xmm3
			jmp ddalej4
			dalej4 :
		movlps xmm3, maskB
				movhps xmm3, ma
			shufps xmm3, xmm3, 0xa8
			andps xmm0, xmm3
			ddalej4 :
		shufps xmm1, xmm1, 00100111b
			


			movsd[eax], xmm0
			add esi, 3
			cmp limit, esi
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
OperationResult* ImagesConventerASM_XMM::EnforceRedImage(SDL_Surface *image) {
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
	int lenghtInPixels = image->h * image->w;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	int limit = lenghtInPixels;

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
			add eax, 9
			movupd xmm0, [eax]
			pcmpeqd xmm1, xmm1
			andnpd xmm0, xmm1
			movsd [eax], xmm0
			add esi, 3
			cmp limit, esi
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
	return or;
}

OperationResult * ImagesConventerASM_XMM::Brighten(SDL_Surface * image)
{
	int lenghtInPixels = image->h * image->w;
	int bitsPerPixel = image->format->BitsPerPixel;
	int lenghtInBits = lenghtInPixels * bitsPerPixel;
	int Rmask = image->format->Rmask;
	int Gmask = image->format->Gmask;
	int Bmask = image->format->Bmask;
	int limit = lenghtInPixels;
	int dodatek = 0b1111111;
	int maxi = 0b11111111;
	void *pixels2 = image->pixels;

	if (SDL_MUSTLOCK(image))
	{
		SDL_LockSurface(image);
	}
	performanceCountStart = global.startTimer();
	_asm {
		mov eax, pixels2
		mov esi, 0
		movlps xmm2, Rmask
		shufps xmm2, xmm2, 0x00

		movlps xmm3, dodatek
		shufps xmm3, xmm3, 0x00
		movlps xmm4, maxi
		shufps xmm4, xmm4, 0x00
		wyjasniaj:
		add eax, 9
			movupd xmm0, [eax]
			// R
			movlps xmm2, Rmask
			shufps xmm2, xmm2, 0x00
			movsd xmm1, xmm0
			andps xmm1, xmm2

			paddq xmm1, xmm3
			comiss xmm1, xmm4
			jb dalej
			movss xmm1, maxi
			dalej:
			shufps xmm1, xmm1, 11100001b
			comiss xmm1, xmm4
			jb dalej2
			movss xmm1, maxi
			dalej2:
			shufps xmm1, xmm1, 11010010b
			comiss xmm1, xmm4
			jb dalej3
			movss xmm1, maxi
			dalej3:
			shufps xmm1, xmm1, 10000111b
			comiss xmm1, xmm4
			jb dalej4
			movss xmm1, maxi
			dalej4 :
			shufps xmm1, xmm1, 00100111b
			andps xmm1, xmm2
				pcmpeqd xmm3, xmm3
				andnps xmm2, xmm3
				orps xmm1, xmm2
				movlps xmm2, Rmask
				shufps xmm2, xmm2, 0x00

				movlps xmm3, dodatek
				shufps xmm3, xmm3, 0x00
				orps xmm0, xmm2
				andps xmm1, xmm0
				//G 
				movlps xmm2, Gmask

				shufps xmm2, xmm2, 0x00
				movsd xmm1, xmm0
				andps xmm1, xmm2
				psrlq xmm1,  8d
				paddq xmm1, xmm3
				comiss xmm1, xmm4
				jb Gdalej
				movss xmm1, maxi
				Gdalej :
			shufps xmm1, xmm1, 11100001b
				comiss xmm1, xmm4
				jb Gdalej2
				movss xmm1, maxi
				Gdalej2 :
			shufps xmm1, xmm1, 11010010b
				comiss xmm1, xmm4
				jb Gdalej3
				movss xmm1, maxi
				Gdalej3 :
			shufps xmm1, xmm1, 10000111b
				comiss xmm1, xmm4
				jb Gdalej4
				movss xmm1, maxi
				Gdalej4 :
			shufps xmm1, xmm1, 00100111b
				psllq xmm1, 8d
				andps xmm1, xmm2
				pcmpeqd xmm3, xmm3
				andnps xmm2, xmm3
				orps xmm1, xmm2
				movlps xmm2, Gmask
				shufps xmm2, xmm2, 0x00

				movlps xmm3, dodatek
				shufps xmm3, xmm3, 0x00
				orps xmm0, xmm2
				andps xmm1, xmm0
				//B
				movlps xmm2, Bmask

				shufps xmm2, xmm2, 0x00
				movsd xmm1, xmm0
				andps xmm1, xmm2
				psrlq xmm1, 16d
				paddq xmm1, xmm3
				comiss xmm1, xmm4
				jb Bdalej
				movss xmm1, maxi
				Bdalej :
			shufps xmm1, xmm1, 11100001b
				comiss xmm1, xmm4
				jb Bdalej2
				movss xmm1, maxi
				Bdalej2 :
			shufps xmm1, xmm1, 11010010b
				comiss xmm1, xmm4
				jb Bdalej3
				movss xmm1, maxi
				Bdalej3 :
			shufps xmm1, xmm1, 10000111b
				comiss xmm1, xmm4
				jb Bdalej4
				movss xmm1, maxi
				Bdalej4 :
			shufps xmm1, xmm1, 00100111b
				psllq xmm1, 16d
				andps xmm1, xmm2
				pcmpeqd xmm3, xmm3
				andnps xmm2, xmm3
				orps xmm1, xmm2
				movlps xmm2, Bmask
				shufps xmm2, xmm2, 0x00

				movlps xmm3, dodatek
				shufps xmm3, xmm3, 0x00
				orps xmm0, xmm2
				andps xmm1, xmm0

			movsd [eax], xmm0
			add esi, 3
			cmp limit, esi
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
