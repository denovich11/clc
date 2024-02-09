#include "model.h"

void Model::calc()
{

}

Model::CalcResult Model::result() const
{
    return m_result;
}
Model::Model()
    :  m_result(UndefinedResult), m_edit(0)
{
}

void Model::setEdit(double edit)
{
    m_edit = edit;
}

