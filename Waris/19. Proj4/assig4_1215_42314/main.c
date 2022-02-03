/* Student Name: _____________________
 * Student Number: ___________________
 */

#include "studenttree.c"
#include "string.h"

int main(int argc, char **argv)
{
  argv[1] = "students.txt";
  FILE *in = fopen(argv[1], "r");
  char name[25];
  char num[25];
  char names[30][25];
  char nums[30][25];

  Student *array_of_students[CLASS_SIZE];
  Student *tree = NULL;

  /* read file contents into an array Student* */
  int i = 0;
  while (fscanf(in, "%s %s", &names[i], &nums[i]) == 2)
  {
    i++;
  }
  for (i = 0; i < 30; i++)
  {
    array_of_students[i] = make_node(names[i], nums[i]);
  }

  printf("\nOriginal unsorted array\n");
  print_array(array_of_students, CLASS_SIZE);

  printf("\nSorted array:\n");
  sort_array(array_of_students, CLASS_SIZE);
  print_array(array_of_students, CLASS_SIZE);

  tree = make_tree(tree, array_of_students, 0, CLASS_SIZE - 1);
  // // /* traverse the tree and print it */

  printf("\nIn Order traversal:\n");
  print_inorder(tree);

  // /* Delete the entry for Xudong. */
  printf("\nDeleting Xudong...\n");
  tree = delete_node(tree, "Xudong");
  printf("\ndelte \n");
  print_inorder(tree);
  // /* print the tree */

  // /* Delete the entry for Yanjun. */
  // printf("\nDeleting Yanjun...\n");
  // tree = delete_node(tree, "Yanjun");
  // print_inorder(tree);

  // /* Delete the entry for Kirat. */
  // printf("\nDeleting Kirat...\n");
  // tree = delete_node(tree, "Kirat");
  // print_inorder(tree);

  // /* Delete the entry for Mehakdeep. */
  // printf("\nDeleting Mehakdeep...\n");
  // tree = delete_node(tree, "Mehakdeep");
  // print_inorder(tree);

  // /* Delete the entry for Jacob -- non-existent entry. */
  // printf("\nDeleting Jacob...\n");
  // tree = delete_node(tree, "Jacob");
  // print_inorder(tree);

  return 0;
}

/* 1215_42314 */
