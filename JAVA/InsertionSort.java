
public class InsertionSort {

    void insertion_sort(int arr[], int n) {

        for (int i = 1; i < n; i++) {
            int value = arr[i];

            int j = i - 1;

            while (j >= 0 && arr[j] > value) {

                arr[j + 1] = arr[j];

                j--;
            }
            arr[j + 1] = value;
        }
        System.out.println("The sorted array:");

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = {15, 25, 30, 17, 9, 5, 20, 10, 11, 6};

        int n = arr.length;

        System.out.println("The original array:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        InsertionSort is = new InsertionSort();
       is.insertion_sort(arr, n);
    }
}
