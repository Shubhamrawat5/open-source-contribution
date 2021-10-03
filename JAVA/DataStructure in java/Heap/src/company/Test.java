package company;

public class Test {
    public static void main(String[] args) {
        Heap hp = new Heap(15);
        hp.insert(1);
        hp.insert(4);
        hp.insert(2);
        hp.insert(5);
        hp.insert(13);
        hp.insert(6);
        hp.insert(17);

        hp.printHeap(hp.array);
        System.out.println("The Delete Number Is : " + hp.deleteMax());
        hp.printHeap(hp.array);

    }
}
