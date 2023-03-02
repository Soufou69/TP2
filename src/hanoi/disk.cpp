#include "disk.h"

Disk::Disk(int diametre){
    Disk::diametre = diametre;
}

int Disk::getDiametre() const{
    return Disk::diametre;
}

std::ostream& operator<<(std::ostream& out, const Disk & d){
    out << d.getDiametre()<<std::endl;
    return out;
}