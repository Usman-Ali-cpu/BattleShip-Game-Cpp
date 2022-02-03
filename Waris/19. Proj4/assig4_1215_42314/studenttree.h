/* Student Name: _____________________
 * Student Number: ___________________
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLASS_SIZE 30

typedef struct student
{
  char *name;            /* student name */
  char *number;          /* student number */
  struct student *left;  /* pointer to left subtree */
  struct student *right; /* pointer to right subtree */
} Student;

Student *make_node(char *, char *);

void print_array(Student **, int);

void print_inorder(Student *);

void sort_array(Student **, int);

Student *make_tree(Student *, Student **, int, int);

Student *delete_node(Student *, char *);

/* 1215_42314 */
