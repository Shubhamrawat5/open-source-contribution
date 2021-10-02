package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code
        BinaryTree newBinaryTree = new BinaryTree(9);

        newBinaryTree.insert("N1");
        newBinaryTree.insert("N2");
        newBinaryTree.insert("N3");
        newBinaryTree.insert("N4");
        newBinaryTree.insert("N5");
        newBinaryTree.insert("N6");
        newBinaryTree.insert("N7");
        newBinaryTree.insert("N8");
        newBinaryTree.insert("N9");

//        newBinaryTree.preOrder(1);
//        newBinaryTree.inOrder(1);
//        newBinaryTree.postOrder(1);

//        newBinaryTree.levelOrder();

//            newBinaryTree.search("N7");
//        newBinaryTree.levelOrder();
//        System.out.println(" ");
//            newBinaryTree.delete("N7");
//        System.out.println(" ");
        newBinaryTree.levelOrder();

        newBinaryTree.deleteBT();













    }
}
