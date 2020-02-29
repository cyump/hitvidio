#include "menu.h"

#include "global/global.h"
#include "global/config.h"

Menu::Menu(QWidget *parent) :
  QMenu(parent)
{
  if (hitvidio::CurrentConfig.use_native_menu_styling) {
    HitvidioGlobal::SetNativeStyling(this);
  }
}

Menu::Menu(const QString &title, QWidget *parent) :
  QMenu(title, parent)
{
  if (hitvidio::CurrentConfig.use_native_menu_styling) {
    HitvidioGlobal::SetNativeStyling(this);
  }
}