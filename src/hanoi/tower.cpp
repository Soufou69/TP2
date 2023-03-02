#include "tower.h"

Tower::Tower(std::string name) {
    Tower::name = name;
    Tower::myDisks = new std::vector<Disk>();
}

void Tower::addDisk(Disk d){
    if(d.getDiametre()>Tower::getTopDisk().getDiametre() && Tower::getDiskCount()>0)
        throw std::string("Disk is too big for this tower !!");
    Tower::myDisks->push_back(d);
}

int Tower::getDiskCount() const
{
    return Tower::myDisks->size();
}

Disk Tower::getTopDisk() const
{
    return Tower::myDisks->back();
}

void Tower::removeTopDisk()
{
    Tower::myDisks->pop_back();
}

Disk Tower::getDisk(int index) const
{
    return Tower::myDisks->at(index);
}