#include "object2d.h"

Object2D::Object2D()
{
    speed = 400;

    object.setPointCount(3);
    object.setRadius(20);

    Position.x = 400;
    Position.y = 300;
}

void Object2D::moveLeft()
{
    m_LeftPressed = true;
}

void Object2D::moveRight()
{
    m_RightPressed = true;
}

void Object2D::stopLeft()
{
    m_LeftPressed = false;
}

void Object2D::stopRight()
{
    m_RightPressed = false;
}


void Object2D::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        Position.x += speed * elapsedTime;
    }

    if (m_LeftPressed)
    {
        Position.x -= speed * elapsedTime;
    }

    // Теперь сдвигаем спрайт на новую позицию
    object.setPosition(Position);

}

CircleShape Object2D::getObject(){
    return object;
}
