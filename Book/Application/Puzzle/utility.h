#ifndef UTILITY_H
#define UTILITY_H
// convert representation, two-dimension is easy to visualize
// and debug
// the caller must allocate memory
void twoD2oneD(int size, char * oneD, char * * twoD);
void oneD2twoD(int size, char * oneD, char * * twoD);
char * * allocateTwoD(int size);
void releaseTwoD(int size, char * * twoD);
void printoneD(int size, char * oneD);
void printtwoD(int size, char * * twoD);
char * copyState(int size, const char * srcstate);
#endif
