#ifndef GLOBAL_VAL_H_
#define GLOBAL_VAL_H_

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


//���ڴ��ݵ㿪�ĸ��ӵ�λ�ú����ֵ���Ϣ�ṹ��
struct OpenGridMsg 
{
	int i;
	int j;
	int stat;//ͼƬ״̬
};


//��GUI::clickOpen()�����л��������Ľӿ�
//�����㷨�и�GUI�ṩ�Ľӿ�
//void clickOpen(int i, int j, vector<OpenGridMsg>& msg)

//���������ʾ״̬��ö������
enum {init=-1,one=1,two=2,three=3,four=4,five=5,six=6,seven=7,eight=8,mine=9}

#endif