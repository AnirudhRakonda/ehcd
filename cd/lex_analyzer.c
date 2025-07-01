#include <stdio.h>
#include <ctype.h>
#include <string.h>

void analyze(char input[]) {
    char token[100];
    int i = 0, j = 0;

    while (input[i]) {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        if (isdigit(input[i])) {
            token[j++] = input[i++];
            while (isdigit(input[i])) token[j++] = input[i++];
            token[j] = '\0';
            printf("Number: %s\n", token);
            j = 0;
            continue;
        }

        if (isalpha(input[i]) || input[i] == '_') {
            token[j++] = input[i++];
            while (isalnum(input[i]) || input[i] == '_') token[j++] = input[i++];
            token[j] = '\0';
            printf("Identifier/Keyword: %s\n", token);
            j = 0;
            continue;
        }

        if (strchr("+-*/=<>!&|", input[i])) {
            printf("Operator: %c\n", input[i++]);
            continue;
        }

        printf("Unknown character: %c\n", input[i++]);
    }
}
int main() {
    char input[100];
    printf("Enter source code: ");
    fgets(input, sizeof(input), stdin);
    analyze(input);
    return 0;
}