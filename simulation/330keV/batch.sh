#!/usr/bin/bash

if [ ! -d ../../../sim_raw_data/330keV/ ];then
  mkdir ../../../sim_raw_data/330keV/
fi

cp ../auto.sh ../../../sim_raw_data/330keV/
cd ../../../sim_raw_data/330keV/

#nohup ./auto.sh 327.5 1500000 > 327.5.out &
#nohup ./auto.sh 327.6 9500000 > 327.6.out &
#nohup ./auto.sh 327.7 9000000 > 327.7.out &
#nohup ./auto.sh 327.8 8500000 > 327.8.out &
#nohup ./auto.sh 327.9 5000000 > 327.9.out &

nohup ./auto.sh 328.1 20000000 > 328.1.out &
