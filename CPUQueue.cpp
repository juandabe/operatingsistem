#include "CPUQueue.h"

CPUQueue::CPUQueue(){
  queue = 0;
};

CPUQueue ::~CPUQueue(){
  if(queue !=0) {
    delete queue;
    queue = 0;
  }
};

bool CPUQueue::isIdle() {
  if(queue == 0)
    return true;
  return false;
}

void CPUQueue::insertProcess(PCBProcess process) {
  Queue *ptrNewProcess = new Queue;
  Queue *ptrReadyProcess;
  ptrNewProcess->process = process;
  ptrNewProcess->nextPtr = 0;
  if(queue == 0)
    queue = ptrNewProcess;
  else {
    ptrReadyProcess = queue;
    while(ptrReadyProcess->nextPtr != 0)
      ptrReadyProcess = ptrReadyProcess->nextPtr;
    ptrReadyProcess->nextPtr = ptrNewProcess;//Pone de ultimo el nuevo proceso. FIFO
  }
}