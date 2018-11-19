read dado
while [ $dado != -1 ]
do
    echo $dado
    read dado
done

i=0
while [ $i -lt 10 ]
do
    echo $i
    i=$(($i+1))
done

