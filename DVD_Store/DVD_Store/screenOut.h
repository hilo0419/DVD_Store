
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

/*
	��� : ���α׷��� ����ϱ� ���� �޴� ���
	��ȯ : void
*/
void ShowMenu(void);

/*
	�� ���� �޴� ���
*/

void ShowCusMenu(void);

/*
	DVD ���� �޴� ���
*/
void ShowDvdMenu(void);

/*
	�뿩 �̷� ���� �޴� ���
*/

void ShowRentalInfoMenu(void);
/*
	��� : �� ������ ���
	��ȯ : void
*/
void ShowCustomerInfo(cusInfo * pCus);

void ShowALLCustomerInfo(cusInfo * pCus);


void ShowDVDInfo(dvdInfo * pDVD);

void ShowALLDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

//�뿩�̷� ���
void ShowDVDRecordList(cusInfo * pCus);

/*
	��¥ �̷� ���
*/
void ShowDVDDateList(dvdRentInfo pDVD);
#endif // !__SCREENOUT_H__


