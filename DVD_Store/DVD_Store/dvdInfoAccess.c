#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"

#define MAX_DVD 100
#define DVDINFO_BACKUP_DATA "dvdInfo.dat"


static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

dvdRentInfo *tempRentInfo[RENT_LEN]; // ��¥ �̷�������.�ӽ� �����


int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	if (numOfDVD >= MAX_DVD)
		return 0;

	pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));

	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;
	pDVD->rentState = 0;//�뿩����(�뿩������ 0, �뿩�� �� 1) ���� �ʱ�ȭ.
	//pDVD->numOfRentCus = 0;//�̷� ����Ʈ �ʱ�ȭ
	dvdList[numOfDVD++] = pDVD;

	SaveDVDINfoList();

	return numOfDVD;
}

/*
	��� : �ش� ISBN �� ���� Ȥ�� �帣 ���� �� ������ ����.
	��ȯ ������ 1; ���н� 0;
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
	��� : �ش� ISBN ��ȣ�� �޾� �ش� ISBN�� ����� dvdInfo ��������� ����.
	��ȯ : ������ ��ϵ� DVD �� �� ��ȯ.
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
	��� : ���Ե� ��� ȸ�� ����Ʈ�� ���.
	��ȯ : void;

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
	��� : dvdInfo �迭�� ��ϵ� ISBN�� �뿩������ �ƴ��� üũ
	��ȯ : �뿩���� �ϸ� 1, �뿩���̸�  0��ȯ.
*/
int CheckDVDState(char*ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN); //�ִ����� �̹� �˰������� ���� �ٷ� �޾ƿͼ�.
	if (pDVD->rentState == 0) return 1;
	else return 0;
}
/*
	��� : dvdInfo �迭�� �뿩�ϰ��� �ϴ� ISBN�� �뿩 ���� �� ��ȯ.
	��ȯ : ������ �뿩 ���� �ݳ�, ���н� 0�� �ݳ�.
*/

int AddDVDRecord(char*ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0) {
		return 0;
	}
	else {
		pDVD->rentState = 1; //�뿩������ ����.
		//strcpy(pDVD->rentList[pDVD->numOfRentCus].cusID, ID);
		//strcpy(pDVD->rentList[pDVD->numOfRentCus].ISBN, ISBN);
		//pDVD->rentList[pDVD->numOfRentCus].rentDay = DATE;
		//pDVD->numOfRentCus++;//���� �����ϸ� �뿩�̷� ����

		return pDVD->rentState;
	}
}





/*
	��� : �ش� ISBN �� ���� �뿩 ���� ��  0(�뿩����)���� �ٲ۴�.
	��ȯ : void �ص� �ɵ�.
*/
void ChangeDVDState(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	pDVD->rentState = 0; //�뿩�������� �ٲ�.
}



//����
void LoadDVDInfoList(void)
{
	int i;
	FILE *fp;

	fp = fopen(DVDINFO_BACKUP_DATA, "rb");

	if (fp == NULL) {
		//printf("%s ������ ������ �����ϴ�.\n");
		return;
	}

	fread(&numOfDVD, sizeof(int), 1, fp);


	for (i = 0; i < numOfDVD; i++) {
		dvdList[i] = (dvdInfo*)malloc(sizeof(dvdInfo));
		fread(dvdList[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);

}

//���

void SaveDVDINfoList(void)
{
	int i;
	FILE *fp;

	fp = fopen(DVDINFO_BACKUP_DATA, "wb");
	if (fp == NULL) {
		//printf("%s�� ���� �����ϴ�.\n", DVDINFO_BACKUP_DATA);
		return;
	}

	fwrite(&numOfDVD, sizeof(int), 1, fp);

	for (i = 0; i < numOfDVD; i++) {
		fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);
}




/*
	��� : ISBN ��  numOfRentCus���� �� �ݳ�.
	��ȯ : �뿩 ���� ��ȯ ������ 0�� ��ȯ
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
	DVD ��¥ �뿩 ��ȸ.
	��� : ISBN�� dvdRentInfo ����ü�� firstDay ~ secondDay���� ���� ��¥ ã�Ƽ�
		   dvdRentInfo* temp�� ����.
	��ȯ : dvdRentInfo* temp
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
		return cnt;//������ ����ü �迭�� ù�ּҰ��� �����Ѵٰ� �˰�����. ���߿� Ȯ��.

	}

	return cnt;


}
*/