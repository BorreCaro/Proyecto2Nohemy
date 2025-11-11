
#ifndef MYSTRING_H
#define MYSTRING_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void readline(char* str, int limit) {
    int entercount = 0;
    limit--;
    while (limit--) {
        char c = getchar();
        if (c == '\n') {
            entercount++;
            if (entercount == 2) break;
        } else
            entercount = 0;
        *str = c;
        str++;
    }
    *(str - (entercount > 0 ? 1 : 0)) = '\0';
}

int strlen(const char* str) {
    const char* c = str;
    while (*c != '\0') c++;
    return c - str;
}
int strcmp(const char* str1, const char* str2) {
    while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2) return *str1 - *str2;
        str1++;
        str2++;
    }
    return 0;
}
bool strchr(const char* str, char c) {
    while (*str != '\0') {
        if (*str == c) return true;
    }
    return false;
}
int contarVariosChar(const char* str, const char* caracteres) {
    int num = 0;
    while (*str != '\0') {
        if (strchr(caracteres, *str)) num++;
        str++;
    }
    return num;
}

void strcpy(char* dest, const char* ori, int limit = 500000) {
    while (*ori != '\0' && limit-- > 1) {
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
        } else if (*str == ' ' || *str == '\t' || *str == '\n')
            word = true;
        else
            *str = tolower(*str);
        str++;
    }
}
void safeReadInt(int& var, const int min, const int max, char msg[50], char errorMsg[50]) {
    long long val = 0;
    bool isNum;
    do {
        isNum = true;
        char buffer[11];
        printf("%s", msg);
        fgets(buffer, 10, stdin);
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') break;
            if (i == 0 && buffer[i] == '-') continue;
            if (!isdigit(buffer[i])) isNum = false;
        }
        if (isNum) val = atoll(buffer);
        if (val < min || val > max || !isNum) printf("%s\n", errorMsg);
    } while (val < min || val > max || !isNum);
    var = val;
}
#endif  // MYSTRING_H
