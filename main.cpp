// Ana Taylor
// p4.cpp
// Driver

#include <iostream>
#include "heap.h"
#include "heap.cpp"

using namespace std;

const int INITIAL_SIZE = 5;

int main() {


    cout << endl << endl << endl;

    cout << "------------- START OF TEST ----------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Creating a resizable heap (heap1) of initial size " << INITIAL_SIZE << "..." << endl;
    Heap heap1(INITIAL_SIZE);
    cout << "Heap of size " << INITIAL_SIZE << " created." << endl;


    cout << endl << endl;
    cin.get();

    cout << "------- TESTING THE insert AND resize FUNCTIONS _______" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Inserting values in heap1..." << endl;
    cout << "The heap will accept duplicate values and will be re-sized " << endl;
    cout << "if attempting to insert more values that its initial size. " << endl << endl;

    cout << "Inserting 13 ..." << endl;
    heap1.insert(13);
    cout << "Inserting 14 ..." << endl;
    heap1.insert(14);
    cout << "Inserting 16 ..." << endl;
    heap1.insert(16);
    cout << "Inserting 24 ..." << endl;
    heap1.insert(24);
    cout << "Inserting 21 ..." << endl;
    heap1.insert(21);
    cout << "Inserting 19 ..." << endl;
    heap1.insert(19);
    cout << "Inserting 68 ..." << endl;
    heap1.insert(68);
    cout << "Inserting 65 ..." << endl;
    heap1.insert(65);
    cout << "Inserting 26 ..." << endl;
    heap1.insert(26);
    cout << "Inserting 32 ..." << endl;
    heap1.insert(32);
    cout << "Inserting 65 ..." << endl;
    heap1.insert(65);
    cout << "Inserting 26 ..." << endl;
    heap1.insert(26);
    cout << "Inserting 32 ..." << endl;
    heap1.insert(32);

    cout << endl;
    cin.get();

    cout << "-------- TESTING THE COPY CONSTRUCTOR--------" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Creating heap2 that is the copy of heap1..." << endl;

    Heap heap2(heap1);
    cout << "heap2 created. " << endl;

    cout << endl << endl;
    cin.get();

    cout << "---- TESTING THE remove AND bubbleDown FUNCTION on heap2 ----" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Removing values from heap2 and printing the priorities ..." << endl;
    cout << "The priorities should be the same at this point ..." << endl << endl;


    for (int i = 1; i <= heap2.getHeapCapacity(); i++) {

        cout << "Previous priority is: " << heap2.getPreviousPriority(i) << endl;
        cout << "Updated  priority is: " << heap2.getCurrentPriority(i) << endl << endl;

    }

    cin.get();

    cout << "Now removing values from heap2..." << endl;
    while(!heap2.isEmpty()) {

        cout << heap2.remove() << endl;

    }

    cout << endl;
    cout << "Values removed form heap2. " << endl;
    cout << "Now trying to remove 3 more values..." << endl;
    heap2.remove();
    heap2.remove();
    heap2.remove();
    cout << "Unable to remove because the heap2 is empty." << endl;

    cout << endl << endl;
    cin.get();

    cout << "-------- TESTING THE OVERLOADED ASSIGNMENT OPERATOR --------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Creating heap3 that is the copy of heap1..." << endl;
    Heap heap3 = heap1;
    cout << "heap3 created. " << endl;

    cout << endl << endl;
    cin.get();

    cout << "---- TESTING THE remove AND bubbleDown FUNCTION on heap3 ----" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Printing the priorities of heap3 then removing values: " << endl;

    for (int i = 1; i <= heap3.getHeapCapacity(); i++) {

        cout << "Previous priority is: " << heap3.getPreviousPriority(i) << endl;
        cout << "Updated  priority is: " << heap3.getCurrentPriority(i) << endl << endl;

    }

    cin.get();

    cout << "Now removing values from heap3..." << endl;
    while(!heap3.isEmpty()) {

        cout << heap3.remove() << endl;

    }

    cout << endl;
    cout << "Values removed form heap3. " << endl;
    cout << "Now trying to remove 3 more values..." << endl;
    heap3.remove();
    heap3.remove();
    heap3.remove();
    cout << "Unable to remove because the heap3 is empty." << endl;

    cout << endl << endl;
    cin.get();


    cout << "----- TESTING THE resetPriority FUNCTION -----" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "The priority will be changed to the (minimum priority in the heap - 1) " << endl;
    cout << "to ensure the new priority is the highest priority and to bubble up. " << endl;
    cout << "Choosing the values from heap1 for a priority reset..." << endl;
    cout << endl << endl;

    cin.get();

    cout << "Resetting priority of 21..." << endl;
    heap1.resetPriority(21);
    cout << "Now printing the previous and updated priority... " << endl;
    cout << "Previous priority is: " << heap1.getPreviousPriority(1) << endl;
    cout << "Updated  priority is: " << heap1.getCurrentPriority(1) << endl << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;

    cin.get();

    cout << "Resetting priority of 32..." << endl;
    heap1.resetPriority(32);
    cout << "Now printing the previous and updated priority... " << endl;
    cout << "Previous priority is: " << heap1.getPreviousPriority(1) << endl;
    cout << "Updated  priority is: " << heap1.getCurrentPriority(1) << endl << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;

    cin.get();

    cout << "Resetting priority of 14..." << endl;
    heap1.resetPriority(14);
    cout << "Now printing the previous and updated priority... " << endl;
    cout << "Previous priority is: " << heap1.getPreviousPriority(1) << endl;
    cout << "Updated  priority is: " << heap1.getCurrentPriority(1) << endl << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;

    cin.get();

    cout << "Now removing the values in heap1..." << endl;
    while(!heap1.isEmpty()) {

        cout << heap1.remove() << endl;

    }

    cout << endl << endl;

    cout << "-------- END OF TEST --------" << endl;


    return 0;

}







