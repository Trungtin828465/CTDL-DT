#include "ThirdTab.h"

ThirdTab::ThirdTab(int num) : m_blocks("second"), m_texts("second")
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
	//
	m_blocks.AddBlockContainer(khungden, 105, 92, 0.5454, 0.9302);
	m_blocks.AddBlockContainer(khungden, 236, 92, 0.5454, 0.9302);
	m_blocks.AddBlockContainer(khungdo, 367, 92, 0.1769, 0.2469);

	m_texts.AddTextContainer("Phim Chieu", semiBold, 15, Color::Black, 109, 100);
	m_texts.AddTextContainer("Rap Chieu", semiBold, 15, Color::Black, 248, 100);
	m_texts.AddTextContainer("Thong Tin", semiBold, 15, Color::White, 380, 100);
	//
	m_texts.AddTextContainer("SLC2T", semiBold, 50, Color::Red, 212, 25);
	// thong tin
	m_blocks.AddBlockContainer(bg_rap, xbgRap, ybgRap, 1, 1);
	m_texts.AddTextContainer("Vo Cong Sinh ( Leader ) ", semiBold, 20, Color::Black, 178, 192);
	m_texts.AddTextContainer("MSSV: 6351071062 ", semiBold, 20, Color::Black, 200, 224);

	m_blocks.AddBlockContainer(bg_rap, xbgRap, 326, 1, 1);
	m_texts.AddTextContainer("Huynh Thi Truc Lam ( Thanh vien ) ", semiBold, 20, Color::Black, 150, 350);
	m_texts.AddTextContainer("MSSV: 6351071040", semiBold, 20, Color::Black, 203, 379);

	m_blocks.AddBlockContainer(bg_rap, xbgRap, 473, 1, 1);
	m_texts.AddTextContainer("Pham Luc Chuong ( Thanh vien ) ", semiBold, 20, Color::Black, 159, 489);
	m_texts.AddTextContainer("MSSV: 6351071008", semiBold, 20, Color::Black, 203, 518);

	m_blocks.AddBlockContainer(bg_rap, xbgRap, 621, 1, 1);
	m_texts.AddTextContainer("Dang Thi Kim Thao ( Thanh vien ) ", semiBold, 20, Color::Black, 158, 637);
	m_texts.AddTextContainer("MSSV: 6351071066", semiBold, 20, Color::Black, 203, 667);

	m_blocks.AddBlockContainer(bg_rap, xbgRap, 769, 1, 1);
	m_texts.AddTextContainer("Nguyen Trung Tin ( Thanh vien ) ", semiBold, 20, Color::Black, 153, 785);
	m_texts.AddTextContainer("MSSV: 6351071070", semiBold, 20, Color::Black, 203, 815);
}
void ThirdTab::draw(RenderWindow& window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}
void ThirdTab::HandleMouseClick(int x, int y)
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
void ThirdTab::Click(int x, int y) {

}
int ThirdTab::GetState()
{
	return selectedItemIndex;
}
int ThirdTab::GetCurrentState()
{
	return curentState;
}
void ThirdTab::SetCurrentState(int state)
{
	curentState = state;
}