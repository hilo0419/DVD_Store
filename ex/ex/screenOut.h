
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

/*
	기능 : 프로그램을 사용하기 위한 메뉴 출력
	반환 : void
*/
void ShowMenu(void);

/*
	고객 관련 메뉴 출력
*/

void ShowCusMenu(void);

/*
	DVD 관련 메뉴 출력
*/
void ShowDvdMenu(void);

/*
	대여 이력 관련 메뉴 출력
*/

void ShowRentalInfoMenu(void);
/*
	기능 : 고객 정보를 출력
	반환 : void
*/
void ShowCustomerInfo(cusInfo * pCus);

void ShowALLCustomerInfo(cusInfo * pCus);


void ShowDVDInfo(dvdInfo * pDVD);

void ShowALLDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

//대여이력 출력
void ShowDVDRecordList(cusInfo * pCus);

/*
	날짜 이력 출력
*/
void ShowDVDDateList(dvdRentInfo pDVD);
#endif // !__SCREENOUT_H__


