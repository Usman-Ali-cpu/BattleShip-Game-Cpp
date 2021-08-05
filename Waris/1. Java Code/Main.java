public class Main{
    public static void main(String[] args) {
        TrafficMinimization t = new TrafficMinimization();
        int ar[];
        ar=getArray(10);
        print(ar,3,t);
        ar=getArray(100);
        print(ar,30,t);
        ar=getArray(100);
        print(ar,30,t);
        ar=getArray(500);
        print(ar,30,t);
    }
        static void print(int array[],int k,TrafficMinimization t){
            long startTime = System.nanoTime();
            int val=t.performServerplacement(array, k);
            long endTime = System.nanoTime();
            long duration = (endTime - startTime);
            System.out.println("number of client:"+(array.length)+" execution time= " +duration+" ns");
            System.out.println(val);
        }
        static int[] getArray(int length){
            int arr[]=new int[length];
            for(int i=0;i<length;i++){
                arr[i]=(int)(Math.random()*length);
            }
            return arr;
        }
    }