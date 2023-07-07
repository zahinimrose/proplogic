/*
A simple logic evaluator that can parse and evaluate logical expression strings.

Features: Can only parse char* _ev_input string and evaluate it at the same time. Outputs True or False. Probably has bugs

How to use: evaluate(char* str); 

No whitespaces are supported.

True -  'T'
False - 'F'
Negate - '~'
Conjunction - '^'
Disjunction - 'v'
Parentheses supported

Example: "~(T^~F)"

TODO: 
#Removal of whitespace
#Ensure memory safety
*/
#ifndef EVALUATOR_C
#define EVALUATOR_C

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool expression();
bool term();
bool factor();

void _ev_error() {
    fprintf(stderr, "Syntax Error!\n");
    exit(1);
}

#define MAX_SIZE 100

char _ev_input[MAX_SIZE];
size_t _ev_index;
#define CURRENT _ev_input[_ev_index]

void consume(char expected) {
    if (CURRENT == expected) {
        _ev_index++;
    }
    else if (CURRENT == '\0') {
        printf("Parsing Completed\n");
    }
    else {
        _ev_error();
    }
}

bool literal() {
    char c = CURRENT;
    switch(c) {
        case 'T':
            consume(c);
            return true;
        case 'F':
            consume(c);
            return false;
        default:
            _ev_error();
    }
}

bool factor() {
    char c = CURRENT;
    bool negate = false;
    bool output;

    if (c == '~') { // negation
        consume('~');
        negate = true;
    }

    if (CURRENT == 'T' | CURRENT == 'F') {
        output = literal();
    }
    else if (CURRENT == '(') {
        consume('(');
        output = expression();
        consume(')');
    }
    else {
        _ev_error();
    }

    return (negate) ? !output : output;
}

bool expression() {
    bool result = term();
    while(CURRENT == 'v') {
        consume('v');
        bool t = term();
        result = result || t;
    }
    
    return result;
}

bool term() {
    bool result = factor();

    while (CURRENT == '^') {
        consume('^');
        bool f = factor();
        result = result && f;
    }

    return result;
}

bool evaluate(char* str) {
    strcpy(_ev_input, str);
    _ev_index = 0;

    bool ans = expression();

    _ev_input[0] = '\0';
    _ev_index = 0;

    return ans;
}

#endif // EVALUATOR_C