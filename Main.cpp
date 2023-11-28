#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenManager.h"
#include "FirstPage.h"
#include "SecondaryPage.h"
#include "ThirdPage.h"
#include "FourthPage.h"

using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;
static pair<int, int> m_seats;

int main()
{

    ScreenManager screenManager;

    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SLC2T");
    View view(sf::FloatRect(0, 0, 585, 900));
    window.setView(view);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
                cout << "Handling event closed" << endl;
                exit(EXIT_SUCCESS);
            }
            
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    screenManager.HandleMouseClick(mousePos.x, mousePos.y);
                    screenManager.Click(mousePos.x, mousePos.y);
                }
            }
            
            if (event.type == sf::Event::MouseMoved && event.type != sf::Event::MouseLeft)
            {
                int mouseX = event.mouseMove.x;
                int mouseY = event.mouseMove.y;
                std::cout << "Mouse X: " << mouseX << " Mouse Y: " << mouseY << std::endl;
            }  
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            view.move(0, -0.5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            view.move(0, 0.5);
        }

        window.clear(Color::White);
        window.setView(view);
        // render Màn hình
        screenManager.draw(window);
        window.display();
    }

    return 0;
}