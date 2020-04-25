#ifndef BASE_C
#define BASE_c

#include <stdlib.h>
#include <string.h>

typedef struct{
  int count_words;
  int current_key;
  char* engwords;
  char* ruwords;
  char* entry;
  char* result;
}DATA;

DATA* set_data(int count_words) {
  DATA* new_base;
  
  new_base = (DATA*)malloc(20);
  new_base->count_words = count_words;
  new_base->engwords = (char*)calloc(count_words, 20 * sizeof(char));
  new_base->ruwords = (char*)calloc(count_words, 20 * sizeof(char));
  new_base->entry = (char*)malloc(20 * sizeof(char));
  new_base->result = (char*)malloc(count_words * sizeof(char));
  new_base->current_key = 0;
  
  
  FILE* file = fopen("words.csv", "r");

  char string[50] = {};
  char sub_word[20] = {};
  char *istr;

  for (int i = 1; i < 11; i++) {

    fscanf(file, "%49s", string);

    istr = strtok(string, ",");
    strcpy(sub_word, istr);

    istr = strtok(NULL, ",");
    for (int j = 0; j < 20; j++) {
    	*(new_base->engwords + i*20 + j) = sub_word[j];
    }

    strcpy(sub_word, istr);
    for (int j = 0; j < 20; j++) {
    	*(new_base->ruwords + i*20 + j) = sub_word[j];
    }
  
  }
  
  return new_base;
}

char* get_word(DATA* v, int key, char lang) {
  
  char* word = (char*)malloc(20 * sizeof(char));
  key++;
  if (key > v->count_words)
  	key = key % v->count_words;
  
  if (lang)
    for (int i = 0; i < 20; i++) {
    	*(word + i) = *(v->engwords + key*20 + i);
    }
  else
    for (int i = 0; i < 20; i++) {
    	*(word + i) = *(v->ruwords + key*20 + i);
    }
  return word;
}

#endif
