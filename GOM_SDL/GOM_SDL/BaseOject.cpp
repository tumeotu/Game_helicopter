#include"BaseOject.h"
BaseObject::BaseObject()
{
	rect.x = 0;
	rect.y = 0;
	p_object_ = NULL;
}
BaseObject::~BaseObject()
{
	;
}
bool BaseObject::LoadImg(const char * filename)
{
	p_object_ = SDL_COMMON_FUNTION::LoadImage(filename);
	if (p_object_ == NULL)
		return false;
	return true; 

}
void BaseObject::show(SDL_Surface*Des)
{
	if (p_object_ != NULL)
	{
		SDL_COMMON_FUNTION::ApplySurface(p_object_,Des,rect.x,rect.y);
	}

}