#!/bin/bash

mkdir abc.cc; mkdir bca.cc

echo a && echo b && echo c

echo a || echo b || echo c

echo a && echo b || echo c && mkdir aaa.cc

ls && echo a || mkdir bbb.cc; echo c
