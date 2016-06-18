#include <iostream>
#include "list.h"

using namespace DS;

int main()
{
    std::ostream& io = std::cout;

    std::vector<float> v;
    v.push_back(99);
    v.push_back(58);
    v.push_back(97);
    v.push_back(86);
    v.push_back(15);

    List<float> arr(v);

    arr.push(777);
    arr.push(666);

    arr.sort(false);
    io << arr;

    return 0;
}
