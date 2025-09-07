#include "StrokeFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define d 256
#define q 10000000007

int Mputs(const char *str) {
    assert(str != NULL);

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

size_t Mstrlen(const char *str) {
    assert(str != NULL);

    size_t i = 0;
    while (str[i] != '\0') {
        i++;
    }

    return i;
}

char *Mstrcpy(char *str1, const char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    char *cur = str1;

    while ((*str2) != '\0') {
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

char *Mstrcat(char *str1, const char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    char *start = str1;
    while ((*str1) != '\0') {
        str1++;
    }

    while ((*str2) != '\0') {
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

    char *start = dest;

    while ((*dest) != '\0') {
        dest++;
    }

    while (num > 0 && (*src) != '\0') {
        num--;

        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return start;
}


char *Mfgets(char *str, int num, FILE *file) {
    assert(str  != NULL);
    assert(file != NULL);
    if (file == NULL) {
        return NULL;
    }

    int c = 0;
    char *start = str;
    int i = 0;

    while (i < num - 1 && (c = getc(file)) != EOF) {
        *str = (char)c;
        str++;
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


char *Mstrdup(char *str) {
    assert(str != NULL);

    char *buff = (char *) malloc ((Mstrlen(str) + 1) * sizeof(char));
    if (buff == NULL) {
        return NULL;
    }
    Mstrcpy(buff, str);

    return buff;
}

ssize_t Mgetline(char **lineptr, size_t *num, FILE *file) {
    assert(lineptr != NULL);
    assert(num     != NULL);
    assert(file    != NULL);
    if (file == NULL) {
        return NULL;
    }

    if (*num == 0){
        *num = 128;
    }

    *lineptr = (char *) calloc((*num + 1), sizeof(char));
    if (*lineptr == NULL) {
        return -1;
    }

    ssize_t pos = 0;
    int c = 0;

    while ((c = fgetc(file)) != EOF) {
        if (pos + 1 >= (ssize_t)*num) {
            size_t new_size = *num * 2;
            
            char *new_ptr = (char *) realloc(*lineptr, new_size);
            if (new_ptr == NULL) {
                return -1;
            }

            *lineptr = new_ptr;
            *num = new_size;
        }

        (*lineptr)[pos++] = (char)c;
    }

    (*lineptr)[pos] = '\0'; //'\n' ??

    return pos;
}

long Matoi(const char *str) {
    assert(str != NULL);

    int minus = 1;
    long num = 0;
    int i = (int)Mstrlen(str) - 1;
    long long powi = 1;

    while (i >= 0) {
        if (str[i] == '-') {
            minus = -1;

        } else {
            if (str[i] == ' ') {
                break;

            } else {
                num += ((str[i] - '0') * powi);
                powi *= 10;
            }
        }
        i--;
    }

    return minus * num;

}

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
    assert(delim != NULL);

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

const char *Mstrstr5(const char *str, const char *compare) {
    assert(str     != NULL);
    assert(compare != NULL);

    size_t n = Mstrlen(str);
    size_t m = Mstrlen(compare);

    if (m == 0) {
        return str;
    }

    size_t freq[256] = {m};
    for (int i = 1; i < 256; i++) {
       freq[i] = m;
    }

    for (size_t i = 0; i < m - 1; i++) {
        freq[(unsigned char)compare[i]] = m - i - 1;
    }

    size_t pos = m - 1;
    while (pos < n) {

        if (str[pos] == compare[m - 1]) {
            size_t cnt = 1;

            while (cnt < m && str[pos - cnt] == compare[m - 1 - cnt]) {
                cnt++;
            }

            if (cnt == m) {
                return str + pos - m + 1;
            }

            pos += freq[(unsigned char)str[pos - cnt]];

        } else {

            pos += freq[(unsigned char)str[pos]];
        }
    }

    return NULL;
}

size_t rabin_karp(const char *text, const char *pattern) {
    assert(text    != NULL);
    assert(pattern != NULL);

    size_t M = Mstrlen(pattern);
    size_t N = Mstrlen(text);
    size_t i = 0;
    int p = 0, t = 0, h = 1;

    for (i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (Mstrncmp(text + i, pattern, M) == 0){
            return i;
        }

        t = (d * (t - text[i] * h) + text[i + M]) % q;
        if (t < 0) {
            t += q;
        }
    }

    return NULL;
}

int Mstrcmp(const char *str1, const char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    size_t n = Mstrlen(str1);
    size_t m = Mstrlen(str2);

    if (n < m) {
        return -1;
    }
    
    if (m > n) {
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return ((str1[i] > str2[i]) ? (1) : (-1));
        }
    }

    return 0;
}

int Mstrncmp(const char *str1, const char *str2, size_t num) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    size_t n = Mstrlen(str1);
    size_t m = Mstrlen(str2);

    if (n < num || m < num) {
        if (n > m) {
            return 1;
        }
    }

    for (size_t i = 0; (i < num && i < n); i++) {
        if (str1[i] != str2[i]) {
            return ((str1[i] > str2[i]) ? (1) : (-1));
        }
    }

    return 0;
}