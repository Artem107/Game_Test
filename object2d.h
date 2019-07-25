#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Object2D
{
private:
    Vector2f Position;
    float angle;

    CircleShape object;
    CircleShape direction;

    bool m_ForwardPressed;
    bool m_BackPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    float speed;
    float rotate;
    float angleOld;

public:
    Object2D();
    CircleShape getObject();
    CircleShape getObject1();

    void moveForward();

    void moveBack();

    void stopForward();

    void stopBack();
    
    void rotateLeft();
    
    void rotateRight();
    
    void stopLeft();
    
    void stopRight();

    void update(float elapsedTime);

    float zeroFunc(float value, float step);
};

#endif // OBJECT2D_H
