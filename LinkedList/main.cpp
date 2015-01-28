//
//  main.cpp
//  LinkedList
//
//  Created by Vinod Gupta on 1/16/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <iostream>

class Node{
public:
    Node(int data):m_data(data),m_next(NULL){}
    virtual ~Node(){
        if(m_next)
            delete m_next;
    }
    
    void addNext(Node *n) {m_next=n;}
    Node *next() {return m_next;}
    
    int GetData() {return m_data;}
private:
    Node *m_next;
    int m_data;
};

class LinkedList{
public:
    LinkedList(Node *h):m_head(h){}
    virtual ~LinkedList() {
        if(m_head){
            delete m_head;
        }
    }
    
    Node *GetHead() { return m_head;}
    void AddNode(Node *node){
        if(!m_head){
            m_head = node;
            return;
        }
        
        node->addNext(m_head);
        m_head = node;
    }
    
    void Traverse(){
        Node *node = m_head;
        while(node){
            std::cout<<node->GetData()<<"\t";
            node = node->next();
        }
    }
    
private:
    Node *m_head;
};

int main(int argc, const char * argv[]) {
    std::cout << "Link List\n";
    LinkedList *list=new LinkedList(new Node(5));
    list->AddNode(new Node(10));
    list->AddNode(new Node(7));
    list->AddNode(new Node(15));
    list->AddNode(new Node(2));
    list->AddNode(new Node(9));
    
    list->Traverse();
    delete list;
    std::cout << "\nTraversal done\n";
    return 0;
}
