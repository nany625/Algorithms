#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char *pattern, int len, int *LPS) {
    int i = 1, length = 0;
    LPS[0] = 0;
    while(i < len) {
        if(pattern[i] == pattern[length])
            LPS[i++] = ++length;
        else {
            if(length != 0)
                length = LPS[length - 1];
            else
                LPS[i++] = 0;
        }
    }
}

void KMPSearch(char *text, char *pattern) {
    int textLen = strlen(text), patternLen = strlen(pattern);
    int LPS[patternLen];
    computeLPSArray(pattern, patternLen, LPS);
    int i = 0, j = 0;
    while(i < textLen) {
        if(pattern[j] == text[i]) {
            ++i;
            ++j;
        }
        if(j == patternLen) {
            printf("Pattern found at index %d.\n", i - j);
            j = LPS[j - 1];
        } else if(i < textLen && pattern[j] != text[i]) {
            if(j != 0)
                j = LPS[j - 1];
            else
                ++i;
        }
    }
}

int main() {
    char *text = NULL, *pattern = NULL;
    while(scanf("%ms %ms", &text, &pattern) == 2) {
        KMPSearch(text, pattern);
        free(text);
        free(pattern);
        text = pattern = NULL;
    }
    return 0;
}
