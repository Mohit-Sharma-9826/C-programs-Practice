#include <stdio.h>
#include <string.h>

int coun(char *str, char ch){
    int i=0, count=0;
    while(str[i] != '\0'){
        if(str[i] == ch){
            count++;
        }
        i++;
    }
    return count;
}

int main(){
    char ch;
    char str[20] = "Hello World";
    printf("Enter the charcter you want to count: ");
    scanf("%c", &ch);

    printf("It appears %d times \n", coun(str, ch));
    
    return 0;
}