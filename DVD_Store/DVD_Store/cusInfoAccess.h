/*
	기능   : 고객 정보 저장 및 참조 함수들의 선언.
	작성자 : SJY 대리
	작성일 : 2019-03-11
	Ver    : 1.0
*/

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

/*
	기능 : cusInfo 할당 및 저장
	반환 : 성공 시 등록된 정보의 개수,
		   실패 시 0을 반환.
*/
int AddCusInfo(char * ID, char * name, char * num);

/*
	기능 : 해당 cusInfo 의 phonenum 의 내용을 변경.
	반환 성공시 1; 실패시 0;
*/

int ChangeCusInfo(char * ID, char * num);


/*
	기능 : 해당고객 ID 정보를 지운다. 해당 cusInfo 배열을 삭제.
	반환 : 총 고객수를 반환
*/


int eraseCusInfo(char*ID);
/*
	기능 : 가입된 모든 회원 리스트를 출력.
	반환 : void;

*/

int AllPutCusInfo(void);
/*
	기능 : 해당 고객 ID의 정보를 가지고 있는
			포인터를 반환
	반환 : 등록 안된 ID의 경우 NULL 포인터 반환.
*/


cusInfo * GetCusPtrByID(char * ID);

/*
	기능 : 가입된 ID인지 체크
	반환 : 가입되었으면 1, 아니면 0을 반환.
*/
int IsregistID(char * ID);


//복구
void LoadCusInfoList(void);


//백업

void SaveCusInfoList(void);

#endif // !__CUSACCESS_H__