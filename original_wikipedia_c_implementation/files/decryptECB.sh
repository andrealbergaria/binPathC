#!/bin/bash
openssl enc -d -nopad -aes-256-ecb -K 61616161 -in cipherTextECB -out plainTextECB
