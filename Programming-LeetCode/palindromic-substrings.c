#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int countSubstrings(char* s) {
    
    unsigned long n = strlen(s);
    
    int i,length,end,start;
    
    
    bool **isPalindrome = (bool **)calloc(n, sizeof(bool *));
    for (i=0; i<n; i++)
        isPalindrome[i] = (bool *)calloc(n, sizeof(bool));
    
    int **palindromeNumber = (int **)calloc(n, sizeof(int *));
    for (i=0; i<n; i++)
        palindromeNumber[i] = (int *)calloc(n, sizeof(int));
    
    // fill for substring of length 1.
    for(i=0;i<n;i++){
        isPalindrome[i][i]=true;
        palindromeNumber[i][i]=1;
    }
    
    // substring of length 2
    for(i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            isPalindrome[i][i+1]=true;
            palindromeNumber[i][i+1]=3;
        } else{
            palindromeNumber[i][i+1]=2;
        }
    }
    
    // Other substrings
    for(length=2;length<n;length++){
        for(start=0;start<n-length;start++){
            end=start+length;
            
            // Check for Palindrome
            if(s[start] == s[end] && isPalindrome[start+1][end-1]==true){
                isPalindrome[start][end]=1;
                palindromeNumber[start][end]=palindromeNumber[start+1][end] + palindromeNumber[start][end-1] + 1 - palindromeNumber[start+1][end-1];
                
            } else{
                palindromeNumber[start][end]=palindromeNumber[start+1][end] + palindromeNumber[start][end-1] - palindromeNumber[start+1][end-1];
            }
        }
    }
    return palindromeNumber[0][n-1];
}
