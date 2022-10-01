#include "system.h"

System::System () {}

System::System (string name, double value) {
    this->name = name;
    this->value = value;
}

System::~System () {}

void System::setName (string name) {
    this->name = name;
}

void System::setValue (double value) {
    this->value = value;
}

string System::getName () {
    return name;
}

double System::getValue () {
    return value;
}

System* System::operator= (System* system) {
    if (this == system)
        return this;
    name = system->getName();
    value = system->getValue();
    return this;
}