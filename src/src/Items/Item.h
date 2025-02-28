//
// @brief: 最基本的Item基类
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_ITEM_H
#define QT_PROGRAMMING_2024_ITEM_H

#include <QGraphicsItem>
#include <QPainter>

class Item : public QGraphicsItem
{
public:
    explicit Item(QGraphicsItem *parent, const QString &pixmapPath);
    [[nodiscard]] QRectF boundingRect() const override
    {
        if (pixmapItem != nullptr)
        {
            return this->pixmapItem->boundingRect();
        }
        return {};
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
    }
protected:
    QGraphicsPixmapItem *pixmapItem{};
};


#endif //QT_PROGRAMMING_2024_ITEM_H
