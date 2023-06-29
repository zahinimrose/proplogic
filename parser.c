/*
A simple logic evaluator that can parse and evaluate logic strings.

Feature: Can only parse char* input string and evaluate it at the same time. Outputs 1 for true and 0 for false. Probably has bugs

How to use: Edit Input string, compile and run parser.c. No whitespaces are supported.

True -  'T'
False - 'F'
Negate - '~'
Conjunction - '^'
Disjunction - 'v'
parentheses supported

Example: "~(T^~F)"

TODO: 
#Interface
#Removal of whitespace
#Bug fixes
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool expression();
bool term();
bool factor();

char* input = "~(T^~F)";
size_t position = 0;

void error() {
    fprintf(stderr, "Syntax Error!\n");
    exit(1);
}

void consume(char expected) {
    if (input[position] == expected) {
        position++;
    }
    else if (input[position] == '\0') {
        printf("Parsing Completed\n");
    }
    else {
        error();
    }
}

bool literal() {
    char c = input[position];
    switch(c) {
        case 'T':
            consume(c);
            return true;
        case 'F':
            consume(c);
            return false;
        default:
            error();
    }
}

bool factor() {
    char c = input[position];
    bool negate = false;
    bool output;
    if (c == '~') { // negation
        consume('~');
        negate = true;
    }
    if (input[position] == 'T' | input[position] == 'F') {
        output = literal();
    }
    else if (input[position] == '(') {
        consume('(');
        output = expression();
        consume(')');
    }
    else {
        error();
    }

    return (negate) ? !output : output;
}

bool expression() {
    bool result = term();
    while(input[position] == 'v') {
        consume('v');
        result = result || term();
    }
    return result;
}

bool term() {
    bool result = factor();

    while (input[position] == '^') {
        consume('^');
        result = result && factor();
    }

    return result;
}

int main() {
    
    printf("%d\n",expression());
    return 0;
}