#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

    loadAddressApiFromFile();

    createStackOfView();
    createView();
    addViewToStack();

    connnectAllSignals();
}

MainWindow::~MainWindow()
{
}


void MainWindow::loadAddressApiFromFile()
{
    QFile file("./host.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        m_address = readAddressFromFile(file);
    }
    else
    {
        m_address = "localhost:5000";
    }
}

QString MainWindow::readAddressFromFile(QFile &file)
{
    QByteArray line = file.readAll().removeLast();
    return QString(line.toStdString().data());
}

void MainWindow::createView()
{
    m_wellcome = new Wellcome(this);
    m_selectDiscipline = new SelectDiscipline(this);
    m_selectCountry = new SelectCountry(this);
    m_result = new Result(this);
}

void MainWindow::createStackOfView()
{
    m_stackWidget = new QStackedWidget(this);
    QVBoxLayout *layaut = new QVBoxLayout(this);
    layaut->addWidget(m_stackWidget);
}

void MainWindow::addViewToStack()
{
    m_stackWidget->addWidget(m_wellcome);
    m_stackWidget->addWidget(m_selectDiscipline);
    m_stackWidget->addWidget(m_selectCountry);
    m_stackWidget->addWidget(m_result);
}

void MainWindow::connnectAllSignals()
{
    connect(m_wellcome, &BaseWidget::changeWidget, this, &MainWindow::onChangeWidget);

    connect(m_selectDiscipline, &BaseWidget::changeWidget, this, &MainWindow::onChangeWidget);
    connect(m_selectDiscipline, &SelectDiscipline::sportChosed, this, &MainWindow::onSportSelected);

    connect(m_selectCountry, &SelectCountry::changeWidget, this, &MainWindow::onChangeWidget);
    connect(m_selectCountry, &SelectCountry::countryChosed, this, &MainWindow::onCountrySelected);

    connect(m_result, &Result::changeWidget, this, &MainWindow::onChangeWidget);

    connect(&m_menager, &QNetworkAccessManager::finished,this, &MainWindow::onFinishedRequestApi);
}

void MainWindow::onChangeWidget(QWidget *widget)
{
    m_stackWidget->setCurrentWidget(widget);
}

void MainWindow::onSportSelected(QString name)
{
    m_discipline = name;
    m_selectCountry->setSelectedSport(name);
    m_stackWidget->setCurrentWidget(m_selectCountry);
}


void MainWindow::onCountrySelected(QString name)
{
    m_country = name;

    sendApiRequsest();

    m_result->setTextResult("Loading...");
    m_stackWidget->setCurrentWidget(m_result);
}

void MainWindow::sendApiRequsest()
{
    m_request.setUrl(QUrl(QString("http://%1/discipline/%2/opponent/%3").arg(m_address, m_discipline, m_country)));
    m_menager.get(m_request);
}

void MainWindow::onFinishedRequestApi(QNetworkReply *reply)
{

    if (reply->error())
    {
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
                                    "Result: %3").arg(discipline.toString(), opponent.toString(), result.toString()));

}


