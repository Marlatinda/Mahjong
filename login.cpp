#include "loging.h"
#include "ui_loging.h"
#include "mainwindow.h"

loging::loging(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loging)
{
    ui->setupUi(this);

    setWindowTitle("游戏登陆");
    QPixmap pixmap = QPixmap(":/images/images/c.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    loginSound.setSource(QUrl::fromLocalFile(":sounds/sounds/login.wav"));
}

loging::~loging()
{
    delete ui;
}

void loging::on_pushButton_clicked()
{
   if(ui->account->text()=="123" && ui->password->text()=="123"){
       this->close();
       loginSound.play();
       MainWindow* w=new MainWindow();
       w->show();
   }else
       ui->infor->setText("账号或密码不正确");

}

void loging::on_pushButton_3_clicked()
{
    exit(0);
}
