#!/usr/bin/bash

if [ ! -d ../../../sim_raw_data/350keV/ ];then
  mkdir ../../../sim_raw_data/350keV/
fi

cp ../auto.sh ../../../sim_raw_data/350keV/

if [ ! -d ../../../sim_raw_data/350keV/c12_em ];then
  cp -r ../c12_em ../../../sim_raw_data/350keV/
fi
cd ../../../sim_raw_data/350keV/

#nohup ./auto.sh 347.0 20000000 > 347.0.out &
nohup ./auto.sh 347.1 20000000 > 347.1.out &
