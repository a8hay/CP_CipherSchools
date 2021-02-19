#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    int *harr;
    int count;
    int capacity;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        this->count = 0;
        this->harr = new int[this->capacity];
    }

    void insertIntoheap(int key)
    {
        if (this->count == this->capacity)
            return;
        this->count++;
        int index = this->count - 1;
        this->harr[index] = key;

        while (index != 0 && this->harr[index] < this->harr[parent(index)])
        {
            swap(this->harr[index], this->harr[parent(index)]);
            index = parent(index);
        }
    }
    // O(1)
    int getMin()
    {
        if (this->count == 0)
            return -1;
        return this->harr[0];
    }

    void deleteFromHeap()
    {
        if (this->count == 0)
            return;
        if (this->count == 1)
            this->count--;
        else
        {
            this->harr[0] = this->harr[this->count - 1];
            this->count--;
            minHeapify(0);
        }
    }

    void minHeapify(int index)
    {
        int l = leftChild(index);
        int r = rightChild(index);
        int smallest = index;

        if (l < count && this->harr[1] < this->harr[smallest])
        {
            smallest = l;
        }

        if (r < count && this->harr[r] < this->harr[smallest])
        {
            smallest = r;
        }
    }
};

int main()
{
    return 0;
}