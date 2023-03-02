#include "Pair.h"

Pair::Pair(int a, int b) {
    pa = new int(a);
    pb = new int(b);
}

Pair::Pair(const Pair & other) {
    pa = new int(*other.pa);
    pb = new int(*other.pb);
}

Pair::~Pair() {
    delete pa;
    delete pb;
}

std::ostream& operator<<(std::ostream& out, const Pair & p) {
    out << "(" << *p.pa << "," << *p.pb << ")"<< std::endl;
    return out;
}