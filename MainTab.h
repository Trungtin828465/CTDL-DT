#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
class MainTab {
protected:
	int curentState;// ID của các page
	int selectedItemIndex;
	Font bold;
	Font semiBold;
	Font regular;
	pair<int, int> seat;

	float xPos = 40.0f;
	float yPos = 85.0f;
	float xScale = 0.55;
	float yScale = 0.55;
	float xPosInfo = 200.0f;
	float wBgGray = 73;
	float wBgGrayLarger = 285;
	float xLogoPosition = 220;
	float yLogoPosition = 20.0f;
	float xIconPrevPosition = 40.0f;
	float yIconPrevPosition = 35.0f;

public:
	MainTab() {}// hàm mặc định
	MainTab(int num) // hàm mặc định có tham số
	{
		selectedItemIndex = num;
		curentState = num;
	}
	virtual void draw(RenderWindow& window) = 0; // phương thức ảo để vẽ
	virtual void HandleMouseClick(int x, int y) = 0;
	virtual void Click(int x, int y) = 0;
	virtual int GetState() = 0;
	virtual int GetCurrentState() = 0;
	virtual void SetCurrentState(int state) = 0;
};