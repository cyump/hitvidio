/***

    Hitvidio - Non-Linear Video Editor
    Copyright (C) 2019  Hitvidio Team

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

#include "cursors.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QPixmap>
#include <QSvgRenderer>
#include <QPainter>
#include <QCursor>
#include <QDebug>

QCursor hitvidio::cursor::LeftTrim;
QCursor hitvidio::cursor::RightTrim;
QCursor hitvidio::cursor::LeftRipple;
QCursor hitvidio::cursor::RightRipple;
QCursor hitvidio::cursor::Slip;
QCursor hitvidio::cursor::Razor;

const int cursor_size = 24;

QCursor load_cursor(const QString& file, int hotX = -1, int hotY = -1, bool right_aligned = false){
  // load specified file into a pixmap
  QSvgRenderer renderer(file);

  int cursor_size_dpiaware = cursor_size * QApplication::desktop()->devicePixelRatio();
  QPixmap pixmap(cursor_size_dpiaware, cursor_size_dpiaware);
  pixmap.fill(Qt::transparent);

  QPainter painter(&pixmap);
  renderer.render(&painter, pixmap.rect());

  // set cursor's horizontal hotspot
  if (right_aligned) {
    hotX = pixmap.width() - hotX;
  }

  // return cursor
  return QCursor(pixmap, hotX, hotY);
}

void hitvidio::cursor::Initialize(){
  qInfo() << "Initializing custom cursors";
  hitvidio::cursor::LeftTrim = load_cursor(":/cursors/1_left.svg");
  hitvidio::cursor::RightTrim = load_cursor(":/cursors/1_right.svg");
  hitvidio::cursor::LeftRipple = load_cursor(":/cursors/3_left.svg");
  hitvidio::cursor::RightRipple = load_cursor(":/cursors/3_right.svg");
  hitvidio::cursor::Slip = load_cursor(":/cursors/4.svg");
  hitvidio::cursor::Razor = load_cursor(":/cursors/5.svg");
  qInfo() << "Finished initializing custom cursors";
}