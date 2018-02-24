
//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_MOCKFILE_H
#define MARKOS_MOCKFILE_H

#include <filesystem/File.h>
#include "gmock/gmock.h"

class MockFile : public File {
public:
    MOCK_METHOD0(readInt, int());

    MOCK_METHOD0(readString, const char*());

    MOCK_METHOD1(writeInt, void(int
            number));

    MOCK_METHOD1(writeString, void(
            const char *string));
};


#endif //MARKOS_MOCKFILE_H
