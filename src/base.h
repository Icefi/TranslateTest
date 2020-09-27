#ifndef BASE_H
#define BASE_H

#include "gui.h"

#include <stdlib.h>
#include <time.h>

void setCompData(int countWords, struct compData* newBase, char* name);
int getFileLines(char* name);
int randCondition(int maxLines, int countWords, int i, int passed);

#endif
