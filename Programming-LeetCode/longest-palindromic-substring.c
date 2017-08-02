#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

char* longestPalindrome(char* s) {
    
    unsigned long n = strlen(s);
    
    int i,length,end,start;
    
    bool **isPalindrome = (bool **)calloc(n, sizeof(bool *));
    for (i=0; i<n; i++)
        isPalindrome[i] = (bool *)calloc(n, sizeof(bool));
    
    int max_length = 1;
    int startIndex = 0;
    // fill for substring of length 1.
    for(i=0;i<n;i++){
        isPalindrome[i][i]=true;
    }
    
    // substring of length 2
    for(i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            isPalindrome[i][i+1]=true;
            max_length=2;
            startIndex = i;
        }
    }
    
    // Other substrings
    for(length=2;length<n;length++){
        for(start=0;start<n-length;start++){
            end=start+length;
            
            // Check for Palindrome
            if(s[start] == s[end] && isPalindrome[start+1][end-1]==true){
                isPalindrome[start][end]=1;
                max_length = length+1;
                startIndex = start;
            }
        }
    }
    
    char* ans = (char*)malloc(max_length+1);
    memcpy(ans,s+startIndex,max_length);
    return ans;
}
