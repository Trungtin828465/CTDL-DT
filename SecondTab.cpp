#include "SecondTab.h"

SecondTab::SecondTab(int num) : m_blocks("second"), m_texts("second")
{
	// set font default
	selectedItemIndex = num;
	curentState = num;

	bold.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	semiBold.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
	regular.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
	
	string bg_rap = "images/data/bg-rap.png";
	string khungdo = "images/bg-red.png";
	string khungden = "images/bg-gray-larger.png";
	float ybgRap = 178.0f;
	float xbgRap = 46.0f;

	m_blocks.AddBlockContainer(bg_rap, xbgRap, ybgRap, 1, 1);
	m_texts.AddTextContainer("BHD Star Le Van Viet ", semiBold, 20, Color::Black, 189, 192);
	m_texts.AddTextContainer("Vincom Plaza, Le Van Viet, Hiep Phu, Quan 9, ", regular, 14, Color::Black, 135, 224);
	m_texts.AddTextContainer("Thanh pho Ho Chi Minh, Viet Nam ", regular, 14, Color::Black, 185, 246);

	m_blocks.AddBlockContainer(bg_rap, xbgRap, 326, 1, 1);
	m_texts.AddTextContainer("Cinestar Sinh Vien ", semiBold, 20, Color::Black, 206, 350);
	m_texts.AddTextContainer("8, 19, Binh Duong, Viet Nam", regular, 14, Color::Black, 203, 379);

	m_blocks.AddBlockContainer(bg_rap, xbgRap, 473, 1, 1);
	m_texts.AddTextContainer("CGV Vincom Thu Duc ", semiBold, 20, Color::Black, 189, 489);
	m_texts.AddTextContainer("216 Vo Van Ngan, Binh Tho", regular, 14, Color::Black, 203, 518);
	m_texts.AddTextContainer(" Thu Duc, Thanh pho Ho Chi Minh, Viet Nam", regular, 14, Color::Black, 135, 540);

	m_blocks.AddBlockContainer(bg_rap, xbgRap, 621, 1, 1);
	m_texts.AddTextContainer("CGV Vincom Giga Mall Thu Duc ", semiBold, 20, Color::Black, 137, 637);
	m_texts.AddTextContainer("Tang 6 TTTM Giga Mall, 240, 242 Pham Van Dong, Hiep Binh Chanh", regular, 14, Color::Black, 60, 667);
	m_texts.AddTextContainer(" Thu Duc, Thanh pho Ho Chi Minh, Viet Nam", regular, 14, Color::Black, 145, 689);



	//
	m_blocks.AddBlockContainer(khungden, 105, 92, 0.5454, 0.9302);
	m_blocks.AddBlockContainer(khungdo, 236, 92, 0.1769, 0.2469);
	m_blocks.AddBlockContainer(khungden, 367, 92, 0.5454, 0.9302);

	m_texts.AddTextContainer("Phim Chieu", semiBold, 15, Color::Black, 109, 100);
	m_texts.AddTextContainer("Rap Chieu", semiBold, 15, Color::White, 248, 100);
	m_texts.AddTextContainer("Thong Tin", semiBold, 15, Color::Black, 380, 100);
	//
	m_texts.AddTextContainer("SLC2T", bold, 50, Color::Red, 212, 25);

}
void SecondTab::draw(RenderWindow& window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}
void SecondTab::HandleMouseClick(int x, int y)
{
	int width = 119;// chieu rong
	int height = 39; // chieu dai
	// Kiểm tra xem click có nằm trong vị trí cụ thể không
	if (x >= 109 && x <= 109 + width && y >= 95 && y <= 95 + height)
	{
		curentState = 1;
		cout << "Da click vao phim chieu" << endl;
	}
	else if (x >= 248 && x <= 248 + width && y >= 95 && y <= 95 + height)
	{
		curentState = 2;
		cout << " Da click vao o Rap chieu" << endl;
	}
	else if (x >= 380 && x <= 380 + width && y >= 95 && y <= 95 + height)
	{
		curentState = 3;
		cout << " Da click vao o Thong tin" << endl;
	}
}
void SecondTab::Click(int x, int y) {

}
int SecondTab::GetState()
{
	return selectedItemIndex;
}
int SecondTab::GetCurrentState()
{
	return curentState;
}
void SecondTab::SetCurrentState(int state)
{
	curentState = state;
}