#ifndef PLUGIN_H
#define PLUGIN_H

#include "skydel_plug_ins/skydel_plugin.h"

// Plugin implementation
class Plugin : public QObject, public SkydelCoreInterface
{
  Q_OBJECT

public:
  // SkydelCoreInterface
  inline void setLogPath(const QString&) override {}
  inline void setNotifier(SkydelNotifierInterface*) override {}
  inline void setConfiguration(const QString&, const QJsonObject&) override {}
  inline QJsonObject getConfiguration() const override { return {}; }
  inline QWidget* createUI() override { return nullptr; }
  inline void initialize() override {}
};

// Required boilerplate
class PluginFactory : public QObject, public SkydelPlugin<Plugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "Plugin" FILE "plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // PLUGIN_H
