#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qstackedlayout.h>
#include <qtabwidget.h>
#include <qpushbutton.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void onDialog();
    
private:
    void layoutWindow();
    
    Ui::MainWindow *ui;
    
    QStackedLayout *m_stackLayout;
	QTabWidget *m_tabWindow;    
    QPushButton *m_exitBtn[3];
    QPushButton *m_dlgBtn[3];
};

#endif // MAINWINDOW_H
