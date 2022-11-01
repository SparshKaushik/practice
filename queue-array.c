//linear queue using arrays
#include <stdio.h>
#define MAX 100

struct queue {
    int front;
    int arr[MAX];
    int rear;
};

typedef struct queue queue;

void enqueue(queue *q) {
    int x;
    if(q->rear==MAX-1){
        printf("Queue Overflow");
    }
    else{
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        if (q->front==-1){
            q->front=0;
        }
        q->rear++;
        q->arr[q->rear]=x;
    }
}

void dequeue(queue *q){
    if(q->front==-1){
        printf("Queue Underflow");
    }
    else{
        printf("The popped element is %d\n",q->arr[q->front]);
        q->front++;
    }
}

void display(queue *q){
    if(q->front==-1){
        printf("Queue is empty");
    }
    else{
        printf("Your Queue : ");
        for(int i=q->front; i<=q->rear; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void main(){
    printf("Linear Queue using arrays");
    queue *q;
    q->front = -1;
    q->rear = -1;
    int choice;
    while (choice!=4){
        printf("What to do ?\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice");
        }
    }
}