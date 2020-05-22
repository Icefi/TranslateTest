#ifndef BASE_C
#define BASE_C

#include "base.h"

int rand_condition(int max_lines, int count_words, int i){
  //a proper function
  return 1;
}

int get_file_lines(){
  int number_of_lines = 0;
  FILE *f = fopen("words.csv", "r");
  int ch;

  while (EOF != (ch=getc(f)))
      if ('\n' == ch){
          ++number_of_lines;
      }
  fclose(f);
  return number_of_lines;
}

void set_compData(int count_words, struct compData *new_base) {

  new_base->count_words = count_words;
  new_base->result = (char *)malloc((count_words + 1) * sizeof(char));
  new_base->current_key = 0;

  FILE *file = fopen("words.csv", "r");

  char string[2 * MAX_WORD_SIZE + 2] = {};
  char *istr;

  srand(time(NULL));

  int i = 0;
  int max_lines = get_file_lines();
  while ((fgets(string, 2 * MAX_WORD_SIZE + 2, file) != NULL) && (i<count_words))
  {
    if (rand_condition(max_lines,count_words,i)) {    //some function
    istr = strtok(string, ",");
    strcpy(new_base->ruwords[i], istr);

    istr = strtok(NULL, ",");
    strcpy(new_base->engwords[i], istr);
    
    i++;
    }
  }
}

#endif
