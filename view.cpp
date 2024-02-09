#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
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
