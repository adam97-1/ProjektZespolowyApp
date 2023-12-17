#include "Result.h"

Result::Result(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    createAllObject();
    createStaticObjectAndAddToLayout();
    connectAllSignals();
}

void Result::setTextResult(QString text)
{
    m_ResultLabel->setText(text);
}

void Result::createAllObject()
{
    m_mainLayout = new QVBoxLayout(this);
    m_backButton = new QPushButton("Back", this);
}

void Result::createStaticObjectAndAddToLayout()
{
    QLabel *label = new QLabel("The predicted result is:",this);

    m_mainLayout->addWidget(label, 0, Qt::AlignHCenter);

    m_ResultLabel = new QLabel("Loading...",this);
    m_mainLayout->addWidget(m_ResultLabel, 0, Qt::AlignHCenter);

    m_mainLayout->addWidget(new QWidget(this),2);

    m_mainLayout->addWidget(m_backButton);
}

void Result::connectAllSignals()
{
    connect(m_backButton, &QPushButton::clicked, this, &Result::onBackClidked);
}

void Result::onBackClidked()
{
    emit changeWidget(widgetMap.at("SelectCountry"));
}
