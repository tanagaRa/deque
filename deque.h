#pragma once
#include <iostream> 
#include <exception>
#include <cstring>
using namespace std;

template <typename InfoType = int>
class CDeque 
{
    public:
        CDeque(): front(NULL), rear(NULL), size(0) {};
        CDeque(const CDeque&);
        virtual ~CDeque();
        CDeque& operator = (const CDeque&);

        void pushFront(InfoType AInfo);
        void pushBack(InfoType AInfo);
        bool popFront();
        bool popBack();
        InfoType getFirst() const;
        InfoType getLast() const;
        unsigned getSize() const;
        void outputFromFront(ostream& os);
        void outputFromBack(ostream& os);
    private:
        struct CElement {
            InfoType info;
            CElement *next;
            CElement *prev;
            CElement (InfoType Ainfo): info(Ainfo),next (NULL),prev(NULL) {}
        };
        CElement *front, *rear;
        unsigned size;
        void Erase();
        void Clone(const CDeque &);
};


template <typename InfoType>
void CDeque <InfoType> :: Erase() {
    while(popFront());
    size=0;
}

template <typename InfoType>
void CDeque <InfoType> ::Clone(const CDeque& Q) {
    CElement *tmp = Q.front;
    for (unsigned i=0; i<Q.size; i++) {
        pushBack(tmp->info);
        tmp = tmp->next;
    }
}

template <>
CDeque < const char *>::CElement::CElement(const char * AInfo) :next(NULL), prev(NULL) {
	info = new char[strlen(AInfo) + 1];
	strcpy((char*)info, AInfo);
}

template <typename InfoType>
CDeque <InfoType> ::CDeque(const CDeque& Q) {
    size = 0;
    Clone(Q);
}

template <typename InfoType>
CDeque <InfoType> ::~CDeque() {
    Erase();
}

template <typename InfoType>
CDeque<InfoType>& CDeque <InfoType> ::operator = (const CDeque& Q) {
    if (this != &Q) {
        Erase();
        Clone(Q);
    }
    return *this;
}

template <typename InfoType>
void CDeque <InfoType> ::pushBack(InfoType Ainfo)
{
    CElement* tmp = new CElement(Ainfo);
    if (size>0) {
        rear->next=tmp;
        tmp->prev = rear;
    }
    else {
        tmp->next = NULL;
        front =tmp;
    }
    rear = tmp;
    size++;
}

template <typename InfoType>
void CDeque <InfoType>::pushFront(InfoType Ainfo)
{
    CElement* tmp = new CElement(Ainfo);
    if(size>0) {
        tmp->next=front;      
        front->prev=tmp;     
    }
    else {
        tmp->prev = NULL;
        rear = tmp;
    }
    front = tmp;
    size++;
}

template <typename InfoType>
bool CDeque <InfoType> ::popFront() {
    if (size == 0) {
        return false;
    }
    CElement *tmp = front;
    front = front->next;
    delete tmp;
    size--;
    if (size==0) {
        front = NULL;
        rear = NULL;
    }
    return true;
}

template <>
bool CDeque <const char *>::popFront() {
    if(size == 0) {
        return false;
    }
    CElement *tmp = front;
    front = front->next;
    delete[] tmp->info;
    delete tmp;
    size--;
    if (size == 0) {
        front = NULL;
        rear = NULL;
    }
    return true;
}

template <typename InfoType>
bool CDeque <InfoType>::popBack() {
    if (size == 0) {
        return false;
    }
    CElement *tmp = rear;
    rear = rear ->prev;
    rear->next = NULL;
    delete tmp;
    size --;
    if (size == 0) {
        front = NULL;
        rear = NULL;
    }
    return true;
}

template <>
bool CDeque <const char *>::popBack()
{
	if (size == 0) {
		return false;
	}
	CElement *tmp = rear;
	rear = rear->prev;
    rear->next = NULL;
	delete[] tmp->info;
	delete tmp;
	--size;
	if (size == 0) {
		rear = NULL;
		front = NULL;
	}
	return true;
}

template <typename InfoType>
InfoType CDeque <InfoType> :: getFirst() const {
    if (size==0) {
        throw std::runtime_error("Impossible to execute getFirst: deque is empty");
    }
    return front->info;
}

template <typename InfoType>
InfoType CDeque <InfoType>::getLast() const {
    if (size == 0) {
        throw runtime_error ("Impossible to execute getLast: deque is empty");
    }
    return rear->info;
}

template <typename InfoType>
unsigned CDeque <InfoType> ::getSize() const {
    return size;
}

template <typename InfoType>
void  CDeque <InfoType> ::outputFromFront(ostream& os)
{
    for (CElement* tmp = front; tmp != NULL; tmp = tmp->next) {
        os << (*tmp).info << " ";
    }
    os<<endl;
}

template <typename InfoType>
void CDeque <InfoType> ::outputFromBack(ostream& os)
{
    CElement* tmp = rear;
    for (unsigned i=0; i<size; i++) {
        os << (*tmp).info << " ";
        tmp = tmp->prev;
    }
    os<<endl;
}