gcc -c avl.c

read -p "Lots of Numbers? (Y/N): " opt

if [ "$opt" = "Y" -o "$opt" = "y" ]; then
    gcc -c test1.c;
    gcc -o run avl.o test1.o;
    file_name="test1.c";

    echo "STARTING PROGRAM... $file_name\n";
    ./run

elif [ "$opt" = "N" -o "$opt" = "n" ]; then
    gcc -c test2.c;
    gcc -o run avl.o test2.o;
    file_name="test2.c";

    echo "STARTING PROGRAM... $file_name\n";
    ./run

else
    echo "What the f**k??."
fi
