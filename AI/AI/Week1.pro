# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Week1
DESTDIR = ../Debug
QT += core opengl widgets gui
CONFIG += debug
DEFINES += QT_DLL QWT_DLL _CRT_SECURE_NO_WARNINGS $(NOINHERIT)
INCLUDEPATH += ./GeneratedFiles/Debug
LIBS += -lkernel32 \
    -luser32 \
    -lgdi32 \
    -lwinspool \
    -lcomdlg32 \
    -ladvapi32 \
    -lshell32 \
    -lole32 \
    -loleaut32 \
    -luuid \
    -lodbc32 \
    -lodbccp32
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/Debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(Week1.pri)
