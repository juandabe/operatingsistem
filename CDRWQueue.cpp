#include "CDRWQueue.h"

using namespace std;

CDRWQueue::CDRWQueue(){
  queue = 0;
  counterPID = 1;
};

CDRWQueue::~CDRWQueue(){
  if(queue != 0) {
      delete queue;
      queue = 0;
    }
};

void CDRWQueue::insertProcess(PCBProcess myProcess, std::string refClass) {
  Queue *ptrNewProcess = new Queue;
  Queue *ptrReadyProcess;
  myProcess.setPID(counterPID);//La cola printer le asigna su propio PID.
  ptrNewProcess->process = myProcess;
  ptrNewProcess->nextPtr = 0;
  ptrNewProcess->refClass = refClass;
  ptrNewProcess->inRQ = 0; //Nuevo proceso encolado que no esta en RQ.
  if(queue == 0)
    queue = ptrNewProcess;
  else {
    ptrReadyProcess = queue;
    while(ptrReadyProcess->nextPtr != 0)
      ptrReadyProcess = ptrReadyProcess->nextPtr;
    ptrReadyProcess->nextPtr = ptrNewProcess;
  }
  counterPID++;
}

void CDRWQueue::printProcessNotIsRQ() {
  if(queue == 0)
    cout << "Empty CDRWQueue\n";
  else {
    Queue *temp;
    temp = queue;
    int counterLines=0;
    char p;
    system("clear");
    cout << "CDRWQueue\n";
    cout << left << setw(6) << setfill(' ') << "PID";
    cout << left << setw(10) << setfill(' ') << "Name";
    cout << left << setw(20) << setfill(' ') << "MemoryLocation";
    cout << left << setw(20) << setfill(' ') <<"LongProcess ";
    cout << left << setw(20) << setfill(' ') <<"Class ";
    cout << endl;
    while(temp != 0) {
//       std::size_t found = temp->process.getName().find_first_of(typeProcess);//Encuentra un tipo de proceso
//       if(found!=std::string::npos) {
      if(temp->inRQ == 0) { //No esta el process todavia en RQ.
	cout << left << setw(6) << setfill(' ') << temp->process.getPID();
	cout << left << setw(10) << setfill(' ') << temp->process.getName();
	cout << left << setw(20) << setfill(' ') << temp->process.getMemoryLocation();
	cout << left << setw(20) << setfill(' ') << temp->process.getLongProcess();
	cout << left << setw(20) << setfill(' ') << temp->refClass;
	cout << endl;
// 	processTypeMatch=true;
	counterLines++;
	if(counterLines > 19) {
	  counterLines=0;
	  cout << "Press p for see more process...";
	  cin >> p;
	  if(p == 'p') {
	    system("clear");
	    cout << "CDRWQueue\n";
	    cout << left << setw(6) << setfill(' ') << "PID";
	    cout << left << setw(10) << setfill(' ') << "Name";
	    cout << left << setw(20) << setfill(' ') << "MemoryLocation";
	    cout << left << setw(20) << setfill(' ') <<"LongProcess ";
	    cout << left << setw(20) << setfill(' ') <<"Class ";
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

//Saca el primer proceso que no haya estado en la RQ.
PCBProcess CDRWQueue::getProcess(std::string refClass) {
  PCBProcess processFound;
  processFound.setPID(0);
  if(queue == 0)
    return processFound;
  else {
    std::string nameProc;
    Queue *temp;
    temp = queue;
    while(temp != 0) {
//       std::stringstream value;
//       value << "c" << temp->process.getPID();;
//       nameProc=value.str();
      if(temp->refClass == refClass && temp->inRQ == 0) {
	temp->inRQ = 1;
	return temp->process;
      }
      temp = temp->nextPtr;
    }
    return processFound;
  }
}

//Busca un proceso por su nombre en CDRWQueue
bool CDRWQueue::findProcess(std::string refClass) {
  if(queue == 0)
    return false;
  else {
    std::string nameProc;
    Queue *temp;
    temp = queue;
    while(temp != 0) {
//       std::stringstream value;
//       value << "c" << temp->process.getPID();;
//       nameProc=value.str();
      if(temp->refClass == refClass) {
	return true;
      }
      temp = temp->nextPtr;
    }
    return false;
  }
}

