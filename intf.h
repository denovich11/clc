#ifndef INTF_H
#define INTF_H

#include "model.h"

class Intf
{
public:
    virtual double edit() const = 0;
    virtual void setCalcResult(Model::CalcResult result) = 0;

public: // signals
    virtual void calcActionTriggered() = 0;
};

#endif // INTF_H
