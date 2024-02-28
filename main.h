#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* 1-StrFun.c */
int _putchar(char c);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* 2-StrFun.c */
int _putchar(char);
void _puts(char *str);
char *_strcpy(char *dest, char *src);

/* 3-StrFun.c */
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
int _putchar(char c);
char *_strchr(char *s, char c);

/* 4-StrFun.c */
char **strtow(char *str);
char *_strdup(char *str);

#endif
