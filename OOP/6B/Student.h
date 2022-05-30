#pragma once

class Student {
public:
    virtual bool select(int, int) = 0;
    virtual ~Student() {}
};

class StudentTypeA : public Student {
public:
    bool select(int no, int cre) {
        return cre <= 2;
    }
    ~StudentTypeA() {}
};

class StudentTypeB : public Student {
public:
    bool select(int no, int cre) {
        if (no == 1) return false;
        if (no == 2) return true;
        for (int i = 2; i < no; i++) {
            if (no % i == 0) return false;
        }
        return true;
    }
    ~StudentTypeB() {}
};

class StudentTypeC : public Student {
public:
    bool select(int no, int cre) {
        return (no % cre) == 0;
    }
    ~StudentTypeC() {}
};