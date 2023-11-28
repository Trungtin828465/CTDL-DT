#include "TextContainer.h"
TextContainer::TextContainer(string name)
{
    m_name = name;
}
void TextContainer::AddTextContainer(string text, Font &font, unsigned int size, Color color, float xPosotion, float yPosotion)
{
    shared_ptr<TextComponent> item = make_shared<TextComponent>(text, font, size, color, xPosotion, yPosotion);
    m_components.push_back(item);
}
void TextContainer::Render(RenderWindow &ref)
{
    for (int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->Render(ref);
    }
}