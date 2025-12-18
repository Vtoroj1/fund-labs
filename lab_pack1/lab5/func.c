#include "func.h"

bool isLetter(const char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

ErrorCode nameCheck(const char *name) {
    if (name == NULL) {
        return ERROR_NULL_POINTER;
    }
    const char *fileTypes[] = {".txt", ".docx", "doc", "rtf", ".c", ".h", ".cpp", ".hpp", ".java", ".py", ".csv", ".json", ".xml", ".html", ".css", ".js", ".md", ".log", ".conf", ".config", NULL};

    char *split = strrchr(name, '.');

    if (split == NULL) {
        return ERROR_NO_FILE_TYPE;
    }

    for (int i = 0; fileTypes[i] != NULL; i++) {
        if (strcmp(split, fileTypes[i]) == 0) {
            return SUCCESS;
        }
    }

    return UNKNOWN_FILE_TYPE;
}

ErrorCode noDigit(FILE *input, FILE *output) { //d
    if (input == NULL || output == NULL) {
        return ERROR_NULL_POINTER;
    }

    int ch;

    while ((ch = fgetc(input)) != EOF) {
        unsigned char c = (unsigned char)ch;
        if (!isdigit(c)) {
            if (fputc(c, output) == EOF) {
                return ERROR_OUTPUT_FILE_ERROR;
            }
        }
    }

    return SUCCESS; 
}

ErrorCode letterCount(FILE *input, FILE *output) { //i
    if (input == NULL || output == NULL) {
        return ERROR_NULL_POINTER;
    }

    int ch;
    unsigned int count = 0;

    while ((ch = fgetc(input)) != EOF) {
        unsigned char c = (unsigned char)ch;
        if (c == '\n') {
            if (fprintf(output, "%d \n", count) <= 0) {
                return ERROR_OUTPUT_FILE_ERROR;
            }
            count = 0;
        } else if (isLetter(c)) {
            count++;
        }
    }

    if (count > 0) {
        if (fprintf(output, "%d \n", count) <= 0) {
            return ERROR_OUTPUT_FILE_ERROR;
        }
    }

    return SUCCESS;
}

ErrorCode otherCount(FILE *input, FILE *output) { //s
    if (input == NULL || output == NULL) {
        return ERROR_NULL_POINTER;
    }

    int ch;
    unsigned int count = 0;

    while ((ch = fgetc(input)) != EOF) {
        unsigned char c = (unsigned char)ch;
        if (c == '\n') {
            if (fprintf(output, "%d \n", count) <= 0) {
                return ERROR_OUTPUT_FILE_ERROR;
            }
            count = 0;
        } else if (!isLetter(c) && !isdigit(c) && !isspace(c)) {
            count++;
        }
    }

    if (count > 0) {
        if (fprintf(output, "%d \n", count) <= 0) {
            return ERROR_OUTPUT_FILE_ERROR;
        }
    }

    return SUCCESS;
}

ErrorCode letterHex(FILE *input, FILE *output) { //a
    if (input == NULL || output == NULL) {
        return ERROR_NULL_POINTER;
    }

    int ch;

    while ((ch = fgetc(input)) != EOF) {
        unsigned char c = (unsigned char)ch;

        if (isdigit(c) || c == '\n') {
            fputc(c, output);

        } else {
            int firstDigit = c / 16;
            int secondDigit = c % 16;

            char firstChar = firstDigit < 10 ? '0' + firstDigit : 'A' + firstDigit - 10;
            char secondChar = secondDigit < 10 ? '0' + secondDigit : 'A' + secondDigit - 10;

            if (fputc(firstChar, output) == EOF || fputc(secondChar, output) == EOF) {
                return ERROR_OUTPUT_FILE_ERROR;
            }
        }        
    }

    return SUCCESS;
}