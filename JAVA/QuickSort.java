public class QuickSort {

    // method for partition
    public static int Partition(int low, int high, int[] A) {

        int pivot = A[high];
        int i = low;
        int j = high - 1;

        while (i <= j) {
            while (A[i] < pivot) {
                i++;
            }
            while (j > 0 && A[j] > pivot) {
                j--;
            }
            if (i < j)
                swap(i, j, A);
            else
                break;
        }
        swap(i, high, A);
        return j;
    }

    static void swap(int num1, int num2, int[] A) {
        int temp = A[num1];
        A[num1] = A[num2];
        A[num2] = temp;
    }

    // method for quicksort
    void quicksort(int low, int high, int[] A) {

        if (low < high) {
            int j = Partition(low, high, A);
            quicksort(low, j, A);
            quicksort(j + 1, high, A);
        }

    }

    static void printarr(int[] A) {
        int n = A.length;
        for (int i = 0; i < n; i++)
            System.out.print(A[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] arr = { 23, 4, 6, 43, 2, 8, 34, 19, 3, 12 };
        int low = 0;
        int high = arr.length - 1;

        QuickSort arr1 = new QuickSort();
        arr1.quicksort(low, high, arr);

        System.out.println("sorted array : ");
        printarr(arr);
    }

}