/*
Question :
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.


*/
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include <stdlib.h>

struct Stack {
    char data;
    struct Stack *next;
};

struct Stack *top = NULL;

void Push(char c) {
    struct Stack *newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char Pop() {
    if (top == NULL) return '\0';
    struct Stack *temp = top;
    char val = temp->data;
    top = temp->next;
    free(temp);
    return val;
}
int match(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

bool isValid(char* s) {
    top = NULL;
    if(strlen(s)%2 != 0) return false;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '(' ||s[i] == '{' || s[i] == '[') Push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top == NULL) {
                return false;
            }
            char pop = Pop();
            if (!match(pop, s[i])) {
                return false;
            }
        }
    }
    return (top == NULL);
}

int main() {
    char s[100];
    printf("Enter a string of parentheses: ");
    scanf("%s", s);
    if(isValid(s)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }
    return 0;
}

/*
Output :
Enter a string of parentheses: ()[]{}
The string is valid.    

Enter a string of parentheses: ([)]
The string is not valid.
*/