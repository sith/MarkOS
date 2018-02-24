//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_FILE_H
#define MARKOS_FILE_H

class File {
public:
    virtual int readInt()= 0;

    virtual const char *readString()= 0;

    virtual void writeInt(int number)= 0;

    virtual void writeString(const char *string)= 0;
};

#endif //MARKOS_FILE_H
