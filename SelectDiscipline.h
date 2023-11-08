#ifndef SELECTDISCIPLINE_H
#define SELECTDISCIPLINE_H

#include <QtWidgets>
#include <vector>
#include <string>
#include "BaseWidget.h"
#include "PushButton.h"

class SelectDiscipline : public BaseWidget
{
    Q_OBJECT

public:
    explicit SelectDiscipline(QWidget *parent = nullptr);

signals:
    void sportChosed(std::string name);

private:
    std::vector<PushButton *> m_sportVect;
    void onSoprtClidked(std::string name);

};

#endif // SELECTDISCIPLINE_H
