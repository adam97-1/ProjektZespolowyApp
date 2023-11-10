#include "MainWindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

    resize(600,600);

    QFile file("./host.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray line = file.readAll().removeLast();
        m_address = QString(line.toStdString().data());
    }
    else
    {
        m_address = "localhost:5000";
    }
    m_welcome = new Welcome(this);
    m_selectDiscipline = new SelectDiscipline(this);
    m_selectCountry = new SelectCountry(this);
    m_result = new Result(this);


    m_stackWidget = new QStackedWidget(this);
    QVBoxLayout *layaut = new QVBoxLayout(this);
    layaut->addWidget(m_stackWidget);

    m_stackWidget->addWidget(m_welcome);
    m_stackWidget->addWidget(m_selectDiscipline);
    m_stackWidget->addWidget(m_selectCountry);
    m_stackWidget->addWidget(m_result);

    connect(m_welcome, &BaseWidget::changeWidget, this, &MainWindow::onChangeWidget);

    connect(m_selectDiscipline, &BaseWidget::changeWidget, this, &MainWindow::onChangeWidget);
    connect(m_selectDiscipline, &SelectDiscipline::sportChosed, this, &MainWindow::onSportSelected);

    connect(m_selectCountry, &SelectCountry::changeWidget, this, &MainWindow::onChangeWidget);
    connect(m_selectCountry, &SelectCountry::countryChosed, this, &MainWindow::onCountrySelected);

    connect(m_result, &Result::changeWidget, this, &MainWindow::onChangeWidget);

    QObject::connect(&m_menager, &QNetworkAccessManager::finished,
                     this, [=](QNetworkReply *reply) {
                         if (reply->error()) {
                             m_result->setTextResult("Error of connection");
                             return;
                         }

                         QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
                         QJsonObject object = document.object();
                         QJsonValue discipline = object.value(QString("discipline"));
                         QJsonValue opponent = object.value(QString("opponent"));
                         QJsonValue result = object.value(QString("result"));

                         m_result->setTextResult(QString("Soprt: %1\n"
                                                         "Opponent: %2\n"
                                                         "Result: %3").arg(discipline.toString()).arg(opponent.toString()).arg(result.toString()));

                     }
                     );



}

MainWindow::~MainWindow()
{
}

void MainWindow::onChangeWidget(QWidget *widget)
{
    m_stackWidget->setCurrentWidget(widget);
}

void MainWindow::onSportSelected(std::string name)
{
    m_discipline = QString(name.data());
    m_stackWidget->setCurrentWidget(m_selectCountry);
}

void MainWindow::onCountrySelected(std::string name)
{
    m_country = QString(name.data());


    m_request.setUrl(QUrl(QString("http://%1/discipline/%2/opponent/%3").arg(m_address).arg(m_discipline).arg(m_country)));
    m_menager.get(m_request);
    m_result->setTextResult("Loading...");
    m_stackWidget->setCurrentWidget(m_result);
}


