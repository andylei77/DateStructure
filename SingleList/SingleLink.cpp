#include <iostream>

using namespace std;


template <typename T>
class Node {
public:
    T value_;
    Node* next_;

public:
    Node() = default;
    Node(T value, Node* next): value_(value), next_(next) {}
};

template <typename T>
class SingleLink {

public:

    // init
    typedef Node<T>* Pointer;
    SingleLink();
    ~SingleLink();

    // insert
    Node<T>* Insert(int index, T value);
    Node<T>* InsertHead(T value);
    Node<T>* InsertLast(T value);

    // delete
    Node<T>* Delete(int index);
    Node<T>* DeleteHead();
    Node<T>* DeleteLast();

    // modify

    // find

    //T Get(int index);
    //T GetHead();
    //T GetLast();
    Node<T>* GetNodeHead();

    // other
    int Size();
    int IsEmpty();

private:
    int count_;
    Node<T>* phead_;

private:
    // find
    Node<T>* GetNode(int index);

};

template <typename T>
SingleLink<T>::SingleLink(): count_(0), phead_(nullptr) {
    // create head node
    phead_ = new Node<T>();
    phead_->next_ = nullptr;
}

template <typename T>
SingleLink<T>::~SingleLink() {
    Node<T>* pnode = phead_->next_;
    while (nullptr != pnode){
        Node<T>* temp = pnode;
        pnode = pnode->next_;
        delete temp;
    }
}

template <typename T>
Node<T>* SingleLink<T>::Insert(int index, T value){
    Node<T>* pre_node = GetNode(index);

    if(pre_node){
        Node<T>* new_node = new Node<T>(value, pre_node->next_);
        pre_node->next_ = new_node;

        count_++;
        return new_node;
    }
    return nullptr;
}

template <typename T>
Node<T>* SingleLink<T>::InsertHead(T value){
    return Insert(0, value);
}
template <typename T>
Node<T>* SingleLink<T>::InsertLast(T value){
    return Insert(count_, value);
}


template <typename T>
Node<T>* SingleLink<T>::Delete(int index) {
    if (IsEmpty()){
        return nullptr;
    }

    if (index < 0 || index > count_ ){
        return nullptr;
    }

    Node<T>* pre_node = GetNode(index);
    Node<T>* del_node = pre_node->next_;
    pre_node->next_ = del_node->next_;
    delete del_node;
    count_--;
    return pre_node->next_;
}

template <typename T>
Node<T>* SingleLink<T>::DeleteHead() {
    return Delete(0);
}

template <typename T>
Node<T>* SingleLink<T>::DeleteLast(){
    return Delete(count_);
}



template <typename T>
Node<T>* SingleLink<T>::GetNodeHead(){
    return phead_->next_;
    //return GetNode(1);
}


template <typename T>
Node<T>* SingleLink<T>::GetNode(int index){
    if (index < 0 || index > count_ )
        return nullptr;

    int temp = 0;
    Node<T>* pre_node = phead_;
    while (temp < index){
        temp++;
        pre_node = pre_node->next_;
    }

    return pre_node;
}



template <typename T>
int SingleLink<T>::Size(){
    return count_;
}

template <typename T>
int SingleLink<T>::IsEmpty(){
    return count_ == 0;
}



// Test

int main() {

    SingleLink<int> link;
    for (int i = 0; i < 10; i++)
    {
        link.Insert(i, i);
    }
    cout << link.Size() << endl;

    link.Delete(0);
    link.InsertHead(1111);
    link.InsertLast(2222);


    SingleLink<int>::Pointer ptr = link.GetNodeHead();
    while (ptr != nullptr)
    {
        cout << ptr->value_ << endl;
        ptr = ptr->next_;
    }
    getchar();
    return 0;
}