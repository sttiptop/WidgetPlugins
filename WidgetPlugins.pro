#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T10:01:28
#
#-------------------------------------------------

QT       += widgets

TARGET = WidgetPlugins
TEMPLATE = lib
DEFINES += WIDGETPLUGINS_LIBRARY
CONFIG+=build_all
SOURCES += pluginablewidget.cpp \
    pluginfactory.cpp \
    iwidgetplugin.cpp \
    csvtableplugin.cpp \
    pluginpanel.cpp \
    screenshotwidgetplugin.cpp \
    ireportplugin.cpp \
    screenshotreportplugin.cpp \
    csvtablereportplugin.cpp

HEADERS += pluginablewidget.h\
        widgetplugins_global.h \
    const_and_structs.h \
    pluginfactory.h \
    iwidgetplugin.h \
    csvtableplugin.h \
    pluginpanel.h \
    screenshotwidgetplugin.h \
    ireportplugin.h \
    screenshotreportplugin.h \
    csvtablereportplugin.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    icons.qrc
