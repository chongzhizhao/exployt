#ifndef EXPLOYT_HH
#define EXPLOYT_HH

class Exployt {
    int flag;

    public:
    Exployt(const int flag = 0){};

    ~Exployt(){};

    void set_flag(int val) {flag = val;}

    int get_flag() {return flag;}

    static int exployt_toctou();

};

#endif
