#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define MAX_CUSTOMER 100
#define CUSINFO_BACKUP "cusInfo.dat"

//분할컴파일에서 전역변수 선언시 
// extern -> 공유 , static -> 공유하지 않겠다.
static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

int AddCusInfo(char * ID, char * name, char * num)
{
	cusInfo * pCus;

	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	pCus = (cusInfo *)malloc(sizeof(cusInfo));

	strcpy(pCus->ID, ID);
	strcpy(pCus->name, name);
	strcpy(pCus->phoneNum, num);

	cusList[numOfCustomer++] = pCus;


	SaveCusInfoList();
	
	return numOfCustomer;
}

cusInfo * GetCusPtrByID(char * ID)
{
	int i;

	for (i = 0; i < numOfCustomer; i++)
	{
		if (!strcmp(cusList[i]->ID, ID))
			return cusList[i];
	}

	return (cusInfo *)0;
}


/*
	기능 : 해당 cusInfo 의 phonenum 의 내용을 변경.
	반환 성공시 1; 실패시 0;
*/

int ChangeCusInfo(char * ID, char * num)
{
	cusInfo * tempCus = GetCusPtrByID(ID);

	if (tempCus == 0) {
		return 0;
	}

	strcpy(tempCus->phoneNum, num);

	SaveCusInfoList();//수정성공시 백업. 

	return 1;
}




/*
	기능 : 해당고객 ID 정보를 지운다. 해당 cusInfo 배열을 삭제.
	반환 : 총 고객수를 반환
*/


int eraseCusInfo(char*ID)
{
	int i;
	int j;


	for (i = 0; i < numOfCustomer; i++) {
		if (!strcmp(cusList[i]->ID, ID)) {
			numOfCustomer--;
			for (j = i; j < numOfCustomer; j++) {
				cusList[j] = cusList[j + 1];
			}
		}
	}

	SaveCusInfoList();

	return numOfCustomer;
}


/*
	기능 : 가입된 모든 회원 리스트를 출력.
	반환 : void;

*/

int AllPutCusInfo(void)
{
	int i;

	for (i = 0; i < numOfCustomer; i++) {
		ShowALLCustomerInfo(cusList[i]);
	}

	return numOfCustomer;
}

/*
	등록되어있으면 1 없으면 0
*/

int IsregistID(char * ID)
{
	cusInfo * pCus = GetCusPtrByID(ID);

	if (pCus == 0)
		return 0;
	else
		return 1;
}

//복구
void LoadCusInfoList(void)
{
	int i;
	FILE *fp;

	fp = fopen(CUSINFO_BACKUP, "rb");
	
	if (fp == NULL) {
		//printf("%s을 열수가 없습니다.\n", CUSINFO_BACKUP);
		return;
	}

	fread(&numOfCustomer, sizeof(int), 1, fp);

	
	for (i = 0; i < numOfCustomer; i++) {
		cusList[i] = (cusInfo *)malloc(sizeof(cusInfo));
		fread(cusList[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);
}


//백업

void SaveCusInfoList(void)
{
	int i;
	FILE* fp;

	fp = fopen(CUSINFO_BACKUP, "wb");
	
	if (fp == NULL) {
		//printf("%s을 열수가 없습니다.\n", CUSINFO_BACKUP);
		return;
	}

	
	fwrite(&numOfCustomer, sizeof(int), 1, fp);

	for (i = 0; i < numOfCustomer; i++) {
		fwrite(cusList[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);

}
