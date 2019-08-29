#include"Amoobject.h"
AmoObject::AmoObject()
{
	rect.x = 0;
	rect.y = 0;
	x_ = 0;
	y_ = 0;
	is_move_ = false;
	amo_type_ = NONE;
}
AmoObject::~AmoObject()
{ 
	;
}
void AmoObject::HandleMove(const int & x_border, const int & y_border)
{
	rect.x += x_;
	if (rect.x > x_border)
	{ 
		is_move_ = false;
	}
}
void AmoObject::HandleInputAction()
{
	;
}
void AmoObject::handlemoveamo()
{
	rect.x -= x_;
	if (rect.x < 0)
	{
		is_move_ = false;
	}
}