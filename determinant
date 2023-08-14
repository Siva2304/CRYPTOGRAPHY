#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int determinant(int a, int b, int c, int d) {
    return a*d - b*c;
}

int modInv(int a) {
    a %= 26;
    for (int x = 1; x < 26; x++) {
        if ((a*x) % 26 == 1)
            return x;
    }
    return -1;
}

void hillCipherEncrypt(char* plaintext, int key[][2], int len) {

    for (int i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            plaintext[i] = plaintext[i] - 'a' + 'A';
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            plaintext[j++] = plaintext[i];
    }
    plaintext[j] = '\0';
    len = j;

    if (len % 2 != 0) {
        plaintext[len] = 'X';
        plaintext[len+1] = '\0';
        len++;
    }

    for (int i = 0; i < len; i += 2) {
        int p1 = plaintext[i] - 'A';
        int p2 = plaintext[i+1] - 'A';
        int c1 = (key[0][0]*p1 + key[0][1]*p2) % 26;
        int c2 = (key[1][0]*p1 + key[1][1]*p2) % 26;
        plaintext[i] = c1 + 'A';
        plaintext[i+1] = c2 + 'A';
    }
}

int main() {
   
    int key[2][2] = {{9, 4}, {5, 7}};

    char plaintext[] = "meet me at the usual place at ten rather than eight oclock";
    int len = strlen(plaintext);

    hillCipherEncrypt(plaintext, key, len);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
