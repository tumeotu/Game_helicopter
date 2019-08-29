#include"ThreatObject.h"
#define WIDTH_THREAT 80
#define HIGHT_THREAT 33
threatobject::threatobject()
{ 
	rect.x = SCREEN_WIDTH;
	rect.y = 10;
	rect.w = WIDTH_THREAT;
	rect.h = HIGHT_THREAT;

	x_ = 0;
	y_ = 0;
}
threatobject::~threatobject()
{ 
	if (p_amo_list.size() > 0)
	{
		for (int i = 0; i < p_amo_list.size(); i++)
		{
			AmoObject* p_amo = p_amo_list.at(i);
			if (p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
		p_amo_list.clear();
	}
}

void threatobject::Initamo(AmoObject*p_amo)
{ 
	if (p_amo != NULL)
	{
		bool ret = p_amo->LoadImg("sphere2.png");
		if (ret)
		{
			p_amo->set_is_move(true);
			p_amo->setwidthhight(WIDTH_THREAT, HIGHT_THREAT);
			p_amo->settype(AmoObject::SPHERE);
			p_amo->Setreact(rect.x,rect.y+rect.h*0.5);
			p_amo->set_x_(8);
			p_amo_list.push_back(p_amo);
		}
	}
}

void threatobject::Makeamo(SDL_Surface*Des, const int &x_limit, const int & y_mimit)
{
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		AmoObject*p_amo = p_amo_list.at(i);
		if (p_amo)
		{
			if (p_amo->get_is_move() == true)
			{
				p_amo->show(Des);
				p_amo->handlemoveamo();
			}
			else
			{
				p_amo->set_is_move(true);
				p_amo->Setreact(rect.x, rect.y + rect.h*0.5);
			}
		}
	}
}

void threatobject::HandleMove(const int & x_border, const int &y_border)
{
	rect.x -= x_;
	if (rect.x < 0)
	{
		rect.x = SCREEN_WIDTH;
		int rand_y = rand() % 20;
		if (rand_y>SCREEN_HEIGHT)
		{
			rand_y = SCREEN_HEIGHT*0.3;
		}
		rect.y = rand_y*20;
	}

}
void threatobject::HandleInputAction(SDL_Event events)
{ 
	;
}
void threatobject::Resetamo(AmoObject*p_amo)
{
	p_amo->Setreact(rect.x, rect.y + rect.h*0.5);
}
void threatobject::Reset(const int &xboder)
{
	rect.x = xboder;
	int rand_y = rand() % 400;
	if (rand_y>SCREEN_HEIGHT)
	{
		rand_y = SCREEN_HEIGHT*0.3;

	}
	rect.y = rand_y;
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		AmoObject*p_amo = p_amo_list.at(i);
		if (p_amo != NULL)
		{
			Resetamo(p_amo);
		}
	}
}