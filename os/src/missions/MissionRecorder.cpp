//
// Created by Oleksandra Baukh on 2/27/18.
//

#include "MissionRecorder.h"

MissionRecorder::MissionRecorder(uint8 id) : id(id) {}

uint8 MissionRecorder::getId() const {
    return id;
}

MissionRecorder::~MissionRecorder() {

}
