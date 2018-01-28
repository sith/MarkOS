#ifndef MARK1_CONTROLLER_H
#define MARK1_CONTROLLER_H

#include "../modes/EmptyModeListener.h"

class Controller {
protected:
    ModeListener *modeListener = new EmptyModeListener;
public:

    void addModeListener(ModeListener &ml);

    virtual void readControllerCommand()=0;
};

#endif //MARK1_CONTROLLER_H
