#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {

  FILE *file = fopen("words.csv", "r");

  char string[50] = {};
  char *istr;
  char sep[10] = ",";
  char word_en[20], word_ru[20], word_user[20];
  char count = 0;

  for (int i = 0; i < 10; i++) {

    fscanf(file, "%49s", string);
    istr = strtok(string, sep);
    strcpy(word_en, istr);
    istr = strtok(NULL, sep);
    strcpy(word_ru, istr);

    printf("%d) %s\n", i + 1, word_ru);
    fgets(word_user, 19, stdin);
    fflush(stdin);

    int flag = 1;
    for (int j = 0; word_en[j] != '\0'; j++) {
      if (word_user[j] != word_en[j]) {
		if(word_user[j] - ('A' - 'a') != word_en[j]){
          flag = 0;
          break;
        }
      }
    }
    if (flag) {
      printf("Correct!\n");
      count++;
    } else {
      printf("Wrong!\n%s - %s\n", word_ru, word_en);
    }
  }

  if (count >= 9)
    printf("Excellent! %d/10\n", count);
  else if (count >= 7)
    printf("Good! %d/10\n", count);
  else if (count >= 5)
    printf("Not bad. %d/10\n", count);
  else
    printf("Try again. %d/10\n", count); 

  fclose(file);
  return 0;
}
