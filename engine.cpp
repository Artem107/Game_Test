#include "engine.h"
#include "math.h"

Engine::Engine()
{

        m_Window.create(VideoMode(800, 600),
            "Simple Game Engine");

        m_Window.setFramerateLimit(60);
}

void Engine::start()
{
    // Расчет времени
    Clock clock;

    while (m_Window.isOpen())
    {
        // Перезапускаем таймер и записываем отмеренное время в dt
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    m_Window.close();
                }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }

    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        object2D.moveForward();
    }
    else
    {
        object2D.stopForward();
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        object2D.moveBack();
    }
    else
    {
        object2D.stopBack();
    }

    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        object2D.rotateLeft();
    }
    else
    {
        object2D.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        object2D.rotateRight();
    }
    else
    {
        object2D.stopRight();
    }

}

void Engine::update(float dtAsSeconds)
{
    object2D.update(dtAsSeconds);
}

void Engine::draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(Color::Red);

    // Отрисовываем фон
    m_Window.draw(object2D.getObject());
    m_Window.draw(object2D.getObject1());

    // Отображаем все, что нарисовали
    m_Window.display();
}
