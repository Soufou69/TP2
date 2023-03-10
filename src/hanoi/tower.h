#ifndef __TOWER_H__
#define __TOWER_H__

#include <string>
#include <iostream>
#include <vector>
#include "disk.h"

class Tower {
    public:
        Tower(std::string name);
        void pushDisk(Disk d);
        Disk getDisk(int index) const;
        int getDiskCount() const;
        Disk getTopDisk() const;
        Disk popDisk();
        friend std::ostream& operator<<(std::ostream& out, const Tower & t);
    private:
        std::string name;
        std::vector<Disk> myDisks;
};

#endif