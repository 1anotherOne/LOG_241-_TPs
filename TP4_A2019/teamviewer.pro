# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = teamviewer
DESTDIR = ./debug
QT += core gui widgets printsupport
CONFIG += debug
DEFINES += _WINDOWS _UNICODE _ENABLE_EXTENDED_ALIGNED_STORAGE WIN64 QT_PRINTSUPPORT_LIB QT_WIDGETS_LIB
INCLUDEPATH += . \
    ./debug \
    ../../../../../VulkanSDK/1.0.51.0/include \
    $(QTDIR)/mkspecs/win32-msvc
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(teamviewer.pri)