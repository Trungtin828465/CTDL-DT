#pragma once
#include <iostream>
#include "I_Component.h"
using namespace std;
class TextComponent : public I_Component
{
private:
    Text m_text;

public:
    TextComponent() {
        Font font;
        font.loadFromFile("fonts/Montserrat/Montserrat-ExtraBold.ttf");
        m_text.setFont(font);
        m_text.setString("");
        m_text.setCharacterSize(0);
        m_text.setFillColor(Color::Black);
        m_text.setPosition(0, 0);
    }
    TextComponent(string text, Font& font, unsigned int size, Color color = Color::Black, float xPosotion = 1, float yPosotion = 1);
    void Render(RenderWindow& ref);
   
};

