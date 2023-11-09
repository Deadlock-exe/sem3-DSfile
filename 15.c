#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n1 100
char operatorStack[n1];
#define n2 100
char numberStack[n2];

char infix[n1];
char postfix[n2];

int operatorTop = -1;
int numberTop = -1;

// infix to postfix

void operatorPush(char c){
    if(operatorTop == n1-1){
        printf("Stack overflow");
    }
    else{
        operatorTop++;
        operatorStack[operatorTop] = c;
    }
}

char operatorPop(){
    if(operatorTop == -1){
        printf("Stack underflow");
        exit(1);
    }
    char operatorPopped;
    operatorPopped = operatorStack[operatorTop];
    operatorTop--;
    return operatorPopped;
}

int operatorPrecedence(char c){
    switch (c)
    {
    case '/':
        return 4;
    case '*':
        return 3;
    case '+':
        return 2;
    case '-':
        return 1;
        
    default:
        return 0;
    }
}

int isEmpty(){
    if(operatorTop == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void printData()
{
    int i = 0;
    printf("Postfix Expression: ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void toPost(){
    char present;
    int j=0;
    for(int i=0; i<strlen(infix); i++){
        present = infix[i];
        switch (present)
        {
        case '*':
        case '/':
        case '-':
        case '+':
            while(operatorPrecedence(present) <= operatorPrecedence(operatorStack[operatorTop])){
                postfix[j] = operatorPop();
                j++;
            }
            operatorPush(present);
            break;
        
        default:
            postfix[j] = present;
            j++;
            break;
        }
    }
        while (!isEmpty())
        postfix[j++] = operatorPop();
    postfix[j] = '\0';
}

// postfix evaluation


void numberPush(char c){
    if(numberTop == n1-1){
        printf("Stack overflow");
    }
    else{
        numberTop++;
        numberStack[numberTop] = c;
    }
}

char numberPop(){
    if(numberTop == -1){
        printf("Stack underflow");
        exit(1);
    }
    char numberPopped;
    numberPopped = numberStack[numberTop];
    numberTop--;
    return numberPopped;
}

void postEval(){
    int temp, temp1, temp2;
    for(int i=0; i<strlen(postfix); i++){
        char present;
        present = postfix[i];
        switch (present)
        {
        case '+':
            temp2 = numberPop() - '0';
            temp1 = numberPop() - '0';
            temp = temp1 + temp2;
            numberPush(temp + '0');
            break;
        
        case '-':
            temp2 = numberPop() - '0';
            temp1 = numberPop() - '0';
            temp = temp1 - temp2;
            numberPush(temp + '0');
            break;
        
        case '*':
            temp2 = numberPop() - '0';
            temp1 = numberPop() - '0';
            temp = temp1 * temp2;
            numberPush(temp + '0');
            break;
        
        case '/':
            temp2 = numberPop() - '0';
            temp1 = numberPop() - '0';
            temp = temp1 / temp2;
            numberPush(temp + '0');
            break;
        
        default:
            numberPush(present);
            break;
        }
    }
    if (numberTop != 0) {
        printf("Invalid postfix expression\n");
        exit(1);
    }
    printf("Postfix Evaluation gives: %d\n", numberStack[numberTop] - '0');
}

int main(){
    printf("Enter the infix expression: ");
    gets(infix);
    toPost();
    printData();
    postEval();
}