#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <iostream>
#include <string>
#include "utility.h"
#include "../include/Memory.h"
extern Memory mem;
inline void ManageInput() {
    std::string token;
    std::string recorder{};
    while (std::cin >> token) {
        if (token.length() == 9) {
            unsigned int index = HexToDec(token.substr(1, 8));
            mem.MoveCursor(index / 4);
        } else {
            recorder.insert(0, token);
            if (recorder.length() == 8) {
                unsigned int val = HexToDec(recorder);
                mem.StoreWord(val);
            }
        }
    }
}
#endif //INPUTMANAGER_H
