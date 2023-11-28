#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
class SecondTab : public MainTab
{
private:
	BlockContainer m_blocks;
	TextContainer m_texts;
public:
	SecondTab(int num);
	void draw(RenderWindow& window);
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	//void Click(int x, int y);
	int GetCurrentState();
	void SetCurrentState(int state);
};

