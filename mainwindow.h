#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qstackedlayout.h>
#include <qtabwidget.h>

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
};

#endif // MAINWINDOW_H
