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
    int size_of_Queue();
    void sort_in_ascending();
    void sort_in_descending();
    
    //Exception Class (try ---catch)
    class UnderFlow{};
};


//Constructor
Queue::Queue(){
    head = NULL;
    rear = NULL;
}

//Destructor
Queue::~Queue(){
   
    Node * tmp = head;
    
    while(tmp != NULL){
        
        head = head->next;
        delete tmp;
        tmp = head;
    }
    rear = NULL;
}

//Adds a new node containing a character at the rear of the linked list.
//if list is empty it just add one and makes both rear and head point to it.
void Queue::enqueue(char item){
    if(isEmpty() == true){
        
        head = rear = new Node(item);
    }
    else{
        rear = rear->next = new Node(item);
        
    }
    
    
}

//Removes a node in the queue at the head of the queue.If the queue is empty
//it throws and exception.
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


//This member function displays the queue.
//if queue empty it displays this for the user to see.
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

//This displays the Queue but reversed.
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

void Queue ::sort_in_ascending(){
   
    if(isEmpty()){
    cout<<"This list is empty";
    }
    
    else{
        //vector is created to contain characters.It contains 10 indexes
        //as a default and expands if more than 10 is inputed.
        vector<char> container(10);
        Node * tmp = head;
        
        for(int i = 0; i < 10 && tmp->next!=NULL; i++){
            
            container[i] = tmp->character;
            tmp = tmp->next;
        }
        
        
        while(tmp!= NULL){
            
            container.push_back(tmp->character);
            tmp = tmp->next;
        }
        
        // new size of vector.
        long int end_of_container = (container.size());
        
        
    int j;
    char temp;
        //This is the insertion sort that sorts the characters in the vector.
        //in ascending order.
        for(int index = 1; index < end_of_container ; index++){
            j=index;
            
            while(j > 0 && (container[j] < (container[j-1]))){
                
                temp = container[j];
                container[j] =  container[j-1];
                 container[j-1] = temp;
                j--;
            }
        }
       
        //This inputs the characters right back into the nodes but in ascending order.
        //starting from the head.
        Node * tmp_l = head;
        for(int i = 0; i < end_of_container; i++){
        
            tmp_l->character = container[i];
            tmp_l =tmp_l->next;
            
        }
    }
}






void Queue ::sort_in_descending(){
    
    if(isEmpty()){
        cout<<"This list is empty";
    }
    
    else{
        //vector is created to contain characters.It contains 10 indexes
        //as a default and expands if more than 10 is inputed.
        vector<char> container(10);
        Node * tmp = head;
        
        for(int i = 0; i < 10 && tmp->next!=NULL; i++){
            
            container[i] = tmp->character;
            tmp = tmp->next;
        }
        
        
        while(tmp!= NULL){
            
            container.push_back(tmp->character);
            tmp = tmp->next;
        }
        
        // new size of vector.
        long int end_of_container = (container.size());
        
        
        //Bubble sort that will sort the characters in the vector in descending order.
        int i, j, flag = 1;    // set flag to 1 to start first pass
        int temp;
        
        for(i = 1; (i <= end_of_container) && flag; i++)
        {
            flag = 0;
            for (j=0; j < (end_of_container -1); j++)
            {
                if (container[j+1] > container[j])
                {
                    temp = container[j];
                    container[j] = container[j+1];
                    container[j+1] = temp;
                    flag = 1;
                }
            }
        }
        
        //This inserts the chracters back into the nodes but in descending order.
        Node * tmp_l = head;
        for(int i = 0; i < end_of_container; i++){
            
            tmp_l->character = container[i];
            tmp_l =tmp_l->next;
        }
        
    }
    
}

//This returns the number of nodes in the queue.
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
    
    char list[14] = {'I','J','A','B','K','L','M','N','E','F','G','H','C','D'};
    Queue Q;
    
    
    for(int i= 0; i < 14; i++){

    Q.enqueue(list[i]);
    }
    
   
  Q.displayQueue();
 //Q.sort_in_ascending();
    Q.sort_in_descending();
    cout << endl<<endl;
Q.displayQueue();
   cout << Q.size_of_Queue();
  
   //Q.displayQueue_Reversed();
    
    
    return 0;
}



