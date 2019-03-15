#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#define MAX 10

typedef struct dequeue
{
    int data[MAX];
    int last, first;
}dequeue;


void init(dequeue *P)
{
    P->last=-1;
    P->first=-1;
}

void Insert(dequeue *P,int x)
{
        P->last=(P->last+1)%MAX;
        P->data[P->last]=x;
}

void InsertFirst(dequeue *P,int x)
{
        P->first=(P->first-1+MAX)%MAX;
        P->data[P->first]=x;
}

int DeleteLast(dequeue *P)
{
    int x;

    x=P->data[P->first];

    if(P->last==P->first)	//delete the last element
        init(P);
    else
        P->first=(P->first+1)%MAX;

    return(x);
}

int DeleteFirst(dequeue *P)
{
    int x;

    x=P->data[P->last];

    if(P->last==P->first)
        init(P);
    else
        P->last=(P->last-1+MAX)%MAX;

    return(x);
}

void print(dequeue *P)
{

    int i;
    i=P->first;

    while(i!=P->last)
    {
        printf("\n%d",P->data[i]);
        i=(i+1)%MAX;
    }

    printf("\n%d\n",P->data[P->last]);
}

void main()
{
    int i,x,op,n;
    dequeue q;

    init(&q);
    int c = 1;
    while(c){
        printf("\n1.Create\n2.Insert(last)\n"
               "3.Insert(first)\n4.Delete(last)\n"
               "5.Delete(first)\n"
               "6.Print\n7.Exit\n\n"
               "Enter your choice:");
        scanf("%d", &op);

        if (op == 1) {
            printf("\nEnter number of elements:");
            scanf("%d", &n);
            init(&q);
            printf("\nEnter the data:");

            for (i = 0; i < n; i++) {
                scanf("%d", &x);
                Insert(&q, x);
            }
        }

            else if(op == 2){
            printf("\nEnter element:");
            scanf("%d", &x);
            Insert(&q, x);
        }

            else if(op == 3) {
            printf("\nEnter the element:");
            scanf("%d", &x);
            InsertFirst(&q, x);
        }

            else if(op == 4) {
            x = DeleteFirst(&q);
            printf("\nDeleted element is %d\n", x);
        }
        else if(op == 5) {
            x = DeleteLast(&q);
            printf("\nDeleted element is %d\n", x);
        }
        else if(op == 6) {
            print(&q);
        } else{
            c = 0;

        }
    }
}
