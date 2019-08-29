#ifndef EX
#define EX
#include"BaseOject.h"
#include "Header.h"

const int EXP_WIDTH = 165;
const int EXP_HIGHT = 165;

class ExplosionObject : public BaseObject
{
public: 
	ExplosionObject();
	~ExplosionObject();
	void set_clip();
	void set_frame(const int &fr) { frame = fr; }
	void ShowEx(SDL_Surface * des);
private:
	int frame;
	SDL_Rect clip[4];
};

#endif