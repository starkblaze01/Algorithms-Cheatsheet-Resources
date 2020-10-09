public class JumpSearch { 
    public static int jumpSearch(int[] sortedArray, int key) { 
        
        int n = sortedArray.length; 
        int step = (int)Math.floor(Math.sqrt(n)); 
        int prev = 0; 
        
        while (sortedArray[Math.min(step, n)-1] < key) { 
            prev = step; 
            step += (int)Math.floor(Math.sqrt(n)); 
            if (prev >= n) 
                return -1; 
        }  
        
        while (sortedArray[prev] < key) { 
            prev++; 
            if (prev == Math.min(step, n)) 
                return -1; 
        } 
        
        if (sortedArray[prev] == key) 
            return prev; 
  
        return -1; 
    } 
    public static void main(String [ ] args) { 
        int sortedArray[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 43, 48, 55, 89, 144, 233, 377, 610}; 
        int key = 55; 
        int index = jumpSearch(sortedArray, key); 
        System.out.println("Number " + key + " is at index " + index); 
    } 
} 