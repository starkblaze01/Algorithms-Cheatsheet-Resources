//Example HashMap
// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.
import java.util.HashMap;
import java.util.Map;

class TwoSum{
    public static void main(String[] args) {
        int[] arr={2,7,11,15};
        int target = 9;
        int[] a=twoSum(arr, target);
        for (int i = 0; i < a.length; i++) {
            
            System.out.println(a[i]);
        }
    }

    public static int[] twoSum(int[] nums, int target) {
        
        HashMap<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int n=target-nums[i];
            if(mp.containsKey(n)){
                return new int[]{i,mp.get(n)};
            }
            mp.put(nums[i], i);
        }

        return new int[]{0,0};
    }
}