#include"manobject.h"
MainObject::MainObject()
{
	rect.x = 0;
	rect.y = 0;
	rect.w = width_main;
	rect.y = hight_main;
	x_ = 0;
	y_ = 0;
}	
MainObject::~MainObject()
{
}
void MainObject::handleinputaction(SDL_Event events, Mix_Chunk*bullet_sound[2])
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_w: y_ -= hight_main / 5;
			break;
		case SDLK_s: y_ += hight_main / 5;
			break;
		case SDLK_a: x_ -= hight_main / 5;
			break;
		case SDLK_d: x_ += hight_main / 5;
			break;;
		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_w: y_ += hight_main / 5;
			break;
		case SDLK_s: y_ -= hight_main / 5;
			break;
		case SDLK_a: x_ += hight_main / 5;
			break;
		case SDLK_d: x_ -= hight_main / 5;
			break;;
		default:
			break;
		}
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		AmoObject*p_amo = new AmoObject();
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			p_amo->setwidthhight(WIDTH_AMO_LASER, HEIGHT_AMO_LASER);
			p_amo->LoadImg("laser1.png");
			p_amo->settype(AmoObject::LASER);
			Mix_PlayChannel(-1, bullet_sound[0],0);
		}
		else if (events.button.button == SDL_BUTTON_RIGHT)
		{
			p_amo->setwidthhight(WIDTH_AMO_SPHERE, HEIGHT_AMO_SPHERE);
			p_amo->LoadImg("sphere.png");
			p_amo->settype(AmoObject::SPHERE);
			Mix_PlayChannel(-1, bullet_sound[1], 0);
		}
		p_amo->Setreact(this->rect.x + 60, this->rect.y + 38);
		p_amo->set_is_move(true);
		p_amo->set_x_(20);
		p_amo_list.push_back(p_amo);
	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{

	}
	else
	{
		;
	}
}

void MainObject::MakeAmo(SDL_Surface*g_screen)
{ 
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		AmoObject*p_amo = p_amo_list.at(i);
		if (p_amo != NULL)
		{
			p_amo->show(g_screen);
			p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
		}
		else
		{
			if (p_amo != NULL)
			{
				p_amo_list.erase(p_amo_list.begin() + i);
				delete p_amo;
				p_amo = NULL;
			}
		}
	}
}
void MainObject::handlemove()
{
	rect.x += x_;
	if (rect.x<0 || rect.x + width_main>SCREEN_WIDTH)
	{
		rect.x -= x_;
	}
	rect.y += y_;
	if (rect.y<0 || rect.y+hight_main>(SCREEN_HEIGHT - 170))
	{
		rect.y -= y_;
	}

}
void MainObject::Remove(const int& idx)
{
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		if (idx < p_amo_list.size())
		{
			AmoObject*p_amo1 = p_amo_list.at(idx);
			p_amo_list.erase(p_amo_list.begin() + idx);
			if (p_amo1 != NULL)
			{
				delete p_amo1;
				p_amo1 = NULL;
			}
		}
	}
}