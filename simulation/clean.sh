#!/usr/bin/bash

for file in `ls`
do
  if [ -d $file ];then
    if [[ $file == *em_* ]];then
      echo $file
      cd $file/data
      rm *.cpp
      rm *.pdf
      rm step*.root
      cd ../..
    fi
  fi
done
