#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversion.h"

#define MAX 100

int main() {
    int choice;
    char expression[MAX], result[MAX];
    
    while (1) {
        printf("\nKonversi Ekspresi Aritmatika\n");
        printf("1. Infix ke Postfix\n");
        printf("2. Postfix ke Infix\n");
        printf("3. Infix ke Prefix\n");
        printf("4. Prefix ke Infix\n");
        printf("5. Prefix ke Postfix\n");
        printf("6. Postfix ke Prefix\n");
        printf("7. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice == 7) {
            printf("Program selesai.\n");
            break;
        }
        
        printf("Masukkan ekspresi: ");
        fgets(expression, MAX, stdin);
        expression[strcspn(expression, "\n")] = '\0';
        
        switch (choice) {
            case 1: infixToPostfix(expression, result); break;
            case 2: postfixToInfix(expression, result); break;
            case 3: infixToPrefix(expression, result); break;
            case 4: prefixToInfix(expression, result); break;
            case 5: prefixToPostfix(expression, result); break;
            case 6: postfixToPrefix(expression, result); break;
            default: printf("Pilihan tidak valid!\n"); continue;
        }
        
        printf("Hasil konversi: %s\n", result);
    }
    
    return 0;
}