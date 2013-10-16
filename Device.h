#ifndef __CLASSDEVICE
#define __CLASSDEVICE

#include <string>
#include <iostream>
#include <sstream>

class Device {
  private:
    std::string *printer;
    std::string *disc;
    std::string *cdrw;
    int numPrinters, numDisc, numCd;
  public:
    Device();
    ~Device();
    //Referencia para la implementacion del puntero al arreglo.
    //http://www.nebrija.es/~abustind/Informatica/MetodologiaII/Objetos_memoria_dinamica.pdf
    void initiatePrinters(int printers);
    void initiateDisc(int discs);
    void initiateCdrw(int cdwds);
    bool findDevice(std::string device);
};

#endif