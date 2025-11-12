/* 
   Problem Statement:
   Implement a C++ program for infix to postfix conversion using stack 
*/

#include <iostream>
#include <cstring>
#include <string>
#define N 10
using namespace std;

class Stack {
public:
    char arr[N];
    int top;

    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top == N - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = c;
        }
    }

    char pop() {
        char c = ' ';
        if (top == -1) {
            // Stack underflow - return blank
        } else {
            c = arr[top--];
        }
        return c;
    }

    char peek() {
        if (top == -1)
            return ' ';
        return arr[top];
    }

    int precedence(char opr) {
        if (opr == '*' || opr == '/')
            return 2;
        if (opr == '+' || opr == '-')
            return 1;
        if (opr == '(')
            return 0;
        return -1; // for safety
    }

    char associativity(char opr) {
        if (opr == '*' || opr == '/' || opr == '+' || opr == '-')
            return 'L';
        else
            return 'R';
    }

    string infixToPostfix(string ex);
};

string Stack::infixToPostfix(string ex) {
    int l = ex.length();
    int i = 0, j = 0;
    char op_exp[50];
    char ch, ch1;

    while (i < l) {
        if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/') {
            if (top == -1) {
                push(ex[i]);
            } else {
                ch = peek();
                while (precedence(ex[i]) <= precedence(ch)) {
                    ch1 = pop();
                    op_exp[j++] = ch1;
                    ch = peek();
                }
                push(ex[i]);
            }
        } 
        else if (ex[i] == '(') {
            push(ex[i]);
        } 
        else if (ex[i] == ')') {
            ch1 = pop();
            while (ch1 != '(') {
                op_exp[j++] = ch1;
                ch1 = pop();
            }
        } 
        else {
            // Operand (variable or number)
            op_exp[j++] = ex[i];
        }
        i++;
    }

    do {
        ch = pop();
        if (ch != ' ')  // avoid garbage
            op_exp[j++] = ch;
    } while (top != -1);

    op_exp[j] = '\0';
    return op_exp;
}

int main() {
    Stack s;
    string ex;

    cout << "\nEnter an infix expression: ";
    cin >> ex;

    string postfix = s.infixToPostfix(ex);
    cout << "\nPostfix Expression: " << postfix << endl;

    return 0;
}
