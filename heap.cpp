// Ana Taylor
// heap.cpp
// function implementation

#include "heap.h"
#include <string>
#include <iostream>
using namespace std;


Heap::Heap(int size) {


    heap_size  = 0;
    array_size = size;
    heap = new HeapNode[array_size];
    for (int i = 0; i < array_size; i++) {
        heap[i].currentPriority  = 0;
        heap[i].previousPriority = 0;
    }

}


Heap::Heap(const Heap &h) {

    heap_size  = h.heap_size;
    array_size = h.array_size;
    heap = new HeapNode[array_size];

    for (int i = 0; i < array_size; i++) {
        heap[i].currentPriority  = h.heap[i].currentPriority;
        heap[i].previousPriority = h.heap[i].previousPriority;
    }

}


Heap& Heap::operator=(const Heap &rhs) {

    if (this != &rhs) {
        array_size = rhs.array_size;
        heap_size = rhs.heap_size;
        delete[] heap;
        heap = new HeapNode[heap_size];

        for (int i = 0; i < array_size; i++) {
            heap[i].currentPriority = rhs.heap[i].currentPriority;
            heap[i].previousPriority = rhs.heap[i].previousPriority;
        }

    }


    return *this;

}


Heap::~Heap() {

    cout << "Destructor now running..." << endl;

    delete[] heap;

}


bool Heap::isEmpty() {

    return heap_size == 0;

}


void Heap::insert(int key) {


    if (heap_size == array_size - 1) {

        resize();

    }

    bubbleUp(key);

}


void Heap::bubbleUp(int key) {

    int hole = ++heap_size;
    while (hole > 1 && key < heap[hole/2].currentPriority) {

        heap[hole] = heap[hole/ 2];
        hole = hole/ 2;

    }
    heap[hole].currentPriority = key;
    heap[hole].previousPriority = key;

}


void Heap::resize() {



    HeapNode *temp;
    int larger =  array_size * 2;
    temp = new HeapNode[larger];
    for (int i = 0; i < larger; i++) {
        temp[i].currentPriority = heap[i].currentPriority;
        temp[i].previousPriority = heap[i].previousPriority;
    }
    delete[] heap;
    heap = temp;
    array_size = larger;

}


int Heap::remove() {

    if (heap_size == 0) {
        cout << "EMPTY!" << endl;
        return 0;

    } else {
        int head = heap[1].currentPriority;
        heap[1].currentPriority = heap[heap_size].currentPriority;
        heap_size--;
        bubbleDown(1);
        return head;

    }

}


void Heap::bubbleDown(int hole) {

    HeapNode temp = heap[hole];
    while ( (hole * 2 <= heap_size && temp.currentPriority > heap[hole * 2].currentPriority)
             ||
            (hole * 2 + 1 <= heap_size && temp.currentPriority > heap[hole * 2 + 1].currentPriority)) {

        if ( hole * 2 + 1 <= heap_size && heap[hole * 2 + 1].currentPriority < heap[hole * 2].currentPriority ) {

            heap[hole].currentPriority = heap[hole * 2 + 1].currentPriority;
            hole = hole * 2 + 1;

        } else {

            heap[hole].currentPriority = heap[hole * 2].currentPriority;
            hole = hole * 2;

        }
    }
    heap[hole] = temp;

}


void Heap::resetPriority(int key) {


    int index;

    for (int i = 1; i <= heap_size; i++) {
        if(heap[i].previousPriority == key) {
            index = i;
        }
    }

    //heap[index].previousPriority = heap[index].currentPriority;
    heap[index].currentPriority = heap[1].currentPriority - 1;
    while (index != 1 && heap[index/2].currentPriority > heap[index].currentPriority) {
        HeapNode  temp = heap[index];
        heap[index] = heap[index/2];
        heap[index/2] = temp;

        index = index/ 2;


    }

}

int Heap::getHeapCapacity() {

    return heap_size;
}


int Heap::getPreviousPriority(int i) {


    return heap[i].previousPriority;


}

int Heap::getCurrentPriority(int i) {


    return heap[i].currentPriority;

}