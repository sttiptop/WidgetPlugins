#include "pluginpanel.h"
#include "screenshotwidgetplugin.h"
namespace WidgetPlugins
{
ScreenShotWidgetPlugin::ScreenShotWidgetPlugin(QWidget *parent)
{
    setParent(parent);
    _wgt=parent;
    _btn=new QPushButton(_wgt);
    _btn->setStyleSheet("QPushButton{"
                        "border-image: url(:/icons/screenShot.png);"
                        "border-radius: 2px;"
                        "text-align:center;"
                        "}"
                        "QPushButton:hover{"
                        "border-image: url(:/icons/screenShotPressed.png);"
                        "border-radius: 2px;"
                        "}"
                        "QPushButton:pressed{"
                        "border-image: url(:/icons/screenShotPressed.png);"
                        "border-radius: 1px;"
                        "margin:2px;"
                        "}");
    connect(_btn,SIGNAL(clicked(bool)),this,SLOT(handleScreenShot(bool)));
}

QWidget *ScreenShotWidgetPlugin::getControl()
{
    return _btn;
}

void ScreenShotWidgetPlugin::handleScreenShot(bool)
{
    PluginPanel *_panel;
    _panel=_wgt->findChild<PluginPanel*>();
    _panel->hide();
    QPixmap pixmap=_wgt->grab();
    QClipboard *clipboard= QApplication::clipboard();
    clipboard->setPixmap(pixmap);
    _panel->show();
}

}
