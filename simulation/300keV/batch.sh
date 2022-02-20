#!/usr/bin/bash

if [ ! -d ../../../sim_raw_data/300keV/ ];then
  mkdir ../../../sim_raw_data/300keV/
fi

cp ../auto.sh ../../../sim_raw_data/300keV/

if [ ! -d ../../../sim_raw_data/300keV/c12_em ];then
  cp -r ../c12_em ../../../sim_raw_data/300keV/
fi
cd ../../../sim_raw_data/300keV/

nohup ./auto.sh 297.2 100000000 > 297.2.out &
nohup ./auto.sh 297.3 100000000 > 297.3.out &
nohup ./auto.sh 297.4 100000000 > 297.4.out &
nohup ./auto.sh 297.5 100000000 > 297.5.out &
nohup ./auto.sh 297.6 100000000 > 297.6.out &

