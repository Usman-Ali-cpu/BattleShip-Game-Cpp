public class Node {
    int key;
        Student stData; 
        Node left, right; 
   
        public Node(Student data){ 
            key = data.studentID;
            this.stData = data;
            left = right = null; 
        }  
}
