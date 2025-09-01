#include "StrokeFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define P 1021
#define R 101

int Mputs(const char *str) {
    assert(str != NULL);
    if (str == NULL) {
        return EOF;
    }

    while (*str) {
        if (putchar(*str++) == EOF) {
            return EOF;
        }
    }

    if (putchar('\n') == EOF) {
        return EOF;
    }

    return 1; 
}

const char *Mstrchr(const char *str, int c) {
    assert(str != NULL);
    if (str == NULL){
        return NULL;
    }

    while (*str) {
        if (*str == (char)c) {
            return str;
        }
        str++;
    }

    if (c == '\0') {
        return str;
    }

    return NULL;
}

size_t Mstrlen(const char *str){
    assert(str != NULL);
    if (str == NULL){
        return NULL;
    }

    size_t i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char *Mstrcpy(char *str1, const char *str2){
    assert(str1 != NULL);
    assert(str2 != NULL);

    char *cur = str1;

    while ((*str2) != '\0'){
        *cur = *str2;
        str2++;
        cur++;
    }
    *cur = '\0';
    return str1;
}

char *Mstrncpy(char *str1, const char *str2, size_t num) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    size_t i = 0;
    while (i < num && str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }

    while (i < num) {
        str1[i] = '\0';
        i++;
    }
    return str1;
}

char *Mstrcat(char *str1, const char *str2){
    assert(str1 != NULL);
    assert(str2 != NULL);

    char *start = str1;
    while ((*str1) != '\0'){
        str1++;
    }
    while ((*str2) != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';

    return start;
}

char *Mstrncat(char *dest, const char *src, size_t num) {
    assert(dest != NULL);
    assert(src  != NULL);
    if (dest == NULL || src == NULL){
        return NULL;
    }

    char *start = dest;

    while ((*dest) != '\0') {
        dest++;
    }

    while (num-- && *src) {
        *dest++ = *src++;
    }

    *dest = '\0';

    return start;
}


char *Mfgets(char *str, int num, FILE *file) {
    assert(str  != NULL);
    assert(file != NULL);
    if (str == NULL || file == NULL){
        return NULL;
    }

    int c = 0;
    char *start = str;
    int i = 0;

    while (i < num - 1 && (c = getc(file)) != EOF) {
        *str++ = (char)c;
        i++;
        if (c == '\n') {
            break; 
        }
    }

    if (i == 0 && c == EOF) {
        return NULL;
    }

    *str = '\0'; 
    return start;
}


char *Mstrdup(char *str){
    assert(str != NULL);
    if (str == NULL){
        return NULL;
    }

    char *buff = (char *) malloc ((Mstrlen(str) + 1) * sizeof(char));
    if (buff == NULL){
        return NULL;
    }

    Mstrcpy(buff, str);

    return buff;
}

int Mgetline(FILE *file, char *str, int num) {
    assert(str  != NULL);
    assert(file != NULL);
    if (str == NULL || file == NULL){
        return NULL;
    }

    int c = 0;
    int i = 0;

    while (i < num - 1 && (c = fgetc(file)) != EOF && c != '\n') {
        str[i++] = (char)c;
    }

    if (c == '\n' && i < num - 1) {
        str[i++] = (char)c;
    }

    str[i] = '\0';

    if (i == 0 && c == EOF) {
        return -1;
    }

    return i;
}

// ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
//     if (lineptr == NULL || n == NULL || stream == NULL) {
//         return -1;
//     }

//     if (*lineptr == NULL || *n == 0) {
//         *n = 128; 
//         *lineptr = (char *) malloc(*n);
//         if (*lineptr == NULL) {
//             return -1;
//         }
//     }

//     size_t pos = 0;
//     int c;

//     while ((c = fgetc(stream)) != EOF) {

//         if (pos + 1 >= *n) {
//             size_t new_size = *n * 2;
//             char *new_ptr = (char *) realloc(*lineptr, new_size);
//             if (new_ptr == NULL) {
//                 return -1;
//             }
//             *lineptr = new_ptr;
//             *n = new_size;
//         }

//         (*lineptr)[pos++] = (char)c;

//         if (c == '\n') {
//             break;
//         }
//     }

//     if (pos == 0 && c == EOF) {
//         return -1;
//     }

//     (*lineptr)[pos] = '\0';
//     return (ssize_t)pos;
// }

const char *Mstrstr(const char *str1, const char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    if (*str2 == '\0') {
        return str1;
    }

    for (size_t i = 0; str1[i] != '\0'; i++) {
        size_t j = 0;
        while (str2[j] != '\0' && str1[i + j] == str2[j]) {
            j++;
        }
        if (str2[j] == '\0') {
            return (str1 + i);  //char needed
        }
    }

    return NULL;
}

char *Mstrtok(char *str, const char *delim) {
    static char *next = NULL;

    if (str != NULL) {
        next = str;
    }

    if (next == NULL) {
        return NULL;
    }

    char *start = next;
    while (*start && Mstrchr(delim, *start)) {
        start++;
    }

    if (*start == '\0') {
        next = NULL;
        return NULL;
    }

    char *end = start;
    while (*end && !Mstrchr(delim, *end)) {
        end++;
    }

    if (*end != '\0') {
        *end = '\0';
        next = end + 1;
    } else {
        next = NULL;
    }

    return start;
}
