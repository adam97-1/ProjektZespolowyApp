#include "SelectDiscipline.h"

SelectDiscipline::SelectDiscipline(QWidget *parent) : BaseWidget{__FUNCTION__, parent}
{

    m_sportVect.push_back(new PushButton("Piłka nożna", this));
    m_sportVect.push_back(new PushButton("Siatkówka", this));
    m_sportVect.push_back(new PushButton("Piłka ręczna", this));
    m_sportVect.push_back(new PushButton("Koszykówka", this));

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addWidget(new QLabel("Wybierz dyscyplinę sportu.",this), 0, Qt::AlignCenter);

    for(auto sport : m_sportVect)
    {
        layout_main->addWidget(sport);
        connect(sport, &PushButton::onClidkedWithText, this, &SelectDiscipline::onSoprtClidked);
    }

    layout_main->addWidget(new QWidget(this),2);
    QPushButton *bt_back = new QPushButton("Powrót", this);
    layout_main->addWidget(bt_back);

    connect(bt_back, &QAbstractButton::clicked, [&](){emit changeWidget(widgetMap.at("Welcome"));});
}

void SelectDiscipline::onSoprtClidked(std::string name)
{
    emit sportChosed(name);
}
