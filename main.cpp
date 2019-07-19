#include <iostream>
#include <math.h>

#include "thread"

//Graphics librory
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace std;
using namespace sf;

uint procPhisics = 0;
uint frameReady = 0;

double map1(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

class Object  : public sf::Transformable, public sf::Drawable
{
protected:
    float posX, posY;
    float angle, speed, maxSpeed, minSpeed, accelSpeed, accelRotate, accelReverse, rotate;
    sf::Color Color;
    float size;
    float mass;
    float energy;
    float healthPoint;
    CircleShape object;
public:
    Object()
    {
    }

    double toDegrees(double radians)
    {
        return double(double(radians) * 180.0 / M_PI);
    }

    double toRad(double Deg)
    {
        return double(Deg*(M_PI/180));
    }

    double dista(double posX1, double posY1, double posY2, double posX2){
        posX1 =toRad(posX1);
        posX2 =toRad(posX2);
        posY1 =toRad(posY1);
        posY2 =toRad(posY2);
        return acos(sin(posY1)*sin(posY2)+cos(posY1)*cos(posY2)*cos(posX1-posX2)) * 6371302;
    }

    void setParamets(float sp, float maxSp, float minSp, float acc, float accRev, float accR, float rot)
    {
        speed = sp;
        maxSpeed = maxSp;
        minSpeed = minSp;
        accelSpeed = acc;
        accelReverse = accRev;
        accelRotate = accR;
        rotate = rot;
    }

    void move(int direction, int turn)
    {
        static float oldAngle;
        if(turn>0)
        {
            angle += accelRotate;

        }
        else if (turn<0)
        {
            angle -= accelRotate;
        }


        if(direction>0)
        {
            speed += accelSpeed;
            if(speed > maxSpeed) speed = maxSpeed;
        }
        else if (direction<0)
        {
            speed -= accelSpeed;
            if(speed < minSpeed) speed = minSpeed;
        }
        else if(speed < 0)speed += accelReverse;
        else if(speed > 0) speed -= accelReverse;
        cout<<"SPEED "<<speed<<endl;

    }

    void update()
    {
        posX += sin(angle) * speed;
        posY += cos(angle) * speed;
        cout<<"posX "<< posX<<" posY "<< posY<<" angle "<<angle<<endl;
        if(posX < 0 && posX > 800) speed =0;
        if(posY < 0 && posY > 600) speed =0;
        object.setPosition(posX,posY);
        //object.rotate(rotate);
        move(0, 0);
    }

    void draw( sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(object, states);
    }

    void setFigure(uint point, int radius){
        object.setPointCount(point);
        object.setRadius(radius);
    }

};

class Player: public Object{
public:
    Player(){
        setFigure(3, 60);
        setParamets(0, 2.0, -1. , 0.2, 0.1, 0.01, 0);
    }


};

Player newPlayer;

void phisics(){
    while(procPhisics){
        if(frameReady){
            newPlayer.update();
            frameReady=0;
        }
    }
}


int main()
{
    RenderWindow window(VideoMode(800, 600), "Game");
    window.setFramerateLimit(30);


    thread phisicsThread(phisics);
    phisicsThread.detach();
    procPhisics =1;

    while (window.isOpen())
    {
        frameReady =1;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                procPhisics = 0;
                window.close();
            }

            if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
            {
                newPlayer.move(0, 1);
            }

            if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
            {
                newPlayer.move(0, -1);
            }

            if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
            {
                newPlayer.move(-1, 0);
            }

            if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
            {
                newPlayer.move(1, 0);
            }

        }

        window.clear();
        window.draw(newPlayer);
        window.display();
    }
    return 0;
}
