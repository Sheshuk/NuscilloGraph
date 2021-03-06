#-------------------------------------------------
#
# Project created by QtCreator 2014-02-25T13:34:34
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nuscillograph
TEMPLATE = app


SOURCES += main.cpp\
        nuoscwindow.cpp \
    gl_scene.cpp \
    matrixwidget.cpp \
    expedit.cpp \
    mathutf.cpp


HEADERS  += nuoscwindow.h \
    gl_scene.h \
    Mcomplex.h \
    matrixwidget.h \
    expedit.h \
    mathutf.h

OTHER_FILES += \
    shader/nuosc3.frag \
    shader/nuosc3.vert \
    shader/nuosc3.f120 \
    shader/nuosc3.v120 \
    shader/nuosc.frag \
    shader/nuosc.vert
