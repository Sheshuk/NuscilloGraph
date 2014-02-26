#-------------------------------------------------
#
# Project created by QtCreator 2014-02-25T13:34:34
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NuOsc
TEMPLATE = app


SOURCES += main.cpp\
        nuoscwindow.cpp \
    gl_scene.cpp

HEADERS  += nuoscwindow.h \
    gl_scene.h \
    Mcomplex.h

OTHER_FILES += \
    shader/nuosc.frag \
    shader/nuosc.vert
