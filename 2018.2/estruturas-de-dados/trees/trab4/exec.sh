gcc -c avl.c
gcc -c main.c
gcc -o run avl.o main.o

echo "RUNNING\n"

./run
