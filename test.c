#include <stdio.h>
#include "evaluator.c"

int main() {
    printf("%s\n",(evaluate("~T")) ? "True" : "False");
    
    return 0;
}