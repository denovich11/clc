#ifndef MODEL_H
#define MODEL_H

class Model
{
public:
    enum CalcResult {
        UndefinedResult = 0, /*!< Результат не определен */
        Error        ,        /*!< Ошибка при расчете */
        Ok /*расчет успешно проведен*/
    };

public:

    Model();
    void calc();
    CalcResult result() const;
    void setEdit(double edit);

private:
    CalcResult m_result;
    double m_edit;

};

#endif // MODEL_H
