#include "mylib.hpp"
#include "mylib_prv.hpp"


namespace MyLibInterface
{


int add(int a, int b){

  return MyLib::add(a,b);
}

}