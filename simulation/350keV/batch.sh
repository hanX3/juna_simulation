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
#nohup ./auto.sh 347.1 20000000 > 347.1.out &
#nohup ./auto.sh 347.2 20000000 > 347.2.out &
#nohup ./auto.sh 347.3 20000000 > 347.3.out &
#nohup ./auto.sh 347.4 20000000 > 347.4.out &
#nohup ./auto.sh 347.5 20000000 > 347.5.out &

#nohup ./auto.sh 347.6 100000000 > 347.6.out &
#nohup ./auto.sh 347.7 100000000 > 347.7.out &
#nohup ./auto.sh 347.8 100000000 > 347.8.out &
#nohup ./auto.sh 347.9 100000000 > 347.9.out &
#nohup ./auto.sh 348.0 100000000 > 348.0.out &

#nohup ./auto.sh 348.1 100000000 > 348.1.out &
#nohup ./auto.sh 348.2 100000000 > 348.2.out &
#nohup ./auto.sh 348.3 100000000 > 348.3.out &
#nohup ./auto.sh 348.4 100000000 > 348.4.out &
#nohup ./auto.sh 348.5 100000000 > 348.5.out &

#nohup ./auto.sh 348.6 100000000 > 348.6.out &
#nohup ./auto.sh 348.7 100000000 > 348.7.out &
#nohup ./auto.sh 348.8 100000000 > 348.8.out &
#nohup ./auto.sh 348.9 100000000 > 348.9.out &
#nohup ./auto.sh 349.0 100000000 > 349.0.out &

nohup ./auto.sh 349.1 100000000 > 349.1.out &
nohup ./auto.sh 349.2 100000000 > 349.2.out &
nohup ./auto.sh 349.3 100000000 > 349.3.out &
nohup ./auto.sh 349.4 100000000 > 349.4.out &
nohup ./auto.sh 349.5 100000000 > 349.5.out &
