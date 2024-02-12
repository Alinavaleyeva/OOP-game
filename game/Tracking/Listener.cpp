#include "Listener.h"

Listener::Listener(Subject &subject1): subject(subject1){};

void Listener::DeteleMe() {
    subject.detach(this);
}