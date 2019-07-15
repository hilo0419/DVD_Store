#ifndef __RENTINFO_H__
#define __RENTINFO_H__
#include"dvdInfo.h"

#define RENT_LEN 100

typedef struct __dvdRentInfo {

	char ID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;

}dvdRentInfo;



#endif