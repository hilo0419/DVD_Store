#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"
#include "dvdInfoAccess.h"

void ShowMenu(void)
{
	system("cls"); //stdlib.h

	printf("----- 메 뉴 ----- \n");
	
	printf(" 1. 회 원 \n");
	printf(" 2. D V D\n");
	printf(" 3. 이 력 조 회\n");
	printf(" 4. 종료 \n");
	printf("----------------- \n");
	printf("선택 >> ");
}


/*
	고객 관련 메뉴 출력
*/
void ShowCusMenu(void)
{
	system("cls");

	printf(" 1. 신규가입 \n");
	printf(" 2. 회원조회 \n");
	printf(" 3. 회원 정보 수정 \n");
	printf(" 4. 회원탈퇴 \n");
	printf(" 5. 전체 회원 목록 \n");
	printf(" 6. 메인 메뉴\n ");
	printf("----------------- \n");
	printf("선택 >> ");
}

/*
	DVD 관련 메뉴 출력
*/

void ShowDvdMenu(void)
{
	system("cls");
	printf(" 1. DVD 등록 \n");
	printf(" 2. DVD 조회 \n");
	printf(" 3. DVD 정보 수정 \n");
	printf(" 4. DVD 삭제 \n");
	printf(" 5. 전체 DVD 목록 \n");
	printf(" 6. DVD 대여 \n");
	printf(" 7. DVD 반납 \n");
	printf(" 8. 메인메뉴로\n");
	printf("----------------- \n");
	printf("선택 >> ");

}
/*
	대여 이력 관련 메뉴 출력
*/


void ShowRentalInfoMenu(void)
{
	system("cls");

	printf(" 1. DVD 대여이력\n");
	printf(" 2. DVD 기간조회\n");
	printf(" 3. 메인메뉴로\n");
	printf("----------------- \n");
	printf("선택 >> ");

}

void ShowCustomerInfo(cusInfo * pCus)
{
	printf("");
	printf("----------------- \n");
	printf(" ID : %s \n", pCus->ID);
	printf(" Name : %s \n", pCus->name);
	printf(" Phone : %s \n", pCus->phoneNum);
	printf("----------------- \n");

	getchar();
}

void ShowALLCustomerInfo(cusInfo * pCus)
{
	
	printf("----------------- \n");
	printf(" ID : %s \n", pCus->ID);
	printf(" Name : %s \n", pCus->name);
	printf(" Phone : %s \n", pCus->phoneNum);
	printf("----------------- \n");

	
}

void ShowDVDInfo(dvdInfo * pDVD)
{
	printf("\n");
	printf(" ISBN : %s \n", pDVD->ISBN);
	printf(" TITLE : %s \n", pDVD->title);
	printf(" 장르 :  "); ShowGenre(pDVD->genre);
	printf("\n 대여확인 : %s", CheckDVDState(pDVD->ISBN) ? "대여가능" : "대여중");
	printf("\n");

	getchar();

}

void ShowALLDVDInfo(dvdInfo * pDVD)
{
	printf("---------------\n");
	printf(" ISBN : %s \n", pDVD->ISBN);
	printf(" TITLE : %s \n", pDVD->title);
	printf(" 장르 :  "); ShowGenre(pDVD->genre);
	printf("\n 대여확인 : %s\n", CheckDVDState(pDVD->ISBN) ? "대여가능" : "대여중");
	printf("---------------\n");
}

//대여이력 출력
void ShowDVDRecordList(cusInfo * pCus){


	printf(" ID : %s \n", pCus->ID);
	printf(" Name : %s \n", pCus->name);
	printf(" Phone : %s \n", pCus->phoneNum);
	
	getchar();
}




void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		printf("액션");
		break;
	case COMIC:
		printf("코믹");
		break;
	case SF:
		printf("SF");
		break;
	case ROMANTIC:
		printf("로맨스");
		break;
	}
}

/*
	날짜 이력 출력
*/
void ShowDVDDateList(dvdRentInfo pDVD)
{

	printf("\n");

	printf("---- 대여일 : %d ----\n ", pDVD.rentDay);
	printf(" ID : %s \n", pDVD.ID);
	printf(" ISBN : %s \n", pDVD.ISBN);
	

	getchar();

}