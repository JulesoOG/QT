QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    actionpoint.cpp \
    bezier.cpp \
    beziercreator.cpp \
    bspline.cpp \
    drawer.cpp \
    floodfill.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    pixel.cpp \
    pixelmetrics.cpp \
    shapeincircle.cpp \
    sketch.cpp

HEADERS += \
    actionpoint.h \
    bezier.h \
    beziercreator.h \
    bspline.h \
    drawer.h \
    floodfill.h \
    line.h \
    mainwindow.h \
    pixel.h \
    pixelmetrics.h \
    shapeincircle.h \
    sketch.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
