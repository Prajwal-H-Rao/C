#include <iostream>
using namespace std;

class MinHeap
{
private:
    int capacity;
    int top;
    int *heap;

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        this->top = -1;
        heap = new int(capacity);
    } // The constructor to initialize the data with repsect to the heap

    int left(int index)
    {
        return 2 * index + 1;
    }

    int right(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return index / 2;
    }

    void swap(int &index1, int &index2)
    {
        int temp = index1;
        index1 = index2;
        index2 = temp;
    }

    void insert(int value)
    {
        if (top == capacity)
        {
            cout << "The heap is already full" << endl;
        }
        top++;
        heap[top] = value;
        int i = top;
        while (i > 0 && (heap[parent(i)] > heap[i]))
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int min = index;
        if (index > top)
            return;
        if (heap[l] < heap[min])
        {
            min = l;
        }
        if (heap[r] < heap[min])
        {
            min = l;
        }
        if (min != index)
        {
            swap(heap[index], heap[min]);
            heapify(min);
        }
    }

    void deleteMin()
    {
        if (top == -1)
        {
            cout << "The heap is already empty" << endl;
            return;
        }
        heap[0] = heap[top--];
        printHeap();
        heapify(0);
        printHeap();
    }

    void printHeap()
    {
        int level = 0;
        int itemsInLevel = 1;
        for (int i = 0; i <= top; i++)
        {
            cout << heap[i] << " ";
            if (i == itemsInLevel - 1 || i == top)
            {
                cout << endl;
                level++;
                itemsInLevel += 1 << level;
            }
        }
        cout << endl;
    }
};
int main()
{
    MinHeap heap(10);
    heap.insert(40);
    heap.insert(20);
    heap.insert(30);
    heap.insert(10);
    heap.printHeap();
    heap.deleteMin();
    return 0;
}