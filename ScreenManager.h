#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
#include "FirstPage.h"
#include "SecondTab.h"
#include "ThirdTab.h"
#include "SecondaryPage.h"
#include "ThirdPage.h"
#include "FourthPage.h"

enum eScreen
{
	// enum để chạy các page
	Tab_1 = 1,
	Tab_2,
	Tab_3,

	Page2_1 = 11,
	Page2_2,
	Page2_3,
	Page2_4,
	Page2_5,
	Page2_6,

	Page3_1 = 21,
	Page3_2,
	Page3_3,
	Page3_4,
	Page3_5,
	Page3_6,

	/*Page4_1 = 31,
	Page4_2,
	Page4_3,
	Page4_4,
	Page4_5,
	Page4_6*/
};
class ScreenManager {
private:
	MainTab** maintablist; // Khai báo mảng con trỏ để quản lý
	int size = 15; // xem tất cả các page có bao nhiu để khai báo size
	eScreen current = Tab_1; // mặc định khi chạy là firstTab
	
public:
	ScreenManager()
	{
		// đưa tên các file để chạy
		maintablist = new MainTab * [size];
		maintablist[0] = new FirstPage(Tab_1);
		maintablist[1] = new SecondTab(Tab_2);
		maintablist[2] = new ThirdTab(Tab_3);

		maintablist[3] = new SecondaryPage(Page2_1);
		maintablist[4] = new SecondaryPage(Page2_2);
		maintablist[5] = new SecondaryPage(Page2_3);
		maintablist[6] = new SecondaryPage(Page2_4);
		maintablist[7] = new SecondaryPage(Page2_5);
		maintablist[8] = new SecondaryPage(Page2_6);

		maintablist[9]  = new ThirdPage(Page3_1);
		maintablist[10] = new ThirdPage(Page3_2);
		maintablist[11] = new ThirdPage(Page3_3);
		maintablist[12] = new ThirdPage(Page3_4);
		maintablist[13] = new ThirdPage(Page3_5);
		maintablist[14] = new ThirdPage(Page3_6);

		/*maintablist[15] = new FourthPage(Page4_1);
		maintablist[16] = new FourthPage(Page4_2);
		maintablist[17] = new FourthPage(Page4_3);
		maintablist[18] = new FourthPage(Page4_4);
		maintablist[19] = new FourthPage(Page4_5);
		maintablist[20] = new FourthPage(Page4_6);*/

	}
	// giải phóng vùng nhớ
	~ScreenManager()
	{
		for (int i = 0; i < size; i++) {
			delete maintablist[i];
		}
	}

	void updateCurrentState(); // cập nhật lại trạng thái hiện tại
	void draw(RenderWindow& window); // vẽ
	void HandleMouseClick(int x, int y); // sự kiện các tab
	void Click(int x, int y); // sự kiện các phim
};