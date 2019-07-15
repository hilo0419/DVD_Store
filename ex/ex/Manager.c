#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"
#include "screenOut.h"

//extern dvdRentInfo *tempRentInfo[];

void RegisterCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	printf("ID 입력 : ");
	gets(ID);

	if (IsregistID(ID))
	{
		puts("해당 ID는 사용중입니다.");
		getchar();
		return;
	}

	printf("이름 입력 : ");
	gets(name);

	printf("전화번호 입력 : ");
	gets(phoneNum);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("데이터 저장에 실패했습니다.");
		getchar();
		return;
	}

	puts("회원 가입이 되었습니다.");
	getchar();
}


void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * cusPtr;

	printf("찾을 ID 입력 : ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("존재하지 않는 ID입니다.");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}

/*
	 기능 : ID를 통한 회원 정보 수정.
	 반환 : void
*/

void UdateCusInfo(void)
{
	char id[ID_LEN];
	char num[PHONE_LEN];

	printf("ID 입력 : ");
	gets(id);

	if (!IsregistID(id)) {
		printf("회원이 아닙니다.");
		getchar();
		return;
	}

	printf("변경 하실 전화 번호를 입력해주세요 :");//지금 당장 수정할만한게 전화번호 밖에 없음.
	gets(num);

	if (ChangeCusInfo(id, num)) {//id,phone num 받아서 성공하면 1 실패 0
		printf("회원 수정이 완료 되었습니다.");
		getchar();
	}
	else {
		printf("회원 수정이 실패 하였습니다.");
		getchar();
	}
}

/*
	가입된 고객 전부 출력
*/
void AllcusInfo(void)
{	
	printf("------전체 회원 목록 ------\n");
	AllPutCusInfo();
	getchar();
	printf("--------------------------");

}



/*
	기능 : 회원 삭제
	반환 : void
*/

void DelCusInfo(void)
{
	char id[ID_LEN];

	printf("탈퇴를 원하는 회원 ID 를 입력해주세요 :");
	scanf("%s", id);
	getchar();

	if (GetCusPtrByID(id) == 0) {
		printf("가입 된 회원 이 아닙니다.\n");
		getchar();
		return;
	}

	if (eraseCusInfo(id)) { //회원 삭제 시작. 
		printf("탈퇴에 성공하셨습니다.");
		getchar();
	}
	else
		printf("탈퇴에 실패하였습니다.");
	
}

void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN 입력 : ");
	gets(ISBN);

	if (IsRegistISBN(ISBN))
	{
		puts("해당 ISBN은 이미 등록되었습니다.");
		getchar();
		return;
	}

	printf("제목 입력 : ");
	gets(title);

	printf("장르 입력 (1.액션, 2.코믹, 3.SF, 4.로맨틱)");
	scanf("%d", &genre);
	getchar();

	if (!AddDVDInfo(ISBN, title, genre))
	{
		puts("DVD 데이터 저장에 실패했습니다.");
		getchar();
		return;
	}

	puts("등록이 완료되었습니다.");
	getchar();
}

void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dvdPtr;

	printf("찾는 ISBN 입력 : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);
	if (dvdPtr == 0)
	{
		puts("등록되지 않은 ISBN입니다.");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

/*
	 기능 : ISBN를 통한 DVD 정보 수정.
	 반환 : void
*/

void UdateDVDInfo(void)
{
	char isbn[ISBN_LEN];
	char title[TITLE_LEN];
	int gen;

	printf("수정 하실 도서 등록 번호를 입력해주세요.\n");
	gets(isbn);
	if (!IsRegistISBN(isbn)) {
		printf("없는 도서등록 번호 입니다.\n");
		getchar();
		return;
	}

	printf("변경 된 도서 제목을 입력해주세요.\n");
	gets(title);

	printf("변경 된 도서 장르를 입력해주세요.\n");
	printf("장르 입력 (1.액션, 2.코믹, 3.SF, 4.로맨틱)");
	scanf("%d", &gen);
	getchar();

	if (ChangeDVDInfo(isbn, title, gen)) {
		printf("도서 정보 수정 완료하였습니다.");
		getchar();
	}
	else {
		printf("도서 정보 수정이 실패하였습니다.");
		getchar();
	}
	   

}


/*
	기능 : DVD 삭제
	반환 : void
*/

void DelDVDInfo(void)
{
	char ISBN[ISBN_LEN];

	printf("삭제 하고 싶은 DVD 등록번호를 입력해주세요 :");
	scanf("%s", ISBN);
	getchar();

	if (!GetDVDPtrByISBN(ISBN)) {
		printf("등록되지 않은 DVD 입니다.\n");
		getchar();
		return;
	}


	eraseDVDInfo(ISBN);//삭제 시작
	printf("%s DVD가 삭제 되었습니다.", ISBN);
	getchar();
	
	
}

/*
	등록된 DVD 전부 출력
*/
void AllDVDInfo(void)
{
	printf("-----------등록된 DVD LIST------------\n");
	AllPutDVDInfo();
	printf("-------------------------------------\n");
	getchar();

}


/*
	DVD 대여
*/

void RentalDVD(void) {
	//ID 입력
	//등록된 아이디 체크
	//ISBN 입력
	//ISBN 체크
	//대여가능 인지 체크
	//대여날짜 입력
	// 입력된 ID, ISBN 저장. 성공후 멘트 출력.

	char id[ID_LEN];
	char isbn[ISBN_LEN];
	int rentDate;
	int AddState;

	printf("등록하신 ID를 입력해주세요 : ");
	scanf("%s", id);
	if (IsregistID(id)) {
		printf("대여하고자하는 도서 등록번호를 입력해주세요 : ");
		scanf("%s", isbn);
		if (IsRegistISBN(isbn)) {
			if (CheckDVDState(isbn)) { //대여중인지 아닌지 체크
				printf("대여날짜를 입력해주세요 : ");
				scanf("%d", &rentDate);
				AddState = AddDVDRecord(isbn);//대여함수 호출

				if (AddState) printf("대여를 완료\n");
				else {
					printf("대여실패\n");
					return;
				}

				AddRentList(id, isbn, rentDate);

				getchar();
				getchar();
				return;
			}
			else {
				printf("해당 도서는 대여중입니다.\n");
				getchar();
				getchar();
				return;
			}
		}
		else {
			printf("등록되지 않은 도서 등록번호 입니다.\n");
			getchar();
			getchar();
			return;
		}
	}
	else {
		printf("등록되지 않은 ID입니다.\n");
		getchar();
		getchar();
		return;
	}
}


/*
	DVD 반납
*/
void ReturnDVD(void)
{
	//도서 등록번호 입력
	//도서 등록번호 체크
	//도서 대여상태 변경.
	char isbn[ISBN_LEN];

	printf("반납하시는 도서등록번호를 입력해주세요 : ");
	scanf("%s", isbn);

	if (IsRegistISBN(isbn)) {
		if (!CheckDVDState(isbn)) {
			ChangeDVDState(isbn);//대여가능으로 바꿈
			printf("정상적으로 반납을 하였습니다.\n");
			getchar();
			getchar();
			return;
		}
		else {
			printf("해당 도서는 대여중이 아닙니다.\n");
			getchar();
			getchar();
			return;

		}
	}
	else {
		printf("등록되지 않은 도서번호 입니다.\n");
		getchar();
		getchar();
		return;
	}
}


/*
	DVD 대여이력
*/
void RecordDVD(void)
{
	char isbn[ISBN_LEN];

	printf("도서등록 번호를 입력해주세요 : ");
	scanf("%s", isbn);
	if (IsRegistISBN(isbn)) {
		//cnt = ReturnDVDRentNum(isbn);
		SearchRentISBN(isbn);
	}
	else {
		printf("등록되지 않은 도서번호 입니다.\n");
		getchar();
		
		return;
	}

}
/*
	DVD 대여날짜 조회
*/
void RecordDateDVD(void) {

	char isbn[ISBN_LEN];
	char id[ID_LEN];
	int firstDate;
	int secondDate;
	int cnt;
	printf("등록하신 ID를 입력해주세요 : ");
	scanf("%s", id);
	if (IsregistID(id)) {
		printf("도서등록 번호를 입력해주세요 : ");
		scanf("%s", isbn);
		if (IsRegistISBN(isbn)) {

			printf("조회 하고 싶은 처음 날짜 입력해주세요.");
			scanf("%d", &firstDate);
			printf("조회 하고 싶은 마지막 날짜 입력해주세요.");
			scanf("%d", &secondDate);

			cnt = SearchRentId(id, firstDate, secondDate);

			if (cnt) {
				printf("%d건 검색 되었습니다.\n", cnt);
				getchar();
				return;
			}
			else {
				printf("검색 결과 없습니다.");
				getchar();
				getchar();
				return;
			}
		}
		else {
			printf("등록되지 않은 도서번호 입니다.\n");
			getchar();
			getchar();
			return;
		}
	}
	else {
		printf("등록되지 않은 ID입니다.\n");
		getchar();
		getchar();
		return;
	}

}

/*
	데이터 복구 함수.
*/

void InitData(void)
{
	LoadCusInfoList();
	LoadDVDInfoList();
	LoadRentInfoList();
}