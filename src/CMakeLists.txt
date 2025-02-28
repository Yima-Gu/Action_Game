cmake_minimum_required(VERSION 3.28)
project(qt_programming_2024)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt_programming_2024 src/main.cpp
        src/MyGame.cpp
        src/MyGame.h
        src/Items/Item.cpp
        src/Items/Item.h
        src/Items/Characters/Character.cpp
        src/Items/Characters/Character.h
        src/Items/Characters/Link.cpp
        src/Items/Characters/Link.h
        src/Items/Armors/Armor.cpp
        src/Items/Armors/Armor.h
        src/Items/HeadEquipments/HeadEquipment.cpp
        src/Items/HeadEquipments/HeadEquipment.h
        src/Items/LegEquipments/LegEquipment.cpp
        src/Items/LegEquipments/LegEquipment.h


        src/Items/Armors/OldShirt.cpp
        src/Items/Armors/OldShirt.h


        src/Scenes/Scene.cpp
        src/Scenes/Scene.h
        src/Scenes/BattleScene.cpp
        src/Scenes/BattleScene.h
        assets/assets.qrc
        src/Items/Maps/Map.cpp
        src/Items/Maps/Map.h
        src/Items/Maps/Battlefield.cpp
        src/Items/Maps/Battlefield.h
        src/Items/Mountable.cpp
        src/Items/Mountable.h


        src/Items/Platfrom/Platform.h
        src/Items/Platfrom/AirPlatform.h
        src/Items/Platfrom/AirPlatform.cpp
        src/Items/Platfrom/RockPlatform.h
        src/Items/Platfrom/Platform.cpp
        src/Items/Platfrom/RockPlatform.cpp
        src/Items/Gravitational.h
        src/Items/Gravitational.cpp
        src/Items/Platfrom/MetalPlatform.h
        src/Items/Platfrom/MetalPlatform.cpp
        src/Items/Platfrom/WoodPlatform.h
        src/Items/Platfrom/WoodPlatform.cpp
        src/Items/Weapon/Weapon.h
        src/Items/Weapon/Weapon.cpp
        src/Items/Weapon/Sword/Sword.h
        src/Items/Weapon/Sword/Sword.cpp
        src/Items/Weapon/Sword/WoodSword.h
        src/Items/Weapon/Sword/WoodSword.cpp
        src/Items/Weapon/Bow.h
        src/Items/Weapon/Bow.cpp
        src/Items/Weapon/Bow/WoodBow.h
        src/Items/Weapon/Bow/WoodBow.cpp
        src/Items/Weapon/Arrow.h
        src/Items/Weapon/Arrow.cpp
        src/Items/Weapon/Arrow/NormalArrow.h
        src/Items/Weapon/Arrow/NormalArrow.cpp
        src/Items/Weapon/Arrow/SpareArrow.h
        src/Items/Weapon/Arrow/SpareArrow.cpp
        src/Items/Weapon/Arrow/SpareNormalArrow.h
        src/Items/Weapon/Arrow/SpareNormalArrow.cpp
        src/Items/Characters/Enemy.h
        src/Items/Characters/Enemy.cpp
        src/Items/Armors/EnemyShirt.h
        src/Items/Armors/EnemyShirt.cpp
        src/Items/Weapon/Bow/IronBow.h
        src/Items/Weapon/Bow/IronBow.cpp
        src/Items/Weapon/Sword/IronStaff.h
        src/Items/Weapon/Sword/IronStaff.cpp
        src/Items/Weapon/Sword/FrezzeTHS.h
        src/Items/Weapon/Sword/FreezeTHS.cpp
        src/Items/Weapon/Bow/IronHandBow.h
        src/Items/Weapon/Bow/IronHandBow.cpp
        src/Items/Weapon/Sword/FireSword.h
        src/Items/Weapon/Sword/FireSword.cpp
        src/Items/SpecialEffect/FireEffect.h
        src/Items/SpecialEffect/FireEffect.cpp
        src/Items/Weapon/Arrow/SpareFireArrow.h
        src/Items/Weapon/Arrow/SpareFireArrow.cpp
        src/Items/Weapon/Arrow/FireArrow.h
        src/Items/Weapon/Arrow/FireArrow.cpp
        src/Items/GravityMountableItem.h
        src/Items/GravityMountableItem.cpp
        src/Items/SpecialEffect/FrozenEffect.h
        src/Items/SpecialEffect/FrozenEffect.cpp
        src/Items/Weapon/Arrow/FrozenArrow.h
        src/Items/Weapon/Arrow/FrozenArrow.cpp
        src/Items/Weapon/Arrow/SpareFrozenArrow.h
        src/Items/Weapon/Arrow/SpareFrozenArrow.cpp
        src/Items/Weapon/Sword/ThunderSword.h
        src/Items/Weapon/Sword/ThunderSword.cpp
        src/Items/SpecialEffect/ThunderEffect.h
        src/Items/SpecialEffect/ThunderEffect.cpp
        src/Items/Weapon/Arrow/SpareThunderArrow.h
        src/Items/Weapon/Arrow/SpareThunderArrow.cpp
        src/Items/Weapon/Arrow/ThunderArrow.h
        src/Items/Weapon/Arrow/ThunderArrow.cpp
        src/Items/Armors/IceProofArmor.h
        src/Items/Armors/IceProofArmor.cpp
        src/Items/ItemType.h
        src/Items/ItemFactory.h
        src/Items/ItemFactory.cpp
        src/Items/CheatCodeManager.h
        src/Items/CheatCodeManager.cpp
        src/CheatCode/CheatCodeDialog.h
        src/CheatCode/CheatCodeDialog.cpp
        src/Items/StatusBar/StatusBar.h
        src/Items/StatusBar/StatusIcon.h
        src/Items/StatusBar/StatusIcon.cpp
        src/Items/StatusBar/StatusBar.cpp








    )
target_link_libraries(qt_programming_2024
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

