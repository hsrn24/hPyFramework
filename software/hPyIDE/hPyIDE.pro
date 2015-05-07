#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T19:48:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hPyIDE
TEMPLATE = app

CONFIG += qscintilla2

INCLUDEPATH += port/linux/ /usr/include/libusb-1.0/

LIBS += -lusb-1.0 -lpthread

SOURCES += main.cpp\
        MainWindow.cpp \
    SettingsDialog.cpp \
    myFTDI.cpp \
    port/linux/timeutil.cpp \
    port/linux/ftdi_stream.c \
		port/linux/ftdi.c \
		FTDI.cpp

HEADERS  += MainWindow.h \
    SettingsDialog.h \
    myFTDI.h \
    port/linux/ftdi_version_i.h \
    port/linux/ftdi_i.h \
		port/linux/ftdi.h \
		FTDI.h

FORMS    += MainWindow.ui \
    SettingsDialog.ui
