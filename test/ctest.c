#include "base.h"
#include "ctest.h"

compData data;

CTEST(setCompData1, compData1) {

  setCompData(1, &data, "words5.csv");
  int numLines = getFileLines("words5.csv");

  ASSERT_EQUAL(1, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(5, numLines);
}

CTEST(setCompData1, compData2) {

  setCompData(2, &data, "words5.csv");
  int numLines = getFileLines("words5.csv");

  ASSERT_EQUAL(2, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(5, numLines);
}

CTEST(setCompData1, compData3) {

  setCompData(3, &data, "words5.csv");
  int numLines = getFileLines("words5.csv");

  ASSERT_EQUAL(3, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(5, numLines);
}

CTEST(setCompData1, compData4) {

  setCompData(4, &data, "words5.csv");
  int numLines = getFileLines("words5.csv");

  ASSERT_EQUAL(4, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(5, numLines);
}

CTEST(setCompData1, compData5) {

  setCompData(5, &data, "words5.csv");
  int numLines = getFileLines("words5.csv");

  ASSERT_EQUAL(5, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(5, numLines);
}

CTEST(setCompData2, compData6) {

  setCompData(2, &data, "words10.csv");
  int numLines = getFileLines("words10.csv");

  ASSERT_EQUAL(2, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(10, numLines);
}

CTEST(setCompData2, compData7) {

  setCompData(4, &data, "words10.csv");
  int numLines = getFileLines("words10.csv");

  ASSERT_EQUAL(4, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(10, numLines);
}

CTEST(setCompData2, compData8) {

  setCompData(6, &data, "words10.csv");
  int numLines = getFileLines("words10.csv");

  ASSERT_EQUAL(6, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(10, numLines);
}

CTEST(setCompData2, compData9) {

  setCompData(8, &data, "words10.csv");
  int numLines = getFileLines("words10.csv");

  ASSERT_EQUAL(8, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(10, numLines);
}

CTEST(setCompData2, compData10) {

  setCompData(10, &data, "words10.csv");
  int numLines = getFileLines("words10.csv");

  ASSERT_EQUAL(10, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(10, numLines);
}

CTEST(setCompData3, compData11) {

  setCompData(10, &data, "words.csv");
  int numLines = getFileLines("words.csv");

  ASSERT_EQUAL(10, data.countWords);
  ASSERT_EQUAL(0, data.currentKey);
  ASSERT_EQUAL(3369, numLines);
}
