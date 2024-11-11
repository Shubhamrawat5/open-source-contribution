public class SB {
    public static void main(String args[]) {
        // String name = "Sudarshan";
        StringBuilder name = new StringBuilder("Sudarshan");
        System.out.println(name);

        // add at the begin of string
        name.insert(0, "U");
        System.out.println(name);

        // Delete any letter in string eg:r
        name.deleteCharAt(5);
        System.out.println(name);

        // replace charater at index
        name.setCharAt(1, 'a');
        System.out.println(name);

        // add at the end of string
        name.append(' ');
        System.out.println(name);
        name.append("Jadhav");
        System.out.println(name);

        // Reverse string
        name.reverse();
        System.out.println(name);

        // OR
        for (int i = 0; i < name.length() / 2; i++) {
            int front = i;
            int back = name.length() - 1 - i;

            char frontchar = name.charAt(front);
            char backchar = name.charAt(back);

            name.setCharAt(front, backchar);
            name.setCharAt(back, frontchar);

        }
        System.out.println(name);
    }

}
