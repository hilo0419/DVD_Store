#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30


// 도서 장르 정보
enum { ACTION = 1, COMIC, SF, ROMANTIC };
// 대여 상태 정보
enum { RENTED, RETURNED };


typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;//도서 장르 멤버 변수

	// 대여가능여부(대여, 반납)
	int rentState;
	// rentList의 저장 위치정보
} dvdInfo;



#endif // !__DVDINFO_H__