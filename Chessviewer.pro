QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    adddialog.cpp \
    filterdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    adddialog.h \
    common.h \
    filterdialog.h \
    mainwindow.h

FORMS += \
    adddialog.ui \
    filterdialog.ui \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
