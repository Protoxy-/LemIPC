#!/bin/bash

i=0
while [ $i != 40000 ]
do
    ./lemipc &
    ((i++))
done
