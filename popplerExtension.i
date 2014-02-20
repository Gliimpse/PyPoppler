/* File: popplerExtension.i */
%module popplerExtension
#define SWIG_FILE_WITH_INIT
%{

%}

%{
#include "poppler.h"
%}

%include <typemaps.i>
%include <std_string.i>
%include "poppler.h";

FILE *fopen(char *, char *);
void fclose(FILE *f);
