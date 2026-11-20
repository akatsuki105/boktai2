#ifndef __DATA_SCRIPTS_SCRIPT_H__
#define __DATA_SCRIPTS_SCRIPT_H__

// data/scripts/scripts.bokc で include する用
// 行末コメントはダンパーがそのスクリプトの定義の直前のアドレスコメントにそのまま付け足す, 引数の説明は先頭に "p0=map, p1=entrance, p2=room" のように pN=名前 を並べて書く

#define Scr_InitNewGame 0x0002  // 新規ゲーム用にセーブデータを初期化する, 進行度と周回数を 0 にしてから能力値・棺桶・ステージなどの初期化を順に呼ぶ
#define Scr_InitPlayerStats 0x0003  // プレイヤーの能力値を初期化する, Lv1・ステータス 10 から最大 HP/ENE を計算し, ボスの HP ゲージも 500 にする
#define Scr_InitCoffinState 0x0006  // 棺桶の位置・向き・中身・時刻などの W_COFFIN_* を初期状態に戻す
#define Scr_InitItems 0x000C  // 所持アイテムを初期状態にしてアイテム 49 を持たせる
#define Scr_InitWeaponsAndMagic 0x000D  // 武器・防具と魔法を初期状態にする
#define Scr_ClearQuests 0x0012  // クエストの受注・クリアのフラグを全部消す
#define Scr_InitWeaponsAndArmors 0x0017  // 武器を 4 本, 防具を 1 つの初期状態にする
#define Scr_InitMagic 0x0018  // 魔法の所持状態を初期化する
#define Scr_ResetGameKeepingVars 0x001A  // Cmd_ResetGameKeepingVars でリセット後も残す値を引き継いでゲームの状態を消す
#define Scr_InitMapCommon 0x001D               // マップ初期化の共通処理, 日付を更新してから入場時の特別な場面か通常のシステム生成かを選ぶ, p0: bit2 なら特別な場面を判定しない
#define Scr_CreateMapSystems 0x001E            // マップ用の管理エンティティ (MsgBus, 敵管理, メニューなど) を作り, 一時フラグを初期化する
#define Scr_CreateMainMenu 0x0020              // メニュー画面 (MainMenu) を作る, マップ共通初期化の末尾で呼ばれる
#define Scr_0x0037 0x0037
#define Scr_SpawnSolarBarrier 0x003A  // 太陽結界を出す, p0/p1: x/z, p2: '.m', 棺桶が入る/出ると Scr_OnCoffinEnterSolarBarrier / Scr_OnCoffinLeaveSolarBarrier を呼ぶ
#define Scr_OnCoffinEnterSolarBarrier 0x003B  // 棺桶が太陽結界に入ったとき (SolarBarrier の '.i')
#define Scr_OnCoffinLeaveSolarBarrier 0x003C  // 棺桶が太陽結界から出たとき (SolarBarrier の '.o')
#define Scr_0x0045 0x0045
#define Scr_SpawnPileDriver 0x0047             // 進行度に応じて Bin_14F8 から設定を読んでパイルドライバーを作る, p0: '.m' モード, p1: '.d'
#define Scr_0x0049 0x0049
#define Scr_SetPileDriverBossHP 0x004A         // Bin_14F8 の p0 行目からボスの HP ゲージ (bossHP / bossHPMax) を設定する
#define Scr_PileDriverShoutOtenko 0x004D       // パイルドライバー発動時のおてんこさまの「太陽ぉーー!!」
#define Scr_PileDriverShoutDjango 0x004E       // パイルドライバー発動時のジャンゴの「太陽ぉーー!!」
#define Scr_PileDriverShoutBlackDjango 0x004F  // パイルドライバー発動時の黒ジャンゴの「太陽ぉーー!!」
#define Scr_0x0052 0x0052
#define Scr_PurifyBossLastWords 0x0054         // 浄化されたイモータルの断末魔, 進行度でドゥネイル/ドゥラスロール/ドヴァリン/ダーインを選ぶ
#define Scr_0x0055 0x0055
#define Scr_0x0056 0x0056
#define Scr_0x0057 0x0057
#define Scr_0x0058 0x0058
#define Scr_0x005F 0x005F
#define Scr_0x0061 0x0061
#define Scr_0x0062 0x0062
#define Scr_0x0063 0x0063
#define Scr_0x0064 0x0064
#define Scr_0x006A 0x006A
#define Scr_0x006E 0x006E
#define Scr_0x006F 0x006F
#define Scr_0x0070 0x0070
#define Scr_ResetCurrentStageState 0x0071           // 入口 p0 から来たとき (-1 なら常に) スイッチ・燭台・鍵扉などの仕掛けのフラグを消し, 敵の復活情報の残り回数を3回減らす
#define Scr_SetStage 0x0072                    // ステージIDを設定してバックアップする, 街 (p0 >= ST_AVE6) なら □のカギを捨てる
#define Scr_ClearStageEventFlags 0x0074  // W_CURRENT_STAGE_EVENT_FLAGS を全部消す
#define Scr_ClearStageFlags 0x0075  // W_CURRENT_STAGE_FLAGS を全部消す
#define Scr_ClearStageSwitches 0x0076  // W_CURRENT_STAGE_SWITCH_ON を全部消す
#define Scr_ClearStageChests 0x0077  // W_CURRENT_STAGE_CHEST_OPENED を全部消す
#define Scr_ClearCandles 0x0078  // W_CANDLE_LIT を全部消す
#define Scr_SetMapStageBgm 0x0079              // 入口 p4 から来たとき (-1 なら常に) BGM とステージを設定する, p0: ステージID, p1: BGM, p2: フェード時間 (0 なら 1)
#define Scr_BeginEventLockPlayer 0x007B        // Scr_BeginEvent(1) をしてプレイヤーを止める
#define Scr_EndEventUnlockPlayer 0x007D        // イベントを終えてプレイヤーを動けるようにする
#define Scr_BeginEvent 0x007E                  // イベントを始める (GAMEFLAG_CUTSCENE), 出口の矢印を隠す, p0: 1 なら Entity と BGM を止める
#define Scr_EndEvent 0x007F                    // イベントを終える, 止めた Entity と BGM を再開して出口の矢印を戻す
#define Scr_BeginCutscene 0x0080               // 演出を始める, コウモリ/ネズミ/睡眠の姿を戻してから p0 のスクリプトを実行し, HUD をモード7のままにする印を立てる
#define Scr_EndCutscene 0x0081                 // 演出を終える, イベント終了と印・段階カウンタ (scratch + 0x2F) を戻す
#define Scr_SpawnExitArrow 0x0082              // ゾーン p0 に出口の矢印を出す (scratch + 0x15 が 4 以上なら出さない)
#define Scr_AddEntranceEx 0x0085               // Scr_AddEntrance の全引数版, p3: 歩く距離, p4: 着いた後のスクリプト, p5: 種類 (4 なら矢印なし)
#define Scr_AddEntrance 0x0086                 // 出口の矢印を出し, 入口 p2 から来たときはゾーン p0 から向き p1 で歩いて入らせる
#define Scr_AddEntranceNoArrow 0x0087          // 矢印を出さず, 入口 p2 から来たらゾーン p0 に向き p1 で置く, p3: 着いた後のスクリプト
#define Scr_0x0089 0x0089
#define Scr_0x008B 0x008B
#define Scr_AddPosEntrance 0x008D              // 入口 p3 から来たら座標 (p0, p1) に向き p2 で置く, イベントで包んで 16 フレーム後に解除する
#define Scr_AddPosEntranceScript 0x008F        // Scr_AddPosEntrance のイベントなし版, 置いた後に p5 のスクリプトを p4 を引数に呼ぶ
#define Scr_ExitInterruptedRoomBattle 0x0096   // 閉じ込め戦闘のフラグ (world + 0x4C bit0) が残ったまま読み込まれたら, すぐ p0 のマップ (入口 p1, 部屋 p2) へ移す
#define Scr_AddExit 0x0099                     // 出口を作る, プレイヤーがゾーン p0 に入ったら p1 のマップへ移る, p2: 行き先の入口番号, p3: 行き先の部屋番号 (stat + 0x242)
#define Scr_AddExitEx 0x009C                   // Scr_AddExit の全引数版, p4: 歩く距離, p5: 種類 (5/6 で入場タイトル, 2/3 は歩かない), p6: 移る前に呼ぶスクリプト
#define Scr_Warp 0x00A2                        // p0=map, p1=entrance, p2=room フェードせずにマップ map の入口 entrance (部屋 room) へ移る
#define Scr_FadeWarp 0x00A3                    // p0=map, p1=entrance, p2=room 16 フレームで暗転してマップ map の入口 entrance (部屋 room) へ移る
#define Scr_FadeWarpEx 0x00A6                  // Scr_FadeWarp の全引数版, p3: 移る直前に呼ぶスクリプト, p4: フェード時間
#define Scr_AddExitAtHeight 0x00A7             // ゾーン p0 にプレイヤーが高さ p4 (タイル) でいる間, p1 のマップの入口 p2 (部屋 p3) へ歩かずに移る
#define Scr_0x00AA 0x00AA
#define Scr_0x00AB 0x00AB
#define Scr_0x00AF 0x00AF
#define Scr_GetZoneBounds 0x00B6               // ゾーン p0 の範囲と中心を scratch + 0x22..0x4A に入れる
#define Scr_LoadCollisionMap 0x00B7            // 当たり判定マップを読み BG 用フラグを既定にする, p0: 未使用, p1: ファイルID
#define Scr_LoadCollisionMapEx 0x00B8  // Scr_LoadCollisionMap の全引数版, p2: BG 用フラグ, p3: カメラのタイルマップのずれ
#define Scr_CreateMapBG 0x00B9                 // マップのタイルマップを BG にする, p0: タイルマップ, p1: 0 なら BG2, 1 なら BG3
#define Scr_CreateBG 0x00BA                    // BG を作る, p0: エンティティID, p1: タイルマップ, p2: 優先度, p3: BG 番号
#define Scr_TrackZoneMapSpot 0x00C0            // Scr_TrackZone に加え, MapSpot を p1 にする (棺桶を連れていれば棺桶の場所も)
#define Scr_TrackZone 0x00C1                   // プレイヤーがゾーン p0 に入ったら, それを現在のゾーン (stat + 0x248) にする
#define Scr_SetMapSpotOnEnter 0x00C2           // プレイヤーがゾーン p0 に入ったら MapSpot を p1 にする (棺桶も同様)
#define Scr_IsMapEntryScene 0x00C3             // マップ入場時の特別な場面 (ダンジョンタイトルなど) を出しているかを返す
#define Scr_SetMapFlags 0x00C4                 // マップフラグ (stat + 0x934, MPF_*) に p0 を立てる
#define Scr_ClearMapFlags 0x00C5               // マップフラグから p0 を落とす
#define Scr_CreateBgPlttController 0x00C6               // マップのパレット管理を作る, p0: 基本の BG パレット, p1/p2: 時間帯で混ぜるパレット (0 なら p0 のみ)
#define Scr_CreateSunlitBgPltt 0x00C7          // p0 のゾーンにいる間, 太陽が当たっているかどうかで BG パレットを差し替える仕掛けを作る (BgPlttController 0x317B)
#define Scr_ShowSolarFloor 0x00C9              // 太陽床の汎用オブジェ15個 (0x7C83〜) を表示する
#define Scr_HideSolarFloor 0x00CA              // 太陽床の汎用オブジェ15個 (0x7C83〜) を消す
#define Scr_OnSolarFloorAppear 0x00CB          // 太陽ゲージが範囲に入ったとき, 音を鳴らして太陽床を出し, 床のタイルの上書きを切り替える
#define Scr_OnSolarFloorVanish 0x00CC          // 太陽ゲージが範囲から出たとき, 太陽床を消し, 床のタイルの上書きを戻す
#define Scr_CreateSolarFloorWatcher 0x00CD     // 太陽床の監視 (SunRangeWatcher, インスタンスは HashName("太陽床")) を作る, 太陽ゲージ 1〜8 の間だけ床が出る
#define Scr_FadeScreen 0x00D1                  // 画面をフェードする, p0: 2/4 でフェードイン, 3/5 でフェードアウト, p1: 色 (0: 黒, 1: 白, 2: 緑, 3: 赤, 4: 青), p2: フレーム数
#define Scr_FadeScreenThen 0x00D2              // Scr_FadeScreen に終わったら呼ぶスクリプト p3 を足したもの
#define Scr_FadeScreenEx 0x00D3                // Scr_FadeScreen の全引数版, p5: 終わったら呼ぶスクリプト
#define Scr_SendBgPlttCommand 0x00D4           // BG パレットコマンドを送る, p0: コマンド番号, p1〜p5: 引数
#define Scr_SendObjPlttCommand 0x00D5          // OBJ パレットコマンドを送る, p0: コマンド番号, p1〜p5: 引数
#define Scr_SetFadeKind 0x00D6                 // フェードの種類 p0 (BG 側の 2〜5) を OBJ 側の番号 (1〜4) に直して S_FADE_KIND に入れる
#define Scr_SetFadeSpeed 0x00D7                // フェードのフレーム数 p0 (1, 16〜256) を長さの log2 に直して S_FADE_SPEED に入れる
#define Scr_SetFadeColor 0x00D8                // フェード色の番号 p0 (0: 黒, 1: 白, 2: 緑, 3: 赤, 4: 青) を S_FADE_R/G/B に入れる
#define Scr_IsNight 0x00DB  // 夜 (時間帯が TIME_NIGHT_DAWN / TIME_NIGHT_DUSK / TIME_NIGHT_MID) なら 1 を返す
#define Scr_CreateOcclusionMask 0x00DC  // 壁の裏に入ったキャラを隠すマスク (OcclusionMask) を作る, p0: 壁の形のスプライト ('.m', SPR_MASK_*), p1: '.n', W_UNK_00C_5 が 0 ならプレイヤーも登録する
#define Scr_PlaceMovableBlock 0x00DD           // 押せるブロックを置く, p0: ID, p1: 種類, p3/p5: 座標, p4: 高さ
#define Scr_PlaceMovableBlockEx 0x00DE  // Scr_PlaceMovableBlock の全引数版
#define Scr_0x00E3 0x00E3
#define Scr_0x00E4 0x00E4
#define Scr_AddObjSkylight 0x00EF              // オブジェ天窓を1つ置く, 天窓の光の範囲と光の柱 (汎用オブジェ) を同じ ID で登録し, パレットは時間帯で選ぶ, 最大12個
#define Scr_CreateSunlitSkylights 0x00F0       // 太陽が当たっている間だけオブジェ天窓を出す仕掛けを作る (SunRangeWatcher 0x9A75)
#define Scr_SelectBySpanOfTime 0x00F1          // 時間帯で p0 (朝・昼), p1 (夕方), p2 (夜) のどれかを返す
#define Scr_ShowSkylights 0x00F2               // 部屋を明るくしてオブジェ天窓を出す
#define Scr_HideSkylights 0x00F3               // 部屋を暗くしてオブジェ天窓を消す
#define Scr_SetMsgWindowScripts 0x00F4         // メッセージウィンドウのスクリプトID列 ('.p') を p0, p1 にする
#define Scr_OpenMsgWindow 0x00F8               // p0=hudMode, p1=body, p2=unused メッセージウィンドウを開く, hudMode: HUD モード, body: 本文のスクリプトID
#define Scr_OpenChoiceCancelable 0x00F9        // B でキャンセルできる選択肢を出す, p0: ID, p1: 結果を受けるスクリプト, p2/p3: スクリプトへ渡す引数
#define Scr_OpenChoiceNoCancel 0x00FA          // B でキャンセルできない選択肢を出す, 引数は Scr_OpenChoiceCancelable と同じ
#define Scr_OpenChoice 0x00FC                  // 選択肢を出す, p0: ID, p1: 結果を受けるスクリプト, p2-p5: 矩形, p6: 文字列の基準, p7: 初期カーソル, p8: B でキャンセルできるか, p9/p10: スクリプトへ渡す引数
#define Scr_CloseMsgWindow 0x00FD              // メッセージウィンドウを閉じて HUD モードを戻す
#define Scr_EndEventCloseMsg 0x00FE            // イベントを終え, プレイヤーを動けるようにしてメッセージウィンドウを閉じる
#define Scr_CloseMsgWindowHUDHidden 0x00FF     // メッセージウィンドウを閉じ, HUD は隠したまま (モード7) にする
#define Scr_0x0102 0x0102
#define Scr_AddDoor 0x0104                     // 扉をゾーン p1 の辺 p2 に置く, p0: 扉ID, p3: 扉の種類 ('.d'), p4: この入口から来たときは開いている (202 なら常に)
#define Scr_AddDoorEx 0x0105  // Scr_AddDoor の全引数版
#define Scr_AddLockedDoor 0x0107               // 鍵付き扉を置く, p0: ゾーン, p1: 辺, p2: マップアイコン番号, p5: 開いている入口, p6: 鍵フラグ番号 (world + 0x1D), p7: 鍵アイテム, p8: 開けたときのスクリプト
#define Scr_AddLockedDoorEx 0x0108  // Scr_AddLockedDoor の全引数版
#define Scr_0x0109 0x0109
#define Scr_0x010A 0x010A
#define Scr_0x010B 0x010B
#define Scr_0x010C 0x010C
#define Scr_UseKey 0x010D                      // 鍵を使った
#define Scr_DoorLocked 0x010E                  // 鍵がかかっている
#define Scr_AddShutter 0x010F                  // 開閉する扉をゾーン p1 の辺 p2 に置く, p0: 扉ID, p3: 開いた状態で置くか, p4: 高さ
#define Scr_0x0111 0x0111
#define Scr_0x0112 0x0112
#define Scr_OpenDoorWithCamera 0x0113          // カメラをゾーン p2 へ動かして扉 p1 を開け, 戻してからイベントを終える
#define Scr_AddScriptSprite 0x011E             // スクリプトから操る表示要素を追加する, p0: ID, p1: スプライト, p5-p7: 位置
#define Scr_SetEnemyDrops 0x0122               // 敵が落とす物を2つ設定する, p0/p2: 種類, p1/p3: ID
#define Scr_0x0123 0x0123
#define Scr_0x0125 0x0125
#define Scr_PlaceRandomCardChest 0x0126        // 13種の魔法カードからランダムに1枚入った宝箱を置く, p0/p1: 座標, p2: 宝箱のフラグ番号
#define Scr_PlaceMapItem 0x0128  // マップにアイテム (MapItem) を置く, p0: 種類, p1: アイテムID, p2〜p4: 座標, p5: 出現演出, p6: 拾ったときのスクリプト, p7: 引数, p8: オプション
#define Scr_0x012A 0x012A
#define Scr_0x012B 0x012B
#define Scr_PlaceChest 0x012F                  // 宝箱を置く, p0: 種類, p1: ID, p2/p3: 座標, p4: 向き, p5: フラグ, p6: 開封フラグ番号
#define Scr_PlaceChestAutoDir 0x0130           // 宝箱を置く, 向きは地形から自動で決める, p4: 開封フラグ番号
#define Scr_PlaceChestEx 0x0131                // 宝箱を置く全引数版, p5: 1 なら出現演出つき
#define Scr_PlaceChestBlinking 0x0132          // Scr_PlaceChest と同じで, 点滅させる ('.S' = 1)
#define Scr_0x0134 0x0134
#define Scr_OnChestOpened 0x0135               // 宝箱を開けたときの処理, 取得フラグを立てて p3 (0: アイテム, 1: 武器, 2: 防具, 3: 魔法, 4: 地図) の p4 を渡す, p6/p7: 続けて呼ぶスクリプトと引数
#define Scr_0x0136 0x0136
#define Scr_0x0137 0x0137
#define Scr_0x0138 0x0138
#define Scr_0x0139 0x0139
#define Scr_OnPhotoChestOpened 0x013D          // ブロマイドの宝箱を開けたときの処理, p5: 写真番号, p6/p7: 続けて呼ぶスクリプトと引数
#define Scr_0x013F 0x013F
#define Scr_AddLamp 0x0144                     // 照明 (燭台・シャンデリア) を置く, p1: 初期状態 (燭台フラグも更新), p8: 燭台フラグ番号
#define Scr_AddLampEx 0x0145  // Scr_AddLamp の全引数版
#define Scr_0x014B 0x014B
#define Scr_CreateElevator 0x014C  // エレベーターを作る, p0: '.n', p1/p2: '.r', p3: 高さ (タイル), p4: '.k', p5: '.s', p6: '.p', p7: '.S'
#define Scr_0x014E 0x014E
#define Scr_0x014F 0x014F
#define Scr_CreateElevatorByEntrance 0x0152    // 移動床/昇降床を作る, 入口 p14 から来たときは別の初期位置で作る
#define Scr_0x015B 0x015B
#define Scr_0x015D 0x015D
#define Scr_PlaceSolarStand 0x0161             // 太陽スタンドを (p0, p1) に置き, 足元のタイルを上書きする, p2: '.f'
#define Scr_PlaceSolarStandEx 0x0162  // Scr_PlaceSolarStand の全引数版, p0: ID
#define Scr_AddTileOverride 0x0163             // 当たり判定タイルを上書きする, p0: ID, p1: 段差, p2: 属性, p3: '.f', p4-p6: 位置
#define Scr_0x016F 0x016F
#define Scr_0x0170 0x0170
#define Scr_PlayBgm 0x0172                     // BGM を切り替える, 今と違う曲ならフェードアウトしてから鳴らす, p0: フェード時間 (0 なら即座), p1: 曲
#define Scr_ItemWarp 0x0175 // ワープアイテムによるワープ, p0: 種類 (0: 転移の葉, 1: 愚者のカード, 2: 暗黒ローン)
#define Scr_Riremito 0x0176                    // 転移の葉によるダンジョンからの脱出
#define Scr_MapRetry 0x0177                    // 愚者のカード, 暗黒ローンの"やり直し"
#define Scr_InitRoomBattle 0x0178              // 閉じ込め戦闘を初期化する, p0: 倒すべき数
#define Scr_AddRoomBattleShutter 0x0179        // 閉じ込め戦闘用の扉をゾーン p0 の辺 p1 に置く (最大4枚), p2: 高さ
#define Scr_PrepareRoomBattle 0x017A           // 閉じ込め戦闘の準備, BGM を消して戦闘曲を予約する, p1: Str_Missions の行 (60 ならメッセージなし)
#define Scr_PrepareRoomBattleEx 0x017B  // Scr_PrepareRoomBattle の全引数版, p2: 1 なら BGM を消さない
#define Scr_0x017C 0x017C
#define Scr_ShowRoomMission 0x017E             // 部屋のミッション文 (敵をみな殺しにしろ等) を表示する
#define Scr_0x017F 0x017F
#define Scr_0x0180 0x0180
#define Scr_EndRoomBattle 0x0181               // 閉じ込め戦闘の終わり, 曲を鳴らしてプレイヤーを動けるようにし, 280 フレーム後に元の BGM へ戻す
#define Scr_CreateMissionMarker 0x0184  // ミッションの目印 (MissionMarker) を作る, p0: ID, p1: '.t', p2: '.I', p3: '.p'
#define Scr_0x0187 0x0187
#define Scr_0x0188 0x0188
#define Scr_CreateDoorManager 0x018B           // 扉の絵一式を持つ DoorManager を作る, p0: '.m'
#define Scr_SpawnBambooShoots 0x018C           // 太陽タケノコを最大5個ばらまく, p0: 精霊虫の種類 (3 なら時間帯で抽選), p1: 精霊虫の数, p2/p3: 中心, p4: ばらつき, p5: 個数
#define Scr_SpawnSolarBamboo 0x018E  // 太陽タケノコを 1 つ出す, p0: ID, p1/p2: x/z (高さは地面から取る), p3: '.l', p4: '.n', p5: '.e'
#define Scr_AddInteractPoint 0x018F            // 調べられる場所を置く, p0: ID, p1: 壁の向き, p2: スプライトなし, p3: 調べたときのスクリプト, p4/p5: 座標
#define Scr_AddInteractPointEx 0x0191  // Scr_AddInteractPoint の全引数版
#define Scr_EndInteractMsg 0x0192              // 調べる場所のメッセージを閉じてイベントを終え, 調べ終わりにする
#define Scr_AdvanceStory 0x0196                // p0=progress ストーリー進行度 (world + 0x0) を progress に上げる, 今より小さければ何もしない
#define Scr_GetKeyData 0x0198                  // ロックマンエグゼ連動のキーデータ1〜4を進行度に応じて入手する
#define Scr_CreateAlarmPanel 0x019B  // 警報パネル (AlarmPanel) を作る, p0: ID, p1/p3: x/z, p2: 高さ (タイル), p4: '.r', p5: '.h', p6: '.R'
#define Scr_CreateBarricade 0x019F  // バリケードを作る, p0: ID, p1〜p3: 位置, p4: '.t', p5: '.i', p6: '.r', p7: '.R'
#define Scr_SetCameraBoundsOnEnter 0x01AA      // ゾーン p0 に入ったらカメラの移動範囲を (p1, p2)-(p3, p4) にする
#define Scr_SetCameraBoundsDiagOnEnter 0x01AB  // ゾーン p0 に入ったらカメラの移動範囲を斜めの範囲 (bounds type 2) にする
#define Scr_0x01B3 0x01B3
#define Scr_0x01B4 0x01B4
#define Scr_0x01B5 0x01B5
#define Scr_0x01D2 0x01D2
#define Scr_0x01D5 0x01D5
#define Scr_PlaceWarpMagicSquare 0x01D8        // ワープ魔方陣を (p1, p2) に置く, p0: ID
#define Scr_PlaceWarpMagicSquareEx 0x01D9  // Scr_PlaceWarpMagicSquare の全引数版
#define Scr_0x01DA 0x01DA
#define Scr_0x01DB 0x01DB
#define Scr_0x01DC 0x01DC
#define Scr_StartChangePlayerA 0x01E6  // 操作キャラ交代を始める, 行き先 p0 を W_CHANGE_PLAYER_DEST_A に記録し, ワイプを閉じて Scr_FinishChangePlayer へ
#define Scr_StartChangePlayerB 0x01E7  // 操作キャラ交代を始める, 行き先 p0 を W_CHANGE_PLAYER_DEST_B に記録し, ワイプを閉じて Scr_FinishChangePlayer へ
#define Scr_FinishChangePlayer 0x01E8  // 良い状態と悪い状態を消し, 記録した行き先の螺旋の塔の部屋へワープする
#define Scr_0x01EF 0x01EF
#define Scr_ResumeCountdown 0x01F1             // 前のマップの残りフレーム (world + 0x52) でカウントダウンを出し直す
#define Scr_SetupRequestMap 0x01F2             // 依頼の実行中ならメニューとアイテム使用を制限し, レア敵の抽選を止める
#define Scr_0x01F6 0x01F6
#define Scr_GetActiveRequest 0x01F9            // 実行中の依頼の番号を返す, 無ければ -1
#define Scr_ApplyRequestRestrictions 0x01FA    // 実行中の依頼に応じて攻撃・魔法を禁止する
#define Scr_0x01FB 0x01FB
#define Scr_0x01FD 0x01FD
#define Scr_DropSpikeBall 0x01FE  // 鉄球 (FallingObject の TYPE_SPIKEBALL) を落とす, p0: ID, p1〜p3: 落とし始める位置, p4: 威力
#define Scr_SpawnFallingObject 0x01FF  // 落下物 (Cmd_SpawnFallingObject) を出す全引数版, p0: ID, p1〜p3: 位置, p4: 種類, p5: フラグ, p6: 残る時間, p7: 落下の速さ, p8: HP, p9: 威力, p10: '.F'
#define Scr_0x0200 0x0200
#define Scr_0x0202 0x0202
#define Scr_0x0204 0x0204
#define Scr_0x0207 0x0207
#define Scr_StartChangePlayerWipe 0x020D  // プレイヤー交代の円形ワイプ (ChangePlayerWipe) を出す, p0: 0 で閉じる, 1 で開く (W_CHANGE_PLAYER_WIPE_ON_ENTRY を切り替える)
#define Scr_HugeExplosion 0x0212  // 大爆発 (Cmd_HugeExplosion) を起こす, p0/p1/p2: 座標 (p1 は高さ, 256 倍して渡す), p3〜p6: 攻撃値4つ
#define Scr_0x0213 0x0213
#define Scr_0x0214 0x0214
#define Scr_0x0215 0x0215
#define Scr_0x0216 0x0216
#define Scr_0x0217 0x0217
#define Scr_0x0218 0x0218
#define Scr_0x0219 0x0219
#define Scr_0x021A 0x021A
#define Scr_0x021B 0x021B
#define Scr_0x021C 0x021C
#define Scr_0x021D 0x021D
#define Scr_0x021E 0x021E
#define Scr_0x021F 0x021F
#define Scr_0x0220 0x0220
#define Scr_0x0221 0x0221
#define Scr_0x0222 0x0222
#define Scr_0x0223 0x0223
#define Scr_0x0224 0x0224
#define Scr_0x0225 0x0225
#define Scr_0x0226 0x0226
#define Scr_0x0227 0x0227
#define Scr_0x0228 0x0228
#define Scr_0x0229 0x0229
#define Scr_0x022A 0x022A
#define Scr_0x022B 0x022B
#define Scr_0x022C 0x022C
#define Scr_0x022D 0x022D
#define Scr_0x022E 0x022E
#define Scr_HideOtenko 0x0234                  // おてんこを隠す
#define Scr_0x0235 0x0235
#define Scr_AddFriendship 0x0236               // p0=who, p1=amount 好感度を増減する, who: 0 ザジ, 1 リタ, 2 スミレ, 3 サバタ, 4 レディ
#define Scr_0x023A 0x023A
#define Scr_0x023C 0x023C
#define Scr_0x0241 0x0241
#define Scr_0x0243 0x0243
#define Scr_0x0244 0x0244
#define Scr_0x0248 0x0248
#define Scr_0x0249 0x0249
#define Scr_0x024A 0x024A
#define Scr_0x024B 0x024B
#define Scr_0x024C 0x024C
#define Scr_IsArmorObtained 0x024E  // 防具 p0 を取得済みか
#define Scr_CountObtainedArmors 0x024F  // 取得済みの防具の数を数える
#define Scr_IsWeaponObtained 0x0250  // 武器 p0 を取得済みか
#define Scr_CountObtainedWeapons 0x0251  // 取得済みの武器の数を数える
#define Scr_IsEnemyMet 0x0252  // 魔物図鑑で敵 p0 に出会ったか
#define Scr_CountEnemiesMet 0x0253  // 魔物図鑑で出会った敵の数を数える
#define Scr_IsPhotoObtained 0x0254  // ブロマイド p0 を取得済みか
#define Scr_CountObtainedPhotos 0x0255  // 取得済みのブロマイドの数を数える
#define Scr_AddCrossoverPoint 0x0256  // クロスオーバーポイントに p0 を足す, 0 未満にはしない
#define Scr_RaiseBlindBoxLevel 0x0257  // ブラインドボックスのレベルを p0 まで上げる, 下げはしない
#define Scr_CountTitlesEarned 0x0259  // 獲得した称号の数を数える
#define Scr_CountImmortalResearched 0x025A  // 調査済みのイモータルダンジョンの数を数える
#define Scr_CountUndeadResearched 0x025B  // 調査済みのアンデッドダンジョンの数を数える
#define Scr_Nop 0x025C                         // 何もしない, 「スクリプトなし」のコールバックとして渡される
#define Scr_RollRareEnemy 0x025E               // レア敵が出るかを抽選する, p0: その系統の撃破数, パレードアーマーで確率が上がる
#define Scr_ScaleEnemyParamsForLap 0x025F      // 2周目以降なら用意した敵の能力値を 1.5 倍にする
#define Scr_SetBokuParams 0x0260               // ボクの能力値を scratch に用意する, p0: 種類 (レア抽選で 3)
#define Scr_SpawnBoku 0x0261                   // ボクを出す, p0: ID, p3: 撃破時スクリプト, p5: 種類
#define Scr_SpawnBokuEx 0x0262  // Scr_SpawnBoku の全引数版
#define Scr_SetSkeletonParams 0x0263           // スケルトンの能力値を scratch に用意する, p0: 種類 (レア抽選で 5)
#define Scr_SpawnSkeleton 0x0264               // スケルトンを出す, p4: 種類
#define Scr_SpawnSkeletonEx 0x0265  // Scr_SpawnSkeleton の全引数版
#define Scr_SetLichParams 0x0266  // リッチの能力値を scratch に用意する, 種類 0 のみ, 感知範囲 1280, Scr_SpawnLich と組で使う
#define Scr_SpawnLich 0x0267  // リッチを出す, 変異域 B2 のボス部屋などで使う
#define Scr_0x0268 0x0268  // リッチが呼び出すスケルトンを出す (能力値は固定値), p4: ID, p5: Scr_LichSummonSkeleton1〜3 の番号
#define Scr_0x0269 0x0269  // リッチが呼び出すスケルトンを出す (能力値は固定値, Scr_0x0268 とは攻撃の値が違う), p4: ID, p5: Scr_LichSummonSkeleton1〜3 の番号
#define Scr_SetLichPlusParams 0x026A  // リッチ+ の能力値を scratch に用意する, 種類 1 のみ, 感知範囲 4096, Scr_SpawnLichPlus と組で使う
#define Scr_SpawnLichPlus 0x026B  // リッチ+ を出す, 召喚スクリプト ('.s') に Scr_SpawnSalamander を渡す, 変異域 B4 のボス部屋などで使う
#define Scr_0x026C 0x026C  // スケルトンを出す, Scr_SpawnSkeletonEx に引数がさらに2つ付いた版?
#define Scr_SetMummyParams 0x026D  // マミーの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnMummy 0x026E                  // マミーを出す, p5: 種類
#define Scr_SpawnMummyEx 0x026F  // Scr_SpawnMummy の全引数版
#define Scr_SetGolemParams 0x0270  // ゴーレムの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnGolem 0x0271                  // ゴーレムを出す, p4: 種類
#define Scr_SpawnGolemEx 0x0272  // Scr_SpawnGolem の全引数版
#define Scr_SetCockatriceParams 0x0273  // コカトリスの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnCockatrice 0x0274             // コカトリスを出す, p4: 種類
#define Scr_SpawnCockatriceEx 0x0275  // Scr_SpawnCockatrice の全引数版
#define Scr_SetDogParams 0x0276  // 犬の能力値を scratch に用意する, p0: 種類
#define Scr_SpawnDog 0x0277                    // 犬を出す, p4: 種類
#define Scr_SpawnDogEx 0x0278  // Scr_SpawnDog の全引数版
#define Scr_SetSpiderParams 0x0279  // スパイダーの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnSpider 0x027A  // スパイダーを出す, p4: 種類
#define Scr_SpawnSpiderEx 0x027B  // Scr_SpawnSpider の全引数版
#define Scr_SetCuroroParams 0x027C  // クロロホルルンの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnCuroro 0x027D  // クロロホルルンを出す, p7: 種類
#define Scr_SpawnCuroroEx 0x027E  // Scr_SpawnCuroro の全引数版
#define Scr_0x027F 0x027F  // クロロホルルンを出す, 位置指定 ('.p') の無い版
#define Scr_0x0280 0x0280  // バットを最大5匹, 範囲内のランダムな位置に出す, 高さは (p1, p2) の地面から取る
#define Scr_0x0281 0x0281  // バットを最大 p8 匹 (5 まで), 範囲内のランダムな位置に出す, p9: 撃破時スクリプト
#define Scr_SetBatParams 0x0282  // バットの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnBat 0x0283  // バットを出す ('.T' = 1), p6: 種類
#define Scr_0x0284 0x0284  // バットを出す ('.T' = 0), p6: 種類
#define Scr_SpawnBatEx 0x0285  // バットを出す (全引数版), p7: '.T'
#define Scr_0x0286 0x0286  // クロウを最大 p3 匹 (5 まで), 範囲内のランダムな位置に出す
#define Scr_SetCrowParams 0x0287  // クロウの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnCrow 0x0288  // クロウを出す, p6: 種類
#define Scr_SpawnCrowEx 0x0289  // Scr_SpawnCrow の全引数版
#define Scr_SetMimicParams 0x028A  // ミミックの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnMimic 0x028B  // ミミックを出す, p6: 種類
#define Scr_0x028C 0x028C  // ミミックを出す (能力値を用意しない版)
#define Scr_SpawnMimicEx 0x028D  // Scr_SpawnMimic の全引数版
#define Scr_SetSlimeParams 0x028E  // スライムの能力値を scratch に用意する, p0: 種類
#define Scr_0x028F 0x028F  // スライムを出す, Scr_SpawnSlime と違い座標を地面に合わせない, 呼び出し元なし
#define Scr_0x0290 0x0290  // スライムを出す (全引数版), 座標を地面に合わせない
#define Scr_SpawnSlime 0x0291                  // スライムを出す, p6: 種類
#define Scr_SpawnSlimeEx 0x0292  // Scr_SpawnSlime の全引数版
#define Scr_SetBeeParams 0x0293  // ビーの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnBee 0x0294  // ビーを出す, p6: 種類
#define Scr_SpawnBeeEx 0x0295  // Scr_SpawnBee の全引数版
#define Scr_CreateBeeNest 0x0296  // ビーの巣を作る
#define Scr_SetCentipedeParams 0x0297  // センチピードの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnCentipede 0x0298  // センチピードを出す, p6: 種類
#define Scr_SpawnCentipedeEx 0x0299  // Scr_SpawnCentipede の全引数版
#define Scr_SetGhostParams 0x029A  // ゴーストの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnGhost 0x029B  // ゴーストを出す, p5: 種類
#define Scr_SpawnGhostEx 0x029C  // Scr_SpawnGhost の全引数版
#define Scr_SetSandwormParams 0x029D  // サンドウォームの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnSandworm 0x029E  // サンドウォームを出す, p1: 撃破時スクリプト, 登場時スクリプトは Scr_OnSandwormAppear に決まっている
#define Scr_OnSandwormAppear 0x029F  // BGM を消し, Cmd_C15E を p0 に向けて呼び (カメラ?), プレイヤーを止める, Scr_SpawnSandworm が登場時スクリプト ('.d') として渡す
#define Scr_OnSandwormDefeated 0x02A0  // Cmd_C15E をプレイヤー (0xF5EB) に戻し, プレイヤーを動かせるようにする, サンドウォーム戦の後に呼ばれる
#define Scr_SetSerpentParams 0x02A1  // サーペントの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnSerpent 0x02A2  // サーペントを出す, p1: 登場時スクリプト, p2: 撃破時スクリプト
#define Scr_OnSerpentAppear 0x02A3  // BGM を消し, Cmd_C15E を p0 に向けて呼び (カメラ?), プレイヤーを止める, サーペントの登場時スクリプトとして渡される
#define Scr_OnSerpentDefeated 0x02A4  // Cmd_C15E をプレイヤー (0xF5EB) に戻し, プレイヤーを動かせるようにする, サーペント戦の後に呼ばれる
#define Scr_SetOctopusParams 0x02A5  // オクトパスの能力値を scratch に用意する, p0: 種類
#define Scr_SpawnOctopus 0x02A6  // オクトパスを出す, p5: 種類
#define Scr_SpawnOctopusEx 0x02A7  // Scr_SpawnOctopus の全引数版
#define Scr_SetDarkRootParams 0x02A8  // 暗黒の根の能力値を scratch に用意する, p0: 種類
#define Scr_SpawnDarkRoot 0x02A9  // 暗黒の根を出す, p5: 種類
#define Scr_0x02AA 0x02AA  // 暗黒の根を出す, Scr_SpawnDarkRootEx の最後の引数を 0 にした版
#define Scr_SpawnDarkRootEx 0x02AB  // 暗黒の根を出す (全引数版)
#define Scr_SetAxParams 0x02AC  // アックス系の能力値を scratch に用意する, p0: 種類
#define Scr_SpawnAx 0x02AD  // アックス系を出す, Ax_Create で作る
#define Scr_SetEneSwordParams 0x02AE  // ソード系の能力値を scratch に用意する, p0: 種類
#define Scr_SpawnEneSword 0x02AF  // ソード系を出す, p6: 種類
#define Scr_SpawnEneSwordEx 0x02B0  // Scr_SpawnEneSword の全引数版, EneSword_Create で作る
#define Scr_0x02B2 0x02B2
#define Scr_0x02B3 0x02B3
#define Scr_0x02B4 0x02B4
#define Scr_0x02B5 0x02B5
#define Scr_0x02B8 0x02B8
#define Scr_0x02B9 0x02B9
#define Scr_0x02BA 0x02BA
#define Scr_SetPlayerLevel 0x02BD              // レベルを p0 にしてステータス/HP/エナジー/経験値を計算し直す
#define Scr_f00 0x02BE // "f00", 6番街 (陸番街)
#define Scr_0x02C4 0x02C4
#define Scr_0x02C6 0x02C6
#define Scr_0x02C7 0x02C7
#define Scr_0x02C8 0x02C8
#define Scr_0x02C9 0x02C9
#define Scr_0x02CB 0x02CB
#define Scr_f01 0x02CC // "f01", 10番街 (拾番街)
#define Scr_0x02D2 0x02D2
#define Scr_0x02D4 0x02D4
#define Scr_f02 0x02D5 // "f02", 4番街 (肆番街)
#define Scr_0x02DB 0x02DB
#define Scr_0x02DD 0x02DD
#define Scr_0x02DE 0x02DE
#define Scr_0x02DF 0x02DF
#define Scr_f03 0x02E0 // "f03", 2番街 (弍番街)
#define Scr_0x02E7 0x02E7
#define Scr_f04 0x02E8 // "f04", 8番街 (捌番街)
#define Scr_f05 0x02F5 // "f05", 12番街 (拾弍番街)
#define Scr_0x02FC 0x02FC
#define Scr_0x02FF 0x02FF
#define Scr_FourSealedDoor 0x0300              // 四方封印で閉ざされた扉のメッセージ
#define Scr_0x0301 0x0301
#define Scr_0x0302 0x0302
#define Scr_0x0303 0x0303
#define Scr_0x0304 0x0304
#define Scr_0x0305 0x0305
#define Scr_0x0306 0x0306
#define Scr_st00_00 0x0307  // 渓谷
#define Scr_0x030E 0x030E
#define Scr_0x0310 0x0310
#define Scr_0x0311 0x0311
#define Scr_0x0312 0x0312
#define Scr_GuideAttack 0x0313                 // ヒント看板「倒せ!!」, B ボタン攻撃の説明
#define Scr_0x0314 0x0314
#define Scr_PrologueSlideshow 0x0315           // ゲーム開始時のプロローグ文のスライドショーを進める
#define Scr_0x0316 0x0316
#define Scr_st00_01 0x0318 // 渓谷
#define Scr_GuideWallHug 0x031F                // ヒント看板「張りつけ!!」, 壁に張りつく移動
#define Scr_GuidePushBlock 0x0320              // ヒント看板「押せ!!」, 移動ブロック
#define Scr_0x0321 0x0321
#define Scr_0x0322 0x0322
#define Scr_0x0323 0x0323
#define Scr_0x0324 0x0324
#define Scr_0x0325 0x0325
#define Scr_0x0326 0x0326
#define Scr_0x0327 0x0327
#define Scr_st00_02 0x0329 // 渓谷
#define Scr_0x0330 0x0330
#define Scr_0x0335 0x0335
#define Scr_st00_03 0x0336 // 街門
#define Scr_0x033A 0x033A
#define Scr_0x033B 0x033B
#define Scr_GuideWeaponMenu 0x033F             // ヒント看板「己の武器を知れ。」, 武器の確認と装備
#define Scr_GuideSkylight 0x0340               // ヒント看板「天窓を探し出し〜」
#define Scr_GuideWallKnock 0x0341              // ヒント看板「叩け!!」, 壁叩きで敵を誘い出す
#define Scr_GuideStealth 0x0342                // ヒント看板「敵の後ろを取れ。」, 視界を避ける
#define Scr_GuideArmor 0x0343                  // ヒント看板「守れ!!」, 防具の装備
#define Scr_0x0344 0x0344
#define Scr_0x0346 0x0346
#define Scr_0x0347 0x0347
#define Scr_st00_04 0x0349 // 街門
#define Scr_0x034F 0x034F
#define Scr_0x0352 0x0352
#define Scr_0x0354 0x0354
#define Scr_CutsceneZajiGiveSolDeVice 0x0355   // ザジから太陽機「ソル・デ・バイス」を受け取るカットシーン, 前作の称号に合わせた台詞があり, 受け取る場面で背景を暗くする (BgPlttDimmer)
#define Scr_LichCurveShotStart 0x0358          // リッチの曲射弾の発射時処理, 部屋を明るくする
#define Scr_LichCurveShotEnd 0x0359            // リッチの曲射弾の爆発時処理, 部屋を暗く戻す
#define Scr_LichSummonSkeleton1 0x035A         // リッチのスケルトン召喚枠1, 呼ぶたびに種類を循環させて召喚する
#define Scr_LichSummonSkeleton2 0x035B         // リッチのスケルトン召喚枠2
#define Scr_LichSummonSkeleton3 0x035C         // リッチのスケルトン召喚枠3
#define Scr_TortureTimeUp 0x0363        // 暗黒ローンのおしおき(発電)の時間切れ処理
#define Scr_0x0364 0x0364
#define Scr_TortureEnd 0x0365           // 暗黒ローンのおしおき(発電)の終了処理, 返済状況に応じたメッセージと報酬アイテムの付与
#define Scr_Torture 0x0367          // 暗黒ローンのおしおきの進行, 発電部屋へ連行して操作説明をして発電を始める
#define Scr_DarkLoanElevatorCallback 0x036A    // おしおき部屋のエレベーターの到着時処理, p0: 1 なら到着しておしおき続行, 2 なら帰還
#define Scr_DarkLoanNotice 0x036B              // 返済期限を過ぎたときの暗黒ローンの暗子ちゃんからの督促シーン
#define Scr_0x036C 0x036C
#define Scr_0x036D 0x036D
#define Scr_0x036E 0x036E
#define Scr_0x036F 0x036F
#define Scr_st01_00_cathed 0x0370 // "st01_00_cathed", 大聖堂A [1F]
#define Scr_0x0376 0x0376
#define Scr_0x037A 0x037A
#define Scr_0x037B 0x037B
#define Scr_st01_01_cathed 0x037C // "st01_01_cathed", 大聖堂
#define Scr_0x0384 0x0384
#define Scr_GuideBreakCrate 0x0385             // ヒント看板「壊せ!!」, 木箱をハンマーで壊す
#define Scr_st01_02_cathed 0x0386 // "st01_02_cathed", 大聖堂
#define Scr_0x038C 0x038C
#define Scr_st01_03_cathed 0x038F // "st01_03_cathed", 大聖堂
#define Scr_0x0395 0x0395
#define Scr_0x0396 0x0396
#define Scr_0x0399 0x0399
#define Scr_0x039B 0x039B
#define Scr_GuideQuickChange 0x039C            // ヒント看板「クイックチェンジを使いこなせ」
#define Scr_0x039D 0x039D
#define Scr_0x039E 0x039E
#define Scr_0x039F 0x039F
#define Scr_0x03A0 0x03A0
#define Scr_0x03A1 0x03A1
#define Scr_st01_04_cathed 0x03A2 // "st01_04_cathed", 大聖堂
#define Scr_0x03AB 0x03AB
#define Scr_0x03AD 0x03AD
#define Scr_0x03AF 0x03AF
#define Scr_st01_05_cathed 0x03B0 // "st01_05_cathed", 大聖堂
#define Scr_0x03B6 0x03B6
#define Scr_0x03B7 0x03B7
#define Scr_0x03BA 0x03BA
#define Scr_0x03BC 0x03BC
#define Scr_0x03BD 0x03BD
#define Scr_GuideLightCandle 0x03BE            // ヒント看板「灯せ!!」, フレイムで燭台に火をつける
#define Scr_GuideWeightSwitch 0x03BF           // ヒント看板「載せろ!!」, 重量スイッチ
#define Scr_st01_06_cathed 0x03C0 // "st01_06_cathed", 大聖堂
#define Scr_0x03C8 0x03C8
#define Scr_0x03C9 0x03C9
#define Scr_0x03CA 0x03CA
#define Scr_0x03CB 0x03CB
#define Scr_0x03CC 0x03CC
#define Scr_0x03CD 0x03CD
#define Scr_0x03CE 0x03CE
#define Scr_0x03CF 0x03CF
#define Scr_0x03D0 0x03D0
#define Scr_0x03D1 0x03D1
#define Scr_GuideRustyLever 0x03D2             // ヒント看板「叩け!!」, 錆びたレバーはハンマーで
#define Scr_GuideTouchSwitch 0x03D3            // ヒント看板「たどり着け!!」, 接触スイッチ
#define Scr_0x03D4 0x03D4
#define Scr_st01_07_cathed 0x03D5 // "st01_07_cathed", 大聖堂
#define Scr_0x03D8 0x03D8
#define Scr_0x03E0 0x03E0
#define Scr_0x03E2 0x03E2
#define Scr_0x03E3 0x03E3
#define Scr_0x03E4 0x03E4
#define Scr_0x03E5 0x03E5
#define Scr_0x03E6 0x03E6
#define Scr_st01_08_cathed 0x03E7 // "st01_08_cathed", 大聖堂
#define Scr_0x03EF 0x03EF
#define Scr_0x03F0 0x03F0
#define Scr_0x03F1 0x03F1
#define Scr_0x03F2 0x03F2
#define Scr_0x03F3 0x03F3
#define Scr_0x03F4 0x03F4
#define Scr_st01_09_cathed 0x03F5 // "st01_09_cathed", 大聖堂
#define Scr_0x03FF 0x03FF
#define Scr_0x0400 0x0400
#define Scr_0x0401 0x0401
#define Scr_0x0402 0x0402
#define Scr_st01_10_cathed 0x0403 // "st01_10_cathed", 大聖堂
#define Scr_0x040B 0x040B
#define Scr_0x040C 0x040C
#define Scr_st01_11_cathed 0x040F // "st01_11_cathed", 大聖堂
#define Scr_0x0417 0x0417
#define Scr_0x0418 0x0418
#define Scr_0x0419 0x0419
#define Scr_0x041A 0x041A
#define Scr_0x041B 0x041B
#define Scr_0x041C 0x041C
#define Scr_st01_12_cathed 0x041D // "st01_12_cathed", 大聖堂
#define Scr_st01_13_cathed 0x0425 // "st01_13_cathed", 大聖堂
#define Scr_ReadBookshelf 0x042D               // 本棚の書名を表示する, p1: 本棚番号 (1〜10)
#define Scr_0x042E 0x042E
#define Scr_BookSwitchFound 0x042F             // 「本の奥にスイッチがある。」
#define Scr_BookSwitchPressed 0x0430           // 本の奥のスイッチは押したあと
#define Scr_0x0431 0x0431
#define Scr_0x0432 0x0432
#define Scr_BookSwitchPrompt 0x0434            // 本棚のスイッチを押すかの選択肢
#define Scr_st01_14_cathed 0x0435 // "st01_14_cathed", 大聖堂
#define Scr_0x043F 0x043F
#define Scr_0x0440 0x0440
#define Scr_0x0443 0x0443
#define Scr_0x0445 0x0445
#define Scr_0x0446 0x0446
#define Scr_0x0450 0x0450
#define Scr_st01_15_cathed 0x0451 // "st01_15_cathed", 大聖堂
#define Scr_0x0454 0x0454
#define Scr_0x0459 0x0459
#define Scr_0x045A 0x045A
#define Scr_0x045C 0x045C
#define Scr_0x045D 0x045D
#define Scr_0x045E 0x045E
#define Scr_0x045F 0x045F
#define Scr_0x0460 0x0460
#define Scr_st01_16_cathed 0x0462 // "st01_16_cathed", 大聖堂
#define Scr_0x0469 0x0469
#define Scr_0x046A 0x046A
#define Scr_st01_17_cathed 0x046B // "st01_17_cathed", 大聖堂
#define Scr_0x0471 0x0471
#define Scr_0x0472 0x0472
#define Scr_0x0473 0x0473
#define Scr_0x0474 0x0474
#define Scr_0x0476 0x0476
#define Scr_0x0477 0x0477
#define Scr_0x0478 0x0478
#define Scr_0x0479 0x0479
#define Scr_0x047B 0x047B
#define Scr_st01_18_cathed 0x047C // "st01_18_cathed", 大聖堂
#define Scr_st01_wedge 0x0483  // "wedge", 大聖堂の封印の楔の部屋
#define Scr_0x048A 0x048A
#define Scr_st02_00_desert 0x048B // "st02_00_desert", 遺跡
#define Scr_0x0492 0x0492
#define Scr_0x0496 0x0496
#define Scr_0x0498 0x0498
#define Scr_0x0499 0x0499
#define Scr_0x049A 0x049A
#define Scr_st02_01_desert 0x049B // "st02_01_desert", 遺跡
#define Scr_0x04A1 0x04A1
#define Scr_st02_02_desert 0x04A3 // "st02_02_desert", 遺跡
#define Scr_0x04A9 0x04A9
#define Scr_st02_03_desert 0x04AB // "st02_03_desert", 遺跡
#define Scr_0x04B2 0x04B2
#define Scr_0x04B3 0x04B3
#define Scr_st02_04_desert_a 0x04B5 // "st02_04_desert", 遺跡 (その1), その2は Scr_st02_04_desert_b
#define Scr_0x04BB 0x04BB
#define Scr_0x04BD 0x04BD
#define Scr_GuideBreakRock 0x04BE              // ヒント看板「砕け!!」, クラウドで岩を砕く
#define Scr_st02_05_desert 0x04BF // "st02_05_desert", 遺跡
#define Scr_GuideElementCube 0x04C6            // ヒント看板「属性を使いこなせ。」, 属性キューブ
#define Scr_GuideMeltIce 0x04C7                // ヒント看板「溶かせ!!」, フレイムで氷を溶かす
#define Scr_GuideExtinguish 0x04C8             // ヒント看板「消せ!!」, フロストで炎を消す
#define Scr_st02_06_desert 0x04C9 // "st02_06_desert", 遺跡
#define Scr_0x04CF 0x04CF
#define Scr_0x04D0 0x04D0
#define Scr_st02_07_desert 0x04D3 // "st02_07_desert", 遺跡
#define Scr_0x04DC 0x04DC
#define Scr_0x04DD 0x04DD
#define Scr_0x04DE 0x04DE
#define Scr_st02_08_desert 0x04DF // "st02_08_desert", 遺跡
#define Scr_st02_09_desert 0x04E6 // "st02_09_desert", 遺跡
#define Scr_0x04ED 0x04ED
#define Scr_0x04EE 0x04EE
#define Scr_0x04EF 0x04EF
#define Scr_0x04F0 0x04F0
#define Scr_0x04F1 0x04F1
#define Scr_GuideCrestSwitch 0x04F2            // ヒント看板「合わせろ!!」, 紋章スイッチ
#define Scr_GuideMoveCube 0x04F3               // ヒント看板「突け!!」, 属性キューブを空中で動かす
#define Scr_st02_10_desert 0x04F4 // "st02_10_desert", 遺跡
#define Scr_st02_11_desert 0x04FB // "st02_11_desert", 遺跡
#define Scr_0x0502 0x0502
#define Scr_0x0503 0x0503
#define Scr_0x0504 0x0504
#define Scr_0x0505 0x0505
#define Scr_st02_12_desert 0x0506 // "st02_12_desert", 遺跡
#define Scr_0x050D 0x050D
#define Scr_st02_13_desert 0x050E // "st02_13_desert", 遺跡
#define Scr_0x0514 0x0514
#define Scr_0x0515 0x0515
#define Scr_0x0517 0x0517
#define Scr_0x0518 0x0518
#define Scr_st02_14_desert 0x0519 // "st02_14_desert", 遺跡
#define Scr_0x051F 0x051F
#define Scr_StartCutsceneLearnDynamite 0x0521
#define Scr_CutsceneLearnDynamite 0x0522
#define Scr_st02_04_desert_b 0x0523 // "st02_04_desert", 遺跡 (その2), その1は Scr_st02_04_desert_a
#define Scr_st02_15_desert 0x0524 // "st02_15_desert", 遺跡
#define Scr_0x052E 0x052E
#define Scr_0x0534 0x0534
#define Scr_st02_16_desert 0x0537 // "st02_16_desert", 砂漠 (石版はめる前と後両方)
#define Scr_DesertSlotExamine 0x053E           // 砂漠の四角いくぼみを調べたときのメッセージ
#define Scr_0x053F 0x053F
#define Scr_DesertSlotPrompt 0x0540            // 石版のかけらをはめ込むかの選択肢
#define Scr_DesertSlotAnswer 0x0541            // はめ込むかの選択の結果, かけらを消費して3つで石版が完成する, p0: 選択
#define Scr_0x0542 0x0542
#define Scr_DesertInscriptionPrompt 0x0544     // くぼみの下の文字を読むかの選択肢
#define Scr_DesertInscriptionAnswer 0x0545     // 碑文を読むかの選択の結果, p0: 選択
#define Scr_0x0546 0x0546
#define Scr_DesertFragmentHint 0x0548          // 石版のかけらの隠し場所のヒントを表示する, p0: 隠し場所の番号
#define Scr_0x0549 0x0549
#define Scr_st02_17_desert 0x054A // "st02_17_desert", 遺跡
#define Scr_0x0551 0x0551
#define Scr_KingsCandleIntro 0x0552            // 4人の兄弟王の燭台パズルの説明
#define Scr_KingsCandleFire 0x0553             // 火の王の燭台の言葉
#define Scr_KingsCandleWater 0x0554            // 水の王の燭台の言葉
#define Scr_KingsCandleEarth 0x0555            // 大地の王の燭台の言葉
#define Scr_KingsCandleWind 0x0556             // 風の王の燭台の言葉
#define Scr_KingsCandleMemo 0x0557             // 燭台パズルの「残されたメッセージ」, scratch + 0x14B で文面を選ぶ
#define Scr_0x0558 0x0558
#define Scr_0x055A 0x055A
#define Scr_st02_18_desert 0x055B // "st02_18_desert", 遺跡
#define Scr_st02_19_desert 0x0567 // "st02_19_desert", 遺跡
#define Scr_SignTrialFire 0x056E               // 「火の試練」の看板
#define Scr_SignTrialWater 0x056F              // 「水の試練」の看板
#define Scr_SignTrialEarth 0x0570              // 「地の試練」の看板
#define Scr_SignTrialWind 0x0571               // 「風の試練」の看板
#define Scr_0x0573 0x0573
#define Scr_0x0574 0x0574
#define Scr_0x0575 0x0575
#define Scr_0x0576 0x0576
#define Scr_0x0577 0x0577
#define Scr_0x0579 0x0579
#define Scr_0x057A 0x057A
#define Scr_0x057B 0x057B
#define Scr_st02_20_desert 0x057C // "st02_20_desert", "遺跡B [B3]", ボス部屋前+ボス部屋
#define Scr_0x0585 0x0585
#define Scr_0x0586 0x0586
#define Scr_0x0589 0x0589
#define Scr_0x058A 0x058A
#define Scr_0x058B 0x058B
#define Scr_st02_21 0x058C // "st02_21", "遺跡B [B3]", 楔
#define Scr_0x0593 0x0593
#define Scr_st03_00_slum 0x0594 // "st03_00_slum", 暗黒街
#define Scr_SetDarkCityBgm 0x0596              // 暗黒街 (ステージ3) の BGM をストーリー進行度で選んで設定する, p0: 1/2 なら固定の曲
#define Scr_0x059C 0x059C
#define Scr_st03_01_slum 0x059D // "st03_01_slum", 暗黒街
#define Scr_0x05A4 0x05A4
#define Scr_0x05A5 0x05A5
#define Scr_0x05A6 0x05A6
#define Scr_st03_02_slum 0x05A7 // "st03_02_slum", 暗黒街
#define Scr_SignBewareDog 0x05AE               // 「猛犬注意!!」の看板
#define Scr_st03_03_slum 0x05AF // "st03_03_slum", 暗黒街
#define Scr_0x05B5 0x05B5
#define Scr_0x05B6 0x05B6
#define Scr_SignBewareOverhead 0x05B8          // 「頭上注意!!」の看板
#define Scr_st03_04_slum 0x05BA // "st03_04_slum", 暗黒街
#define Scr_st03_05_slum 0x05C1 // "st03_05_slum", 暗黒街
#define Scr_st03_06_slum 0x05C8 // "st03_06_slum", 暗黒街
#define Scr_st03_07_slum 0x05CF // "st03_07_slum", 暗黒街
#define Scr_st03_08_slum 0x05D6 // "st03_08_slum", 暗黒街
#define Scr_st03_09_slum 0x05DD // "st03_09_slum", 暗黒街
#define Scr_0x05E4 0x05E4
#define Scr_SignBewareFeet 0x05E5              // 「足元注意!!」の看板
#define Scr_0x05E7 0x05E7
#define Scr_0x05E8 0x05E8
#define Scr_0x05E9 0x05E9
#define Scr_st03_10_slum 0x05EA // "st03_10_slum", 暗黒街
#define Scr_0x05F1 0x05F1
#define Scr_0x05F2 0x05F2
#define Scr_st03_11_slum 0x05F3 // "st03_11_slum", 暗黒街
#define Scr_0x05FA 0x05FA
#define Scr_0x05FB 0x05FB
#define Scr_0x05FC 0x05FC
#define Scr_0x05FE 0x05FE
#define Scr_st03_12_slum 0x05FF // "st03_12_slum", 暗黒街
#define Scr_GuideWeightLift 0x0606             // ヒント看板「重量をコントロールせよ。」, 重量昇降床
#define Scr_0x0607 0x0607
#define Scr_st03_13_slum 0x0608 // "st03_13_slum", 暗黒街
#define Scr_SignBewareDark 0x060F              // 「暗闇注意!!」の看板
#define Scr_st03_14_slum 0x0610 // "st03_14_slum", 暗黒街
#define Scr_st03_15_slum 0x0617 // "st03_15_slum", 暗黒街
#define Scr_0x061D 0x061D
#define Scr_0x061E 0x061E
#define Scr_st03_16_slum 0x0621 // "st03_16_slum", 暗黒街
#define Scr_0x0628 0x0628
#define Scr_st03_17_slum 0x0629 // "st03_17_slum", 暗黒街
#define Scr_st03_18_slum 0x0630 // "st03_18_slum", 暗黒街
#define Scr_st03_19_slum 0x0637 // "st03_19_slum", 暗黒街
#define Scr_0x063E 0x063E
#define Scr_0x0640 0x0640
#define Scr_st03_20_slum 0x0641 // "st03_20_slum", 暗黒街
#define Scr_st03_21_slum 0x0648 // "st03_21_slum", 暗黒街
#define Scr_0x064F 0x064F
#define Scr_st03_22_slum 0x0650 // "st03_22_slum", 暗黒街
#define Scr_LockMagicInCrawlway 0x0652         // 小さい通路のマップ (st03_22_slum_hpk) に入ったら魔法をロックする, 出入口も置く
#define Scr_st03_23_slum 0x0657 // "st03_23_slum", 暗黒街
#define Scr_st03_24_slum 0x065E // "st03_24_slum", "暗黒街B [4F]"
#define Scr_SetMagicLockZones 0x0665           // 暗黒街B [4F] の小さい通路のゾーンに入ったら魔法をロックし, 出たら解除する
#define Scr_st03_25_slum 0x0667 // "st03_25_slum", 暗黒街
#define Scr_st03_26_slum_a 0x066E // "st03_26_slum", 暗黒街 (その1), その2は Scr_st03_26_slum_b
#define Scr_0x0675 0x0675
#define Scr_0x0679 0x0679
#define Scr_st03_27_slum 0x067A // "st03_27_slum", 暗黒街
#define Scr_0x0681 0x0681
#define Scr_0x0682 0x0682
#define Scr_0x0685 0x0685
#define Scr_0x0686 0x0686
#define Scr_0x0687 0x0687
#define Scr_0x0688 0x0688
#define Scr_st03_28_slum 0x0689 // "st03_28_slum", 暗黒街
#define Scr_GuideSunBarrier 0x0690             // ヒント看板「太陽結界について。」
#define Scr_0x0691 0x0691
#define Scr_0x0692 0x0692
#define Scr_0x0693 0x0693
#define Scr_0x0694 0x0694
#define Scr_st03_29_slum 0x0696 // "st03_29_slum", 暗黒街
#define Scr_st03_30_slum 0x069D // "st03_30_slum", 暗黒街
#define Scr_0x06A4 0x06A4
#define Scr_st03_wedge 0x06A5  // "wedge", 暗黒街の封印の楔の部屋
#define Scr_st03_24_slum_shaian 0x06AC // "st03_24_slum", "暗黒街B [4F]" (シャイアン戦)
#define Scr_0x06B2 0x06B2
#define Scr_0x06B5 0x06B5
#define Scr_0x06B6 0x06B6
#define Scr_0x06B8 0x06B8
#define Scr_0x06B9 0x06B9
#define Scr_0x06BA 0x06BA
#define Scr_0x06BC 0x06BC
#define Scr_0x06BE 0x06BE
#define Scr_0x06BF 0x06BF
#define Scr_0x06C0 0x06C0
#define Scr_st03_26_slum_b 0x06C1 // "st03_26_slum", 暗黒街 (その2), その1は Scr_st03_26_slum_a
#define Scr_0x06C7 0x06C7
#define Scr_0x06C9 0x06C9
#define Scr_0x06CA 0x06CA
#define Scr_0x06CB 0x06CB
#define Scr_0x06CE 0x06CE
#define Scr_0x06CF 0x06CF
#define Scr_0x06D0 0x06D0
#define Scr_0x06D1 0x06D1
#define Scr_0x06D2 0x06D2
#define Scr_st04_00_lake_a 0x06D3 // "st04_00_lake", 地下水路 (その1), 他は Scr_st04_00_lake_b, Scr_st04_00_lake_c
#define Scr_TarotSealedDoor 0x06DA             // タロット封印の扉, 3賢者のカードがそろっていれば開封カットシーン, なければメッセージ
#define Scr_0x06DD 0x06DD
#define Scr_TalkRingoTarotDoor 0x06E2          // タロット封印の前のリンゴの会話, 残りのカードの枚数で変わる
#define Scr_0x06E6 0x06E6
#define Scr_0x06E7 0x06E7
#define Scr_st04_00_lake_b 0x06E8 // "st04_00_lake", 地下水路 (その2), 他は Scr_st04_00_lake_a, Scr_st04_00_lake_c
#define Scr_0x06EF 0x06EF
#define Scr_0x06F0 0x06F0
#define Scr_st04_00_lake_c 0x06F1 // "st04_00_lake", 地下水路 (その3), 他は Scr_st04_00_lake_a, Scr_st04_00_lake_b
#define Scr_0x06F8 0x06F8
#define Scr_st04_01_lake 0x06F9 // "st04_01_lake", 地下水路
#define Scr_0x0700 0x0700
#define Scr_0x0701 0x0701
#define Scr_st04_02_lake_a 0x0702 // "st04_02_lake", 地下水路 (その1), 他は Scr_st04_02_lake_b
#define Scr_st04_03_lake 0x070B // "st04_03_lake", 地下水路
#define Scr_st04_04_lake_a 0x0716 // "st04_04_lake", 地下水路 (その1), 他は Scr_st04_04_lake_b, Scr_st04_04_lake_c
#define Scr_st04_04_lake_b 0x071D // "st04_04_lake", 地下水路 (その2), 他は Scr_st04_04_lake_a, Scr_st04_04_lake_c
#define Scr_st04_04_lake_c 0x0724 // "st04_04_lake", 地下水路 (その3), 他は Scr_st04_04_lake_a, Scr_st04_04_lake_b
#define Scr_st04_wedge 0x072B  // "wedge", 地下水路の封印の楔の部屋
#define Scr_st04_02_lake_b 0x0732 // "st04_02_lake", 地下水路 (その2), 他は Scr_st04_02_lake_a
#define Scr_0x0737 0x0737
#define Scr_0x0738 0x0738
#define Scr_0x0739 0x0739
#define Scr_0x073B 0x073B
#define Scr_st05_00_tower 0x073C // "st05_00_tower", 約束の丘
#define Scr_0x073F 0x073F
#define Scr_0x0741 0x0741
#define Scr_0x0749 0x0749
#define Scr_0x074B 0x074B
#define Scr_0x074D 0x074D
#define Scr_0x074E 0x074E
#define Scr_0x074F 0x074F
#define Scr_0x0750 0x0750
#define Scr_0x0751 0x0751
#define Scr_0x0752 0x0752
#define Scr_0x0754 0x0754
#define Scr_0x0756 0x0756
#define Scr_0x0757 0x0757
#define Scr_0x0758 0x0758
#define Scr_0x075A 0x075A
#define Scr_0x075B 0x075B
#define Scr_0x075C 0x075C
#define Scr_0x075E 0x075E
#define Scr_SabataGiveJokerCrest 0x0760        // サバタからジョーカーの紋章をもらうイベント
#define Scr_0x0761 0x0761
#define Scr_0x0764 0x0764
#define Scr_0x0765 0x0765
#define Scr_st05_01_tower 0x0766 // "st05_01_tower", 螺旋の塔
#define Scr_0x076B 0x076B
#define Scr_0x0770 0x0770
#define Scr_0x0771 0x0771
#define Scr_GuideZeroShift 0x0772              // 月光魔法ゼロシフトの説明看板
#define Scr_GuideBlackSun 0x0773               // 月光魔法ブラックサンの説明看板
#define Scr_0x0774 0x0774
#define Scr_st05_02_tower 0x0776 // "st05_02_tower", 螺旋の塔
#define Scr_0x077D 0x077D
#define Scr_0x077F 0x077F
#define Scr_0x0781 0x0781
#define Scr_0x0782 0x0782
#define Scr_0x0783 0x0783
#define Scr_0x0784 0x0784
#define Scr_st05_03_tower 0x0785 // "st05_03_tower", 螺旋の塔
#define Scr_st05_04_tower 0x078D // "st05_04_tower", 螺旋の塔
#define Scr_st05_05_tower 0x0794 // "st05_05_tower", 螺旋の塔
#define Scr_st05_06_tower 0x079B // "st05_06_tower", 螺旋の塔
#define Scr_0x07A2 0x07A2
#define Scr_0x07A3 0x07A3
#define Scr_0x07A4 0x07A4
#define Scr_0x07A5 0x07A5
#define Scr_st05_07_tower 0x07A6 // "st05_07_tower", 螺旋の塔
#define Scr_st05_08_tower 0x07AD // "st05_08_tower", 螺旋の塔
#define Scr_CreateLockedPlayer 0x07B5  // 操作できない状態のプレイヤーキャラを作る, p0: ID, p1: '.k', p2〜p4: 位置, p5: 向き
#define Scr_0x07B6 0x07B6
#define Scr_0x07B7 0x07B7
#define Scr_st05_09_tower 0x07B9 // "st05_09_tower", 螺旋の塔
#define Scr_0x07BF 0x07BF
#define Scr_0x07C1 0x07C1
#define Scr_0x07C2 0x07C2
#define Scr_st05_10_tower 0x07C3 // "st05_10_tower", 螺旋の塔
#define Scr_0x07CA 0x07CA
#define Scr_0x07CB 0x07CB
#define Scr_0x07CC 0x07CC
#define Scr_st05_11_tower 0x07CE // "st05_11_tower", 螺旋の塔
#define Scr_st05_12_tower 0x07D6 // "st05_12_tower", 螺旋の塔
#define Scr_st05_13_tower 0x07DD // "st05_13_tower", 螺旋の塔
#define Scr_0x07E5 0x07E5
#define Scr_0x07E6 0x07E6
#define Scr_st05_14_tower 0x07E7 // "st05_14_tower", 螺旋の塔
#define Scr_0x07EE 0x07EE
#define Scr_0x07EF 0x07EF
#define Scr_0x07F1 0x07F1
#define Scr_0x07F2 0x07F2
#define Scr_st05_15_tower 0x07F5 // "st05_15_tower", 螺旋の塔
#define Scr_0x07FC 0x07FC
#define Scr_0x07FD 0x07FD
#define Scr_0x07FE 0x07FE
#define Scr_st05_16_tower 0x0801 // "st05_16_tower", 螺旋の塔
#define Scr_0x0807 0x0807
#define Scr_0x0809 0x0809
#define Scr_0x080A 0x080A
#define Scr_0x080B 0x080B
#define Scr_st05_17_tower 0x080C // "st05_17_tower", 螺旋の塔
#define Scr_st05_18_tower 0x0815 // "st05_18_tower", 螺旋の塔
#define Scr_0x081D 0x081D
#define Scr_0x081E 0x081E
#define Scr_0x081F 0x081F
#define Scr_0x0820 0x0820
#define Scr_st05_19_tower 0x0822 // "st05_19_tower", 螺旋の塔
#define Scr_0x082A 0x082A
#define Scr_0x082E 0x082E
#define Scr_0x082F 0x082F
#define Scr_st05_20_tower 0x0832 // "st05_20_tower", 螺旋の塔
#define Scr_0x0835 0x0835
#define Scr_0x0839 0x0839
#define Scr_st05_21_tower 0x083D // "st05_21_tower", 螺旋の塔
#define Scr_0x0844 0x0844
#define Scr_0x0845 0x0845
#define Scr_0x0846 0x0846
#define Scr_0x0847 0x0847
#define Scr_0x0848 0x0848
#define Scr_st05_22_tower 0x0849 // "st05_22_tower", 螺旋の塔
#define Scr_0x0850 0x0850
#define Scr_0x0851 0x0851
#define Scr_0x0852 0x0852
#define Scr_0x0857 0x0857
#define Scr_0x0858 0x0858
#define Scr_st05_23_tower 0x0859 // "st05_23_tower", 螺旋の塔
#define Scr_0x0860 0x0860
#define Scr_0x0861 0x0861
#define Scr_0x0862 0x0862
#define Scr_st05_24_tower 0x0863 // "st05_24_tower", 螺旋の塔
#define Scr_0x0866 0x0866
#define Scr_0x0867 0x0867
#define Scr_0x0868 0x0868
#define Scr_0x0869 0x0869
#define Scr_0x086F 0x086F
#define Scr_0x0870 0x0870
#define Scr_0x0871 0x0871
#define Scr_0x0872 0x0872
#define Scr_0x0873 0x0873
#define Scr_0x0874 0x0874
#define Scr_SpawnShadeMan 0x0877  // 螺旋の塔 (st05_24_tower) で, クロスオーバー進行度 7〜9 かつ入口 3 のときシェードマンを出す
#define Scr_OnShadeManLowHP 0x0878  // シェードマンの HP が .b[0] 以下になって移る状態の入りで呼ばれる (.b[1]), プレイヤーを止める
#define Scr_ShadeManLowHPMessage 0x0879  // HP が減った状態の後半で呼ばれる (.b[2]), 「キ、キキ・・・キサマ!!」とペットのヒントを出す
#define Scr_OnShadeManDefeated 0x087A  // シェードマンを倒したとき (.c[0]), 経験値 3000 を足してプレイヤーを止める
#define Scr_0x087B 0x087B
#define Scr_st05_25_tower 0x087E // "st05_25_tower", 螺旋の塔
#define Scr_0x0886 0x0886
#define Scr_st05_26_tower 0x0887 // "st05_26_tower", 螺旋の塔
#define Scr_st06_enter 0x088E // "st06_enter", "変異域 [1F]"
#define Scr_st06_earth_00 0x0895 // "st06_earth_00", "変異域 [B1]"
#define Scr_st06_earth_01 0x089C // "st06_earth_01", "変異域 [B1]"
#define Scr_0x08A4 0x08A4
#define Scr_0x08A5 0x08A5
#define Scr_0x08A6 0x08A6
#define Scr_0x08AA 0x08AA
#define Scr_st06_earth_02 0x08AB // "st06_earth_02", "変異域 [B1]"
#define Scr_0x08B2 0x08B2
#define Scr_0x08B3 0x08B3
#define Scr_st06_earth_03 0x08B4 // "st06_earth_03", "変異域 [B1]"
#define Scr_0x08BB 0x08BB
#define Scr_st06_earth_04 0x08BC // "st06_earth_04", "変異域 [B1]"
#define Scr_0x08C3 0x08C3
#define Scr_0x08C4 0x08C4
#define Scr_st06_earth_05 0x08C5 // "st06_earth_05", "変異域 [B1]", ボス部屋(サンドウォーム)
#define Scr_SpawnEarthSandworm 0x08CA  // 変異域 B1 のサンドウォームをまだ倒していなければ出す
#define Scr_OnEarthSandwormDefeated 0x08CC  // 変異域 B1 のサンドウォームを倒したとき, 閉じ込め戦闘を数え, 全部倒せばエレベーターを動かし W_EARTH_SANDWORM_DEFEATED を立てて宝箱を置く
#define Scr_0x08CD 0x08CD
#define Scr_st06_cloud_00 0x08CF // "st06_cloud_00", "変異域 [B2]"
#define Scr_st06_cloud_01 0x08D6 // "st06_cloud_01", "変異域 [B2]"
#define Scr_0x08DD 0x08DD
#define Scr_st06_cloud_02 0x08DF // "st06_cloud_02", "変異域 [B2]"
#define Scr_0x08E6 0x08E6
#define Scr_st06_cloud_03 0x08E7 // "st06_cloud_03", "変異域 [B2]"
#define Scr_0x08EE 0x08EE
#define Scr_0x08EF 0x08EF
#define Scr_st06_cloud_04 0x08F0 // "st06_cloud_04", "変異域 [B2]"
#define Scr_st06_cloud_05 0x08F7 // "st06_cloud_05", "変異域 [B2]", ボス部屋(リッチ)
#define Scr_0x08FD 0x08FD
#define Scr_0x08FF 0x08FF
#define Scr_0x0900 0x0900
#define Scr_st06_frost_00 0x0901 // "st06_frost_00", "変異域 [B3]"
#define Scr_st06_frost_01 0x090A // "st06_frost_01", "変異域 [B3]"
#define Scr_0x0911 0x0911
#define Scr_0x0912 0x0912
#define Scr_st06_frost_02 0x0915 // "st06_frost_02", "変異域 [B3]"
#define Scr_0x091C 0x091C
#define Scr_0x091D 0x091D
#define Scr_0x091E 0x091E
#define Scr_st06_frost_03 0x091F // "st06_frost_03", "変異域 [B3]"
#define Scr_st06_frost_04 0x0926 // "st06_frost_04", "変異域 [B3]"
#define Scr_0x092D 0x092D
#define Scr_0x092E 0x092E
#define Scr_0x092F 0x092F
#define Scr_st06_frost_05 0x0930 // "st06_frost_05", "変異域 [B3]", ボス部屋(サーペント)
#define Scr_SpawnFrostSerpent 0x0935  // 変異域 B3 のサーペントをまだ倒していなければ出す
#define Scr_OnFrostSerpentDefeated 0x0936  // 変異域 B3 のサーペントを倒したとき, 閉じ込め戦闘を数え, 全部倒せば W_FROST_SERPENT_DEFEATED を立てて宝箱を置く
#define Scr_0x0938 0x0938
#define Scr_0x0939 0x0939
#define Scr_st06_flame_00 0x093A // "st06_flame_00", "変異域 [B4]"
#define Scr_0x0941 0x0941
#define Scr_st06_flame_01 0x0945 // "st06_flame_01", "変異域 [B4]"
#define Scr_0x094C 0x094C
#define Scr_st06_flame_02 0x094E // "st06_flame_02", "変異域 [B4]"
#define Scr_0x0955 0x0955
#define Scr_st06_flame_03 0x0956 // "st06_flame_03", "変異域 [B4]"
#define Scr_0x095D 0x095D
#define Scr_0x095E 0x095E
#define Scr_0x095F 0x095F
#define Scr_st06_flame_04 0x0960 // "st06_flame_04", "変異域 [B4]"
#define Scr_st06_flame_05 0x0967 // "st06_flame_05", "変異域 [B4]", ボス部屋(リッチ+)
#define Scr_0x096D 0x096D
#define Scr_SpawnSalamander 0x096E  // サラマンダーを (p0, p1, p2) に出す, リッチ+ の召喚スクリプト (Skeleton_Create の '.s') として渡される
#define Scr_OnSalamanderDefeated 0x096F  // Scr_SpawnSalamander で出したサラマンダーの撃破時スクリプト, Scr_0x0971 でオートスクロールに指示を送り直す
#define Scr_0x0973 0x0973
#define Scr_st06_last_00 0x0974 // "st06_last_00", "変異域 [?]"
#define Scr_0x097C 0x097C
#define Scr_0x097D 0x097D
#define Scr_st06_last_01 0x097E // "st06_last_01", "変異域 [?]"
#define Scr_st06_last_02 0x0988 // "st06_last_02", "変異域 [?]"
#define Scr_st06_last_03 0x098F // "st06_last_03", "変異域 [?]"
#define Scr_st06_last_04 0x0996 // "st06_last_04", "変異域 [?]"
#define Scr_st06_last_05 0x099D // "st06_last_05", "変異域 [?]"
#define Scr_st06_last_06 0x09A4 // "st06_last_06", "変異域 [?]"
#define Scr_st06_last_07 0x09AC // "st06_last_07", "変異域 [?]", ボス部屋(ヨルムンガンド)
#define Scr_0x09AF 0x09AF
#define Scr_0x09B3 0x09B3
#define Scr_0x09B4 0x09B4
#define Scr_b00_00_town 0x09B6 // "b00_00_town", サンミゲル (屋外)
#define Scr_SignShopClosed 0x09C0              // 「閉店中のようだ・・・」
#define Scr_SignLibraryClosed 0x09C1           // 「閉館中のようだ・・・」
#define Scr_0x09C2 0x09C2
#define Scr_SpawnOtenko 0x09C5                 // プレイヤーの向きの1マス先におてんこを置く
#define Scr_0x09C6 0x09C6
#define Scr_TalkZaji 0x09CA                    // ザジの会話の入口 (宿屋の太陽ダケ, 星読み, 体調を気にして薬をくれる, 雑談)
#define Scr_ZajiStarReadingIntro 0x09CB        // ザジの星読みの前置き
#define Scr_SetPrefectureName 0x09CC           // 登録した都道府県の名前をメッセージの変数に入れる
#define Scr_0x09CD 0x09CD
#define Scr_0x09CE 0x09CE
#define Scr_ZajiReadBirthplace 0x09CF          // 星読みで出身地を当てる, 前作との連動があればランクの星読みへ
#define Scr_ZajiReadBoktai1Rank 0x09D0         // 星読みで前作 (イストラカン) のランクを当てる
#define Scr_ZajiStarReadingBoast 0x09D1        // 「図星やろ?」
#define Scr_ZajiStarReadingPrompt 0x09D2       // 星読みの感想の選択肢 (恐ろしい/すごい)
#define Scr_ZajiStarReadingAnswer 0x09D3       // 感想の選択で好感度が上下する, p0: 選択
#define Scr_0x09D4 0x09D4
#define Scr_0x09D5 0x09D5
#define Scr_ZajiGiftCurseCure 0x09D6           // 呪われているのを見て秘薬をくれる
#define Scr_ZajiGiftLifeItem 0x09D7            // ライフを心配して回復アイテムをくれる
#define Scr_ZajiGiftEnergyItem 0x09D8          // エナジーを心配して回復アイテムをくれる
#define Scr_ZajiSmallTalk 0x09D9               // ザジの雑談2種類を交互に
#define Scr_0x09DA 0x09DA
#define Scr_0x09DC 0x09DC
#define Scr_TalkSmithInjured 0x09DE            // 負傷中のスミスの会話, 進行度が26を超えていればイベントへ
#define Scr_TalkSumire 0x09E2                  // 太陽街 (0x09C4) のスミレの会話の入口
#define Scr_TalkKuroOutside 0x09E6             // 屋外のクロとの会話
#define Scr_TalkKuroBandagedOutside 0x09E7     // 屋外の包帯を巻いたクロとの会話
#define Scr_0x09E9 0x09E9
#define Scr_0x09EB 0x09EB
#define Scr_0x09EF 0x09EF
#define Scr_SpawnTimedResidents 0x09F2         // 時間帯で出入りする住人(ルイス, マルチェロ, ハテナ)を日の出・日の入り時刻と雨・棺桶の状態に応じて屋外に置く
#define Scr_TalkLuis 0x09F3                    // ルイスの会話の入口
#define Scr_LuisSmallTalk 0x09F4               // ルイスの雑談
#define Scr_LuisSmallTalkEndgame 0x09F5        // 終盤 (1周目の進行度62以降) のルイスの雑談
#define Scr_TalkMarcello 0x09F6                // マルチェロの会話の入口
#define Scr_MarcelloSmallTalk 0x09F7           // マルチェロの雑談
#define Scr_MarcelloSmallTalkEndgame 0x09F8    // 終盤のマルチェロの雑談
#define Scr_0x09FA 0x09FA
#define Scr_0x09FB 0x09FB
#define Scr_b00_01_town 0x09FC // "b00_01_town", サンミゲル (ショップ, 倉庫)
#define Scr_0x09FD 0x09FD
#define Scr_SpawnSumire 0x0A04                 // 進行度と時間帯に応じて家の中にスミレを置く
#define Scr_0x0A05 0x0A05
#define Scr_0x0A06 0x0A06
#define Scr_0x0A08 0x0A08
#define Scr_0x0A09 0x0A09
#define Scr_0x0A0A 0x0A0A
#define Scr_0x0A0B 0x0A0B
#define Scr_PickCrossoverArmor 0x0A0C          // クロスオーバーポイントと交換で渡す防具を進行度別の候補から1つ選んで返す, 未入手のものを優先する
#define Scr_0x0A0F 0x0A0F
#define Scr_0x0A10 0x0A10
#define Scr_CrossoverArmorChoice 0x0A11        // 防具交換の「はい/いいえ」の処理, p0: 選んだ項目 (0 ならバッグに空きがあれば渡す)
#define Scr_CrossoverArmorExchange 0x0A12      // クロスオーバーポイント 60 で防具を1つもらい, 残りのポイントを表示する
#define Scr_TalkKuroHouse 0x0A14               // 家の中のクロとの会話, 周回時はブラックパンサーの選択肢つき
#define Scr_TalkKuroBandagedHouse 0x0A15       // 家の中の包帯を巻いたクロとの会話
#define Scr_0x0A16 0x0A16
#define Scr_0x0A17 0x0A17
#define Scr_0x0A18 0x0A18
#define Scr_KuroBlackPantherReturn 0x0A19      // クロ経由のブラックパンサーから戻ったときの処理, 遊んだフラグを立てて得点に応じた宝箱を出す
#define Scr_0x0A1B 0x0A1B
#define Scr_0x0A25 0x0A25
#define Scr_TalkShaianFromStart 0x0A26         // シャイアンとの会話を最初から始める
#define Scr_TalkShaian 0x0A27                  // 武器屋シャイアンの会話の入口
#define Scr_ShaianDashIntro 0x0A28             // 「渡しておきたいものがある」, ダッシュ伝授の前置き
#define Scr_0x0A29 0x0A29
#define Scr_ShaianWindBlessing 0x0A2A          // 「風の祝福を得た!」
#define Scr_LearnDash 0x0A2B                   // 太陽魔法ダッシュを覚えたメッセージ
#define Scr_0x0A2C 0x0A2C
#define Scr_0x0A2D 0x0A2D
#define Scr_ShaianDashGiven 0x0A2E             // ダッシュを解放し, 進行度に応じてくさびの話をする
#define Scr_ShaianMenuPrompt 0x0A2F            // 買い物/話/通信販売の選択肢
#define Scr_ShaianMenuAnswer 0x0A30            // メニューの選択の結果, 通信販売は初回だけ説明する, p0: 選択
#define Scr_0x0A32 0x0A32
#define Scr_0x0A33 0x0A33
#define Scr_ShaianAfterShop 0x0A34             // 買い物のあとのシャイアンの一言
#define Scr_ShaianHintTalk 0x0A35              // シャイアンの「話」, 進行度ごとのヒント
#define Scr_0x0A36 0x0A36
#define Scr_ShaianMailOrderSavePrompt 0x0A37   // 通信販売の前のセーブの確認
#define Scr_ShaianMailOrderSaveAnswer 0x0A38   // セーブの確認の結果, はいならセーブして通信販売へ, p0: 選択
#define Scr_0x0A39 0x0A39
#define Scr_0x0A3A 0x0A3A
#define Scr_0x0A3B 0x0A3B
#define Scr_0x0A3C 0x0A3C
#define Scr_0x0A3D 0x0A3D
#define Scr_0x0A3F 0x0A3F
#define Scr_TalkKidFromStart 0x0A40            // キッド(道具屋)との会話を最初から始める
#define Scr_TalkKid 0x0A41                     // キッド(道具屋)との会話, 進行度で特別な会話をしてから店の選択肢を出す
#define Scr_KidShopPrompt 0x0A42               // キッドの道具屋の選択肢 (買い物/話)
#define Scr_0x0A43 0x0A43
#define Scr_0x0A45 0x0A45
#define Scr_0x0A46 0x0A46
#define Scr_KidAfterShop 0x0A47                // 買い物のあとのキッドの一言
#define Scr_KidHintTalk 0x0A48                 // キッドの「話」, 進行度ごとのヒント
#define Scr_0x0A49 0x0A49
#define Scr_0x0A4A 0x0A4A
#define Scr_0x0A4B 0x0A4B
#define Scr_TalkRita 0x0A4C                    // リタの店での会話の入口
#define Scr_RitaFistMaster 0x0A4D              // 拳を極めたのでハートの紋章を譲ると言う
#define Scr_0x0A4E 0x0A4E
#define Scr_GetHeartCrest 0x0A4F               // 「ハートの紋章」を手に入れた
#define Scr_0x0A50 0x0A50
#define Scr_0x0A51 0x0A51
#define Scr_RitaHeartCrestExplain 0x0A52       // ハートの紋章の説明
#define Scr_RitaBelievePrompt 0x0A53           // リンゴを信じるかの選択肢 (信じている/分からない)
#define Scr_RitaBelieveAnswer 0x0A54           // 信じるかの選択で好感度が上下する, p0: 選択
#define Scr_RitaShopWelcome 0x0A55             // 「いらっしゃいませ!!お買い物ですか?」
#define Scr_RitaShopPrompt 0x0A56              // リタの店の選択肢 (お買い物/お話)
#define Scr_0x0A57 0x0A57
#define Scr_0x0A59 0x0A59
#define Scr_0x0A5A 0x0A5A
#define Scr_RitaAfterShop 0x0A5B               // 買い物のあとのリタのお礼
#define Scr_0x0A5C 0x0A5C
#define Scr_0x0A5D 0x0A5D
#define Scr_RitaAfterShopByTime 0x0A5E         // 時間帯で変わるリタのお礼
#define Scr_RitaSmallTalk 0x0A5F               // リタとの会話, 進行度ごとの台詞を順番に繰り返す
#define Scr_RitaWolfEvent 0x0A60               // ウルフイベント, リタを噛むとゲームオーバーにするゾーン判定を置く
#define Scr_0x0A61 0x0A61
#define Scr_0x0A62 0x0A62
#define Scr_0x0A63 0x0A63
#define Scr_0x0A64 0x0A64
#define Scr_0x0A66 0x0A66
#define Scr_0x0A68 0x0A68
#define Scr_TalkSumireStorage 0x0A6A           // 倉庫番スミレの会話の入口
#define Scr_SumireKuroPrompt 0x0A6B            // 「クロちゃん、だいじょうぶだよね?」の選択肢
#define Scr_SumireKuroAnswer 0x0A6C            // 選択の結果で好感度が上下する, p0: 選択
#define Scr_0x0A6F 0x0A6F
#define Scr_0x0A70 0x0A70
#define Scr_SumireStorageExpanded 0x0A71       // 「倉庫のボックス数が増えた!!」
#define Scr_SumireStoragePrompt 0x0A72         // 「そうこつかうの?」の選択肢 (つかう/はなす)
#define Scr_0x0A73 0x0A73
#define Scr_SumireSmallTalk 0x0A74             // スミレの雑談, 進行度で変わる
#define Scr_0x0A76 0x0A76
#define Scr_0x0A77 0x0A77
#define Scr_0x0A78 0x0A78
#define Scr_0x0A79 0x0A79
#define Scr_0x0A7C 0x0A7C
#define Scr_0x0A7E 0x0A7E
#define Scr_0x0A7F 0x0A7F
#define Scr_TalkCoffinSeller 0x0A80            // 棺桶屋の会話の入口
#define Scr_CoffinSellerOffer 0x0A81           // 「棺桶買うかい?古い棺桶は下取りするよ?」
#define Scr_CoffinBuyPrompt 0x0A82             // 棺桶を買うかの選択肢
#define Scr_CoffinBuyAnswer 0x0A83             // 棺桶を買うかの選択の結果, p0: 選択
#define Scr_0x0A85 0x0A85
#define Scr_0x0A86 0x0A86
#define Scr_CoffinSellerAfterShop 0x0A87       // 購入したかどうかに応じた棺桶屋の一言
#define Scr_0x0A88 0x0A88
#define Scr_0x0A8A 0x0A8A
#define Scr_0x0A8B 0x0A8B
#define Scr_0x0A8C 0x0A8C
#define Scr_0x0A8D 0x0A8D
#define Scr_0x0A8E 0x0A8E
#define Scr_b00_02_town 0x0A90 // "b00_02_town", サンミゲル (施設=図書館,鍛冶屋,銀行,時計塔)
#define Scr_0x0A91 0x0A91
#define Scr_0x0A92 0x0A92
#define Scr_0x0A93 0x0A93
#define Scr_0x0A94 0x0A94
#define Scr_0x0A95 0x0A95
#define Scr_TalkSmith 0x0AA0                   // 鍛冶屋スミスの会話の入口
#define Scr_0x0AA1 0x0AA1
#define Scr_0x0AA2 0x0AA2
#define Scr_SmithRepairGun 0x0AA3              // 太陽銃を修理して渡す
#define Scr_0x0AA4 0x0AA4
#define Scr_GetGunDelSol 0x0AA5                // 「ガン・デル・ソル」を手に入れた
#define Scr_0x0AA6 0x0AA6
#define Scr_0x0AA7 0x0AA7
#define Scr_SmithGunDelSolExplain 0x0AA8       // 修理した太陽銃の制限と使い方の説明
#define Scr_SmithMeteoriteTalk 0x0AAA          // 隕鉄に気づき, 特別な武器を作れると言う
#define Scr_SmithAstroTypePrompt 0x0AAB        // 隕鉄で作る武器の種類の選択肢 (ソード/スピア/ハンマー)
#define Scr_0x0AAC 0x0AAC
#define Scr_0x0AAE 0x0AAE
#define Scr_SmithAstroDone 0x0AAF              // 「できたぞ!!」(アストロ武器)
#define Scr_0x0AB0 0x0AB0
#define Scr_GetAstroWeapon 0x0AB1              // アストロソード/スピア/ハンマーを手に入れる
#define Scr_0x0AB2 0x0AB2
#define Scr_0x0AB3 0x0AB3
#define Scr_SmithAstroExplain 0x0AB4           // アストロ武器の特殊効果の説明
#define Scr_SmithLicenseTalk 0x0ABB            // S ランクの限定解除の話の入口
#define Scr_SmithLicenseSelectType 0x0ABC      // 限定解除できるタイプの数に応じて, 一番得意な武器の説明か選択へ分岐する
#define Scr_SmithAskLicenseSword 0x0ABE        // 「ソードタイプの限定解除でいいか?」
#define Scr_SmithAskLicenseSpear 0x0ABF        // 「スピアタイプの限定解除でいいか?」
#define Scr_SmithAskLicenseHammer 0x0AC0       // 「ハンマータイプの限定解除でいいか?」
#define Scr_SmithLicensePrompt 0x0AC1          // 限定解除の確認の選択肢 (いい/ダメ)
#define Scr_0x0AC2 0x0AC2
#define Scr_SmithGiveLicenseSword 0x0AC3       // ソードの限定解除の証を渡す前置き
#define Scr_SmithGiveLicenseSpear 0x0AC4       // スピアの限定解除の証を渡す前置き
#define Scr_SmithGiveLicenseHammer 0x0AC5      // ハンマーの限定解除の証を渡す前置き
#define Scr_SmithMasteredSword 0x0AC6          // ソードを極めたので限定解除を許可する
#define Scr_SmithMasteredSpear 0x0AC7          // スピアを極めたので限定解除を許可する
#define Scr_SmithMasteredHammer 0x0AC8         // ハンマーを極めたので限定解除を許可する
#define Scr_0x0AC9 0x0AC9
#define Scr_GetLicenseCrest 0x0ACA             // スペード/ダイヤ/クラブの紋章を手に入れる
#define Scr_0x0ACB 0x0ACB
#define Scr_0x0ACC 0x0ACC
#define Scr_SmithSRankExplain 0x0ACD           // S ランク (レベル49以上) の説明
#define Scr_SmithForgePrompt 0x0ACE            // 「鍛冶をするか?」の選択肢 (鍛冶をする/話をする)
#define Scr_SmithForgeAnswer 0x0ACF            // 鍛冶をするかの選択の結果, パネルの説明を読んでいなければ注意する, p0: 選択
#define Scr_0x0AD0 0x0AD0
#define Scr_SetupForge 0x0AD2                  // 鍛冶画面 (Forge) を作る
#define Scr_0x0AD3 0x0AD3
#define Scr_ForgeResult 0x0AD4                 // 太陽鍛冶でできた武器のパラメータを保存して結果画面へ進む, p0-p9: 名前/種類/ランク/レベル/品質/特殊/大成功/成功/失敗/スキル
#define Scr_0x0AD5 0x0AD5
#define Scr_SmithForgeResult 0x0AD6            // 鍛冶の出来ばえのコメント
#define Scr_0x0AD7 0x0AD7
#define Scr_0x0AD8 0x0AD8
#define Scr_0x0AD9 0x0AD9
#define Scr_0x0ADA 0x0ADA
#define Scr_0x0ADB 0x0ADB
#define Scr_0x0ADC 0x0ADC
#define Scr_0x0ADD 0x0ADD
#define Scr_0x0ADE 0x0ADE
#define Scr_SmithSmallTalk 0x0ADF              // スミスの雑談, 進行度で変わる
#define Scr_0x0AE0 0x0AE0
#define Scr_0x0AE1 0x0AE1
#define Scr_0x0AE3 0x0AE3
#define Scr_0x0AE5 0x0AE5
#define Scr_0x0AE6 0x0AE6
#define Scr_0x0AE7 0x0AE7
#define Scr_0x0AE8 0x0AE8
#define Scr_0x0AE9 0x0AE9
#define Scr_BankCounterTalk 0x0AEB             // 太陽バンク・暗黒ローン窓口の会話の開始
#define Scr_0x0AED 0x0AED
#define Scr_0x0AEE 0x0AEE
#define Scr_0x0AEF 0x0AEF
#define Scr_BankCounterEnd 0x0AF0              // 太陽バンク・暗黒ローン窓口の会話の終了
#define Scr_0x0AF2 0x0AF2
#define Scr_0x0AF3 0x0AF3
#define Scr_0x0AF4 0x0AF4
#define Scr_0x0AF5 0x0AF5
#define Scr_0x0AF6 0x0AF6
#define Scr_0x0AF7 0x0AF7
#define Scr_0x0AF8 0x0AF8
#define Scr_0x0AF9 0x0AF9
#define Scr_0x0AFA 0x0AFA
#define Scr_0x0AFB 0x0AFB
#define Scr_0x0AFC 0x0AFC
#define Scr_0x0AFD 0x0AFD
#define Scr_0x0AFE 0x0AFE
#define Scr_0x0AFF 0x0AFF
#define Scr_0x0B00 0x0B00
#define Scr_RecordsChoice 0x0B01               // 記録の閲覧の選択肢の処理, p0: 項目 (0: 総合記録, 1: 浄化記録, 2: 通信販売, ...)
#define Scr_0x0B03 0x0B03
#define Scr_ClampValue 0x0B04                  // p0 を 0..p1 に丸めて返す
#define Scr_0x0B06 0x0B06
#define Scr_LibraryResearchRecord 0x0B07       // 調査記録の本を開く, 全部調査済みなら★
#define Scr_LibraryResearchPrompt 0x0B08       // イモータル/アンデッドダンジョンの調査数を出して選ばせる
#define Scr_LibraryResearchAnswer 0x0B09       // 選んだ種類のダンジョンの一覧を表示する, p0: 選択
#define Scr_LibraryImmortalList 0x0B0A         // イモータルダンジョンの調査状況 (未調査/調査中/完了) をメッセージの EXTEND に詰める
#define Scr_LibraryUndeadList 0x0B0B           // アンデッドダンジョンの調査状況をメッセージの EXTEND に詰める
#define Scr_0x0B0C 0x0B0C
#define Scr_LibraryShowTitles 0x0B0D           // 称号一覧の本を表示する, 12個そろうと完成の表示
#define Scr_0x0B0E 0x0B0E
#define Scr_0x0B0F 0x0B0F
#define Scr_0x0B10 0x0B10
#define Scr_0x0B11 0x0B11
#define Scr_0x0B12 0x0B12
#define Scr_0x0B13 0x0B13
#define Scr_0x0B14 0x0B14
#define Scr_0x0B1E 0x0B1E
#define Scr_ShowTreasureRequest 0x0B1F         // 財宝探しの依頼内容を表示する
#define Scr_0x0B20 0x0B20
#define Scr_QuestAcceptAnswer 0x0B21           // 依頼を受けるかの結果, 前回の報酬を受け取っていなければ断る, p0: 0 受ける, 1 受けない, 2 もう一度読む
#define Scr_0x0B22 0x0B22
#define Scr_0x0B24 0x0B24
#define Scr_QuestCleared 0x0B25                // 依頼達成の報告, 報酬を渡す
#define Scr_0x0B26 0x0B26
#define Scr_0x0B28 0x0B28
#define Scr_SignLibraryWelcome 0x0B2E          // 「図書館へようこそ!!」の看板
#define Scr_TalkLady 0x0B2F                    // レディの会話の入口 (称号の達成報告など)
#define Scr_0x0B31 0x0B31
#define Scr_0x0B32 0x0B32
#define Scr_0x0B33 0x0B33
#define Scr_0x0B34 0x0B34
#define Scr_LadyMenuPrompt 0x0B35              // 仕事の話/世間話/景品交換の選択肢
#define Scr_0x0B36 0x0B36
#define Scr_LadyJobTalk 0x0B37                 // 依頼の「仕事の話」
#define Scr_LadyPrizeExplain 0x0B38            // 景品交換の説明
#define Scr_LadyShowLinkPoints 0x0B39          // 対戦ポイントを表示し, 100以上なら交換へ
#define Scr_0x0B3A 0x0B3A
#define Scr_LadyCardExchangeConfirm 0x0B3B     // 「100ポイント使って魔法カードと交換しますか?」
#define Scr_LadyCardExchangePrompt 0x0B3C      // 交換の選択肢 (はい/いいえ)
#define Scr_0x0B3D 0x0B3D
#define Scr_LadyCardExchangeGive 0x0B3E        // 魔法カードをランダムに1枚渡す
#define Scr_LadySmallTalk 0x0B40               // レディの世間話
#define Scr_LadyRumor 0x0B41                   // 「そういえば・・・」の噂話7種類を順に
#define Scr_0x0B42 0x0B42
#define Scr_0x0B43 0x0B43
#define Scr_0x0B45 0x0B45
#define Scr_TalkEnnio 0x0B47                   // 時計塔管理人エンニオの会話の入口
#define Scr_EnnioClockTalk 0x0B48              // エンニオとの会話, 時計合わせは1日1回だけ受け付ける
#define Scr_EnnioClockOffPrompt 0x0B49         // 大時計がずれているかの選択肢 (狂ってる/狂ってない)
#define Scr_EnnioClockOffAnswer 0x0B4A         // ずれているかの選択の結果, 狂ってるなら時計直しの説明, p0: 選択
#define Scr_EnnioFixClockAsk 0x0B4B            // 「時計を直すのか?」
#define Scr_EnnioFixClockPrompt 0x0B4C         // 直す/直さないの選択肢
#define Scr_0x0B4D 0x0B4D
#define Scr_0x0B4F 0x0B4F
#define Scr_0x0B50 0x0B50
#define Scr_EnnioClockAdjusted 0x0B51          // 時計合わせのあと時計台に戻ったときのエンニオの台詞
#define Scr_0x0B52 0x0B52
#define Scr_EnnioDismiss 0x0B53                // 「何じゃ、冷やかしか?」
#define Scr_0x0B54 0x0B54
#define Scr_0x0B55 0x0B55
#define Scr_0x0B56 0x0B56
#define Scr_0x0B57 0x0B57
#define Scr_0x0B58 0x0B58
#define Scr_0x0B59 0x0B59
#define Scr_0x0B5A 0x0B5A  // 太陽樹 (ST_TREE) のマップ初期化
#define Scr_MorningDew 0x0B66                  // 太陽樹の朝露
#define Scr_0x0B69 0x0B69
#define Scr_RitaTreeTalk 0x0B6A                // 成木になった太陽樹の前のリタの会話 (朝露の話など)
#define Scr_RitaConfession1 0x0B6C             // リタが告白しかけて「隙ありっ!!」
#define Scr_RitaConfession2 0x0B6D             // 告白しかけて「すき焼きっ!!」
#define Scr_RitaConfession3 0x0B6E             // 告白しかけて「すきま風っ!!」
#define Scr_RitaConfession4 0x0B6F             // 「(好きですっ♥)」と心の中だけで言う
#define Scr_RitaConfessionRegret 0x0B70        // 「何言ってんのーっ!」と悔やむ心の声
#define Scr_RitaConfessionGiveUp 0x0B71        // 「やっぱり言えないよーっ!」と悔やむ心の声
#define Scr_0x0B72 0x0B72
#define Scr_0x0B73 0x0B73
#define Scr_0x0B74 0x0B74
#define Scr_0x0B75 0x0B75
#define Scr_b00_04_town_a 0x0B7B // "b00_04_town", パイルドライバーの広場(その1), その2は Scr_b00_04_town_b
#define Scr_0x0B85 0x0B85
#define Scr_SpawnZazie 0x0B86                  // 進行度に応じてザジを置く
#define Scr_0x0B87 0x0B87
#define Scr_SpawnRita 0x0B88                   // 進行度に応じてリタを置く
#define Scr_RitaSetTownMode 0x0B89             // ジャンゴ戦のあとリタを町モードに戻す
#define Scr_TalkRitaToSabata 0x0B8A            // サバタを操作している間 (進行度33〜34) のリタの会話, アイテムを渡す
#define Scr_0x0B8B 0x0B8B
#define Scr_0x0B8C 0x0B8C
#define Scr_0x0B8F 0x0B8F
#define Scr_0x0B91 0x0B91
#define Scr_0x0B93 0x0B93
#define Scr_0x0B95 0x0B95
#define Scr_0x0B97 0x0B97
#define Scr_0x0B9B 0x0B9B
#define Scr_0x0B9C 0x0B9C
#define Scr_0x0B9D 0x0B9D
#define Scr_b00_05_town 0x0B9E // "b00_05_town", サンミゲル (酒場, 住人の家)
#define Scr_InitResidentHouses 0x0BA6          // 住人の家の中の初期化, 雨や夜ならルイス, マルチェロ, ハテナを各自の家に置く
#define Scr_TalkZaji2 0x0BA9                   // 別の太陽街のマップ (0x0B9E) のザジの会話の入口 (寝ているザジ, フリーズ伝授など)
#define Scr_0x0BAB 0x0BAB
#define Scr_0x0BAC 0x0BAC
#define Scr_0x0BAD 0x0BAD
#define Scr_0x0BB2 0x0BB2
#define Scr_0x0BB3 0x0BB3
#define Scr_0x0BB4 0x0BB4
#define Scr_0x0BB7 0x0BB7
#define Scr_0x0BB8 0x0BB8
#define Scr_0x0BB9 0x0BB9
#define Scr_0x0BBB 0x0BBB
#define Scr_StarReadingStart 0x0BBC            // 星読みの開始, エピローグ全文をナレーション (Narration) で流す
#define Scr_StarReadingEnd 0x0BBD              // 星読みの全文再生が終わったあとの処理
#define Scr_0x0BBE 0x0BBE
#define Scr_0x0BC0 0x0BC0
#define Scr_0x0BC1 0x0BC1
#define Scr_0x0BC2 0x0BC2
#define Scr_0x0BC3 0x0BC3
#define Scr_0x0BC5 0x0BC5
#define Scr_0x0BC8 0x0BC8
#define Scr_0x0BCA 0x0BCA
#define Scr_0x0BCC 0x0BCC
#define Scr_0x0BCD 0x0BCD
#define Scr_0x0BCE 0x0BCE
#define Scr_TalkLuis2 0x0BD0                   // 別の太陽街のマップ (0x0B9E) のルイスの会話の入口
#define Scr_LuisSmallTalk2 0x0BD1              // Scr_TalkLuis2 から呼ぶルイスの雑談
#define Scr_TalkMarcello2 0x0BD2               // 別の太陽街のマップ (0x0B9E) のマルチェロの会話の入口
#define Scr_MarcelloSmallTalk2 0x0BD3          // Scr_TalkMarcello2 から呼ぶマルチェロの雑談
#define Scr_TalkHatena 0x0BD5                   // "ハテナ"に話しかけたときの会話の入口, 初対面・帰宅中・ブラインドボックスなどで分岐する
#define Scr_HatenaGrandmaster 0x0BD7            // 称号を全部取ったのでグランドマスターを授ける
#define Scr_0x0BD8 0x0BD8
#define Scr_GetWorldCard 0x0BD9                // 「世界のカード」を手に入れた
#define Scr_0x0BDA 0x0BDA
#define Scr_0x0BDB 0x0BDB
#define Scr_HatenaBlindBoxUpThanks 0x0BDC       // 商売のお礼にブラインドボックスの中身をレベル1に上げる
#define Scr_HatenaBlindBoxUp2 0x0BDD            // ブラインドボックスの中身がレベル2に上がった
#define Scr_HatenaBlindBoxUp3 0x0BDE            // ブラインドボックスの中身がレベル3に上がった
#define Scr_HatenaBlindBoxUp4 0x0BDF            // ブラインドボックスの中身がレベル4に上がった
#define Scr_HatenaRecallName 0x0BE0             // 直撃を受けて名前を思い出しかけ, 持ち物を譲る
#define Scr_0x0BE1 0x0BE1
#define Scr_0x0BE3 0x0BE3
#define Scr_HatenaBlindBoxPrice 0x0BE4          // ブラインドボックスの値段 (1箱200ソル) の案内
#define Scr_HatenaChatPrompt 0x0BE5             // "ハテナ"の選択肢を出して Scr_HatenaChat に渡す
#define Scr_HatenaChat 0x0BE6                   // "ハテナ"との会話
#define Scr_0x0BE7 0x0BE7
#define Scr_SpawnBlindBox 0x0BE8               // 購入済みのブラインドボックスを設定した位置に置く, p0: 置き場所の区分, p1: 現在のエリア
#define Scr_0x0BE9 0x0BE9
#define Scr_0x0BEA 0x0BEA
#define Scr_HatenaSmallTalk 0x0BEB              // "ハテナ"の雑談2種類を交互に
#define Scr_HatenaSmallTalkEndgame 0x0BEC       // 終盤 (1周目の進行度62以降) の"ハテナ"の雑談
#define Scr_HatenaSmallTalkNewGamePlus 0x0BED   // 2周目以降の"ハテナ"の雑談 (称号の話)
#define Scr_HatenaTitleTalk 0x0BEE              // "ハテナ"が獲得済みの称号について話す
#define Scr_0x0BF1 0x0BF1
#define Scr_0x0BF3 0x0BF3
#define Scr_0x0BF4 0x0BF4
#define Scr_0x0BF5 0x0BF5
#define Scr_0x0BF6 0x0BF6  // パイルドライバー (ST_PD_POINT) のマップ初期化, 衝突マップ 0x7E9E
#define Scr_0x0BFC 0x0BFC
#define Scr_a00_00_ruins 0x0BFD // "a00_00_ruins", 廃墟
#define Scr_0x0C04 0x0C04
#define Scr_0x0C05 0x0C05
#define Scr_0x0C08 0x0C08
#define Scr_0x0C09 0x0C09
#define Scr_0x0C0B 0x0C0B
#define Scr_0x0C0C 0x0C0C
#define Scr_0x0C0D 0x0C0D
#define Scr_0x0C0E 0x0C0E
#define Scr_a00_01_ruins 0x0C10 // "a00_01_ruins", 廃墟
#define Scr_0x0C17 0x0C17
#define Scr_0x0C18 0x0C18
#define Scr_a00_02_ruins 0x0C1B // "a00_02_ruins", 廃墟
#define Scr_0x0C22 0x0C22
#define Scr_0x0C23 0x0C23
#define Scr_a00_03_ruins 0x0C27 // "a00_03_ruins", 廃墟
#define Scr_RuinsColorCountSign 0x0C2E         // 遺跡の「赤:n 青:m」の看板, p0: 看板ID
#define Scr_0x0C2F 0x0C2F
#define Scr_0x0C30 0x0C30
#define Scr_0x0C31 0x0C31
#define Scr_a00_04_ruins 0x0C34 // "a00_04_ruins", 廃墟
#define Scr_0x0C3B 0x0C3B
#define Scr_0x0C3C 0x0C3C
#define Scr_RuinsSign 0x0C3D                   // 遺跡の看板 (進む/戻る, 落書き), p0: 看板ID
#define Scr_a00_05_ruins 0x0C3E // "a00_05_ruins", 廃墟
#define Scr_a00_06_ruins 0x0C47 // "a00_06_ruins", 廃墟
#define Scr_0x0C4E 0x0C4E
#define Scr_RuinsSwitchOrderSign 0x0C51        // 「5、7、3、の順にスイッチを入れよ。」
#define Scr_a00_07_ruins 0x0C54 // "a00_07_ruins", 廃墟
#define Scr_0x0C5A 0x0C5A
#define Scr_0x0C5B 0x0C5B
#define Scr_0x0C5C 0x0C5C
#define Scr_0x0C5E 0x0C5E
#define Scr_0x0C5F 0x0C5F
#define Scr_0x0C60 0x0C60
#define Scr_a00_08_ruins 0x0C61 // "a00_08_ruins", 廃墟
#define Scr_0x0C6A 0x0C6A
#define Scr_0x0C6D 0x0C6D
#define Scr_0x0C6E 0x0C6E
#define Scr_0x0C71 0x0C71
#define Scr_a10_00_forest 0x0C73 // "a10_00_forest", 森
#define Scr_0x0C7B 0x0C7B
#define Scr_0x0C7D 0x0C7D
#define Scr_0x0C7E 0x0C7E
#define Scr_0x0C80 0x0C80
#define Scr_0x0C81 0x0C81
#define Scr_a10_01_forest 0x0C82 // "a10_01_forest", 森
#define Scr_a10_02_forest 0x0C8A // "a10_02_forest", 森
#define Scr_a10_03_forest 0x0C92 // "a10_03_forest", 森
#define Scr_0x0C98 0x0C98
#define Scr_0x0C99 0x0C99
#define Scr_a10_04_forest 0x0C9C // "a10_04_forest", 森
#define Scr_0x0CA2 0x0CA2
#define Scr_a10_05_forest 0x0CA5 // "a10_05_forest", 森
#define Scr_StartSolarLift 0x0CAC              // 太陽移動床 (HashName("移動床") = 0x4699) を動かす
#define Scr_StopSolarLift 0x0CAD               // 太陽移動床を止める
#define Scr_0x0CAF 0x0CAF
#define Scr_a10_06_forest 0x0CB0 // "a10_06_forest", 森
#define Scr_0x0CB7 0x0CB7
#define Scr_0x0CB8 0x0CB8
#define Scr_0x0CB9 0x0CB9
#define Scr_a10_07_forest 0x0CBA // "a10_07_forest", 森
#define Scr_a10_08_forest 0x0CC2 // "a10_08_forest", 森
#define Scr_0x0CC8 0x0CC8
#define Scr_0x0CCA 0x0CCA
#define Scr_a10_09_forest 0x0CCB // "a10_09_forest", 森
#define Scr_a10_10_forest 0x0CD2 // "a10_10_forest", 森
#define Scr_0x0CD8 0x0CD8
#define Scr_0x0CDA 0x0CDA
#define Scr_0x0CDB 0x0CDB
#define Scr_0x0CDC 0x0CDC
#define Scr_0x0CDD 0x0CDD
#define Scr_0x0CDE 0x0CDE
#define Scr_0x0CDF 0x0CDF
#define Scr_0x0CE0 0x0CE0
#define Scr_a10_11_forest 0x0CE1 // "a10_11_forest", 森
#define Scr_0x0CE7 0x0CE7
#define Scr_0x0CE9 0x0CE9
#define Scr_0x0CEA 0x0CEA
#define Scr_0x0CEB 0x0CEB
#define Scr_0x0CEE 0x0CEE
#define Scr_0x0CEF 0x0CEF
#define Scr_0x0CF0 0x0CF0
#define Scr_0x0CF3 0x0CF3
#define Scr_0x0CF4 0x0CF4
#define Scr_0x0CF5 0x0CF5
#define Scr_a10_12_forest 0x0CF6 // "a10_12_forest", 森
#define Scr_0x0CFE 0x0CFE
#define Scr_0x0D03 0x0D03
#define Scr_0x0D04 0x0D04
#define Scr_0x0D05 0x0D05
#define Scr_a10_13_forest 0x0D06 // "a10_13_forest", 森
#define Scr_0x0D10 0x0D10
#define Scr_0x0D11 0x0D11
#define Scr_0x0D12 0x0D12
#define Scr_a10_14_forest 0x0D13 // "a10_14_forest", 森
#define Scr_0x0D19 0x0D19
#define Scr_0x0D1B 0x0D1B
#define Scr_0x0D1C 0x0D1C
#define Scr_0x0D1D 0x0D1D
#define Scr_0x0D1E 0x0D1E
#define Scr_0x0D1F 0x0D1F  // 地下墓地 (a20) の最初の部屋のマップ初期化, 衝突マップ 0xB26B
#define Scr_0x0D24 0x0D24
#define Scr_0x0D2A 0x0D2A
#define Scr_0x0D2B 0x0D2B
#define Scr_0x0D2C 0x0D2C
#define Scr_0x0D2D 0x0D2D
#define Scr_0x0D2E 0x0D2E  // 地下墓地 (a20) の部屋のマップ初期化, 衝突マップ 0xB66F
#define Scr_0x0D35 0x0D35  // 地下墓地 (a20) の部屋のマップ初期化, 衝突マップ 0xB673
#define Scr_0x0D3C 0x0D3C  // 地下墓地 (a20) の部屋のマップ初期化, 衝突マップ 0xB677
#define Scr_0x0D43 0x0D43  // 地下墓地 (a20) の部屋のマップ初期化, 衝突マップ 0xB67B
#define Scr_0x0D49 0x0D49
#define Scr_0x0D4A 0x0D4A
#define Scr_0x0D4C 0x0D4C  // 地下墓地 (a20) の部屋のマップ初期化, 衝突マップ 0xB67F
#define Scr_0x0D53 0x0D53  // 地下墓地 (a20) の部屋のマップ初期化, 衝突マップ 0xB683
#define Scr_0x0D5A 0x0D5A  // 地下墓地 (a20) の部屋のマップ初期化, 衝突マップ 0xB687
#define Scr_0x0D60 0x0D60
#define Scr_0x0D61 0x0D61
#define Scr_0x0D63 0x0D63
#define Scr_a30_00_time 0x0D65 // "a30_00_time", 時の家
#define Scr_0x0D6C 0x0D6C
#define Scr_0x0D6D 0x0D6D
#define Scr_0x0D6F 0x0D6F
#define Scr_0x0D70 0x0D70
#define Scr_a30_01_time 0x0D72 // "a30_01_time", 時の家
#define Scr_GhostBoyFirstTalk 0x0D75           // 時の家で幽霊少年に初めて会ったときの会話
#define Scr_TimeHouseDoorLocked 0x0D7B         // 「扉はかたく閉ざされている。」
#define Scr_0x0D81 0x0D81
#define Scr_0x0D82 0x0D82
#define Scr_0x0D84 0x0D84
#define Scr_TimeHouseRubble 0x0D87             // がれきで通れないメッセージ
#define Scr_0x0D89 0x0D89
#define Scr_GuideDynamite 0x0D8A               // 時の家のヒント看板「壊せ!!」, 傷んだ壁はダイナマイトで
#define Scr_a30_02_time 0x0D8C // "a30_02_time", 時の家
#define Scr_0x0D95 0x0D95
#define Scr_0x0D9C 0x0D9C
#define Scr_0x0D9D 0x0D9D
#define Scr_GuideTimeCircle 0x0DA0             // 時の家のヒント看板「時を越えろ。」, タイム魔方陣
#define Scr_0x0DA4 0x0DA4
#define Scr_TimeHousePinDoor 0x0DA5            // 暗証番号の扉, 未入力なら入力を促し, 入力済みなら番号を表示する, p1: 扉のフラグ番号
#define Scr_TimeHousePinInput 0x0DA6           // 扉の暗証番号を1桁ずつ選ぶ選択肢
#define Scr_0x0DA7 0x0DA7
#define Scr_SetPinDigitExtend 0x0DA8           // 数字 p1 の文字列をメッセージの EXTEND p0 に入れる
#define Scr_TimeHousePinCheck 0x0DA9           // 入力した暗証番号を照合し, 解錠するか不一致を表示する
#define Scr_0x0DAC 0x0DAC
#define Scr_0x0DAD 0x0DAD
#define Scr_a30_03_time 0x0DAE // "a30_03_time", 時の家
#define Scr_0x0DB8 0x0DB8
#define Scr_0x0DC0 0x0DC0
#define Scr_a30_04_time 0x0DC2 // "a30_04_time", 時の家
#define Scr_0x0DD1 0x0DD1
#define Scr_TimeHousePinSetTerminal 0x0DD4     // 暗証番号を設定する装置, 設定するかの選択肢
#define Scr_TimeHousePinSetAnswer 0x0DD5       // 設定するかの選択の結果, p0: 選択
#define Scr_TimeHousePinSetInput 0x0DD6        // 設定する暗証番号を1桁ずつ選ぶ選択肢
#define Scr_0x0DD7 0x0DD7
#define Scr_TimeHousePinSetDone 0x0DD8         // 「暗証番号を設定しました。」
#define Scr_0x0DD9 0x0DD9
#define Scr_0x0DDB 0x0DDB
#define Scr_0x0DDC 0x0DDC
#define Scr_0x0DDD 0x0DDD
#define Scr_a30_05_time 0x0DDE // "a30_05_time", 時の家
#define Scr_0x0DEA 0x0DEA
#define Scr_0x0DF2 0x0DF2
#define Scr_0x0DF6 0x0DF6
#define Scr_a30_06_time 0x0DFA // "a30_06_time", 時の家
#define Scr_TalkGhostBoy 0x0E01                // 幽霊少年の会話, 2種類を交互に
#define Scr_0x0E02 0x0E02
#define Scr_0x0E04 0x0E04
#define Scr_0x0E05 0x0E05
#define Scr_a30_07_time 0x0E06 // "a30_07_time", 時の家
#define Scr_0x0E09 0x0E09
#define Scr_0x0E0D 0x0E0D
#define Scr_0x0E0F 0x0E0F
#define Scr_0x0E13 0x0E13
#define Scr_0x0E15 0x0E15
#define Scr_0x0E17 0x0E17
#define Scr_0x0E18 0x0E18
#define Scr_0x0E19 0x0E19
#define Scr_0x0E1B 0x0E1B
#define Scr_0x0E1E 0x0E1E
#define Scr_a30_08_time 0x0E1F // "a30_08_time", 時の家
#define Scr_0x0E27 0x0E27
#define Scr_0x0E30 0x0E30
#define Scr_0x0E33 0x0E33  // 宝物庫 (a40) の最初の部屋のマップ初期化, 衝突マップ 0xB889
#define Scr_0x0E3A 0x0E3A
#define Scr_SignTreasuryRockRoom 0x0E3B        // 宝物庫「岩の間」の看板
#define Scr_SignTreasuryIceRoom 0x0E3C         // 宝物庫「氷の間」の看板
#define Scr_SignTreasuryCrestRoom 0x0E3D       // 宝物庫「紋章の間」の看板
#define Scr_SignTreasuryPanelRoom 0x0E3E       // 宝物庫「パネルの間」の看板
#define Scr_0x0E3F 0x0E3F  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xB909
#define Scr_0x0E46 0x0E46  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xB989
#define Scr_0x0E4D 0x0E4D  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xBA09
#define Scr_0x0E54 0x0E54  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xBA89
#define Scr_0x0E5B 0x0E5B  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xBB09
#define Scr_0x0E62 0x0E62  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xBB89
#define Scr_0x0E69 0x0E69  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xBC09
#define Scr_0x0E70 0x0E70  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xBC89
#define Scr_0x0E77 0x0E77  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xBD09
#define Scr_0x0E7E 0x0E7E  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xC889
#define Scr_0x0E85 0x0E85  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xC909
#define Scr_0x0E8C 0x0E8C  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xC989
#define Scr_0x0E93 0x0E93  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCA09
#define Scr_0x0E9A 0x0E9A  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCA89
#define Scr_0x0EA1 0x0EA1  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCB09
#define Scr_0x0EA8 0x0EA8
#define Scr_0x0EA9 0x0EA9
#define Scr_0x0EAA 0x0EAA  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCB89
#define Scr_0x0EB1 0x0EB1
#define Scr_0x0EB3 0x0EB3
#define Scr_0x0EB4 0x0EB4
#define Scr_0x0EBA 0x0EBA  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCB89
#define Scr_0x0EC1 0x0EC1  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCB89
#define Scr_0x0EC8 0x0EC8  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCB89
#define Scr_0x0ECF 0x0ECF  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xCB89
#define Scr_0x0ED6 0x0ED6  // 宝物庫 (a40) の部屋のマップ初期化, 衝突マップ 0xD909
#define Scr_0x0EDE 0x0EDE
#define Scr_0x0EE4 0x0EE4
#define Scr_0x0EE5 0x0EE5
#define Scr_0x0EEE 0x0EEE
#define Scr_0x0EF0 0x0EF0
#define Scr_random_enter 0x0F04  // "random_enter", 夢幻街の入口
#define Scr_0x0F0B 0x0F0B
#define Scr_MugenGuide1 0x0F0C                 // 「夢幻の心得・その1」
#define Scr_MugenGuide2 0x0F0D                 // 「夢幻の心得・その2」
#define Scr_MugenGuide3 0x0F0E                 // 「夢幻の心得・その3」
#define Scr_MugenGuide4 0x0F0F                 // 「夢幻の心得・その4」
#define Scr_MugenLevelSign 0x0F10              // 「夢幻街:レベルN」を表示する (最大10)
#define Scr_0x0F13 0x0F13
#define Scr_0x0F16 0x0F16
#define Scr_0x0F18 0x0F18
#define Scr_0x0F20 0x0F20
#define Scr_0x0F21 0x0F21
#define Scr_0x0F27 0x0F27
#define Scr_0x0F29 0x0F29
#define Scr_OnMugenSandwormDefeated 0x0F2A  // 夢幻街の閉じ込め戦闘 (W_MUGEN_LEVEL 6) のサンドウォームを倒したとき
#define Scr_0x0F2B 0x0F2B
#define Scr_OnMugenSerpentDefeated 0x0F2C  // 夢幻街の閉じ込め戦闘 (W_MUGEN_LEVEL 8) のサーペントを倒したとき
#define Scr_0x0F2D 0x0F2D
#define Scr_0x0F2E 0x0F2E
#define Scr_0x0F30 0x0F30
#define Scr_random_goal 0x0F31  // "random_goal", 夢幻街の報酬部屋
#define Scr_0x0F38 0x0F38
#define Scr_0x0F39 0x0F39
#define Scr_0x0F3A 0x0F3A
#define Scr_0x0F3B 0x0F3B
#define Scr_0x0F3C 0x0F3C
#define Scr_0x0F3D 0x0F3D
#define Scr_0x0F3E 0x0F3E
#define Scr_0x0F3F 0x0F3F
#define Scr_0x0F41 0x0F41
#define Scr_0x0F42 0x0F42
#define Scr_0x0F43 0x0F43
#define Scr_TitleSensorCalib 0x0F44            // タイトルメニューを太陽センサー調整画面で開く
#define Scr_TitleOptionMenu 0x0F45             // タイトルメニューをオプション (センサー調整/地域選択) で開く
#define Scr_TitleLink 0x0F46 // "LINK", タイトルメニューを "LINK" で開く?
#define Scr_0x0F47 0x0F47
#define Scr_0x0F48 0x0F48
#define Scr_0x0F49 0x0F49
#define Scr_0x0F4A 0x0F4A
#define Scr_0x0F4B 0x0F4B
#define Scr_TitleSoundTest 0x0F4C              // タイトルメニューをサウンドテストで開く
#define Scr_TitleSaveSelect 0x0F4D             // タイトルメニューをセーブ選択 (つづき/はじめ/パスワード/名前) で開く
#define Scr_0x0F4E 0x0F4E
#define Scr_0x0F4F 0x0F4F
#define Scr_SensorGuide 0x0F50                 // 太陽センサーのガイド本体, W_SENSOR_GUIDE_PAGE のページを SensorGuide で出す
#define Scr_SensorGuideNext 0x0F52             // 太陽センサーのガイドを次のページへ進め, 項目の最後なら元の画面へ戻る, p0: 0 で進める
#define Scr_0x0F55 0x0F55
#define Scr_0x0F56 0x0F56
#define Scr_0x0F58 0x0F58
#define Scr_0x0F5A 0x0F5A
#define Scr_0x0F5B 0x0F5B
#define Scr_0x0F5C 0x0F5C
#define Scr_0x0F5E 0x0F5E
#define Scr_0x0F5F 0x0F5F
#define Scr_CrossoverHelpAnswer 0x0F60         // クロスオーバーバトルの説明メニューで選んだ項目を表示する, p0: 項目
#define Scr_0x0F61 0x0F61
#define Scr_0x0F62 0x0F62
#define Scr_ArenaRankSelect 0x0F69             // 闘技場のランク選択
#define Scr_0x0F6A 0x0F6A
#define Scr_0x0F6B 0x0F6B
#define Scr_0x0F6C 0x0F6C
#define Scr_0x0F6E 0x0F6E
#define Scr_0x0F71 0x0F71
#define Scr_0x0F72 0x0F72
#define Scr_0x0F75 0x0F75
#define Scr_0x0F7B 0x0F7B
#define Scr_0x0F7D 0x0F7D
#define Scr_0x0F83 0x0F83
#define Scr_0x0F85 0x0F85
#define Scr_0x0F8B 0x0F8B
#define Scr_0x0F8D 0x0F8D
#define Scr_SpawnArenaSandworm 0x0F92  // 闘技場でサンドウォームを出す, ランク 3 なら能力値を上げる
#define Scr_OnArenaSandwormDefeated 0x0F94  // 闘技場のサンドウォームを倒したとき
#define Scr_0x0F95 0x0F95
#define Scr_0x0F9B 0x0F9B
#define Scr_0x0F9E 0x0F9E
#define Scr_SpawnArenaSerpent 0x0FA3  // 闘技場でサーペントを出す, ランク 3 なら能力値を上げる
#define Scr_OnArenaSerpentDefeated 0x0FA4  // 闘技場のサーペントを倒したとき
#define Scr_0x0FA6 0x0FA6
#define Scr_0x0FAC 0x0FAC
#define Scr_0x0FAF 0x0FAF
#define Scr_SpawnArenaShadeMan 0x0FB5  // 闘技場でシェードマンを出す, ランク 3 なら HP 10000, クラッシュノイズの攻撃力 200 などに上げる
#define Scr_OnArenaShadeManDefeated 0x0FB6  // 闘技場のシェードマンを倒したとき (.c[0])
#define Scr_0x0FB7 0x0FB7
#define Scr_0x0FB8 0x0FB8
#define Scr_0x0FBE 0x0FBE
#define Scr_0x0FBF 0x0FBF
#define Scr_0x0FC1 0x0FC1
#define Scr_0x0FCA 0x0FCA
#define Scr_0x0FCB 0x0FCB
#define Scr_0x0FCC 0x0FCC
#define Scr_0x0FD3 0x0FD3
#define Scr_0x0FD4 0x0FD4
#define Scr_0x0FD5 0x0FD5
#define Scr_0x0FDA 0x0FDA
#define Scr_0x0FDB 0x0FDB
#define Scr_0x0FDD 0x0FDD
#define Scr_0x0FE4 0x0FE4
#define Scr_0x0FE5 0x0FE5
#define Scr_0x0FE6 0x0FE6
#define Scr_0x0FEC 0x0FEC
#define Scr_0x0FED 0x0FED
#define Scr_0x0FEF 0x0FEF
#define Scr_0x0FF0 0x0FF0
#define Scr_0x0FF1 0x0FF1
#define Scr_0x0FF2 0x0FF2
#define Scr_0x0FF3 0x0FF3
#define Scr_0x0FF4 0x0FF4
#define Scr_0x0FF5 0x0FF5
#define Scr_0x0FF6 0x0FF6
#define Scr_0x0FF8 0x0FF8
#define Scr_0x0FF9 0x0FF9
#define Scr_0x0FFA 0x0FFA
#define Scr_0x0FFB 0x0FFB
#define Scr_0x0FFC 0x0FFC
#define Scr_0x0FFD 0x0FFD
#define Scr_0x0FFE 0x0FFE
#define Scr_0x1003 0x1003
#define Scr_0x1004 0x1004
#define Scr_0x1005 0x1005
#define Scr_0x1006 0x1006
#define Scr_0x100B 0x100B
#define Scr_0x1011 0x1011
#define Scr_0x1012 0x1012
#define Scr_0x1013 0x1013
#define Scr_SpawnShadeManCrossover 0x1018  // クロスオーバーのシェードマン (ShadeManCrossover) を出す
#define Scr_0x1019 0x1019
#define Scr_0x101A 0x101A
#define Scr_0x101B 0x101B
#define Scr_0x101D 0x101D
#define Scr_0x101E 0x101E
#define Scr_0x1026 0x1026
#define Scr_0x1029 0x1029
#define Scr_0x102A 0x102A
#define Scr_BestFriendEpilogue 0x102F // p0=会話の段階, ゲームクリア後の、好感度が1番高いキャラとのエピローグ会話
#define Scr_0x1031 0x1031
#define Scr_CreateGameResult 0x1032 // ゲームクリア時のリザルト画面
#define Scr_0x1033 0x1033
#define Scr_0x1034 0x1034
#define Scr_0x1035 0x1035
#define Scr_0x1036 0x1036
#define Scr_0x1037 0x1037
#define Scr_0x1038 0x1038
#define Scr_0x103B 0x103B
#define Scr_0x103C 0x103C
#define Scr_0x103D 0x103D
#define Scr_0x103E 0x103E
#define Scr_GameClear 0x103F                   // ゲームクリア, 周回数++して、 偶数周ならブラックパンサーを挟んでから Scr_StaffRoll
#define Scr_StaffRoll 0x1040                   // スタッフロール
#define Scr_0x1041 0x1041
#define Scr_0x1042 0x1042
#define Scr_0x1043 0x1043
#define Scr_0x1044 0x1044
#define Scr_EpilogueSlideshow 0x1045           // スタッフロールのあとのエピローグのナレーション (Narration 0xB470, Str_Epilogue)
#define Scr_0x1046 0x1046
#define Scr_TheEndSlideshow 0x1047             // エピローグのあとの「THE END」のナレーション (Narration 0x1465)
#define Scr_0x1048 0x1048
#define Scr_0x1049 0x1049
#define Scr_0x104A 0x104A
#define Scr_0x104B 0x104B
#define Scr_0x104C 0x104C
#define Scr_0x104D 0x104D
#define Scr_0x104E 0x104E
#define Scr_0x104F 0x104F
#define Scr_CutsceneKidFrostLens 0x1050        // キッド再会カットシーン, 太陽銃のレンズ「フロスト」を取り戻してエンチャント・フロストを覚える
#define Scr_0x1051 0x1051
#define Scr_0x1052 0x1052
#define Scr_0x1053 0x1053
#define Scr_0x1054 0x1054
#define Scr_0x1055 0x1055
#define Scr_0x1056 0x1056
#define Scr_0x1057 0x1057
#define Scr_0x1058 0x1058
#define Scr_0x1059 0x1059
#define Scr_0x105A 0x105A
#define Scr_CutsceneShaianFirstMeet 0x105B     // シャイアンとの初対面と戦闘のカットシーン
#define Scr_0x105C 0x105C
#define Scr_CutsceneShaianGiveCircleKey 0x105D // シャイアンが正体に気づき「○のカギ」を渡すカットシーン
#define Scr_CutsceneDainnImpostor 0x105E       // ドゥラスロールのボス部屋前のカットシーン
#define Scr_CutsceneDurathrorAppear 0x105F     // 赤きドゥラスロール登場のカットシーン
#define Scr_0x1061 0x1061
#define Scr_0x1062 0x1062
#define Scr_0x1063 0x1063
#define Scr_0x1064 0x1064
#define Scr_CutsceneRingoEarthLens 0x1065      // リンゴ再会カットシーン, 太陽銃のレンズ「アース」を取り戻してエンチャント・アースを覚える
#define Scr_CutsceneTarotSealOpen 0x1066       // 3賢者のカードでタロット封印を開け, リンゴが駆けつけるカットシーン
#define Scr_0x1067 0x1067
#define Scr_0x1068 0x1068
#define Scr_CutsceneDvalinnAppear 0x1069       // 青いシルエットの女 (ドヴァリン) 登場のカットシーン
#define Scr_CutsceneSabataLeavesFight 0x106A   // サバタの声がジャンゴに後を任せて敵を追うカットシーン
#define Scr_0x106B 0x106B
#define Scr_0x106C 0x106C
#define Scr_0x106D 0x106D
#define Scr_0x106E 0x106E
#define Scr_0x106F 0x106F
#define Scr_0x1070 0x1070
#define Scr_0x1071 0x1071
#define Scr_0x1072 0x1072
#define Scr_0x1073 0x1073
#define Scr_0x1074 0x1074
#define Scr_0x1075 0x1075
#define Scr_0x1076 0x1076
#define Scr_CutsceneLadyRitaArrive 0x1077      // レディとリタが駆けつけて戦うカットシーン
#define Scr_CutsceneShaianKidArrive 0x1078     // シャイアンとキッドが駆けつけるカットシーン
#define Scr_0x1079 0x1079
#define Scr_0x107A 0x107A
#define Scr_0x107B 0x107B
#define Scr_0x107C 0x107C
#define Scr_0x107D 0x107D
#define Scr_0x107E 0x107E
#define Scr_0x107F 0x107F
#define Scr_b00_04_town_b 0x1080 // "b00_04_town", パイルドライバーの広場(その2), その1は Scr_b00_04_town_a
#define Scr_0x1082 0x1082
#define Scr_0x1083 0x1083
#define Scr_0x1084 0x1084
#define Scr_0x1086 0x1086
#define Scr_0x1087 0x1087
#define Scr_0x1088 0x1088
#define Scr_0x1089 0x1089
#define Scr_0x108A 0x108A
#define Scr_0x108B 0x108B
#define Scr_0x108C 0x108C
#define Scr_0x108D 0x108D
#define Scr_0x108E 0x108E
#define Scr_0x108F 0x108F
#define Scr_0x1090 0x1090
#define Scr_0x1091 0x1091
#define Scr_0x1092 0x1092
#define Scr_0x1093 0x1093
#define Scr_0x1094 0x1094
#define Scr_0x1095 0x1095
#define Scr_0x1096 0x1096
#define Scr_0x1097 0x1097
#define Scr_0x1098 0x1098
#define Scr_0x1099 0x1099
#define Scr_0x109A 0x109A
#define Scr_0x109B 0x109B
#define Scr_0x109C 0x109C
#define Scr_0x109D 0x109D
#define Scr_0x109E 0x109E
#define Scr_0x109F 0x109F
#define Scr_0x10A0 0x10A0
#define Scr_CutsceneSt03End 0x10A1 // ドゥラスロール浄化後の仲間とのカットシーン
#define Scr_St03EndSavePrompt 0x10A2     // ST_TREE(ドゥラスロール浄化後の太陽樹でのカットシーン) へ移る前のセーブの確認
#define Scr_St03EndSaveAnswer 0x10A3     // セーブしてから (またはそのまま) ST_TREE(ドゥラスロール浄化後の太陽樹でのカットシーン) へ移る, p0: 選択
#define Scr_0x10A4 0x10A4
#define Scr_CutsceneRitaLearnHealing 0x10A5    // 太陽樹の芽の前のリタのカットシーン, 大地の祝福でヒーリングを覚える
#define Scr_0x10A6 0x10A6
#define Scr_0x10A7 0x10A7
#define Scr_0x10A8 0x10A8
#define Scr_0x10A9 0x10A9
#define Scr_0x10AA 0x10AA
#define Scr_0x10AB 0x10AB
#define Scr_0x10AC 0x10AC
#define Scr_0x10AD 0x10AD
#define Scr_CutsceneZajiWakeFreeze 0x10AE      // 寝ているザジを起こすカットシーン, 水の祝福でフリーズを覚える
#define Scr_0x10AF 0x10AF
#define Scr_CutsceneZajiWakeFreeze2 0x10B0     // Scr_CutsceneZajiWakeFreeze の進行度32以降版
#define Scr_0x10B1 0x10B1
#define Scr_CutsceneZajiLearnFreeze 0x10B4     // ザジにフリーズを教わるカットシーン (起こす件なし)
#define Scr_0x10B5 0x10B5
#define Scr_0x10B6 0x10B6
#define Scr_0x10B7 0x10B7
#define Scr_0x10B8 0x10B8
#define Scr_0x10B9 0x10B9
#define Scr_0x10BA 0x10BA
#define Scr_0x10BB 0x10BB
#define Scr_0x10BC 0x10BC
#define Scr_0x10BD 0x10BD
#define Scr_0x10BE 0x10BE
#define Scr_0x10BF 0x10BF
#define Scr_0x10C0 0x10C0
#define Scr_0x10C1 0x10C1
#define Scr_0x10C2 0x10C2
#define Scr_0x10C3 0x10C3
#define Scr_0x10C4 0x10C4
#define Scr_0x10C5 0x10C5
#define Scr_0x10C6 0x10C6
#define Scr_0x10C7 0x10C7
#define Scr_0x10C8 0x10C8
#define Scr_0x10C9 0x10C9
#define Scr_0x10CA 0x10CA
#define Scr_0x10CB 0x10CB
#define Scr_0x10CC 0x10CC
#define Scr_0x10CD 0x10CD
#define Scr_0x10CE 0x10CE
#define Scr_0x10CF 0x10CF
#define Scr_0x10D0 0x10D0
#define Scr_0x10D1 0x10D1
#define Scr_0x10D2 0x10D2
#define Scr_0x10D3 0x10D3
#define Scr_0x13E8 0x13E8
#define Scr_0x13EA 0x13EA
#define Scr_0x13EB 0x13EB
#define Scr_0x13EC 0x13EC
#define Scr_0x13ED 0x13ED
#define Scr_GuideSunlightControl 0x13F0        // ヒント看板「太陽の光をコントロールせよ。」
#define Scr_0x13F1 0x13F1
#define Scr_0x13F2 0x13F2
#define Scr_GetKuroState 0x13F4                // クロの状態を返す, 1: 倉庫の前で威嚇, 2: 包帯を巻いて威嚇, 0: それ以外
#define Scr_0x13F6 0x13F6
#define Scr_0x13F7 0x13F7
#define Scr_0x13F8 0x13F8
#define Scr_LibraryRecordBookSealed 0x13F9     // 調査記録の本がまだ封印されている
#define Scr_LibraryTitleBookSealed 0x13FA      // 称号の本がまだ封印されている
#define Scr_QuestFailed 0x13FB                 // 依頼失敗の処理, レディが気づかう
#define Scr_0x13FC 0x13FC
#define Scr_0x13FD 0x13FD
#define Scr_BPantherCheckBestScore 0x1404
#define Scr_BPantherResult 0x1405          // ブラックパンサーの終了後にハイスコアを更新して結果を表示する
#define Scr_0x1406 0x1406
#define Scr_0x1407 0x1407
#define Scr_GuideElementCube2 0x1409           // Scr_GuideElementCube と同じ文の別の部屋のヒント看板
#define Scr_0x171F 0x171F
#define Scr_0x1720 0x1720
#define Scr_0x1721 0x1721
#define Scr_ArenaRankAnnounce 0x1722           // 闘技場で選んだランク (ブロンズ〜プラチナ) に「挑みます」と表示する
#define Scr_0x1723 0x1723
#define Scr_0x1724 0x1724
#define Scr_0x1727 0x1727
#define Scr_KuroTalkAnimStart 0x1728           // 会話中のクロのアニメに切り替える, 通常と包帯の両方
#define Scr_RitaAffectionEvent 0x172B          // リタの好感度イベント, 吸血ジャンゴには血を差し出す
#define Scr_0x172D 0x172D
#define Scr_0x172E 0x172E
#define Scr_0x172F 0x172F
#define Scr_0x1731 0x1731
#define Scr_0x1732 0x1732
#define Scr_0x1734 0x1734
#define Scr_0x1735 0x1735
#define Scr_0x1736 0x1736
#define Scr_0x1739 0x1739
#define Scr_0x173A 0x173A
#define Scr_CreateElevatorEx 0x173D  // Scr_CreateElevator に '.m' (p8) を足した版
#define Scr_KuroTalkAnimEnd 0x173F             // クロのアニメを通常に戻す
#define Scr_0x1740 0x1740
#define Scr_OnMugenTrapPanelStepped 0x1741  // 夢幻街のトラップパネルを踏んだとき, 区画の仕掛けの種類 (W_MUGEN_BLOCK_EVENT) で効果を出す, 1: 警報 (プレイヤーなら鉄格子を20秒閉じる), 2: 鉄球落下 (当たると最大HP分のダメージ), 3: 大爆発 (威力9999), 4〜6: 状態異常, 7〜9: 良い効果, 10: カギ落下 (□のカギを落とす), p9: 踏んだもの
#define Scr_OnMugenTrapPanelLeft 0x1742  // 夢幻街のトラップパネルから離れたとき, 何もしない
#define Scr_PlaceMugenTrapPanel 0x1743  // 夢幻街の区画にトラップパネルを置く, p0: 種類
#define Scr_SetupRTC 0x1A62 // 太陽センサーの説明と時間合わせ (セーブデータがない or RTCが設定されていないときにこのスクリプトが呼ばれる)
#define Scr_0x1D7E 0x1D7E
#define Scr_0x1D7F 0x1D7F
#define Scr_0x209B 0x209B
#define Scr_0x23BA 0x23BA
#define Scr_0x23BB 0x23BB
#define Scr_0x26D8 0x26D8
#define Scr_0x26D9 0x26D9
#define Scr_0x29F5 0x29F5
#define Scr_0x2D11 0x2D11
#define Scr_0x2D12 0x2D12
#define Scr_0x2D13 0x2D13

#endif // __DATA_SCRIPTS_SCRIPT_H__
