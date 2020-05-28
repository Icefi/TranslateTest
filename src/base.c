#ifndef BASE_C
#define BASE_C

#include "base.h"

int rand_condition(int max_lines, int count_words, int i, int passed)
{
    if ((double)((count_words - i) / (double)(max_lines - passed))
        >= ((double)rand() / (double)RAND_MAX)) {
        return 1;
    }
    return 0;
}

int get_file_lines(char* name)
{
    int number_of_lines = 0;
    int ch;
    FILE* f = fopen(name, "r");

    while (EOF != (ch = getc(f)))
        if ('\n' == ch) {
            ++number_of_lines;
        }
    fclose(f);
    return number_of_lines;
}

void set_compData(int count_words, struct compData* new_base, char* name)
{
    new_base->count_words = count_words;
    new_base->resultString
            = (char*)malloc(count_words * MAX_WORD_SIZE * 8 + 50);
    new_base->aString = (char*)malloc(count_words * MAX_WORD_SIZE * 4 + 50);
    new_base->qString = (char*)malloc(count_words * MAX_WORD_SIZE * 4 + 50);
    new_base->current_key = 0;

    sprintf(new_base->aString, "Ответ\n");
    sprintf(new_base->qString, "Вопрос\n");
    sprintf(new_base->resultString, "Оценка\tВвод\n");

    FILE* file = fopen(name, "r");

    char string[2 * MAX_WORD_SIZE + 2] = {};
    char* istr;

    srand(time(NULL));

    int i = 0;
    int passed = 0;
    int max_lines = get_file_lines(name);
    while ((fgets(string, 2 * MAX_WORD_SIZE + 2, file) != NULL)
           && (i < count_words)) {
        passed++;
        if (rand_condition(max_lines, count_words, i, passed)) {
            istr = strtok(string, ",");
            g_utf8_strncpy(new_base->ruwords[i], istr, MAX_WORD_SIZE);

            istr = strtok(NULL, "\n");
            g_utf8_strncpy(new_base->engwords[i], istr, MAX_WORD_SIZE);

            i++;
        }
    }
}

#endif
