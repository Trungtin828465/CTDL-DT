#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "dataBase.h"
#include "MainTab.h"
class FirstPage : public MainTab
{
private:
	BlockContainer m_blocks;
	TextContainer m_texts;
	listMovie a;
public:
	FirstPage(int num);
	void draw(RenderWindow& window);
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
};
