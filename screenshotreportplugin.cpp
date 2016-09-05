#include "screenshotreportplugin.h"
#include "QDebug"
#include "pluginpanel.h"
#include <QFile>
#include <QTextDocumentWriter>

namespace WidgetPlugins
{
ScreenShotReportPlugin::ScreenShotReportPlugin(QString fileName,QWidget *parent)
{
    setParent(parent);
    _wgt=parent;
    _fileName=fileName;
    _btn=new QPushButton(_wgt);
    _btn->setStyleSheet("QPushButton{"
                        "border-image: url(:/icons/screenShotToFile.png);"
                        "border-radius: 2px;"
                        "color:red;"
                        "text-align:center;"
                        "}"
                        "QPushButton:hover{"
                        "border-image: url(:/icons/screenShotToFilePressed.png);"
                        "border-radius: 2px;"
                        "}"
                        "QPushButton:pressed{"
                        "border-image: url(:/icons/screenShotToFilePressed.png);"
                        "border-radius: 1px;"
                        "margin:2px;"
                        "}");
    connect(_btn,SIGNAL(clicked(bool)),this,SLOT(handleScreenShot(bool)));
}

QWidget *ScreenShotReportPlugin::getControl()
{
    return _btn;
}
void ScreenShotReportPlugin::handleScreenShot(bool)
{
    PluginPanel *_panel;
    _panel=_wgt->findChild<PluginPanel*>();
    _panel->hide();
    QPixmap _pixmap=_wgt->grab();
    ReportDocument::getInstance().addImage(_pixmap.toImage());
    _panel->show();
}
}
