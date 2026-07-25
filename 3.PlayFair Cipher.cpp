#include <stdio.h>
#include <string.h>

char matrix[5][5] = {
    {'M','O','N','A','R'},
    {'C','H','Y','B','D'},
    {'E','F','G','I','K'},
    {'L','P','Q','S','T'},
    {'U','V','W','X','Z'}
};

void findPos(char ch, int *r, int *c) {
    if(ch == 'J')
        ch = 'I';

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(matrix[i][j] == ch) {
                *r = i;
                *c = j;
                return;
            }
}

int main() {
    char text[100];

    printf("Enter Plaintext: ");
    scanf("%s", text);

    int len = strlen(text);

    printf("Cipher Text: ");

    for(int i = 0; i < len; i += 2) {
        char a = text[i];
        char b = (i + 1 < len) ? text[i + 1] : 'X';

        int r1, c1, r2, c2;

        findPos(a, &r1, &c1);
        findPos(b, &r2, &c2);

        if(r1 == r2)
            printf("%c%c", matrix[r1][(c1 + 1) % 5], matrix[r2][(c2 + 1) % 5]);
        else if(c1 == c2)
            printf("%c%c", matrix[(r1 + 1) % 5][c1], matrix[(r2 + 1) % 5][c2]);
        else
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
    }

    return 0;
}