#include <cassert>

bool palindrome(const char* str) {
    const char* end = str;
    while (*end) {
        ++end;
    }
    --end;
    while (str < end) {
        if (*str != *end) {
            return false;
        }
        ++str;
        --end;
    }
    return true;
}

int main() {
    assert(palindrome("abba") == true);
    assert(palindrome("aba") == true);
    assert(palindrome("abc") == false);
    assert(palindrome("ccc") == true);
    assert(palindrome(nullptr) == 0);
    return 0;
}