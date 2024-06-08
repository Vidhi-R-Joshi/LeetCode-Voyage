bool isPrefix(char *prefix, char *word) {
    while (*prefix && *word) {
        if (*prefix != *word) return false;
        prefix++;
        word++;
    }
    return *prefix == '\0';
}
char* replaceWords(char** dictionary, int dictionarySize, char* sentence) {
    char *result = malloc(strlen(sentence) + 1);
    result[0] = '\0';

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        char *prefix = word;
        for (int i = 0; i < dictionarySize; i++) {
            if (isPrefix(dictionary[i], word)) {
                if (strlen(dictionary[i]) < strlen(prefix)) {
                    prefix = dictionary[i];
                }
            }
        }
        if (strlen(result) > 0) {
            strcat(result, " ");
        }
        strcat(result, prefix);
        word = strtok(NULL, " ");
    }

    return result;
}