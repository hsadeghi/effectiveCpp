//
// Created by hadi on 9/30/2018.
//

#ifndef EFFECTIVECPP_PARTIALCONST_H
#define EFFECTIVECPP_PARTIALCONST_H

#include <vector>
using namespace std;
class partialConst {
public:
    partialConst(vector<int> const && v ):vc(v), numZeros(0), numOnes(0){}
    const vector<int>* getVec()const {
        numZeros = 0;
        //numOnes = 0;
        for(auto item : vc)
            if(!item) numZeros++;
        return &vc;
    }
    vector<int>* getVec(){
        numOnes= 0;
        for(auto item : vc)
            if(item == 1) numOnes++;

        return const_cast<vector<int >*>(static_cast<const partialConst&>(*this).getVec());
    }

private:
    vector<int> vc;
public:
    mutable unsigned int numZeros;
    unsigned int numOnes;

};


#endif //EFFECTIVECPP_PARTIALCONST_H
