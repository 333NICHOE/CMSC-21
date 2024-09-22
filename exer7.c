#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

// function to check if a string is a palindrome 
int isPalindrome(char s[], int first, int last) {
    
    if (first == last) {
        return true;
    }

    if (s[first] != s[last]) {
        return false;
    }

    return isPalindrome(s, first + 1, last -1);
}

int main() {

    char str[1000];
    int first = 0;
    int last = strlen(str) - 1;
    printf("Enter a word: ");
    scanf("%s", str);

    bool answer = isPalindrome(str, first, last);

    if (answer) {
        printf("%s is a palindrome\n", str);
    }
    
    else {
        printf("%s is not a palindrome\n", str);
    }
    
    return 0;
}