package com.company;

public class SearchInString {
    public static void main(String[] args) {
        String name = "heena";
        char t1 = 'e';
        char t2 = 'a';
        char t3 = 'z';
        System.out.println(SearchBool(name, t1));
        System.out.println(SearchChar(name, t2));
        System.out.println(SearchIndex(name, t3));
    }
    static int SearchIndex(String str, char ch)
    {
        if(str.length() == 0)
            return -1;
        for(int i = 0; i < str.length(); i++)
        {
            if(ch == str.charAt(i))
            {
                return i;
            }
        }
        return -1;
    }
    static char SearchChar(String str, char ch)
    {
        if(str.length() == 0)
            return '#';
        for(char c : str.toCharArray()) //for each element access : We've to convert String to Array --> CharArray
        {
            if(ch == c)
            {
                return c;
            }
        }
        return '#';
    }
    static boolean SearchBool(String str, char ch)
    {
        if(str.length() == 0)
            return false;
        for(int i = 0; i < str.length(); i++)
        {
            if(ch == str.charAt(i))
            {
                return true;
            }
        }
        return false;
    }
}
