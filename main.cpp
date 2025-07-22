#include <iostream>
#include <cstring>
#include <string>
#include "include/Instruction.h"
#include "include/Memory.h"
#include "include/Executor.h"
#include "utility/InputManager.h"

Memory mem{};

int main() {
    ManageInput();
    Execute();
}