package open-source-contribution.JAVA.JavaProject;

// Description: A console-based quiz application where users answer questions and get their score at the end. Key Features:

// Multiple-choice questions
// Score calculation at the end
// Feedback on the correct/incorrect answers
import java.util.Scanner;

public class OnlineQuizSystem {
    public static void main(String[] args) {
        String[] questions = {
            "What is the capital of France? \n1. Paris \n2. Berlin \n3. Madrid",
            "Who developed Java? \n1. James Gosling \n2. Mark Zuckerberg \n3. Bill Gates"
        };
        int[] answers = {1, 1}; // Correct answers
        int score = 0;

        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < questions.length; i++) {
            System.out.println(questions[i]);
            System.out.print("Enter your answer: ");
            int userAnswer = scanner.nextInt();

            if (userAnswer == answers[i]) {
                score++;
                System.out.println("Correct!");
            } else {
                System.out.println("Wrong.");
            }
        }

        System.out.println("Quiz Over! Your score is: " + score + "/" + questions.length);
    }
}
