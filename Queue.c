#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;

//kuyruğun sonuna yeni veri ekler(First in)
int enqueue(int newData){

    if(front == NULL){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = newData;
        new->next = NULL;
        front = rear = new;
        return 1;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = newData;
    new->next = NULL;
    rear->next = new;
    rear = new;
    return 1;
}

//kuyruğun başındaki veriyi siler(First out)
int dequeue(){

    if(front == NULL){
        printf("List is Empty\n");
        return 0;
    }
    struct node *temp = front;
    front = front->next;
    free(temp);
    return 1;

}

//kuyruğun boş olup olmadığını return eder
int isEmpty(){

    if(front == NULL){
        return 1;
    }
    return 0;
}

//kuyruğu ekrana bastırır
void display(){

    if(front == NULL){
        printf("Queue is Empty\n");
    }
    else{
        printf("\nQueue:");
        struct node *temp = front;
        while(temp != NULL){
            printf(" %d",temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    dequeue();
    display();
    printf("\nIsEmpty: %d",isEmpty());

    getchar();
    return 0;
}
