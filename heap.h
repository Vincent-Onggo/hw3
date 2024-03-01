#ifndef HEAP_H
#define HEAP_H

#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap {
public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m = 2, PComparator c = PComparator()) : m_(m), c_(c) {
        // Reserve index 0 as invalid
        heap.push_back(T());
    }

    /**
     * @brief Destroy the Heap object
     */
    ~Heap() {}

    /**
     * @brief Push an item to the heap
     *
     * @param item item to heap
     */
    void push(const T &item) {
        heap.push_back(item);
        int loc = heap.size() - 1;
        int parent = loc / m_;
        while (parent >= 1 && c_(heap[loc], heap[parent])) {
            std::swap(heap[loc], heap[parent]);
            loc = parent;
            parent = loc / m_;
        }
    }

    /**
     * @brief Returns the top (priority) item
     *
     * @return T const& top priority item
     * @throw std::underflow_error if the heap is empty
     */
    T const &top() const {
        if (empty()) {
            throw std::underflow_error("Heap is empty");
        }
        return heap[1];
    }

    /**
     * @brief Remove the top priority item
     *
     * @throw std::underflow_error if the heap is empty
     */
    void pop() {
        if (empty()) {
            throw std::underflow_error("Heap is empty");
        }
        heap[1] = heap.back();
        heap.pop_back();
        heapify(1);
    }

    /**
     * @brief Returns true if the heap is empty
     */
    bool empty() const {
        return heap.size() <= 1;
    }

    /**
     * @brief Returns size of the heap
     */
    size_t size() const {
        return heap.size() - 1;
    }

private:
    /// Add whatever helper functions and data members you need below
    std::vector<T> heap;
    int m_;
    PComparator c_;

    /**
     * @brief Reorganizes heap to maintain heap property starting at given index
     *
     * @param index Starting index for heapify
     */
    void heapify(int index) {
        if(index >= (heap.size() / m_) + 1){
            return;
        }
        int smallerChild = m_ * index;
        if(m_*index + 1 < heap.size()){ // right child exists
            int rChild = smallerChild + 1;
            if(c_(heap[rChild], heap[smallerChild])){
                smallerChild = rChild;
            }
        }
        if(c_(heap[smallerChild], heap[index])){
            std::swap(heap[index], heap[smallerChild]);
            heapify(smallerChild);
        }
    }
};

#endif
