package open-source-contribution.JAVA.JavaProject;

import java.util.*;

class Book {
    String title, author, isbn;
    boolean isBorrowed;

    Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.isBorrowed = false;
    }

    void borrow() {
        if (!isBorrowed) {
            isBorrowed = true;
            System.out.println("You borrowed " + title);
        } else {
            System.out.println(title + " is already borrowed.");
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            System.out.println("You returned " + title);
        } else {
            System.out.println(title + " was not borrowed.");
        }
    }
}

class Library {
    private final ArrayList<Book> books = new ArrayList<>();

    void addBook(String title, String author, String isbn) {
        books.add(new Book(title, author, isbn));
        System.out.println("Book added: " + title);
    }

    void searchBook(String title) {
        for (Book book : books) {
            if (book.title.equalsIgnoreCase(title)) {
                System.out.println("Book found: " + book.title + " by " + book.author);
                return;
            }
        }
        System.out.println("Book not found.");
    }
}

public class LibraryManagementSystem {
    public static void main(String[] args) {
        Library library = new Library();
        library.addBook("Java Programming", "John Doe", "12345");
        library.searchBook("Java Programming");
        library.searchBook("Python Programming");
    }
}

