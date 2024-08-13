#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_OF_CHARS 256

void badCharHeuristic(char *pattern, int len, int *badchar) {
    for(int i = 0; i < NO_OF_CHARS; ++i)
        badchar[i] = -1;
    for(int i = 0; i < len; ++i)
        badchar[(int)pattern[i]] = i;
}

void BoyerMooreSearch(char *text, char *pattern) {
    int textLen = strlen(text), patternLen = strlen(pattern);
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pattern, patternLen, badchar);
    int s = 0;
    while(s <= textLen - patternLen) {
        int i = patternLen - 1;
        while(i >= 0 && pattern[i] == text[s + i])
            --i;
        if(i < 0) {
            printf("Pattern found at index %d\n", s);
            s += (s < textLen - patternLen) ? patternLen - badchar[(int)text[s + patternLen]] : 1;
        } else
            s += (1 > i - badchar[(int)text[s + i]]) ? 1 : i - badchar[(int)text[s + i]];
    }
}

int main() {
    char *text = NULL, *pattern = NULL;
    while(scanf("%ms %ms", &text, &pattern) == 2) {
        BoyerMooreSearch(text, pattern);
        free(text);
        free(pattern);
        text = pattern = NULL;
    }
    return 0;
}
