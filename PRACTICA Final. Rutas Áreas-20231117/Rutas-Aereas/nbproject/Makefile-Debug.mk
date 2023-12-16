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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Almacen_Rutas.o \
	${OBJECTDIR}/src/Pais.o \
	${OBJECTDIR}/src/Paises.o \
	${OBJECTDIR}/src/Punto.o \
	${OBJECTDIR}/src/Ruta.o \
	${OBJECTDIR}/src/Rutas_Aereas.o \
	${OBJECTDIR}/src/imagen.o \
	${OBJECTDIR}/src/imagenES.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rutas-aereas

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rutas-aereas: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rutas-aereas ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Almacen_Rutas.o: src/Almacen_Rutas.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Almacen_Rutas.o src/Almacen_Rutas.cpp

${OBJECTDIR}/src/Pais.o: src/Pais.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Pais.o src/Pais.cpp

${OBJECTDIR}/src/Paises.o: src/Paises.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Paises.o src/Paises.cpp

${OBJECTDIR}/src/Punto.o: src/Punto.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Punto.o src/Punto.cpp

${OBJECTDIR}/src/Ruta.o: src/Ruta.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Ruta.o src/Ruta.cpp

${OBJECTDIR}/src/Rutas_Aereas.o: src/Rutas_Aereas.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Rutas_Aereas.o src/Rutas_Aereas.cpp

${OBJECTDIR}/src/imagen.o: src/imagen.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/imagen.o src/imagen.cpp

${OBJECTDIR}/src/imagenES.o: src/imagenES.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/imagen.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/imagenES.o src/imagenES.cpp

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
