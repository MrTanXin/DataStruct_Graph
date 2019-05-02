#pragma once

#define Queue_max 100

typedef struct queue
{
	char Element[Queue_max];
	int num;
	int front, back;
}queue;

void Queue_push(queue *q,char e);

char Queue_pop(queue *q);

bool IsEmpty(queue *q);

void InitQueue(queue *&q);
