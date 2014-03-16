#ifndef COMPONENTSYSTEM_H
#define COMPONENTSYSTEM_H

#include <SFML/System/Time.hpp>
#include "ComponentBase.h"
#include <cassert>
#include <map>

using namespace std;

template <class T> class ComponentSystem
{
    public:
        void process(sf::Time);
        void addComponent(T);
        T* getComponent(unsigned int ID);
    protected:
        std::map<unsigned int, T> components;
    private:
};

template<class T>
void ComponentSystem<T>::process(sf::Time frameTime) {
    for(typename std::map<unsigned int, T>::iterator it = components.begin(); it!=components.end(); it++) {
        it->second.go(frameTime);
    }
}

template<class T>
void ComponentSystem<T>::addComponent(T input) {
    components[input.getID()]=input;
}

template<class T>
T* ComponentSystem<T>::getComponent(unsigned int ID) {
    typename map<unsigned int,T>::iterator it = components.find(ID);
    if(it!=components.end())
        return &(it->second);
    else
        return nullptr;
}

#endif // COMPONENTSYSTEM_H
