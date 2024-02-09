#include "presenter.h"
#include "intf.h"

Presenter::Presenter(Intf *view, QObject *parent)
    : QObject(parent), m_model(new Model), m_view(view)
{
    QObject *view_obj = dynamic_cast<QObject*>(m_view);
    QObject::connect(view_obj, SIGNAL(calcActionTriggered()),
                     this, SLOT(processCalcAction()));
    refreshView();
}

void Presenter::refreshView() const
{
    m_view->setCalcResult(m_model->result());
    //if (m_model->result() == Model::Ok)
    //    m_view->setSection(m_model->section());
}
void Presenter::processCalcAction()
{
    m_model->setEdit(m_view->edit());
    m_model->calc();
    refreshView();
}
