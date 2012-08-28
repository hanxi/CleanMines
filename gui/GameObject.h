#ifndef GAME_OBJECT_H_H
#define GAME_OBJECT_H_H

#include "FLTK.h"

class GameObject
{
public:
	GameObject(void);
	virtual ~GameObject(void);

protected:
	Fl_Image* m_pImage;
};

inline GameObject::GameObject(void):m_pImage(NULL)
{
}

inline GameObject::~GameObject(void)
{
	if (m_pImage != NULL)
	{
		delete m_pImage;
	}
}

//�������е�С����
//������ʾ����/����/�հ�/����/����/�ʺŵ�
class GridBlock:public GameObject
{
public:
	GridBlock(void);
	virtual ~GridBlock(void);
};
inline GridBlock::GridBlock(void)
{
	m_pImage = new Fl_PNG_Image();
}
#endif