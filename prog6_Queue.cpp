//-----------------------------------------------------------------------------------------
//
//   Name:Joachim Isaac
//
//   Course:
//
//   Purpose:
//
//-----------------------------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<iostream>
using namespace std;


class Queue{
    
protected:
    struct Node{
        char character;
        Node* next;
       
        
        Node(char c, Node* n = NULL){
            character = c;
            next = n;
           
        }
    };
    
private:
    Node * head;
    Node * rear;
    
    
public:
    Queue();
    ~Queue();
    void enqueue(char item);
    char dequeue();
    void displayQueue();
    bool isEmpty();
    
    //Exception Class
    class UnderFlow{};
};



Queue::Queue(){
    head = NULL;
    rear = NULL;
}

Queue::~Queue(){
    Node * tmp = head;
    
    while(tmp != NULL){
        
        head = head->next;
        delete tmp;
        tmp = head;
        
    }
    rear = NULL;
}

void Queue::enqueue(char item){
    if(isEmpty() == true){
        
        head = rear = new Node(item);
    }
    else{
        rear = rear->next = new Node(item);
        
    }
    
    
}

char Queue::dequeue(){
    
    
    if(isEmpty() == true){
        throw Queue :: UnderFlow();
    }
    else{
        
        
        Node * tmp = head;
        char item = tmp->character;
        head = head->next;
        delete tmp;
        tmp = NULL;
        
        
        return item;
    }

}

void Queue::displayQueue(){
     Node * tmp = head;
    
    if(isEmpty()){
        
        cout<<"This List is empty!";
        
    }
    
    
    while(tmp != NULL){
   
    cout<< tmp->character;
    tmp = tmp->next;
    
    
    }
    
    
}

bool Queue::isEmpty(){
    
    if(head == NULL)
        return true;
    else
        return false;
    
}


int main()
{
    
    
    
    
   
    return 0;
}



