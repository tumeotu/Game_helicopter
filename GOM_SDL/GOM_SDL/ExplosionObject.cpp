
#include"ExplosionObject.h"
ExplosionObject::ExplosionObject()
{

}
ExplosionObject::~ExplosionObject()
{ 

}
void ExplosionObject::set_clip()
{
	clip[0].x = 0;
	clip[0].y = 0;
	clip[0].w = EXP_WIDTH;
	clip[0].h = EXP_HIGHT;

	clip[1].x = EXP_WIDTH;
	clip[1].y = 0;
	clip[1].w = EXP_WIDTH;
	clip[1].h = EXP_HIGHT;

	clip[2].x = 2*EXP_WIDTH;
	clip[2].y = 0;
	clip[2].w = EXP_WIDTH;
	clip[2].h = EXP_HIGHT;

	clip[3].x = 3*EXP_WIDTH;
	clip[3].y = 0;
	clip[3].w = EXP_WIDTH;
	clip[3].h = EXP_HIGHT;
}
void ExplosionObject::ShowEx(SDL_Surface *des)
{ 
	if (frame >= 4)
	{
		frame = 0;
	}
	SDL_COMMON_FUNTION::ApplySurfaceClip(this->p_object_, des, &clip[frame], rect.x, rect.y);
}