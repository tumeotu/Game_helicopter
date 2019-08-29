#ifndef Threat_H_
#define Threat_H_
#include"BaseOject.h"
#include"Header.h"
#include"manobject.h"
#include<vector>
class threatobject :public BaseObject
{
public:
	threatobject();
	~threatobject();

	void HandleMove(const int& x_border, const int &y_border);
	void HandleInputAction(SDL_Event events);
	void set_x_(const int& val){ x_ = val; }
	void set_y_(const int &val){ y_ = val; }
	int get_x_()const { return x_; }
	int get_y_()const { return y_; }
	void setamolist(vector<AmoObject*>amo_list){ p_amo_list = amo_list; }
	vector<AmoObject*>getamolist(){ return p_amo_list; }
	void Initamo(AmoObject*p_amo);
	void Makeamo(SDL_Surface*Des, const int &x_limit, const int & y_mimit);
	void Reset(const int &xboder);
	void Resetamo(AmoObject*p_amo);
private:
	int x_;
	int y_;
	vector<AmoObject*> p_amo_list;
};
#endif