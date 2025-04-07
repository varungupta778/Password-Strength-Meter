/*
 * COP 3515 – Fall Semester 2024
 *
 * Homework #1: Password Strength Meter
 * Main code
 *
 * Varun Gupta
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Settings
int maxPasswordLength;
int minPasswordLength;
int allowPassPhrases;
int minPassPhraseLength;
int requireOptionalTests;
int minOptionalTestsToPass;

// All Functions
int checkRequiredTests(char password[]);
int checkOptionalTests(char password[], int* optionalPassed);
int hasRepeatedCharacters(char password[]);
int hasLettersNumbersSymbols(char password[]);
int isPassPhrase(char password[]);
void printTestResults(char password[], int strongPassword, int optionalPassed);
void configureSettings(int maxLen, int minLen, int allowPass, int minPassLen, int optTests, int minOptTests);

int main() {
    // Test Case 1
    configureSettings(15, 10, 1, 20, 1, 4);
    char passwords1[6][256] = {
        "my pass phrase does not need to pass tests",
        "short pass phrase",
        "x",
        "x1",
        "Zxcvbnmnas7",
        "Zxcvbnmnas7~"
    };
    
    printf("Processing Test Case 1:\n");
    for (int i = 0; i < 6; i++) {
        printf("Processing password #%d: %s\n", i + 1, passwords1[i]);
        int isStrong = checkRequiredTests(passwords1[i]);
        int optionalPassed = 0;
        
        if (requireOptionalTests) {
            isStrong = isStrong && checkOptionalTests(passwords1[i], &optionalPassed);
        }
        
        printTestResults(passwords1[i], isStrong, optionalPassed);
    }

    // Test Case 2
    configureSettings(15, 10, 1, 20, 1, 2);
    char passwords2[10][256] = {
        "This is my password phrase1",
        "Tinypw1",
        "Ireallydontlikehavingtomakeupnewpasswordsallthetime1",
        "Iloveyouxxxooo1",
        "Boom*********!",
        "IHATEPWORDS1!",
        "ihatepwords1!",
        "IHatePw0rds!",
        "IHatePw0rds",
        "Just exactly how many words can you include in a password phrase?"
    };

    printf("Processing Test Case 2:\n");
    for (int i = 0; i < 10; i++) {
        printf("Processing password #%d: %s\n", i + 1, passwords2[i]);
        int isStrong = checkRequiredTests(passwords2[i]);
        int optionalPassed = 0;
        
        if (requireOptionalTests) {
            isStrong = isStrong && checkOptionalTests(passwords2[i], &optionalPassed);
        }
        
        printTestResults(passwords2[i], isStrong, optionalPassed);
    }

    // Test Case 3
    configureSettings(12, 10, 0, 0, 0, 0);
    char passwords3[4][256] = {
        "password",
        "mypassword",
        "thisismypassword",
        "passssword"
    };

    printf("Processing Test Case 3:\n");
    for (int i = 0; i < 4; i++) {
        printf("Processing password #%d: %s\n", i + 1, passwords3[i]);
        int isStrong = checkRequiredTests(passwords3[i]);
        int optionalPassed = 0;
        
        if (requireOptionalTests) {
            isStrong = isStrong && checkOptionalTests(passwords3[i], &optionalPassed);
        }
        
        printTestResults(passwords3[i], isStrong, optionalPassed);
    }

    return 0;  
}


void configureSettings(int maxLen, int minLen, int allowPass, int minPassLen, int optTests, int minOptTests) {
    maxPasswordLength = maxLen;
    minPasswordLength = minLen;
    allowPassPhrases = allowPass;
    minPassPhraseLength = minPassLen;
    requireOptionalTests = optTests;
    minOptionalTestsToPass = minOptTests;
}


int checkRequiredTests(char password[]) {
    int length = strlen(password);

    // For min length
    if (length < minPasswordLength) {
        printf("The password must be at least %d characters long.\n", minPasswordLength);
        return 0; // false
    }

    // For max length
    if (length > maxPasswordLength) {
        printf("The password must be fewer than %d characters.\n", maxPasswordLength);
        return 0; // false
    }

    // This is to check for repeated characters
    if (hasRepeatedCharacters(password)) {
        printf("The password may not contain sequences of three or more repeated characters.\n");
        return 0; // false
    }

    // This is to check for letters, numbers, and symbols
    if (!hasLettersNumbersSymbols(password)) {
        printf("The password must contain letters, numbers, AND symbols.\n");
        return 0;
    }

    return 1;
}


int checkOptionalTests(char password[], int* optionalPassed) {
    int hasLower = 0, hasUpper = 0, hasTwoDigits = 0, hasTwoSpecial = 0;
    int digitCount = 0, specialCount = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) hasLower = 1;
        if (isupper(password[i])) hasUpper = 1;
        if (isdigit(password[i])) digitCount++;
        if (!isalnum(password[i])) specialCount++;
    }

    if (digitCount >= 2) hasTwoDigits = 1;
    if (specialCount >= 2) hasTwoSpecial = 1;

    *optionalPassed = hasLower + hasUpper + hasTwoDigits + hasTwoSpecial;

    if (*optionalPassed >= minOptionalTestsToPass) {
        return 1; 
    } else {
        if (!hasLower) printf("The password must contain at least one lowercase letter.\n");
        if (!hasUpper) printf("The password must contain at least one uppercase letter.\n");
        if (!hasTwoDigits) printf("The password must contain at least two digits.\n");
        if (!hasTwoSpecial) printf("The password must contain at least two special characters.\n");
        return 0;
    }
}


int hasRepeatedCharacters(char password[]) {
    for (int i = 0; password[i + 2] != '\0'; i++) {
        if (password[i] == password[i + 1] && password[i] == password[i + 2]) {
            return 1;
        }
    }
    return 0;
}


int hasLettersNumbersSymbols(char password[]) {
    int hasLetter = 0, hasNumber = 0, hasSymbol = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isalpha(password[i])) hasLetter = 1;
        if (isdigit(password[i])) hasNumber = 1;
        if (!isalnum(password[i])) hasSymbol = 1;
    }

    return hasLetter && hasNumber && hasSymbol;
}


void printTestResults(char password[], int strongPassword, int optionalPassed) {
    printf("Password: %s\n", password);
    printf("Strong: %s\n", strongPassword ? "Yes" : "No");
    printf("Total optional tests passed: %d\n", optionalPassed);
    printf("------------------------------\n");
}
