#include "Welcome.h"



Welcome::Welcome(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    createAllObject();
    createStaticObjectAndAddToLayout();

    connectAllSignals();

}

void Welcome::onStartClidked()
{
    emit changeWidget(getWidget("SelectDiscipline"));
}

void Welcome::createAllObject()
{

    m_Mainleyaut = new QVBoxLayout(this);
    m_startButton = new QPushButton("Start", this);
}

void Welcome::createStaticObjectAndAddToLayout()
{
    QLabel *label = new QLabel("Welcome to the application for predicting the results of sports games of the Polish national team.",this);
    label->setWordWrap(true);
    m_Mainleyaut->addWidget(label, 0, Qt::AlignHCenter);
    m_Mainleyaut->addWidget(m_startButton);
}

void Welcome::connectAllSignals()
{
    connect(m_startButton, &QPushButton::clicked, this, &Welcome::onStartClidked);
}
