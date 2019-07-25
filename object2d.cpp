#include "object2d.h"

Object2D::Object2D()
{
    speed = 0.f;
    rotate = 0.f;
    angle = M_PI_2;

    direction.setPointCount(3.f);
    direction.setRadius(10.f);
    direction.setOrigin(10.f,20.f);
    direction.setFillColor(Color::Blue);


    object.setPointCount(3.f);
    object.setRadius(20.f);
    object.setOrigin(20.f,20.f);

    Position.x = 400.f;
    Position.y = 300.f;
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
        speed-=10.f;
        if(speed<=-400.f)speed = -400.f;
    }

    if (m_BackPressed)
    {
        speed+=10.f;
        if(speed>=400.f)speed = 400.f;
    }

    if(!m_ForwardPressed && !m_BackPressed && speed != 0.f)
    {
        speed=zeroFunc(speed, 7.f);
    }
    
    if (m_LeftPressed)
    {
        rotate-=0.1f;
        if(rotate<=-10.f)rotate = -10.f;
    }

    if (m_RightPressed)
    {
        rotate+=0.1f;
        if(rotate>=10.f)rotate = 10.f;
    }

    if(!m_LeftPressed && !m_RightPressed && rotate != 0.f)
    {
        rotate=zeroFunc(rotate,0.1f);
    }

    // Теперь сдвигаем спрайт на новую позицию
    Position.y += sin(angle) * speed * elapsedTime;
    Position.x += cos(angle) * speed * elapsedTime;
    angle += rotate * elapsedTime;
    object.setPosition(Position);
    direction.setPosition(Position);
    object.rotate(rotate);
    direction.rotate(rotate);
    float temp = angleOld - angle;
    angleOld = angle;
    cout<<"rotate= "<<rotate<<endl;
    cout<<"speed= "<<speed<<endl;
    cout<<"angle= "<<angle<<endl;
    cout<<"DDD= "<<temp<<endl;
    if(abs(angle)>M_PI*2.f) angle = 0.f;
    if(Position.x < 0.f) Position.x=0.f;
    if(Position.y < 0.f) Position.y=0.f;
    if(Position.x > 800.f) Position.x=800.f;
    if(Position.y > 600.f) Position.y=600.f;
}

float Object2D::zeroFunc(float value, float step){
    if(value<0.f) value+=step;
    if(value>0.f) value-=step;
    if(abs(value)<step) value = 0;
    return value;
}

CircleShape Object2D::getObject(){
    return object;
}

CircleShape Object2D::getObject1(){
    return direction;
}
