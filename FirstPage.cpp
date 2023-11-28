#include "FirstPage.h"
#include "SecondTab.h"
#include <fstream>

FirstPage::FirstPage(int num) : m_blocks("second"), m_texts("second")
{
	curentState = 1;
	selectedItemIndex = num;

	bold.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	semiBold.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
	regular.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");

	string khungdo = "images/bg-red.png";
	string khungden = "images/bg-gray-larger.png";
	float xIconPrevPosition = 109.0f;
	float yIconPrevPosition = 148.0f;

	m_blocks.AddBlockContainer(a.a[0].filePath, xIconPrevPosition, yIconPrevPosition, 0.63,0.57);
	m_blocks.AddBlockContainer(a.a[1].filePath, 320, yIconPrevPosition, 0.63,0.57);
	m_blocks.AddBlockContainer(a.a[2].filePath, xIconPrevPosition, 392, 0.63,0.57);
	m_blocks.AddBlockContainer(a.a[3].filePath, 320, 393, 0.63,0.57);
	m_blocks.AddBlockContainer(a.a[4].filePath, xIconPrevPosition, 647, 0.63,0.57);
	m_blocks.AddBlockContainer(a.a[5].filePath, 320, 647, 0.63,0.57);
	m_blocks.AddBlockContainer(khungdo, 105, 92, 0.1769, 0.2469);
	m_blocks.AddBlockContainer(khungden, 236, 92, 0.5454, 0.9302);
	m_blocks.AddBlockContainer(khungden, 367, 92, 0.5454, 0.9302);
	//
	/*ifstream fin("input.txt");
	string phim;
	std::getline(fin, phim);
	fin.close();
	wstring wtext = L"Phim chiếu";
	sf::String text;
	text = sf::String::fromUtf8(begin(wtext), end(wtext));*/
	m_texts.AddTextContainer("SLC2T", bold, 50, Color::Red, 212, 25);

	m_texts.AddTextContainer("Phim Chieu", semiBold, 15, Color::White, 109, 100);
	m_texts.AddTextContainer("Rap Chieu", semiBold, 15, Color::Black, 248, 100);
	m_texts.AddTextContainer("Thong Tin", semiBold, 15, Color::Black, 380, 100);
	//
	m_texts.AddTextContainer("Nam Dem Kinh hoang", semiBold, 16, Color::Black, 109, 353);
	m_texts.AddTextContainer("The Marvel", semiBold, 16, Color::Black, 321, 353);
	m_texts.AddTextContainer("Ke Kien Tao", semiBold, 16, Color::Black, 109, 601);
	m_texts.AddTextContainer("Sieu Dang", semiBold, 16, Color::Black, 321, 599);
	m_texts.AddTextContainer("Cu May An Tien", semiBold, 16, Color::Black, 109, 855);
	m_texts.AddTextContainer("Biet Doi Danh Thue 4", semiBold, 16, Color::Black, 321, 853);

}
void FirstPage::draw(RenderWindow& window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}

void FirstPage::HandleMouseClick(int x, int y)
{
	int xIconPrevPosition = 109;
	int yIconPrevPosition = 148;
	int width = 119;// chieu rong
	int height = 39; // chieu dai
	// Kiểm tra xem click có nằm trong vị trí cụ thể không
	if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= 95 && y <= 95 + height)
	{
		curentState = 1;
		cout << "Da click vao phim chieu" << endl;
	}
	else if (x >= xIconPrevPosition + 139 && x <= xIconPrevPosition + 139 + width && y >= 95 && y <= 95 + height)
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
void FirstPage::Click(int x, int y) {
	int width = 173;// chieu rong
	int height = 202; // chieu dai
	int xIconPrevPosition = 109; // chieu rong X
	int yIconPrevPosition = 148; // chieu dai Y

	if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= yIconPrevPosition && y <= yIconPrevPosition + height)
	{
		curentState = 11;
		cout << "Da chon phim 1	" << endl;
	}
	else if (x >= 320 && x <= 320 + width && y >= yIconPrevPosition && y <= yIconPrevPosition + height) {
		curentState = 12;
		cout << "Da chon phim 2" << endl;
	}
	else if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= 392 && y <= 392 + height) {
		curentState = 13;
		cout << "Da chon phim 3" << endl;
	}
	else if (x >= 320 && x <= 320 + width && y >= 393 && y <= 393 + height) {
		curentState = 14;
		cout << "Da chon phim 4	" << endl;
	}
	else if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= 647 && y <= 647 + height) {
		curentState = 15;
		cout << "Da chon phim 5	" << endl;
	}
	else if (x >= 320 && x <= 320 + width && y >= 647 && y <= 647 + height) {
		curentState = 16;
		cout << "Da chon phim 6	" << endl;
	}
}
// Viết thêm
int FirstPage::GetState()
{
	return selectedItemIndex;
}
int FirstPage::GetCurrentState()
{
	return curentState;
}
void FirstPage::SetCurrentState(int state)
{
	curentState = state;
}
// in man 2
