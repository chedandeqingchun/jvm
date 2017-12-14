#ifndef __LOAD_CLASS_H
#define __LOAD_CLASS_H
#include <iostream>

class classEntry {
public:
    int magic;
    int16_t minor_number;
    int16_t major_number;
    int16_t const_poll_count;
    int32_t const_poll[const_poll_count - 1]; 
    int16_t access_flags;
    int16_t this_class;
    int16_t super_class;
    int16_t interface_count;
    int16_t interfaces[interface_count - 1];

    







};


class classLoader {

private:
  int header;

private:
  int classParse();

public:
  int loadClass(std::string clsName);
};


#endif
