#ifndef STROKE_START_H_
#define stroke_start_h_

#include <stdio.h>

int Mputs(const char *str);
const char *Mstrchr(const char *str, int c);
size_t Mstrlen(const char *str);
char *Mstrcpy(char *str1, const char *str2);
char *Mstrncpy(char *str1, const char *str2, size_t num);
char *Mstrcat(char *str1, const char *str2);
char *Mstrncat(char *dest, const char *src, size_t num);
char *Mfgets(char *str, int num, FILE *file);
char *Mstrdup(char *str);
int Mgetline(FILE *file, char *str, int num);
long Matoi(const char *str);
const char *Mstrstr(const char *str1, const char *str2);
char *Mstrtok(char *str, const char *delim);
const char *Mstrstr5(const char *str, const char *compare);
size_t rabin_karp(const char *text, const char *pattern);
int Mstrcmp(const char *str1, const char *str2);
int Mstrncmp(const char *str1, const char *str2, size_t num);

#endif // STROKE_START_H_