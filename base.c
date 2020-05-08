#ifndef BASE_C
#define BASE_c

#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int count_words;
    int current_key;
    char* engwords;
    char* ruwords;
    //GtkWidget *entry;
    //GtkWidget *pages;
    //GtkWidget *labelWord;
    //GtkWidget *counterSetter;
    char* result;
    char mode;
}compData;

float get_rand_range(const float min, const float max) {
    return rand()%100 * (max - min) + min;
}

compData* set_compData(int count_words, char lang) {
  compData* new_base;
  
  new_base = (compData*)malloc(20);
  new_base->count_words = count_words;
  new_base->engwords = (char*)calloc(count_words, 20 * sizeof(char));
  new_base->ruwords = (char*)calloc(count_words, 20 * sizeof(char));
  new_base->result = (char*)malloc(count_words * sizeof(char));
  new_base->current_key = 0;
  new_base->mode = lang;
  
  FILE* file = fopen("words.csv", "r");

  char string[50] = {};
  char sub_word[20] = {};
  char *istr;
  float x;
  int size_of_base = 100; //count of words in words.csv
  srand(time(NULL));
  int i = 0;
  while (count_words > 0) {
    x = (float)count_words/size_of_base + get_rand_range(0, 1)/100;
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

char* get_word(compData* v, int key, char lang) {
  
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
