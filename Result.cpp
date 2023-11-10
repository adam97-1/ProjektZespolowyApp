#include "Result.h"

Result::Result(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    QVBoxLayout *leyaut = new QVBoxLayout(this);
    QLabel *label = new QLabel("The predicted result is:",this);
    leyaut->addWidget(label, 0, Qt::AlignHCenter);
    m_label_result = new QLabel("Loading...",this);
    leyaut->addWidget(m_label_result, 0, Qt::AlignHCenter);
    leyaut->addWidget(new QWidget(this),2);
    QPushButton *bt = new QPushButton("Back", this);
    leyaut->addWidget(bt);

    connect(bt, &QPushButton::clicked, this, &Result::onBackClidked);
}

void Result::setTextResult(QString text)
{
    m_label_result->setText(text);
}

void Result::onBackClidked()
{
    emit changeWidget(widgetMap.at("SelectCountry"));
}
