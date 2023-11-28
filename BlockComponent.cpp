#include "BlockComponent.h"
BlockComponent::BlockComponent(string filepath, float xPosotion, float yPosotion, float xScale, float yScale)
{
    m_texture.loadFromFile(filepath);
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(xScale, yScale);
    m_sprite.setPosition(xPosotion, yPosotion);
}
void BlockComponent::Render(RenderWindow &ref)
{
    ref.draw(m_sprite);
}