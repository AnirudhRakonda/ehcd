#include<stdio.h>
#include<string.h>

char input[100];
int i, l;

int S();
int L();
int LP();

int main() {
    printf("\n The RDP grammar is\n");
    printf("\n S -> (L)\n S -> a\n L -> L , S\n L -> S");

    printf("\n Enter the string to be parsed: ");
    scanf("%s", input);

    i = 0;
    l = strlen(input);

    if (S()) {
        if (input[i] == '\0') {
            printf("\nString is accepted");
        } else {
            printf("\nString is not accepted");
        }
    } else {
        printf("\nString is rejected");
    }

    return 0;
}

int S() {
    if (input[i] == '(') {
        i++;
        if (L()) {
            if (input[i] == ')') {
                i++;
                return 1;
            }
        }
        return 0;
    }
    else if (input[i] == 'a') {
        i++;
        return 1;
    }
    return 0;
}

int L() {
    if (S()) {
        if (LP()) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int LP() {
    if (input[i] == ',') {
        i++;
        if (S()) {
            if (LP()) {
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 1;  // epsilon
}