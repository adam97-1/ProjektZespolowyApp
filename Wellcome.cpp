#include "Wellcome.h"

Wellcome::Wellcome(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    createAllObject();
    createStaticObjectAndAddToLayout();

    connectAllSignals();

}

void Wellcome::onStartClidked()
{
    emit changeWidget(getWidget("SelectDiscipline"));
}

void Wellcome::createAllObject()
{

    m_Mainleyaut = new QVBoxLayout(this);
    m_startButton = new QPushButton("Start", this);
}

void Wellcome::createStaticObjectAndAddToLayout()
{
    QLabel *label = new QLabel("Wellcome to the application for predicting the results of sports games of the Polish national team.",this);
    label->setWordWrap(true);
    m_Mainleyaut->addWidget(label, 0, Qt::AlignHCenter);
    m_Mainleyaut->addWidget(m_startButton);
}

void Wellcome::connectAllSignals()
{
    connect(m_startButton, &QPushButton::clicked, this, &Wellcome::onStartClidked);
}
