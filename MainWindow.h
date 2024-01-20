#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtNetwork>
#include <QJsonDocument>
#include <iostream>
#include "Wellcome.h"
#include "SelectDiscipline.h"
#include "SelectCountry.h"
#include "Result.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createView();


private:

    QStackedWidget *m_stackWidget {nullptr};
    Wellcome *m_wellcome {nullptr};
    SelectDiscipline *m_selectDiscipline {nullptr};
    SelectCountry *m_selectCountry {nullptr};
    Result *m_result {nullptr};

    QNetworkAccessManager m_menager;
    QNetworkRequest m_request;

    QString m_discipline;
    QString m_country;
    QString m_address;

    void onChangeWidget(QWidget *widget);
    void onSportSelected(QString name);
    void onCountrySelected(QString name);
    void onFinishedRequestApi(QNetworkReply *reply);
    QString readAddressFromFile(QFile &file);
    void loadAddressApiFromFile();
    void createStackOfView();
    void addViewToStack();
    void connnectAllSignals();
    void sendApiRequsest();
};
#endif // MAINWINDOW_H
