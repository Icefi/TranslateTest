#include "ctest.h"
#include "base.h"

compData data;

CTEST(set_compData1, compData1) {
    
    set_compData(1, &data, "words5.csv");
    int num_lines = get_file_lines("words5.csv");
    
    ASSERT_EQUAL(1, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(5, num_lines);

}

CTEST(set_compData1, compData2) {
    
    set_compData(2, &data, "words5.csv");
    int num_lines = get_file_lines("words5.csv");
    
    ASSERT_EQUAL(2, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(5, num_lines);
}

CTEST(set_compData1, compData3) {
    
    set_compData(3, &data, "words5.csv");
    int num_lines = get_file_lines("words5.csv");
    
    ASSERT_EQUAL(3, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(5, num_lines);
}

CTEST(set_compData1, compData4) {
    
    set_compData(4, &data, "words5.csv");
    int num_lines = get_file_lines("words5.csv");
    
    ASSERT_EQUAL(4, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(5, num_lines);
}

CTEST(set_compData1, compData5) {
    
    set_compData(5, &data, "words5.csv");
    int num_lines = get_file_lines("words5.csv");
    
    ASSERT_EQUAL(5, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(5, num_lines);
}

CTEST(set_compData2, compData6) {
    
    set_compData(2, &data, "words10.csv");
    int num_lines = get_file_lines("words10.csv");
    
    ASSERT_EQUAL(2, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(10, num_lines);
}

CTEST(set_compData2, compData7) {
    
    set_compData(4, &data, "words10.csv");
    int num_lines = get_file_lines("words10.csv");
    
    ASSERT_EQUAL(4, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(10, num_lines);
}

CTEST(set_compData2, compData8) {
    
    set_compData(6, &data, "words10.csv");
    int num_lines = get_file_lines("words10.csv");
    
    ASSERT_EQUAL(6, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(10, num_lines);
}

CTEST(set_compData2, compData9) {
    
    set_compData(8, &data, "words10.csv");
    int num_lines = get_file_lines("words10.csv");
    
    ASSERT_EQUAL(8, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(10, num_lines);
}

CTEST(set_compData2, compData10) {
    
    set_compData(10, &data, "words10.csv");
    int num_lines = get_file_lines("words10.csv");
    
    ASSERT_EQUAL(10, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(10, num_lines);
}

CTEST(set_compData3, compData11) {
    
    set_compData(10, &data, "words.csv");
    int num_lines = get_file_lines("words.csv");
    
    ASSERT_EQUAL(10, data.count_words);
    ASSERT_EQUAL(0, data.current_key);
    ASSERT_EQUAL(3369, num_lines);
}
