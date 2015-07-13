#!/bin/zsh

writeScript() {

    root -b<<EOF

.L ZmassFitter.cc++ 

runfits() 

.q
EOF

}

writeScript;
