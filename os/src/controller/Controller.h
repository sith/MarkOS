#ifndef MARK1_CONTROLLER_H
#define MARK1_CONTROLLER_H

#include "../modes/EmptyModeListener.h"

class Controller {
    ModeListener *defaultModeListener = new EmptyModeListener;
protected:

    ModeListener *modeListener = defaultModeListener ;
public:

    virtual ~Controller();

    void addModeListener(ModeListener &ml);

    virtual void readControllerCommand()=0;
};

#endif //MARK1_CONTROLLER_H
