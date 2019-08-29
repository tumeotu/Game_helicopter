#ifndef COMMON_FUNTION_H_
#define COMMON_FUNTION_H_
#include<iostream>
#include<Windows.h>
#include<SDL.h>
#include <ctime>
#include<string>
#include<SDL_image.h>
#include<SDL_mixer.h>
using namespace std;

const int width_background = 4800;
const int hight_background = 600;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

const int MUN_THREAT = 4;

static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Event g_even;

static Mix_Chunk*g_sound_bullet[2];
static Mix_Chunk *g_sound_exp[2];
namespace SDL_COMMON_FUNTION
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void ApplySurfaceClip(SDL_Surface*src, SDL_Surface*des, SDL_Rect*clip, int x, int y);
	bool CheckCollision(const SDL_Rect &object1, const SDL_Rect & object2);
	void CleanUp();
}
#endif