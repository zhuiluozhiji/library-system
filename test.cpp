#include <iostream>
#include <chrono>
#include <ctime>

void printCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::cout << std::ctime(&t); // 格式化输出当前时间
}


int main(){
    printCurrentTime();
    return 0;
}