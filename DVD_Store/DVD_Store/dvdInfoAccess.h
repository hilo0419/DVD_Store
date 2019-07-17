#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

/*
	��� : dvdInfo ������� �Ҵ� �� ����ü
			�迭�� ����
	��ȯ : ���� �� ��ϵ� ������ ��,
			���� �� 0�� ��ȯ.
*/
int AddDVDInfo(char * ISBN, char * title, int genre);
/*
	��� : �ش� ISBN ��ȣ�� �޾� �ش� ISBN�� ����� dvdInfo ��������� ����.
	��ȯ : ������ ��ϵ� DVD �� �� ��ȯ.
*/

/*
	��� : �ش� ISBN �� ���� Ȥ�� �帣 ���� �� ������ ����.
	��ȯ ������ 1; ���н� 0;
*/

int ChangeDVDInfo(char * ISBN, char * title, int gen);


int eraseDVDInfo(char * ISBN);



/*
	��� : ���Ե� ��� ȸ�� ����Ʈ�� ���.
	��ȯ : void;

*/

int AllPutDVDInfo(void);
/*
	��� : �ش� ISBN�� ������ ��� �ִ� ������
			�����͸� ��ȯ.
	��ȯ : ��ϵ��� ���� ISBN�� ��� NULL
			�����͸� ��ȯ.
*/
dvdInfo * GetDVDPtrByISBN(char * ISBN);

/*
	��� : �� ��ϵ� ISBN���� üũ.
	��ȯ : ��ϵǾ����� 1, �ƴϸ� 0�� ��ȯ.
*/
int IsRegistISBN(char * ISBN);

/*
	��� : dvdInfo �迭�� ��ϵ� ISBN�� �뿩������ �ƴ��� üũ
	��ȯ : �뿩���� �ϸ� 1, �뿩���̸�  0��ȯ.
*/

int CheckDVDState(char*ISBN);
/*
	��� : dvdInfo �迭�� �뿩�ϰ��� �ϴ� ISBN�� ID�� �뿩��¥ �� �Է��� �뿩���º���.
	��ȯ : ������ �뿩 Ƚ�� �ݳ�, ���н� 0�� �ݳ�.
*/
int AddDVDRecord(char*ISBN);
/*
	��� : �ش� ISBN �� ���� �뿩 ���� ��  0(�뿩����)���� �ٲ۴�.
	��ȯ : void �ص� �ɵ�.
*/
void ChangeDVDState(char*ISBN);

/*
	��� : ISBN ��  numOfRentCus���� �� �ݳ�.
*/
int ReturnDVDRentNum(char*ISBN);

/*
	DVD ��¥ �뿩 ��ȸ.
	��� : ISBN�� dvdRentInfo ����ü�� firstDay ~ secondDay���� ���� ��¥ ã�Ƽ�
		   dvdRentInfo* temp�� ����.
	��ȯ : dvdRentInfo* temp
*/

int SearchDateDVD(char *ISBN, char* ID, int firstDay, int secondDay);


//����
void LoadDVDInfoList(void);

//���

void SaveDVDINfoList(void);

#endif