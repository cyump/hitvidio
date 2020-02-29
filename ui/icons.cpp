#include "icons.h"

#include <QDebug>

#include "global/global.h"
#include "global/config.h"

QIcon hitvidio::icon::LeftArrow;
QIcon hitvidio::icon::RightArrow;
QIcon hitvidio::icon::UpArrow;
QIcon hitvidio::icon::DownArrow;
QIcon hitvidio::icon::Diamond;
QIcon hitvidio::icon::Clock;

QIcon hitvidio::icon::MediaVideo;
QIcon hitvidio::icon::MediaAudio;
QIcon hitvidio::icon::MediaImage;
QIcon hitvidio::icon::MediaError;
QIcon hitvidio::icon::MediaSequence;
QIcon hitvidio::icon::MediaFolder;

QIcon hitvidio::icon::ViewerGoToStart;
QIcon hitvidio::icon::ViewerPrevFrame;
QIcon hitvidio::icon::ViewerPlay;
QIcon hitvidio::icon::ViewerPause;
QIcon hitvidio::icon::ViewerNextFrame;
QIcon hitvidio::icon::ViewerGoToEnd;

QIcon hitvidio::icon::CreateIconFromSVG(const QString &path, bool create_disabled)
{
  QIcon icon;

  QPainter p;

  // Draw the icon as a solid color
  QPixmap normal(path);

  // Color the icon dark if the user is using a dark theme
  if (hitvidio::styling::UseDarkIcons()) {
    p.begin(&normal);
    p.setCompositionMode(QPainter::CompositionMode_SourceIn);
    p.fillRect(normal.rect(), QColor(32, 32, 32));
    p.end();
  }

  icon.addPixmap(normal, QIcon::Normal, QIcon::On);

  if (create_disabled) {

    // Create semi-transparent disabled icon
    QPixmap disabled(normal.size());
    disabled.fill(Qt::transparent);

    // draw semi-transparent version of icon for the disabled variant
    p.begin(&disabled);
    p.setCompositionMode(QPainter::CompositionMode_SourceOver);
    p.setOpacity(0.5);
    p.drawPixmap(0, 0, normal);
    p.end();

    icon.addPixmap(disabled, QIcon::Disabled, QIcon::On);

  }

  return icon;
}

void hitvidio::icon::Initialize()
{
  qInfo() << "Initializing icons";

  LeftArrow = CreateIconFromSVG(":/icons/tri-left.svg", false);
  RightArrow = CreateIconFromSVG(":/icons/tri-right.svg", false);
  UpArrow = CreateIconFromSVG(":/icons/tri-up.svg", false);
  DownArrow = CreateIconFromSVG(":/icons/tri-down.svg", false);
  Diamond = CreateIconFromSVG(":/icons/diamond.svg", false);
  Clock = CreateIconFromSVG(":/icons/clock.svg", false);

  MediaVideo = CreateIconFromSVG(":/icons/videosource.svg");
  MediaAudio = CreateIconFromSVG(":/icons/audiosource.svg");
  MediaImage = CreateIconFromSVG(":/icons/imagesource.svg", false);
  MediaError = CreateIconFromSVG(":/icons/error.svg", false);
  MediaSequence = CreateIconFromSVG(":/icons/sequence.svg", false);
  MediaFolder = CreateIconFromSVG(":/icons/folder.svg", false);

  ViewerGoToStart = CreateIconFromSVG(QStringLiteral(":/icons/prev.svg"));
  ViewerPrevFrame = CreateIconFromSVG(QStringLiteral(":/icons/rew.svg"));
  ViewerPlay = CreateIconFromSVG(QStringLiteral(":/icons/play.svg"));
  ViewerPause = CreateIconFromSVG(":/icons/pause.svg", false);
  ViewerNextFrame = CreateIconFromSVG(QStringLiteral(":/icons/ff.svg"));
  ViewerGoToEnd = CreateIconFromSVG(QStringLiteral(":/icons/next.svg"));

  qInfo() << "Finished initializing icons";
}