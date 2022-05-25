#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int empty(struct queue_t *q) { 
	if(q->size==0)
		return 1;
	return 0; 
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	
	if (q->size == MAX_QUEUE_SIZE){
		/* Full queue. */
		return;	
	}

	/* Insert at queue's tail. */
	q->proc[q->size] = proc;

	/*Adjust queue's size. */
	q->size++;
}

struct pcb_t *dequeue(struct queue_t *q)
{
	    //PCB to be returned
    struct pcb_t *proc = NULL;

    if (q == NULL || q->size == 0){
    // Empty queue. 
        return NULL;
    }
    else{
        //An index with highest priority while traversing
        int idx = 0;

        //max priority in queue
        uint32_t maxpriority = q->proc[0]->priority;

        // Traverse the queue to find pcb with highest priority.
        for (int i = 0; i < q->size; i++) {
            if (q->proc[i]->priority > maxpriority)
            {
                maxpriority = q->proc[i]->priority;
                idx = i;
            }
        }

        //Assign the highest PCB to the returned variable
        proc = q->proc[idx];

        //Remove the PCB above from queue
        for (int i = idx; i < q->size - 1; i++) {
            q->proc[i] = q->proc[i + 1];
        }

        //Adjust queue size
        q->proc[q->size-1] = NULL;
        q->size--;
    }

    return proc;
}
