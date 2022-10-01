#include "templates.hpp"

template <class T>
void TemplateClasse<T>::conjNaoOrdenado (const T& value) {
    objeto.push_back(value);
}

template <class T>
void TemplateClasse<T>::conjOrdenado (const T& value) {
    conjNaoOrdenado(value);
    sort (objeto.begin(), objeto.end(), objeto);
}