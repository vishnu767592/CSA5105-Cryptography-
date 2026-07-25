#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[100], cipher[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter Plain Text: ");
    fgets(plain, sizeof(plain), stdin);

    for(i = 0; plain[i] != '\0'; i++) {
        if(isupper(plain[i]))
            cipher[i] = key[plain[i] - 'A'];
        else if(islower(plain[i]))
            cipher[i] = tolower(key[plain[i] - 'a']);
        else
            cipher[i] = plain[i];
    }

    cipher[i] = '\0';

    printf("Cipher Text: %s", cipher);

    return 0;
}