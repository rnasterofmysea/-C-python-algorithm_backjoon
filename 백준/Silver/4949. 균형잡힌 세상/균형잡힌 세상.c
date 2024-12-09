#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char *input = NULL;
    size_t buffer_size = 0;
    int len = 0;
    int top = -1;
    while(1){
        getline(&input, &buffer_size, stdin);

        if(input[0] =='.'){break;}
        len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';}
        
        int *stack = (int*)malloc((len-1) * sizeof(int));
        for(int i = 0; i < len; i++){
            if(input[i] == '('){
                stack[++top] = '(';
                //printf("SUCCESS1 %d %c \n", top, stack[top]);
            } else if(input[i] == '['){
                stack[++top] = '[';
                //("SUCCESS2 %d %c \n", top, stack[top]);
            } else if(input[i] == ')'){
                if(stack[top] == '('){
                    stack[top] = '\0';
                    top -=1 ;
                } else{
                    top = -2;
                    break;
                }
            } else if(input[i] ==']'){
                if(stack[top] == '['){
                    stack[top] = '\0';
                    top --;
                } else{
                    top = -2;
                    break;
                }
            }
        }
            top == -1 ? printf("yes\n") : printf("no\n");
            top = -1;
            free(stack);
    }

    free(input);
    return 0;
}