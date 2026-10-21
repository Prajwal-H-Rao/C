#include <iostream>
#include <stdexcept>
#include <vector>
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
        if (capacity < 0)
        {
            throw invalid_argument("Heap capacity cannot be negative");
        }
        this->capacity = capacity;
        this->top = -1;
        heap = new int[capacity];
    } // The constructor to initialize the data with repsect to the heap
    ~MinHeap()
    {
        delete[] heap;
    }

    MinHeap(const MinHeap &) = delete;
    MinHeap &operator=(const MinHeap &) = delete;

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

    void insert(int value)
    {
        if (top + 1 >= capacity)
        {
            cout << "The heap is already full" << endl;
            return;
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
        if (index < 0 || index > top)
            return;
        if (l <= top && heap[l] < heap[min])
        {
            min = l;
        }
        if (r <= top && heap[r] < heap[min])
        {
            min = r;
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
        // printHeap();
        heapify(0);
        // printHeap();
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

    int minElement()
    {
        return heap[0];
    }

    void heapSort()
    {
        int size = top + 1;
        while (top > 0)
        {
            int min = minElement();
            deleteMin();
            heap[top + 1] = min;
        }
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    MinHeap heap(10);
    vector<int> input = {1, 3, 21, 4, 6, 5};
    for (int num : input)
    {
        heap.insert(num);
    }
    heap.printHeap();
    heap.heapSort();
    // heap.insert(40);
    // heap.insert(20);
    // heap.insert(30);
    // heap.insert(10);
    // heap.printHeap();
    // heap.deleteMin();
    return 0;
}