#include "object2d.h"

Object2D::Object2D()
{
    speed = 0;

    object.setPointCount(3);
    object.setRadius(20);

    Position.x = 400;
    Position.y = 300;
}

void Object2D::moveForward()
{
    m_ForwardPressed = true;
}

void Object2D::moveBack()
{
    m_BackPressed = true;
}

void Object2D::stopForward()
{
    m_ForwardPressed = false;
}

void Object2D::stopBack()
{
    m_BackPressed = false;

}

void Object2D::rotateLeft()
{
    m_LeftPressed = true;
}

void Object2D::rotateRight()
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
    if (m_ForwardPressed)
    {
        Position.y += speed * elapsedTime;
        speed+=7;
        if(speed>=400)speed = 400;
    }

    if (m_BackPressed)
    {
        Position.y += speed * elapsedTime;
        speed-=7;
        if(speed<=-400)speed = -400;
    }

    if(!m_ForwardPressed && !m_BackPressed)
    {
        Position.y += speed * elapsedTime;
        speed=zeroFunc(speed);
    }
    
    if (m_LeftPressed)
    {
        Position.x += speed * elapsedTime;
        speed+=7;
        if(speed>=400)speed = 400;
    }

    if (m_RightPressed)
    {
        Position.x += speed * elapsedTime;
        speed-=7;
        if(speed<=-400)speed = -400;
    }

    if(!m_LeftPressed && !m_RightPressed)
    {
        Position.x += speed * elapsedTime;
        speed=zeroFunc(speed);
    }

    // Теперь сдвигаем спрайт на новую позицию
    object.setPosition(Position);

}

int Object2D::zeroFunc(int value){
    if(value<0)return value+4;
    if(value>0)return value-4;
    return 0;
}

CircleShape Object2D::getObject(){
    return object;
}
