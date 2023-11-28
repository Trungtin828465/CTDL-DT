
// scr bên dưới của nhánh dataBase

#include "SecondaryPage.h"

SecondaryPage::SecondaryPage(int num) : m_blocks("second"), m_texts("second")
{
	
	selectedItemIndex = num;
	curentState = num;

	bold.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	semiBold.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
	regular.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");

	listMovie x;
	int filmIndex = num % 11;
	string filePath = x.a[filmIndex].filePath;
	string filePathIconPrev = "images/icon-prev.png";

	// icon previous
	m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);
	m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);

	ChoseDate(m_blocks, m_texts);

	m_texts.AddTextContainer("SLC2T", bold, 50, Color::Red, 212, 35);
	// set film's name
	m_texts.AddTextContainer(x.a[filmIndex].name, bold, 30, Color::Black, xPosInfo, 113);
	// set film's category
	m_texts.AddTextContainer("The loai:", semiBold, 18, Color::Black, xPosInfo, 150);
	// set film's category content
	m_texts.AddTextContainer(x.a[filmIndex].type, regular, 16, Color::Black, xPosInfo + 85, 150 + 2);
	// set film's time
	m_texts.AddTextContainer("Thoi luong:", semiBold, 18, Color::Black, xPosInfo, 172);
	// set film's time content
	m_texts.AddTextContainer(x.a[filmIndex].time, regular, 16, Color::Black, xPosInfo + 110, 172 + 2);
	// set film's language
	m_texts.AddTextContainer("Ngon ngu:", semiBold, 18, Color::Black, xPosInfo, 193);
	// set film's language content
	m_texts.AddTextContainer(x.a[filmIndex].language, regular, 16, Color::Black, xPosInfo + 102, 193 + 2);
	// set film's Rate
	m_texts.AddTextContainer("Danh gia:", semiBold, 18, Color::Black, xPosInfo, 215);
	// set film's Rate content
	m_texts.AddTextContainer(x.a[filmIndex].rating, regular, 16, Color::Black, xPosInfo + 95, 215 + 2);
	// set film's Date
	m_texts.AddTextContainer("Khoi Chieu:", semiBold, 18, Color::Black, xPosInfo, 238);
	// set film's Date content
	m_texts.AddTextContainer("10/11/2023", regular, 16, Color::Black, xPosInfo + 110, 238 + 2);
	//set film's Time content
	m_texts.AddTextContainer("Thoi luong:", semiBold, 18, Color::Black, xPosInfo, 262);
	m_texts.AddTextContainer(x.a[filmIndex].time, regular, 16, Color::Black, xPosInfo + 108, 264);
	// set film's description heading
	m_texts.AddTextContainer("Mo ta phim", semiBold, 26, Color::Black, xPos, 310);
	// set film's director
	m_texts.AddTextContainer("Dao dien:", semiBold, 18, Color::Black, xPos, 340);
	// set film's director content
	m_texts.AddTextContainer(x.a[filmIndex].director, regular, 16, Color::Black, xPos + 95, 340 + 2);
	// set film's actor
	m_texts.AddTextContainer("Dien vien long tieng:", semiBold, 18, Color::Black, xPos, 365);
	// set film's actor desc
	m_texts.AddTextContainer(x.a[filmIndex].artist, regular, 16, Color::Black, xPos + 198, 365 + 2);
	// set film' content
	m_texts.AddTextContainer("Noi dung phim:", semiBold, 18, Color::Black, xPos, 392);
	m_texts.AddTextContainer(x.a[filmIndex].content, regular, 16, Color::Black, xPos + 150, 392 + 2);

}

void SecondaryPage::draw(RenderWindow& window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}

bool SecondaryPage::prevButtonIsPressed(RenderWindow& window) {

	static bool isButtonPressed = false;
	BlockComponent prevIcon("images/data/ke-kien-tao.png", 40.0f, 44.0f, 0.22, 0.2);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		Vector2i mousePos = Mouse::getPosition(window);
		if (prevIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
			return true;
		}
	}

	return false;
}

bool SecondaryPage::nextButtonIsPressed(RenderWindow& window) {

	BlockComponent nextIcon("images/data/ke-kien-tao.png", 40.0f, 113.0f, 0.55, 0.55);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		Vector2i mousePos = Mouse::getPosition(window);
		if (nextIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
			return true;
		}
	}
	return false;
}

void SecondaryPage::ChoseDate(BlockContainer& m_blocks, TextContainer& m_texts)
{
	string date[7][2] = { {"T2", "19/11"}, {"T3", "20/11"}, {"T4", "21/11"}, {"T5", "22/11"}, {"T6", "23/11"}, {"T7", "24/11"}, {"CN", "25/11"} };
	m_texts.AddTextContainer("Chon ngay chieu", semiBold, 18, Color::White, xPos + 22.5, 40 + 390);
	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer(date[i][0], semiBold, 16, Color::Black, xPos + 22 + i * 73, 22 + yPos + 390);
		m_texts.AddTextContainer(date[i][1], regular, 14, Color::Black, xPos + 18 + i * 73, 40 + yPos + 390);
	}
	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 4.95 * yPos + 0 * 150, 0.3, 0.3);
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
	}
}
void SecondaryPage::ChoseCenima(BlockContainer& m_blocks, TextContainer& m_texts)
{
	m_texts.AddTextContainer("Chon rap chieu", semiBold, 18, Color::White, xPos + 32.5, 40 + 541);

	m_texts.AddTextContainer("Cinestar Quoc Thanh", semiBold, 16, Color::Black, xPos + 22.5, 110 + 541);
	m_texts.AddTextContainer("Cinestar Sinh vien", semiBold, 16, Color::Black, xPos + 32.5, 164 + 542);
	m_texts.AddTextContainer("CGV Vincom Thu Duc", semiBold, 16, Color::Black, xPos + 305, 110 + 541);
	m_texts.AddTextContainer("CGV GigaMall Thu Duc", semiBold, 16, Color::Black, xPos + 300, 164 + 542);

	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 4.95 * yPos + 1 * 150, 0.3, 0.3);
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
		else
			m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
	}
}
void SecondaryPage::ChoseTime(BlockContainer& m_blocks, TextContainer& m_texts)
{
	string time[7] = { "7h", "9h", "11h", "13h", "15h", "17h", "19h" };
	m_texts.AddTextContainer("Suat chieu", semiBold, 18, Color::White, xPos + 52.5, 40 + 740);

	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 5 * yPos + 2 * 172.5, 0.3, 0.3);
	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer(time[i], semiBold, 16, Color::Black, xPos + 22.5 + i * 73, 5.1 * yPos + 418);
		m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
	}
}

void SecondaryPage::HandleChoseDate(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.75 * yPos; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.75 * yPos + 51; // khong doi
	int space = 73;						// khong doi
	for (int i = 0; i < 7; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 106 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && DateWasSelected != i)
		{
			// clear
			if (DateWasSelected >= 0)
			{
				TimeWasSelected = -1;
				clearChoseTime();
				CenimaWasSelected = -1;
				clearChoseCenima();
				clearBgGray();
				for (int i = 0; i < 7; i++)
				{
					m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
				}
			}
			// handle
			DateWasSelected = i;
			cout << "Ngay " << DateWasSelected << endl;
			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + space * i, 5.75 * yPos, 1, 1);
			ChoseCenima(m_blocks, m_texts);
		}
	}
}
void SecondaryPage::HandleChoseCenima(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.3 * yPos + 190; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.3 * yPos + 245 + 43; // khong doi
	int space = wBgGrayLarger;				  // khong doi
	for (int i = 0; i < 2; i++)
	{
		// Hover(xMouse, yMouse);
	//	if (xMouse > xMinGray + space * i && xMouse < 260 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && CenimaWasSelected != i)
		if (xMouse > xMinGray + space * i && xMouse < 260 + space * i && yMouse <= yMinGray + 43 && yMouse >= yMinGray && CenimaWasSelected != i)
		{
			// clear
			if (CenimaWasSelected >= 0)
			{
				TimeWasSelected = -1;
				clearChoseCenima();
				for (int i = 0; i < 4; i++)
				{
					if (i < 2)
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
					else
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
				}
				clearChoseTime();
			}
			// handle
			CenimaWasSelected = i;
			cout << "Rap " << CenimaWasSelected << endl;

			m_blocks.AddBlockContainer("images/bg-gray-larger-hover.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
			ChoseTime(m_blocks, m_texts);
		}
		if (xMouse > xMinGray + space * i && xMouse < 260 + space * i && yMouse <= yMaxGray && yMouse >= 5.3 * yPos + 245 && CenimaWasSelected != i + 2)
		{
			// clear
			if (CenimaWasSelected >= 0)
			{
				TimeWasSelected = -1;
				clearChoseCenima();
				for (int i = 0; i < 4; i++)
				{
					if (i < 2)
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
					else
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
				}
				clearChoseTime();
			}
			// handle
			CenimaWasSelected = i + 2;
			cout << "'Rap " << CenimaWasSelected << endl;

			m_blocks.AddBlockContainer("images/bg-gray-larger-hover.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 245, 1, 1);
			ChoseTime(m_blocks, m_texts);
		}
	}
}
void SecondaryPage::HandleChoseTime(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.1 * yPos + 400; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.1 * yPos + 400 + 51; // khong doi
	int space = 73;							  // khong doi
	for (int i = 0; i < 7; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 106 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && TimeWasSelected != i)
		{
			// clear
			if (TimeWasSelected >= 0)
			{
				clearChoseTime();
				TimeWasSelected = -1;
				for (int i = 0; i < 7; i++)
				{
					m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
				}
			}
			// handle
			TimeWasSelected = i;
			cout << "Gio " << TimeWasSelected << endl;
			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + space * i, 5.1 * yPos + 400, 1, 1);
			// handle goto ThirdPage
		}
	}
}

void SecondaryPage::clearBgGray()
{
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-white-small.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
	}
}

void SecondaryPage::clearChoseCenima()
{
	if (CenimaWasSelected < 0)
	{
		m_blocks.AddBlockContainer("images/bg-white.png", xPos, 4.95 * yPos + 1 * 150, 1, 1);

		for (int i = 0; i < 5; i++)
			m_texts.pop();
	}
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			m_blocks.AddBlockContainer("images/bg-white-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
		else
			m_blocks.AddBlockContainer("images/bg-white-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
	}
}
void SecondaryPage::clearChoseTime()
{
	if (TimeWasSelected < 0)
	{
		m_blocks.AddBlockContainer("images/bg-white.png", xPos, 5 * yPos + 2 * 174, 1, 1);
		if (CenimaWasSelected >= 0)
			for (int i = 0; i < 8; i++)
				m_texts.pop();
	}
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-white-small.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
	}
}

void SecondaryPage::HandleMouseClick(int x, int y)
{

	if (x >= 40 && x <= 80 && y >= 40 && y <= 80) {
		cout << "Back button" << endl;
		this->clearBgGray();
		this->clearChoseCenima();
		this->clearChoseTime();
		this->handleResetValue();
		curentState = 1;
	}

	if (212<=x && x<=360 && 37<=y && y<=73){
		cout << "Click on logo" << endl;
		curentState = 1;
	}

	this->HandleChoseDate(x, y);
	this->HandleChoseCenima(x, y);
	// chương để tạm
	/*if (CenimaWasSelected != -1) {
		curentState += 10;
	}*/
	this->HandleChoseTime(x, y);
	if (TimeWasSelected != -1) {
		curentState += 10;
	}
}
void SecondaryPage::Click(int x, int y) {

}
int SecondaryPage::GetState()
{
	return selectedItemIndex;
}
int SecondaryPage::GetCurrentState()
{
	return curentState;
}
void SecondaryPage::SetCurrentState(int state)
{
	curentState = state;
}




