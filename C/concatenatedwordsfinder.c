#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isConcatenatedWord(char *word, char **wordList, int wordListSize) {
    if (word == NULL || wordList == NULL || wordListSize <= 1) return 0;

    int wordLength = strlen(word);
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(word, wordList[i]) == 0) continue;
        int wordListLength = strlen(wordList[i]);
        if (wordLength >= wordListLength) continue;

        int j = 0;
        int k = 0;
        while (j < wordLength) {
            if (word[j] == wordList[i][k]) {
                j++;
                k++;
            } else {
                k++;
            }
            if (k == wordListLength) {
                break;
            }
        }
        if (j == wordLength) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int wordListSize;
    printf("Enter the number of words in the list: ");
    scanf("%d", &wordListSize);

    char **wordList = (char **)malloc(wordListSize * sizeof(char *));
    for (int i = 0; i < wordListSize; i++) {
        printf("Enter word %d: ", i + 1);
        char word[100];
        scanf("%s", word);
        wordList[i] = (char *)malloc(strlen(word) + 1);
        strcpy(wordList[i], word);
    }

    printf("Concatenated words in the list:\n");
    for (int i = 0; i < wordListSize; i++) {
        if (isConcatenatedWord(wordList[i], wordList, wordListSize)) {
            printf("%s\n", wordList[i]);
        }
    }

    // Free allocated memory
    for (int i = 0; i < wordListSize; i++) {
        free(wordList[i]);
    }
    free(wordList);

    return 0;
}
