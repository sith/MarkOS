//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_OBSTACLESENSOR_H
#define MARKOS_OBSTACLESENSOR_H

#include <cycle/CycleListener.h>
#include <List.h>
#include <LinkedList.h>

class Obstacle {
public:
    //TODO doesn't have to be public
    bool left;
    bool forward;
    bool right;

    Obstacle(bool left, bool forward, bool right);

    Obstacle();

    bool hasAnyObstacle();
};

class ObstacleListener {
public:
    virtual void onEvent(Obstacle obstacle) = 0;
};

class ObstacleSensor : public CycleListener {
    List<ObstacleListener> *listeners = new LinkedList<ObstacleListener>;
public:
    virtual ~ObstacleSensor();

    void addListener(ObstacleListener *obstacleListener);

    void removeListener(ObstacleListener *obstacleListener);

    void onEvent(unsigned long cycleNumber) override;

    virtual Obstacle read() = 0;

};

#endif //MARKOS_OBSTACLESENSOR_H
