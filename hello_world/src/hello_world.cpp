#include "hello_world.h"
#include <string>
using namespace std;

string hello (string name) {
    string str = "Hello ";
    str.append (name);
    str.append ("!");
    return str;
}
