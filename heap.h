// Ana Taylor
// heap.h
// function declarations

#ifndef P4_HEAP_H
#define P4_HEAP_H

class Heap {

private:

    struct HeapNode {

        int currentPriority;
        int previousPriority;

    };

    HeapNode *heap;
    int array_size;
    int heap_size;
    void resize();
    // called by insert if the array needs resizing upon insertion
    // pre:
    // post:


public:

    Heap(int size = 10);
    // pre: array size initially set to 10
    // post: array will expand if attempting to insert more than 10 values

    Heap(const Heap &h);
    // pre:
    // post:

    Heap &operator=(const Heap &rhs);
    // pre:
    // post:

    ~Heap();
    // pre:
    // post:

    void insert(int key);
    // calls bubbleUp function
    // calls resize function if attempting to insert beyond array size
    // pre:
    // post:

    int remove();
    // calls bubbleDown function
    // pre: checks for the empty heap
    // post: returns the value of first priority(root)

    bool isEmpty();
    // returns the status of the heap
    // pre:
    // post:

    void bubbleDown(int hole);
    // pre:
    // post:

    void bubbleUp(int key);
    // pre:
    // post:

    void resetPriority(int key);
    // pre: the value passed is in the heap and it represents priority
    // post:

    int getCurrentPriority(int i);
    // the priority after the key is changed
    // pre:
    // post:

    int getPreviousPriority(int i);
    // the priority before the key is changed
    // pre:
    // post:

    int getHeapCapacity();



};

#endif //P4_HEAP_H
