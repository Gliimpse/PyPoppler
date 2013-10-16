// appending to string
#include <iostream>
#include <string>
#include <sstream>

#include <stdio.h>
#include <string.h>

int main ()
{
  std::string str1="Sample string";
  char str2[500];
  char str3[500];
  strcpy (str2,str1.c_str());
  strcpy (str3,"copy successful");
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1.c_str(),str2,str3);
  return 0;
}

