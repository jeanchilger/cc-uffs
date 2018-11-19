#!/bin/bash

#ps -e -o pid --sort -size | head -n 11 | grep [0-9]

if [ ! -d log ]
then
    mkdir log
fi

process(){
    proc=$(ps -e -o pid --sort -size | head -n 11 | grep [0-9])
    for pid in $proc
    do
        nameProc=$(ps -p $pid -o comm=)
        echo -n "$(date +%F" "%H:%M:%S)   " >> log/$nameProc.log
        sizeProc=$(ps -p $pid -o size | grep [0-9])
        echo "$(python -c "print($sizeProc/1024)") MB" >> log/$nameProc.log

    done
}

process

if [ $? -eq 0 ]
then
    echo "Log saved"
else
    echo "Error"
fi
