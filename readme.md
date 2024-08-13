# CPU内核分配

## 程序内核分配

- 使用`taskset`

  ```bash
  taskset -c 0,1,2 ./test_demo
  ```

  - 使用`-c`指定程序运行在哪个核上

## 线程内核分配

- 使用CPU亲和力函数`sched_setaffinity()`,看示例代码

## 注意

- CPU亲和力函数优先级大于`taskset`，同时使用无效

  ```bash
  taskset -c 0,1,2 ./main
  ```

  
