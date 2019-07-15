#include"rentMenu.h"
#include"manager.h"
#include"screenOut.h"


enum { DVD_RECORD = 1 , DVD_DATERECORD, QUIT };

void rentInfoMenu(void)
{

	int num;



	while (1) {

		ShowRentalInfoMenu();

		scanf("%d", &num);

		getchar();

		switch (num) {

		case DVD_RECORD:
			RecordDVD();
			break;

		case DVD_DATERECORD:
			RecordDateDVD();
			break;

		}

		if (num == QUIT)
		{
			puts("메인 메뉴로.");
			break;
		}
	}
}