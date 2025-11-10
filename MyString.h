
#ifndef MYSTRING_H
#define MYSTRING_H
#include <cctype>
int strlen(const char* str) {
    const char* c = str;
    while (*c != '\0') c++;
    return c - str;
}
void strcpy(char* dest, const char* ori) {
    while (*ori != '\0') {
        *dest = *ori;
        dest++;
        ori++;
    }
    *dest = '\0';
}
void strupr(char* str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}
void strlwr(char* str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}
void strwupr(char* str) {
    bool word = true;
    while (*str != '\0') {
        if (word && isalpha(*str)) {
            *str = toupper(*str);
            word = false;
        } else if (*str == ' ')
            word = true;
        else
            *str = tolower(*str);
        str++;
    }
}
#endif  // MYSTRING_H
