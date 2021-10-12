package com.company;

import java.util.ArrayList;


public class SearchingArrayList {
    public static boolean search (ArrayList<Integer> val, int n){
        if (val.contains(n)){
            return true;
        }else {
            return false;
        }
    }
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>(10);
        arr.add(10);
        arr.add(11);
        arr.add(15);
        arr.add(80);
        arr.add(60);
        arr.add(10);
        arr.add(20);
        arr.add(30);
        arr.add(4);
        arr.add(70);
//        search(arr, 20);
        System.out.println(search(arr, 21));
    }
}
