#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template<class T>
class List {
    private:
        class Node {
                T data;
                Node* next;
                Node* prev;

                void insertNext(T);
                T deleteNext();

                friend class List;
                friend class Iterator;
            };

        class Iterator {
            private:
                Node* actualPosition;
            public:
                void operator = (Iterator&);
                bool operator != (Iterator&);
                bool operator == (Iterator&);
                Iterator& operator ++ ();
                Iterator& operator -- ();
                T& operator * ();

                friend class List;
            };

        Iterator it;
        Node beginList;
        Node endList;

    public:
        List();
        ~List();

        void insertBegin(T);
        void insertLast(T);

        T deleteFirst();
        T deleteLast();

        int sizeList();

        bool isEmpty();

        void clearList();

        Iterator& beginIt();
        Iterator& endIt();
    };

#endif // LIST_H_INCLUDED


template<class T>
void List<T>::Node::insertNext(T nd) {
    Node* newNd(new Node);

    newNd->data = nd;

    newNd->prev = this;
    newNd->next = this->next;
    this->next = newNd;
    newNd->next->prev = newNd;
    }

template<class T>
T List<T>::Node::deleteNext() {
    T aux = this->next->data;
    Node* nodAux = this->next;

    this->next = this->next->next;
    this->next->prev = this;

    delete nodAux;

    return aux;
    }

template<class T>
void List<T>::Iterator::operator=(Iterator& p) {
    this->actualPosition = p.actualPosition;
    }

template<class T>
bool List<T>::Iterator::operator!=(Iterator& a) {
    return this->actualPosition != a.actualPosition;
    }

template<class T>
bool List<T>::Iterator::operator==(Iterator& p) {
    return this->actualPosition == p.actualPosition;
    }

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    this->actualPosition = actualPosition->next;
    return (*this);
    }

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    this->actualPosition = this->actualPosition->prev;
    return (*this);
    }

template<class T>
T& List<T>::Iterator::operator*() {
    return this->actualPosition->data;
    }

template<class T>
List<T>::List() {
    beginList.next = &endList;
    endList.prev = &beginList;
    beginList.prev = nullptr;
    endList.next = nullptr;
    }

template<class T>
List<T>::~List() {
    clearList();
    }

template<class T>
void List<T>::insertBegin(T nd) {
    beginList.insertNext(nd);
    }

template<class T>
void List<T>::insertLast(T nd) {
    endList.prev->insertNext(nd);
    }

template<class T>
T List<T>::deleteFirst() {
    return beginList.deleteNext();
    }

template<class T>
T List<T>::deleteLast() {
    return endList.prev->prev->deleteNext();
    }

template<class T>
int List<T>::sizeList() {
    int counterS = 0;
    Node* p = beginList.next;

    while(p != &endList) {
        counterS++;
        p = p->next;
        }

    return counterS;
    }

template<class T>
bool List<T>::isEmpty() {
    if(beginList.next == &endList) {
        return true;
        }
    return false;
    }

template<class T>
void List<T>::clearList() {
    while(!isEmpty()) {
        beginList.deleteNext();
        }
    }

template<class T>
typename List<T>::Iterator& List<T>::beginIt() {
    it.actualPosition = &beginList;
    return it;
    }

template<class T>
typename List<T>::Iterator& List<T>::endIt() {
    it.actualPosition = &endList;
    return it;
    }
