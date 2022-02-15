#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP
#include "templates.hpp"

#include <iostream>
using namespace std;

template <class T>

class TemplateClasse {
    T* objeto;

    public:

        void conjNaoOrdenado(const T&);
        void conjOrdenado(const T&);
};

#endif