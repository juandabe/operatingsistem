#ifndef __CLASSCPUQUEUE
#define __CLASSCPUQUEUE

#include <iostream>
#include "PCBProcess.h"

class CPUQueue {
  private:
    int countPID;
    struct Queue {
      PCBProcess process;
      Queue *nextPtr;
    };
    Queue *queue;
  public:
    CPUQueue();
    ~CPUQueue();
    //Referencia para implementar insertProcess FIFO: 
    //http://en.wikipedia.org/wiki/FIFO
    //http://dmmolina.wordpress.com/2008/07/13/listas-enlazadas-defenicion-y-ejemplos/
    void insertProcess(PCBProcess process);
    bool isIdle();
};

#endif

