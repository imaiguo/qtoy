#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qputenv("QT_WAYLAND_SHELL_INTEGRATION", "kwayland-shell");
    setenv("PULSE_PROP_media.role", "video", 1);
    qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--disable-gpu");
    qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--single-process");
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGLES);
    format.setDefaultFormat(format);
    MainWindow w;
    w.show();

    return a.exec();
}
