#include <stdio.h>
#include <string.h>

char input[100];
int i = 0, l = 0;

int E();
int EP();
int T();
int TP();
int F();

int E() {
    if (T()) {
        if (EP())
            return 1;
    }
    return 0;
}

int EP() {
    if (input[i] == '+') {
        i++;
        if (T()) {
            if (EP())
                return 1;
        }
        return 0;
    }
    return 1;  // epsilon
}

int T() {
    if (F()) {
        if (TP())
            return 1;
    }
    return 0;
}

int TP() {
    if (input[i] == '*') {
        i++;
        if (F()) {
            if (TP())
                return 1;
        }
        return 0;
    }
    return 1;  // epsilon
}

int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            }
        }
        return 0;
    } else if (input[i] == 'i' && input[i + 1] == 'd') {
        i += 2;
        return 1;
    }
    return 0;
}

int main() {
    printf("The RDP grammar is:\n");
    printf("E  -> T EP\n");
    printf("EP -> + T EP | ε\n");
    printf("T  -> F TP\n");
    printf("TP -> * F TP | ε\n");
    printf("F  -> (E) | id\n");

    printf("\nEnter the string to be parsed: ");
    scanf("%s", input);

    i = 0;
    l = strlen(input);

    if (E() && input[i] == '\0') {
        printf("\nString is accepted\n");
    } else {
        printf("\nString is not accepted\n");
    }

    return 0;
}