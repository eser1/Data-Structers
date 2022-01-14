#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

//Yığının başına veri ekler(Last in)
int push(int newData){

    if(top == NULL){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = newData;
        new->next = NULL;
        top = new;
        return 1;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = newData;
    new->next = top;
    top = new;
    return 1;

}

//Yığının başındaki veriyi siler(First out)
int pop(){

    if(top == NULL){
        printf("Stack is Empty\n");
        return 0;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
    return 1;
}

//Yığının boş olup olmadığını return eder
int isEmpty(){

    if(top == NULL){
        return 1;
    }
    return 0;
}

//Yığını ekrana bastırır
void display(){

    if(top == NULL){
        printf("Stack is Empty\n");
    }
    else{
        printf("\nStack:");
        struct node *temp = top;
        while(temp != NULL){
            printf(" %d", temp->data);
            temp = temp->next;
        }
    }

}

int main(){

    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    display();
    printf("\nIsEmpty: %d",isEmpty());

    getchar();
    return 0;
}