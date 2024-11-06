QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Controller/controller.cpp \
    ../Model/parser/parser.cc \
    ../Model/strategy/strategy.cc \
    edgessettings.cpp \
    glscene.cpp \
    main.cpp \
    readfileinfo.cpp \
    settingswidgets.cpp \
    slidersettings.cpp \
    vertecissettings.cpp \
    viewwindow.cpp \
    widgetanimation.cpp

HEADERS += \
    ../Controller/controller.h \
    ../Model/model.h \
    ../Model/parser/parser.h \
    ../Model/strategy/strategy.h \
    defineview.h \
    edgessettings.h \
    gif.h \
    glscene.h \
    readfileinfo.h \
    settingswidgets.h \
    slidersettings.h \
    vertecissettings.h \
    viewwindow.h \
    widgetanimation.h

FORMS += \
    viewwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
