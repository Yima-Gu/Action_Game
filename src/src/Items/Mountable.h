//
// @brief: 相关的挂载行为，是所有可挂载对象的基类
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_MOUNTABLE_H
#define QT_PROGRAMMING_2024_MOUNTABLE_H


class Mountable
{
public:
    virtual void mountToParent();
    virtual void unmount();
    [[nodiscard]] bool isMounted() const;
    virtual void update()=0;

private:
    bool mounted{};
};


#endif //QT_PROGRAMMING_2024_MOUNTABLE_H
