#include <stdio.h>
#include <string.h>

#define MAX 256

void rearrangeString(char s[]) {
    int freq[MAX] = {0};
    int len = strlen(s);

   
    for (int i = 0; i < len; i++)
        freq[s[i]]++;

    
    int maxFreq = 0, maxChar = 0;
    for (int i = 0; i < MAX; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = i;
        }
    }

   
    if (maxFreq > (len + 1) / 2) {
        printf("0\n");
        return;
    }

   
    char result[len + 1];
    int index = 0;


    while (freq[maxChar] > 0) {
        result[index] = maxChar;
        index += 2;
        freq[maxChar]--;
    }


    for (int i = 0; i < MAX; i++) {
        while (freq[i] > 0) {
            if (index >= len)
                index = 1;  
            result[index] = i;
            index += 2;
            freq[i]--;
        }
    }

    result[len] = '\0';  
    printf("1\n"); 
}

int main() {
    char s[100];
    scanf("%s", s);
    rearrangeString(s);
    return 0;
}
