//
// Created by hadi on 10/2/2018.
//

#ifndef EFFECTIVECPP_BASEANDDERIVED_H
#define EFFECTIVECPP_BASEANDDERIVED_H

#include <string>
#include <iostream>

using namespace std;

class cc {
public:
    cc()= default;
    cc(const string& Name): myname(Name){}
    virtual void print(){ cout<<myname<<endl; }
    void deleleMe(){ delete this;}
protected:
    string myname;
    ~cc(); //{ cout<< "base deleted \n";} // no virtual -> memory leak in derived class(es) !!!

};

class base {
public:
    base()= default;
    base(const string& Name): myname(Name){}
    virtual ~base()=0; //{ cout<< "base deleted \n";} // no virtual -> memory leak in derived class(es) !!!
    virtual void print(){ cout<<myname<<endl; }
protected:
    string myname;
};

class deribedB: public base{
public:
    deribedB() = default;
    deribedB(const string&& Name, const int v): base(Name), val(v){}
    void printMe(){
        cout<<this->myname<<"\t"<<this->val<<endl;
    }
    ~deribedB(){cout<<"derived deleted \n";}
private:
    int val;
};

#endif //EFFECTIVECPP_BASEANDDERIVED_H
