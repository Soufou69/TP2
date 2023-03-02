#include "tower.h"

Tower::Tower(std::string name) {
    Tower::name = name;
}

void Tower::pushDisk(Disk d){
        Tower::myDisks.push_back(d);
}

int Tower::getDiskCount() const
{
    return Tower::myDisks.size();
}

Disk Tower::getTopDisk() const
{
    return Tower::myDisks.back();
}

Disk Tower::popDisk()
{
    Disk d = Tower::myDisks.back();
    Tower::myDisks.pop_back();
    return d;
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