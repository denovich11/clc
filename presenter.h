#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include "model.h"

class Intf;

class Presenter : public QObject
{
    Q_OBJECT

public:
    explicit Presenter(Intf *view, QObject *parent = 0);

private:
    void refreshView() const;

    Model *m_model;
    Intf *m_view;

private slots:
    void processCalcAction();
};

#endif // PRESENTER_H
