#ifndef SCENE_H
#define SCENE_H

#include "gateitem.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

QT_BEGIN_NAMESPACE
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE

class Scene : public QGraphicsScene
{
  Q_OBJECT

public:
  enum Mode { InsertItem, InsertLine, MoveItem };

  explicit Scene(QObject* parent = nullptr);

public slots:
  void setMode(Mode mode);
  void setItemType(GateItem::GateType type);

signals:
  void itemInserted(GateItem* item);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
  GateItem* getNewGateItem(GateItem::GateType type);
  void mouseReleaseMultiplexerEnd(GateItem* startItem,GateItem* endItem, QPointF endPoint);
  void mouseReleaseMultiplexerStart(GateItem* startItem,GateItem* endItem);

  GateItem::GateType myItemType;
  Mode myMode;
  QPointF startPoint;
  QGraphicsLineItem *line;
};

#endif // SCENE_H
