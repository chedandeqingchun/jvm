#include <iostream>
#include <string>
#include <unistd.h>
#include <getopt.h>
#include <set>

#include "jvm_cli.h"
#include "load_class.h"
#include "log.h"
using namespace std;

int main(int argc, char *argv[]) {

  JLog log;

  log.error("test 123");


  jvmArgsParse *para = new jvmArgsParse();

  if (!para) {
    return -1;
  }

  if (JVM_EC_FAILURE == para->parse(argc, argv)) {
    
    return -1;
  }

  if (false != para->helpFlag) {
    cout << "jvm [-options] class [args]" << endl;
  } else if (false != para->versionFlag) {
    cout << "jvm version 1.0" << endl;
  } else {
    para->startJvm();
  }

  delete para;

  return 0;
}
