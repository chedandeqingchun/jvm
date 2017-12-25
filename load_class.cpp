#include <iostream>
#include <string>
#include "load_class.h"
using namespace std;

classEntry::classEntry() {

    int16_t const_poll_count = 5;
    this->const_poll = new int32_t[const_poll_count];
    cout << "new class entry" << endl;

}

classEntry::~classEntry() {

    delete this->const_poll;
    cout << "free class entry" << endl;

}

int classLoader::loadClass(std::string clsName) {

    cout << "class name is " << clsName << endl;

    return -1;
}


int classLoader::classParse() {


    return -1;
}

