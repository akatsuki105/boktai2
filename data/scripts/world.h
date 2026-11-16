#ifndef __DATA_SCRIPTS_WORLD_H__
#define __DATA_SCRIPTS_WORLD_H__

// data/scripts/scripts.bokc で include する用, world 領域 (include/vm_memory.h の World) の名前の付いたメンバ
// 名前はメンバ名を大文字にしたもの, すべて W_ を付ける
// 中身は .bokc のメモリ参照の綴りそのままにする (ダンパーはこの綴りと完全に一致する参照だけを名前で出す), 外側を括弧で囲まないこと

#define W_STORY_PROGRESS *((s16 *)(world + 0x0))  // ストーリー進行度
#define W_CROSSOVER_PROGRESS *((s16 *)(world + 0x2))  // ロックマンエグゼ連動 (クロスオーバー) の進行度
#define W_LAST_DATE_YEAR *((s16 *)(world + 0x4))  // 前回日付を確認した年
#define W_LAST_DATE_MONTH *((s16 *)(world + 0x6))  // 前回日付を確認した月
#define W_LAST_DATE_DAY *((s16 *)(world + 0x8))  // 前回日付を確認した日
#define W_SAVED_PLAYER_KIND *((s16 *)(world + 0xA))  // 一時的な切り替えやワープの後に戻す PLAYER_KIND
#define W_UNK_00C_0 BIT(world + 0xC, 0)
#define W_UNK_00C_1 BIT(world + 0xC, 1)
#define W_UNK_00C_2 BIT(world + 0xC, 2)
#define W_UNK_00C_3 BIT(world + 0xC, 3)
#define W_UNK_00C_4 BIT(world + 0xC, 4)
#define W_UNK_00C_5 BIT(world + 0xC, 5)
#define W_UNK_00C_6 BIT(world + 0xC, 6)
#define W_UNK_00C_7 BIT(world + 0xC, 7)
#define W_SENSOR_GUIDE_STEP *((u8 *)(world + 0xD))  // 太陽センサーのガイドの表の読み位置, 項目 × 5 + 項目の中の何ページ目か
#define W_SENSOR_GUIDE_PAGE *((u8 *)(world + 0xE))  // 太陽センサーのガイドで表示中のページ (SensorGuide の '.i')
#define W_SENSOR_GUIDE_MODE *((u8 *)(world + 0xF))  // 太陽センサーのガイドの入り方, 0: 起動時の導入, 1: タイトルで放置して自動再生, 2: OPTION の解説から選択
#define W_SENSOR_GUIDE_SELECTED_TOPIC *((u8 *)(world + 0x10))  // OPTION の解説で選んだ太陽センサーのガイドの項目
#define W_UNK_011 *((u8 *)(world + 0x11))
#define W_NORMAL_DROP_RATE *((u8 *)(world + 0x12))  // 敵の通常ドロップ率 (%), 盗人の服で +20
#define W_RARE_DROP_RATE *((u8 *)(world + 0x13))  // 敵のレアドロップ率 (%), 狩人の服で +20
#define W_SENSOR_GUIDE_AUTO_COUNT *((s32 *)(world + 0x14))  // タイトルで放置して太陽センサーのガイドを流した回数, 4 で割った余りで次に流す項目を選ぶ
#define W_CURRENT_STAGE_CHEST_OPENED(i) BIT(world + 0x18, 0, 40, i)  // 今のステージの宝箱を開けたか, 添字は宝箱番号
#define W_LOCKED_DOOR_OPENED(i) BIT(world + 0x1D, 0, 32, i)  // 鍵付き扉を開けたか, 添字は鍵フラグ番号
#define W_COFFIN_DIR *((u8 *)(world + 0x21))  // 置いてある棺桶の向き
#define W_COFFIN_HOLDS_DARK_DJANGO *((u8 *)(world + 0x22))  // 1 なら棺桶の中身が黒ジャンゴ (サバタで運ぶ, 時間制限あり)
#define W_COFFIN_TIME_MONTH *((u8 *)(world + 0x23))  // 棺桶の逃走時間の起点の月
#define W_COFFIN_TIME_YEAR *((s16 *)(world + 0x24))  // 棺桶の逃走時間の起点の年
#define W_COFFIN_TIME_DAY *((u8 *)(world + 0x26))  // 棺桶の逃走時間の起点の日
#define W_COFFIN_TIME_HOUR *((u8 *)(world + 0x27))  // 棺桶の逃走時間の起点の時
#define W_COFFIN_TIME_MINUTE *((u8 *)(world + 0x28))  // 棺桶の逃走時間の起点の分
#define W_COFFIN_CHECKPOINT *((u8 *)(world + 0x29))  // 棺桶運搬のチェックポイント番号, 時間経過で減る
#define W_COFFIN_DEST_X *((s16 *)(world + 0x2A))  // 棺桶が自力で逃げる目的地の x (チェックポイントのゾーン中心)
#define W_COFFIN_DEST_Z *((s16 *)(world + 0x2C))  // 棺桶が自力で逃げる目的地の z
#define W_UNK_02E *((s16 *)(world + 0x2E))
#define W_UNK_030 *((s16 *)(world + 0x30))
#define W_CURRENT_STAGE_FLAGS(i) BIT(world + 0x32, 0, 32, i)  // 今のステージの仕掛けの進行フラグ, 添字はステージごとに決まる
#define W_CURRENT_STAGE_SWITCH_ON(i) BIT(world + 0x36, 0, 32, i)  // 今のステージのスイッチの状態, 添字はスイッチ番号
#define W_STAGE_VISITED(stageID) BIT(world + 0x3A, 0, 16, stageID)  // ステージを調査したか (図書館の「調査中」), 添字は StageID (ST_XXX)
#define W_STAGE_CLEARED(stageID) BIT(world + 0x3C, 0, 16, stageID)  // ステージの調査を完了したか (図書館の「調査完了」), 添字は StageID (ST_XXX)
#define W_UNK_03E(i) BIT(world + 0x3E, 0, 5, i)
#define W_TITLE_EARNED(i) BIT(world + 0x3E, 5, 12, i)  // 称号を獲得したか, 添字は称号番号
#define W_UNK_040_1 BIT(world + 0x40, 1)
#define W_UNK_040_2 BIT(world + 0x40, 2)
#define W_UNK_040_3 BIT(world + 0x40, 3)
#define W_UNK_040_4 BIT(world + 0x40, 4)
#define W_UNK_040_5 BIT(world + 0x40, 5)
#define W_UNK_040_6 BIT(world + 0x40, 6)
#define W_UNK_040_7 BIT(world + 0x40, 7)
#define W_EXIT_POS_RATIO *((u8 *)(world + 0x41))  // 出口ゾーンでのプレイヤーの位置の割合 (0〜255)
#define W_CONTINUE_COST *((s16 *)(world + 0x42))  // コンティニュー時に暗黒ローンから払う額
#define W_ARENA_BOSS_INDEX *((u8 *)(world + 0x44))  // 闘技場で次に戦うボスの番号, 14 なら挑戦中でない
#define W_BOSS_ADVICE_COUNT *((u8 *)(world + 0x45))  // ボス戦でコンティニューしたときの助言を出した回数
#define W_CURSE_COUNT *((s16 *)(world + 0x46))  // 呪われた回数 (総合記録, 最大 9999)
#define W_BERSERK_COUNT *((s16 *)(world + 0x48))  // 暴走した回数 (総合記録, 最大 9999)
#define W_RETRY_COUNT *((s16 *)(world + 0x4A))  // やり直した回数 (総合記録, 最大 9999)
#define W_UNK_04C_0 BIT(world + 0x4C, 0)
#define W_UNK_04C_1 BIT(world + 0x4C, 1)
#define W_CHANGE_PLAYER_WIPE_ON_ENTRY BIT(world + 0x4C, 2)  // 次のマップに入ったら操作キャラ交代のワイプを開く
#define W_UNK_04C_3 BIT(world + 0x4C, 3)
#define W_UNK_04C_4 BIT(world + 0x4C, 4)
#define W_UNK_04C_5 BIT(world + 0x4C, 5)
#define W_UNK_04C_6 BIT(world + 0x4C, 6)
#define W_UNK_04C_7 BIT(world + 0x4C, 7)
#define W_RARE_ENEMY_KILL_THRESHOLD *((u8 *)(world + 0x4D))  // レア敵が出るのに必要なその系統の撃破数
#define W_RARE_ENEMY_RATE *((u8 *)(world + 0x4E))  // レア敵の出現率 (千分率), パレードアーマーで +200
#define W_LOAN_STATE *((u8 *)(world + 0x4F))  // 暗黒ローンの返済状態, 0: 借りていない, 5: 返済済み, 6: 督促
#define W_SUN_COUNTDOWN_STATE *((u8 *)(world + 0x50))  // 日の出/日の入りのカウントダウンの表示段階
#define W_UNK_051_0 BIT(world + 0x51, 0)
#define W_UNK_051_1 BIT(world + 0x51, 1)
#define W_UNK_051_2 BIT(world + 0x51, 2)
#define W_UNK_051_3 BIT(world + 0x51, 3)
#define W_UNK_051_4 BIT(world + 0x51, 4)
#define W_UNK_051_5 BIT(world + 0x51, 5)
#define W_UNK_051_6 BIT(world + 0x51, 6)
#define W_UNK_051_7 BIT(world + 0x51, 7)
#define W_COUNTDOWN_REMAINING *((s16 *)(world + 0x52))  // マップをまたいで引き継ぐカウントダウンの残りフレーム
#define W_PREV_ROOM *((s16 *)(world + 0x54))  // 1つ前にいた部屋の番号 (ROOM の控え)
#define W_PREV_PREV_ROOM *((s16 *)(world + 0x56))  // 2つ前にいた部屋の番号
#define W_UNK_058 *((u8 *)(world + 0x58))
#define W_WAREHOUSE_LEVEL *((u8 *)(world + 0x59))  // 倉庫の開放段階, 0: 未開放
#define W_UNK_05A_0 BIT(world + 0x5A, 0)
#define W_UNK_05A_1 BIT(world + 0x5A, 1)
#define W_UNK_05A_2 BIT(world + 0x5A, 2)
#define W_UNK_05A_3 BIT(world + 0x5A, 3)
#define W_UNK_05A_4 BIT(world + 0x5A, 4)
#define W_UNK_05A_5 BIT(world + 0x5A, 5)
#define W_UNK_05A_6 BIT(world + 0x5A, 6)
#define W_UNK_05A_7 BIT(world + 0x5A, 7)
#define W_KURO_EVENT_STEP *((u8 *)(world + 0x5B))  // クロ負傷イベントの段階
#define W_UNK_05C_0 BIT(world + 0x5C, 0)
#define W_UNK_05C_1 BIT(world + 0x5C, 1)
#define W_UNK_05C_2 BIT(world + 0x5C, 2)
#define W_UNK_05C_3 BIT(world + 0x5C, 3)
#define W_UNK_05C_4 BIT(world + 0x5C, 4)
#define W_UNK_05C_5 BIT(world + 0x5C, 5)
#define W_UNK_05C_6 BIT(world + 0x5C, 6)
#define W_UNK_05C_7 BIT(world + 0x5C, 7)
#define W_BLACK_PANTHER_PRIZE *((u8 *)(world + 0x5D))  // ブラックパンサーの景品のアイテム ID, 0 なら無し
#define W_UNK_05E_0 BIT(world + 0x5E, 0)
#define W_UNK_05E_1 BIT(world + 0x5E, 1)
#define W_UNK_05E_2 BIT(world + 0x5E, 2)
#define W_UNK_05E_3 BIT(world + 0x5E, 3)
#define W_UNK_05E_4 BIT(world + 0x5E, 4)
#define W_UNK_05E_5 BIT(world + 0x5E, 5)
#define W_UNK_05E_6 BIT(world + 0x5E, 6)
#define W_UNK_05E_7 BIT(world + 0x5E, 7)
#define W_UNK_05F_0 BIT(world + 0x5F, 0)
#define W_UNK_05F_1 BIT(world + 0x5F, 1)
#define W_UNK_05F_2 BIT(world + 0x5F, 2)
#define W_UNK_05F_3 BIT(world + 0x5F, 3)
#define W_UNK_05F_4 BIT(world + 0x5F, 4)
#define W_UNK_05F_5 BIT(world + 0x5F, 5)
#define W_UNK_05F_6 BIT(world + 0x5F, 6)
#define W_UNK_05F_7 BIT(world + 0x5F, 7)
#define W_CLOCK_FIX_YEAR *((s16 *)(world + 0x60))  // エンニオの時計を直した年
#define W_CLOCK_FIX_MONTH *((s16 *)(world + 0x62))  // エンニオの時計を直した月
#define W_CLOCK_FIX_DAY *((s16 *)(world + 0x64))  // エンニオの時計を直した日
#define W_CLOCK_FIX_HOUR *((s16 *)(world + 0x66))  // エンニオの時計を直した時
#define W_CLOCK_FIX_MINUTE *((s16 *)(world + 0x68))  // エンニオの時計を直した分
#define W_FORGE_SPECIAL *((u8 *)(world + 0x6A))  // 直前の太陽鍛冶の特殊 (special)
#define W_UNK_06B_0 BIT(world + 0x6B, 0)
#define W_UNK_06B_1 BIT(world + 0x6B, 1)
#define W_UNK_06B_2 BIT(world + 0x6B, 2)
#define W_UNK_06B_3 BIT(world + 0x6B, 3)
#define W_UNK_06B_4 BIT(world + 0x6B, 4)
#define W_UNK_06B_5 BIT(world + 0x6B, 5)
#define W_UNK_06B_6 BIT(world + 0x6B, 6)
#define W_UNK_06B_7 BIT(world + 0x6B, 7)
#define W_FORGE_QUALITY *((s16 *)(world + 0x6C))  // 直前の太陽鍛冶の品質 (quality)
#define W_FORGE_GREAT_COUNT *((s16 *)(world + 0x6E))  // 直前の太陽鍛冶の大成功 (great) の数
#define W_FORGE_TYPE *((s16 *)(world + 0x70))  // 直前の太陽鍛冶でできた武器の種類 (type)
#define W_FORGE_SKILL *((s16 *)(world + 0x72))  // 直前の太陽鍛冶の腕前 (skill)
#define W_UNK_074_0 BIT(world + 0x74, 0)
#define W_UNK_074_1 BIT(world + 0x74, 1)
#define W_UNK_074_2 BIT(world + 0x74, 2)
#define W_UNK_074_3 BIT(world + 0x74, 3)
#define W_UNK_074_4 BIT(world + 0x74, 4)
#define W_UNK_074_5 BIT(world + 0x74, 5)
#define W_UNK_074_6 BIT(world + 0x74, 6)
#define W_UNK_074_7 BIT(world + 0x74, 7)
#define W_UNK_075_0 BIT(world + 0x75, 0)
#define W_UNK_075_1 BIT(world + 0x75, 1)
#define W_UNK_075_2 BIT(world + 0x75, 2)
#define W_UNK_075_3 BIT(world + 0x75, 3)
#define W_UNK_075_4 BIT(world + 0x75, 4)
#define W_UNK_075_5 BIT(world + 0x75, 5)
#define W_UNK_075_6 BIT(world + 0x75, 6)
#define W_UNK_075_7 BIT(world + 0x75, 7)
#define W_CURRENT_QUEST *((u8 *)(world + 0x76))  // 受けている依頼の番号 (0〜11, 依頼の組 * 3 + 選択)
#define W_UNK_077_0 BIT(world + 0x77, 0)
#define W_UNK_077_1 BIT(world + 0x77, 1)
#define W_UNK_077_2 BIT(world + 0x77, 2)
#define W_UNK_077_3 BIT(world + 0x77, 3)
#define W_UNK_077_4 BIT(world + 0x77, 4)
#define W_UNK_077_5 BIT(world + 0x77, 5)
#define W_UNK_077_6 BIT(world + 0x77, 6)
#define W_UNK_077_7 BIT(world + 0x77, 7)
#define W_UNK_078_0 BIT(world + 0x78, 0)
#define W_UNK_078_1 BIT(world + 0x78, 1)
#define W_UNK_078_2 BIT(world + 0x78, 2)
#define W_UNK_078_3 BIT(world + 0x78, 3)
#define W_UNK_078_4 BIT(world + 0x78, 4)
#define W_UNK_078_5 BIT(world + 0x78, 5)
#define W_UNK_078_6 BIT(world + 0x78, 6)
#define W_UNK_078_7 BIT(world + 0x78, 7)
#define W_PILE_DRIVER_STATE *((u8 *)(world + 0x79))  // パイルドライバー戦の段階
#define W_UNK_07A_0 BIT(world + 0x7A, 0)
#define W_UNK_07A_1 BIT(world + 0x7A, 1)
#define W_UNK_07A_2 BIT(world + 0x7A, 2)
#define W_UNK_07A_3 BIT(world + 0x7A, 3)
#define W_UNK_07A_4 BIT(world + 0x7A, 4)
#define W_UNK_07A_5 BIT(world + 0x7A, 5)
#define W_UNK_07A_6 BIT(world + 0x7A, 6)
#define W_UNK_07A_7 BIT(world + 0x7A, 7)
#define W_BLIND_BOX_SPOT *((u8 *)(world + 0x7B))  // ブラインドボックスを置いた位置
#define W_HATENA_GIFT_AREA *((u8 *)(world + 0x7C))  // ハテナが持ち物を置いていったエリア
#define W_UNK_07D_0 BIT(world + 0x7D, 0)
#define W_UNK_07D_1 BIT(world + 0x7D, 1)
#define W_UNK_07D_2 BIT(world + 0x7D, 2)
#define W_UNK_07D_3 BIT(world + 0x7D, 3)
#define W_UNK_07D_4 BIT(world + 0x7D, 4)
#define W_UNK_07D_5 BIT(world + 0x7D, 5)
#define W_UNK_07D_6 BIT(world + 0x7D, 6)
#define W_UNK_07D_7 BIT(world + 0x7D, 7)
#define W_BLIND_BOX_LEVEL *((u8 *)(world + 0x7E))  // ブラインドボックスの中身のレベル
#define W_ZAJI_GIFT_ITEM *((u8 *)(world + 0x7F))  // ザジがくれる宝箱のアイテム ID, 0 なら無し
#define W_UNK_080_0 BIT(world + 0x80, 0)
#define W_UNK_080_1 BIT(world + 0x80, 1)
#define W_UNK_080_2 BIT(world + 0x80, 2)
#define W_UNK_080_3 BIT(world + 0x80, 3)
#define W_UNK_080_4 BIT(world + 0x80, 4)
#define W_UNK_080_5 BIT(world + 0x80, 5)
#define W_UNK_080_6 BIT(world + 0x80, 6)
#define W_UNK_080_7 BIT(world + 0x80, 7)
#define W_CROSSOVER_ARMOR_COUNT *((u8 *)(world + 0x81))  // クロスオーバーポイントで防具を交換した回数
#define W_VALENTINE_EVENT_SEEN(i) BIT(world + 0x82, 0, 5, i)  // バレンタインのイベントが起きたか, 添字は好感度の相手
#define W_VALENTINE_TALK_SEEN(i) BIT(world + 0x82, 5, 5, i)  // バレンタインの後日の会話を見たか
#define W_VALENTINE_GIFT_TAKEN(i) BIT(world + 0x83, 2, 5, i)  // バレンタインのお返しを受け取ったか
#define W_UNK_083_7 BIT(world + 0x83, 7)
#define W_CATACOMBS_ROOM *((u8 *)(world + 0x84))  // 地下墓地で訪ねる部屋, 1: 僕, 2: 岩, 3: 犬, 4: 骨, 5: 鳥
#define W_CATACOMBS_ROOM_CLEARED(i) BIT(world + 0x85, 0, 6, i)  // 地下墓地の部屋をクリアしたか, 添字は catacombsRoom
#define W_TREASURY_ROOM_CLEARED(i) BIT(world + 0x85, 6, 4, i)  // 宝物庫の部屋をクリアしたか
#define W_UNK_086_2 BIT(world + 0x86, 2)
#define W_UNK_086_3 BIT(world + 0x86, 3)
#define W_UNK_086_4 BIT(world + 0x86, 4)
#define W_UNK_086_5 BIT(world + 0x86, 5)
#define W_UNK_086_6 BIT(world + 0x86, 6)
#define W_UNK_086_7 BIT(world + 0x86, 7)
#define W_CROSSOVER_ARMOR_CANDIDATES(i) ((u8 *)(world + 0x87))[6, i]  // 防具交換で渡す防具 ID の候補
#define W_KEY_DATA_RECEIVED(i) ((u8 *)(world + 0x8D))[4, i]  // ロックマンエグゼ連動のキーデータ1〜4を受け取ったか
#define W_MUGEN_FLOOR *((u8 *)(world + 0x91))  // 夢幻街の現在の階 (1 始まり, 13 以上で最終階)
#define W_MUGEN_BLOCK *((u8 *)(world + 0x92))  // 夢幻街で今いる区画 (3x3 の 0〜8)
#define W_MUGEN_SIDE *((u8 *)(world + 0x93))  // 区画の中で今いる小部屋の方向, 4 なら区画の通り
#define W_MUGEN_LEVEL *((u8 *)(world + 0x94))  // 夢幻街のレベル (クリア回数)
#define W_MUGEN_ENTRANCE_BLOCK *((u8 *)(world + 0x95))  // 夢幻街の入口 (小部屋 7) がある区画
#define W_MUGEN_EXIT_BLOCK *((u8 *)(world + 0x96))  // 夢幻街の出口 (小部屋 8, 鍵付き扉) がある区画
#define W_MUGEN_BLOCK_MAP(i) ((u8 *)(world + 0x97))[9, i]  // 区画ごとの地形, 0: 区画なし, 1〜10: マップの種類
#define W_MUGEN_BLOCK_EVENT(i) ((u8 *)(world + 0xA0))[9, i]  // 区画ごとの仕掛けの種類
#define W_MUGEN_SIDE_ROOM(i) ((u8 *)(world + 0xA9))[36, i]  // 区画の辺ごとの小部屋, 0: なし, 7: 入口, 8: 出口
#define W_MUGEN_SIDE_ROOM_COUNT(i) ((u8 *)(world + 0xCD))[9, i]  // 区画ごとの小部屋の数
#define W_MUGEN_ENEMY_KIND(i) ((u8 *)(world + 0xD6))[27, i]  // 夢幻街の敵の種類, 添字は区画 * 3 + 枠
#define W_MUGEN_ENEMY_SPAWN(i) ((u8 *)(world + 0xF1))[27, i]  // 夢幻街の敵の出現位置の番号
#define W_MUGEN_ENEMY_ALT_PARAM(i) ((u8 *)(world + 0x10C))[27, i]  // 夢幻街の敵の切り替え先の値
#define W_MUGEN_ENEMY_TOGGLED(i) BIT(world + 0x127, 0, 3, i)  // 夢幻街の今の区画の敵が切り替え後か
#define W_UNK_127_3 BIT(world + 0x127, 3)
#define W_UNK_127_4 BIT(world + 0x127, 4)
#define W_UNK_127_5 BIT(world + 0x127, 5)
#define W_UNK_127_6 BIT(world + 0x127, 6)
#define W_UNK_127_7 BIT(world + 0x127, 7)
#define W_MUGEN_REWARD_ARMORS(i) ((u8 *)(world + 0x128))[4, i]  // 夢幻街の報酬部屋で出す防具 ID
#define W_MUGEN_ROOM_CONTENT(i) ((u8 *)(world + 0x12C))[36, i]  // 夢幻街の小部屋の中身, 0: 敵, 1: 太陽スタンド, 3 以降: 宝箱
#define W_QUEST_CLEARED(i) BIT(world + 0x150, 0, 12, i)  // 依頼を達成したか, 添字は依頼番号
#define W_QUEST_ACCEPTED(i) BIT(world + 0x151, 4, 12, i)  // 依頼を受注中か, 添字は依頼番号
#define W_UNK_153_0 BIT(world + 0x153, 0)
#define W_UNK_153_1 BIT(world + 0x153, 1)
#define W_UNK_153_2 BIT(world + 0x153, 2)
#define W_UNK_153_3 BIT(world + 0x153, 3)
#define W_UNK_153_4 BIT(world + 0x153, 4)
#define W_UNK_153_5 BIT(world + 0x153, 5)
#define W_UNK_153_6 BIT(world + 0x153, 6)
#define W_UNK_153_7 BIT(world + 0x153, 7)
#define W_UNK_154_0 BIT(world + 0x154, 0)
#define W_UNK_154_1 BIT(world + 0x154, 1)
#define W_UNK_154_2 BIT(world + 0x154, 2)
#define W_UNK_154_3 BIT(world + 0x154, 3)
#define W_UNK_154_4 BIT(world + 0x154, 4)
#define W_UNK_154_5 BIT(world + 0x154, 5)
#define W_UNK_154_6 BIT(world + 0x154, 6)
#define W_UNK_154_7 BIT(world + 0x154, 7)
#define W_UNK_155_0 BIT(world + 0x155, 0)
#define W_UNK_155_1 BIT(world + 0x155, 1)
#define W_UNK_155_2 BIT(world + 0x155, 2)
#define W_UNK_155_3 BIT(world + 0x155, 3)
#define W_UNK_155_4 BIT(world + 0x155, 4)
#define W_UNK_155_5 BIT(world + 0x155, 5)
#define W_UNK_155_6 BIT(world + 0x155, 6)
#define W_UNK_155_7 BIT(world + 0x155, 7)
#define W_ARENA_RANK *((u8 *)(world + 0x156))  // 闘技場で選んだランク, 0: 未選択, 1〜4: ブロンズ〜プラチナ
#define W_UNK_157_0 BIT(world + 0x157, 0)
#define W_UNK_157_1 BIT(world + 0x157, 1)
#define W_UNK_157_2 BIT(world + 0x157, 2)
#define W_UNK_157_3 BIT(world + 0x157, 3)
#define W_UNK_157_4 BIT(world + 0x157, 4)
#define W_UNK_157_5 BIT(world + 0x157, 5)
#define W_UNK_157_6 BIT(world + 0x157, 6)
#define W_UNK_157_7 BIT(world + 0x157, 7)
#define W_UNK_158_0 BIT(world + 0x158, 0)
#define W_UNK_158_1 BIT(world + 0x158, 1)
#define W_UNK_158_2 BIT(world + 0x158, 2)
#define W_UNK_158_3 BIT(world + 0x158, 3)
#define W_UNK_158_4 BIT(world + 0x158, 4)
#define W_UNK_158_5 BIT(world + 0x158, 5)
#define W_UNK_158_6 BIT(world + 0x158, 6)
#define W_UNK_158_7 BIT(world + 0x158, 7)
#define W_UNK_159_0 BIT(world + 0x159, 0)
#define W_UNK_159_1 BIT(world + 0x159, 1)
#define W_UNK_159_2 BIT(world + 0x159, 2)
#define W_UNK_159_3 BIT(world + 0x159, 3)
#define W_UNK_159_4 BIT(world + 0x159, 4)
#define W_UNK_159_5 BIT(world + 0x159, 5)
#define W_UNK_159_6 BIT(world + 0x159, 6)
#define W_UNK_159_7 BIT(world + 0x159, 7)
#define W_UNK_15A_0 BIT(world + 0x15A, 0)
#define W_UNK_15A_1 BIT(world + 0x15A, 1)
#define W_UNK_15A_2 BIT(world + 0x15A, 2)
#define W_UNK_15A_3 BIT(world + 0x15A, 3)
#define W_UNK_15A_4 BIT(world + 0x15A, 4)
#define W_UNK_15A_5 BIT(world + 0x15A, 5)
#define W_UNK_15A_6 BIT(world + 0x15A, 6)
#define W_UNK_15A_7 BIT(world + 0x15A, 7)
#define W_UNK_15B_0 BIT(world + 0x15B, 0)
#define W_UNK_15B_1 BIT(world + 0x15B, 1)
#define W_UNK_15B_2 BIT(world + 0x15B, 2)
#define W_UNK_15B_3 BIT(world + 0x15B, 3)
#define W_UNK_15B_4 BIT(world + 0x15B, 4)
#define W_UNK_15B_5 BIT(world + 0x15B, 5)
#define W_UNK_15B_6 BIT(world + 0x15B, 6)
#define W_UNK_15B_7 BIT(world + 0x15B, 7)
#define W_UNK_15C_0 BIT(world + 0x15C, 0)
#define W_UNK_15C_1 BIT(world + 0x15C, 1)
#define W_UNK_15C_2 BIT(world + 0x15C, 2)
#define W_UNK_15C_3 BIT(world + 0x15C, 3)
#define W_UNK_15C_4 BIT(world + 0x15C, 4)
#define W_UNK_15C_5 BIT(world + 0x15C, 5)
#define W_UNK_15C_6 BIT(world + 0x15C, 6)
#define W_UNK_15C_7 BIT(world + 0x15C, 7)
#define W_UNK_15D_0 BIT(world + 0x15D, 0)
#define W_UNK_15D_1 BIT(world + 0x15D, 1)
#define W_UNK_15D_2 BIT(world + 0x15D, 2)
#define W_UNK_15D_3 BIT(world + 0x15D, 3)
#define W_UNK_15D_4 BIT(world + 0x15D, 4)
#define W_UNK_15D_5 BIT(world + 0x15D, 5)
#define W_UNK_15D_6 BIT(world + 0x15D, 6)
#define W_UNK_15D_7 BIT(world + 0x15D, 7)
#define W_TASTY_WATER_TIMER *((s16 *)(world + 0x15E))  // おいしい水の残りフレーム数
#define W_UNK_160_0 BIT(world + 0x160, 0)
#define W_UNK_160_1 BIT(world + 0x160, 1)
#define W_UNK_160_2 BIT(world + 0x160, 2)
#define W_UNK_160_3 BIT(world + 0x160, 3)
#define W_UNK_160_4 BIT(world + 0x160, 4)
#define W_UNK_160_5 BIT(world + 0x160, 5)
#define W_UNK_160_6 BIT(world + 0x160, 6)
#define W_UNK_160_7 BIT(world + 0x160, 7)
#define W_UNK_161_0 BIT(world + 0x161, 0)
#define W_UNK_161_1 BIT(world + 0x161, 1)
#define W_UNK_161_2 BIT(world + 0x161, 2)
#define W_UNK_161_3 BIT(world + 0x161, 3)
#define W_UNK_161_4 BIT(world + 0x161, 4)
#define W_UNK_161_5 BIT(world + 0x161, 5)
#define W_UNK_161_6 BIT(world + 0x161, 6)
#define W_UNK_161_7 BIT(world + 0x161, 7)
#define W_UNK_162_0 BIT(world + 0x162, 0)
#define W_UNK_162_1 BIT(world + 0x162, 1)
#define W_UNK_162_2 BIT(world + 0x162, 2)
#define W_UNK_162_3 BIT(world + 0x162, 3)
#define W_UNK_162_4 BIT(world + 0x162, 4)
#define W_UNK_162_5 BIT(world + 0x162, 5)
#define W_UNK_162_6 BIT(world + 0x162, 6)
#define W_UNK_162_7 BIT(world + 0x162, 7)
#define W_ISEKI_SLAB_PIECES *((u8 *)(world + 0x163))  // 砂漠のくぼみにはめ込んだ石版のかけらの数, 3 で完成
#define W_UNK_164_0 BIT(world + 0x164, 0)
#define W_UNK_164_1 BIT(world + 0x164, 1)
#define W_UNK_164_2 BIT(world + 0x164, 2)
#define W_UNK_164_3 BIT(world + 0x164, 3)
#define W_UNK_164_4 BIT(world + 0x164, 4)
#define W_UNK_164_5 BIT(world + 0x164, 5)
#define W_UNK_164_6 BIT(world + 0x164, 6)
#define W_UNK_164_7 BIT(world + 0x164, 7)
#define W_ISEKI_DESERT_CELL *((u8 *)(world + 0x165))  // 砂漠の今の区画, 5x5 の 0〜24
#define W_ISEKI_DESERT_CELL_EDGE *((u8 *)(world + 0x166))  // 今の区画が砂漠の端のどこか, 3x3 の 0〜8 (4 が中央)
#define W_UNK_167_0 BIT(world + 0x167, 0)
#define W_ISEKI_FRAGMENT_TAKEN(i) BIT(world + 0x167, 1, 9, i)  // 石版のかけらを隠し場所から取ったか
#define W_ISEKI_FRAGMENT_PLACED(i) BIT(world + 0x168, 2, 9, i)  // 石版のかけらが置かれている隠し場所か
#define W_UNK_169_3 BIT(world + 0x169, 3)
#define W_UNK_169_4 BIT(world + 0x169, 4)
#define W_UNK_169_5 BIT(world + 0x169, 5)
#define W_UNK_169_6 BIT(world + 0x169, 6)
#define W_UNK_169_7 BIT(world + 0x169, 7)
#define W_ISEKI_FRAGMENT_SPOT(i) ((u8 *)(world + 0x16A))[4, i]  // 石版のかけら3つの隠し場所番号
#define W_UNK_16E_0 BIT(world + 0x16E, 0)
#define W_UNK_16E_1 BIT(world + 0x16E, 1)
#define W_UNK_16E_2 BIT(world + 0x16E, 2)
#define W_UNK_16E_3 BIT(world + 0x16E, 3)
#define W_UNK_16E_4 BIT(world + 0x16E, 4)
#define W_UNK_16E_5 BIT(world + 0x16E, 5)
#define W_UNK_16E_6 BIT(world + 0x16E, 6)
#define W_UNK_16E_7 BIT(world + 0x16E, 7)
#define W_UNK_16F_0 BIT(world + 0x16F, 0)
#define W_UNK_16F_1 BIT(world + 0x16F, 1)
#define W_UNK_16F_2 BIT(world + 0x16F, 2)
#define W_UNK_16F_3 BIT(world + 0x16F, 3)
#define W_UNK_16F_4 BIT(world + 0x16F, 4)
#define W_UNK_16F_5 BIT(world + 0x16F, 5)
#define W_UNK_16F_7 BIT(world + 0x16F, 7)
#define W_UNK_170_0 BIT(world + 0x170, 0)
#define W_DARK_VINE_BROKEN BIT(world + 0x170, 1)  // 暗黒街の壊せる暗黒つた (DarkVine) を壊した
#define W_UNK_170_2 BIT(world + 0x170, 2)
#define W_UNK_170_3 BIT(world + 0x170, 3)
#define W_UNK_170_4 BIT(world + 0x170, 4)
#define W_UNK_170_5 BIT(world + 0x170, 5)
#define W_UNK_170_6 BIT(world + 0x170, 6)
#define W_UNK_170_7 BIT(world + 0x170, 7)
#define W_UNK_171_1 BIT(world + 0x171, 1)
#define W_UNK_171_2 BIT(world + 0x171, 2)
#define W_UNK_171_3 BIT(world + 0x171, 3)
#define W_UNK_171_4 BIT(world + 0x171, 4)
#define W_UNK_171_5 BIT(world + 0x171, 5)
#define W_UNK_171_6 BIT(world + 0x171, 6)
#define W_UNK_171_7 BIT(world + 0x171, 7)
#define W_UNK_172_0 BIT(world + 0x172, 0)
#define W_UNK_172_1 BIT(world + 0x172, 1)
#define W_UNK_172_2 BIT(world + 0x172, 2)
#define W_UNK_172_3 BIT(world + 0x172, 3)
#define W_UNK_172_4 BIT(world + 0x172, 4)
#define W_UNK_172_5 BIT(world + 0x172, 5)
#define W_UNK_172_6 BIT(world + 0x172, 6)
#define W_UNK_172_7 BIT(world + 0x172, 7)
#define W_UNK_173_0 BIT(world + 0x173, 0)
#define W_UNK_173_1 BIT(world + 0x173, 1)
#define W_UNK_173_2 BIT(world + 0x173, 2)
#define W_UNK_173_3 BIT(world + 0x173, 3)
#define W_UNK_173_4 BIT(world + 0x173, 4)
#define W_UNK_173_5 BIT(world + 0x173, 5)
#define W_UNK_173_6 BIT(world + 0x173, 6)
#define W_UNK_173_7 BIT(world + 0x173, 7)
#define W_UNK_174_0 BIT(world + 0x174, 0)
#define W_UNK_174_1 BIT(world + 0x174, 1)
#define W_UNK_174_2 BIT(world + 0x174, 2)
#define W_UNK_174_3 BIT(world + 0x174, 3)
#define W_UNK_174_4 BIT(world + 0x174, 4)
#define W_UNK_174_5 BIT(world + 0x174, 5)
#define W_UNK_174_6 BIT(world + 0x174, 6)
#define W_UNK_174_7 BIT(world + 0x174, 7)
#define W_RASEN_BLOCK_DIST_NS *((u8 *)(world + 0x175))  // 螺旋の塔の壁の暗号が示すブロックの位置の南北の距離 (マス)
#define W_RASEN_BLOCK_DIST_EW *((u8 *)(world + 0x176))  // 壁の暗号が示すブロックの位置の東西の距離 (マス)
#define W_RASEN_BLOCK_DIR_NS *((u8 *)(world + 0x177))  // 壁の暗号が示す南北の向き, 0: 北, 1: 南
#define W_RASEN_BLOCK_DIR_EW *((u8 *)(world + 0x178))  // 壁の暗号が示す東西の向き, 0: 東, 1: 西
#define W_UNK_179_0 BIT(world + 0x179, 0)
#define W_UNK_179_1 BIT(world + 0x179, 1)
#define W_UNK_179_2 BIT(world + 0x179, 2)
#define W_UNK_179_3 BIT(world + 0x179, 3)
#define W_UNK_179_4 BIT(world + 0x179, 4)
#define W_UNK_179_5 BIT(world + 0x179, 5)
#define W_UNK_179_6 BIT(world + 0x179, 6)
#define W_UNK_179_7 BIT(world + 0x179, 7)
#define W_UNK_17A_0 BIT(world + 0x17A, 0)
#define W_UNK_17A_1 BIT(world + 0x17A, 1)
#define W_UNK_17A_2 BIT(world + 0x17A, 2)
#define W_UNK_17A_3 BIT(world + 0x17A, 3)
#define W_UNK_17A_4 BIT(world + 0x17A, 4)
#define W_UNK_17A_5 BIT(world + 0x17A, 5)
#define W_CHANGE_PLAYER_SIDE BIT(world + 0x17A, 6)  // 操作キャラ交代の行き先が A (0) と B (1) のどちらか
#define W_UNK_17A_7 BIT(world + 0x17A, 7)
#define W_UNK_17B *((u8 *)(world + 0x17B))
#define W_CHANGE_PLAYER_DEST_A *((u8 *)(world + 0x17C))  // 操作キャラ交代 (チェンジ魔方陣など) の行き先 A (ワープ先番号, 奇数)
#define W_CHANGE_PLAYER_DEST_B *((u8 *)(world + 0x17D))  // 操作キャラ交代 (チェンジ魔方陣など) の行き先 B (ワープ先番号, 偶数)
#define W_UNK_17E_0 BIT(world + 0x17E, 0)
#define W_UNK_17E_1 BIT(world + 0x17E, 1)
#define W_UNK_17E_2 BIT(world + 0x17E, 2)
#define W_UNK_17E_3 BIT(world + 0x17E, 3)
#define W_UNK_17E_4 BIT(world + 0x17E, 4)
#define W_UNK_17E_5 BIT(world + 0x17E, 5)
#define W_UNK_17E_6 BIT(world + 0x17E, 6)
#define W_UNK_17E_7 BIT(world + 0x17E, 7)
#define W_UNK_17F_0 BIT(world + 0x17F, 0)
#define W_UNK_17F_1 BIT(world + 0x17F, 1)
#define W_UNK_17F_2 BIT(world + 0x17F, 2)
#define W_UNK_17F_3 BIT(world + 0x17F, 3)
#define W_UNK_17F_4 BIT(world + 0x17F, 4)
#define W_UNK_17F_5 BIT(world + 0x17F, 5)
#define W_UNK_17F_6 BIT(world + 0x17F, 6)
#define W_UNK_17F_7 BIT(world + 0x17F, 7)
#define W_UNK_180_0 BIT(world + 0x180, 0)
#define W_UNK_180_1 BIT(world + 0x180, 1)
#define W_UNK_180_2 BIT(world + 0x180, 2)
#define W_UNK_180_3 BIT(world + 0x180, 3)
#define W_UNK_180_4 BIT(world + 0x180, 4)
#define W_UNK_180_5 BIT(world + 0x180, 5)
#define W_UNK_180_6 BIT(world + 0x180, 6)
#define W_UNK_180_7 BIT(world + 0x180, 7)
#define W_UNK_181_0 BIT(world + 0x181, 0)
#define W_UNK_181_1 BIT(world + 0x181, 1)
#define W_UNK_181_2 BIT(world + 0x181, 2)
#define W_UNK_181_3 BIT(world + 0x181, 3)
#define W_UNK_181_4 BIT(world + 0x181, 4)
#define W_UNK_181_5 BIT(world + 0x181, 5)
#define W_FRIEND_CUTSCENE_SHOWN(i) BIT(world + 0x181, 6, 5, i)  // 12番街の仲間の場面に選ばれた仲間, 添字は FRIENDSHIP と同じ
#define W_UNK_182_3 BIT(world + 0x182, 3)
#define W_UNK_182_4 BIT(world + 0x182, 4)
#define W_UNK_182_5 BIT(world + 0x182, 5)
#define W_UNK_182_6 BIT(world + 0x182, 6)
#define W_UNK_182_7 BIT(world + 0x182, 7)
#define W_COFFIN_STATE *((u8 *)(world + 0x183))  // 棺桶の運搬状態, 0: 運んでいない, 1/2: 運搬中
#define W_UNK_184 *((s16 *)(world + 0x184))
#define W_ENTRANCE *((s16 *)(world + 0x186))  // マップに入ったときの入口番号
#define W_COFFIN_X *((s16 *)(world + 0x18A))  // 棺桶が置かれている x
#define W_COFFIN_Z *((s16 *)(world + 0x18C))  // 棺桶が置かれている z
#define W_COFFIN_ROOM *((s16 *)(world + 0x18E))  // 棺桶が置かれている部屋 (ROOM の値)
#define W_COFFIN_DUNGEON *((u8 *)(world + 0x190))  // 棺桶のイモータルダンジョン番号 (ステージ ID - 1)
#define W_UNK_195 *((u8 *)(world + 0x195))
#define W_UNK_196 *((u8 *)(world + 0x196))
#define W_CURRENT_STAGE_EVENT_FLAGS(i) BIT(world + 0x197, 0, 32, i)  // 今のステージの仕掛けとイベントのフラグ
#define W_CANDLE_LIT(i) BIT(world + 0x19B, 0, 32, i)  // 燭台の点灯フラグ, 添字は燭台フラグ番号
#define W_TORTURE_COUNT *((u8 *)(world + 0x19F))  // 暗黒ローンのおしおきを受けた回数, 100 で頭打ち
#define W_UNK_1A0 *((s32 *)(world + 0x1A0))
#define W_UNK_1A4 *((s32 *)(world + 0x1A4))
#define W_CHEST_OPENED(i) BIT(world + 0x1A8, 0, (u8)100, i)  // 宝箱を開けたか, 添字は宝箱番号
#define W_LINK_ITEM_SPOT_USED(i) BIT(world + 0x1B4, 4, 12, i)  // 通信対戦のアイテム配置点が使用中か
#define W_PREV_BGM *((s16 *)(world + 0x1B6))  // 直前に流れていた BGM, イベント後に戻す曲
#define W_CURRENT_BGM *((s16 *)(world + 0x1B8))  // 今流れている BGM
#define W_LOAN_YEAR *((s16 *)(world + 0x1BA))  // 暗黒ローンを借りた日の年
#define W_LOAN_MONTH *((s16 *)(world + 0x1BC))  // 暗黒ローンを借りた日の月
#define W_LOAN_DAY *((s16 *)(world + 0x1BE))  // 暗黒ローンを借りた日の日
#define W_QUEST_ENEMY_DEFEATED(i) BIT(world + 0x1C0, 0, 40, i)  // 依頼の討伐対象を倒したか, 添字は敵番号
#define W_UNK_1C5 *((u8 *)(world + 0x1C5))
#define W_UNK_1C6 *((s16 *)(world + 0x1C6))
#define W_UNK_1C8 *((s16 *)(world + 0x1C8))
#define W_UNK_1CA *((s16 *)(world + 0x1CA))
#define W_UNK_1CC *((s16 *)(world + 0x1CC))
#define W_UNK_1CE *((s16 *)(world + 0x1CE))
#define W_UNK_1D0 *((s16 *)(world + 0x1D0))
#define W_UNK_1D2 *((s16 *)(world + 0x1D2))
#define W_UNK_1D4 *((s16 *)(world + 0x1D4))
#define W_UNK_1D6 *((s16 *)(world + 0x1D6))
#define W_UNK_1D8 *((s16 *)(world + 0x1D8))
#define W_LINK_PLAYER_COUNT *((s16 *)(world + 0x1DA))  // 通信対戦の参加人数
#define W_LINK_ITEM_WEIGHTS(i) ((u8 *)(world + 0x1DC))[11, i]  // 通信対戦でアイテム配置点に出すアイテム 11 種の抽選の重み
#define W_UNK_1E7 *((u8 *)(world + 0x1E7))
#define W_UNK_1E8 *((s16 *)(world + 0x1E8))
#define W_UNK_1EA *((s16 *)(world + 0x1EA))
#define W_UNK_1EC *((s16 *)(world + 0x1EC))
#define W_UNK_1EE *((s16 *)(world + 0x1EE))
#define W_UNK_1F0 *((s16 *)(world + 0x1F0))
#define W_UNK_1F2_0 BIT(world + 0x1F2, 0)
#define W_UNK_1F2_1 BIT(world + 0x1F2, 1)
#define W_UNK_1F2_2 BIT(world + 0x1F2, 2)
#define W_UNK_1F2_3 BIT(world + 0x1F2, 3)
#define W_UNK_1F2_4 BIT(world + 0x1F2, 4)
#define W_UNK_1F2_7 BIT(world + 0x1F2, 7)
#define W_HATENA_SMALL_TALK_COUNT *((u8 *)(world + 0x1F3))  // ハテナの雑談の回数, 偶奇で2種類を交互に話す
#define W_HATENA_TITLE_TALK_COUNT *((u8 *)(world + 0x1F4))  // ハテナの称号会話のカウンタ
#define W_BLIND_BOX_AREA *((u8 *)(world + 0x1F5))  // ブラインドボックス (ハテナ) の今のエリア
#define W_TREASURY_SWITCH_ON(i) BIT(world + 0x1FA, 0, 12, i)  // 宝物庫の切り替えスイッチの状態, 添字はスイッチ番号
#define W_UNK_1FB_4 BIT(world + 0x1FB, 4)
#define W_UNK_1FB_5 BIT(world + 0x1FB, 5)
#define W_UNK_1FB_6 BIT(world + 0x1FB, 6)
#define W_UNK_1FB_7 BIT(world + 0x1FB, 7)
#define W_UNK_1FC *((s16 *)(world + 0x1FC))
#define W_SENSOR_GUIDE_STATE *((u8 *)(world + 0x1FE))  // 太陽センサーのガイド (Scr_SensorGuide) の進行状態 0〜2
#define W_SENSOR_GUIDE_TOPIC *((u8 *)(world + 0x1FF))  // 再生中の太陽センサーのガイドの項目 (太陽センサーとは / 効果 / 使用上の注意 …), 表の読み位置はこの5倍から
#define W_UNK_200 *((s16 *)(world + 0x200))
#define W_UNK_202 *((s16 *)(world + 0x202))
#define W_LINK_STAGE *((s16 *)(world + 0x204))  // 通信対戦のステージ番号 0〜2
#define W_FORGE_GOOD *((s16 *)(world + 0x206))  // 直前の太陽鍛冶の成功 (good) の回数
#define W_FORGE_BAD *((s16 *)(world + 0x208))  // 直前の太陽鍛冶の失敗 (bad) の回数
#define W_MUGEN_REWARD_COUNT *((u8 *)(world + 0x20A))  // 夢幻街の報酬部屋で報酬を受け取った回数
#define W_UNK_20B_0 BIT(world + 0x20B, 0)
#define W_UNK_20B_1 BIT(world + 0x20B, 1)
#define W_UNK_20B_2 BIT(world + 0x20B, 2)
#define W_UNK_20B_3 BIT(world + 0x20B, 3)
#define W_UNK_20B_4 BIT(world + 0x20B, 4)
#define W_UNK_20B_5 BIT(world + 0x20B, 5)
#define W_UNK_20B_6 BIT(world + 0x20B, 6)
#define W_FORGE_RANK *((s16 *)(world + 0x20C))  // 直前の太陽鍛冶でできた武器のランク
#define W_FORGE_NAME *((s16 *)(world + 0x20E))  // 直前の太陽鍛冶でできた武器の名前 ID
#define W_ISEKI_COFFIN_CELL *((u8 *)(world + 0x210))  // 砂漠で棺桶を置いてきた区画

#endif // __DATA_SCRIPTS_WORLD_H__
