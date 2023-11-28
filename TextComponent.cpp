#include "TextComponent.h"
TextComponent::TextComponent(string text, Font &font, unsigned int size, Color color, float xPosotion, float yPosotion)
{
    m_text.setFont(font);
    m_text.setString(text);
    m_text.setCharacterSize(size);
    m_text.setFillColor(color);
    m_text.setPosition(xPosotion, yPosotion);
}

void TextComponent::Render(RenderWindow &ref)
{
    ref.draw(m_text);
}