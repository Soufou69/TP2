#include "disk.h"

Disk::Disk(int diametre){
    Disk::diametre = diametre;
}

int Disk::getDiametre() const{
    return Disk::diametre;
}