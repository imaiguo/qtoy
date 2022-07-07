QT       += core gui widgets

TARGET = test
TEMPLATE = app

SOURCES += main.cpp


# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
INSTALLS += target
