#ifndef __MANAGER_H__
#define __MANAGER_H__

/*
	��� : �ű� ȸ�� ����
	��ȯ : void
*/
void RegisterCustomer(void);

/*
	��� : ID�� ���� ȸ�� �˻�
	��ȯ : void
*/
void SearchCusInfo(void);
/*
	 ��� : ID�� ���� ȸ�� ���� ����.
	 ��ȯ : void
*/

void UdateCusInfo(void);
/*
	��� : ȸ�� ����
	��ȯ : void
*/

void DelCusInfo(void);

/*
	���Ե� �� ���� ���
*/
void AllcusInfo(void);
/*
	DVD ���
*/
void RegistDVD(void);
/*
	DVD ��ȸ
*/
void SearchDVDInfo(void);
/*
	 ��� : ISBN�� ���� DVD ���� ����.
	 ��ȯ : void
*/

void UdateDVDInfo(void);
/*
	��� : DVD ����
	��ȯ : void
*/

void DelDVDInfo(void);


/*
	��ϵ� DVD ���� ���
*/
void AllDVDInfo(void);

/*
	DVD �뿩
*/

void RentalDVD(void);
/*
	DVD �ݳ�
*/
void ReturnDVD(void);
/*
	DVD �뿩�̷�
*/
void RecordDVD(void);
/*
	DVD �뿩��¥ ��ȸ
*/
void RecordDateDVD(void);


/*
	������ ���� 
*/

void InitData(void);



#endif