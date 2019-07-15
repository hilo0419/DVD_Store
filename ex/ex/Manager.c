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

	printf("ID �Է� : ");
	gets(ID);

	if (IsregistID(ID))
	{
		puts("�ش� ID�� ������Դϴ�.");
		getchar();
		return;
	}

	printf("�̸� �Է� : ");
	gets(name);

	printf("��ȭ��ȣ �Է� : ");
	gets(phoneNum);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("������ ���忡 �����߽��ϴ�.");
		getchar();
		return;
	}

	puts("ȸ�� ������ �Ǿ����ϴ�.");
	getchar();
}


void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * cusPtr;

	printf("ã�� ID �Է� : ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0)
	{
		puts("�������� �ʴ� ID�Դϴ�.");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}

/*
	 ��� : ID�� ���� ȸ�� ���� ����.
	 ��ȯ : void
*/

void UdateCusInfo(void)
{
	char id[ID_LEN];
	char num[PHONE_LEN];

	printf("ID �Է� : ");
	gets(id);

	if (!IsregistID(id)) {
		printf("ȸ���� �ƴմϴ�.");
		getchar();
		return;
	}

	printf("���� �Ͻ� ��ȭ ��ȣ�� �Է����ּ��� :");//���� ���� �����Ҹ��Ѱ� ��ȭ��ȣ �ۿ� ����.
	gets(num);

	if (ChangeCusInfo(id, num)) {//id,phone num �޾Ƽ� �����ϸ� 1 ���� 0
		printf("ȸ�� ������ �Ϸ� �Ǿ����ϴ�.");
		getchar();
	}
	else {
		printf("ȸ�� ������ ���� �Ͽ����ϴ�.");
		getchar();
	}
}

/*
	���Ե� �� ���� ���
*/
void AllcusInfo(void)
{	
	printf("------��ü ȸ�� ��� ------\n");
	AllPutCusInfo();
	getchar();
	printf("--------------------------");

}



/*
	��� : ȸ�� ����
	��ȯ : void
*/

void DelCusInfo(void)
{
	char id[ID_LEN];

	printf("Ż�� ���ϴ� ȸ�� ID �� �Է����ּ��� :");
	scanf("%s", id);
	getchar();

	if (GetCusPtrByID(id) == 0) {
		printf("���� �� ȸ�� �� �ƴմϴ�.\n");
		getchar();
		return;
	}

	if (eraseCusInfo(id)) { //ȸ�� ���� ����. 
		printf("Ż�� �����ϼ̽��ϴ�.");
		getchar();
	}
	else
		printf("Ż�� �����Ͽ����ϴ�.");
	
}

void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN �Է� : ");
	gets(ISBN);

	if (IsRegistISBN(ISBN))
	{
		puts("�ش� ISBN�� �̹� ��ϵǾ����ϴ�.");
		getchar();
		return;
	}

	printf("���� �Է� : ");
	gets(title);

	printf("�帣 �Է� (1.�׼�, 2.�ڹ�, 3.SF, 4.�θ�ƽ)");
	scanf("%d", &genre);
	getchar();

	if (!AddDVDInfo(ISBN, title, genre))
	{
		puts("DVD ������ ���忡 �����߽��ϴ�.");
		getchar();
		return;
	}

	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dvdPtr;

	printf("ã�� ISBN �Է� : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);
	if (dvdPtr == 0)
	{
		puts("��ϵ��� ���� ISBN�Դϴ�.");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

/*
	 ��� : ISBN�� ���� DVD ���� ����.
	 ��ȯ : void
*/

void UdateDVDInfo(void)
{
	char isbn[ISBN_LEN];
	char title[TITLE_LEN];
	int gen;

	printf("���� �Ͻ� ���� ��� ��ȣ�� �Է����ּ���.\n");
	gets(isbn);
	if (!IsRegistISBN(isbn)) {
		printf("���� ������� ��ȣ �Դϴ�.\n");
		getchar();
		return;
	}

	printf("���� �� ���� ������ �Է����ּ���.\n");
	gets(title);

	printf("���� �� ���� �帣�� �Է����ּ���.\n");
	printf("�帣 �Է� (1.�׼�, 2.�ڹ�, 3.SF, 4.�θ�ƽ)");
	scanf("%d", &gen);
	getchar();

	if (ChangeDVDInfo(isbn, title, gen)) {
		printf("���� ���� ���� �Ϸ��Ͽ����ϴ�.");
		getchar();
	}
	else {
		printf("���� ���� ������ �����Ͽ����ϴ�.");
		getchar();
	}
	   

}


/*
	��� : DVD ����
	��ȯ : void
*/

void DelDVDInfo(void)
{
	char ISBN[ISBN_LEN];

	printf("���� �ϰ� ���� DVD ��Ϲ�ȣ�� �Է����ּ��� :");
	scanf("%s", ISBN);
	getchar();

	if (!GetDVDPtrByISBN(ISBN)) {
		printf("��ϵ��� ���� DVD �Դϴ�.\n");
		getchar();
		return;
	}


	eraseDVDInfo(ISBN);//���� ����
	printf("%s DVD�� ���� �Ǿ����ϴ�.", ISBN);
	getchar();
	
	
}

/*
	��ϵ� DVD ���� ���
*/
void AllDVDInfo(void)
{
	printf("-----------��ϵ� DVD LIST------------\n");
	AllPutDVDInfo();
	printf("-------------------------------------\n");
	getchar();

}


/*
	DVD �뿩
*/

void RentalDVD(void) {
	//ID �Է�
	//��ϵ� ���̵� üũ
	//ISBN �Է�
	//ISBN üũ
	//�뿩���� ���� üũ
	//�뿩��¥ �Է�
	// �Էµ� ID, ISBN ����. ������ ��Ʈ ���.

	char id[ID_LEN];
	char isbn[ISBN_LEN];
	int rentDate;
	int AddState;

	printf("����Ͻ� ID�� �Է����ּ��� : ");
	scanf("%s", id);
	if (IsregistID(id)) {
		printf("�뿩�ϰ����ϴ� ���� ��Ϲ�ȣ�� �Է����ּ��� : ");
		scanf("%s", isbn);
		if (IsRegistISBN(isbn)) {
			if (CheckDVDState(isbn)) { //�뿩������ �ƴ��� üũ
				printf("�뿩��¥�� �Է����ּ��� : ");
				scanf("%d", &rentDate);
				AddState = AddDVDRecord(isbn);//�뿩�Լ� ȣ��

				if (AddState) printf("�뿩�� �Ϸ�\n");
				else {
					printf("�뿩����\n");
					return;
				}

				AddRentList(id, isbn, rentDate);

				getchar();
				getchar();
				return;
			}
			else {
				printf("�ش� ������ �뿩���Դϴ�.\n");
				getchar();
				getchar();
				return;
			}
		}
		else {
			printf("��ϵ��� ���� ���� ��Ϲ�ȣ �Դϴ�.\n");
			getchar();
			getchar();
			return;
		}
	}
	else {
		printf("��ϵ��� ���� ID�Դϴ�.\n");
		getchar();
		getchar();
		return;
	}
}


/*
	DVD �ݳ�
*/
void ReturnDVD(void)
{
	//���� ��Ϲ�ȣ �Է�
	//���� ��Ϲ�ȣ üũ
	//���� �뿩���� ����.
	char isbn[ISBN_LEN];

	printf("�ݳ��Ͻô� ������Ϲ�ȣ�� �Է����ּ��� : ");
	scanf("%s", isbn);

	if (IsRegistISBN(isbn)) {
		if (!CheckDVDState(isbn)) {
			ChangeDVDState(isbn);//�뿩�������� �ٲ�
			printf("���������� �ݳ��� �Ͽ����ϴ�.\n");
			getchar();
			getchar();
			return;
		}
		else {
			printf("�ش� ������ �뿩���� �ƴմϴ�.\n");
			getchar();
			getchar();
			return;

		}
	}
	else {
		printf("��ϵ��� ���� ������ȣ �Դϴ�.\n");
		getchar();
		getchar();
		return;
	}
}


/*
	DVD �뿩�̷�
*/
void RecordDVD(void)
{
	char isbn[ISBN_LEN];

	printf("������� ��ȣ�� �Է����ּ��� : ");
	scanf("%s", isbn);
	if (IsRegistISBN(isbn)) {
		//cnt = ReturnDVDRentNum(isbn);
		SearchRentISBN(isbn);
	}
	else {
		printf("��ϵ��� ���� ������ȣ �Դϴ�.\n");
		getchar();
		
		return;
	}

}
/*
	DVD �뿩��¥ ��ȸ
*/
void RecordDateDVD(void) {

	char isbn[ISBN_LEN];
	char id[ID_LEN];
	int firstDate;
	int secondDate;
	int cnt;
	printf("����Ͻ� ID�� �Է����ּ��� : ");
	scanf("%s", id);
	if (IsregistID(id)) {
		printf("������� ��ȣ�� �Է����ּ��� : ");
		scanf("%s", isbn);
		if (IsRegistISBN(isbn)) {

			printf("��ȸ �ϰ� ���� ó�� ��¥ �Է����ּ���.");
			scanf("%d", &firstDate);
			printf("��ȸ �ϰ� ���� ������ ��¥ �Է����ּ���.");
			scanf("%d", &secondDate);

			cnt = SearchRentId(id, firstDate, secondDate);

			if (cnt) {
				printf("%d�� �˻� �Ǿ����ϴ�.\n", cnt);
				getchar();
				return;
			}
			else {
				printf("�˻� ��� �����ϴ�.");
				getchar();
				getchar();
				return;
			}
		}
		else {
			printf("��ϵ��� ���� ������ȣ �Դϴ�.\n");
			getchar();
			getchar();
			return;
		}
	}
	else {
		printf("��ϵ��� ���� ID�Դϴ�.\n");
		getchar();
		getchar();
		return;
	}

}

/*
	������ ���� �Լ�.
*/

void InitData(void)
{
	LoadCusInfoList();
	LoadDVDInfoList();
	LoadRentInfoList();
}