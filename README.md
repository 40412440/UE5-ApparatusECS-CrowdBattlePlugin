# UE5-ApparatusECS-CrowdBattleFramePlugin

[![Join Discord](https://img.shields.io/badge/Discord-Join%20Chat-blue?logo=discord)](https://discord.gg/8AUMxq3SgV)
[![QQ Group](https://img.shields.io/badge/QQ%20Group-916358710-blue?logo=tencentqq)](https://jq.qq.com/?_wv=1027&k=5R5X5wX)

## Version
The repository version is my current progress. 
If it failed to compile, use the release version instead.

## Dependencies

This plugin is open source, but has the following dependencies:

- **Apparatus ECS Framework** (Paid on FAB)  
  https://www.fab.com/listings/23ddc9c0-a218-44ed-8c0c-ebef362f08d5

- **Flowfield Canvas** (Pathfinding plugin)  
  Since FFC is my plugin, I've included a lite version for free.
  Full version available for purchase:  
  https://www.fab.com/listings/e306cd3d-9855-45bf-a978-d9ac6ae2ee33

- **Anim To Texture** (Official Unreal Engine plugin)  
  Included with the engine

## Technical Details

- **Status**: Beta (with frequent modifications and may contain bugs)
- **Tested Platforms**: 
  - Windows
  - UE5.3, UE5.4, UE5.5
- **Performance**: 
  - 60 fps with 25,000 agents
  - 30 fps with 50,000 agents
  - (AMD Ryzen 5900X + RTX 4080S, CPU capped. Shipping Package)
- **Technology Stack**:
  - ECS for logic
  - Niagara + VAT for rendering
  - RVO2 for avoidance
  - Neighbour grid for collision detection
  - Flow field and A* for navigation

## Features

Comprehensive crowd battle system. Demo maps are included in the plugin's content folder.

- **AI Behaviors**: 
  - Birth, Sleep, Patrol, Chase, Attack, Hit, Death, each with many params
  - Debuffs, including launching, slowing and temporal dmg, comes with material Fx.
  - 2.5D movement supporting flying, falling and moving on uneven surfaces
  - Navigation and avoidance support sphere and box obstacles
- **AI Perception**:
  - Support vision. Agent can trace for targets, and optionally only visible ones
- **Projectile System**:
  - 4 movement mode: static, Ballistic, Interped, Tracking
  - 3 damage mode : point, radial, beam
  - Ballistic launch speed solver with prediction
- **NS GPU Particle VAT**:
  - Basic Idle-Move-Montage anim state machine with blending
  - Editor utility widget to set up VAT in 1 click
- **NS GPU Particle UI**:
  - Health Bar, Text Pop, Ground Ring
- **NS CPU Batched Emitter**:
  - Batched particle burst, Batched trails
- **BP WorkFlow**:
  - Spawn projectile by data asset
  - Spawn agent by data asset
  - Bind agent to unreal's actor
  - Setting trait values runtime to control agents' behaviors 
  - Trace for agents and apply damage and debuff
  - Spawning actor fx and sound on birth atk hit and death
  - Event interface: OnAppear, OnAttack, OnHit, OnDeath...
  - Draw Debug Shapes
  
## Roadmap

In progress:
1. Tower defence demo map
2. Sprite rendering support
3. MassEntity branch
4. GPU SKM support with TurboSequence
5. Network replication
6. RTS demo map

## Leave a star if you find this project useful ;)

# UE5-ApparatusECS-群体战斗框架插件

[![加入Discord](https://img.shields.io/badge/Discord-加入聊天-blue?logo=discord)](https://discord.gg/8AUMxq3SgV)
[![QQ群](https://img.shields.io/badge/QQ群-916358710-blue?logo=tencentqq)](https://jq.qq.com/?_wv=1027&k=5R5X5wX)

## 版本说明
仓库版本为当前开发进度版
如编译失败请使用发布版本

## 依赖项

本插件开源但依赖以下付费插件：

- **Apparatus ECS框架** (FAB平台付费)  
  https://www.fab.com/listings/23ddc9c0-a218-44ed-8c0c-ebef362f08d5

- **Flowfield Canvas** (寻路插件)  
  由于FFC是作者开发的插件，已包含精简免费版
  完整版购买地址：  
  https://www.fab.com/listings/e306cd3d-9855-45bf-a978-d9ac6ae2ee33

- **Anim To Texture** (官方虚幻引擎插件)  
  引擎自带

## 技术细节

- **开发状态**：测试版（频繁修改中可能存在bug）
- **测试平台**： 
  - Windows
  - UE5.3/UE5.4/UE5.5
- **性能表现**： 
  - 25,000个实体时60帧
  - 50,000个实体时30帧
  - (AMD Ryzen 5900X + RTX 4080S配置，CPU瓶颈，Shipping包)
- **技术栈**：
  - ECS逻辑架构
  - Niagara+VAT渲染方案
  - RVO2避障算法
  - 邻居网格碰撞检测
  - 流场+A*导航系统

## 功能特性

完整的群体战斗系统。演示地图包含在插件内容目录中。

- **AI行为**： 
  - 出生/休眠/巡逻/追击/攻击/受击/死亡等状态，各含丰富参数
  - 击飞/减速/持续伤害等Debuff效果，附带材质特效
  - 2.5D移动系统支持飞行、坠落和崎岖地形移动
  - 导航避障支持球体和方体障碍物
- **AI感知**：
  - 视觉系统支持，可追踪视野内/外目标
- **投射物系统**：
  - 4种运动模式：静态/弹道/插值/追踪
  - 3种伤害模式：点/范围/光束
  - 带预测的弹道初速解算器
- **NS GPU粒子VAT**：
  - 基础待机-移动-蒙太奇动画状态机混合
  - 编辑器工具一键配置VAT
- **NS GPU粒子UI**：
  - 血条/飘字/地面标记环
- **NS CPU批量发射器**：
  - 批量粒子爆发/拖尾效果
- **蓝图工作流**：
  - 通过数据资产生成投射物
  - 通过数据资产生成AI实体
  - 将实体绑定到Actor
  - 运行时设置特征值控制AI行为
  - 检测实体并施加伤害/减益
  - 在出生/攻击/受击/死亡时生成Actor特效和音效
  - 事件接口: OnAppear, OnAttack, OnHit, OnDeath...
  - 调试图形绘制
  
## 开发路线

进行中功能：
1. 塔防演示地图
2. 精灵渲染支持
3. MassEntity分支
4. 基于TurboSequence的GPU蒙皮支持
5. 网络同步功能
6. RTS演示地图

## 如果觉得项目有用请点个Star ;)
