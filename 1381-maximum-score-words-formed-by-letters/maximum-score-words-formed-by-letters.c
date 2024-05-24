#define MAX_WORDS 14
#define MAX_WORD_LEN 15
#define MAX_LETTERS 100
#define LETTERS_LEN 26

int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize,
                  int* score, int scoreSize) {
    int letterScores[LETTERS_LEN];
    memset(letterScores, 0, sizeof(letterScores));
    for (int i = 0; i < LETTERS_LEN; i++) {
        letterScores[i] = score[i];
    }

    int letterCount[LETTERS_LEN];
    memset(letterCount, 0, sizeof(letterCount));
    for (int i = 0; i < lettersSize; i++) {
        letterCount[letters[i] - 'a']++;
    }

    int wordScore(char* word) {
        int score = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            score += letterScores[word[i] - 'a'];
        }
        return score;
    }

    int backtrack(char** words, int wordsSize, int* letterCount, int idx) {
        if (idx == wordsSize) {
            return 0;
        }

        int wordLen = strlen(words[idx]);
        int temp[LETTERS_LEN];
        memcpy(temp, letterCount, sizeof(temp));
        for (int i = 0; i < wordLen; i++) {
            if (temp[words[idx][i] - 'a'] == 0) {
                return backtrack(words, wordsSize, letterCount, idx + 1);
            }
            temp[words[idx][i] - 'a']--;
        }

        int scoreWithWord =
            wordScore(words[idx]) + backtrack(words, wordsSize, temp, idx + 1);

        int scoreWithoutWord =
            backtrack(words, wordsSize, letterCount, idx + 1);

        return scoreWithWord > scoreWithoutWord ? scoreWithWord
                                                : scoreWithoutWord;
    }

    return backtrack(words, wordsSize, letterCount, 0);
}