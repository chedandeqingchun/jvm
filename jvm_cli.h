#ifndef __JVM_CLI_H
#define __JVM_CLI_H

#include <iostream>
#include <set>

#include "load_class.h"
using namespace std;


enum status {
  JVM_EC_OK,
  JVM_EC_FAILURE
};

class jvmArgsParse {
public:
  bool helpFlag;
  bool versionFlag;
  string option;
  string args[5];
  string version;
  set<string> lookingPath;
  classLoader  loader;

public:
  jvmArgsParse ();
  ~jvmArgsParse ();
  status parse(int argc, char *argv[]);
  status startJvm();
  status loadClass(std::string clsName);
  std::string findClass(std::string clsName);

};

#endif
