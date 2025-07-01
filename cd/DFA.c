#include <stdio.h>

int isAccepted(char str[]) {
    int countA = 0, countB = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'a') {
            countA = (countA + 1) % 3;
        } else if (str[i] == 'b') {
            countB = (countB + 1) % 2;
        } else {
            return 0; // Invalid character
        }
        i++;
    }

    return (countA == 0 && countB == 0);
}

int main() {
    char input[100];

    printf("Enter input string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("Accepted: The number of 'a's is divisible by 3 and 'b's by 2.\n");
    } else {
        printf("Rejected: Condition not met.\n");
    }

    return 0;
}

