//
// Created by hadi on 10/5/2018.
//

#ifndef EFFECTIVECPP_FACTORY_H
#define EFFECTIVECPP_FACTORY_H

#include <memory>
#include <iostream>
namespace  Fruits {
    enum FruitType {
        Apple,
        Orange
    };

    template <typename T>
    class baseFruit {
        static unsigned int __id;
        unsigned int myId;
    public:
        T myTy;
        baseFruit(T ty) : myTy(ty), myId(++__id){ }

        virtual ~baseFruit() {
            std::cout<<"base "<<myId<<myTy<<"destroyed"<<std::endl;
        }

        virtual int getCost() const = 0;

        unsigned int getId() { return myId; }
    };

    template <typename T>
    class apple : public baseFruit<T> {

    public:
        apple(T ty):baseFruit<T>(ty){}
        int getCost() const override { return 45; }

        ~apple() {}
    };

    template <typename T>
    class orange : public baseFruit<T> {
    public:
        orange(T ty):baseFruit<T>(ty){}
        int getCost() const { return 80; }

        ~orange() {}
    };

    template <typename T>
    class FruitFactory {
    public:
         static baseFruit<T> *cerateFruit(T ty) {
            if (ty == FruitType::Apple)
                return (new apple<T>(ty));
            if (ty == FruitType::Orange)
                return (new orange<T>(ty));
            return nullptr;
        }

    };

    template <typename T>
    unsigned int baseFruit<T>::__id = 0;} // question !!! here or in cpp file? is there any prefrence ?
#endif //EFFECTIVECPP_FACTORY_H
