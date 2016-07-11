#include <qmessagebox.h>
#include <qboxlayout.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    layoutWindow();
    
    for (int i = 0; i < 3; i++) {
        connect(m_exitBtn[i], SIGNAL(clicked()), SLOT(close()));
        connect(m_dlgBtn[i], SIGNAL(clicked()), SLOT(onDialog()));
    }        
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDialog()
{
	m_stackLayout->setCurrentIndex(1);

#ifdef Q_OS_WIN    
	QMessageBox msgBox(QMessageBox::Information, 
		"This is the title (optional)",
		"This is the text", 
		QMessageBox::Yes | QMessageBox::No,
		this,
		Qt::FramelessWindowHint);

	msgBox.exec();
#else
    QMessageBox::information(this, "", "This is the text");
#endif
    
	m_stackLayout->setCurrentIndex(0);
}

void MainWindow::layoutWindow()
{
    QHBoxLayout *hLayout;
    
	m_stackLayout = new QStackedLayout;
  
	m_tabWindow = new QTabWidget;
    
    for (int i = 0; i < 3; i++) {
        m_exitBtn[i] = new QPushButton("Exit");
        m_dlgBtn[i] = new QPushButton("Dialog");
        QVBoxLayout *vLayout = new QVBoxLayout;
        vLayout->addStretch();
        hLayout = new QHBoxLayout;
        hLayout->addStretch();
        hLayout->addWidget(m_dlgBtn[i]);
        hLayout->addStretch();
        vLayout->addLayout(hLayout);
        vLayout->addStretch();
        hLayout = new QHBoxLayout;
        hLayout->addStretch();
        hLayout->addWidget(m_exitBtn[i]);
        hLayout->addStretch();
        vLayout->addLayout(hLayout);
        vLayout->addStretch();
        
        QWidget *w = new QWidget;
        w->setLayout(vLayout);
        m_tabWindow->addTab(w, "Tab " + QString::number(i + 1));        
    }
      
	m_stackLayout->addWidget(m_tabWindow);
	m_stackLayout->addWidget(new QWidget);
	m_stackLayout->setCurrentIndex(0);

	centralWidget()->setLayout(m_stackLayout);
}