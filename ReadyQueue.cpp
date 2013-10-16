#include "ReadyQueue.h"
using namespace std;

ReadyQueue::ReadyQueue() {
  RPQueue = 0;
  counterPID = 1;
};

ReadyQueue::~ReadyQueue(){
  if(RPQueue != 0) {
    delete RPQueue;
    RPQueue = 0;
  }
};

PCBProcess ReadyQueue::getProcess() {
  PCBProcess process;
  process.setPID(0);
  Queue *temp;
  temp = RPQueue;
  while(temp != 0) {
    if(temp->inCPU == 0) {
      temp->inCPU = 1;
      return temp->process;
    }
    temp = temp->nextPtr;
  }
  return process;
}

void ReadyQueue::insertProcess(PCBProcess myProcess) {
  Queue *ptrNewProcess = new Queue;
  Queue *ptrReadyProcess;
  myProcess.setPID(counterPID);//Estable ReadyQueue su propio PID.
  ptrNewProcess->process = myProcess;
  ptrNewProcess->nextPtr = 0;
  ptrNewProcess->inCPU = 0; //Nuevo proceso encolado que no esta en CPU.
  if(RPQueue == 0)
    RPQueue = ptrNewProcess;
  else {
    ptrReadyProcess = RPQueue;
    while(ptrReadyProcess->nextPtr != 0)
      ptrReadyProcess = ptrReadyProcess->nextPtr;
    ptrReadyProcess->nextPtr = ptrNewProcess;
  }
  counterPID++;
}

bool ReadyQueue::isEmpty() {
  if(RPQueue == 0)
    return true;
  else {
    Queue *temp;
    temp = RPQueue;
    while(temp != 0) {
      if(temp->inCPU == 0)
	return false;
      temp = temp->nextPtr;
    }
  }
  return true;
}

void ReadyQueue::printProcessNotIsCPU() {
  if(RPQueue == 0)
    cout << "Empty ReadyQueue\n";
  else {
    Queue *temp;
    temp = RPQueue;
//     bool processTypeMatch = false;
    int counterLines=0;
    char p;
    system("clear");
    cout << "ReadyQueue\n";
    cout << left << setw(6) << setfill(' ') << "PID";
    cout << left << setw(10) << setfill(' ') << "Name";
    cout << left << setw(20) << setfill(' ') << "MemoryLocation";
    cout << left << setw(20) << setfill(' ') <<"LongProcess ";
    cout << endl;
    while(temp != 0) {
//       std::size_t found = temp->process.getName().find_first_of(typeProcess);//Encuentra un tipo de proceso
//       if(found!=std::string::npos) {
      if(temp->inCPU == 0) { //CPU=no
	cout << left << setw(6) << setfill(' ') << temp->process.getPID();
	cout << left << setw(10) << setfill(' ') << temp->process.getName();
	cout << left << setw(20) << setfill(' ') << temp->process.getMemoryLocation();
	cout << left << setw(20) << setfill(' ') << temp->process.getLongProcess();
	cout << endl;
// 	processTypeMatch=true;
	counterLines++;
	if(counterLines > 20) {
	  cout << "Press p for see more process...";
	  cin >> p;
	  if(p == 'p') {
	    counterLines=0;
	    system("clear");
	    cout << "ReadyQueue\n";
	    cout << left << setw(6) << setfill(' ') << "PID";
	    cout << left << setw(10) << setfill(' ') << "Name";
	    cout << left << setw(20) << setfill(' ') << "MemoryLocation";
	    cout << left << setw(20) << setfill(' ') <<"LongProcess ";
	    cout << endl;
	  }
	}
      }
      temp = temp->nextPtr;
//       if(temp == 0 && !processTypeMatch)
// 	cout << "That information is not available, please press r, p, d or c.\n";
//     }
    }
  }
}