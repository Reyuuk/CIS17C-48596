TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    DblLnkLst.h \
    Stack.h \
    Queue.h \
    CircularList.h \
    PriorityList.h \
    SortedList.h

