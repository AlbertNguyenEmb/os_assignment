#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
        if (q == NULL)
                return 1;
        return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
        /* TODO: put a new process to queue [q] */
        if (q == NULL){
                return;
        }
        if (proc == NULL){
                return;
        }
        if (q->size >= MAX_QUEUE_SIZE){
                return;
        }
        q->proc[q->size] = proc;
        q->size++;
}

struct pcb_t *dequeue(struct queue_t *q)
{

        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if (q == NULL){
                return NULL;
        }
        
        if (q->size == 0){
                return NULL;
        }
        int max = 0;
        for (int i = 0; i < q->size; i++){
                if (q->proc[i]->priority > q->proc[max]->priority){
                        max = i;
                }
        }

        struct pcb_t *highest_proc = q->proc[max];
        
        for (int i = max; i < q->size - 1; i++){
                q->proc[i] = q->proc[i + 1];
        }

        q->size--;
        return highest_proc;
}

struct pcb_t *purgequeue(struct queue_t *q, struct pcb_t *proc)
{
        /* TODO: remove a specific item from queue
         * */
        if (q == NULL){
                return NULL;
        }
        if (q->size == 0){
                return NULL;
        }
        if (proc == NULL){
                return NULL;
        }
        for (int i = 0; i < q->size; i++){
                if (q->proc[i] = proc){
                        struct pcb_t *removed = q->proc[i];
                        for (int j = i; j < q->size - 1; j++){
                                q->proc[j] = q->proc[j + 1];
                        } 
                        q->size--;
                        return removed;
                } 
        }
        return NULL;
}