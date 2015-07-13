#!/bin/zsh

writeScript() {

    root -b<<EOF

.L ZmassFitterVsIter.cc++ 

runfits() 

.q
EOF

}

writeScript;
