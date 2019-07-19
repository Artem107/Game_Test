#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Object2D
{
private:
    Vector2f Position;

    CircleShape object;

    bool m_LeftPressed;
    bool m_RightPressed;

    float speed;

public:
    Object2D();
    CircleShape getObject();

    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void update(float elapsedTime);
};

#endif // OBJECT2D_H
