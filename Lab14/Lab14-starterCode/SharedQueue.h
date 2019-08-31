#ifndef __Lab14__SharedQueue__
#define __Lab14__SharedQueue__

#include <mutex>

template<typename T>
class SharedQueue {
public:
    SharedQueue();

    ~SharedQueue();

    /*
     These declarations mean that we do NOT get the automatically
     defined copy/copy-assign functions.  If you try to call one
     by copying the queue, you'll get a compiler error.
     
     This is a common technique for things that are uncopyable (like std::thread and std::mutex, for example).
     
     We really DO want a destructor, so cheating at the
     rule of 3 here makes sense here.
     */
    SharedQueue(const SharedQueue<T> &) = delete;

    SharedQueue<T> &operator=(const SharedQueue<T> &) = delete;


    //Return true if the queue is empty
    bool IsEmpty() const;

    //Enqueue the next item at the tail of the queue.
    void Add(T value);

    //Dequeue the next queue element and store it in "item" variable.  The function returns false if the queue is empty and no item can be retrieved.
    bool Remove(T &item);

    void Print();

private:
    struct QueueItem {
        T item;
        QueueItem *next;
    };

    std::mutex m;
    QueueItem *tail, *head;
    //Fill in the The private data members.
};

template <typename T>
SharedQueue<T>::SharedQueue() {
    head = NULL;
    tail = NULL;
}

template <typename T>
SharedQueue<T>::~SharedQueue() {
    QueueItem *curr = head;

    while(curr != NULL)
    {
        QueueItem *next = curr;
        delete curr;
        curr = next;
    }
    delete head;
    delete tail;
}

template <typename T>
bool SharedQueue<T>::IsEmpty() const {
    return head == NULL;
}

template <typename T>
void SharedQueue<T>::Add(T value) {
    m.lock();

    QueueItem *last = new QueueItem();

    last->item = value;
    last->next = NULL;

    if(IsEmpty()){
        head = last;
    }
    else{
        QueueItem *temp = new QueueItem();
        temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = last;
        tail = last;
    }

    m.unlock();
}

template <typename T>
bool SharedQueue<T>::Remove(T &item) {
    m.lock();

    QueueItem *temp = new QueueItem();

    if(IsEmpty()){
        m.unlock();
        return false;
    }
    else{
        item = head->item;
        temp = head->next;
        head = temp;
        m.unlock();
        return true;
    }
}

template <typename T>
void SharedQueue<T>::Print() {
    m.lock();

    QueueItem *curr;

    curr = head;
    while(curr != NULL){
        std::cout << curr->item;
        curr = curr->next;
    }

    std::cout << std::endl;

    m.unlock();
}
//Fill in the function definitions

#endif
