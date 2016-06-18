#ifndef LIST_H
#define LIST_H

#include <ostream>
#include <algorithm>
#include <vector>

namespace DS
{

    template <class T>
    struct ListNode {
        T data = T();
        ListNode* next = NULL;
        ListNode* prev = NULL;
    };

    // Have to define this for operator overloading
    template <class T>
    class List;
    template <class T>
    std::ostream& operator<<(std::ostream& s, List<T>& l);

    /**
      * @class List
      * Simple list-container
      */
    template <class T>
    class List
    {
        private:
            static bool comp(int i, int j) { return (i>j); }
            void free();
            void init();
            ListNode<T>* head;
            ListNode<T>* tail;
            unsigned int size;
        public:
            List();
            List(const std::vector<T>& _new);
            ~List();

            // Basic modifiers
            void push(T _new);
            void pop();
            T* back();
            void clear();
            bool isEmpty() { return (size)? false:true; };
            int getSize(){ return size; };
            void sort(bool order); // true: A-Z, false: Z-A
            std::vector<T> convert(); // convert list to the std::vector

            // Overloading
            friend std::ostream& operator<< <>(std::ostream& s, DS::List<T>& l);
    };

    /**
      * Initialization
    */
    template <class T>
    void List<T>::init()
    {
        head = new ListNode<T>;
        tail = head;
        size = 0;
    }

    /**
      * Create an empty list
    */
    template <class T>
    List<T>::List()
    {
        init();
    }

    /**
      * Load to the list from a vector
      * @param {std::vector} _new - A vector to load
    */
    template <class T>
    List<T>::List(const std::vector<T>& _new)
    {
        init();
        for (unsigned int i = 0; i < _new.size(); i++ ) push(_new[i]);
    }

    /**
      * Load to a vector from the list
      * @param {std::vector} _new - A vector to load
    */
    template <class T>
    std::vector<T> List<T>::convert()
    {
        std::vector<T> res;
        ListNode<T>* it = head;

        it = it->next;
        while ( it )
        {
            res.push_back(it->data);
            it = it->next;
        }

        return res;
    }


    /**
      * Sort the list
    */
    template <class T>
    void List<T>::sort(bool order)
    {
        std::vector<T> temp;
        temp = convert();

        if (order)
            std::sort(temp.begin(), temp.end());
        else
            std::sort(temp.begin(), temp.end(), comp);

        ListNode<T>* it = head;
        int i = 0;

        it = it->next;
        while ( it )
        {
            it->data = temp[i];
            it = it->next;
            i++;
        }
    }

    /**
      * Free the memory
    */
    template <class T>
    DS::List<T>::~List()
    {
        free();
    }

    /**
      * Push to end of the list
      *
    */
    template <class T>
    void List<T>::push(T _new)
    {
        ListNode<T>* temp = new ListNode<T>;

        tail->next = temp;

        temp->data = T(_new);
        temp->prev = tail;
        temp->next = NULL;

        tail = temp;

        size++;
    }

    /**
      * Pop last element
      *
    */
    template <class T>
    void List<T>::pop()
    {
        if (tail == head)
            return;

        ListNode<T>* last = tail;

        delete last;
        tail = tail->prev;
        tail->next = NULL;

        size--;
    }
    /**
      * Retrieve last element
      *
    */
    template <class T>
    T* List<T>::back()
    {
        if (tail == head)
            return NULL;

        return &(tail->data);
    }

    /**
      * Free the memory
      *
    */
    template <class T>
    void List<T>::free()
    {
        ListNode<T>* it = head;
        ListNode<T>* current;
        while ( it )
        {
            current = it;
            it = it->next;
            delete current;
        }
        if (tail) delete tail;
        if (head) delete head;
    }

    /**
      * Clear the list
      *
    */
    template <class T>
    void List<T>::clear()
    {
        free();
        init();
    }

    /**
      * Overloading
      */
    template <class T>
    std::ostream& operator << (std::ostream& s, DS::List<T>& l)
    {
        DS::ListNode<T>* it = l.head;
        it = it->next;

        int i = 0;
        while ( it )
        {
            s << "Element #" << i + 1 << ": " << it->data << "\n";
            it = it->next;
            i++;
        }
        return s;
    }

}

#endif
