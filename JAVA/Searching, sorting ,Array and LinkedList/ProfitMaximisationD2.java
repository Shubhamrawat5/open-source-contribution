package com.company;

public class ProfitMaximisationD2 {
    public static void main(String[] args) {
        int price[] = { 100, 180, 260, 310, 40, 535, 695 };
        System.out.println(maxProfit(price));
    }

    private static int maxProfit(int[] price) {
        int size = price.length;
        int maxProfit = 0;
        for (int i = 1; i < size; i++) {
            if (price[i]>price[i-1]){
                maxProfit+=price[i]-price[i-1];
            }

        }
        return maxProfit;

    }

}
