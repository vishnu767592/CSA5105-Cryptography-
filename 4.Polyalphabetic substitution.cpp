#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter Plain Text: ");
    scanf("%s", text);

    printf("Enter Key: ");
    scanf("%s", key);

    int keyLen = strlen(key);

    printf("Encrypted Text: ");

    for(i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);
        int shift = toupper(key[j % keyLen]) - 'A';
        printf("%c", ((ch - 'A' + shift) % 26) + 'A');
        j++;
    }

    return 0;
}