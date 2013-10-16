#ifndef __CLASSREADYQUEUE
#define __CLASSREADYQUEUE

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "PCBProcess.h"

class ReadyQueue {
  private:
    int counterPID;
    struct Queue {
      PCBProcess process;
      Queue *nextPtr;
      int inCPU;
    };
    Queue *RPQueue;
  public:
    ReadyQueue();
    ~ReadyQueue();
    bool isEmpty();
    void printProcessNotIsCPU();
    //Referencia para implementar insertProcess FIFO: 
    //http://en.wikipedia.org/wiki/FIFO
    //http://dmmolina.wordpress.com/2008/07/13/listas-enlazadas-defenicion-y-ejemplos/
    void insertProcess(PCBProcess process); 
    PCBProcess getProcess();//Retorna el primer process que fue encolado desde el inicio. FIFO
};

#endif

