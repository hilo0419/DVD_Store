#include"common.h"
#include"cusInfo.h"
#include"cusInfoAccess.h"
#include"rentInfo.h"
#include"rentInfoAccess.h"
#include"screenOut.h"

#define RENTLIST_BACKUP_DATA "rentInfo.dat"

dvdRentInfo dvdRentList[RENT_LEN];



int numOfRentCus = 0;

//�̷��߰�
void AddRentList(char* ID, char* ISBN, int rentday)
{
	strcpy(dvdRentList[numOfRentCus].ID, ID);
	strcpy(dvdRentList[numOfRentCus].ISBN, ISBN);
	dvdRentList[numOfRentCus].rentDay = rentday;
	numOfRentCus++;

	SaveRentInfoList(); //���

}


//id �˻�
void SearchRentISBN(char* ISBN)
{
	int i;

	for (i = 0; i < numOfRentCus; i++) {
		if (!strcmp(dvdRentList[i].ISBN, ISBN)) {
			printf("------------------------\n");
			printf("�뿩�� : %d\n", dvdRentList[i].rentDay);
			cusInfo *tempCus = GetCusPtrByID(dvdRentList[i].ID);
			ShowDVDRecordList(tempCus);
		}
	}
}


//��¥ �˻�
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

	if (cnt) return cnt; //1�̻��� �� �� �̹Ƿ�. �˻��� �����Ͽ����� �Ǽ� ��ŭ
	else return cnt;//�Ѱǵ� ������ 0�� �ݳ�.
}

//����
void LoadRentInfoList(void)
{
	FILE* fp;

	fp = fopen(RENTLIST_BACKUP_DATA, "rb");
	if (fp == NULL) {
		//printf("%s �� ������ �����ϴ�.\n");
		return;
	}

	fread(&numOfRentCus, sizeof(int), 1, fp);
	fread(dvdRentList, sizeof(dvdRentList), numOfRentCus, fp);

	fclose(fp);
}


//���
void SaveRentInfoList(void)
{
	FILE* fp;

	fp = fopen(RENTLIST_BACKUP_DATA, "wb");
	if (fp == NULL) {
		printf("%s�� ������ �����ϴ�.\n");
		return;
	}

	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(dvdRentList, sizeof(dvdRentList), numOfRentCus, fp);

	

	fclose(fp);

}

