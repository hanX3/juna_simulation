#!/usr/bin/bash

if [ $# -ne 2 ];then
  echo "need 2 parameter."
  echo "such as: ./auto.sh energy 10000000"
  echo "such as: ./auto.sh 338.0 10000000"
  exit 1
fi

if [ ! -d em_${1} ];then
  echo "copy file ..."
  cp -r c12_em em_${1}
  cd em_${1}
  sed -i "s/ParticleEnergy = 338. \*keV/ParticleEnergy = ${1} \*keV/g" include/Constants.hh
else
  cd em_${1}
fi

if [ -d build ];then
  rm -rf build
fi

mkdir build
cd build
cmake ../
make
mv HPGe em_${1}
sed -i "s/beamOn 0/beamOn ${2}/g" run2.mac

for ((i=0;i<8;i++));
do
  nohup ./em_${1} run2.mac > out_${i}.txt &
  sleep 3
done
