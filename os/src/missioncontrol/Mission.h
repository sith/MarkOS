//
// Created by Oleksandra Baukh on 2/23/18.
//

#ifndef MARKOS_MISSION_H
#define MARKOS_MISSION_H


class Mission {
    const char *name;
public:

    virtual ~Mission() {
    }

    virtual void start()=0;

    virtual void finish()=0;

    virtual void replay()=0;

    const char *getName() const {
        return name;
    }
};


#endif //MARKOS_MISSION_H
