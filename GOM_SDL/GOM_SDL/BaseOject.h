#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include"Header.h"
class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	void show(SDL_Surface*Des);
	bool LoadImg(const char *filename);
	void Setreact(const int x,const int y){ rect.x = x,rect.y = y ;}
	SDL_Rect getrect()const{ return rect;}
	SDL_Surface* getsuface() {return p_object_;}
protected:
	SDL_Rect rect;
	SDL_Surface *p_object_;
};

#endif