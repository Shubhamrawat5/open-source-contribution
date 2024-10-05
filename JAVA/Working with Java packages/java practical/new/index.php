<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Retrieve form data
    $name = $_POST['name'];
    $email = $_POST['emailid'];
    $message = $_POST['message'];

    // Validate form data (you can add more validation if needed)
    if (empty($name) || empty($email) || empty($message)) {
        echo "Please fill in all fields.";
        exit;
    }

    // Set up email parameters
    $to = 'your-email@example.com'; // Replace with your own email address
    $subject = 'New Message from your website';
    $body = "Name: $name\nEmail: $email\nMessage: $message";
    $headers = "From: $email";

    // Send email
    if (mail($to, $subject, $body, $headers)) {
        echo "Thank you for contacting us. We will get back to you soon!";
    } else {
        echo "Oops! An error occurred while sending the email.";
    }
}
?>
