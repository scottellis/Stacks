#include <qmessagebox.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    connect(ui->actionExit, SIGNAL(triggered()), SLOT(close()));
	connect(ui->actionDialog, SIGNAL(triggered()), SLOT(onDialog()));

	layoutWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onDialog()
{
	m_stackLayout->setCurrentIndex(1);

#ifdef Q_OS_WINDOWS
	QMessageBox msgBox(QMessageBox::Information, 
		"This is the title (optional)",
		"This is the text", 
		QMessageBox::Yes | QMessageBox::No,
		this,
		Qt::FramelessWindowHint);

	msgBox.exec();
#else
	QMessageBox::information(this,
		"This is the title(not shown)",
		"This is the dialog text");
#endif

	m_stackLayout->setCurrentIndex(0);
}

void MainWindow::layoutWindow()
{
	m_stackLayout = new QStackedLayout;

	m_tabWindow = new QTabWidget;
	m_tabWindow->addTab(new QWidget, "Tab 1");
	m_tabWindow->addTab(new QWidget, "Tab 2");
	m_tabWindow->addTab(new QWidget, "Tab 3");

	m_stackLayout->addWidget(m_tabWindow);
	m_stackLayout->addWidget(new QWidget);
	m_stackLayout->setCurrentIndex(0);

	centralWidget()->setLayout(m_stackLayout);
}
