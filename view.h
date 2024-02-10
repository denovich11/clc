#ifndef VIEW_H
#define VIEW_H
#include "intf.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow, public Intf
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    double edit() const;
    void setCalcResult(Model::CalcResult result);
signals:
    void calcActionTriggered();
    void clearActionTriggered();
    void divideActionTriggered();
    void multiplyActionTriggered();
    void plusActionTriggered();
    void minusActionTriggered();
private:
    Ui::View *ui;
private slots:
    void on_pushButton_equal_clicked();
   // void on_result_show_windowIconTextChanged(const QString &iconText);
   // void on_result_show_objectNameChanged(const QString &objectName);
   //void on_result_show_windowTitleChanged(const QString &title);
    void on_pushButton_dot_clicked();
    void digits_numbers();
    void on_lineEdit_returnPressed();
   // void operations();
    void on_pushButton_CE_clicked();
    //void math_operations();
    void on_pushButton_divide_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_plus_clicked();
};

#endif // VIEW_H
