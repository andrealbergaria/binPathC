#!/bin/bash
seq 1 8 | tr '\n' 'A' > plainTextECB
seq 1 8 | tr '\n' 'B' >> plainTextECB
seq 1 8 | tr '\n' 'C' >> plainTextECB
seq 1 8 | tr '\n' 'D' >> plainTextECB


ls -l plainText*
