//
// @brief: 可挂载的基类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Mountable.h"

void Mountable::unmount()
{
    mounted = false;
}

bool Mountable::isMounted() const
{
    return mounted;
}

void Mountable::mountToParent()
{
    mounted = true;
}
