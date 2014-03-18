#ifndef FREQ_H
#define FREQ_H
typedef struct
{
  char value;
  int freq;
} CharFreq;
// count the frequencies of the letters
// frequency is an array of NUMLETTER elements
// NUMLETTER is a constant defined in constant.h
// return 0 if cannot read from file
// return the number of characters in the file
int countFrequency(char * filename, CharFreq * frequencies);
void printFrequency(CharFreq * frequencies);
void sortFrequency(CharFreq * frequencies);
#endif
