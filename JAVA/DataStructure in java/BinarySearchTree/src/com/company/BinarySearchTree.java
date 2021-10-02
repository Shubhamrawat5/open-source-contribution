package com.company;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class BinarySearchTree {
    BinaryNode root;

    BinarySearchTree(){
        root=null;
    }

    private BinaryNode insert(BinaryNode currentNode, int value){
        if (currentNode==null){
            BinaryNode newNode = new BinaryNode();
            newNode.value=value;
//            System.out.println("value inserted successfully!");
            return newNode;
        }
        else if (value<=currentNode.value){
            currentNode.left= insert(currentNode.left,value);
            return currentNode;
        }
        else {
            currentNode.right=insert(currentNode.right, value);
            return currentNode;
        }
    }

    void insert(int value){
        root = insert(root,value);
    }

    public void preOrder(BinaryNode node){
        if (node==null){
            return;
        }
        System.out.print(node.value+ " ");
        preOrder(node.left);
        preOrder(node.right);
    }


    // Inorder Traversal
    public void inOrder(BinaryNode node) {
        if (node == null) {
            return;
        }
        inOrder(node.left);
        System.out.print(node.value + " ");
        inOrder(node.right);


    }

    // PostOrder Traversal
    public void postOrder(BinaryNode node) {
        if (node == null) {
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.value + " ");
    }

//    level order
        void levelOrder(){
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while (!queue.isEmpty()){
            BinaryNode presentNOde = queue.remove();
            System.out.print(presentNOde.value+ " ");
            if (presentNOde.left!=null){
                queue.add(presentNOde.left);
            }
            if (presentNOde.right!=null){
                queue.add(presentNOde.right);
            }
        }
        }

        BinaryNode search(BinaryNode node, int value){
        if (node==null){
            System.out.println("Node not found!");
            return null;
        }else if (node.value==value){
            System.out.println("node found  ");
            return node;
        }else if (value> node.value){
            return search(node.right,value);
        }else {
            return search(node.left,value);
        }
        }

        public static BinaryNode minimumNode(BinaryNode root){
        if (root.left==null){
            return root;
        }else {
            return minimumNode(root.left);
        }
        }

    public BinaryNode deleteNode(BinaryNode root, int value) {
        if (root == null) {
            System.out.println("Value not found in BST");
            return null;
        }
        if (value < root.value) {
            root.left = deleteNode(root.left, value);
        } else if (value > root.value) {
            root.right = deleteNode(root.right, value);
        } else {
            if (root.left != null && root.right != null) {
                BinaryNode temp = root;
                BinaryNode minNodeForRight = minimumNode(temp.right);
                root.value = minNodeForRight.value;
                root.right = deleteNode(root.right, minNodeForRight.value);
            } else if (root.left != null) {
                root = root.left;
            } else if (root.right != null) {
                root = root.right;
            } else {
                root = null;
            }
        }

        return root;

    }


    public void deleteBST() {
        root = null;
        System.out.println("BST has been deleted successfully");
    }




}
