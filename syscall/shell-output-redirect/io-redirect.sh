#! /bin/sh 

echo "./a.out 2>&1 >stdout_1"
./a.out 2>&1 >stdout_1
echo 
echo "./a.out >stdout_2 2>&1"
echo 
./a.out >stdout_2 2>&1
