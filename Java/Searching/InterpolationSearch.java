public class InterpolationSearch {
    private static int [] sorted = null;

    public static final int find (int value, int[] array) {
        InterpolationSearch.sorted = array;
        try {
            return recursiveFind(value, 0, InterpolationSearch.sorted.length - 1);
        } finally {
            InterpolationSearch.sorted = null;
        }
    }

    private static int recursiveFind(int value, int start, int end) {
        if(start == end) {
            int lastValue = sorted[start];
            if(value == lastValue)
                return start;
            return Integer.MAX_VALUE;
        }

        final int middle = start + ((value - sorted[start]) * (end - start)) /
            (sorted[end] - sorted[start]);
        if (middle < 0 || middle > end)
            return Integer.MAX_VALUE;
        int middleValue = sorted[middle];
        if (value == middleValue)
            return middle;
        if (value > middleValue)
            return recursiveFind(value, middle + 1, end);
        return recursiveFind(value, start, middle -1);
    }

    public static void main(String[] args) {
        int[] integers = {10,20,30,40,50,60,70,80,90,100};
        int key = 100;

        int atIndex = InterpolationSearch.find(key, integers);

        System.out.println("The array indes starts from 0");
        System.out.println("The size of the array is : " + integers.length);
        System.out.println("The element found at index : " + atIndex);
    }
}