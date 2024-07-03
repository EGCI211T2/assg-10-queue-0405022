
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
    if(tailPtr!=NULL){
        tailPtr->set_next(new_node);
        tailPtr=new_node;
    }
    else{
        headPtr=new_node;
        tailPtr=new_node;
    }
    size++;
 }
}

int Queue::dequeue(){
  if(headPtr!=NULL){
    NodePtr t=headPtr;
    int value= t->get_value();
    headPtr=headPtr->get_next();
    if(headPtr==NULL) tailPtr=NULL;
          
     delete t;
     return value;
  }
  cout<<"Empty queue"<<endl;
  return -1;
}


Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
    
}
Queue::~Queue(){
    while(headPtr!=NULL){
        dequeue();
    }
    
}


#endif
