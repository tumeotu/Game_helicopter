#include<iostream>
#include<Windows.h>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include"Header.h"
#include"manobject.h"
#include"ThreatObject.h"
#include"ExplosionObject.h"

using namespace std;

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
	{
		return false;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return false;
	// read file wav audio
	g_sound_bullet[0] = Mix_LoadWAV("GunSilence.wav");
	g_sound_bullet[1] = Mix_LoadWAV("Shotgun.wav");
	g_sound_exp[0] = Mix_LoadWAV("ExplosionMain.wav");
	g_sound_exp[1] = Mix_LoadWAV("ExplosionMain1.wav");
	if (g_sound_bullet[0] == NULL || g_sound_bullet[1] == NULL || g_sound_exp[0] == NULL || g_sound_exp[1] == NULL)
		return false;
	return true;
}
int main(int arc, char* argv[])
{
	int bkgn_x = 0;
	bool is_quit = false;
	if (Init() == false)
		return 0;
	g_bkground = SDL_COMMON_FUNTION::LoadImage("bk3.png");
	if (g_bkground == NULL)
	{
		return 0;
	}
	//SDL_COMMON_FUNTION::ApplySurface(g_bkground, g_screen, 0, 0);

	// make mainobject
	MainObject human_object;
	human_object.Setreact(100, 200);
	bool ret = human_object.LoadImg("plane_fly.png");
	if (!ret)
	{
		return 0;
	}

	// init explpsion
	ExplosionObject exp_main;
	ret = exp_main.LoadImg("exp_main.png");
	exp_main.set_clip();
	if (ret == false)
	{
		return 0;
	}

	//human_object.show(g_screen);
    // make threat
	threatobject* p_threats = new threatobject[MUN_THREAT];
	for (int iu = 0; iu < MUN_THREAT; iu++)
	{
		int rand_y = rand() % 400;
		if (rand_y>SCREEN_HEIGHT)
		{
			rand_y = SCREEN_HEIGHT*0.3;

		}
		threatobject*p_threat = (p_threats + iu);
		if (p_threat!=NULL)
		{
			ret = p_threat->LoadImg("af1.png");
			p_threat->Setreact(SCREEN_WIDTH + iu * 400, rand_y);
			p_threat->set_x_(5);
			if (!ret)
			{
				return 0;
			}
			AmoObject*p_amo = new AmoObject();
			p_threat->Initamo(p_amo);
		}
	}
	while (!is_quit)
	{
		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			human_object.handleinputaction(g_even,g_sound_bullet);
		}

		
		if (bkgn_x < -3500)
			bkgn_x -=0 ;
		else
			bkgn_x -= 2;
		SDL_COMMON_FUNTION::ApplySurface(g_bkground, g_screen, bkgn_x, 0);

		//apply background
		
		human_object.handlemove();
		human_object.show(g_screen);
		human_object.MakeAmo(g_screen);
	
		// run threat	
		for (int i = 0; i < MUN_THREAT; i++)
		{
			(p_threats + i)->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			(p_threats + i)->show(g_screen);
			(p_threats + i)->Makeamo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);


			//checkcolision main with amo_threat
			std::vector<AmoObject*> amo_list_th = (p_threats + i)->getamolist();
			bool is_col = SDL_COMMON_FUNTION::CheckCollision((p_threats + i)->getrect(), human_object.getrect());
			for (int tt = 0; tt < amo_list_th.size(); tt++)
			{
				AmoObject*p_amo1 = amo_list_th.at(tt);
				is_col = SDL_COMMON_FUNTION::CheckCollision(human_object.getrect(), p_amo1->getrect());
			}
			if (is_col)
			{
				for (int ex = 0; ex < 4; ex++)
				{
				
					int x_pos = (human_object.getrect().x + human_object.getrect().w*0.5) - EXP_WIDTH*0.5;
					int y_pos = (human_object.getrect().y + human_object.getrect().h*0.5) - EXP_HIGHT*0.5;
					exp_main.set_frame(ex);
					exp_main.Setreact(x_pos,y_pos);
					exp_main.ShowEx(g_screen);
					Mix_PlayChannel(-1, g_sound_exp[1], 0);
					SDL_Delay(150);
					// Update sceen
					if (SDL_Flip(g_screen) == -1)
						return 0;
					
				}

				if (MessageBox(NULL, L"GAM OVER!", L"Battle Arena ^.^", MB_OK) == IDOK)
				{
					delete[] p_threats;
					SDL_COMMON_FUNTION::CleanUp();
					SDL_Quit();
					return 1;
				}
			}
			//checkcolision threat with amo_main
			std::vector<AmoObject*>amo_list = human_object.getamolist();
			for (int ii = 0; ii < amo_list.size(); ii++)
			{
				AmoObject*p_amo = amo_list.at(ii);
				if (p_amo != NULL)
				{
					bool ret_col = SDL_COMMON_FUNTION::CheckCollision(p_amo->getrect(), (p_threats + i)->getrect());
					if (ret_col)
					{
						for (int ex = 0; ex < 4; ex++)
						{

							int x_pos = ((p_threats + i)->getrect().x + (p_threats + i)->getrect().w*0.5) - EXP_WIDTH*0.5;
							int y_pos = ((p_threats + i)->getrect().y + (p_threats + i)->getrect().h*0.5) - EXP_HIGHT*0.5;
							exp_main.set_frame(ex);
							exp_main.Setreact(x_pos, y_pos);
							//Mix_PlayChannel(-1, g_sound_exp[1], 0);
							exp_main.ShowEx(g_screen);
							// Update sceen
							if (SDL_Flip(g_screen) == -1)
								return 0;

						}
						(p_threats + i)->Reset(SCREEN_WIDTH + i * 400);
						human_object.Remove(ii);
					}
				}
			}
			
		}
		// Update sceen
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}
	delete[] p_threats;
	SDL_COMMON_FUNTION::CleanUp();
	SDL_Quit();
	return 1;
}