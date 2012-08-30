#ifndef GAME_OBJECT_H_H
#define GAME_OBJECT_H_H

#include "../FLTK.h"
#include <cassert>
#include <memory>
using std::auto_ptr;

class GameObject
{
public:
	GameObject(void);
	void setImage(const char* filename);
	GameObject(const char* filename);
	GameObject(const GameObject& a_rightSide)
	{
		m_pBox.reset(new Fl_Box(a_rightSide.getX(),a_rightSide.getY(),
			a_rightSide.getWidth(),a_rightSide.getHeight()));//����һ���µĴ�Сλ����ͬ��box
		m_pSharedImage = Fl_Shared_Image::get(a_rightSide.m_pSharedImage->name());//��ȡ��ͬ��sharedImage
		m_pImage.reset(m_pSharedImage->copy(a_rightSide.getWidth(),a_rightSide.getHeight()));//����һ����С��ͬ��Image
		m_pBox->image(m_pImage.get());
	}
	GameObject& operator=(const GameObject& a_rightSide)
	{
		m_pBox->resize(a_rightSide.getX(),a_rightSide.getY(),
			a_rightSide.getWidth(),a_rightSide.getHeight());
		m_pSharedImage = Fl_Shared_Image::get(a_rightSide.m_pSharedImage->name());
		m_pImage.reset(m_pSharedImage->copy(a_rightSide.getWidth(),a_rightSide.getHeight()));//����һ����С��ͬ��Image
		m_pBox->image(m_pImage.get());
		return *this;
	}
	~GameObject(void)
	{
		//û����Ҫɾ����
	}

	void show(void);
	void hide(void);

	float getX(void)const {return m_pBox->x();}
	float getY(void)const {return m_pBox->y();}
	float getWidth(void)const {return m_pBox->w();}
	float getHeight(void)const {return m_pBox->h();}
	void setPosition(float a_x, float a_y);
	void setSize(float a_width, float a_height);

private:
	auto_ptr<Fl_Box> m_pBox;
	auto_ptr<Fl_Image> m_pImage;
	Fl_Shared_Image* m_pSharedImage;
};
inline GameObject::GameObject(void)
:m_pSharedImage(NULL)
{
	m_pBox.reset(new Fl_Box(0,0,0,0));
}
inline GameObject::GameObject(const char* filename)
:m_pSharedImage(NULL)
{
	m_pBox.reset(new Fl_Box(0,0,0,0,0));
	setImage(filename);//����ͼƬ
}
inline void GameObject::setImage(const char *filename)
{
	fl_register_images();
	m_pSharedImage = Fl_Shared_Image::get(filename);
	m_pImage.reset(m_pSharedImage->copy());
	m_pBox->image(m_pImage.get());
}

inline void GameObject::show(void)
{
	m_pBox->show();
}
inline void GameObject::hide(void)
{
	m_pBox->hide();
}

inline void GameObject::setPosition(float a_x, float a_y)
{
	m_pBox->position(a_x,a_y);
}
inline void GameObject::setSize(float a_width, float a_height)
{
	m_pBox->size(a_width,a_height);
	m_pImage.reset(m_pSharedImage->copy(a_width,a_height));
	m_pBox->image(m_pImage.get());//�����޸�image,��Ϊ֮ǰ��image���Զ�����
}

#endif