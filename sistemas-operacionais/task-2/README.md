# Dining Philosophers Problem

The code in `dining_philosophers.c` gives the solution for the dining philosophers problem. To execute run the following commands:

```
gcc -o phil.out dining_philosophers.c -lpthread
./phil.out
```

In file `dining_philosophers.h`, set the `N` macro as the desired number of philosophers and `CYCLES` macro as the desired number of "life cycles" to be executed - setting a negative number givens infinite cycles. 