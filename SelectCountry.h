#ifndef SELECTCOUNTRY_H
#define SELECTCOUNTRY_H

#include <QtWidgets>
#include <vector>
#include <map>
#include "BaseWidget.h"
#include "PushButton.h"

class SelectCountry : public BaseWidget
{
Q_OBJECT

public:
    explicit SelectCountry(QWidget *parent = nullptr);
    void setSelectedSport(QString name);

signals:
    void countryChosed(QString name);

private:
    QString m_selectedSport {"foodball"};
    std::map<QString, std::vector<PushButton *>> m_mapOfCountryVect;
    QVBoxLayout *m_mainLayout {nullptr};
    QScrollArea *m_scrollarea {nullptr};
    QWidget * m_scrollWidget {nullptr};
    QVBoxLayout *m_layoutButtons {nullptr};
    QLineEdit *m_searchCountry  {nullptr};
    QPushButton *m_backButton {nullptr};

    void readAllCountryForDysciplines();
    void createAllObject();
    void createStaticObjectAndAddToLayout();
    void connectAllSignals();
    void onCountryClidked(QString name);
    void onSearchCountryTextChanged(const QString &text);
};

#endif // SELECTCOUNTRY_H
