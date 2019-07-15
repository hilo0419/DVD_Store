#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define MAX_CUSTOMER 100
#define CUSINFO_BACKUP "cusInfo.dat"

//���������Ͽ��� �������� ����� 
// extern -> ���� , static -> �������� �ʰڴ�.
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
	��� : �ش� cusInfo �� phonenum �� ������ ����.
	��ȯ ������ 1; ���н� 0;
*/

int ChangeCusInfo(char * ID, char * num)
{
	cusInfo * tempCus = GetCusPtrByID(ID);

	if (tempCus == 0) {
		return 0;
	}

	strcpy(tempCus->phoneNum, num);

	SaveCusInfoList();//���������� ���. 

	return 1;
}




/*
	��� : �ش�� ID ������ �����. �ش� cusInfo �迭�� ����.
	��ȯ : �� ������ ��ȯ
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
	��� : ���Ե� ��� ȸ�� ����Ʈ�� ���.
	��ȯ : void;

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
	��ϵǾ������� 1 ������ 0
*/

int IsregistID(char * ID)
{
	cusInfo * pCus = GetCusPtrByID(ID);

	if (pCus == 0)
		return 0;
	else
		return 1;
}

//����
void LoadCusInfoList(void)
{
	int i;
	FILE *fp;

	fp = fopen(CUSINFO_BACKUP, "rb");
	
	if (fp == NULL) {
		//printf("%s�� ������ �����ϴ�.\n", CUSINFO_BACKUP);
		return;
	}

	fread(&numOfCustomer, sizeof(int), 1, fp);

	
	for (i = 0; i < numOfCustomer; i++) {
		cusList[i] = (cusInfo *)malloc(sizeof(cusInfo));
		fread(cusList[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);
}


//���

void SaveCusInfoList(void)
{
	int i;
	FILE* fp;

	fp = fopen(CUSINFO_BACKUP, "wb");
	
	if (fp == NULL) {
		//printf("%s�� ������ �����ϴ�.\n", CUSINFO_BACKUP);
		return;
	}

	
	fwrite(&numOfCustomer, sizeof(int), 1, fp);

	for (i = 0; i < numOfCustomer; i++) {
		fwrite(cusList[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);

}
