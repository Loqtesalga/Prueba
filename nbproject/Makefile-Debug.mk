#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Alfil.o \
	${OBJECTDIR}/Caballo.o \
	${OBJECTDIR}/Peon.o \
	${OBJECTDIR}/Piezas.o \
	${OBJECTDIR}/Reina.o \
	${OBJECTDIR}/Rey.o \
	${OBJECTDIR}/Tablero.o \
	${OBJECTDIR}/Torre.o \
	${OBJECTDIR}/bmp.o \
	${OBJECTDIR}/igvCamara.o \
	${OBJECTDIR}/igvColor.o \
	${OBJECTDIR}/igvEscena3D.o \
	${OBJECTDIR}/igvFuenteLuz.o \
	${OBJECTDIR}/igvInterfaz.o \
	${OBJECTDIR}/igvMallaTriangulos.o \
	${OBJECTDIR}/igvMaterial.o \
	${OBJECTDIR}/igvPunto3D.o \
	${OBJECTDIR}/igvTextura.o \
	${OBJECTDIR}/pr4.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafinal.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafinal.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafinal ${OBJECTFILES} ${LDLIBSOPTIONS} -static -lglut32 -lopengl32 -lglu32

${OBJECTDIR}/Alfil.o: Alfil.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Alfil.o Alfil.cpp

${OBJECTDIR}/Caballo.o: Caballo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Caballo.o Caballo.cpp

${OBJECTDIR}/Peon.o: Peon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Peon.o Peon.cpp

${OBJECTDIR}/Piezas.o: Piezas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Piezas.o Piezas.cpp

${OBJECTDIR}/Reina.o: Reina.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reina.o Reina.cpp

${OBJECTDIR}/Rey.o: Rey.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rey.o Rey.cpp

${OBJECTDIR}/Tablero.o: Tablero.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tablero.o Tablero.cpp

${OBJECTDIR}/Torre.o: Torre.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Torre.o Torre.cpp

${OBJECTDIR}/bmp.o: bmp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bmp.o bmp.cpp

${OBJECTDIR}/igvCamara.o: igvCamara.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvCamara.o igvCamara.cpp

${OBJECTDIR}/igvColor.o: igvColor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvColor.o igvColor.cpp

${OBJECTDIR}/igvEscena3D.o: igvEscena3D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvEscena3D.o igvEscena3D.cpp

${OBJECTDIR}/igvFuenteLuz.o: igvFuenteLuz.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvFuenteLuz.o igvFuenteLuz.cpp

${OBJECTDIR}/igvInterfaz.o: igvInterfaz.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvInterfaz.o igvInterfaz.cpp

${OBJECTDIR}/igvMallaTriangulos.o: igvMallaTriangulos.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvMallaTriangulos.o igvMallaTriangulos.cpp

${OBJECTDIR}/igvMaterial.o: igvMaterial.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvMaterial.o igvMaterial.cpp

${OBJECTDIR}/igvPunto3D.o: igvPunto3D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvPunto3D.o igvPunto3D.cpp

${OBJECTDIR}/igvTextura.o: igvTextura.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/igvTextura.o igvTextura.cpp

${OBJECTDIR}/pr4.o: pr4.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pr4.o pr4.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
