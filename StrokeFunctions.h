#ifndef STROKE_START_H_
#define stroke_start_h_

#include <stdio.h>

//---------------------------------------
//! Prints stroke to standart output.
//!
//! @param [in] str Pointer to the stroke
//!
//! @return 1 / EOF
//---------------------------------------
int Mputs(const char *str);

//------------------------------------------------------
//! Checks whether "str" consists of at least 1 "c".
//!
//! @param [in] str Pointer to the stroke
//! @param [in] c number of char symbol
//!
//! @return pointer to the position of "c" symbol / NULL
//!-----------------------------------------------------
const char *Mstrchr(const char *str, int c);

//---------------------------------------
//! Finds the size of stroke.
//!
//! @param [in] str Pointer to the stroke
//!
//! @return size of stroke
//---------------------------------------
size_t Mstrlen(const char *str);

//-----------------------------------------------
//! Copies str2 to the beginning of str1.
//!
//! @param [in] str1 Pointer to the first stroke
//! @param [in] str2 Pointer to the second stroke
//!
//! @return pointer to the str1
//-----------------------------------------------
char *Mstrcpy(char *str1, const char *str2);

//--------------------------------------------------------------------------------
//! Copies elements of "str2" to the beginning of "str1" no more than "num" times.
//!
//! @param [in] str1 Pointer to the first stroke
//! @param [in] str2 Pointer to the second stroke
//! @param [in] num Amount of copies
//!
//! @return pointer to the str1
//--------------------------------------------------------------------------------
char *Mstrncpy(char *str1, const char *str2, size_t num);

//-----------------------------------------------
//! Copies str2 to the end of str1.
//!
//! @param [in] str1 Pointer to the first stroke
//! @param [in] str2 Pointer to the second stroke
//!
//! @return pointer to the str1
//-----------------------------------------------
char *Mstrcat(char *str1, const char *str2);

//--------------------------------------------------------------------------
//! Copies elements of "str2" to the end of "str1" no more than "num" times.
//!
//! @param [in] str1 Pointer to the first stroke
//! @param [in] str2 Pointer to the second stroke
//! @param [in] num Amount of copies
//!
//! @return pointer to the str1
//--------------------------------------------------------------------------
char *Mstrncat(char *dest, const char *src, size_t num);

//---------------------------------------------------------------------------------------------
//! Reads at most "num-1" characters from the given "file" stream and stores them in the "str".
//!
//! @param [in] str Pointer to the stroke
//! @param [in] num Amount of elements in stroke beeing read
//! @param [in] file file to read from
//!
//! @return pointer to the str
//---------------------------------------------------------------------------------------------
char *Mfgets(char *str, int num, FILE *file);

//-----------------------------------------------------------------------------------
//! Returns a pointer to a null-terminated byte string, to which "str" is dublicated.
//!
//! @param [in] str Pointer to the stroke beeing copied
//!
//! @return pointer to the newly allocated string
//-----------------------------------------------------------------------------------
char *Mstrdup(char *str);

//-----------------------------------------------------------------------------------------------------------------------
//! Reads at most "num-1" characters from the given "file" stream and stores them in the stroke with the pointer lineptr.
//!
//! @param [in] lineptr Pointer to the stroke
//! @param [in] num Amount of elements in stroke beeing read
//! @param [in] file file to read from
//!
//! @return pointer to the str
//-----------------------------------------------------------------------------------------------------------------------
ssize_t Mgetline(char **lineptr, size_t *num, FILE *file);

//------------------------------------
//! Converts char number to int.
//!
//! @param [in] str Pointer to the str
//!
//! @return converted int value
//------------------------------------
long Matoi(const char *str);

//------------------------------------------------------------------
//! Checks whether str1 consists of str2 or not.
//!
//! @param [in] str1 Stroke beeing checked to have another one in it
//! @param [in] str2 Stroke which has to be found in another one
//!
//! @return pointer to the position of "str2" start in "str1"
//------------------------------------------------------------------
const char *Mstrstr(const char *str1, const char *str2);

//-----------------------------------------------------------------
// Parses str to the partes which symbols from delim.
//!
//! @param [in] str Pointer to the stroke
//! @param [in] delim Pointer to the stroke of "separating" symbols
//!
//! @return position of start of new stroke in str
//-----------------------------------------------------------------
char *Mstrtok(char *str, const char *delim);

//-------------------------------------------------------------------------------
//! Checks whether str1 consists of str2 or not (but maybe faster, than Mstrstr).
//!
//! @param [in] str1 Stroke beeing checked to have another one in it
//! @param [in] str2 Stroke which has to be found in another one
//!
//! @return pointer to the position of "str2" start in "str1"
//-------------------------------------------------------------------------------
const char *Mstrstr5(const char *str, const char *compare);

//-------------------------------------------------------------------------------
//! Checks whether str1 consists of str2 or not (but maybe faster, than Mstrstr).
//!
//! @param [in] str1 Stroke beeing checked to have another one in it
//! @param [in] str2 Stroke which has to be found in another one
//!
//! @return pointer to the position of "str2" start in "str1"
//-------------------------------------------------------------------------------
size_t rabin_karp(const char *text, const char *pattern);

//-------------------------------------------------------
//! Checks whether "str1" and "str2" are the same or not.
//!
//! @param [in] str1 Pointer to the stroke1
//! @param [in] str2 Pointer to the stroke2
//!
//! @return -1 / 0 / 1
//-------------------------------------------------------
int Mstrcmp(const char *str1, const char *str2);

//--------------------------------------------------------------------------
//! Checks whether "num" positions of "str1" and "str2" are the same or not.
//!
//! @param [in] str1 Pointer to the stroke1
//! @param [in] str2 Pointer to the stroke2
//!
//! @return -1 / 0 / 1
//--------------------------------------------------------------------------
int Mstrncmp(const char *str1, const char *str2, size_t num);

#endif // STROKE_START_H_