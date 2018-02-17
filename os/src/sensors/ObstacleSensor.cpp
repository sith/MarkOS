
#include "ObstacleSensor.h"

ObstacleSensor::~ObstacleSensor() {
    delete listeners;
}

void ObstacleSensor::addListener(ObstacleListener *obstacleListener) {
    listeners->add(obstacleListener);
}

void ObstacleSensor::removeListener(ObstacleListener *obstacleListener) {
    listeners->removeByPointer(obstacleListener);
}

void ObstacleSensor::onEvent(unsigned long cycleNumber) {
    auto obstacle = read();
    if (obstacle.hasAnyObstacle()) {
        auto pIterator = listeners->iterator();
        while (pIterator->hasNext()) {
            pIterator->next()->onEvent(obstacle);
        }
        delete pIterator;
    }
}


Obstacle::Obstacle(bool left, bool forward, bool right) : left(left), forward(forward), right(right) {}

Obstacle::Obstacle() {}

bool Obstacle::hasAnyObstacle() {
    return left || forward || right;
}
