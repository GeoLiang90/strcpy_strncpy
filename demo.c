/***

strcpy() copies entire content of one string into another string. If the destination has less chars than
the source it copies the string without the NULL terminator. Destination needs to be large enough or there
will be weird side effects

strncpy() is similar to strcpy except this time, n bytes of the source string will be copied. If there is
no NULL amongst the first n chars of the string, strncpy() will add in the NULL. It will basically cut off
a part of the source string to be copied to a destination to ensure that there is no issue with not enough
space allocated.

strcpy(char *dest, const char *src)
Pointer Destination
Pointer to string that will be copied
***Returns a pointer to destination

strncpy(char *dest, const char *src, size_t n)
Pointer destination
Pointer to string that will be copied
n is size
***Returns a pointer to destination
IMPORTANT: The programmer should properly specify n
***/
#include <string.h>
#include <stdio.h>
int main(){
  char s[4];
  char d[50];
  char srce[] = "pizza";
  strcpy(d,srce);
  printf("Copying the string srce that contains : %s \n", srce);
  printf("String strcpy into properly fitting container : %s \n", d);
  printf("srce after copying : %s \n", srce);
  printf("The copied String's length is recorded as : %ld \n \n", strlen(d));
  strcpy(s,srce);
  printf("String strcpy into improperly fitting container : %s \n", s);
  printf("srce after copying : %s \n", srce);
  printf("The copied String's length is recorded as : %ld \n \n", strlen(s));
  printf("Our original string lost the 4 bytes that was allocated to the improper container and got chopped up in the front \n \n");

  char a[2];
  char b[20];
  char c[6];
  char nsrc[] = "pizza";
  printf("Going under the allocated bytes results in this effect \n");
  strncpy(b,nsrc,3);
  printf("Copying the string nsrc that contains : %s \n", nsrc);
  printf("String strncpy into 20 byte container limited by 2 as n: %s \n", b);
  printf("srce after copying : %s \n", nsrc);
  printf("The copied String's length is recorded as : %ld \n \n", strlen(b));

  printf("Exceeding allocated bytes results in this effect \n");
  strncpy(a,nsrc,5);
  printf("Copying the string nsrc that contains : %s \n", nsrc);
  printf("String strncpy into 2 byte container limited by 5 as n: %s \n", a);
  printf("srce after copying : %s \n", nsrc);
  printf("The copied String's length is recorded as : %ld \n \n", strlen(a));

  printf("Getting just the right amount of bytes including the NULL results in this \n");
  strncpy(c,nsrc,6);
  printf("Copying the string nsrc that contains : %s \n", nsrc);
  printf("String strncpy into 6 byte container limited by 6 as n: %s \n", c);
  printf("srce after copying : %s \n", nsrc);
  printf("The copied String's length is recorded as : %ld \n \n", strlen(c));




}
