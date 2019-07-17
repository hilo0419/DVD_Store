#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"
#include "dvdInfoAccess.h"

void ShowMenu(void)
{
	system("cls"); //stdlib.h

	printf("----- �� �� ----- \n");
	
	printf(" 1. ȸ �� \n");
	printf(" 2. D V D\n");
	printf(" 3. �� �� �� ȸ\n");
	printf(" 4. ���� \n");
	printf("----------------- \n");
	printf("���� >> ");
}


/*
	�� ���� �޴� ���
*/
void ShowCusMenu(void)
{
	system("cls");

	printf(" 1. �ű԰��� \n");
	printf(" 2. ȸ����ȸ \n");
	printf(" 3. ȸ�� ���� ���� \n");
	printf(" 4. ȸ��Ż�� \n");
	printf(" 5. ��ü ȸ�� ��� \n");
	printf(" 6. ���� �޴�\n ");
	printf("----------------- \n");
	printf("���� >> ");
}

/*
	DVD ���� �޴� ���
*/

void ShowDvdMenu(void)
{
	system("cls");
	printf(" 1. DVD ��� \n");
	printf(" 2. DVD ��ȸ \n");
	printf(" 3. DVD ���� ���� \n");
	printf(" 4. DVD ���� \n");
	printf(" 5. ��ü DVD ��� \n");
	printf(" 6. DVD �뿩 \n");
	printf(" 7. DVD �ݳ� \n");
	printf(" 8. ���θ޴���\n");
	printf("----------------- \n");
	printf("���� >> ");

}
/*
	�뿩 �̷� ���� �޴� ���
*/


void ShowRentalInfoMenu(void)
{
	system("cls");

	printf(" 1. DVD �뿩�̷�\n");
	printf(" 2. DVD �Ⱓ��ȸ\n");
	printf(" 3. ���θ޴���\n");
	printf("----------------- \n");
	printf("���� >> ");

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
	printf(" �帣 :  "); ShowGenre(pDVD->genre);
	printf("\n �뿩Ȯ�� : %s", CheckDVDState(pDVD->ISBN) ? "�뿩����" : "�뿩��");
	printf("\n");

	getchar();

}

void ShowALLDVDInfo(dvdInfo * pDVD)
{
	printf("---------------\n");
	printf(" ISBN : %s \n", pDVD->ISBN);
	printf(" TITLE : %s \n", pDVD->title);
	printf(" �帣 :  "); ShowGenre(pDVD->genre);
	printf("\n �뿩Ȯ�� : %s\n", CheckDVDState(pDVD->ISBN) ? "�뿩����" : "�뿩��");
	printf("---------------\n");
}

//�뿩�̷� ���
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
		printf("�׼�");
		break;
	case COMIC:
		printf("�ڹ�");
		break;
	case SF:
		printf("SF");
		break;
	case ROMANTIC:
		printf("�θǽ�");
		break;
	}
}

/*
	��¥ �̷� ���
*/
void ShowDVDDateList(dvdRentInfo pDVD)
{

	printf("\n");

	printf("---- �뿩�� : %d ----\n ", pDVD.rentDay);
	printf(" ID : %s \n", pDVD.ID);
	printf(" ISBN : %s \n", pDVD.ISBN);
	

	getchar();

}