//
// @brief: Item基类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "Item.h"

Item::Item(QGraphicsItem *parent, const QString &pixmapPath) : QGraphicsItem(parent)
{
    if (pixmapPath != "")
    {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    }
}
