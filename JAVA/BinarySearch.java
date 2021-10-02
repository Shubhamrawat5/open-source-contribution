
public class BinarySearch {


    public static int binarySearch(int array[], int value) {

        //declare the left index
        int Left = 0;
        int n = array.length;
        //declare the right index
        int Right = n - 1;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (Left > Right)
                result = -1;
            else {
                //set the middle index of the array
                int mid = (Left + Right) / 2;
                
                if (array[mid] < value)
                    Left = mid + 1;
                if (array[mid] > value)
                    Right = mid - 1;
                if (array[mid] == value)
                    result = mid;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        //sorted array of items
        int[] arr = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
        //value we need to search
        int value = 23;

        //call the binary search method
        int result = binarySearch(arr, value);
        if (result == -1) {
            System.out.println(value + " is not found");
        } else {
            System.out.println(value + " is found in index " + result);
        }

    }
}