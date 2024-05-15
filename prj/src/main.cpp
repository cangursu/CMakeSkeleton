
#include "DummyLib.h"
#include "DummyPrj.h"
#include <iostream>


int main(int /*argc*/, const char * /*argv*/[])
{
    std::cout << "Hello  " << DummyPrj() << DummyLib() << std::endl;
    return 0;
}
