#ifndef MEMORY_H
#define MEMORY_H
constexpr int MemSize = 1e4;
class Memory {
    unsigned int mem[MemSize]{};
    unsigned int cursor = 0;
public:

    Memory() = default;

    void MoveCursor(unsigned int goal) {
        cursor = goal;
    }

    unsigned int LoadWord() {
        unsigned int ret = mem[cursor];
        ++cursor;
        return ret;
    }

    void StoreWord(unsigned int val) {
        mem[cursor] = val;
    }
};
#endif //MEMORY_H
