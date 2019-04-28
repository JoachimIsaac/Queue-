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
#include<vector>
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
    void displayQueue_Reversed();
    bool isEmpty();
    // make a function to display the size.
    int size_of_Queue();
    
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
   
    cout<< tmp->character<<"   ";
    tmp = tmp->next;
    
    
    }
    
    
}

//doesn't have prev pointers so i would have to use and array or vector to display it reversed.
void Queue :: displayQueue_Reversed(){
   
    if(isEmpty()){
        cout<<"This List is empty!";
    }
    else{
       
        vector<char> container(0);
        Node * tmp = head;
        
        while(tmp != NULL){
            
            container.push_back(tmp->character);
            tmp = tmp->next;
            }
        
           long int end_of_container = (container.size()-1);
           while(end_of_container >= 0){
            
            cout << container[end_of_container]<<"   ";
            
            end_of_container--;
          }
        
        }
    }
    
    


bool Queue::isEmpty(){
    
    if(head == NULL)
        return true;
    else
        return false;
    
}




int Queue :: size_of_Queue(){
    Node * tmp = head;
    int count = 0;
    
    while(tmp != NULL){
        tmp = tmp->next;
        count++;
        
        
    }
    return count;
}




int main()
{
    
    char list[14] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N'};
    Queue Q;
    
    
    for(int i= 0; i < 14; i++){

    Q.enqueue(list[i]);
    }
    
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
  Q.displayQueue();
    
   cout << Q.size_of_Queue();
  
   //Q.displayQueue_Reversed();
    
    
    return 0;
}



