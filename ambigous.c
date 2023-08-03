#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isAmbiguous(char *input) {
	int i;
    int n = strlen(input);
    int a_count = 0;
    int b_count = 0;
    bool a_found = false;
    bool b_found = false;
    for(i = 0; i < n; i++) {
        if (input[i] == 'a') {
            a_found = true;
            a_count++;
        } else if (input[i] == 'b') {
            b_found = true;
            b_count++;
        } else {
            return false; 
        }
        if (b_found && a_count > b_count) {
            return true;
        }
    }
    return a_found && a_count != b_count;
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    if (isAmbiguous(input)) {
        printf("The grammar is ambiguous for the input string.\n");
    } else {
        printf("The grammar is not ambiguous for the input string.\n");
    }

    return 0;
}

