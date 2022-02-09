#!/usr/bin/bash

if [ ! -d ../../../sim_raw_data/340keV/ ];then
  mkdir ../../../sim_raw_data/340keV/
fi

cp ../auto.sh ../../../sim_raw_data/340keV/
cd ../../../sim_raw_data/340keV/

nohup ./auto.sh 327.6 9500000 > 327.6.out &
