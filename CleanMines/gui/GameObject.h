#ifndef GAME_OBJECT_H_H
#define GAME_OBJECT_H_H

#include "../FLTK.h"
#include <cassert>
#include <memory>
#include <iostream>
using std::auto_ptr;

//���ڷ���ͼƬ��ͼƬ��
class GridBlock:public Fl_Box
{
public:
	GridBlock(void):Fl_Box(0,0,0,0,0) {}
	GridBlock(const char* filename):Fl_Box(0,0,0,0,0)
	{
		setImage(filename);
	}
	GridBlock(const GridBlock& a_rightSide)
	:Fl_Box(a_rightSide.getX(),a_rightSide.getY(),a_rightSide.getWidth(),a_rightSide.getHeight(),0)
	{
		m_x = a_rightSide.getX();
		m_y = a_rightSide.getY();
		m_width = a_rightSide.getWidth();
		m_height = a_rightSide.getHeight();
		m_pSharedImage = Fl_Shared_Image::get(a_rightSide.m_pSharedImage->name());//��ȡ��ͬ��sharedImage
		m_pImage.reset(m_pSharedImage->copy(m_width,m_height));//����һ����С��ͬ��Image
		image(m_pImage.get());
		redraw();
	}
	GridBlock& operator=(const GridBlock& a_rightSide)
	{
		m_x = a_rightSide.getX();
		m_y = a_rightSide.getY();
		m_width = a_rightSide.getWidth();
		m_height = a_rightSide.getHeight();
		resize(m_x,m_y,m_width,m_height);
		m_pSharedImage = Fl_Shared_Image::get(a_rightSide.m_pSharedImage->name());//��ȡ��ͬ��sharedImage
		m_pImage.reset(m_pSharedImage->copy(m_width,m_height));//����һ����С��ͬ��Image
		image(m_pImage.get());
		redraw();
		return *this;
	}

	//����ͼƬ
	void setImage(const char *filename)
	{
		fl_register_images();
		m_pSharedImage = Fl_Shared_Image::get(filename);
		m_pImage.reset(m_pSharedImage->copy());
		image(m_pImage.get());
		redraw();
	}

	int getX(void)const {return x();}
	int getY(void)const {return y();}
	int getWidth(void)const {return w();}
	int getHeight(void)const {return h();}
	void setPosition(int a_x, int a_y) {position(a_x,a_y);}
	void setSize(int a_width, int a_height)
	{
		m_width = a_width;
		m_height = a_height;
		size(m_width,m_height);
		m_pImage.reset(m_pSharedImage->copy(m_width,m_height));
		image(m_pImage.get());//�����޸�image,��Ϊ֮ǰ��image���Զ�����
		redraw();
	}

	//Event����
	int handle(int event)
	{
		if (!m_enable) return (0);//�㿪���ֺ�ʧȥ����Ȩ
		using std::cout;
		using std::endl;
		switch (event)
		{
		case FL_PUSH:
			switch (Fl::event_button())//ֻ�������¼�
			{
			case FL_LEFT_MOUSE:
				cout << "������������" << endl;
				cout << "x=" << Fl::event_x() << ",y=" << Fl::event_y() << endl;
				//m_pSharedImage = Fl_Shared_Image::get("res/images/bg.jpg");
				//m_pImage.reset(m_pSharedImage->copy(m_width,m_height));
				//image(m_pImage.get());//�����޸�image,��Ϊ֮ǰ��image���Զ�����
				//redraw();
				leftClick();//�������¼�����
				break;
			case FL_RIGHT_MOUSE:
				rightClick();//�����һ��¼�
				break;
			}
			break;
		}
		return 0;
	}

	void leftClick(void)
	{
//		pGUI->clickOpen(m_lineNumber,m_columnNumber);
		;//�������£�
		;//���ݸ���Ϣ(�����кź��к�)��GUI => GUI���ú����㷨��ȡ�㿪�����и��ӺͶ�Ӧ������ => ���ݵ�ͼ����setImage(image[k]).k����[0,9]�����ø���Ϊ������Ӧ�¼�setDisable()
		;//GUI������һ�����ֵ�ͼ��-1��ʾ��ʼ̬��0~9��ʾ�㿪������֡��������ֶ�Ӧ�Ÿ���ͼƬ,9��ʾ�㵽�˵��ף�GameOver
		;//
		;//��������¼����øø���Ϊ������Ӧ�¼�״̬�����ú����㷨����������ֵ������ȡ���º�ĵ�ͼ״�壬����ͼƬ
		;//��Ҫ������ô������¼����ݸ�GUI,��GUI����������ͼƬ�ĸ�����
	}
	void rightClick(void)
	{
		;//�����һ��¼���״��ת��������ͼƬ������ǡ����족�͡��ʺš�״�����ò�����Ӧ����¼��������ÿ���Ӧ����¼�
	}

private:
	auto_ptr<Fl_Image> m_pImage;//ͼƬ
	Fl_Shared_Image* m_pSharedImage;//������ͼƬ
	int m_x,m_y;
	int m_width,m_height;
	bool m_enable;//�Ƿ������Ӧ�¼������㿪���ֺ����Ϊfalse��
	bool m_isableLeftClick;//�Ƿ������Ӧ����¼�
	int m_lineNumber;//�����к�
	int m_columnNumber;//�����к�
};
#endif