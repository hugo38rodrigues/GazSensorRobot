QT -= gui

TEMPLATE = lib
DEFINES += ROBOT_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    IRSensor.cpp \
    Moteur.cpp \
    Near_sensor.cpp \
    Robot.cpp \
    SpeedBox.cpp \
    cosensor.cpp \
    jail.cpp

HEADERS += \
    IRSensor.h \
    Moteur.h \
    Near_sensor.h \
    Robot.h \
    Robot_global.h \
    SpeedBox.h \
    cosensor.h \
    jail.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
