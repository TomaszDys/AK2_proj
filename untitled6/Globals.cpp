#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
struct OperationResult {
	SDL_Surface *image;
	int time;
};
static class Globals {
public:
	static LARGE_INTEGER startTimer()
	{
		LARGE_INTEGER start;
		DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
		QueryPerformanceCounter(&start);
		SetThreadAffinityMask(GetCurrentThread(), oldmask);
		return start;
	}
	static LARGE_INTEGER endTimer()
	{
		LARGE_INTEGER stop;
		DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
		QueryPerformanceCounter(&stop);
		SetThreadAffinityMask(GetCurrentThread(), oldmask);
		return stop;
	}

	static SDL_Surface* Load_image(const char *file_name)
	{
		/* Open the image file */
		SDL_Surface* tmp = IMG_Load(file_name);
		if (tmp == NULL) {
			const char* a = SDL_GetError();
			exit(0);
		}
		return tmp;
	}
};

