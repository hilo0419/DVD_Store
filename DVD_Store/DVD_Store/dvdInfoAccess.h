#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

/*
	기능 : dvdInfo 저장공간 할당 및 구조체
			배열에 저장
	반환 : 성공 시 등록된 정보의 수,
			실패 시 0을 반환.
*/
int AddDVDInfo(char * ISBN, char * title, int genre);
/*
	기능 : 해당 ISBN 번호를 받아 해당 ISBN이 저장된 dvdInfo 저장공간을 삭제.
	반환 : 성공시 등록된 DVD 수 를 반환.
*/

/*
	기능 : 해당 ISBN 의 제목 혹은 장르 변경 의 내용을 변경.
	반환 성공시 1; 실패시 0;
*/

int ChangeDVDInfo(char * ISBN, char * title, int gen);


int eraseDVDInfo(char * ISBN);



/*
	기능 : 가입된 모든 회원 리스트를 출력.
	반환 : void;

*/

int AllPutDVDInfo(void);
/*
	기능 : 해당 ISBN의 정보를 담고 있는 변수의
			포인터를 반환.
	반환 : 등록되지 않은 ISBN의 경우 NULL
			포인터를 반환.
*/
dvdInfo * GetDVDPtrByISBN(char * ISBN);

/*
	기능 : 기 등록된 ISBN인지 체크.
	반환 : 등록되었으면 1, 아니면 0을 반환.
*/
int IsRegistISBN(char * ISBN);

/*
	기능 : dvdInfo 배열에 등록된 ISBN을 대여중인지 아닌지 체크
	반환 : 대여가능 하면 1, 대여중이면  0반환.
*/

int CheckDVDState(char*ISBN);
/*
	기능 : dvdInfo 배열에 대여하고자 하는 ISBN에 ID와 대여날짜 를 입력후 대여상태변경.
	반환 : 성공시 대여 횟수 반납, 실패시 0을 반납.
*/
int AddDVDRecord(char*ISBN);
/*
	기능 : 해당 ISBN 의 도서 대여 상태 를  0(대여가능)으로 바꾼다.
	반환 : void 해도 될듯.
*/
void ChangeDVDState(char*ISBN);

/*
	기능 : ISBN 의  numOfRentCus변수 값 반납.
*/
int ReturnDVDRentNum(char*ISBN);

/*
	DVD 날짜 대여 조회.
	기능 : ISBN의 dvdRentInfo 구조체의 firstDay ~ secondDay사이 같은 날짜 찾아서
		   dvdRentInfo* temp에 저장.
	반환 : dvdRentInfo* temp
*/

int SearchDateDVD(char *ISBN, char* ID, int firstDay, int secondDay);


//복구
void LoadDVDInfoList(void);

//백업

void SaveDVDINfoList(void);

#endif