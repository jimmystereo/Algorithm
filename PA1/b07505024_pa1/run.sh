#!/bin/bash
make
ulimit -s 262144
sort_tools=(IS MS QS HS)
sets=(5.case1 4000.case1 4000.case2 4000.case3 16000.case1 16000.case2 16000.case3 32000.case1 32000.case2 32000.case3 1000000.case1 1000000.case2 1000000.case3)
# sets=(4000.case1)
# sort_tools=(IS)
for tool in ${sort_tools[@]};
do
    for set in ${sets[@]};
    do
    ./bin/NTU_sort -$tool ./inputs/$set.in ./outputs/$tool$set.out 
    echo $tool $set
    printf "\n"
    echo "-------------------"
    done
done
echo "finished"