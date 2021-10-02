package com.company;
import java.util.LinkedList;
import java.util.Queue;


public class BinaryTreeLL {
    BinaryNode root;

    public BinaryTreeLL(){
        this.root=null;
    }

//    preorder
    void preOrder(BinaryNode node){
        if (node==null){
            return;
        }
        System.out.print(node.value+" ");
        preOrder((node.left));
        preOrder((node.right));
    }

//    inorder
    void inOrder(BinaryNode node){
        if (node==null){
            return;
        }
        inOrder(node.left);
        System.out.print(node.value+" ");
        inOrder(node.right);
    }

//    postorder
    void postOrder(BinaryNode node){
        if (node==null){
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.value+" ");

    }



    // Level Order
    void levelOrder() {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            BinaryNode presentNode = queue.remove();
            System.out.print(presentNode.value + " ");
            if (presentNode.left != null) {
                queue.add(presentNode.left);
            }
            if (presentNode.right != null) {
                queue.add(presentNode.right);
            }
        }
    }

    // Search Method
    public void search(String value) {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            BinaryNode presentNode = queue.remove();
            if (presentNode.value == value) {
                System.out.println("The value-"+value+" is found in Tree");
                return;
            } else {
                if (presentNode.left!=null) {
                    queue.add(presentNode.left);
                }
                if (presentNode.right!=null) {
                    queue.add(presentNode.right);
                }
            }
        }
        System.out.println("The value-"+value+" is not found in Tree");
    }


    // Insert Method
    void insert(String value) {
        BinaryNode newNode = new BinaryNode();
        newNode.value = value;
        if (root == null) {
            root = newNode;
            System.out.println("Inserted new node at Root");
            return;
        }
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            BinaryNode presentNode = queue.remove();
            if (presentNode.left == null) {
                presentNode.left = newNode;
                System.out.println("Successfully Inserted");
                break;
            } else if (presentNode.right == null) {
                presentNode.right = newNode;
                System.out.println("Successfully Inserted");
                break;
            } else {
                queue.add(presentNode.left);
                queue.add(presentNode.right);
            }
        }
    }

    // Get Deepest node
    public BinaryNode getDeepestNode() {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        BinaryNode presentNode = null;
        while (!queue.isEmpty()) {
            presentNode = queue.remove();
            if (presentNode.left != null) {
                queue.add(presentNode.left);
            }
            if (presentNode.right != null) {
                queue.add(presentNode.right);
            }
        }
        return presentNode;
    }

    // Delete Deepest node
    public void deleteDeepestNode() {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        BinaryNode previousNode, presentNode = null;
        while (!queue.isEmpty()) {
            previousNode = presentNode;
            presentNode = queue.remove();
            if (presentNode.left == null) {
                previousNode.right = null;
                return;
            } else if (presentNode.right == null) {
                presentNode.left = null;
                return;
            }
            queue.add(presentNode.left);
            queue.add(presentNode.right);

        }
    }

    // Delete Given node
    void deleteNode(String value) {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            BinaryNode presentNode = queue.remove();
            if (presentNode.value == value) {
                presentNode.value = getDeepestNode().value;
                deleteDeepestNode();
                System.out.println("The node is deleted!");
                return;
            } else {
                if (presentNode.left != null) queue.add(presentNode.left);
                if (presentNode.right != null) queue.add(presentNode.right);
            }
        }
        System.out.println("The node does not exist in this BT");
    }

    // Delete Binary Tree
    void deleteBT() {
        root = null;
        System.out.println("BT has been successfully deleted!");
    }



}
