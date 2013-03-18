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
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile_NB

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/PersonRecognizer.o \
	${OBJECTDIR}/CsvWriter.o \
	${OBJECTDIR}/FramesReader.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/FaceDetector.o \
	${OBJECTDIR}/FramesWriter.o


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
LDLIBSOPTIONS=-L/C/opencv244/release/lib -lopencv_contrib244.dll -lopencv_core244.dll -lopencv_highgui244.dll -lopencv_imgproc244.dll -lopencv_objdetect244.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obamasummarizer.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obamasummarizer.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obamasummarizer ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/PersonRecognizer.o: PersonRecognizer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/opencv244/build/include -I/C/opencv244/build/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/PersonRecognizer.o PersonRecognizer.cpp

${OBJECTDIR}/CsvWriter.o: CsvWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/opencv244/build/include -I/C/opencv244/build/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/CsvWriter.o CsvWriter.cpp

${OBJECTDIR}/FramesReader.o: FramesReader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/opencv244/build/include -I/C/opencv244/build/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/FramesReader.o FramesReader.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/opencv244/build/include -I/C/opencv244/build/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/FaceDetector.o: FaceDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/opencv244/build/include -I/C/opencv244/build/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/FaceDetector.o FaceDetector.cpp

${OBJECTDIR}/FramesWriter.o: FramesWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/opencv244/build/include -I/C/opencv244/build/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/FramesWriter.o FramesWriter.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obamasummarizer.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
