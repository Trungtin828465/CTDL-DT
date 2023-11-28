#include <iostream>
#include "I_Component.h"
using namespace std;

#pragma once
class BlockComponent : public I_Component
{
public:
    BlockComponent(string filepath, float xPosotion = 1, float yPosotion = 1, float xScale = 1, float yScale = 1);
    ~BlockComponent() {};
    void Render(RenderWindow& ref);
    FloatRect getGlobalBounds() {
        return m_sprite.getGlobalBounds();
    }
private:
    Texture m_texture;
    Sprite m_sprite;
};

