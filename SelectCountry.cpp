#include "SelectCountry.h"
#include <iostream>

SelectCountry::SelectCountry(QWidget *parent) : BaseWidget(__FUNCTION__, parent)
{
    readAllCountryForDysciplines();
    createAllObject();
    createStaticObjectAndAddToLayout();
    connectAllSignals();
}

void SelectCountry::setSelectedSport(QString name)
{
    m_selectedSport = name;
    m_searchCountry->setText("");
    for (const auto& countries : m_mapOfCountryVect)
        for ( auto country : countries.second)
            country->setVisible(false);

    for(auto country : m_mapOfCountryVect.at(m_selectedSport))
    {
        country->setVisible(true);
    }
}

void SelectCountry::readAllCountryForDysciplines()
{
    const std::vector<QString> dysciplines {"football", "volleyball", "handball", "basketball"};

    for (const auto& dyscipline : dysciplines)
    {
        m_mapOfCountryVect.insert({dyscipline, std::vector<PushButton *>()});
        QFile file("./Country_" + dyscipline + ".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while (!file.atEnd())
        {
            QByteArray line = file.readLine().removeLast();
            m_mapOfCountryVect.at(dyscipline).push_back(new PushButton(QString(line.toStdString().data()), this));
        }
    }
}

void SelectCountry::createAllObject()
{
    m_mainLayout = new QVBoxLayout(this);
    m_searchCountry = new QLineEdit(this);

    m_scrollarea = new QScrollArea(this);
    m_scrollWidget = new QWidget(this);
    m_layoutButtons = new QVBoxLayout(m_scrollWidget);

    m_backButton = new QPushButton("Back", this);
}

void SelectCountry::createStaticObjectAndAddToLayout()
{
    m_mainLayout->addWidget(new QLabel("Select country's representation", this), 0, Qt::AlignCenter);

    m_mainLayout->addWidget(m_searchCountry);

    m_scrollarea->setWidgetResizable(true);
    m_mainLayout->addWidget(m_scrollarea, 1);
    m_scrollarea->setWidget(m_scrollWidget );

    for (const auto& countries : m_mapOfCountryVect)
        for ( auto country : countries.second)
            m_layoutButtons->addWidget(country);
    m_mainLayout->addWidget(m_backButton);

}

void SelectCountry::connectAllSignals()
{
    for (const auto& countries : m_mapOfCountryVect)
        for ( auto country : countries.second)
            connect(country, &PushButton::onClidkedWithText, this, &SelectCountry::onCountryClidked);
    connect(m_backButton, &QAbstractButton::clicked, m_backButton, [&](){emit changeWidget(getWidget("SelectDiscipline"));});
    connect(m_searchCountry, &QLineEdit::textChanged, this, &SelectCountry::onSearchCountryTextChanged);
}


void SelectCountry::onCountryClidked(QString name)
{
    emit countryChosed(name);
}

void SelectCountry::onSearchCountryTextChanged(const QString &text)
{
    for(auto country : m_mapOfCountryVect.at(m_selectedSport))
    {
        if(!country->text().toLower().contains(text.toLower()))
            country->hide();
        else
            country->show();
    }
}

