#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, char** argv) {
    doctest::Context context;

    context.setOption("order-by", "name");  // sort the test cases by their name
    //context.setOption("success", true);     // print all tests

    return context.run();                   // run
}
