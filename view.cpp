#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    /*connect(ui->pushButton_plusminus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);*/

}

View::~View()
{
    delete ui;
}
double View::edit() const
{
    return ui->lineEdit->text().toDouble();

}
void View::setCalcResult(Model::CalcResult result)
{
    switch (result) {
    case Model::Ok:
        break;
    case Model::UndefinedResult:
        ui->result_show->clear();
        break;

    case Model::Error:
        // Переход на следующую секцию
    default:
        ui->result_show->setText(tr("<font color=\"red\">Ошибка при расчете!</font>"));
        break;
    }
}
void View::on_pushButton_equal_clicked()
{
    emit calcActionTriggered();
}
void View::on_lineEdit_returnPressed()
{
    emit calcActionTriggered();
}
void View::on_pushButton_dot_clicked()
{
    if(!(ui->lineEdit->text().contains('.')))
    ui->lineEdit->setText(ui->lineEdit->text()+".");
}

void View::digits_numbers()
{
    QPushButton *button=(QPushButton *)sender();
   /* double all_numbers;
    QString new_label;

    if(ui->lineEdit->text().contains(".") && button->text()=="0")
    {
        new_label=(ui->lineEdit->text()+button->text());}
    else
    {
        all_numbers=(ui->lineEdit->text()+button->text()).toDouble();
        new_label=QString::number(all_numbers, 'g', 15);
    }
        ui->lineEdit->setText(new_label);
    */
   ui->lineEdit->setText(ui->lineEdit->text()+button->text());

}

/*void View::operations()
{
    QPushButton *button=(QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if(button->text()=="+/-")
    {
        all_numbers=(ui->lineEdit->text()).toDouble();
        all_numbers=all_numbers*(-1);
        new_label=QString::number(all_numbers, 'g', 15);
        ui->lineEdit->setText(new_label);
    }else if(button->text()=="%")
    {
        all_numbers=(ui->lineEdit->text()).toDouble();
        all_numbers=all_numbers*0.01;
        new_label=QString::number(all_numbers, 'g', 15);
        ui->lineEdit->setText(new_label);
    }
}
*/
void View::on_pushButton_CE_clicked()
{
 emit clearActionTriggered();
}


void View::on_pushButton_divide_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"/");
     emit divideActionTriggered();
}


void View::on_pushButton_multiply_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"*");
     emit multiplyActionTriggered();
}


void View::on_pushButton_minus_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"-");
     emit minusActionTriggered();
}


void View::on_pushButton_plus_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"+");
     emit plusActionTriggered();
}

