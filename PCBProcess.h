#ifndef __CLASSPCBProcess
#define __CLASSPCBProcess

#include <iostream>
#include <string>

class PCBProcess {
  private:
    int PID;
    std::string name;
    int memoryLocation;
    int longProcess;
  public:
    PCBProcess();
    ~PCBProcess();
    int getPID(void){return PID;};
    std::string getName(void){return name;};
    int getMemoryLocation(void){return memoryLocation;};
    int getLongProcess(void){return longProcess;};
    void setPID(int pid) { this->PID = pid;};
    void setName(std::string name) {this->name = name;};
    void setMemoryLocation(int locMem) {this->memoryLocation = locMem;};
    void setLongProcess(int longProc) {this->longProcess = longProc;};
};

#endif