#include "qmywebview.h"
#include <QDebug>
#include <iostream>
#include <QEvent>
#include <QOpenGLContext>

QMyWebView::QMyWebView()
{

}

QMyWebView::QMyWebView(QWidget* parent):QWebEngineView(parent){

}

bool QMyWebView::event(QEvent* e){

    std::cout<< "---mag---QMyWebView::event-------("<<e->type()<<")"<<std::endl;
    if(QEvent::Close == e->type()){
    if(QOpenGLContext *current = QOpenGLContext::currentContext()){
            std::cout<<"---doneCurrent()---doing---"<<std::endl;
            current->doneCurrent();
        }
    }
    return QWebEngineView::event(e);
}

