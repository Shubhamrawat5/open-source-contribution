package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        ArrayList<Integer> l = new ArrayList<>(10);
        l.add(5);
        l.add(25);
        l.add(45);
        l.add(55);
        int index= l.get(3);
        System.out.println(l.isEmpty());
        System.out.println(l);
        l.remove(0);
        System.out.println(l);

        l.add(1,3);
        System.out.println(l);

    }
}
