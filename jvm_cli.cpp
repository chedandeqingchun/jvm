#include <iostream>
#include <fstream>
#include <getopt.h>

#include "jvm_cli.h"
#include "log.h"
using namespace std;

jvmArgsParse::jvmArgsParse () {
  //cout << "new command line parse object "<< endl;
}

jvmArgsParse::~jvmArgsParse() {
  //cout << "destruct command line parse object" << endl;
}

/*
*java --version
*
*
*/
status jvmArgsParse::parse(int argc, char *argv[]) {

  int opt;
  int option_index = 0;

  /*
  *no_argument 
  *required_argument  
  *option_argument 
  *  
  */
  static struct option long_options[] = {
    {"version", no_argument, NULL, 'v'},
    {"help", no_argument, NULL, 'h'},
    {"path", 2, NULL, 'x'},
    {0, 0, 0, 0}
  };

  while (-1 != (opt = getopt_long(argc, argv, "vhx:", long_options, &option_index))) {

    switch (opt) {
      case 'v': {
          this->versionFlag = true;
          break;
      }

      case 'h': {
        this->helpFlag = true;
        break;
      }

      case 'x': {

        if (!optarg) {
            cout << "optarg is empty" << endl;
            return JVM_EC_FAILURE;
        }

        auto res = lookingPath.insert(optarg);//TODO string split

        if (!res.second) {
            cout << "insert patch fails" << endl;
            return JVM_EC_FAILURE;
        }

        break; 
      }

      default:
        cout << "default options" << endl;
    }

  }

  return  JVM_EC_OK;
}

status jvmArgsParse::startJvm() {
  cout << "start jvm..." << endl;
  this->loadClass("hello");
  return JVM_EC_OK;
}

status jvmArgsParse::loadClass(string clsName) {

  std::string classPath = this->findClass(clsName);
  JInfo("class path is %s", classPath.c_str());   

  this->loader.loadClass(clsName);
  return JVM_EC_OK;
}

std::string jvmArgsParse::findClass(string clsName) {

    std::set<string>::iterator iter = this->lookingPath.begin();

    while (iter != this->lookingPath.end()) {

        std::ifstream inFile((*iter + "/" +  clsName).c_str());       

        if (bool(inFile) == true) {
            return *iter + clsName;
        }

        iter++;
    }

    return "11223344";
}
