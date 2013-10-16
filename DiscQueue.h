#ifndef __CLASSDISCQUEUE
#define __CLASSDISCQUEUE

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "PCBProcess.h"

class DiscQueue {
  private:
    int counterPID;
    struct Queue {
      PCBProcess process;
      Queue *nextPtr;
      std::string refClass;
      int inRQ;
    };
    Queue *queue;
  public:
    DiscQueue();
    ~DiscQueue();
    //Referencia para implementar insertProcess FIFO: 
    //http://en.wikipedia.org/wiki/FIFO
    //http://dmmolina.wordpress.com/2008/07/13/listas-enlazadas-defenicion-y-ejemplos/
    void insertProcess(PCBProcess process, std::string refClass);
    void printProcessNotIsRQ();
    bool findProcess(std::string refClass);
    PCBProcess getProcess(std::string refClass);
};

#endif