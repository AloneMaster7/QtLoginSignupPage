#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QDebug>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Login/Sign-up");
    this->setStyleSheet("background-image: url(b.jpg);color: black;padding: 10px;");
    this->statusBar()->showMessage("Welcome , Enter your user&pass or if you don't have ,"
                                   " make it ;)",10000);

    QTabWidget* tb = new QTabWidget;
    tb->setObjectName("tb");
    tb->setTabShape(QTabWidget::Triangular);
    tb->setTabPosition(QTabWidget::West);
    this->setCentralWidget(tb);

    QWidget* login = new QWidget(this);
    QFormLayout* fl = new QFormLayout;
    fl->setFormAlignment(Qt::AlignCenter);
    //login->setStyleSheet("padding: 20px");
    login->setLayout(fl);
    login->setStyleSheet("QLineEdit {margin: 5px;margin-right:60px;background-color: black;color: blue;"
                         "margin-top: 20px;border: 1px solid aqua;"
                         "border-radius: 10px}"
                         "QLabel {margin: 5px;margin-left: 60px;margin-top: 20px;border-radius: 10px}"
                         "QPushButton {margin: 5px;margin-top: 20px;border-radius: 10px;"
                         "margin-left: 220px;margin-right: 60px}"
                         "QPushButton:pressed {color: red}");
    QLineEdit* username = new QLineEdit;
    username->setPlaceholderText("Username");
    fl->addRow(new QLabel("Username : "),username);
    QLineEdit* le = new QLineEdit();
    le->setEchoMode(QLineEdit::Password);
    le->setPlaceholderText("Password");
    fl->addRow(new QLabel("Password : "),le);
    QPushButton* loginpb = new QPushButton("Login");
    loginpb->setCursor(Qt::PointingHandCursor);
    fl->addWidget(loginpb);
    tb->addTab(login,"Login");

    QWidget* SignUp = new QWidget(this);
    tb->addTab(SignUp,"Sign up");
    QFormLayout* fl2 = new QFormLayout;
    fl2->setFormAlignment(Qt::AlignCenter);
    SignUp->setLayout(fl2);
    SignUp->setStyleSheet("QLineEdit {margin: 5px;margin-right:60px;background-color: black;color: blue;"
                         "margin-top: 5px;border: 1px solid aqua;"
                         "border-radius: 10px}"
                         "QLabel {margin: 5px;margin-left: 60px;margin-top: 5px;border-radius: 10px}"
                         "QPushButton {margin: 5px;margin-top: 5px;border-radius: 10px;"
                         "margin-left: 220px;margin-right: 60px}"
                         "QPushButton:pressed {color: red}"
                         "QRadioButton {margin-left: 50px;margin-right: 50px}"
                         "QGroupBox {margin-left: 60px;margin-right: 200px}");

    QLineEdit* name = new QLineEdit;
    name->setPlaceholderText("Name");
    fl2->addRow(new QLabel("Name : "),name);
    this->email = new QLineEdit;
    QObject::connect(this->email,SIGNAL(textChanged(const QString &)),this,
                     SLOT(etch(const QString&)));
    this->email->setPlaceholderText("E-mail");
    fl2->addRow(new QLabel("E-mail : "),this->email);
    QGroupBox* gb = new QGroupBox;
    gb->setTitle("Gender");
    QButtonGroup* bg = new QButtonGroup;
    bg->addButton(new QRadioButton("Male"),0);
    bg->addButton(new QRadioButton("Female"),1);
    QGridLayout* gl = new QGridLayout(gb);
    gl->addWidget(bg->button(0),0,0);
    gl->addWidget(bg->button(1),0,1);
    fl2->addRow(gb);
    QLineEdit* pass = new QLineEdit;
    QLineEdit* reEnter = new QLineEdit;
    pass->setPlaceholderText("Password");
    reEnter->setPlaceholderText("Re-enter password");
    pass->setEchoMode(QLineEdit::Password);
    reEnter->setEchoMode(QLineEdit::Password);
    fl2->addRow(new QLabel("Password : "),pass);
    fl2->addRow(new QLabel("Re-enter Password : "),reEnter);
    this->phonenum = new QLineEdit;
    this->phonenum->setPlaceholderText("Phone Number");
    QObject::connect(this->phonenum,SIGNAL(textChanged(const QString&)),this,
                     SLOT(ptch(const QString&)));
    fl2->addRow(new QLabel("Phone Number : "),this->phonenum);
    fl2->addWidget(new QPushButton("Sign up"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(800,600);
}

void MainWindow::resizeEvent(QResizeEvent *ev)
{
    this->resize(QSize(800,600));
}

void MainWindow::etch(const QString &text)
{
    QRegExp reg("[a-zA-Z]+[a-zA-Z0-9._]*[a-zA-Z0-9]+@[a-zA-Z]+[.]{1}[a-zA-Z]{2,4}");
    if(reg.exactMatch(text)){
        this->email->setStyleSheet("color: green");
    }else{
        this->email->setStyleSheet("color: red");
    }
}

void MainWindow::ptch(const QString &text)
{
    QRegExp reg1("09[0-9]{9}");
    QRegExp reg2("+989[0-9]{9}");
    if(reg1.exactMatch(text) || reg2.exactMatch(text)){
        this->phonenum->setStyleSheet("color: green");
    }else{
        this->phonenum->setStyleSheet("color: red");
    }
}

