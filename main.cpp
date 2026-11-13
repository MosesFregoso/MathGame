#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int choice;
    cout << "=== Welcome to the Math Adventure Game! ===" << endl;
    cout << "Choose your operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    int score = 0;
    int questions = 3;
    
    for (int i = 1; i <= questions; i++) {
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;
        int correctAnswer = 0;
        char opSymbol = '+';
        
        switch (choice) {
            case 1:
                correctAnswer = num1 + num2;
                opSymbol = '+';
                break;
            case 2:
                // Make sure subtraction doesn't result in negative numbers for kids
                if (num1 < num2) {
                    int temp = num1;
                    num1 = num2;
                    num2 = temp;
                }
                correctAnswer = num1 - num2;
                opSymbol = '-';
                break;
            case 3:
                correctAnswer = num1 * num2;
                opSymbol = '*';
                break;
            default:
                cout << "Invalid choice! Defaulting to Addition." << endl;
                correctAnswer = num1 + num2;
                opSymbol = '+';
                break;
        }
        
        int userAnswer;
        cout << "\nQuestion " << i << ": What is " << num1 << " " << opSymbol << " " << num2 << "? ";
        cin >> userAnswer;
        
        if (userAnswer == correctAnswer) {
            cout << "Correct! Awesome job! 🌟" << endl;
            score++;
        } else {
            cout << "Oops! The correct answer was " << correctAnswer << "." << endl;
        }
    }
    
    cout << "\n=== Game Over! ===" << endl;
    cout << "Your final score: " << score << " out of " << questions << endl;
    
    if (score == questions) {
        cout << "You're a math superstar!" << endl;
    } else {
        cout << "Good effort! Keep practicing!" << endl;
    }
    
    return 0;
}