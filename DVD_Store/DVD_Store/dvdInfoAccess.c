#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"

#define MAX_DVD 100
#define DVDINFO_BACKUP_DATA "dvdInfo.dat"


static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

dvdRentInfo *tempRentInfo[RENT_LEN]; // 날짜 이력을위한.임시 저장소


int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	if (numOfDVD >= MAX_DVD)
		return 0;

	pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));

	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;
	pDVD->rentState = 0;//대여가능(대여가능은 0, 대여중 은 1) 으로 초기화.
	//pDVD->numOfRentCus = 0;//이력 리스트 초기화
	dvdList[numOfDVD++] = pDVD;

	SaveDVDINfoList();

	return numOfDVD;
}

/*
	기능 : 해당 ISBN 의 제목 혹은 장르 변경 의 내용을 변경.
	반환 성공시 1; 실패시 0;
*/

int ChangeDVDInfo(char * ISBN, char * title, int gen)
{
	dvdInfo * tempDVD = GetDVDPtrByISBN(ISBN);

	if (tempDVD == 0) {
		return 0;
	}

		strcpy(tempDVD->title, title);
		tempDVD->genre = gen;

		SaveDVDINfoList();

	return 1;
}





/*
	기능 : 해당 ISBN 번호를 받아 해당 ISBN이 저장된 dvdInfo 저장공간을 삭제.
	반환 : 성공시 등록된 DVD 수 를 반환.
*/

int eraseDVDInfo(char * ISBN)
{
	int i,j;

	for (i = 0; i < numOfDVD; i++) {
		if (!strcmp(dvdList[i]->ISBN, ISBN)) {
			numOfDVD--;
			for (j = i; j < numOfDVD; j++) {
				dvdList[j] = dvdList[j + 1];
			}
		}
	}

	SaveDVDINfoList();

	return numOfDVD;
}

/*
	기능 : 가입된 모든 회원 리스트를 출력.
	반환 : void;

*/

int AllPutDVDInfo(void)
{
	int i;

	for (i = 0; i < numOfDVD; i++) {
		ShowALLDVDInfo(dvdList[i]);
	}

	return numOfDVD;
}


dvdInfo * GetDVDPtrByISBN(char * ISBN)
{
	int i;

	for (i = 0; i < numOfDVD; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
		{
			return dvdList[i];
		}
	}

	return (dvdInfo *)0;
}

int IsRegistISBN(char * ISBN)
{
	dvdInfo * pDVD =
		GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;
	else
		return 1;
}

/*
	기능 : dvdInfo 배열에 등록된 ISBN을 대여중인지 아닌지 체크
	반환 : 대여가능 하면 1, 대여중이면  0반환.
*/
int CheckDVDState(char*ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN); //있는지는 이미 알고있으니 정보 바로 받아와서.
	if (pDVD->rentState == 0) return 1;
	else return 0;
}
/*
	기능 : dvdInfo 배열에 대여하고자 하는 ISBN에 대여 상태 값 변환.
	반환 : 성공시 대여 상태 반납, 실패시 0을 반납.
*/

int AddDVDRecord(char*ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0) {
		return 0;
	}
	else {
		pDVD->rentState = 1; //대여중으로 변경.
		//strcpy(pDVD->rentList[pDVD->numOfRentCus].cusID, ID);
		//strcpy(pDVD->rentList[pDVD->numOfRentCus].ISBN, ISBN);
		//pDVD->rentList[pDVD->numOfRentCus].rentDay = DATE;
		//pDVD->numOfRentCus++;//저장 성공하면 대여이력 증가

		return pDVD->rentState;
	}
}





/*
	기능 : 해당 ISBN 의 도서 대여 상태 를  0(대여가능)으로 바꾼다.
	반환 : void 해도 될듯.
*/
void ChangeDVDState(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	pDVD->rentState = 0; //대여가능으로 바꿈.
}



//복구
void LoadDVDInfoList(void)
{
	int i;
	FILE *fp;

	fp = fopen(DVDINFO_BACKUP_DATA, "rb");

	if (fp == NULL) {
		//printf("%s 파일을 열수가 없습니다.\n");
		return;
	}

	fread(&numOfDVD, sizeof(int), 1, fp);


	for (i = 0; i < numOfDVD; i++) {
		dvdList[i] = (dvdInfo*)malloc(sizeof(dvdInfo));
		fread(dvdList[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);

}

//백업

void SaveDVDINfoList(void)
{
	int i;
	FILE *fp;

	fp = fopen(DVDINFO_BACKUP_DATA, "wb");
	if (fp == NULL) {
		//printf("%s을 열수 없습니다.\n", DVDINFO_BACKUP_DATA);
		return;
	}

	fwrite(&numOfDVD, sizeof(int), 1, fp);

	for (i = 0; i < numOfDVD; i++) {
		fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);
}




/*
	기능 : ISBN 의  numOfRentCus변수 값 반납.
	반환 : 대여 갯수 반환 없으면 0을 반환
*/
/*
int ReturnDVDRentNum(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	int listCnt = pDVD->numOfRentCus;
	if (pDVD->numOfRentCus == 0) pDVD->numOfRentCus;


	return listCnt;

}
*/
/*
	DVD 날짜 대여 조회.
	기능 : ISBN의 dvdRentInfo 구조체의 firstDay ~ secondDay사이 같은 날짜 찾아서
		   dvdRentInfo* temp에 저장.
	반환 : dvdRentInfo* temp
*/
/*
int SearchDateDVD(char *ISBN, char* ID, int firstDay, int secondDay)
{
	int i, j;
	int cnt = 0;
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	dvdRentInfo temp2;

	if (pDVD != 0) {
		for (i = 0; i < pDVD->numOfRentCus; i++) {
			for (j = firstDay; j <= secondDay; j++) {
				if (!(strcmp(pDVD->rentList[i].cusID, ID)) &&
					(pDVD->rentList[i].rentDay == j)) {
					temp2 = pDVD->rentList[i];
					//tempRentInfo[cnt]->cusID = temp2.cusID;
					cnt++;
				}
			}
		}
		//*tempRentInfo[i + 1].cusID = NULL;
		return cnt;//리턴은 구조체 배열의 첫주소값을 리턴한다고 알고있음. 나중에 확인.

	}

	return cnt;


}
*/