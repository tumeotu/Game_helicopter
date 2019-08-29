#ifndef Mainobject_H_
#define Mainobject_H_
#include"BaseOject.h"
#include"Header.h"
#include<vector>
#include"Amoobject.h"
#define width_main 80
#define hight_main 46
class MainObject:public BaseObject
{
public:
	MainObject();
	~MainObject();
	void handleinputaction(SDL_Event events, Mix_Chunk*sound_bullet[2]);
	void handlemove();
	void setamolist(vector<AmoObject*>amo_list){ p_amo_list = amo_list; }
	vector<AmoObject*>getamolist(){ return p_amo_list;}
	void MakeAmo(SDL_Surface*g_screen);
	void Remove(const int & idx);


private:
	int x_;
	int y_;
	vector<AmoObject*> p_amo_list;
};

#endif