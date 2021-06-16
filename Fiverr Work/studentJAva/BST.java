import Student;
import Node;

class BST_class { 
    //node class that defines BST node


    // Each Student must have, first name, last name, and email address fields. 

    // BST root node 
    Node root; 
  
   // Constructor for BST =>initial empty tree
    BST_class(){ 
        root = null; 
    } 
    //delete a node from BST
    void deleteKey(int key) { 
        root = delete_Recursive(root, key); 
    } 
   
    //recursive delete function
    Node delete_Recursive(Node root, int key)  { 
        //tree is empty
        if (root == null)  return root; 
   
        //traverse the tree
        if (key < root.key)     //traverse left subtree 
            root.left = delete_Recursive(root.left, key); 
        else if (key > root.key)  //traverse right subtree
            root.right = delete_Recursive(root.right, key); 
        else  { 
            // node contains only one child
            if (root.left == null) 
                return root.right; 
            else if (root.right == null) 
                return root.left; 
   
            // node has two children; 
            //get inorder successor (min value in the right subtree) 
            root.key = minIDValue(root.right); 
   
            // Delete the inorder successor 
            root.right = delete_Recursive(root.right, root.key); 
        } 
        return root; 
    } 

    int minIDValue(Node root)  { 
        //initially minval = root
        int minval = root.key; 
        //find minval
        while (root.left != null)  { 
            minval = root.left.key; 
            root = root.left; 
        } 
        return minval; 
    } 

    // insert a node in BST 
    void insert(int key, Student s)  { 
        root = insert_Recursive(root, key, s); 
    } 

    //recursive insert function
    Node insert_Recursive(Node root, int key, Student s) { 
          //tree is empty
        if (root == null) {
            s.studentID = key; 
            root = new Node(s); 
            return root; 
        } 
        //traverse the tree
        if (key < root.key)     //insert in the left subtree
            root.left = insert_Recursive(root.left, key, s); 
        else if (key > root.key)    //insert in the right subtree
            root.right = insert_Recursive(root.right, key, s); 
          // return pointer
        return root; 
    } 
 
// method for inorder traversal of BST 
    void inorder() { 
        inorder_Recursive(root); 
    } 

    // recursively traverse the BST  
    void inorder_Recursive(Node root) {
        if (root != null) {
            inorder_Recursive(root.left);
            root.stData.printStudent();

            inorder_Recursive(root.right);
        }
    }
    void postorder() { 
        postorder_Recursive(root); 
    } 

    void postorder_Recursive(Node root) {
        if (root != null) {
            postorder_Recursive(root.left);
            postorder_Recursive(root.right);
            root.stData.printStudent();
        }
    }
    void preorder() { 
        preorder_Recursive(root); 
    } 
    void preorder_Recursive(Node root) {
        if (root != null) {
            root.stData.printStudent();
            preorder_Recursive(root.left);
            preorder_Recursive(root.right);
        }
    }

     
    Student find(int key)  { 
        root = search_Recursive(root, key);
        root.stData.printStudent();
        if (root!= null)
            return root.stData;
        else
            return null;
    } 
   
    //recursive insert function
    Node search_Recursive(Node root, int key)  { 
        // Base Cases: root is null or key is present at root 
        if (root==null || root.key==key) 
            return root; 
        // val is greater than root's key 
        if (root.key > key) 
            return search_Recursive(root.left, key); 
        // val is less than root's key 
        return search_Recursive(root.right, key); 
    } 
}
class Main{
    public static void main(String[] args)  { 
       //create a BST object
       BST_class bst = new BST_class();
        
        
       Student st1 = new Student();
       Student st2 = new Student();
       Student st3 = new Student();
       Student st4 = new Student();
       Student st5 = new Student();

        /* BST tree example
              45 
           /     \ 
          10      90 
         /  \    /   
        7   12  50   */
        //insert data into BST
        bst.insert(13, st1); 
        bst.insert(5, st2); 
        bst.insert(3, st3); 
        bst.insert(9, st4); 
        bst.insert(2, st5); 
        //print the BST
        System.out.println("The BST Created with input data(Left-root-right):");
        System.out.println("*********** Inorder ! ************"); 
        bst.inorder();
        System.out.println("*********** pre order! ************");
        bst.preorder();
        System.out.println("*********** post order! *************");
        bst.postorder();
        
        //delete leaf node  
        // System.out.println("\nThe BST after Delete 12(leaf node):"); 
        // bst.deleteKey(12); 
        // bst.inorder(); 
        // //delete the node with one child
        // System.out.println("\nThe BST after Delete 90 (node with 1 child):"); 
        // bst.deleteKey(90); 
        // bst.inorder(); 
                 
        // //delete node with two children  
        // System.out.println("\nThe BST after Delete 45 (Node with two children):"); 
        // bst.deleteKey(45); 
        // bst.inorder(); 
        // //search a key in the BST
        try {
            Student retval = bst.find(6);
            retval.printStudent();
        } 
        catch (NullPointerException e) {
            //TODO: handle exception
            // System.out.println(e.getMessage());
            System.out.println("You don't have Student with this ID ! ");
        }
       
        // if (retval == null) {
        //     System.out.println("You don't have Student with this ID ! ");
        // } 
        // else {
        //     retval.printStudent();
        // }
        // System.out.println("\nKey 50 found in BST:" + ret_val );
        // ret_val = bst.search (12);
        // System.out.println("\nKey 12 found in BST:" + ret_val );
     } 
}

// This is the project: 
// Implement a Binary Tree that has an id of type of integer and a data field of type of Student. 
// Each Student must have, first name, last name, and email address fields. 
// Student ID must be stored in the Binary Tree id filed, 
// so you don't need to have a field in Student class for ID. 
// Then implement following methods for the Binary Tree:

// find(int key): This method will receive a student id (key) and will return a Student info with the same id. 
// If there was no student found for the given key, this method will return null. 

// insert(int key, Student s): this method will insert a student node with 
// the id equals to the key in a proper place for the id field in the binary tree.