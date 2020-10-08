import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class RadixSort{
    public static void radixSort(int[] input) {
        final int RADIX = 10;
        List<Integer>[] bucket = new ArrayList[RADIX];
        for (int i = 0; i < bucket.length; i++) {
            bucket[i] = new ArrayList<Integer>();
        }

        boolean maxLength = false;
        int temp = -1, placement = 1;
        while (!maxLength) {
            maxLength = true;

            for(Integer i : input) {
                temp = i / placement;
                bucket[temp % RADIX].add(i);
                if(maxLength && temp > 0) {
                maxLength = false;
                }
            }

            int a = 0;
            for(int b = 0; b < RADIX; b++) {
                for(Integer i : bucket[b]) {
                input[a++] = i;
                }
                    bucket[b].clear();
            }
            placement *= RADIX;
        }
    }

    public static void main(String[] args) {
        int[] input = {90,23,101,45,65,23,67,89,34,23};
        radixSort(input);
        System.out.println("The sorted array is: " + Arrays.toString(input));
    }
}