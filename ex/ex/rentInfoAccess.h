#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__



//�̷��߰�
void AddRentList(char* ID, char* ISBN, int rentday);


//������� ��ȣ �˻�
void SearchRentISBN(char* ISBN);


//��¥ �˻�
int SearchRentId(char* ID,int firstDay, int secondDay);

//����
void LoadRentInfoList(void);


//���
void SaveRentInfoList(void);

#endif