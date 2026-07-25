#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a) {
    for(int i = 1; i < 26; i++)
        if((a * i) % 26 == 1)
            return i;
    return -1;
}

int main() {
    char text[100];
    int a, b;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    if(modInverse(a) == -1) {
        printf("Invalid value of a");
        return 0;
    }

    printf("Encrypted Text: ");

    for(int i = 0; text[i] != '\0'; i++) {
        int p = toupper(text[i]) - 'A';
        printf("%c", ((a * p + b) % 26) + 'A');
    }

    return 0;
}