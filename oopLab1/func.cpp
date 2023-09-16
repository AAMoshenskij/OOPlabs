#include "func.h"

bool check_palindrom(string word) {
    int len = word.length();
    for(int i = 0; i < len/2; ++i) {
        if(word[i] != word[len-i-1]) {
            return false;
        }
    }
    return true;
}