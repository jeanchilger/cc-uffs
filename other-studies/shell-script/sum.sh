#!/bin/bash

i=0
i=$(($i+1))
echo "$i"

i=$(bc <<< $i+1)
echo "$i"
