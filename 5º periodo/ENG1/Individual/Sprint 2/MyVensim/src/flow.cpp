#include "flow.h"

Flow::Flow () {}

Flow::Flow (System* source, System* destination) {
    this->source = source;
    this->destination = destination;
}

Flow::~Flow () {}

void Flow::setSources (System* source) {
    this->source = source;
}

void Flow::setDestination (System* destination) {
    this->destination = destination;
}

System* Flow::getSource () {
    return source;
}

System* Flow::getDestination () {
    return destination;
}

Flow* Flow::operator= (Flow* flow) {
    if (this == flow)
        return this;
        
    source = flow->getSource();
    destination = flow->getSource();
    return this;
}
