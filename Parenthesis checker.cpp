/*Parenthesis Checker:
Write a program using a  stack  for push, pop, peek, and isEmpty operations. Write isBalanced() Function that Iterates through the input expression, Pushes opening brackets onto the stack. For closing brackets, it checks the top of the stack for a matching opening bracket. Ensures that all opening brackets are matched by the end of the traversal. Main Function: Accepts a string expression from the user. Uses isBalanced() to determine if the parentheses in the expression are balanced.
*/

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

class ParenthesisChecker {
private:
    char stack[SIZE];
    int top;

public:
    ParenthesisChecker() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack is  Full! Cannot push " << c << endl;
        } else {
            stack[++top] = c;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
        } else {
            top--;
        }
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        } else {
            return stack[top];
        }
    }

    bool isBalanced(string expr) {
        for (char c : expr) {
            if (c == '(' || c == '{' || c == '[') {
                push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                if (isEmpty())
                    return false;

                char topChar = peek();
                if ((c == ')' && topChar == '(') ||
                    (c == '}' && topChar == '{') ||
                    (c == ']' && topChar == '[')) {
                    pop();
                } else {
                    return false;
                }
            }
        }
        return isEmpty();
    }
};

int main() {
    ParenthesisChecker checker;
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if (checker.isBalanced(expression))
        cout << "Given expression is balanced!" << endl;
    else
        cout << "Given expression is not balanced!" << endl;

    return 0;
}
