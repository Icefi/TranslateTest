#ifndef BASE_C
#define BASE_C

#include "base.h"

int randCondition(int maxLines, int countWords, int i, int passed) {
  if ((double)((countWords - i) / (double)(maxLines - passed)) >=
      ((double)rand() / (double)RAND_MAX)) {
    return 1;
  }
  return 0;
}

int getFileLines(char *name) {
  int numberLines = 0;
  int ch;
  FILE *f = fopen(name, "r");

  while (EOF != (ch = getc(f)))
    if ('\n' == ch) {
      ++numberLines;
    }
  fclose(f);
  return numberLines;
}

void setCompData(int countWords, struct compData *newBase, char *name) {
  newBase->countWords = countWords;
  newBase->resultString = (char *)malloc(countWords * MAX_WORD_SIZE * 8 + 50);
  newBase->aString = (char *)malloc(countWords * MAX_WORD_SIZE * 4 + 50);
  newBase->qString = (char *)malloc(countWords * MAX_WORD_SIZE * 4 + 50);
  newBase->currentKey = 0;

  sprintf(newBase->aString, "Ответ\n");
  sprintf(newBase->qString, "Вопрос\n");
  sprintf(newBase->resultString, "Оценка\tВвод\n");

  FILE *file = fopen(name, "r");

  char string[2 * MAX_WORD_SIZE + 2] = {};
  char *istr;

  srand(time(NULL));

  int i = 0;
  int passed = 0;
  int maxLines = getFileLines(name);
  while ((fgets(string, 2 * MAX_WORD_SIZE + 2, file) != NULL) &&
         (i < countWords)) {
    passed++;
    if (randCondition(maxLines, countWords, i, passed)) {
      istr = strtok(string, ",");
      g_utf8_strncpy(newBase->ruwords[i], istr, MAX_WORD_SIZE);

      istr = strtok(NULL, "\n");
      g_utf8_strncpy(newBase->engwords[i], istr, MAX_WORD_SIZE);

      i++;
    }
  }
}

#endif
