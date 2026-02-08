#pragma once

template <class T>
class HashFunc {
    public:
    int hash(std::string key) {
        int h = 0;
        for (char c : key) {
            h = 31 * h + int(c);
        }
        return h;
    }

    // Segunda función hash para double hashing
    int hash2(std::string key) {
        int h = 0;
        for (char c : key){
            h = 17 * h + int(c);
        } 
        return abs(h) * 2 + 1; 
    }
};
