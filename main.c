#include <stdio.h>
#include <string.h>
#include "base.h"

int main() {
  DATA* base = set_data(10);
  for (int i = 0; i < 10; i++) {
    printf("1) %s - %s\n", get_word(base, i, 1), get_word(base, i, 0));
  }
  
  return 0;
}
