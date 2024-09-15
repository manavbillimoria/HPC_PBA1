# HPC_PBA1
# Comparison of Parellel Matrix Multiplication in C

--- 

### Instructions to run - 
Serial - gcc matrix_serial.c -o matrix_serial
        ./matrix_serial

OpenMP - gcc -fopenmp matrix_openmp.c -o matrix_openmp
        ./matrix_openmp

Pthreads - gcc matrix_pthread.c -o matrix_pthread -lpthread
        ./matrix_pthread

---

### Results - 
Serial Matrix Multiplication Time: 0.162000 seconds
OpenMP Parallel Matrix Multiplication Time: 0.027000 seconds
pthread Parallel Matrix Multiplication Time: 0.080000 seconds

---

  In terms of performance and ease of use, serial programming is the simplest but also the slowest, as it only utilizes a single core and does not involve any parallelism. It's best suited for small tasks or problems where parallel execution would introduce unnecessary complexity and overhead. 
  OpenMP, on the other hand, offers a middle ground between ease of use and performance. It allows for quick parallelization of existing serial code with minimal changes using compiler directives, making it ideal for parallel loops and computational tasks. OpenMP introduces some overhead due to automatic thread management, but this is generally outweighed by the significant performance boost from utilizing multiple cores, especially for larger tasks. 
  Pthreads provides the most fine-grained control over threading, synchronization, and scheduling, which can result in superior performance for highly optimized applications. However, it requires much more effort to implement correctly, as thread creation, synchronization, and load balancing must be managed manually. While pthreads may outperform OpenMP in certain fine-tuned scenarios, it is generally more complex to maintain and less portable, making OpenMP a more practical choice for most high-performance computing tasks.
  
  For most applications, especially those that involve straightforward parallel loops or matrix operations, OpenMP strikes the best balance between performance and ease of use. pthreads would only be a better choice for situations requiring detailed thread management and extreme performance tuning.
