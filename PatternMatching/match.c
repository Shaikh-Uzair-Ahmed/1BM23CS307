#include <stdio.h>
#include <string.h>

void searchPattern(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100], pattern[100];
    
    printf("Enter the text: ");
    gets(text);  // Using gets for simplicity; use fgets in production code
    printf("Enter the pattern: ");
    gets(pattern);
    
    searchPattern(text, pattern);

    return 0;
}
