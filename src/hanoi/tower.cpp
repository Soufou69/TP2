#include "tower.h"

Tower::Tower(std::string name) {
    Tower::name = name;
}

bool Tower::addDisk(Disk d){
    if(Tower::getDiskCount()>0 && d.getDiametre()>Tower::getTopDisk().getDiametre()){
        std::cout << "\033[1;31m" << "Disk is too big for this tower !!"<< "\033[0m" << std::endl;
       return false;
    }
        Tower::myDisks.push_back(d);
        return true;
}

int Tower::getDiskCount() const
{
    return Tower::myDisks.size();
}

Disk Tower::getTopDisk() const
{
    return Tower::myDisks.back();
}

void Tower::removeTopDisk()
{
    Tower::myDisks.pop_back();
}

Disk Tower::getDisk(int index) const
{
    return Tower::myDisks.at(index);
}

std::ostream& operator<<(std::ostream& out, const Tower & t){
    out << t.name << std::endl;
    for(int i=t.getDiskCount()-1;i>=0;i--){
        out << t.getDisk(i) << "\n";
    }
    out << std::endl;
    return out;
}