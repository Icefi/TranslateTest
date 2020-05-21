#ifndef BASE_C
#define BASE_C

#include "base.h"

float get_rand_range(const float min, const float max) {
  return rand() % 100 * (max - min) + min;
}

void set_compData(int count_words, struct compData *new_base) {

  new_base->count_words = count_words;
  new_base->engwords = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
  new_base->ruwords = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
  new_base->result = (char *)malloc((count_words + 1) * sizeof(char));
  new_base->current_key = 0;

  FILE *file = fopen("words.csv", "r");

  char string[2 * MAX_WORD_SIZE + 2] = {};
  char *istr;
  float x;
  int size_of_base = 100;

  int i = 0;
  srand(time(NULL));
  while (count_words > 0) {
    x = (float)count_words / size_of_base + get_rand_range(0, 1) / 100;
    fscanf(file, "%49s", string);

    if (x >= 1) {
      i++;
      count_words--;
      size_of_base--;
    } else {
      size_of_base--;
      continue;
    }

    istr = strtok(string, ",");
    strcpy(new_base->ruwords, istr);

    istr = strtok(NULL, ",");
    strcpy(new_base->engwords, istr);

  }
  fclose(file);
  return;
}

void word_change(struct compData *data) {
  FILE *file = fopen("words.csv", "r");
	srand(time(NULL));

  char string[2 * MAX_WORD_SIZE + 2] = {};
  char *istr;
  
  int size_of_base = 100;
  int i = 0;

  int count_words = data->count_words;
	float x;
  while (count_words > 0) {
    x = (float)count_words / size_of_base + get_rand_range(0, 1) / 100;
    fscanf(file, "%49s", string);

    if (x >= 1) {
      i++;
      count_words--;
      size_of_base--;
    } else {
      size_of_base--;
      continue;
    }

    istr = strtok(string, ",");
    strcpy(data->ruwords, istr);

    istr = strtok(NULL, ",");
    strcpy(data->engwords, istr);
  }

  fclose(file);
  return;
}

char *get_word(struct compData *v, int key, char lang) {

  char *word = (char *)malloc(MAX_WORD_SIZE * sizeof(char));

  key = (key + 1) % v->count_words;

  if (lang == 'e') {

    for (int i = 0; i < MAX_WORD_SIZE; i++)
      *(word + i) = *(v->engwords + key * MAX_WORD_SIZE + i);

  } else {

    for (int i = 0; i < MAX_WORD_SIZE; i++)
      *(word + i) = *(v->ruwords + key * MAX_WORD_SIZE + i);
	}

  return word;
}

#endif
