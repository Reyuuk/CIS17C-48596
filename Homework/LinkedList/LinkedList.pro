TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    LnkdLst.cpp \
    main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS +=

