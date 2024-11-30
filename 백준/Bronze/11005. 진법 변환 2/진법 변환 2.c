#include <stdio.h>
#include <string.h>
int main() {

    int input = 0;
    int numeric = 0 ;
    char result[100];
    scanf("%d", &input);
    scanf("%d", &numeric);


    int index = 0;
    while(input > 0) {
        int flag = input % numeric;
        if(flag >= 0 && flag <= 9){
            result[index++] = flag + '0';
        }else{
            result[index++] = flag + 'A' - 10;
        }
        input = input / numeric;
    }
    result[index] = '\0';
    
    int len = strlen(result);
    for (int i = strlen(result) - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }

    
    return 0;
}
