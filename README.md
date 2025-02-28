# Action-Game
## **2024 程序设计实训大作业项目文档**


**姓名**：顾一马  
**学号**：2023012827  
**邮箱**：[gu-ym23@mails.tsinghua.edu.cn](mailto:gu-ym23@mails.tsinghua.edu.cn)

**日期**：2024-09-05

## **目录**

1. [模块之间的逻辑关系](#模块之间的逻辑关系)
2. [程序运行流程](#程序运行流程)
3. [类继承关系](#类继承关系)
4. [参考文献](#参考文献)
---

## 模块之间的逻辑关系

该游戏项目由多个模块组成，每个模块负责不同的功能。以下是主要模块及其关系的概述：

- **主模块** (`MyGame.cpp, MyGame.h`)：负责游戏的主窗口和整体控制。
- **场景模块** (`Scene.cpp, BattleScene.cpp`)：管理游戏场景、时间、输入处理等。
- **角色模块** (`Character.cpp, Link.cpp`)：处理角色状态、动作、拾取物品等。
- **装备模块** (`Armor.cpp, OldShirt.cpp`)：定义装备和道具逻辑。
- **武器模块** (`Weapon.cpp, Sword.cpp`)：管理不同类型武器及攻击方式。
- **作弊码模块** (`CheatCodeManager.cpp`)：提供作弊码输入界面。
- **地图模块** (`Map.cpp, Battlefield.cpp`)：管理地图布局、障碍物等。
- **平台模块** (`Platform.cpp`)：定义游戏内不同平台的特性。
- **特效模块** (`FireEffect.cpp`)：处理火焰、冰冻、雷电等特效。

---

## 程序运行流程

1. **程序启动**，创建 `MyGame` 主窗口。
2. **初始化战斗场景** (`BattleScene`)：
    - 设定 `1280x720` 场景大小。
    - 设定 `spawnTimer` 每 `8000ms` 生成物品。
3. **将战斗场景设置为当前场景**。
4. **进入主循环**，调用 `Scene::startLoop()` 处理用户输入。
5. **游戏交互**：
    - `processInput()` 处理输入。
    - `processMovement()` 处理角色和敌人移动。
    - `processPicking()` 处理物品拾取。
    - `update()` 更新游戏状态，如攻击、血量计算等。
6. **游戏结束**，调用 `checkGameOver()` 显示胜利信息并退出。

---

## 类继承关系

游戏中类的继承关系如下：

- **`QGraphicsScene`**：图形场景管理。
    - **`Scene`**：管理游戏循环、时间、输入等。
        - **`BattleScene`**：战斗场景的具体实现。
- **`QGraphicsItem`**：所有可绘制对象的基类。
    - **`Item`**：物品基础类。
        - **`Weapon`**：近战武器。
        - **`Bow`**：远程弓箭。
        - **`Armor`**：护甲。
        - **`Character`**：角色类（`Link` 主角, `Enemy` 敌人）。
        - **`SpecialEffect`**：特效类（火、冰、电）。
        - **`Platform`**：平台类（木平台、金属平台等）。
        - **`Map`**：地图类。
        - **`StatusBar`**：状态栏组件。


---

## 参考文献

本项目使用了 **Qt** 框架，涉及以下组件：

- **Qt 库**：
    - `QRandomGenerator`：随机数生成
    - `QGraphicsItem`：图形对象
    - `QTimer`：定时器
    - `QGraphicsView`：图形视图
    - `QMainWindow`：主窗口
    - `QDialog`：对话框
    - `QLineEdit`：文本输入框
    - `QPushButton`：按钮

### **相关文档**

1. **Qt 官方文档**：[Qt 6 Documentation](https://doc.qt.io/qt-6/index.html)
2. **Qt 教程**：[Qt Examples and Tutorials](https://doc.qt.io/qt-6/qtwidgets-widgets-tutorial.html)
3. **Qt Wiki**：[Qt Wiki](https://wiki.qt.io/)

---
