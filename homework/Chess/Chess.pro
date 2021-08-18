QT       += core gui core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    globalvariable.cpp \
    main.cpp \
    mainwindow.cpp \
    mychess.cpp \
    mydialog.cpp \
    mylabel.cpp \
    webdialog.cpp

HEADERS += \
    globalvariable.h \
    mainwindow.h \
    mychess.h \
    mydialog.h \
    mylabel.h \
    webdialog.h

FORMS += \
    mainwindow.ui \
    mychess.ui \
    mydialog.ui \
    webdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Image.qrc


