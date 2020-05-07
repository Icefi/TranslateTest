#ifndef BASE_H
#define BASE_H

#include "base.c"

compData* set_compData(int count_words, char lang);
char* get_word(compData* v, int key, char lang);

#endif
