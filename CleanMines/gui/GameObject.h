#ifndef GAME_OBJECT_H_H
#define GAME_OBJECT_H_H

#include "FLTK.h"
#include <cassert>

class GameObject
{
public:
	GameObject(void);
	virtual ~GameObject(void);

	virtual void show(void);
	virtual void hide(void);

	float getX(void)const {return m_x;}
	float getY(void)const {return m_y;}
	float getWidth(void)const {return m_width;}
	float getHeight(void)const {return m_height;}
	void setPosition(float a_x, float a_y);
	void setSize(float a_width, float a_height);

protected:
	Fl_Box* m_pBox;
	Fl_Image* m_pImage;
	float m_x,m_y;//position
	float m_width,m_height;//size
};

inline GameObject::GameObject(void)
:m_pBox(NULL),m_pImage(NULL),m_x(0),m_y(0),m_width(0),m_height(0)
{
}

inline GameObject::~GameObject(void)
{
}

inline void GameObject::show(void)
{
	assert(m_pImage != NULL);
	m_pBox->show();
}
inline void GameObject::hide(void)
{
	assert(m_pImage != NULL);
	m_pBox->hide();
}

inline void GameObject::setPosition(float a_x, float a_y)
{
	m_x = a_x;
	m_y = a_y;
}
inline void GameObject::setSize(float a_width, float a_height)
{
	m_width = a_width;
	m_height = a_height;
}


//背景
class Background:public GameObject
{
public:
	Background(const char *filename);
	virtual ~Background(void);
};
inline Background::Background(const char *filename)
{
	assert(filename != NULL);
	setPosition(0,0);
	setSize(WIN_WIDTH,WIN_HEIGHT);
	m_pBox = new Fl_Box(FL_FLAT_BOX,m_x,m_y,m_width,m_height,0);
	m_pImage = new Fl_JPEG_Image(filename);
	m_pBox->image(m_pImage);
	m_pBox->color(fl_rgb_color(30, 144, 255));
}
inline Background::~Background(void)
{
	delete m_pBox;
	delete m_pImage;
}

//网格子中的小方块
//用于显示地雷/数字/空白/格子/红旗/问号等
class GridBlock:public GameObject
{
public:
	GridBlock(const char* filename);
	virtual ~GridBlock(void);
};
inline GridBlock::GridBlock(const char* filename)
{
	assert(filename != NULL);
	m_pImage = new Fl_PNG_Image(filename);
}
inline GridBlock::~GridBlock(void)
{
	delete m_pImage;
}
#endif