#!/bin/sh

CGEN="/path/to/cgen/cgen"
GUILE="guile18"
SED="sed"

${GUILE} -l "${CGEN}/guile.scm" -s "${CGEN}/cgen-idp.scm" -s "${CGEN}" -a "${CGEN}/../cpu/mep.cpu" -b -i mep -m mep -f with-scache -A ana.cpp -E emu.cpp -R reg.cpp -I ins.cpp -J ins.hpp -O out.cpp -H mep.hpp
${SED} -i.sedbak -e "s/@ARCH@/MEP/g" -e "s/@arch@/mep/g" -e "s/@prefix@/mep/g" -e "s/@PREFIX@/MEP/g" ana.cpp
${SED} -i.sedbak -e "s/@ARCH@/MEP/g" -e "s/@arch@/mep/g" -e "s/@prefix@/mep/g" -e "s/@PREFIX@/MEP/g" emu.cpp
${SED} -i.sedbak -e "s/@ARCH@/MEP/g" -e "s/@arch@/mep/g" -e "s/@prefix@/mep/g" -e "s/@PREFIX@/MEP/g" ins.cpp
${SED} -i.sedbak -e "s/@ARCH@/MEP/g" -e "s/@arch@/mep/g" -e "s/@prefix@/mep/g" -e "s/@PREFIX@/MEP/g" ins.hpp
${SED} -i.sedbak -e "s/@ARCH@/MEP/g" -e "s/@arch@/mep/g" -e "s/@prefix@/mep/g" -e "s/@PREFIX@/MEP/g" mep.hpp
${SED} -i.sedbak -e "s/@ARCH@/MEP/g" -e "s/@arch@/mep/g" -e "s/@prefix@/mep/g" -e "s/@PREFIX@/MEP/g" out.cpp
${SED} -i.sedbak -e "s/@ARCH@/MEP/g" -e "s/@arch@/mep/g" -e "s/@prefix@/mep/g" -e "s/@PREFIX@/MEP/g" reg.cpp
rm *.sedbak
