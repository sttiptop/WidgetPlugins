#include "pluginpanel.h"
#include "QDebug"
namespace WidgetPlugins {
PluginPanel::PluginPanel(PluginInPlace place, QColor color, QWidget *parent)

{
    QPalette _palette;
    _palette.setColor(QPalette::Window,color);
    this->setPalette(_palette);
    this->setAutoFillBackground(true);
    switch(place){
    case PluginInPlace::verticalLeft:
        _panelLayout=new QVBoxLayout;
        break;
    case PluginInPlace::horizontalTop:
        _panelLayout=new QHBoxLayout;
        break;
    case PluginInPlace::verticalRight:
        _panelLayout=new QVBoxLayout;
        break;
    case PluginInPlace::horizontalBottom:
        _panelLayout=new QHBoxLayout;
        break;
    }
     this->setParent(parent);
    _panelLayout->setMargin(2);
    _panelLayout->setSpacing(0);
    _panelLayout->addStretch();
    setLayout(_panelLayout);


}

void PluginPanel::addWidgetAtPanel(QWidget *wgt)
{
    wgt->setFixedSize(20,20);
    _panelLayout->addWidget(wgt);
    resize(minimumSizeHint());
}

void PluginPanel::enterEvent(QEvent */*event*/)
{
    emit enter();
}

void PluginPanel::leaveEvent(QEvent */*event*/)
{
    emit drop(2000);

}

void PluginPanel::paintEvent(QPaintEvent */*event*/)
{
    resize(minimumSizeHint());

}
}
