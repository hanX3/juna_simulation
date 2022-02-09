#!/usr/bin/bash

if [ ! -d ../../../sim_raw_data/330keV/ ];then
  mkdir ../../../sim_raw_data/330keV/
fi

cp ../auto.sh ../../../sim_raw_data/330keV/
cd ../../../sim_raw_data/330keV/

#nohup ./auto.sh 327.5 1500000 > 327.5.out &
nohup ./auto.sh 327.6 9500000 > 327.6.out &
