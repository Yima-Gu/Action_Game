//
// @brief: 作为所有平台的基类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "Platform.h"

QRectF Platform::boundingRect() const
{
    return QRectF(0, 0, width, height);
}
