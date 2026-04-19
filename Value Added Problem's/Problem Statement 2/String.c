/*Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine
whether the Expression is balanced or not.
An expression is balanced if:
1. Each opening bracket has a corresponding closing bracket of the same type.
2. Opening brackets must be closed in the correct order.*/

#include <stdio.h>
#include <string.h>
#define MAX 1000000
char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}
int isBalanced(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1)
                return 0;
            
            char topElement = pop();
            if (!isMatchingPair(topElement, s[i]))
                return 0;
        }
    }
    return (top == -1);
}
int main() {
    printf("Name : Raj Shekhar Shukla\n");
    printf("PRN : 25070521194\n");
    printf("Section : D-1\n");
    printf("Value Added Problem : 2\n");
    printf("---------------------------\n");
    char s[MAX];
    printf("Enter expression: ");
    scanf("%s", s);   
    if (isBalanced(s))
        printf("true\n");
    else
        printf("false\n");    
    return 0;
}
