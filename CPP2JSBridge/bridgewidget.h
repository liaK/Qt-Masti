#ifndef BRIDGEWIDGET_H
#define BRIDGEWIDGET_H

#include <QtGui/QWidget>

class QWebView;
class QGridLayout;

class CWorkerClass;

class CBridgeWidget : public QWidget
{
    Q_OBJECT
    
public:
    CBridgeWidget(QWidget *parent = 0);
    ~CBridgeWidget();

public slots:

    void loadingCompleted(bool ok);

private:

    QWebView *m_WebView;
    QGridLayout *m_WidgetLayout;
    CWorkerClass *m_Worker;
};

#endif // BRIDGEWIDGET_H
