#include <stdio.h>
#include "evaluator.c"
#include "propvar.c"

int main(int argc, char *argv[]) {

    P_Q_print_truth_table(argv[1]);
    
    return 0;
}