#include"Manager.h"
#include"cusMenu.h"
#include"screenOut.h"

enum { CUS_REGIST = 1, CUS_SEARCH, CUS_UPDATE, CUS_DELETE, CUS_INFOALL, QUIT};

void cusMenu(void)
{

	int num;
	while (1) {
				
		ShowCusMenu();

		scanf("%d", &num);
		getchar();

		switch (num) {

		case CUS_REGIST:
			RegisterCustomer();
			break;
		case CUS_SEARCH:
			SearchCusInfo();
			break;
		case CUS_UPDATE:
			UdateCusInfo();
			break;
		case CUS_DELETE:
			DelCusInfo();
			break;
		case CUS_INFOALL:
			AllcusInfo();
			break;


		}	

		if (num == QUIT)
		{
			puts("메인 메뉴로.");
			break;
		}

	}
}