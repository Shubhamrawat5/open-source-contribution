package com.company;

import java.util.Scanner;

public class MultiplicationTable {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number for you want table for:");
        int urchoice = sc.nextInt();
        System.out.println("Table for " + urchoice + ":");
        for (int i=1; i<=10; i++)
        {
            System.out.printf("%d X %d = %d\n", urchoice, i, urchoice * i);
        }
    }
}
