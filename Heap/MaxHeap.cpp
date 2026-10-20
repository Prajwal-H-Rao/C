#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
    int capacity;
    int top;
    vector<int> heap;

public:
    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        top = -1;
        heap.reserve(capacity);
    }

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
        return (index - 1) / 2;
    }

    void swap(int &index1, int &index2)
    {
        int temp = index1;
        index1 = index2;
        index2 = temp;
    }

    int peekMax()
    {
        return heap[0];
    }

    void deleteMax()
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
    void insert(int element)
    {
        if (top >= capacity - 1)
        {
            cout << "the heap is already full" << endl;
            return;
        }
        top++;
        heap.push_back(element);
        int i = top;
        while (i != 0 && (heap[parent(i)] < heap[i]))
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
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

    void heapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int largest = index;
        if (l <= top && heap[l] > heap[largest])
        {
            largest = l;
        }
        if (r <= top && heap[r] > heap[largest])
        {
            largest = r;
        }
        if (largest != index)
        {
            swap(heap[largest], heap[index]);
            heapify(largest);
        }
    }
};

int main()
{
    MaxHeap heap(10);
    int elements[] = {40, 20, 30, 10, 15, 25, 35};

    for (int element : elements)
    {
        heap.insert(element);
        heap.printHeap();
        cout << endl;
    }

    heap.deleteMax();
    return 0;
}