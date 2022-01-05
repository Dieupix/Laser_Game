#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main() {
    doctest::Context context;

    context.setOption("order-by", "name");  // sort the test cases by their name
    //context.setOption("duration", true);    // print the duration of each test case
    //context.setOption("success", true);     // print all tests

    return context.run();                   // run
}
