#ifndef BASE_H
#define BASE_H

#include "gui.h"

#include <stdlib.h>
#include <time.h>

void set_compData(int count_words, struct compData* new_base);
int get_file_lines(void);
int rand_condition(int max_lines, int count_words, int i, int passed);

#endif
