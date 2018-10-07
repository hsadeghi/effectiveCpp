//
// Created by hadi on 9/30/2018.
//

#ifndef EFFECTIVECPP_SINGLETON_H
#define EFFECTIVECPP_SINGLETON_H

#include <string>

//#include ""
class singleton{
public:
    static singleton& getInstance(){
        static singleton ss("default pass");
        return ss;
    }
    singleton(singleton const &) = delete;
    void operator=(singleton const&) = delete;
    std::string getPass(){ return pass;}
    void setPass(const std::string&& newPass){pass = newPass;}
private:
    std::string pass;
    singleton(const std::string&& str): pass(str){}
    //~singleton(); wrong ! destructor must never be private
};

#endif //EFFECTIVECPP_SINGLETON_H
