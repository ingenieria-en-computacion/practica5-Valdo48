#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

void queue_enqueue(Queue* q, Data d){
    Node *newNode = new_node(d);
    if(queue_is_empty(q)){
        q->head = q->tail = newNode;
    }else{
        q->tail->next = newNode;
        q->tail = newNode; 
    }
}

Data queue_dequeue(Queue* q){
    Data t= q->head->data;
    if(!queue_is_empty(q)){
        Node *temp = q->head;
        q->head = q->head->next;
        temp->next = NULL;
        delete_node(temp);
        return t;
    }else{
        printf("La cola esta vacia\n");
        return 0;
    }
}

bool queue_is_empty(Queue* q){
    return q->head == NULL;
}

Data queue_front(Queue* q){
    return q->head->data;
}

void queue_empty(Queue* q){
    while(!queue_is_empty(q)){
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q){
    if(cqueue_is_empty(q)){ 
        free(q);
        q = NULL;
    }else{
        cqueue_empty(q);
        free(q);
        q = NULL;
    }
}
