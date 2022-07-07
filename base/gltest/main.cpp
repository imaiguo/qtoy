#include <QApplication>
#include <QOpenGLWindow>

class Window : public QOpenGLWindow {
    void paintGL() override {
        glClearColor(parent() ? 0 : 1,0,parent() ? 1 : 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
    }
};

int main(int argc, char *argv[])
{

    qputenv("QT_WAYLAND_SHELL_INTEGRATION", "kwayland-shell");
    setenv("PULSE_PROP_media.role", "video", 1);
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setRenderableType(QSurfaceFormat::OpenGLES);
    QSurfaceFormat::setDefaultFormat(format);

    Window w1;
    Window w2;

    w2.setParent(&w1);

    w1.resize(200,200);
    w2.resize(100,100);

    w2.show();
    w1.show();

    return app.exec();
}
