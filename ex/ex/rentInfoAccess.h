#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__



//이력추가
void AddRentList(char* ID, char* ISBN, int rentday);


//도서등록 번호 검색
void SearchRentISBN(char* ISBN);


//날짜 검색
int SearchRentId(char* ID,int firstDay, int secondDay);

//복구
void LoadRentInfoList(void);


//백업
void SaveRentInfoList(void);

#endif