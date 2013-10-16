#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <typeinfo>
#include "Device.h"
#include "PCBProcess.h"
#include "ReadyQueue.h"
#include "PrinterQueue.h"
#include "DiscQueue.h"
#include "CDRWQueue.h"
#include "CPUQueue.h"

using namespace std;

int main(){
  std::string option;
  int printers, discs, cdrws;
  Device devices;
  ReadyQueue readyqueue;
  PrinterQueue printerqueue;
  DiscQueue discqueue;
  CDRWQueue cdrwqueue;
  CPUQueue cpuqueue;
  system("clear");
  cout << "sys gen section\n";
  while(true) {
    cout << "how many printers do you need? - Enter an integer number!" << endl;
    if(cin >> printers)
      break;
    cin.clear();
    cin.ignore();
  }
  devices.initiatePrinters(printers);
  cout << "done!\n";
  while(true) {
    cout << "how many disc do want? - Enter an integer number!" << endl;
    cin.clear();
    cin.ignore();
    if(cin >> discs)
      break;
  } 
  devices.initiateDisc(discs);
  cout << "done!\n";
  while(true) {
    cout << "how many cd/rw do want? - Enter an integer number!" << endl;
    cin.clear();
    cin.ignore();
    if(cin >> cdrws)
      break;
  } 
  devices.initiateCdrw(cdrws);
  cout << "done!\n";
  cout << "ready\nrunning section\n";
  while(option != "q") {
    cout << "Enter system call or interruption signal. Press q for exit!\n";
    cin >> option;
    if(option == "A") {
      PCBProcess process;
      if(readyqueue.isEmpty() && cpuqueue.isIdle()) {
	readyqueue.insertProcess(process);
	process = readyqueue.getProcess();
	if(process.getPID() != 0) {
	  cpuqueue.insertProcess(process);
	  cout << "first process entering to the reqdyqueue, therefore is the first process was sent to process!\n";
	}
      }
      else {
	readyqueue.insertProcess(process);
	cout << "the process was sent to the readyqueue!\n";
      }
    }
    else if(option == "t") {
      cout << "terminating\n";
      PCBProcess process;
      process = readyqueue.getProcess();
      if(process.getPID() != 0){
	cpuqueue.insertProcess(process);
	cout << "the process was sent to process!\n";
      }
      else
	cout << "until now, all process in the readyque were processed!\n";
    }
    else if(option == "S") {
      char key;
      system("clear");
      while(true) {
	cout << "Snapshot!\n";
	cin >> key;
	if(key == 'r') {
	  readyqueue.printProcessNotIsCPU();
	  cout << "bye snapshot\n";
	  break;
	}
	else if(key == 'p') {
	  printerqueue.printProcessNotIsRQ();
	  cout << "bye snapshot\n";
	  break;
	}
	else if(key == 'd') {
	  discqueue.printProcessNotIsRQ();
	  cout << "bye snapshot\n";
	  break;
	}
	else if(key == 'c') {
	  cdrwqueue.printProcessNotIsRQ();
	  cout << "bye snapshot\n";
	  break;
	}
	else
	  cout << "That information is not available, please press r, p, d or c.\n";
      }
    }
    else if(option.at(0) == 'p') {
      if(option.size() >=2 ) {
	std::string name;
	int locMem, longMem;
	  if(devices.findDevice(option)) {
	    PCBProcess myProcess;
	      while(true) {
	      cin.clear();
	      cin.ignore();
	      cout << "File name?\n";
	      cin >> name;
	      if(name.size() <= 8)
		break;
	      }
	      while(true) {
		cout << "Starting location in memory? - Enter an integer number!\n";
		cin.clear();
		cin.ignore();
		if(cin >> locMem)
		  break;
	      }
	      while(true) {
		cout << "How long is the file? - Enter an integer number!\n";
		cin.clear();
		cin.ignore();
		if(cin >> longMem)
		  break;
	      }
	      myProcess.setName(name);
	      myProcess.setMemoryLocation(locMem);
	      myProcess.setLongProcess(longMem);
	      printerqueue.insertProcess(myProcess, option);//Inserta un proceso con la class que identifica el process.
	  }
	  else
	    cout << "This is an error, that device does not exit\n";
      }
      else
	cout << "error this process not is accepted.\n";
    }
    else if(option.at(0) == 'd') {
      if(option.size() >=2 ) {
	std::string name;
	int locMem, longMem;
	char key;
	if(devices.findDevice(option)) {
	  PCBProcess myProcess;
	    while(true) {
	      cin.clear();
	      cin.ignore();
	      cout << "File name?\n";
	      cin >> name;
	      if(name.size() <= 8)
		break;
	    }
	    while(true) {
		cout << "Starting location in memory? - Enter an integer number!\n";
		cin.clear();
		cin.ignore();
		if(cin >> locMem)
		  break;
	    }
	    while(true) {
	      cout << "If this is for read press r if this for write press w?\n";
	      cin >> key;
	      if(key == 'w') {
		while(true) {
		  cout << "How long is the file? - Enter an integer number!\n";
		  cin.clear();
		  cin.ignore();
		  if(cin >> longMem)
		    break;
		}
		break;
	      }
	      else if(key == 'r') {
		longMem = 0;
		break;
	      }
	    }
	    myProcess.setName(name);
	    myProcess.setMemoryLocation(locMem);
	    myProcess.setLongProcess(longMem);
	    discqueue.insertProcess(myProcess, option);//Inserta un proceso con la class que identifica el process.
	}
	else
	  cout << "This is an error, that device does not exit\n";
      }
      else
	cout << "error this process not is accepted.\n";
    }
    else if(option.at(0) == 'c') {
      if(option.size() >=2 ) {
	std::string name;
	int locMem, longMem;
	char key;
	if(devices.findDevice(option)) {
	  PCBProcess myProcess;
	    while(true) {
	      cin.clear();
	      cin.ignore();
	      cout << "File name?\n";
	      cin >> name;
	      if(name.size() <= 8)
		break;
	    }
	    while(true) {
	      cout << "Starting location in memory? - Enter an integer number!\n";
	      cin.clear();
	      cin.ignore();
	      if(cin >> locMem)
		break;
	    }
	    while(true) {
	      cout << "If this is for read press r if this for write press w?\n";
	      cin >> key;
	      if(key == 'w') {
		while(true) {
		  cout << "How long is the file? - Enter an integer number!\n";
		  cin.clear();
		  cin.ignore();
		  if(cin >> longMem)
		    break;
		}
		break;
	      }
	      else if(key == 'r') {
		longMem = 0;
		break;
	      }
	    }
	    myProcess.setName(name);
	    myProcess.setMemoryLocation(locMem);
	    myProcess.setLongProcess(longMem);
	    cdrwqueue.insertProcess(myProcess,option);//Inserta un proceso con la class que identifica el process.
	}
	else
	  cout << "This is an error, that device does not exit\n";
      }
      else
	cout << "error this process not is accepted.\n";
    }
    else if(option.at(0) == 'P') {
      if(option.size() >= 2) {
	std::transform(option.begin(), option.end(), option.begin(), ::tolower);
	PCBProcess process;
	process = printerqueue.getProcess(option);
	if(process.getPID() != 0) {
	  std::transform(option.begin(), option.end(), option.begin(), ::toupper);
	  process.setName(option);
	  if(readyqueue.isEmpty() && cpuqueue.isIdle()) {
	    readyqueue.insertProcess(process);
	    process = readyqueue.getProcess();
	    if(process.getPID() != 0) {
	      cpuqueue.insertProcess(process);
	      cout << "first process entering to the reqdyqueue, therefore is the first process was sent to process!\n";
	    }
	  }
	  else {
	    readyqueue.insertProcess(process);
	    cout << "the process was sent to the readyqueue!\n";
	  }
	}
	else
	  cout << "fatal error, cannot INTERRUPT with that key\n";
      }
      else
	cout << "fatal error, cannot INTERRUPT with that key\n";
    }
    else if(option.at(0) == 'D') {
      if(option.size() >= 2) {
	std::transform(option.begin(), option.end(), option.begin(), ::tolower);
	PCBProcess process;
	process = discqueue.getProcess(option);
	if(process.getPID() != 0) {
	  std::transform(option.begin(), option.end(), option.begin(), ::toupper);
	  process.setName(option);
	  if(readyqueue.isEmpty() && cpuqueue.isIdle()) {
	    readyqueue.insertProcess(process);
	    process = readyqueue.getProcess();
	    if(process.getPID() != 0) {
	      cpuqueue.insertProcess(process);
	      cout << "first process entering to the reqdyqueue, therefore is the first process was sent to process!\n";
	    }
	  }
	  else {
	    readyqueue.insertProcess(process);
	    cout << "the process was sent to the readyqueue!\n";
	  }
	}
	else
	  cout << "fatal error, cannot INTERRUPT with that key\n";
      }
      else
	cout << "fatal error, cannot INTERRUPT with that key\n";
    }
    else if(option.at(0) == 'C') {
      if(option.size() >= 2){
	std::transform(option.begin(), option.end(), option.begin(), ::tolower);
	PCBProcess process;
	process = cdrwqueue.getProcess(option);
	if(process.getPID() != 0) {
	  std::transform(option.begin(), option.end(), option.begin(), ::toupper);
	  process.setName(option);
	  if(readyqueue.isEmpty() && cpuqueue.isIdle()) {
	    readyqueue.insertProcess(process);
	    process = readyqueue.getProcess();
	    if(process.getPID() != 0) {
	      cpuqueue.insertProcess(process);
	      cout << "first process entering to the reqdyqueue, therefore is the first process was sent to process!\n";
	    }
	  }
	  else {
	    readyqueue.insertProcess(process);
	    cout << "the process was sent to the readyqueue!\n";
	  }
	}
	else
	  cout << "fatal error, cannot INTERRUPT with that key\n";
      }
      else
	cout << "fatal error, cannot INTERRUPT with that key\n";
    }
    else if (option == "q"){
      cout << "Bye system!\n";
    }
    else
      cout << "error this process not is accepted.\n";
  }

  return 0;
}