#ifndef __DATA_SCRIPTS_SCRATCH_H__
#define __DATA_SCRIPTS_SCRATCH_H__

// data/scripts/scripts.bokc で include する用, scratch 領域 (include/vm_memory.h の Scratch) の名前の付いたメンバ
// 名前はメンバ名を大文字にしたもの, すべて S_ を付ける
// 中身は .bokc のメモリ参照の綴りそのままにする (ダンパーはこの綴りと完全に一致する参照だけを名前で出す), 外側を括弧で囲まないこと

#define S_HOUR *((s16 *)(scratch + 0x0))  // 現在の時
#define S_MINUTE *((s16 *)(scratch + 0x2))  // 現在の分
#define S_SECOND *((s16 *)(scratch + 0x4))  // 現在の秒
#define S_ROOM_BATTLE_BGM *((s16 *)(scratch + 0x6))  // 閉じ込め戦闘のミッション文を閉じたあとに鳴らす曲, 既定 13
#define S_PREV_DEBTS *((s32 *)(scratch + 0x8))  // 前回確認したときの暗黒ローンの借金額
#define S_YEAR *((s16 *)(scratch + 0xC))  // 今日の年
#define S_MONTH *((s16 *)(scratch + 0xE))  // 今日の月
#define S_DAY *((s16 *)(scratch + 0x10))  // 今日の日
#define S_ELAPSED_DAYS *((s16 *)(scratch + 0x12))  // 前回日付を確認した日からの経過日数
#define S_EXIT_ARROW_COLOR *((u8 *)(scratch + 0x15))  // 出口の矢印の色, 4 以上なら矢印を出さない
#define S_MAP_FADE_COLOR *((u8 *)(scratch + 0x16))  // マップの出入りでフェードする色, 0: 黒, 1: 白
#define S_MAP_FADE_FRAMES *((s16 *)(scratch + 0x18))  // マップの出入りのフェードのフレーム数, 既定 16
#define S_TILE_ATTR *((s16 *)(scratch + 0x1A))  // (x, z) のタイル属性, 一時値
#define S_TMP_POS_Y *((s16 *)(scratch + 0x1C))  // 汎用の一時座標の y (高さ), 並びは y, x, z
#define S_TMP_POS_X *((s16 *)(scratch + 0x1E))  // 汎用の一時座標の x
#define S_TMP_POS_Z *((s16 *)(scratch + 0x20))  // 汎用の一時座標の z
#define S_ZONE_CENTER_X *((s16 *)(scratch + 0x22))  // Cmd_GetZoneBounds で得たゾーン中心の x
#define S_ZONE_CENTER_Z *((s16 *)(scratch + 0x24))  // ゾーン中心の z
#define S_ZONE_MIN_X *((s16 *)(scratch + 0x26))  // ゾーンの x の最小
#define S_ZONE_MAX_X *((s16 *)(scratch + 0x28))  // ゾーンの x の最大
#define S_ZONE_MIN_Z *((s16 *)(scratch + 0x2A))  // ゾーンの z の最小
#define S_ZONE_MAX_Z *((s16 *)(scratch + 0x2C))  // ゾーンの z の最大
#define S_EVENT_STEP *((u8 *)(scratch + 0x2E))  // イベント (Cmd_Delay の連鎖) の段階カウンタ
#define S_CUTSCENE_STEP *((u8 *)(scratch + 0x2F))  // 演出 (Scr_Cutscene* など) の段階カウンタ
#define S_CURRENT_BGM *((s16 *)(scratch + 0x30))  // 今鳴らしている BGM の曲番号
#define S_WALK_TARGET_X *((s16 *)(scratch + 0x32))  // 出入口でプレイヤーを自動で歩かせる先の x
#define S_ENTRANCE_CALLBACK *((s32 *)(scratch + 0x34))  // 入口からの登場が終わったら呼ぶスクリプト, 0 なら無し
#define S_WALK_TARGET_Z *((s16 *)(scratch + 0x38))  // 出入口でプレイヤーを自動で歩かせる先の z
#define S_EXIT_DIR *((s16 *)(scratch + 0x3A))  // 出口ゾーンから出ていく向き (1/3/5/7)
#define S_UNK_03C *((u16 *)(scratch + 0x3C))
#define S_UNK_03E *((u8 *)(scratch + 0x3E))
#define S_UNK_03F *((u8 *)(scratch + 0x3F))
#define S_ZONE_OFFSET_X *((s16 *)(scratch + 0x40))  // ゾーンの左端からのプレイヤーの x のずれ
#define S_ZONE_OFFSET_Z *((s16 *)(scratch + 0x42))  // ゾーンの手前端からのプレイヤーの z のずれ
#define S_TILE_STAIRS *((u8 *)(scratch + 0x44))  // プレイヤー位置のタイルの階段の種類
#define S_SPAN_OF_TIME *((u8 *)(scratch + 0x45))  // 時間帯 (TIMESPAN_*)
#define S_ZONE_MIN_Y *((s16 *)(scratch + 0x46))  // ゾーンの高さの最小 (ゾーンの z1 * 16)
#define S_ZONE_MAX_Y *((s16 *)(scratch + 0x48))  // ゾーンの高さの最大 (ゾーンの z2 * 16)
#define S_ZONE_CENTER_Y *((s16 *)(scratch + 0x4A))  // ゾーンの高さの中心
#define S_MAP_BG_FLAGS *((s16 *)(scratch + 0x4C))  // マップの BG の BgMapScrollerFlags
#define S_UNK_04F *((u8 *)(scratch + 0x4F))
#define S_UNK_050 *((u16 *)(scratch + 0x50))
#define S_FADE_SPEED *((u8 *)(scratch + 0x52))  // フェード速度, フレーム数の log2
#define S_FADE_R *((u8 *)(scratch + 0x53))  // フェード色の R (0〜31)
#define S_FADE_G *((u8 *)(scratch + 0x54))  // フェード色の G (0〜31)
#define S_FADE_B *((u8 *)(scratch + 0x55))  // フェード色の B (0〜31)
#define S_FADE_KIND *((u8 *)(scratch + 0x56))  // Entity6978 に渡すフェードの種類 (1〜4)
#define S_EMBLEM_SHUTTER_COUNT *((u8 *)(scratch + 0x57))  // 紋章ブロックの仕掛けで開く扉の数 (0〜2)
#define S_EMBLEM_LIT_COUNT *((u8 *)(scratch + 0x58))  // 光っている紋章ブロックの数
#define S_EMBLEM_REQUIRED *((u8 *)(scratch + 0x59))  // 扉が開くのに必要な紋章ブロックの数
#define S_EMBLEM_OPEN_STEP *((u8 *)(scratch + 0x5A))  // 紋章ブロックの仕掛けが解けたときの扉を開く演出の段階
#define S_PITFALL_COUNT *((u8 *)(scratch + 0x5B))  // 置いた落とし穴の数, 次の落とし穴の番号になる
#define S_SKYLIGHT_COUNT *((u8 *)(scratch + 0x5C))  // 置いたオブジェ天窓の数 (最大 11)
#define S_UNK_05D *((u8 *)(scratch + 0x5D))
#define S_ENEMY_DROP_A *((s16 *)(scratch + 0x5E))  // 敵が落とす物1, 下位8bit: ID
#define S_ENEMY_DROP_B *((s16 *)(scratch + 0x60))  // 敵が落とす物2, 下位8bit: ID
#define S_ROLLED_DROP *((s16 *)(scratch + 0x62))  // 抽選で決まった落とし物, 外れなら -1
#define S_CHEST_DIR *((u8 *)(scratch + 0x64))  // 置く宝箱の向き
#define S_CHEST_AUTO_DIR *((u8 *)(scratch + 0x65))  // 地形から決めた宝箱の向き (0/1)
#define S_CHEST_POS_X *((s16 *)(scratch + 0x66))  // 地形に合わせて補正した宝箱の x
#define S_CHEST_POS_Z *((s16 *)(scratch + 0x68))  // 地形に合わせて補正した宝箱の z
#define S_CHEST_SIDE_HEIGHT *((s16 *)(scratch + 0x6A))  // 宝箱の隣のタイルの高さ, 補正判定用の一時値
#define S_ROOM_LIGHT_COUNT *((u8 *)(scratch + 0x6C))  // 部屋を照らしている明かりの数, 0 になると部屋を暗くする
#define S_ROOM_LIGHT_STATE *((u8 *)(scratch + 0x6D))  // 部屋の明るさの状態, 1: 暗い, 2: 明るい
#define S_UNK_06E *((u8 *)(scratch + 0x6E))
#define S_UNK_06F *((u8 *)(scratch + 0x6F))
#define S_UNK_070 *((u8 *)(scratch + 0x70))
#define S_UNK_072 *((u8 *)(scratch + 0x72))
#define S_UNK_073 *((u8 *)(scratch + 0x73))
#define S_UNK_074 *((u8 *)(scratch + 0x74))
#define S_UNK_075 *((u8 *)(scratch + 0x75))
#define S_ROOM_BATTLE_KILLS *((u8 *)(scratch + 0x76))  // 閉じ込め戦闘で倒した数
#define S_ROOM_BATTLE_TARGET *((u8 *)(scratch + 0x77))  // 閉じ込め戦闘で倒すべき数
#define S_ROOM_BATTLE_SHUTTER_COUNT *((u8 *)(scratch + 0x78))  // 閉じ込め戦闘用に置いた扉の数 (最大 4)
#define S_ROOM_MISSION_LINE *((u8 *)(scratch + 0x79))  // 閉じ込め戦闘のミッション文の行
#define S_ROOM_BATTLE_CLEAR_STEP *((u8 *)(scratch + 0x82))  // 閉じ込め戦闘を終えて扉を開ける演出の段階
#define S_UNK_083 *((u8 *)(scratch + 0x83))
#define S_BGM_BEFORE_ROOM_BATTLE *((s16 *)(scratch + 0x84))  // 閉じ込め戦闘の前に鳴っていた BGM, 戦闘後に戻す
#define S_UNK_086 *((u8 *)(scratch + 0x86))
#define S_UNK_087 *((u8 *)(scratch + 0x87))
#define S_SPIRIT_BUG_WEIGHT0 *((u8 *)(scratch + 0x88))  // 精霊虫の種類0の重み
#define S_SPIRIT_BUG_WEIGHT1 *((u8 *)(scratch + 0x89))  // 精霊虫の種類1の重み
#define S_SPIRIT_BUG_KIND *((u8 *)(scratch + 0x8A))  // 抽選で決まった精霊虫の種類
#define S_UNK_08B *((u8 *)(scratch + 0x8B))
#define S_SUN_GAUGE *((u8 *)(scratch + 0x8C))  // 太陽ゲージの現在値 (変化の検出用)
#define S_PREV_SUN_GAUGE *((u8 *)(scratch + 0x8D))  // 前のフレームの太陽ゲージ
#define S_UNK_08E *((u8 *)(scratch + 0x8E))
#define S_UNK_08F *((u8 *)(scratch + 0x8F))
#define S_UNK_090 *((s16 *)(scratch + 0x90))
#define S_UNK_092 *((s16 *)(scratch + 0x92))
#define S_UNK_094 *((s16 *)(scratch + 0x94))
#define S_UNK_096 *((s16 *)(scratch + 0x96))
#define S_DAY_DIFF *((s16 *)(scratch + 0x98))  // Cmd_GetDayDiff の出力, 一時値
#define S_SUNRISE_HOUR *((s16 *)(scratch + 0x9A))  // 日の出の時
#define S_SUNRISE_MINUTE *((s16 *)(scratch + 0x9C))  // 日の出の分
#define S_UNTIL_SUNRISE_HOUR *((s16 *)(scratch + 0x9E))  // 日の出までの残り時間 (時)
#define S_UNTIL_SUNRISE_MINUTE *((s16 *)(scratch + 0xA0))  // 日の出までの残り時間 (分)
#define S_SUNSET_HOUR *((s16 *)(scratch + 0xA2))  // 日の入りの時
#define S_SUNSET_MINUTE *((s16 *)(scratch + 0xA4))  // 日の入りの分
#define S_UNTIL_SUNSET_HOUR *((s16 *)(scratch + 0xA6))  // 日の入りまでの残り時間 (時)
#define S_UNTIL_SUNSET_MINUTE *((s16 *)(scratch + 0xA8))  // 日の入りまでの残り時間 (分)
#define S_CLEARED_REQUEST_COUNT *((u8 *)(scratch + 0xAA))  // 済ませた依頼の数
#define S_REQUEST_IDX *((u8 *)(scratch + 0xAB))  // 依頼番号のループ添字
#define S_UNK_0AC *((u8 *)(scratch + 0xAC))
#define S_UNK_0AD *((u8 *)(scratch + 0xAD))
#define S_ARMOR_DEX_COUNT *((u8 *)(scratch + 0xAE))  // 取得済みの防具の数
#define S_ARMOR_DEX_IDX *((u8 *)(scratch + 0xAF))  // armorDexCount を数えるループ添字
#define S_WEAPON_DEX_COUNT *((u8 *)(scratch + 0xB0))  // 取得済みの武器の数
#define S_WEAPON_DEX_IDX *((u8 *)(scratch + 0xB1))  // weaponDexCount を数えるループ添字
#define S_ENEMY_DEX_COUNT *((u8 *)(scratch + 0xB2))  // 魔物図鑑で出会った敵の数
#define S_ENEMY_DEX_IDX *((u8 *)(scratch + 0xB3))  // enemyDexCount を数えるループ添字
#define S_PHOTO_COUNT *((u8 *)(scratch + 0xB4))  // 取得済みのブロマイドの数
#define S_PHOTO_IDX *((u8 *)(scratch + 0xB5))  // photoCount を数えるループ添字
#define S_IMMORTAL_RESEARCHED *((u8 *)(scratch + 0xB6))  // 調査済みのイモータルダンジョンの数 (/6)
#define S_UNDEAD_RESEARCHED *((u8 *)(scratch + 0xB7))  // 調査済みのアンデッドダンジョンの数 (/7)
#define S_TITLE_COUNT *((u8 *)(scratch + 0xB8))  // 獲得した称号の数 (/12)
#define S_ENEMY_ATK0_POWER *((s16 *)(scratch + 0xBA))  // 敵の攻撃0の威力
#define S_ENEMY_ATK1_POWER *((s16 *)(scratch + 0xBC))  // 敵の攻撃1の威力
#define S_ENEMY_ATK2_POWER *((s16 *)(scratch + 0xBE))  // 敵の攻撃2の威力
#define S_ENEMY_ATK3_POWER *((s16 *)(scratch + 0xC0))  // 敵の攻撃3の威力
#define S_ENEMY_RANGE0 *((s16 *)(scratch + 0xC2))  // 敵の索敵距離
#define S_ENEMY_RANGE3 *((s16 *)(scratch + 0xC4))  // 敵の Enemy_SetRanges の第6引数
#define S_UNK_0C6 *((s16 *)(scratch + 0xC6))
#define S_ENEMY_SLEEP_TIME *((s16 *)(scratch + 0xC8))  // 敵の眠り時間
#define S_ENEMY_FLAGS5 *((s16 *)(scratch + 0xCA))  // 敵の EnemyFlags5 ('.M')
#define S_UNK_0CC *((s16 *)(scratch + 0xCC))
#define S_ENEMY_ATK0_KNOCKBACK *((s16 *)(scratch + 0xCE))  // 敵の攻撃0のふっとばし
#define S_ENEMY_ATK_KNOCKBACK *((s16 *)(scratch + 0xD0))  // 敵の攻撃1以降に共通のふっとばし
#define S_ENEMY_ATK1_IFRAMES *((s16 *)(scratch + 0xD2))  // 敵の攻撃1の無敵フレーム
#define S_ENEMY_ATK1_ATTRS *((s32 *)(scratch + 0xD4))  // 敵の攻撃1の HitboxAttributes
#define S_ENEMY_ATK0_ATTRS *((s16 *)(scratch + 0xD8))  // 敵の攻撃0の HitboxAttributes
#define S_ENEMY_ATK0_IFRAMES *((s16 *)(scratch + 0xDA))  // 敵の攻撃0の無敵フレーム
#define S_ENEMY_MAX_HP *((s16 *)(scratch + 0xDC))  // 敵の最大 HP ('.A[0]')
#define S_ENEMY_POWER *((s16 *)(scratch + 0xDE))  // 敵の体当たりの力 (Enemy.power, '.A[1]')
#define S_UNK_0E0 *((s16 *)(scratch + 0xE0))
#define S_ENEMY_ATTRS *((s16 *)(scratch + 0xE2))  // 敵の食らい判定の属性
#define S_ENEMY_WEAKNESS *((s16 *)(scratch + 0xE4))  // 敵の弱点 (Enemy.weakness, '.A[5]')
#define S_ENEMY_CHASE_TIME_MAX *((s16 *)(scratch + 0xE6))  // 敵の追跡時間の上限
#define S_ENEMY_RANGE2 *((s16 *)(scratch + 0xE8))  // 敵の range2 ('.n[0]')
#define S_ENEMY_EXP *((s16 *)(scratch + 0xEA))  // 倒したときの経験値 (Enemy.exp, '.X[0]')
#define S_ENEMY_WEAPON_EXP *((s16 *)(scratch + 0xEC))  // 倒したときの武器経験値
#define S_UNK_0EE *((u8 *)(scratch + 0xEE))
#define S_ENEMY_VARIANT *((u8 *)(scratch + 0xEF))  // 敵の変種 (Enemy.variant, '.C')
#define S_UNK_0F0 *((s16 *)(scratch + 0xF0))
#define S_UNK_0F2 *((s16 *)(scratch + 0xF2))
#define S_UNK_0F4 *((s16 *)(scratch + 0xF4))
#define S_UNK_0F6 *((s16 *)(scratch + 0xF6))
#define S_UNK_0F8 *((s16 *)(scratch + 0xF8))
#define S_ENEMY_ATK2_IFRAMES *((s16 *)(scratch + 0xFA))  // 敵の攻撃2の無敵フレーム
#define S_ENEMY_ATK2_ATTRS *((s32 *)(scratch + 0xFC))  // 敵の攻撃2の HitboxAttributes
#define S_ENEMY_ATK3_ATTRS *((s32 *)(scratch + 0x100))  // 敵の攻撃3の HitboxAttributes
#define S_ENEMY_ATK3_IFRAMES *((s16 *)(scratch + 0x104))  // 敵の攻撃3の無敵フレーム
#define S_UNK_106 *((s16 *)(scratch + 0x106))
#define S_UNK_108 *((s16 *)(scratch + 0x108))
#define S_UNK_10A *((s16 *)(scratch + 0x10A))
#define S_UNK_10C *((u16 *)(scratch + 0x10C))
#define S_ENEMY_ATK4_POWER *((s16 *)(scratch + 0x10E))  // 敵の攻撃4の威力
#define S_ENEMY_ATK4_ATTRS *((s32 *)(scratch + 0x110))  // 敵の攻撃4の HitboxAttributes
#define S_ENEMY_ATK4_IFRAMES *((s16 *)(scratch + 0x114))  // 敵の攻撃4の無敵フレーム
#define S_UNK_116 *((s16 *)(scratch + 0x116))
#define S_UNK_118 *((s16 *)(scratch + 0x118))
#define S_TILE_HEIGHT *((s16 *)(scratch + 0x11A))  // Cmd_0CD4 で取った (x, z) のタイルの足元の高さ
#define S_UNK_11C *((u8 *)(scratch + 0x11C))
#define S_LOTTERY_ROLL *((u8 *)(scratch + 0x11D))  // 抽選用の乱数 0〜99
#define S_NODE_POS_X *((s16 *)(scratch + 0x11E))  // Cmd_GetPathNodePos で取った経路ノードの x
#define S_NODE_POS_Y *((s16 *)(scratch + 0x120))  // 経路ノードの y
#define S_NODE_POS_Z *((s16 *)(scratch + 0x122))  // 経路ノードの z
#define S_LOTTERY_WEIGHT_SUM *((u8 *)(scratch + 0x124))  // 抽選の重みの累計
#define S_UNK_125 *((u8 *)(scratch + 0x125))
#define S_MAP_EVENT_STEP *((u8 *)(scratch + 0x126))  // マップ固有のイベントの段階番号
#define S_PUSH_BACK_DIR *((u8 *)(scratch + 0x127))  // プレイヤーを押し戻す方向 (8方向 0〜7, 255 で無し)
#define S_SABATA_TALK_TOGGLE *((u8 *)(scratch + 0x128))  // サバタの2種類の台詞を交互に出すトグル
#define S_TORTURE_STEP *((u8 *)(scratch + 0x12C))  // 暗黒ローンのおしおき (発電) の進行段階
#define S_TORTURE_PATTERN *((u8 *)(scratch + 0x12E))  // おしおきの発電パターン 0〜3
#define S_UNK_12F *((u8 *)(scratch + 0x12F))
#define S_UNK_130 *((s16 *)(scratch + 0x130))
#define S_SPAWN_AREA_MIN_X *((s16 *)(scratch + 0x132))  // 敵を湧かせる範囲 (ゾーン) の x の最小
#define S_SPAWN_AREA_MIN_Z *((s16 *)(scratch + 0x134))  // 敵を湧かせる範囲の z の最小
#define S_SPAWN_AREA_MAX_X *((s16 *)(scratch + 0x136))  // 敵を湧かせる範囲の x の最大
#define S_SPAWN_AREA_MAX_Z *((s16 *)(scratch + 0x138))  // 敵を湧かせる範囲の z の最大
#define S_UNK_13A *((u8 *)(scratch + 0x13A))
#define S_MAP_TILE_MAP_ID *((u16 *)(scratch + 0x13C))  // 今のマップで読み込んだタイルマップのファイル ID
#define S_BOOKSHELF_NO *((u8 *)(scratch + 0x13E))  // 最後に調べた本棚の番号 1〜10
#define S_UNK_140 *((u8 *)(scratch + 0x140))
#define S_UNK_141 *((u8 *)(scratch + 0x141))
#define S_UNK_143 *((u8 *)(scratch + 0x143))
#define S_UNK_144 *((s16 *)(scratch + 0x144))
#define S_UNK_146 *((u8 *)(scratch + 0x146))
#define S_SPAN_OF_TIME2 *((u8 *)(scratch + 0x147))  // 時間帯, spanOfTime の別の置き場
#define S_UNK_148 *((u8 *)(scratch + 0x148))
#define S_MAP_EVENT_STEP2 *((u8 *)(scratch + 0x149))  // マップ固有のイベントの段階番号2
#define S_FRAGMENT_HINT_IDX *((u8 *)(scratch + 0x14A))  // 石版のかけらのヒントの番号
#define S_CANDLE_HINT_LEVEL *((u8 *)(scratch + 0x14B))  // 燭台パズルのメッセージの段階 0〜4
#define S_CANDLE_MEMO_READS *((u8 *)(scratch + 0x14C))  // 燭台パズルのメッセージを読んだ回数
#define S_CANDLE_LIT_COUNT *((u8 *)(scratch + 0x14D))  // 灯した燭台の数 0〜4
#define S_CANDLE_ORDER(i) ((u8 *)(scratch + 0x14E))[4, i]  // 燭台を灯した順番 (燭台番号 1〜4)
#define S_DARK_CITY_BGM *((s16 *)(scratch + 0x152))  // 暗黒街で鳴らす BGM 番号 29〜33
#define S_UNK_154 *((u8 *)(scratch + 0x154))
#define S_UNK_155 *((u8 *)(scratch + 0x155))
#define S_UNK_156 *((u8 *)(scratch + 0x156))
#define S_UNK_157 *((u8 *)(scratch + 0x157))
#define S_UNK_159 *((u8 *)(scratch + 0x159))
#define S_UNK_15A *((u8 *)(scratch + 0x15A))
#define S_UNK_15B *((u8 *)(scratch + 0x15B))
#define S_ACTOR_POS_X *((s16 *)(scratch + 0x15C))  // NPC (Actor) を置く位置 x
#define S_ACTOR_POS_Y *((s16 *)(scratch + 0x15E))  // NPC を置く位置 y
#define S_ACTOR_POS_Z *((s16 *)(scratch + 0x160))  // NPC を置く位置 z
#define S_ACTOR_ANGLE *((s16 *)(scratch + 0x162))  // NPC の向き (角度 0〜255)
#define S_ACTOR_INIT_MODE *((s16 *)(scratch + 0x164))  // NPC の初期状態, 0: 立ち, 1: 非表示, 2: 経路を歩く
#define S_UNK_166 *((u8 *)(scratch + 0x166))
#define S_UNK_167 *((u8 *)(scratch + 0x167))
#define S_UNK_169 *((u8 *)(scratch + 0x169))
#define S_UNK_16A *((u8 *)(scratch + 0x16A))
#define S_UNK_16C *((s16 *)(scratch + 0x16C))
#define S_UNK_16E *((s16 *)(scratch + 0x16E))
#define S_UNK_170 *((s16 *)(scratch + 0x170))
#define S_UNK_172 *((u8 *)(scratch + 0x172))
#define S_UNK_173 *((u8 *)(scratch + 0x173))
#define S_UNK_174 *((u8 *)(scratch + 0x174))
#define S_UNK_175 *((u8 *)(scratch + 0x175))
#define S_UNK_176 *((s16 *)(scratch + 0x176))
#define S_UNK_178 *((s16 *)(scratch + 0x178))
#define S_ZAJI_SMALL_TALK_COUNT *((u8 *)(scratch + 0x17A))  // ザジの雑談2種類を交互に出すカウンタ
#define S_PREFECTURE_NO *((u8 *)(scratch + 0x17B))  // 登録した都道府県の番号
#define S_SMITH_INJURED_TALK_TOGGLE *((u8 *)(scratch + 0x17C))  // 負傷中のスミスの台詞を交互に出すトグル
#define S_SUMIRE_TOWN_TALK_COUNT *((u8 *)(scratch + 0x17D))  // 太陽街のスミレの台詞を交互に出すカウンタ
#define S_KURO_OUTSIDE_TALK_TOGGLE *((u8 *)(scratch + 0x17E))  // 屋外のクロの台詞を交互に出すトグル
#define S_LUIS_TALK_COUNT *((u8 *)(scratch + 0x17F))  // ルイスの雑談を交互に出すカウンタ
#define S_MARCELLO_TALK_COUNT *((u8 *)(scratch + 0x180))  // マルチェロの雑談を交互に出すカウンタ
#define S_UNK_181 *((u8 *)(scratch + 0x181))
#define S_NOW_MINUTES *((s16 *)(scratch + 0x182))  // 現在時刻を分で表した値 (時 * 60 + 分)
#define S_SUNRISE_MINUTES *((s16 *)(scratch + 0x184))  // 日の出時刻を分で表した値
#define S_SUNSET_MINUTES *((s16 *)(scratch + 0x186))  // 日の入り時刻を分で表した値
#define S_ARMOR_CANDIDATE_COUNT *((u8 *)(scratch + 0x188))  // クロスオーバー交換の防具候補の数
#define S_OWNED_ARMOR_PICK *((u8 *)(scratch + 0x189))  // 取得済み防具から1つ選ぶための乱数 (何番目か)
#define S_ARMOR_CANDIDATE_PICK *((u8 *)(scratch + 0x18A))  // 防具候補 0〜5 から選んだ添字
#define S_OWNED_ARMOR_IDX *((u8 *)(scratch + 0x18B))  // 取得済み防具を数えながら走査するカウンタ
#define S_PICKED_OWNED_ARMOR *((u8 *)(scratch + 0x18C))  // ownedArmorPick 番目の取得済み防具の ID
#define S_EXCHANGE_ARMOR *((u8 *)(scratch + 0x18D))  // クロスオーバーポイントと交換で渡す防具の ID
#define S_KURO_HOUSE_TALK_TOGGLE *((u8 *)(scratch + 0x18E))  // 家の中のクロの台詞を交互に出すトグル
#define S_SAVED_PLAYER_DIR *((s16 *)(scratch + 0x190))  // 会話の前に保存したプレイヤーの向き, 会話のあとで向きを戻す
#define S_UNK_192 *((u8 *)(scratch + 0x192))
#define S_RITA_TALK_LOOP_LEN *((u8 *)(scratch + 0x193))  // リタの台詞ループの長さ (進行度で決まる)
#define S_RITA_TALK_COUNT *((u8 *)(scratch + 0x194))  // リタとの会話の回数
#define S_SUMIRE_SMALL_TALK_COUNT *((u8 *)(scratch + 0x195))  // スミレの雑談を交互に出すカウンタ
#define S_SMITH_SMALL_TALK_COUNT *((u8 *)(scratch + 0x196))  // スミスの雑談を交互に出すカウンタ
#define S_ASTRO_WEAPON_ID *((u8 *)(scratch + 0x197))  // もらうアストロ武器の武器 ID
#define S_LICENSE_ELIGIBLE_COUNT *((u8 *)(scratch + 0x198))  // 熟練度 5000 以上で紋章を持っていない武器タイプの数
#define S_SMITH_LICENSE_TYPE *((u8 *)(scratch + 0x199))  // 限定解除の対象の武器タイプ
#define S_LICENSE_TALK_COUNT *((u8 *)(scratch + 0x19A))  // 限定解除の会話を巡回させるカウンタ
#define S_FOUND_ARMOR_COUNT *((u8 *)(scratch + 0x19B))  // 見つけた防具の数
#define S_UPTIME_DAYS *((s16 *)(scratch + 0x19C))  // 総合記録の稼働時間の日
#define S_UPTIME_MIN_TENS *((s16 *)(scratch + 0x19E))  // 稼働時間の分の十の位
#define S_UPTIME_MIN_ONES *((s16 *)(scratch + 0x1A0))  // 稼働時間の分の一の位
#define S_PLAY_TIME_HOURS *((s16 *)(scratch + 0x1A2))  // プレイタイムの時 (99 まで)
#define S_PLAY_TIME_MINUTES *((s16 *)(scratch + 0x1A4))  // プレイタイムの分
#define S_PLAY_TIME_HOUR_TENS *((s16 *)(scratch + 0x1A6))  // プレイタイムの時の十の位
#define S_PLAY_TIME_HOUR_ONES *((s16 *)(scratch + 0x1A8))  // プレイタイムの時の一の位
#define S_PLAY_TIME_MIN_TENS *((s16 *)(scratch + 0x1AA))  // プレイタイムの分の十の位
#define S_PLAY_TIME_MIN_ONES *((s16 *)(scratch + 0x1AC))  // プレイタイムの分の一の位
#define S_CROSSOVER_POINT *((s16 *)(scratch + 0x1AE))  // クロスオーバーポイント (記録の表示用)
#define S_CROSSOVER_BATTLE_COUNT *((s16 *)(scratch + 0x1B0))  // クロスオーバーバトルの対戦数
#define S_CROSSOVER_BATTLE_WINS *((s16 *)(scratch + 0x1B2))  // クロスオーバーバトルの勝利数
#define S_CLAMP_RESULT *((s32 *)(scratch + 0x1B4))  // Scr_ClampValue の作業値, 0..p1 に丸めた値
#define S_MSG_VAR_VALUE *((s32 *)(scratch + 0x1B8))  // 丸めてからメッセージ変数に入れる値
#define S_TREASURE_REQUEST_PLACE *((u8 *)(scratch + 0x1BC))  // 財宝探しの依頼場所
#define S_TREASURE_REQUEST_NO *((u8 *)(scratch + 0x1BD))  // 財宝探しの依頼番号 0〜2
#define S_LADY_RUMOR_COUNT *((u8 *)(scratch + 0x1BE))  // レディの噂話7種類を順に出すカウンタ
#define S_LADY_SMALL_TALK_COUNT *((u8 *)(scratch + 0x1BF))  // レディの世間話を交互に出すカウンタ
#define S_UNK_1C0 *((s32 *)(scratch + 0x1C0))
#define S_UNK_1C4 *((s32 *)(scratch + 0x1C4))
#define S_UNK_1C8 *((u8 *)(scratch + 0x1C8))
#define S_SUN_TREE_STAGE *((u8 *)(scratch + 0x1C9))  // 太陽樹の成長段階 0〜6
#define S_ENNIO_CLOCK_DAYS *((s16 *)(scratch + 0x1CA))  // エンニオの時計合わせから経った日数
#define S_UNK_1CC *((s16 *)(scratch + 0x1CC))
#define S_UNK_1CE *((s16 *)(scratch + 0x1CE))
#define S_UNK_1D0 *((u8 *)(scratch + 0x1D0))
#define S_RITA_TREE_TALK_COUNT *((u8 *)(scratch + 0x1D1))  // 太陽樹の前でのリタとの会話の回数
#define S_ZAJI_SABATA_TALK_COUNT *((u8 *)(scratch + 0x1D2))  // サバタ操作中のザジの台詞を交互に出すカウンタ
#define S_RITA_SABATA_TALK_COUNT *((u8 *)(scratch + 0x1D3))  // サバタ操作中のリタの台詞を交互に出すカウンタ
#define S_ZAJI_TALK_COUNT2 *((u8 *)(scratch + 0x1D4))  // 別の太陽街マップのザジの台詞を巡回させるカウンタ
#define S_TAROT_CARD_COUNT *((u8 *)(scratch + 0x1D5))  // 持っているタロットカード (魔術師/教皇/隠者) の枚数
#define S_UNK_1D6 *((s16 *)(scratch + 0x1D6))
#define S_RESIDENT_TALK_COUNT2 *((u8 *)(scratch + 0x1D9))  // ルイスとマルチェロの雑談2を交互に出す共有カウンタ
#define S_UNK_1DA *((s16 *)(scratch + 0x1DA))
#define S_UNK_1DC *((s16 *)(scratch + 0x1DC))
#define S_UNK_1DE *((s16 *)(scratch + 0x1DE))
#define S_UNK_1E0 *((s16 *)(scratch + 0x1E0))
#define S_BLIND_BOX_POS_X *((s16 *)(scratch + 0x1E2))  // ブラインドボックスを置く位置 x
#define S_BLIND_BOX_POS_Z *((s16 *)(scratch + 0x1E4))  // ブラインドボックスを置く位置 z
#define S_BLIND_BOX_CONTENT *((u8 *)(scratch + 0x1E6))  // ブラインドボックスの中身の ID
#define S_UNK_1E7 *((u8 *)(scratch + 0x1E7))
#define S_UNK_1E8 *((u8 *)(scratch + 0x1E8))
#define S_UNK_1E9 *((u8 *)(scratch + 0x1E9))
#define S_UNK_1EA *((u8 *)(scratch + 0x1EA))
#define S_UNK_1EB *((u8 *)(scratch + 0x1EB))
#define S_UNK_1EC *((u8 *)(scratch + 0x1EC))
#define S_UNK_1ED *((u8 *)(scratch + 0x1ED))
#define S_PIN_MATCHED *((u8 *)(scratch + 0x1EF))  // 時の家の暗証番号が一致したか (1: 一致)
#define S_UNK_1F0 *((s16 *)(scratch + 0x1F0))
#define S_PIN_DIGIT_IDX *((u8 *)(scratch + 0x1F2))  // 入力中の暗証番号の桁 0〜3
#define S_PANEL_MOVE_LIMIT *((u8 *)(scratch + 0x1F8))  // パネル反転パズルの手数の上限
#define S_PANEL_GRID_WIDTH *((u8 *)(scratch + 0x1F9))  // パネル反転パズルの盤面の幅 (3)
#define S_PANEL_MOVE_COUNT *((u8 *)(scratch + 0x1FA))  // パネル反転パズルで押した回数
#define S_UNK_1FB *((u8 *)(scratch + 0x1FB))
#define S_UNK_1FC *((u8 *)(scratch + 0x1FC))
#define S_UNK_1FD *((u8 *)(scratch + 0x1FD))
#define S_UNK_1FE *((s16 *)(scratch + 0x1FE))
#define S_UNK_200 *((s16 *)(scratch + 0x200))
#define S_UNK_202 *((u8 *)(scratch + 0x202))
#define S_CROSSOVER_HELP_ITEM *((u8 *)(scratch + 0x203))  // クロスオーバーバトルの説明メニューで選んだ項目
#define S_MAX_FRIENDSHIP *((s16 *)(scratch + 0x206))  // 最も高い FRIENDSHIP の値 (候補を探す途中の最大値)

#endif // __DATA_SCRIPTS_SCRATCH_H__
