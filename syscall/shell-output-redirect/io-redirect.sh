#! /bin/sh 

echo "./error 2>&1 >stdout_1"
./a.out 2>&1 >stdout_1
echo 
echo "./error >stdout_2 2>&1"
echo 
./a.out >stdout_2 2>&1
