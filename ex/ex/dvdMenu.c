#include"Manager.h"
#include"dvdMenu.h"
#include"screenOut.h"
enum{
		DVD_REGIST = 1, DVD_SEARCH, DVD_UPDATE, DVD_DELETE, DVD_INFOALL,
		DVD_RENTAL, DVD_RETURN, QUIT
};


void DVDMenu(void)
{
	int num;



	while (1) {

		ShowDvdMenu();

		scanf("%d", &num);

		getchar();

		switch (num) {
		case DVD_REGIST:
			RegistDVD();
			break;

		case DVD_SEARCH:
			SearchDVDInfo();
			break;
		case DVD_UPDATE:
			UdateDVDInfo();
			break;
		case DVD_DELETE:
			DelDVDInfo();
			break;

		case DVD_INFOALL:
			AllDVDInfo();
			break;

		case DVD_RENTAL:
			RentalDVD();
			break;

		case DVD_RETURN:
			ReturnDVD();
			break;
			
		}
		if (num == QUIT)
		{
			puts("메인 메뉴로.");
			break;
		}
	}

}