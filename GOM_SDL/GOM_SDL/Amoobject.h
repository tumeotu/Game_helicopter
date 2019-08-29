
#ifndef amo_
#define amo_
#include"Header.h"
#include "BaseOject.h"
#define WIDTH_AMO_LASER 35
#define HEIGHT_AMO_LASER 5
#define WIDTH_AMO_SPHERE 10
#define HEIGHT_AMO_SPHERE 10

class AmoObject : public BaseObject
{
public:
	enum AmoType
	{
		NONE=0,
		LASER=1,
		SPHERE=2
	};

	AmoObject();
	~AmoObject();

	void HandleInputAction();//SDL_Event events, SDL_Rect rect_obj);
	void HandleMove(const int& x_boder, const int& y_border);
	void handlemoveamo();

	unsigned int get_type() const { return amo_type_; }
	void settype(const int &type){ amo_type_ = type; }

	bool get_is_move()const { return is_move_; }
	void set_is_move(bool is_move){ is_move_ = is_move; }
	void setwidthhight(const int&width,const int &hight){ rect.w = width; rect.h = hight; }

	void set_x_(const int &x){ x_ = x; }
	void set_y_(const int &y){ y_ = y; }

	int get_x_() const{ return x_; }
	int get_y_() const { return y_; }
private:
	int x_;
	int y_;
	bool is_move_;
	unsigned int amo_type_;
};
#endif