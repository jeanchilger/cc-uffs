#!/bin/bash

echo "Type a number"
read i

if [ $i -eq 0 ]
then
    echo "Zero"
elif [ $i -lt 5 ]
then
    echo "menor que cinco"
else
    echo "maior que cinco"
fi

case $i in
    "0")
        echo "Zero"
        ;;
    "1")
        echo "Um"
esac

for i in {10..0}
do
    echo $i
done

for i in $(seq 1 5)
do
    echo $1
done


