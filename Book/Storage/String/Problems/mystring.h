#ifndef MYSTRING_H
#define MYSTRING_H
/*
 * Count the number of characters in a string s.
 *
 * Example: my_strlen("foo") should be 3.
 */
int my_strlen(const char * str);

/* ---------------------------------------------------- */
/*
 * Count the number of occurrences of a particular character c in a
 * string s.
 *
 * Example: my_countchar("foo", 'o') should be 2.
 */
int my_countchar(const char * str, char c);

/* ---------------------------------------------------- */
/*
 * Convert a string s to uppercase.  Only alphabetical characters
 * should be converted; numbers and symbols should not be affected.
 * Hint: toupper(c) is a macro that is the uppercase version of a
 * character c.
 *
 * Example: char foobar[10] = "foobar";
 * my_strupper(foobar) is "FOOBAR".
 */
void my_strupper(char * str);

#endif /* MYSTRING_H */
