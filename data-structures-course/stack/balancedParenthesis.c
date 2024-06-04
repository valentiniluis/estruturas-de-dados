#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_utils.h"

int checkBalancedParenthesis(char *s, int len);

int main() {
    char string[] = "{[([{[()]}])]}";
    int balanced = checkBalancedParenthesis(string, strlen(string));
    if (balanced) {
        printf("The parenthesis are balanced.\n");
    }
    else {
        printf("The parenthesis are NOT balanced.\n");
    }

    return 0;
}

int checkBalancedParenthesis(char *s, int len) {
    cStack *top = NULL;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            pushChar(&top, s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top == NULL) return 0;
            else if (top->letter == '(' && s[i] != ')') return 0;
            else if (top->letter == '[' && s[i] != ']') return 0;
            else if (top->letter == '{' && s[i] != '}') return 0;
            
            else {
                popChar(&top);
            }
        }
    }
    int result = (top == NULL);
    freeCharStack(&top);
    return result;
}