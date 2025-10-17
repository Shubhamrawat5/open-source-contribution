import java.util.Scanner;

public class CommandLineCalculator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the first operand: ");
        double operand1 = scanner.nextDouble();

        System.out.println("Enter the operator (+, -, *, /): ");
        String operator = scanner.next();

        System.out.println("Enter the second operand: ");
        double operand2 = scanner.nextDouble();

        double result = 0.0;

        switch (operator) {
            case "+":
                result = operand1 + operand2;
                break;
            case "-":
                result = operand1 - operand2;
                break;
            case "*":
                result = operand1 * operand2;
                break;
            case "/":
                if (operand2 != 0) {
                    result = operand1 / operand2;
                } else {
                    System.err.println("Error: Division by zero is not allowed.");
                }
                break;
            default:
                System.err.println("Error: Invalid operator. Please use +, -, *, or /.");
                break;
        }

        System.out.println("Result: " + result);
    }

}
