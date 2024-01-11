#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char input[100];
int i = 0;

void E();
void T();
void F();

void error() {
    printf("Invalid input!\n");
    exit(0);
}

void match(char c) {
    if (input[i] == c) {
        i++;
    } else {
        error();
    }
}

void E() {
    T();
    while (input[i] == '+') {
        match('+');
        T();
    }
}

void T() {
    F();
    while (input[i] == '*') {
        match('*');
        F();
    }
}

void F() {
    if (isdigit(input[i])) {
        match(input[i]);
    } else if (input[i] == '(') {
        match('(');
        E();
        match(')');
    } else {
        error();
    }
}

int main() {
    printf("Enter an arithmetic expression:\n");
   // fgets(input, 100, stdin);
    scanf("%s",input);
    E();
    if (input[i] == '\0') {
        printf("Input is valid!\n");
    } else {
        error();
    }
    return 0;
}
