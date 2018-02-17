#ifndef MARK1_CONTROLLER_H
#define MARK1_CONTROLLER_H

#include <collections/List.h>
#include <cycle/CycleListener.h>
#include <collections/LinkedList.h>
#include "../modes/EmptyModeListener.h"
#include "ControllerCommandListener.h"


class Controller : public CycleListener {
    EmptyModeListener defaultModeListener;
    Pointer<List<ControllerCommandListener>> commandListeners{new LinkedList<ControllerCommandListener>};

    void notifyOnCommand(Command command);

protected:
    ModeName modeName = NONE;
    ModeListener *modeListener = &defaultModeListener;

    ModeName getModeName() const;

public:
    Controller();

    void onEvent(unsigned long cycleNumber) override;

    virtual ~Controller();

    void addModeListener(ModeListener &ml);

    void addListener(ControllerCommandListener &controllerCommandListener);

    void removeListener(ControllerCommandListener &controllerCommandListener);

    virtual Command readControllerCommand()=0;

    //TODO must be friend
    List<ControllerCommandListener> *getCommandListeners() const;

};

#endif //MARK1_CONTROLLER_H
