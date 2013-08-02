#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T11:38:45
#
#-------------------------------------------------

QT       -= core gui

TARGET = noisered
TEMPLATE = lib
CONFIG += staticlib c++11
DESTDIR = $$PWD/../output
LIBS += -lcwt -lfftw3
QMAKE_CXXFLAGS_RELEASE += -fopenmp -O3 -march=native -D_GLIBCXX_PARALLEL
QMAKE_CXX = g++-4.8
BASEPATH = ../build/libnoisered


CONFIG(debug, debug|release) {
	BUILDDIR = $${BASEPATH}/debug
} else {
	BUILDDIR = $${BASEPATH}/release
}
OBJECTS_DIR = $${BUILDDIR}/obj
MOC_DIR = $${BUILDDIR}/moc
RCC_DIR = $${BUILDDIR}/rcc
UI_DIR = $${BUILDDIR}/ui




SOURCES += \
	subtractionconfiguration.cpp \
	spectral_subtractor.cpp \
	point.cpp \
	pair.cpp \
	matrix.cpp \
	eval.cpp \
	cwt_noise_estimator.cpp \
	area.cpp \
	learning/standardssstate.cpp \
	learning/standardssaction.cpp \
	learning/sarsa.cpp \
	learning/realaction.cpp \
    simple_ss.cpp \
    el_ss.cpp \
    geometric_ss.cpp \
    estimation_algorithm.cpp \
    subtraction_algorithm.cpp \
    simple_estimation.cpp \
    martin_estimation.cpp \
    util.cpp \
    wavelet_estimation.cpp

HEADERS += \
	subtractionconfiguration.h \
	spectral_subtractor.h \
	point.h \
	pair.h \
	matrix.h \
	eval.h \
	defines.h \
	cwt_noise_estimator.h \
	area.h \
	learning/state.hpp \
	learning/standardssstate.hpp \
	learning/standardssaction.hpp \
	learning/sarsa.hpp \
	learning/realstate.hpp \
	learning/realaction.hpp \
	learning/action.hpp \
    simple_ss.h \
    el_ss.h \
    geometric_ss.h \
    estimation_algorithm.h \
    subtraction_algorithm.h \
    simple_estimation.h \
    martin_estimation.h \
    util.h \
    wavelet_estimation.h
