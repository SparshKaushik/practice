#include <stdio.h>
#define MAX 100
struct stack {
    int top;
    int arr[MAX];
};
typedef struct stack stack;

void push(struct stack *s) {
    int x;
    if(s->top==MAX-1){
        printf("Stack Overflow");
    }
    else{
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        s->top++;
        s->arr[s->top]=x;
    }
}

void pop(struct stack *s){
    if(s->top==-1){
        printf("Stack Underflow");
    }
    else{
        printf("The popped element is %d\n",s->arr[s->top]);
        s->top--;
    }
}

void display(struct stack *s){
    if(s->top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Your Stack : ");
        for(int i=0; i<=s->top; i++){
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

void main(){
    stack *s;
    s->top = -1;
    int choice;
    while (choice!=4){
        printf("What to do ?\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push(s);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("Exit Point ");
                break;
            default:
                printf("Please Enter a Valid Choice(1/2/3/4)");
        }
    }
}