/* Student Name: _____________________
 * Student Number: ___________________
 */

#include "studenttree.h"

Student *make_node(char *name, char *number)
{
  struct student *new_student = (struct Student *)malloc(sizeof(struct student));
  new_student->name = name;
  new_student->number = number;
  new_student->left = NULL;
  new_student->right = NULL;

  return new_student;
}

/* Given an array of pointers, print the data of the referenced nodes */
void print_array(Student *array_of_students[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%s %d\n", array_of_students[i]->name, array_of_students[i]->number);
  }
}

/* Given a binary tree, print its nodes in inorder*/
void print_inorder(Student *node)
{
  if (node == NULL)
    return;

  /* first recur on left child */
  printInorder(node->left);

  /* then print the data of node */
  printf("%s %s ", node->name, node->number);

  /* now recur on right child */
  printInorder(node->right);
}

/* sort the array -- using selection_sort */
void sort_array(Student **array_of_students, int size)
{
}

Student *make_tree(Student *tree, Student *array_of_students[], int left, int right)
{

  return tree;
}

Student *delete_node(Student *root, char *name)
{
  return root;
}

/* 1215_42314 */
