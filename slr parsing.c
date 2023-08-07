#include <stdio.h>
#include <string.h>

#define NUM_STATES 5
#define NUM_SYMBOLS 4

// SLR Parsing table
int parsing_table[NUM_STATES][NUM_SYMBOLS] = {
    { 3, 4, -1, 2 },
    { -1, -1, -1, -1 },
    { -1, -1, 5, -1 },
    { 3, 4, -1, 6 },
    { -1, -1, 7, -1 }
};

// Stack for parsing
int stack[100];
int top = -1;

void push(int state) {
    stack[++top] = state;
}

int pop() {
    return stack[top--];
}

int main() {
    char input[] = "ab*c$"; // Input string
    int input_len = strlen(input);
    int curr = 0; // Current index in input string
    push(0); // Push initial state

    printf("Stack\t\tInput\t\tAction\n");
    printf("-----\t\t-----\t\t------\n");

    while (curr < input_len) {
        int state = stack[top];
        char symbol = input[curr];

        // Find column index for the symbol
        int symbol_index = -1;
        if (symbol == 'a') symbol_index = 0;
        else if (symbol == 'b') symbol_index = 1;
        else if (symbol == 'c') symbol_index = 2;
        else if (symbol == '$') symbol_index = 3;

        // Look up the parsing action from the table
        int action = parsing_table[state][symbol_index];

        // Print stack, input, and action
        printf(" ");
        for (int i = 0; i <= top; i++) {
            printf("%d", stack[i]);
        }
        printf("\t\t%s\t\t", &input[curr]);
        
        if (action == -1) {
            printf("Error: No action\n");
            break;
        } else if (action < 10) {
            printf("Shift %d\n", action);
            push(action);
            curr++;
        } else if (action >= 10) {
            printf("Reduce by %d\n", action);
            int num_pop = 2; // Default reduce size
            if (action == 10) num_pop = 1;
            for (int i = 0; i < num_pop; i++) pop();
            push(parsing_table[stack[top]][action - 10]);
        }
    }

    if (stack[top] == 2 && curr == input_len - 1) {
        printf("\nParsing successful!\n");
    } else {
        printf("\nParsing failed.\n");
    }

    return 0;
}
