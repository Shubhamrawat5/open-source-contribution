#!/bin/bash

while true; do
    echo "Select an operation:"
    echo "1. Addition (+)"
    echo "2. Subtraction (-)"
    echo "3. Multiplication (*)"
    echo "4. Division (/)"
    echo "5. Quit"

    read -p "Enter your choice (1/2/3/4/5): " choice

    case $choice in
        1)
            read -p "Enter the first number: " num1
            read -p "Enter the second number: " num2
            result=$(bc -l <<< "$num1 + $num2")
            echo "Result: $result"
            ;;
        2)
            read -p "Enter the first number: " num1
            read -p "Enter the second number: " num2
            result=$(bc -l <<< "$num1 - $num2")
            echo "Result: $result"
            ;;
        3)
            read -p "Enter the first number: " num1
            read -p "Enter the second number: " num2
            result=$(bc -l <<< "$num1 * $num2")
            echo "Result: $result"
            ;;
        4)
            read -p "Enter the dividend: " num1
            read -p "Enter the divisor: " num2

            if ((num2 == 0)); then
                echo "Error: Division by zero is not allowed."
            else
                result=$(bc -l <<< "scale=2; $num1 / $num2")
                echo "Result: $result"
            fi
            ;;
        5)
            echo "Exiting calculator."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please select a valid operation."
            ;;
    esac
done
