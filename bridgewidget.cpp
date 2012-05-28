#include "bridgewidget.h"
#include "workerclass.h"

#include <QWebView>
#include <QGridLayout>
#include <QWebFrame>
#include <QMessageBox>

CBridgeWidget::CBridgeWidget(QWidget *parent)
    : QWidget(parent)
{
    m_WebView = new QWebView();
    m_WidgetLayout = new QGridLayout(this);

    m_Worker = new CWorkerClass();
    m_WidgetLayout->addWidget(m_WebView,0,0,1,1,Qt::AlignCenter);

    m_WebView->load(QUrl("qrc:///webFiles/InputGetter.html"));
    m_WebView->page()->mainFrame()->addToJavaScriptWindowObject("CPPWorker",m_Worker);

    QObject::connect(m_WebView,SIGNAL(loadFinished(bool)),this,SLOT(loadingCompleted(bool)));
}

void CBridgeWidget::loadingCompleted(bool ok)
{
    Q_UNUSED(ok)
    QVariant returnedValue = m_WebView->page()->mainFrame()->evaluateJavaScript("valuesEntered()");
    QMessageBox::information(0,"From JS",returnedValue.toString(),QMessageBox::Ok);
}

CBridgeWidget::~CBridgeWidget()
{
    
}
