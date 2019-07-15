#ifndef __MANAGER_H__
#define __MANAGER_H__

/*
	기능 : 신규 회원 가입
	반환 : void
*/
void RegisterCustomer(void);

/*
	기능 : ID를 통한 회원 검색
	반환 : void
*/
void SearchCusInfo(void);
/*
	 기능 : ID를 통한 회원 정보 수정.
	 반환 : void
*/

void UdateCusInfo(void);
/*
	기능 : 회원 삭제
	반환 : void
*/

void DelCusInfo(void);

/*
	가입된 고객 전부 출력
*/
void AllcusInfo(void);
/*
	DVD 등록
*/
void RegistDVD(void);
/*
	DVD 조회
*/
void SearchDVDInfo(void);
/*
	 기능 : ISBN를 통한 DVD 정보 수정.
	 반환 : void
*/

void UdateDVDInfo(void);
/*
	기능 : DVD 삭제
	반환 : void
*/

void DelDVDInfo(void);


/*
	등록된 DVD 전부 출력
*/
void AllDVDInfo(void);

/*
	DVD 대여
*/

void RentalDVD(void);
/*
	DVD 반납
*/
void ReturnDVD(void);
/*
	DVD 대여이력
*/
void RecordDVD(void);
/*
	DVD 대여날짜 조회
*/
void RecordDateDVD(void);


/*
	데이터 복구 
*/

void InitData(void);



#endif