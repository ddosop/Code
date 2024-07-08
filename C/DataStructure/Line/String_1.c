#include<stdio.h>
#include<string.h>


void lengthOfLongestSubstring(char* s) {
   if(s[0]!=s[1]){
    printf("%d", 1);
   }else{
    printf("%d", 2);
   }
    
}


int main(){
    char S[] = "aacabcbc";

    lengthOfLongestSubstring(S);

}