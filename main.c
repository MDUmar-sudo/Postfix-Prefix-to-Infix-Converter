#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define repeat(n) for(int i=0;i<n;i++)
#define max 100

typedef struct Node s;

//Using doubly linked list to perform Postfix/Prefix to Infix conversion

struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
}*stack[max];
int top=max;


//return stack status: Empty or Not

int isEmpty(){

    if(top>=100) return 1;

    return 0;
}

//return stack status: Full or Not

int isFull(){

    if(top<=0) return 1;

    return 0;
}

//push() function append an element at the top most position in the stack

void push(s* x)
{
    if(isFull())
    {
        printf("\nSTACK FULL\n");
    }
    else
    {
        stack[top--]=x;
    }

}

//pop() function deletes the top most element in the stack

s* pop()
{
    s* temp;
    if(isEmpty())
    {
        printf("\nSTACK EMPTY\n");
    }
    else
    {
        temp = stack[++top];
    }
    return temp;
}

//display all the element in the stack

void display(s *temp)
{
    if(temp==NULL) {
        return;
    }
    else
    {
            display(temp->prev);
            printf("%c",temp->data);
            display(temp->next);
    }

}

void PostfixToInfix();
void PrefixTOInfix();
void enterExpression();


int main()
{
	char exp[max];

    int choice;
    printf("\n");
	repeat(50)
    printf("-");
    printf("\nCHOOSE AN INPUT TYPE\n\n(1)POSTFIX EXPRESSION\n\n(2)PREFIX EXPRESSION\n");
    printf("\n");
	repeat(50)
    printf("-");
    printf("\n\nCHOOSE AN OPTION : ");
    scanf("%d",&choice);
    printf("\n");

    switch(choice){
        case 1: {
                    enterExpression(&exp,1);
                    PostfixToInfix(exp);
                    printf("\nINFIX EXPRESSION : ");
                    display(pop());
                    printf("\n");
                    repeat(50)
                    printf("*");
                    printf("\n\n");
                    break;

                }

        case 2: {
                    enterExpression(&exp,2);
                    PrefixToInfix(exp);
                    printf("\nINFIX EXPRESSION : ");
                    display(pop());
                    printf("\n");
                    repeat(50)
                    printf("*");
                    printf("\n\n");
                    break;


                }
        default: printf("WRONG OPTION!!!");
                 exit(0);

    }



    getchar();
	return 0;

}

//enterExpression() function takes the user input expression

void enterExpression(char *exp[],int signal){
    printf("\n");
    repeat(50)
    printf("=");
    if(signal==1) printf("\nENTER POSTFIX EXPRESSION : ");
	else printf("\nENTER PREFIX EXPRESSION : ");
    scanf("%s",exp);
	printf("\n");
	repeat(50)
    printf("=");
}

//is_operator() checks if the given character is an operator or not

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	return 0;
}

//PostfixToInfix() converts postfix expression to infix

void PostfixToInfix(char exp[])
{
    s *opd1,*opd2,*opr;
    for(int i;i<strlen(exp);i++)
    {
        if (is_operator(exp[i]))
        {
           opr = (s *)malloc(sizeof(s));
           opd1 = pop();
           opd2 = pop();
           opr->data = exp[i];
           opr->next = opd1;
           opr->prev = opd2;
           push(opr);
        }

        else
        {
           opr = (s *)malloc(sizeof(s));
           opr->data = exp[i];
           opr->next = NULL;
           opr->prev = NULL;
           push(opr);
        }
    }

}

//PrefixToInfix() converts prefix expression to infix

void PrefixToInfix(char exp[])
{

    s *opd1,*opd2,*opr;
    for(int i=strlen(exp)-1;i>=0;i--) //for the prefix to infix conversion array is traversed from the end
    {
        if (is_operator(exp[i]))
        {
           opr = (s *)malloc(sizeof(s));
           opd1 = pop();
           opd2 = pop();
           opr->data = exp[i];
           opr->next = opd2;
           opr->prev = opd1;
           push(opr);
        }

        else
        {
           opr = (s *)malloc(sizeof(s));
           opr->data = exp[i];
           opr->next = NULL;
           opr->prev = NULL;
           push(opr);
        }
    }

}
