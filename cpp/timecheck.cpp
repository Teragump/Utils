#include <iostream>
#include <chrono>
using namespace std::chrono;

#define TIME_CHECK(expr, comment) \
    auto start = system_clock::now(); \
    expr; \
    auto end = system_clock::now(); \
    std::cout << comment << " time cost: " << duration_cast<microseconds>(end - start).count() << " us" << std::endl

int main(void)
{
    std::cout << "start" << std::endl;

    TIME_CHECK({ 

    int sum = 0;
    for (size_t i = 0; i < 100000; i++) {
        sum += i;
    }
    std::cout << "sum: " << sum << std::endl;

    }, "loop");
    
    std::cout << "end" << std::endl;
    return 0;
}
