#!/usr/bin/bash

if [ ! -d ../../../sim_raw_data/310keV/ ];then
  mkdir ../../../sim_raw_data/310keV/
fi

cp ../auto.sh ../../../sim_raw_data/310keV/

if [ ! -d ../../../sim_raw_data/310keV/c12_em ];then
  cp -r ../c12_em ../../../sim_raw_data/310keV/
fi
cd ../../../sim_raw_data/310keV/

#nohup ./auto.sh 307.2 100000000 > 307.2.out &
#nohup ./auto.sh 307.3 100000000 > 307.3.out &
#nohup ./auto.sh 307.4 100000000 > 307.4.out &
#nohup ./auto.sh 307.5 100000000 > 307.5.out &
#nohup ./auto.sh 307.6 100000000 > 307.6.out &

#nohup ./auto.sh 307.7 100000000 > 307.7.out &
#nohup ./auto.sh 307.8 100000000 > 307.8.out &
#nohup ./auto.sh 307.9 100000000 > 307.9.out &
#nohup ./auto.sh 308.0 100000000 > 308.0.out &
#nohup ./auto.sh 308.1 100000000 > 308.1.out &

#nohup ./auto.sh 308.2 100000000 > 308.2.out &
#nohup ./auto.sh 308.3 100000000 > 308.3.out &
#nohup ./auto.sh 308.4 100000000 > 308.4.out &
#nohup ./auto.sh 308.5 100000000 > 308.5.out &
#nohup ./auto.sh 308.6 100000000 > 308.6.out &

nohup ./auto.sh 308.7 100000000 > 308.7.out &
nohup ./auto.sh 308.8 100000000 > 308.8.out &
nohup ./auto.sh 308.9 100000000 > 308.9.out &
nohup ./auto.sh 309.0 100000000 > 309.0.out &
nohup ./auto.sh 309.1 100000000 > 309.1.out &

