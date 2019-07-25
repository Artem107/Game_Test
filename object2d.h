#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Object2D
{
private:
    Vector2f Position;

    CircleShape object;

    bool m_ForwardPressed;
    bool m_BackPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    float speed;

public:
    Object2D();
    CircleShape getObject();

    void moveForward();

    void moveBack();

    void stopForward();

    void stopBack();
    
    void rotateLeft();
    
    void rotateRight();
    
    void stopLeft();
    
    void stopRight();

    void update(float elapsedTime);

    int zeroFunc(int value);
};

#endif // OBJECT2D_H
