#include "styling.h"

#include "global/config.h"

bool hitvidio::styling::UseDarkIcons()
{
  return hitvidio::CurrentConfig.style == kHitvidioDefaultLight || hitvidio::CurrentConfig.style == kNativeDarkIcons;
}

QColor hitvidio::styling::GetIconColor()
{
  if (UseDarkIcons()) {
    return Qt::black;
  } else {
    return Qt::white;
  }
}



bool hitvidio::styling::UseNativeUI()
{
  return hitvidio::CurrentConfig.style == kNativeLightIcons || hitvidio::CurrentConfig.style == kNativeDarkIcons;
}