#ifndef __DISK_H__
#define __DISK_H__

class Disk {
    public:
        Disk(int diametre);
        int getdiametre() const;
        friend std::ostream& operator<<(std::ostream& out, const Disk & d);
    private:
        int diametre;   
};

#endif