// AK2Proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#undef main
using namespace std;
SDL_Surface* Load_image(char *file_name)
{
	/* Open the image file */
	SDL_Surface* tmp = IMG_Load(file_name);
	if (tmp == NULL) {
		fprintf(stderr, "Couldn't load %s: %s\n",
			file_name, SDL_GetError());
		exit(0);
	}
	return tmp;
}
int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded!";
	}

	cin.get();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
