#!/bin/bash


openssl enc -aes-256-ecb -nopad -p -K 616161 -in plainTextECB -out cipherTextECB
