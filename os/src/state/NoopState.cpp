//
// Created by Oleksandra Baukh on 1/20/18.
//

#include "NoopState.h"

State &NoopState::execute() {
    return *this;
}

void NoopState::cancel() {

}

void NoopState::reset() {

}
