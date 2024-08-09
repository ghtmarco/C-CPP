#include <stdio.h>

int heap[100];
int lastIndex = 1;


int getParentIndex(int childIndex){

    return childIndex / 2;
}

int getLeftChildIndex(int parentIndex){
    return 2 * parentIndex;
}

int getRightChildIndex(int parentIndex){
    return 2 * parentIndex + 1;
}

void swap(int childIndex, int parentIndex) {
    int temp = heap[childIndex];
    heap[childIndex] = heap[parentIndex];
    heap[parentIndex] = temp;
}

int downHeap(int parentIndex){
    int leftChildIndex = getLeftChildIndex(parentIndex);
    int rightChildIndex = getRightChildIndex(parentIndex);
    int newParentIndex = parentIndex;

    if(leftChildIndex < lastIndex && heap[leftChildIndex] < heap[newParentIndex]){
        newParentIndex = leftChildIndex;
    }
    if(rightChildIndex < lastIndex && heap[rightChildIndex] < heap[newParentIndex]){
        newParentIndex = rightChildIndex;
    }

    if(newParentIndex != parentIndex){
        swap(parentIndex, newParentIndex);
        downHeap(newParentIndex);
    }

}

int upHeap(int childIndex){
    if(childIndex == 1) {
        return 0;
    }
    int parentIndex = getParentIndex(childIndex);

    if(heap[childIndex] < heap[parentIndex]){
        swap(childIndex, parentIndex);
    upHeap(parentIndex);
    }
}

void insert(int insertValue){
    heap[lastIndex] = insertValue;
    lastIndex++;
    upHeap(lastIndex - 1);
}

void printAll(){
    for(int i = 1; i < lastIndex; i++){
        printf("%d ", heap[i]);
    }
}

void pop(){
    heap[1] = heap[lastIndex - 1];
    lastIndex--;
    downHeap(1);
}


int main(){
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);
    insert(110);
    insert(120);
    insert(10);
    insert(5);
    insert(3);

    pop();

    printAll();

    return 0;
}
