#include"common.h"
#include"cusInfo.h"
#include"cusInfoAccess.h"
#include"rentInfo.h"
#include"rentInfoAccess.h"
#include"screenOut.h"

#define RENTLIST_BACKUP_DATA "rentInfo.dat"

dvdRentInfo dvdRentList[RENT_LEN];



int numOfRentCus = 0;

//이력추가
void AddRentList(char* ID, char* ISBN, int rentday)
{
	strcpy(dvdRentList[numOfRentCus].ID, ID);
	strcpy(dvdRentList[numOfRentCus].ISBN, ISBN);
	dvdRentList[numOfRentCus].rentDay = rentday;
	numOfRentCus++;

	SaveRentInfoList(); //백업

}


//id 검색
void SearchRentISBN(char* ISBN)
{
	int i;

	for (i = 0; i < numOfRentCus; i++) {
		if (!strcmp(dvdRentList[i].ISBN, ISBN)) {
			printf("------------------------\n");
			printf("대여일 : %d\n", dvdRentList[i].rentDay);
			cusInfo *tempCus = GetCusPtrByID(dvdRentList[i].ID);
			ShowDVDRecordList(tempCus);
		}
	}
}


//날짜 검색
int SearchRentId(char* ID, int firstDay, int secondDay)
{
	int i;
	int cnt = 0;

	for (i = 0; i < numOfRentCus; i++) {
		if (!strcmp(dvdRentList[i].ID, ID)) {
			if (firstDay <= dvdRentList[i].rentDay &&
				secondDay >= dvdRentList[i].rentDay) {
				ShowDVDDateList(dvdRentList[i]);
				cnt++;
			}
		
		}
	}

	if (cnt) return cnt; //1이상은 다 참 이므로. 검색에 성공하였으면 건수 만큼
	else return cnt;//한건도 없으면 0을 반납.
}

//복구
void LoadRentInfoList(void)
{
	FILE* fp;

	fp = fopen(RENTLIST_BACKUP_DATA, "rb");
	if (fp == NULL) {
		//printf("%s 를 열수가 없습니다.\n");
		return;
	}

	fread(&numOfRentCus, sizeof(int), 1, fp);
	fread(dvdRentList, sizeof(dvdRentList), numOfRentCus, fp);

	fclose(fp);
}


//백업
void SaveRentInfoList(void)
{
	FILE* fp;

	fp = fopen(RENTLIST_BACKUP_DATA, "wb");
	if (fp == NULL) {
		printf("%s를 열수가 없습니다.\n");
		return;
	}

	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(dvdRentList, sizeof(dvdRentList), numOfRentCus, fp);

	

	fclose(fp);

}

