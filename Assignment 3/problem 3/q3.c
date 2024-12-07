#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

int validateEmail(char*);

int main(){
    char temp_email[128];
    printf("Enter Email: ");
    scanf(" %s", &temp_email);
    for (int i = 0; temp_email[i] != '\0'; i++){
        size++;
    }

    char* email = malloc(sizeof(char)*size);
    strcpy(email, temp_email);

    if (validateEmail(temp_email)){
        printf("Valid Email\n");
    }
    else{
        printf("Invalid Email\n");
    }
    free (email);

    return 0;
}


int validateEmail(char* email){
    if (size > 0){
        int flag1 = 0, flag2 = 0, index1, index2;
        for (int i = 0; i < size; i++){
            if (email[i] == '@'){
                if (flag1 == 0){
                    flag1 = 1;
                    index1 = i;
                }
                else{
                    return 0;
                }
            }
            if (email[i] == '.'){
                index2 = i;
                flag2 = 1;
            }
        }
        if (index1 < index2 && flag2 == 1 && flag1 == 1){
            return 1;
        }
        return 0;
    }
    return 0;
}
