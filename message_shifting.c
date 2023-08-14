#include <stdio.h>
#include <ctype.h>

int main() {
    int shift;
    char message[100], ch;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ((ch - 65 + shift) % 26) + 65;
        }

        message[i] = ch;
    }

    printf("Encrypted message: %s", message);

    return 0;
}
