#ifndef BASE_H
#define BASE_H

#include "gui.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

float get_rand_range(const float min, const float max);
void set_compData(int count_words, char lang, struct compData* new_base);
void word_change(struct compData* data);
char* get_word(compData* v, int key, char lang);

#endif
