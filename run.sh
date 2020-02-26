#!/bin/bash

cd src 
g++ filecnt.cpp -o filecnt
g++ filedisp.cpp -o filedisp
./filecnt /home | ./filedisp 
