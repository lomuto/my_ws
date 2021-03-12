#include <string.h>

#include <iostream>
#define BUFFER_SIZE 512
#define SWAP(x, y) x = x ^ y, y = x ^ y, x = x ^ y

void reverse(char origin[] /*, char dest[]*/) {
    int ORI_LEN = strlen(origin);
    // int i = 0;
    // for (char *ptr = origin + ORI_LEN - 1; ptr != origin - 1; ptr--, i++) {
    //     *(dest + i) = *ptr;
    // }
    // *(dest + i) = '\0';
    for (char *p = origin, *q = origin + ORI_LEN - 1; p < q; p++, q--) {
        SWAP(*q, *p);
    }
}

int main() {
    std::cout << "Reverse a String" << std::endl;

    char BUFFER[BUFFER_SIZE];
    // char REVERSED[BUFFER_SIZE];

    std::cin.getline(BUFFER, BUFFER_SIZE);

    reverse(BUFFER /*, REVERSED*/);
    std::cout << "Reversed string is: " << BUFFER << std::endl;
}