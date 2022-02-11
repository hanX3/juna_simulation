#!/usr/bin/bash

if [ ! -d ../../../sim_raw_data/360keV/ ];then
  mkdir ../../../sim_raw_data/360keV/
fi

cp ../auto.sh ../../../sim_raw_data/360keV/

if [ ! -d ../../../sim_raw_data/360keV/c12_em ];then
  cp -r ../c12_em ../../../sim_raw_data/360keV/
fi
cd ../../../sim_raw_data/360keV/

nohup ./auto.sh 357.0 100000000 > 357.0.out &
nohup ./auto.sh 357.1 100000000 > 357.1.out &
nohup ./auto.sh 357.2 100000000 > 357.2.out &
nohup ./auto.sh 357.3 100000000 > 357.3.out &
nohup ./auto.sh 357.4 100000000 > 357.4.out &
nohup ./auto.sh 357.5 100000000 > 357.5.out &
