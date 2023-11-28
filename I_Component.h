#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once
class I_Component
{
public:
    virtual ~I_Component() {}
    virtual void Render(RenderWindow& ref) {}
};

