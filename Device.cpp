#include "Device.h"

using namespace std;

Device::Device() {}

Device::~Device() {}

void Device::initiatePrinters(int numPrinter) {
  numPrinters = numPrinter;
  printer = new std::string[numPrinters];
  for(int i=0; i<numPrinters; i++){
    std::stringstream value;
    value << "p" << i+1;
    printer[i] = value.str();
  }
}

void Device::initiateDisc(int numDiscs) {
  numDisc=numDiscs;
  disc = new std::string[numDisc];
  for(int i=0; i<numDiscs; i++) {
    std::stringstream value;
    value << "d" << i+1;
    disc[i] = value.str();
  }
}

void Device::initiateCdrw(int numCdrw) {
  numCd = numCdrw;
  cdrw = new std::string[numCdrw];
  for(int i=0; i<numCdrw; i++) {
    std::stringstream value;
    value << "c" << i+1;
    cdrw[i] = value.str();
  }
}

bool Device::findDevice(std::string dev) {
  for(int i=0; i<numPrinters; i++) {
    if(printer[i] == dev)
      return true;
  }
  for(int i=0; i<numDisc; i++) {
      if(disc[i] == dev)
	return true;
  }
  for(int i=0; i<numCd; i++) {
      if(cdrw[i] == dev)
	return true;
  }
  return false;
}