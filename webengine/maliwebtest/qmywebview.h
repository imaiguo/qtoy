#ifndef QMYWEBVIEW_H
#define QMYWEBVIEW_H


#include <QWebEngineView>

class QMyWebView : public QWebEngineView
{
public:
    explicit QMyWebView();
    explicit QMyWebView(QWidget* parent = Q_NULLPTR);
protected:
    bool event(QEvent*) override;
};

#endif // QMYWEBVIEW_H
