#include <iostream>
#include <vector>
#include <iterator>
#include <bits/unique_ptr.h>
#include "CL1.h"
#include "singleton.h"
#include "partialConst.h"
#include "baseAndDerived.h"
#include "factory.h"
#include <memory>
#include <thread>
//#include <boo>
using  namespace std;

//typedef  vIter vector<int>::iterator;
/* typedef is needed when compiler might not be able to deduce that an expression introduces a type,
    especially when it involves templates

  const_iterator<T> equals  'const T*'
  const  iterator<T>  equals 'T* const'
  */


template <typename T>
typename std::vector<T>::const_iterator setIter(typename std::vector<T>::const_iterator it, T val){
    //*it = val;
    return ++it;
}

int mainFactory(){
    //baseFruit bf;
    using namespace Fruits;
    apple<FruitType > ap(FruitType::Apple);
    orange<FruitType > og(FruitType::Orange);

    auto pAp(shared_ptr<baseFruit<FruitType> >(Fruits::FruitFactory<FruitType >::cerateFruit(Fruits::FruitType::Apple)));
    auto pOg(unique_ptr<baseFruit<FruitType> >(Fruits::FruitFactory<FruitType >::cerateFruit(Fruits::FruitType::Orange)));
    //auto pap2 = pAp;
    cout<<ap.getCost()<<"\t"<<ap.getId()<<"\t"<<og.getCost()<<"\t"<<og.getId()<<endl;
    cout<<pAp->myTy<<"\t"<<pAp->getId()<<"\t"<<pOg->myTy<<"\t"<<pOg->getId()<<endl;
    //pOg.reset(); // release (i.e calls destructor) of the resource
    auto pCg = move(pOg);
    cout<<pCg->getId()<<"\t after move\n";
}
int main(){
    auto cl = new cc("hi");
    cl->print();
    cl->deleleMe();
    //cc cl2("ff");
    deribedB drv;
    drv.printMe();
    int z = 13, k;
    int* ptr = &z;
    int& ref = z; // ref looks like -> int* const ref
    cout<<ref<<"\t"<<&ref<<endl;
    ref = k;
    cout<<ref<<"\t"<<&ref<<endl;
    deribedB* dClass = new deribedB("sorena", 2);
    //base b1 = base(); can not be declared since "base" is an abstract class, but there is a way around it (2 lines down)
    dClass->print();
    dClass->printMe();
    base* bClass = dClass;
    bClass->print();
    delete bClass;
    //dClass->printMe(); undefined stuff may happen here
}
int mainPartialConst(){
    partialConst pc({2,0,1,1,0,0});
    const partialConst* p2 =&pc;
    auto v = p2->getVec();
    auto a = v->back();
    cout<<p2->numOnes<<"\t"<<p2->numZeros<<endl;
    auto v2 = pc.getVec();
    v2->push_back(a);
    cout<<p2->numOnes<<"\t"<<p2->numZeros<<endl;
}
//int CL1::st = -1;
int main2() {
    auto mysing = &singleton::getInstance();
    auto sg2 = &singleton::getInstance();
    //singleton misG(singleton::getInstance()); //copy construct
    //auto mis2 = misG; // copy const
    //misG = mis2;  // copy assign
    //cout<<&mis2<<"\t"<<&misG<<"\t"<<sg2<<endl;
    sg2->setPass(" new pass!");
    cout<<mysing->getPass()<<"\t"<<sg2->getPass()<<endl;
    string s1("first string");
    string s2("Second");
    const string* ptr = &s1;
    vector<int> vInt = {2,-4,0,9};
    /*vector<int>::iterator*/
    auto it1 = vInt.begin();
    cout<<*setIter<int>(it1, -17)<<endl;
    // can not do this with const  ptr->append(" something"); //= &s2;
    CL1* obj= new CL1(5);
    std::cout << "obj data: " <<*it1<< std::endl;
    return 0;
}