#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSize sizeHint() const;
    QLineEdit* email;
    QLineEdit* phonenum;
protected:
    void resizeEvent(QResizeEvent* ev) override;
protected slots:
    void etch(const QString&);
    void ptch(const QString&);
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
