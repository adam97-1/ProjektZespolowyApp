#include "SelectDiscipline.h"

SelectDiscipline::SelectDiscipline(QWidget *parent) : BaseWidget{__FUNCTION__, parent}
{

    m_sportVect.push_back(new PushButton("footbal", this));
    m_sportVect.push_back(new PushButton("volleyball", this));
    m_sportVect.push_back(new PushButton("handball", this));
    m_sportVect.push_back(new PushButton("basketball", this));

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addWidget(new QLabel("Choose a sport",this), 0, Qt::AlignCenter);

    for(auto sport : m_sportVect)
    {
        layout_main->addWidget(sport);
        connect(sport, &PushButton::onClidkedWithText, this, &SelectDiscipline::onSoprtClidked);
    }

    layout_main->addWidget(new QWidget(this),2);
    QPushButton *bt_back = new QPushButton("Back", this);
    layout_main->addWidget(bt_back);

    connect(bt_back, &QAbstractButton::clicked, [&](){emit changeWidget(widgetMap.at("Welcome"));});
}

void SelectDiscipline::onSoprtClidked(std::string name)
{
    emit sportChosed(name);
}
