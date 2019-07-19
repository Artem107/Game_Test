#ifndef ENGINE_H
#define ENGINE_H
#include "object2d.h"

//Graphics librory
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;


class Engine
{
private:
    RenderWindow m_Window;

    void input();
    void update(float dtAsSeconds);
    void draw();
    Object2D object2D;

public:
    Engine();

    void start();
};

#endif // ENGINE_H
