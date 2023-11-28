#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
class ThirdTab : public MainTab
{
private:
	BlockContainer m_blocks;
	TextContainer m_texts;
public:
	ThirdTab(int num);
	void draw(RenderWindow& window);
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
	//void Click(int x, int y);
};

