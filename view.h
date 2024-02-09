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
private:
    Ui::View *ui;
private slots:
    void on_pushButton_equal_clicked();
    void on_result_show_windowIconTextChanged(const QString &iconText);
    void on_result_show_objectNameChanged(const QString &objectName);
    void on_result_show_windowTitleChanged(const QString &title);
};

#endif // VIEW_H
