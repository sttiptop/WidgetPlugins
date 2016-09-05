#ifndef SCREENSHOTREPORTPLUGIN_H
#define SCREENSHOTREPORTPLUGIN_H

#include "ireportplugin.h"
#include "iwidgetplugin.h"
#include <QApplication>
#include <QClipboard>
#include <QPushButton>
#include <QWidget>
#include <QObject>
namespace WidgetPlugins
{

class ScreenShotReportPlugin:public IReportPlugin
{
    Q_OBJECT
public:
    ScreenShotReportPlugin(QString fileName, QWidget *parent);
private:
    QPushButton *_btn=nullptr;
    // IWidgetPlugin interface
public:
    QWidget *getControl();
public slots:
    void handleScreenShot(bool);
};
}
#endif // SCREENSHOTREPORTPLUGIN_H
