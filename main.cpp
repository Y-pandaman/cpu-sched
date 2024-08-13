/*
 * @Author: 姚潘涛
 * @Date: 2024-08-13 19:43:20
 * @LastEditors: 姚潘涛
 * @LastEditTime: 2024-08-13 19:45:53
 * @Description:
 *
 * Copyright (c) 2024 by pandaman, All Rights Reserved.
 */
#include <atomic>
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <sched.h>
#include <thread>

void set_thread_affinity(int cpu_id) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu_id, &cpuset);
    pthread_t current_thread = pthread_self();
    pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset);
}

void thread_function(int thread_id, int cpu_id) {
    set_thread_affinity(cpu_id);

    std::cout << "Thread " << thread_id << " running on CPU "
              << sched_getcpu() + 1 << std::endl;

    // 模拟一些工作
    while (1) {
        for (int i = 0; i < 10000000; ++i) {
            double result = std::sin(i) + std::cos(i);
            (void)result;   // 防止编译器优化掉这个计算
        }
    }
}

int main() {
    std::thread t1(thread_function, 1, 6);   // 线程1分配到CPU核心6
    std::thread t2(thread_function, 2, 7);   // 线程2分配到CPU核心7

    t1.join();
    t2.join();

    return 0;
}
