//
// @brief: 本文件用来实现游戏中人物的行为逻辑，包括移动、拾取、攻击和一些属性
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_CHARACTER_H
#define QT_PROGRAMMING_2024_CHARACTER_H


#include "../HeadEquipments/HeadEquipment.h"
#include "../Armors/Armor.h"
#include "../LegEquipments/LegEquipment.h"
#include "../Platfrom/Platform.h"
#include "../Weapon/Bow.h"
#include "../Weapon/Arrow.h"
#include "../Weapon/Arrow/SpareArrow.h"
#include "../Weapon/Weapon.h"
#include "../SpecialEffect/FireEffect.h"
#include "../SpecialEffect/FrozenEffect.h"
#include "../SpecialEffect/ThunderEffect.h"
#include "../Armors/IceProofArmor.h"
#include "../LegEquipments/LegEquipment.h"
#include "../HeadEquipments/HeadEquipment.h"
#include "../StatusBar/StatusBar.h"

#include <QTIMER>
#include <QGraphicsEllipseItem>

class Character :public QObject, public Item
{
    Q_OBJECT
public:
    explicit Character(QGraphicsItem *parent=nullptr,const QString &pixmapPath= "");

    //设置和获取角色大小
    void setSize(qreal width, qreal height);
    qreal getWidth() const;
    qreal getHeight() const;
    QRectF boundingRect() const override;

    //控制角色的按键状态
    [[nodiscard]] bool isLeftDown() const;
    void setLeftDown(bool leftDown);
    [[nodiscard]] bool isRightDown() const;
    void setRightDown(bool rightDown);
    [[nodiscard]] bool isPickDown() const;
    void setPickDown(bool pickDown);
    [[nodiscard]] bool isUpDown() const;
    void setUpDown(bool upDown);
    [[nodiscard]] bool isPicking() const;

    //处理角色速度
    [[nodiscard]] const QPointF &getVelocity() const;
    void setVelocity(const QPointF &velocity);

    //输入处理，时刻更新的函数
    void processInput();

    //拾取装备的相关方法
    IceProofArmor* pickupArmor(IceProofArmor* newArmor);
    HeadEquipment* pickupHelmet(HeadEquipment* newHelmet);
    LegEquipment* pickupShoes(LegEquipment* newShoes);
    Weapon* pickupWeapon(Weapon* newWeapon);
    Bow* pickupBow(Bow* newBow);
    SpareArrow* pickupArrow(SpareArrow* newSpareArrow);

    // 生命值相关方法
    [[nodiscard]] qreal getHealth() const;
    void setHealth(qreal newHealth);

    //武器的只读接口和投掷处理函数
    Weapon* getWeapon() const;
    void throwWeapon();
    void deleteWeapon();

    //弓的获取和删除接口
    void deleteBow();
    const Bow* getBow() const;

    //判断角色朝向的方法
    qreal getRotationAngle() const;

    //处理角色在近战还是远程的相关方法
    int getMode() const;
    void setMode(int newMode);
    void changeMode();
    void updateMode();

    //射箭和处理箭种类的方法以及一些只读接口
    Arrow* fireArrow(int arrowType);
    bool isHaveArrow() const;
    void changeArrowType();
    const int* getArrowNum() const;
    int getArrowType() const;


    //设置和查询角色元素状态的接口
    void setOnfire(bool newOnFire);
    bool isOnfire() const;
    void setFrozen(bool newFrozen);
    bool isFrozen() const;
    void setStruck(bool newStruck);
    bool isStruck() const;
    bool isFireDefense() const;
    bool isFrozenDefense() const;
    bool isThunderDefnese() const;

    //获取角色状态栏的接口
    StatusBar* getStatusBar() const;

protected:
    //角色穿戴的护甲、弓、近战武器和状态栏
    HeadEquipment *headEquipment{nullptr};
    LegEquipment *legEquipment{nullptr};
    Armor *armor{nullptr};
    IceProofArmor* iceProofArmor{nullptr};
    Weapon *weapon{nullptr};
    Bow *bow{nullptr};
    StatusBar* statusBar {nullptr};

    //角色的速度，重力相关指标
    QPointF velocity{};
    qreal gravity = 0.98;
    bool onGround = true;

    //检查角色是否与地面碰撞，更新状态的接口
    [[nodiscard]] bool isOnGround() const { return onGround; }
    void setOnGround(bool onGround);
    void applyGravity();
    void handleCollision();
    void onCollisionWithPlatform(Platform* platform);
    void updateGroundStatus();

    //保存指向特效对象的指针
    FireEffect* fireEffect{nullptr};
    FrozenEffect* frozenEffect {nullptr};
    ThunderEffect* thunderEffect {nullptr};

    //更新生命值、箭数目的方法
    void updateHealthBar();
    void updateArrowNum();
    void checkOnFire();

    //确保角色一直在边界内部，绘制角色边界，用于debug
    //void ensureInBounds();
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    // 控制按键状态的bool量
    bool leftDown{}, rightDown{}, pickDown{},upDown{};
    bool lastPickDown{};
    bool picking{};

    //保存元素反应的bool量
    bool onFire{false};
    bool frozen {false};
    bool struck {false};

    qreal width{70};  // 初始宽度
    qreal height{100}; // 初始高度
    qreal health{100}; // 初始生命值
    QGraphicsRectItem *healthBar;

    //0：未携带武器， 1：近战武器 2：弓箭
    int mode{0};

    //储存不同种类箭的个数
    int numArrows[5] = {0};

    //0：初始 1：普通 2：火 3：冰 4：电
    int arrowType {1};

    //判断手中是否有箭
    bool haveArrow{false};

    //管理火、冰、电的计时器
    QTimer* fireTimer;
    QTimer* frozenTimer;
    QTimer* struckTimer;

    //元素反应进行步骤
    int fireStage{0};
    int struckStage{0};

    //被电击时检查武器是否金属
    void checkMetalWeapon();

signals:
    //被攻击时发出信号
    void beAttacked();

private slots:
    //处理元素反应的槽函数
    void processFire();
    void unfreeze();
    void processStruck();
};
#endif //QT_PROGRAMMING_2024_CHARACTER_H
