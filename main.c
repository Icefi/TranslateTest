#include <stdio.h>
#include <string.h>
#include "base.h"

int main() {
  compData* base = set_compData(10, 'r');
  for (int i = 0; i < 10; i++) {
    printf("%d) %s - %s\n", i + 1, get_word(base, i, 1), get_word(base, i, 0));
  }
  
  return 0;
}
