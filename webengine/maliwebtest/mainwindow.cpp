#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmywebview.h"

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QOpenGLContext>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QWebEngineView *view = new QWebEngineView;

    layout->addWidget(view);

    view->load(QUrl("https://www.gov.cn/index.htm"));

    this->centralWidget()->setLayout(layout);


    QPushButton *button = new QPushButton("弹窗", this);
    connect(button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);

    this->resize(800, 600);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMyWebView *view = new QMyWebView(nullptr);

    view->load(QUrl("https://www.gov.cn/index.htm"));
    view->show();

}
