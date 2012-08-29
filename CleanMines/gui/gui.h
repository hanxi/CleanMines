#ifndef GUI_H_
#define GUI_H_

#include "FLTK.h"
#include "globalVal.h"
#include "GameObject.h"

class GUI
{
public:
	GUI(void);
	virtual ~GUI(void);

	void show(void);

protected:
	void creatWindow(const char* a_winName="扫雷（FLTK版）");
	void releaseWindow(void);
	void creatGameObjects(void);
	void releaseGameObjects(void);

private:
	Fl_Window* m_pWindow;//主窗体
	Background* m_background;//背景
};

inline GUI::GUI(void)
{
	creatWindow();
	creatGameObjects();
}
inline GUI::~GUI(void)
{
	releaseGameObjects();
	releaseWindow();
}

inline void GUI::show(void)
{
	m_pWindow->end();
	m_pWindow->show();
}

inline void GUI::creatWindow(const char* a_winName)
{
	m_pWindow = new Fl_Window(WIN_WIDTH,WIN_HEIGHT,a_winName);
}
inline void GUI::releaseWindow(void)
{
	delete m_pWindow;
}
inline void GUI::creatGameObjects(void)
{
	m_background = new Background("res/images/bg.jpg");
}
inline void GUI::releaseGameObjects(void)
{
	delete m_background;
}
#endif