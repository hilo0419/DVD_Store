/*
	���   : �� ���� ���� �� ���� �Լ����� ����.
	�ۼ��� : SJY �븮
	�ۼ��� : 2019-03-11
	Ver    : 1.0
*/

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

/*
	��� : cusInfo �Ҵ� �� ����
	��ȯ : ���� �� ��ϵ� ������ ����,
		   ���� �� 0�� ��ȯ.
*/
int AddCusInfo(char * ID, char * name, char * num);

/*
	��� : �ش� cusInfo �� phonenum �� ������ ����.
	��ȯ ������ 1; ���н� 0;
*/

int ChangeCusInfo(char * ID, char * num);


/*
	��� : �ش�� ID ������ �����. �ش� cusInfo �迭�� ����.
	��ȯ : �� ������ ��ȯ
*/


int eraseCusInfo(char*ID);
/*
	��� : ���Ե� ��� ȸ�� ����Ʈ�� ���.
	��ȯ : void;

*/

int AllPutCusInfo(void);
/*
	��� : �ش� �� ID�� ������ ������ �ִ�
			�����͸� ��ȯ
	��ȯ : ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
*/


cusInfo * GetCusPtrByID(char * ID);

/*
	��� : ���Ե� ID���� üũ
	��ȯ : ���ԵǾ����� 1, �ƴϸ� 0�� ��ȯ.
*/
int IsregistID(char * ID);


//����
void LoadCusInfoList(void);


//���

void SaveCusInfoList(void);

#endif // !__CUSACCESS_H__