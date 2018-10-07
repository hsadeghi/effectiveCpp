//
// Created by hadi on 9/28/2018.
//

#ifndef EFFECTIVECPP_CL1_H
#define EFFECTIVECPP_CL1_H

class CL1{
public:
    static constexpr int st = 8;
    unsigned int unInt;
    CL1(unsigned int a): unInt(a){}

private:
    static int cst;
};

#endif //EFFECTIVECPP_CL1_H
