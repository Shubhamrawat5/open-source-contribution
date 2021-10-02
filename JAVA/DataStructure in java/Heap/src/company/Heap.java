package company;

public class Heap {

    public int[] array;
    private int size;
    private int maxHeap;

    //Constructor
    public Heap(int size) {
        this.size = 0;
        this.maxHeap = size;
        array = new int[this.maxHeap + 1];
        array[0] = Integer.MAX_VALUE;
    }

    public int parent(int i) {
        return i / 2;
    }

    public int LeftChild(int i) {
        return (2 * i);
    }

    private int RightChild(int i) {
        return (2 * i) + 1;
    }

    //swap value in heap
    public void Swap(int e, int n) {
        int temp;
        temp = array[0];
        array[e] = array[n];
        array[n] = temp;
    }

    public void HeapifyDown(int pos) {
        if (pos >= (size / 2) && pos <= size) {
            return;
        }

        if (array[pos] < array[LeftChild(pos)] || array[pos] < array[RightChild(pos)]) {
            if (array[LeftChild(pos)] > array[RightChild(pos)]) {
                Swap(pos, LeftChild(pos));
                HeapifyDown(LeftChild(pos));
            } else {
                Swap(pos, RightChild(pos));
                HeapifyDown(RightChild(pos));
            }
        }
    }

    public void HeapifyUp(int pos) {
        int temp = array[pos];
        while (pos > 0 && temp > array[parent(pos)]) {
            array[pos] = array[parent(pos)];
            pos = parent(pos);

        }
        array[pos] = temp;
    }

    // insert value
    public void insert(int data) {
        array[++size] = data;
        int current = size;
        HeapifyUp(current);
    }

    //    delete number
    public int deleteMax() {
        int max = array[1];
        array[1] = array[size--];
        HeapifyDown(1);
        return max;
    }


    public void printHeap(int A[]) {
        for (int i = 1; i <= size; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println("");
    }


}
