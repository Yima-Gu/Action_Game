//
// @brief: 主要的战斗场景
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_BATTLESCENE_H
#define QT_PROGRAMMING_2024_BATTLESCENE_H


#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"
#include "../Items/Platfrom/AirPlatform.h"
#include "../Items/Platfrom/RockPlatform.h"
#include "../Items/Platfrom/MetalPlatform.h"
#include "../Items/Platfrom/WoodPlatform.h"

#include <QKeyEvent>
#include <QTimer>


class BattleScene : public Scene
{
Q_OBJECT

public:
    explicit BattleScene(QObject *parent);

    //核心处理方法
    void processInput() override;
    void processMovement() override;
    void processPicking() override;

    //从作弊码中添加物品
    void addFromCheatCode(GravityMountableItem* item);

public slots:
    //接收木质平台内存被释放的信号
    void woodPlatformDeleted();

protected slots:

    void update() override;
    void spawnRandomItem();

signals:

    void gameoverSignal(int winner);

protected:
    //事件处理函数
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    //添加，删除相关对象的方法，统一管理内存，避免在遍历过程中出现野指针！！！
    void addArrow(Arrow *newArrow);
    void deleteArrow();
    void deleteThrownWeapon();
    void deleteExtinguishedFire();

    void checkGameOver();
    void initialization();

private:
    //捡起物品的相关行为
    Mountable *findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold = std::numeric_limits<qreal>::max());
    static Mountable * pickupMountable(Character *currentCharacter, Mountable *mountable);

    //保存的一些私有变量的指针
    Map *map;
    Character *character;
    Character *enemy;
    AirPlatform* airPlatformGround;
    MetalPlatform* MetalPlatformLeft;
    RockPlatform* RockPlatformRight;
    WoodPlatform* WoodPlatformHigh;
    QTimer* spawnTimer;
};


#endif //QT_PROGRAMMING_2024_BATTLESCENE_H
