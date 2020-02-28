/***

    Hitvidio - Non-Linear Video Editor
    Copyright (C) 2020  Hitvidio Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#include "aboutdialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>

#include "global/global.h"

AboutDialog::AboutDialog(QWidget *parent) :
  QDialog(parent)
{
  setWindowTitle("About Hitvidio");

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->setSpacing(20);

  // Construct About text
  QLabel* label =
      new QLabel(QString("<html><head/><body>"
                         "<p><img src=\":/icons/hitvidio-splash.png\"/></p>"
                         "<p><a href=\"https://www.hitvid.io/\">"
                         "<span style=\" text-decoration: underline; color:#007af4;\">"
                         "https://www.hitvid.io/"
                         "</span></a></p>"
                         "<p><b>%1</b></p>" // AppName (version identifier)
                         "<p>%2</p>" // First statement
                         "<p>%3</p>" // Second statement
                         "</body></html>").arg(hitvidio::AppName,
                                               tr("Hitvidio is a non-linear video editor."
                                                  "This software is protected by the GNU GPL."),
                                               tr("This software is FREE. "
                                                  "To download please go to https://hitvid.io")), this);

  // Set text formatting
  label->setAlignment(Qt::AlignCenter);
  label->setTextInteractionFlags(Qt::TextSelectableByMouse);
  label->setCursor(Qt::IBeamCursor);
  label->setWordWrap(true);
  layout->addWidget(label);

  QDialogButtonBox* buttons = new QDialogButtonBox(QDialogButtonBox::Ok, this);
  buttons->setCenterButtons(true);
  layout->addWidget(buttons);

  connect(buttons, SIGNAL(accepted()), this, SLOT(accept()));
}