#include "SelectDiscipline.h"



SelectDiscipline::SelectDiscipline(QWidget *parent) : BaseWidget{__FUNCTION__, parent}
{

    createAllObject();
    createStaticObjectAndAddToLayout();
    connectAllSignals();
}

void SelectDiscipline::createAllObject()
{
    m_mainLayout = new QVBoxLayout(this);
    m_backButton = new QPushButton("Back", this);
}

void SelectDiscipline::createStaticObjectAndAddToLayout()
{
    m_mainLayout->addWidget(new QLabel("Choose a sport",this), 0, Qt::AlignCenter);
    loadDisciplines();
    m_mainLayout->addWidget(new QWidget(this),2);
    m_mainLayout->addWidget(m_backButton);
}

void SelectDiscipline::connectAllSignals()
{
    connect(m_backButton, &QAbstractButton::clicked, this, &SelectDiscipline::onClickedBack);
}

void SelectDiscipline::loadDisciplines()
{
    m_sportVect.push_back(new PushButton("football", this));
    m_sportVect.push_back(new PushButton("volleyball", this));
    m_sportVect.push_back(new PushButton("handball", this));
    m_sportVect.push_back(new PushButton("basketball", this));

    for(auto sport : m_sportVect)
    {
        m_mainLayout->addWidget(sport);
        connect(sport, &PushButton::onClidkedWithText, this, &SelectDiscipline::onSoprtClidked);
    }

}

void SelectDiscipline::onSoprtClidked(QString name)
{
    emit sportChosed(name);
}

void SelectDiscipline::onClickedBack()
{
    emit changeWidget(getWidget("Welcome"));
}
