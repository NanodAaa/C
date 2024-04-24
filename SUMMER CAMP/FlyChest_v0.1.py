#
#   飞行棋.py
#   Designed by NanodAaa
#


import sys
import random


# 玩家起名
def PlayerName():
    global gs_PlayerName1
    global gs_PlayerName2

    # 玩家姓名
    gs_PlayerName1 = "nanoda"   # input("请输入玩家1的名字:")
    gs_PlayerName2 = "enderddr2"   # input("请输入玩家2的名字:")

    if (gs_PlayerName1 == gs_PlayerName2):
        print("玩家名字重复! 游戏结束")
        sys.exit(-1)


# 游戏初始界面
def GameInit():
    print('*'*32)
    print('*           飞行棋             *')
    print('*     Designed by NanodAaa     *')
    print("* 1.地雷: ※  2.时空隧道: 3.暂停: ▲ \n *")
    print("* 4.幸运轮盘: ♤ 5.走到一起: § *")
    print('*'*32)
#    if (input("\n按任意键开始游戏.") != 0):
#        print("游戏开始!")


# 地图位置信息
MAP_SPACE = int(0)           # 空白区域
MAP_SIZE = int(21)           # 地图大小(选奇数)
MAP_ROUTE = int(6)           # 道路

PORP_TIME_PAUSE = int(1)     # 时停 -- 暂停一回合
PORP_LUCKY_TURN = int(2)     # 幸运转盘 -- 多移动一次
PORP_LAND_MINE = int(3)      # 地雷 -- 回到上次的位置

# 道具数量
PROP_LAND_MINE_NUM = int(5)      # 地雷数量
PORP_LUCKY_TURN_NUM = int(2)     # 幸运转盘
PORP_TIME_PAUSE_NUM = int(4)     # 时停
PORP_TYPE_NUM = int(3)

global TimePauseFlag
TimePauseFlag = False

PLAYER_PLAYER1 = int(4)      # 玩家1
PLAYER_PLAYER2 = int(5)      # 玩家2
PLAYER_PLAYER1_DEFAULT_X = int(MAP_SIZE / 2)  # 玩家初始位置
PLAYER_PLAYER1_DEFAULT_Y = int(0)
PLAYER_PLAYER2_DEFAULT_X = int(MAP_SIZE / 2)
PLAYER_PLAYER2_DEFAULT_Y = int(MAP_SIZE - 1)

# 玩家位置列表
global Player1PosList
global Player2PosList
Player1PosList = [PLAYER_PLAYER1_DEFAULT_Y, PLAYER_PLAYER1_DEFAULT_X]
Player2PosList = [PLAYER_PLAYER2_DEFAULT_Y, PLAYER_PLAYER2_DEFAULT_X]

PlayerOrder = random.randint(0, 1)


# 道具生成函数
# PropList -- 道具列表
# i_PorpNum -- 道具数量
def PorpGenerate(PorpListInput, i_PorpNum):
    global RouteSelect
    global i_PorpCount
    global i_PorpListCount0
    global i_PorpListCount1
    global LoopStopFlag

    PorpList = list(PorpListInput)

    # 生成坐标v2.0
    print("正在生成道具坐标...")
    for PorpNumCount in range(i_PorpNum):
        RouteSelect = random.randint(int(0), int(3))

        if (RouteSelect == int(0)):  # 1
            PorpList[PorpNumCount] = [random.randint(1, (MAP_SIZE - 1)) + 1, int(0)]

        elif (RouteSelect == int(1)):  # 2
            PorpList[PorpNumCount] = [MAP_SIZE, random.randint(1, (MAP_SIZE - 1)) + 1]

        elif (RouteSelect == int(2)):  # 3
            PorpList[PorpNumCount] = [random.randint(1, (MAP_SIZE - 1)) + 1, MAP_SIZE]

        elif (RouteSelect == int(3)):  # 4
            PorpList[PorpNumCount] = [int(0), random.randint(1, (MAP_SIZE + 1))]

    print("道具坐标为:", PorpList)  # 初次分配的道具坐标

    # 检测坐标是否有重复
    print("正在检测道具坐标是否重复...")
    LoopStopFlag = False

    while True:
        for i_PorpListCount0 in range(0, len(PorpList) - 1):
            for i_PorpListCount1 in range((i_PorpListCount0 + 1), len(PorpList)):

                print("正在检测", i_PorpListCount0, "和", i_PorpListCount1, "...")

                # 重复
                if (PorpList[i_PorpListCount0] == PorpList[i_PorpListCount1]):
                    print(i_PorpListCount0, "和", i_PorpListCount1, "坐标重复, 正在重新分配坐标...")

                    # 重新取坐标
                    PorpListDivide = list(PorpList[i_PorpListCount1])
                    if (PorpListDivide[0] == int(0) or PorpListDivide[0] == MAP_SIZE):
                        PorpList[i_PorpListCount1] = [PorpListDivide[0], random.randint(1, MAP_SIZE)]

                    elif (PorpListDivide[1] == int(0) or PorpListDivide[1] == MAP_SIZE):
                        PorpList[i_PorpListCount1] = [random.randint(1, MAP_SIZE), PorpListDivide[1]]

                    else:
                        print("!!!!!坐标生成出错!!!!!")
                        sys.exit(-1)

                    print("坐标重新分配完成!", PorpList)

                    # 标志置位
                    LoopStopFlag = True
                    break

                # 无重复
                else:
                    print(i_PorpListCount0, "和", i_PorpListCount1, "无重复!")

            # 检测到重复, 重新开始检测
            if (LoopStopFlag == True):
                break

        # 检测到重复, 重新开始检测
        if (LoopStopFlag == True):
            LoopStopFlag = False
            continue

        if (LoopStopFlag == False):
            print("坐标重复检查完毕!")
            break

    print("坐标生成完毕...\n")
    return PorpList


# 找2个维数组相同元素
def List2DCampare(InputList1, InputList2):
    InputList1 = InputList1
    InputList2 = InputList2

    for i_List1Count in range(0, len(InputList1)):
        for i_List2Count in range(0, len(InputList2)):
            if InputList1[i_List1Count] == InputList2[i_List2Count]:
                print(InputList2[i_List2Count])
                return True


# 道具位置随机生成
def PropGenerateInit():
    global LandMineList             # 地雷位置列表
    global LuckTurnList             # 幸运转盘
    global TimePauseList            # 时停
    global PorpTotalList            # 储存所有道具列表
    global LoopRepeatFlag           # 重复检测结束标志
    global MapPosInforListX         # 游戏地图横纵坐标
    global MapPosInforListY

    LandMineList = [[0] * 2] * PROP_LAND_MINE_NUM    # 地雷位置列表 [[], [], []] -- "[]"内为坐标, 个数为道具数量
    LuckTurnList = [[0] * 2] * PORP_LUCKY_TURN_NUM
    TimePauseList = [[0] * 2] * PORP_TIME_PAUSE_NUM

    print("正在生成道具...")
    LandMineList = PorpGenerate(LandMineList, PROP_LAND_MINE_NUM)      # 生成地雷
    LuckTurnList = PorpGenerate(LuckTurnList, PORP_LUCKY_TURN_NUM)     # 生成幸运转盘
    TimePauseList = PorpGenerate(TimePauseList, PORP_TIME_PAUSE_NUM)    # 生成时停

    # 装载所有道具列表
    PorpTotalList = []
    PorpTotalList.append(LandMineList)
    PorpTotalList.append(LuckTurnList)
    PorpTotalList.append(TimePauseList)

    print("所有道具坐标为: ", PorpTotalList)

    # 检测道具坐标重复
    LoopRepeatFlag = False
    print("正在检测道具间是否重复...")

    while True:
        for PorpListCount1 in range(0, PORP_TYPE_NUM):
            for PorpListCount2 in range(PorpListCount1 + 1, PORP_TYPE_NUM):
                print("正在对比", PorpListCount1, "和", PorpListCount2, "...")
                if (List2DCampare(PorpTotalList[PorpListCount1], PorpTotalList[PorpListCount2])):

                    # 重复, 重新分配
                    print(PorpListCount1, "和", PorpListCount2, "有重复!")
                    print("\n正在重新分配第", PorpListCount2, "个列表...")
                    PorpTotalList[PorpListCount2] = PorpGenerate(PorpTotalList[PorpListCount2], len(PorpTotalList[PorpListCount2]))

                    # 标志置位
                    print("已重新分配坐标,重新进行对比程序...")
                    LoopRepeatFlag = True
                    break

                else:
                    print(PorpListCount1, "和", PorpListCount2, "无重复!")

            # 检测到重复, 重新开始检测
            if (LoopRepeatFlag == True):
                break

        # 检测到重复, 重新开始检测
        if (LoopRepeatFlag == True):
            LoopRepeatFlag = False
            continue

        if (LoopRepeatFlag == False):
            print("坐标重复检查完毕!")
            break

    print("道具生成完成!\n")

    # 游戏道具装载进地图
    print("正在将游戏道具坐标载入地图...")
    for MapPosInforListCountX in range(0, len(PorpTotalList)):
        for MapPosInforListCountY in range(0, len(PorpTotalList[MapPosInforListCountX])):
            MapPosInforListX = PorpTotalList[MapPosInforListCountX][MapPosInforListCountY][1]
            MapPosInforListY = PorpTotalList[MapPosInforListCountX][MapPosInforListCountY][0]

            if (MapPosInforListX == MAP_SIZE):
                MapPosInforListX -= int(1)

            if (MapPosInforListY == MAP_SIZE):
                MapPosInforListY -= int(1)

            if (MapPosInforListCountX == 0):
                MapPosInforList[MapPosInforListY][MapPosInforListX] = PORP_LAND_MINE

            elif (MapPosInforListCountX == int(1)):
                MapPosInforList[MapPosInforListY][MapPosInforListX] = PORP_LUCKY_TURN

            elif (MapPosInforListCountX == int(2)):
                MapPosInforList[MapPosInforListY][MapPosInforListX] = PORP_TIME_PAUSE

            else:
                print("道具坐标载入出错!")
                sys.exit(-1)

    print("道具坐标载入完毕!")
    print(MapPosInforList)


# 玩家坐标刷新
def PlayerPosRefresh(InputPlayerPosList, PlayeNum):
    if (PlayeNum == PLAYER_PLAYER1):
        MapPosInforList[InputPlayerPosList[0]][InputPlayerPosList[1]] = PLAYER_PLAYER1

    elif (PlayeNum == PLAYER_PLAYER2):
        MapPosInforList[InputPlayerPosList[0]][InputPlayerPosList[1]] = PLAYER_PLAYER2


# 生成玩家
def PlayerGenerateInit():
    print("正在生成玩家...")

    # 载入玩家坐标
    print("正在载入玩家坐标...")
    PlayerPosRefresh(Player1PosList, PLAYER_PLAYER1)
    PlayerPosRefresh(Player2PosList, PLAYER_PLAYER2)

    print("玩家坐标载入完成!")
    print(MapPosInforList)


# 地图位置信息初始化
def MapPosInforInit():
    global MapPosInforList      # 地图位置信息列表
    global i_MapRouteCount
    global MapRouteList         # 地图道路列表

    MapPosInforList = []    # 地图位置信息列表
    for i in range(MAP_SIZE):
        MapPosInforList.append([])

        for j in range(MAP_SIZE):
            MapPosInforList[i].append(0)

    i_MapRouteCount = int(0)    # 地图道路计数

    print("\n...正在初始化地图信息...\n")

    # 生成游戏道路
    print("正在生成游戏道路...")
    # x=0 -- x=mapsize
    MapRouteList0 = [MAP_ROUTE] * MAP_SIZE
    MapPosInforList[0] = MapRouteList0
    MapRouteList1 = [MAP_ROUTE] * MAP_SIZE
    MapPosInforList[MAP_SIZE - 1] = MapRouteList1

    MapRouteList2 = []

    # 二维数组
    for i in range(MAP_SIZE - 2):
        MapRouteList2.append([])
        for j in range(MAP_SIZE):
            if (j == int(0) or j == MAP_SIZE - 1):
                MapRouteList2[i].append(MAP_ROUTE)

            else:
                MapRouteList2[i].append(0)

    for i_MapRouteCount in range(0, MAP_SIZE - 2):
        MapPosInforList[i_MapRouteCount + 1] = MapRouteList2[i_MapRouteCount]

    print("游戏道路生成完毕!\n")

    # 生成游戏道具
    PropGenerateInit()

    # 生成玩家
    PlayerGenerateInit()


# 更新地图
def MapRefresh():
    print("\n正在更新地图...")

    for MapListCountY in range(MAP_SIZE):
        for MapListCountX in range(MAP_SIZE):

            # 地雷
            if (MapPosInforList[MapListCountY][MapListCountX] == PORP_LAND_MINE):
                print("⯐ ", end="")

            # 转盘
            elif (MapPosInforList[MapListCountY][MapListCountX] == PORP_LUCKY_TURN):
                print("♤ ", end="")

            # 时停
            elif (MapPosInforList[MapListCountY][MapListCountX] == PORP_TIME_PAUSE):
                print("▲ ", end="")

            # 道路
            elif (MapPosInforList[MapListCountY][MapListCountX] == MAP_ROUTE):
                print("□ ", end="")

            # 空白
            elif (MapPosInforList[MapListCountY][MapListCountX] == MAP_SPACE):
                print("  ", end="")

            # 玩家1
            elif (MapPosInforList[MapListCountY][MapListCountX] == PLAYER_PLAYER1):
                print("✪ ", end="")

            # 玩家2
            elif (MapPosInforList[MapListCountY][MapListCountX] == PLAYER_PLAYER2):
                print("⭗ ", end="")

        print("")   # 换行

    print("地图更新完毕!")


# 决定先手
def JudgmentOrder():
    if (PlayerOrder == int(0)):
        print("玩家1先手.")

    elif (PlayerOrder == int(1)):
        print("玩家2先手.")

    else:
        print("决定先手时出错, 程序结束!")
        sys.exit(-1)


# 拾取地雷
def PickUpLandMine(PlayerNum):
    print("玩家", PlayerNum + 1, "拾取地雷, 倒退回原来位置!")

    # 倒退
    if (PlayerNum == int(0)):
        MapPosInforList[Player1PosList[0]][Player1PosList[1]] = MAP_ROUTE

        Player1PosList[0] = PlayerOriginPosList[0]
        Player1PosList[1] = PlayerOriginPosList[1]
        MapPosInforList[Player1PosList[0]][Player1PosList[1]] = PLAYER_PLAYER1
        print(Player1PosList)

    else:
        MapPosInforList[Player2PosList[0]][Player2PosList[1]] = MAP_ROUTE

        Player2PosList[0] = PlayerOriginPosList[0]
        Player2PosList[1] = PlayerOriginPosList[1]
        MapPosInforList[Player2PosList[0]][Player2PosList[1]] = PLAYER_PLAYER2
        print(Player2PosList)


# 拾取转盘
def PickUpLuckTurn(PlayerNum):
    global PlayerOrder

    print("玩家", PlayerNum + 1, "拾取转盘, 在次移动一次!")

    if (PlayerNum == int(0)):
        PlayerOrder = int(0)

    else:
        PlayerOrder = int(1)


# 拾取时停
def PickUpTimePause(PlayerNum):
    global TimePauseFlag

    print("玩家", PlayerNum + 1, "拾取时停, 暂停一回合!")
    TimePauseFlag = True


# 玩家移动
# PlayerNum -- 玩家号
def PlayerMove(PlayerInputPosList):
    global PlayerMoveTotal
    global PlayerOriginPosList

    PlayerOriginPosList = PlayerInputPosList.copy()    # 保存原位置
    PlayerPosList = PlayerInputPosList                 # 移动后位置
    MapRouteLeftSpace = int(0)                         # 当前路径剩余的空间
    PlayerMoveTotal = int(0)                           # 玩家走的总距离
    PlayerNum = int(0)

    if (PlayerOriginPosList == Player1PosList):
        PlayerNum = int(0)

    elif (PlayerOriginPosList == Player2PosList):
        PlayerNum = int(1)

#    if (input("输入任意字符以开始移动:") != int(0)):
#        print("开始移动...")

    print(PlayerPosList)

    PlayerMoveDistance = random.randint(0, 6)          # roll点
    PlayerMoveTotal += PlayerMoveDistance
    print("玩家", PlayerNum + 1, "移动", PlayerMoveDistance, "格...")

    # 更改坐标
    # 处于路线 1
    if (PlayerPosList[0] == int(0)):
        MapRouteLeftSpace = (MAP_SIZE - 1) - PlayerPosList[1]

        # 空间不足, 进入路径 2
        if (MapRouteLeftSpace < PlayerMoveDistance):

            PlayerMoveDistance -= MapRouteLeftSpace
            # PlayerPosList = [PlayerMoveDistance, MAP_SIZE - 1]
            PlayerPosList[0] = PlayerMoveDistance
            PlayerPosList[1] = MAP_SIZE - 1

        else:
            PlayerPosList[1] += PlayerMoveDistance

    # 处于路线2
    elif (PlayerPosList[1] == MAP_SIZE - 1):

        # 空间不足, 进入路径 3
        if ((MAP_SIZE - 1) - PlayerPosList[0] < PlayerMoveDistance):
            MapRouteLeftSpace = (MAP_SIZE - 1) - PlayerPosList[0]
            PlayerMoveDistance -= MapRouteLeftSpace
            # PlayerPosList = [MAP_SIZE - 1, (MAP_SIZE - 1) - PlayerMoveDistance]
            PlayerPosList[0] = MAP_SIZE - 1
            PlayerPosList[1] = (MAP_SIZE - 1) - PlayerMoveDistance

        else:
            PlayerPosList[0] += PlayerMoveDistance

    # 处于路线3
    elif (PlayerPosList[0] == MAP_SIZE - 1):

        # 空间不足, 进入路径 4
        if (PlayerPosList[1] < PlayerMoveDistance):
            MapRouteLeftSpace = PlayerPosList[1]
            PlayerMoveDistance -= MapRouteLeftSpace
            # PlayerPosList = [(MAP_SIZE - 1) - PlayerMoveDistance, int(0)]
            PlayerPosList[0] = (MAP_SIZE - 1) - PlayerMoveDistance
            PlayerPosList[1] = int(0)

        else:
            PlayerPosList[1] -= PlayerMoveDistance

    # 处于路线4
    elif (PlayerPosList[1] == int(0)):

        # 空间不足, 进入路径 1
        if (PlayerPosList[0] < PlayerMoveDistance):
            MapRouteLeftSpace = PlayerPosList[0]
            PlayerMoveDistance -= MapRouteLeftSpace
            # PlayerPosList = [int(0), PlayerMoveDistance]
            PlayerPosList[0] = int(0)
            PlayerPosList[1] = PlayerMoveDistance
        else:
            PlayerPosList[0] -= PlayerMoveDistance

    else:
        print("出现错误! 玩家位置列表出错!")
        sys.exit(-1)

    print(PlayerPosList)

    # 载入玩家坐标
    if (PlayerNum == int(0)):
        PlayerPosRefresh(PlayerPosList, PLAYER_PLAYER1)

    elif (PlayerNum == int(1)):
        PlayerPosRefresh(PlayerPosList, PLAYER_PLAYER2)

    else:
        print("玩家坐标载入出错!")

    # 原坐标更改为道路
    if (PlayerMoveDistance != int(0)):
        MapPosInforList[PlayerOriginPosList[0]][PlayerOriginPosList[1]] = MAP_ROUTE

    # 判断是否拾取道具
    # 地雷
    if (LandMineList.count(PlayerPosList)):
        PickUpLandMine(PlayerNum)

    elif (LuckTurnList.count(PlayerPosList)):
        PickUpLuckTurn(PlayerNum)

    elif (TimePauseList.count(PlayerPosList)):
        PickUpTimePause(PlayerNum)

    else:
        print("未拾取道具.")


# 全局初始化
def FlyChestInit():
    GameInit()
    PlayerName()
    MapPosInforInit()
    MapRefresh()
    JudgmentOrder()


FlyChestInit()

while True:
    if (PlayerOrder == int(0) and TimePauseFlag != True):
        PlayerOrder = int(1)
        print("玩家1的回合...")
        PlayerMove(Player1PosList)
        MapRefresh()

    elif (PlayerOrder == int(0) and TimePauseFlag == True):
        PlayerOrder = int(1)
        TimePauseFlag = False
        print("玩家1的回合...")
        PlayerMove(Player1PosList)
        MapRefresh()
        print("玩家1的回合...")
        PlayerMove(Player1PosList)
        MapRefresh()

    elif (PlayerOrder == int(1) and TimePauseFlag != True):
        PlayerOrder = int(0)
        print("玩家2的回合...")
        PlayerMove(Player2PosList)
        MapRefresh()

    elif (PlayerOrder == int(1) and TimePauseFlag == True):
        PlayerOrder = int(0)
        TimePauseFlag = False
        print("玩家2的回合...")
        PlayerMove(Player2PosList)
        MapRefresh()

        print("玩家2的回合...")
        PlayerMove(Player2PosList)
        MapRefresh()
