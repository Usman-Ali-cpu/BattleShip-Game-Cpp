/* Student Name: _____________________
 * Student Number: ___________________
 */

#include "studenttree.h"
#include <string.h>

Student *make_node(char *name, char *number)
{
  Student *new_student = (Student *)malloc(sizeof(Student));

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
    printf("%s %s\n", array_of_students[i]->name, array_of_students[i]->number);
  }
}

/* Given a binary tree, print its nodes in inorder*/
void print_inorder(Student *node)
{
  if (node != NULL) // checking if the root is not null
  {
    print_inorder(node->left);                    // visiting left child
    printf("%s %s\n ", node->name, node->number); // printing data at root
    print_inorder(node->right);                   // visiting right child
  }
}

/* sort the array -- using selection_sort */
void sort_array(Student **array_of_students, int size)
{
  char *tname;
  char *tnum;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (strcmp(array_of_students[j]->name, array_of_students[j + 1]->name) > 0)
      {
        //swap array[j] and array[j+1]
        tname = array_of_students[j]->name;
        tnum = array_of_students[j]->number;

        array_of_students[j]->name = array_of_students[j + 1]->name;
        array_of_students[j]->number = array_of_students[j + 1]->number;

        array_of_students[j + 1]->name = tname;
        array_of_students[j + 1]->number = tnum;
      }
    }
  }
}

Student *make_tree(Student *tree, Student *array_of_students[], int left, int right)
{
  if (left > right)
    return NULL;
  int mid = (left + right) / 2;
  tree = (Student *)malloc(30 * sizeof(Student));
  tree->name = array_of_students[left]->name;
  tree->number = array_of_students[left]->number;

  tree->left = make_tree(tree, array_of_students, left, mid - 1);
  tree->right = make_tree(tree, array_of_students, mid + 1, right);

  return tree;
}

int getArray(Student *tree, Student *array_of_students[])
{
  static int i = 0;
  if (tree != NULL) // checking if the root is not null
  {
    getArray(tree->left, array_of_students);      // visiting left child
    printf("%s %s\n ", tree->name, tree->number); // printing data at root
    printf("i = %d\n ", i);
    array_of_students[i]->name = tree->name;
    array_of_students[i]->number = tree->number;
    i++;

    getArray(tree->right, array_of_students); // visiting right child
  }
  int j = i;
  // i = 0;
  return j;
}

Student *delete_node(Student *root, char *name)
{
  Student *st = root;
  Student *tree = root;
  Student *arrStudents[CLASS_SIZE];
  for (int k = 0; k < 30; k++)
  {
    arrStudents[k] = make_node("names", "nums");
  }

  int i = getArray(tree, arrStudents);

  /// ************************************
  for (int j = 0; j < i; j++)
  {
    if (strcmp(arrStudents[j]->name, name))
    {
      st = arrStudents[j];
      char *tname = arrStudents[j]->name;
      char *tnum = arrStudents[j]->number;

      arrStudents[j]->name = arrStudents[i - 1]->name;
      arrStudents[j]->number = arrStudents[i - 1]->number;

      arrStudents[i - 1]->name = tname;
      arrStudents[i - 1]->number = tnum;
    }
  }

  root = make_tree(root, arrStudents, 0, i - 1);
  return root;
}

/* 1215_42314 */
