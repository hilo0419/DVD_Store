#include "common.h"
#include "Manager.h"
#include "cusMenu.h"
#include "dvdMenu.h"
#include "rentMenu.h"
#include "screenOut.h"

enum { CUS_MENU = 1, DVD_MENU, RENTALINFO_MENU,
	 QUIT
};

int main(void)
{
	int intputMenu = 0;
	InitData();//������ ����
	while (1)
	{
		ShowMenu();
		scanf("%d", &intputMenu);
		getchar();

		switch (intputMenu)
		{
		case CUS_MENU:
			cusMenu();
			break;
		
		case DVD_MENU:
			DVDMenu();
			break;

		case RENTALINFO_MENU:
			rentInfoMenu();
			break;
					
		}

		if (intputMenu == QUIT)
		{
			puts("�̿����ּż� �����մϴ�.");
			break;
		}


	}
	return 0;
}