#include <stdio.h>
#include <stdbool.h>

#include "evaluator.c"

char bool_to_literal(bool b) {
    return (b) ? 'T': 'F';
}

char* replace_variable_to_literal(char* string, char var, bool truth) {
    char* ans = malloc(sizeof(char) * (strlen(string) +1));
    size_t i =0;
    while(string[i] != '\0') {
        if (string[i] == var) {
            ans[i] = bool_to_literal(truth); 
        }
        else {
            ans[i] = string[i];
        }
        i++;
    }
    ans[i] = '\0';
    return ans;
}

#if 1
void P_Q_print_truth_table(char* str) {
    printf("P|Q|R\n_____\n");
    for (size_t i = 0; i < 2; ++i) {
        for(size_t j =0; j < 2; ++j) {
            char* a = replace_variable_to_literal(str, 'P', i);
            char* b = replace_variable_to_literal(a, 'Q', j);
            free(a);

            printf("%c|%c|%c\n",bool_to_literal(i), bool_to_literal(j), bool_to_literal(evaluate(b)));

            free(b);
            //printf("_____\n");
        }
    }
}
#endif

int main() {
    
    P_Q_print_truth_table("PvT");
    
    
    return 0;
}