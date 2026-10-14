#include "structurs_data.h"



int     before(t_request a, t_request b, int edf)
{
    if (edf && a.deadline != b.deadline)
        return a.deadline < b.deadline;
    if (a.ticket != b.ticket)
        return a.ticket < b.ticket;
    return a.id < b.id;
}

void swap(t_request *a, t_request *b)
{
    t_request tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}


int heap_push(t_heap *heap, t_request request)
{
    int i;
    int parent;

    if (heap->size == heap->capacity)
        return (0);
    i = heap -> size++;
    heap->items[i] = request;
    while (i > 0)
    {
        parent = (i - 1) / 2;
        if (!(before(heap->items[i], heap->items[parent], heap->edf)))
            break;
        swap(&heap->items[i], &heap->items[parent]);
        i = parent;
    }
    return 1;
}

int best_child(t_heap *heap, int i)
{
    int left;
    int right;

    left = 2 * i + 1;
    right = left + 1;
    if (right < heap->size && before(heap->items[right], heap->items[left], heap->edf))
        return right;
    return left;
}

void heap_pop(t_heap *heap)
{
    int i;
    int child;

    if (heap->size == 0)
        return ;
    heap->size--;
    heap->items[0] = heap->items[heap->size];
    i = 0;
    while (2 * i + 1 < heap->size)
    {
        child = best_child(heap, i);
        if (!before(heap -> items[child], heap -> items[i], heap -> edf))
            break;
        swap(&heap -> items[i], &heap -> items[child]);
        i = child;
    }
}

