#include "global.h"
#include "msgbus.h"

// カットシーンスクリプトの構成 (内部的には MsgPacket をまとめただけ)
//
//   gCutsceneTable[125]      カットシーンIDで引く表 (このファイルの末尾)
//     |
//     +- sCutscene_N[]            1つのカットシーン, ステップへのポインタを並べて NULL 終端
//          |                  添字がそのまま進行順で、MsgBus が step を1つずつ上げていく
//          +- sStep_cN_sM[]        1ステップ, メッセージへのポインタを並べて NULL 終端
//               |                 同じステップのメッセージは同じフレームにまとめて配られる
//               +- sMsg_cN_sM_K       1件のメッセージ, 宛先 (targetID/targetClass) と cmd と引数
//                                     waitFlag が WAIT のものは、受け手が処理し終えるまで次のステップに進まない
//
// CutsceneTable_GetMsg がこの3段を引いて1件を返し、MsgBus がそれを宛先のエンティティに配る
//
// ソースはカットシーン1本につき1ファイル (data/cutscene/cNNN.h) で, メッセージ, ステップ, カットシーンの順に続けて書く
// ROM ではメッセージ全部 → ステップ全部 → カットシーン全部 の順に並んでいるので, 段ごとに別の section に入れ,
// ld_script.ld で .rodata.cutscene_msg → _step → _list の順に並べ直す (同じ section の中は宣言順)

// ---- メッセージの実体 ----
// 可変長で、実体サイズは 8 + ceil(argc/2)*4, argc を偶数に丸めた6種を使い分ける
// 実行時に見るときは MsgPacket* にキャストする, 余りスロットは常に 0,

// clang-format off
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; }                CutsceneMsg0;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[2]; }   CutsceneMsg2;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[4]; }   CutsceneMsg4;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[6]; }   CutsceneMsg6;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[8]; }   CutsceneMsg8;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[10]; }  CutsceneMsg10;
// clang-format on

// waitFlag: WAIT なら受け手が処理し終えるまで次のステップに進まない
#define NOWAIT 0
#define WAIT 1

// cmd の意味は targetClass ごとに別物, ハンドラを読んで確定したものだけ名前を付けてある
#define BUS_CMD_EXEC_SCRIPT 0  // Cutscene_CmdExecScript
#define BUS_CMD_WAIT 1         // Cutscene_CmdWait
#define BUS_CMD_WAIT_EXT 2     // Cutscene_CmdWaitExternal

#define TGT_BUS 0x4E69             // BOKHASH("デモマネージャ"), gMsgBus
#define TGT_CAM 0xD23E             // BOKHASH("カメラ1"), gCamera
#define TGT_CAM2 0x56CB            // BOKHASH("カメラ１"), 1 が全角になったもの、 ただの表記揺れ
#define TGT_EFFECT 0x730A          // BOKHASH("デモエフェクトマネージャ"), CutsceneEffectManager
#define TGT_SOUND 0x74E2           // BOKHASH("サウンドマネージャ"), CutsceneSoundManager
#define TGT_PLAYER 0xF5EB          // BOKHASH("プレイヤー")
#define TGT_DJANGO 0xBF31          // BOKHASH("ジャンゴ")
#define TGT_SABATA 0x2B06          // BOKHASH("サバタ")
#define TGT_OTNK 0x9CFE            // BOKHASH("おてんこさま")
#define TGT_DUNEYRR 0x2B18         // BOKHASH("ドゥネイル")
#define TGT_RINGO 0xBA4B           // BOKHASH("リンゴ")
#define TGT_DURATHROR 0x9386       // BOKHASH("ドゥラスロール")
#define TGT_DVALINN 0x0074         // BOKHASH("ドヴァリン")
#define TGT_DAIIN 0x7901           // BOKHASH("ダーイン")
#define TGT_SMITH 0x6740           // BOKHASH("スミス")
#define TGT_RITA 0x3DB5            // BOKHASH("リタ")
#define TGT_ZAJI 0x6DAD            // BOKHASH("ザジ")
#define TGT_SUMIRE 0x6773          // BOKHASH("スミレ")
#define TGT_KURO_A 0x51E2          // BOKHASH("クロ")
#define TGT_KID 0xF68F             // BOKHASH("キッド")
#define TGT_MARCELLO 0xCB6B        // BOKHASH("マルチェロ")
#define TGT_LUIS 0x7E5F            // BOKHASH("ルイス")
#define TGT_LADY 0x0A5A            // BOKHASH("レディ")
#define TGT_MEGAMAN 0xB548         // BOKHASH("ロックマン")
#define TGT_SHADEMAN 0x0623        // BOKHASH("シェードマン")
#define TGT_HATENA 0x04B1          // BOKHASH("ハテナ")
#define TGT_SHAIAN 0x8E9F          // BOKHASH("シャイアン")
#define TGT_KURO_B 0x29A0          // BOKHASH("包帯クロ")
#define TGT_KURO_B1 0x3436         // BOKHASH("包帯クロ1")
#define TGT_KURO_B2 0x3437         // BOKHASH("包帯クロ2")
#define TGT_KURO_B3 0x3438         // BOKHASH("包帯クロ3")
#define TGT_MAGIC_MACHINE0 0x1E18  // BOKHASH("魔法機械０")
#define TGT_MAGIC_MACHINE1 0x1E19  // BOKHASH("魔法機械１")
#define TGT_MAGIC_MACHINE2 0x1E1A  // BOKHASH("魔法機械２")
#define TGT_BOKU_B 0x45E5          // BOKHASH("僕B"), 敵のボク
#define TGT_BOKU_C 0x45E6          // BOKHASH("僕C")
#define TGT_BOKU_D 0x45E7          // BOKHASH("僕D")
#define TGT_BOKU_E 0x45E8          // BOKHASH("僕E")
#define TGT_JORMUNGANDR 0xD37F     // BOKHASH("ヨルムンガンド")
#define TGT_BAT_SWARM 0xE534       // BOKHASH("デモバット"), CutsceneBatSwarm
#define TGT_MAGIC_SQUARE 0xB142    // BOKHASH("魔方陣"), ワープ魔方陣

// ---- データの書き方 ----
//
//   MSG(c1_s0_0, WAIT,   BUS_WAIT(60));                         宛先と cmd と引数は本体マクロに書く
//   MSG_F(c1_s2_2, 1, NOWAIT, TO_NPC(TGT_OTNK, 6, 1));       '.f' (unk_4) が 0 でないものは MSG_F
//   STEP(c1_s0) = { M(c1_s0_0), M(c1_s0_1), NULL };
//   CUTSCENE(1) = { sStep_c1_s0, sStep_c1_s1, ..., NULL };
//
// 本体マクロは 引数の個数, 宛先, 種別, cmd, 引数... に展開され, 個数から構造体の型と argc が決まる

// clang-format off
#define CUTSCENE_MSG_SECTION __attribute__((section(".rodata.cutscene_msg")))
#define CUTSCENE_STEP_SECTION __attribute__((section(".rodata.cutscene_step")))
#define CUTSCENE_LIST_SECTION __attribute__((section(".rodata.cutscene_list")))

// 引数の個数 (0..9)
#define CS_NARGS(...) CS_NARGS_(_, ##__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define CS_NARGS_(_, a1, a2, a3, a4, a5, a6, a7, a8, a9, n, ...) n

// 引数の個数 -> 構造体の型
#define CS_TYPE(n) CS_TYPE_(n)
#define CS_TYPE_(n) CS_TYPE_##n
#define CS_TYPE_0 CutsceneMsg0
#define CS_TYPE_1 CutsceneMsg2
#define CS_TYPE_2 CutsceneMsg2
#define CS_TYPE_3 CutsceneMsg4
#define CS_TYPE_4 CutsceneMsg4
#define CS_TYPE_5 CutsceneMsg6
#define CS_TYPE_6 CutsceneMsg6
#define CS_TYPE_7 CutsceneMsg8
#define CS_TYPE_8 CutsceneMsg8
#define CS_TYPE_9 CutsceneMsg10

// 引数の初期化子, 0 個のときは args メンバが無いので何も書かない
#define CS_ARGS(n, ...) CS_ARGS_(n, __VA_ARGS__)
#define CS_ARGS_(n, ...) CS_ARGS_##n(__VA_ARGS__)
#define CS_ARGS_0(...)
#define CS_ARGS_1(...) , { __VA_ARGS__ }
#define CS_ARGS_2(...) , { __VA_ARGS__ }
#define CS_ARGS_3(...) , { __VA_ARGS__ }
#define CS_ARGS_4(...) , { __VA_ARGS__ }
#define CS_ARGS_5(...) , { __VA_ARGS__ }
#define CS_ARGS_6(...) , { __VA_ARGS__ }
#define CS_ARGS_7(...) , { __VA_ARGS__ }
#define CS_ARGS_8(...) , { __VA_ARGS__ }
#define CS_ARGS_9(...) , { __VA_ARGS__ }

#define CS_BODY(target, cls, cmd, ...) CS_NARGS(__VA_ARGS__), target, cls, cmd, ##__VA_ARGS__

#define MSG(name, wait, body) CS_MSG(name, 0, wait, body)
#define MSG_F(name, f, wait, body) CS_MSG(name, f, wait, body)
#define CS_MSG(name, f, wait, ...) CS_MSG_(name, f, wait, __VA_ARGS__)
#define CS_MSG_(name, f, wait, n, target, cls, cmd, ...) \
  static const CS_TYPE(n) CUTSCENE_MSG_SECTION sMsg_##name = { target, cls, wait, f, cmd, n CS_ARGS(n, __VA_ARGS__) }

#define STEP(name) static const MsgPacket* const CUTSCENE_STEP_SECTION sStep_##name[]
#define M(name) (const MsgPacket*)&sMsg_##name
#define CUTSCENE(id) static const MsgPacket* const* const CUTSCENE_LIST_SECTION sCutscene_##id[]

// MsgBus 自身への命令, 宛先は常に TGT_BUS
#define BUS_EXEC_SCRIPT(key) CS_BODY(TGT_BUS, CLS_BUS, BUS_CMD_EXEC_SCRIPT, (s16)(key))  // key は Cmd_StartCutscene の '.p' で登録したもの
#define BUS_WAIT(frames) CS_BODY(TGT_BUS, CLS_BUS, BUS_CMD_WAIT, frames)
#define BUS_WAIT_EXT() CS_BODY(TGT_BUS, CLS_BUS, BUS_CMD_WAIT_EXT)

// 種別ごとの本体, cmd の意味は種別ごとに別物
#define TO_BUS(target, cmd, ...) CS_BODY(target, CLS_BUS, cmd, ##__VA_ARGS__)
#define TO_PLAYER(target, cmd, ...) CS_BODY(target, CLS_PLAYER, cmd, ##__VA_ARGS__)
#define TO_ENEMY(target, cmd, ...) CS_BODY(target, CLS_ENEMY, cmd, ##__VA_ARGS__)
#define TO_BOSS(target, cmd, ...) CS_BODY(target, CLS_BOSS, cmd, ##__VA_ARGS__)
#define TO_NPC(target, cmd, ...) CS_BODY(target, CLS_NPC, cmd, ##__VA_ARGS__)
#define TO_CAMERA(target, cmd, ...) CS_BODY(target, CLS_CAMERA, cmd, ##__VA_ARGS__)
#define TO_EFFECT(target, cmd, ...) CS_BODY(target, CLS_EFFECT, cmd, ##__VA_ARGS__)
#define TO_SOUND(target, cmd, ...) CS_BODY(target, CLS_SOUND, cmd, ##__VA_ARGS__)
#define TO_CBB0(target, cmd, ...) CS_BODY(target, CLS_CBB0, cmd, ##__VA_ARGS__)
#define TO_ETC(target, cmd, ...) CS_BODY(target, CLS_ETC, cmd, ##__VA_ARGS__)

// ---- 名前のついた命令 ----
// tools/dumper/cutscene.ts はこの #define を読み, 種別, cmd, 引数の個数が合うメッセージをこの名前で書く
// 宛先を固定した形 (#define X(a) TO_BOSS(TGT_RINGO, 3, a)) は, その宛先にだけ使う

// NPC, 人物ごとの処理関数 (src/npc/*.c) に共通の番号
#define NPC_TURN(target, dir) TO_NPC(target, 2, dir)                 // dir (8方向) へ少しずつ向き直る
#define NPC_MOVE_TO(target, x, y, z) TO_NPC(target, 3, x, y, z)      // (x, y, z) へ向かう, 多くの人物は歩き, キッド・クロ・スミス・ルイス・マルチェロ・ハテナは state 16 の動き (歩きは cmd 20)
#define NPC_WARP_IN(target) TO_NPC(target, 4)                        // 細長い姿で上から落ちてきて現れる (アニメ表の 5 番, FUN_08042414)
#define NPC_WARP_OUT(target) TO_NPC(target, 5)                       // 縦に伸びながら上へ消える (アニメ表の 6 番, FUN_08042638)
#define NPC_EMOTE(target, kind) TO_NPC(target, 10, kind)             // 頭上に吹き出しを出す, kind は FUN_080415cc
#define NPC_EMOTE_TIMED(target, kind, timer, duration) TO_NPC(target, 10, kind, timer, duration)
#define NPC_SET_POS(target, x, y, z) TO_NPC(target, 41, x, y, z)     // その場で (x, y, z) へ移す

// PLAYER, Player_HandleMessages (src/player.c), 名前は呼んでいる関数から, 未確定のもの (4, 5, 10-13, 20, 36, 37 など) は番号のまま
#define PLAYER_HIDE(target) TO_PLAYER(target, 0)                                         // Player_LockHidden, 操作不能の素立ちで姿と影を隠す
#define PLAYER_SET_POS(target, x, y, z) TO_PLAYER(target, 1, x, y, z)                    // Player_SetPos
#define PLAYER_STAND(target, dir) TO_PLAYER(target, 2, dir)                              // Player_Lock, 今のフォームのまま dir を向いて待機
#define PLAYER_TURN(target, dir) TO_PLAYER(target, 3, dir)                               // Player_LockTurnTo, dir へ振り向く
#define PLAYER_MOVE_TO(target, x, y, z) TO_PLAYER(target, 6, x, y, z)                    // Player_MoveTo, フォームごとの移動で (x, y, z) へ
#define PLAYER_CHARGE_POSE(target, variant) TO_PLAYER(target, 7, variant)                // FUN_0807bbb0, 手前を向いて太陽チャージなどの構え (PACT_UNK_7)
#define PLAYER_END_CHARGE_POSE(target) TO_PLAYER(target, 9)                              // FUN_0807bc64, 構えを解く
#define PLAYER_PULL_COFFIN(target, dir) TO_PLAYER(target, 14, dir)                       // Player_LockPullCoffinTo, その場で棺桶を引く
#define PLAYER_BLOW_AWAY(target, dir, speed, stayDown) TO_PLAYER(target, 16, dir, speed, stayDown)  // Player_LockBlownAway, stayDown が 0 以外なら倒れたまま待つ
#define PLAYER_GET_UP(target) TO_PLAYER(target, 17)                                      // Player_GetUpFromBlownAway
#define PLAYER_KNOCK_PRONE(target, dir, speed) TO_PLAYER(target, 18, dir, speed)         // Player_LockKnockProne, 押し出されてうつ伏せに倒れる
#define PLAYER_WARP_OUT(target) TO_PLAYER(target, 19)  // Player_LockWarpOut, データでは引数なしで送っていて dir は余りの値を読む
#define PLAYER_WARP_IN(target, dir) TO_PLAYER(target, 21, dir)                           // Player_LockWarpIn
#define PLAYER_GUN_READY(target, dir) TO_PLAYER(target, 22, dir)                         // Player_LockGunReady
#define PLAYER_FIRE_GUN(target, dir) TO_PLAYER(target, 23, dir)                          // Player_LockFireGun
#define PLAYER_CHARGE_BUSTER(target, dir, flyTime) TO_PLAYER(target, 24, dir, flyTime)   // Player_LockChargeBuster, ロックバスターを構えて溜める
#define PLAYER_FIRE_BUSTER(target) TO_PLAYER(target, 25)                                 // Player_LockFireBuster
#define PLAYER_REVERT_TO_DARK_DJANGO(target) TO_PLAYER(target, 27)                       // Player_LockRevertToDarkDjango
#define PLAYER_EMOTE(target, kind) TO_PLAYER(target, 28, kind)                           // Player_ShowEmote
#define PLAYER_EMOTE_TIMED(target, kind, timer, duration) TO_PLAYER(target, 28, kind, timer, duration)
#define PLAYER_DASH_TO(target, x, y, z) TO_PLAYER(target, 29, x, y, z)                   // Player_LockDashTo
#define PLAYER_FREEZE(target, unused) TO_PLAYER(target, 38, unused)  // 凍結 (ELEMCOND_HYOKETU) の粒をつける, 引数は読まれない
#define PLAYER_CLEAR_ELEM_COND(target) TO_PLAYER(target, 39)                             // Player_ClearElementalCond
#define PLAYER_FOOT_HITBOX_ON(target) TO_PLAYER(target, 40)
#define PLAYER_FOOT_HITBOX_OFF(target) TO_PLAYER(target, 41)
#define PLAYER_PLTT_PULSE(target, pltt) TO_PLAYER(target, 42, pltt)                      // Player_StartPlttPulse, パレット 0x121 + pltt との間で点滅
#define PLAYER_PLTT_FADE_IN(target, pltt) TO_PLAYER(target, 43, pltt)                    // Player_StartPlttFadeIn, パレット 0x121 + pltt へ寄せたまま保つ
#define PLAYER_STOP_PLTT_FX(target) TO_PLAYER(target, 44)                                // Player_StopPlttEffect

// SOUND, CutsceneSoundManager_HandleMessages (src/cutscene_sound.c), 宛先は TGT_SOUND, 'sub' は音楽プレイヤー P_UNK12 (ループする環境音のような曲に使う)
#define SOUND_PLAY(target, id) TO_SOUND(target, 0, id)                // PlaySound_082406e0
#define SOUND_PLAY_UNTRACKED(target, id) TO_SOUND(target, 1, id)      // 再生中 ID として記録せずに鳴らす
#define SOUND_PLAY_BGM(target, id) TO_SOUND(target, 2, id)            // 音量最大で鳴らし, BGM は再生中なら続ける (Cmd_PlayBGM と同じ)
#define SOUND_FADE_IN_BGM(target, speed) TO_SOUND(target, 3, speed)   // Sound_FadeInBGM
#define SOUND_PAUSE_BGM(target, speed) TO_SOUND(target, 4, speed)     // Sound_FadeOutBGMTemporarily, SOUND_FADE_IN_BGM で再開できる
#define SOUND_FADE_OUT_BGM(target, speed) TO_SOUND(target, 5, speed)  // Sound_FadeOutBGM, 止める
#define SOUND_PLAY_SUB(target, id) TO_SOUND(target, 6, id)
#define SOUND_FADE_IN_SUB(target, speed) TO_SOUND(target, 7, speed)
#define SOUND_PAUSE_SUB(target, speed) TO_SOUND(target, 8, speed)
#define SOUND_FADE_OUT_SUB(target, speed) TO_SOUND(target, 9, speed)

// CAMERA, Camera_PollMessages (src/camera.c), frames が 2 未満ならすぐに切り替える
#define CAMERA_FOLLOW_PLAYER(target) TO_CAMERA(target, 0)                                  // Camera_FollowPlayer, 注視点をプレイヤーに戻す
#define CAMERA_LOOK_AT(target, x, y, z) TO_CAMERA(target, 1, x, y, z)                      // Camera_LookAt, 注視点を (x, y, z) に固定する
#define CAMERA_PAN_TO(target, x, y, z, frames) TO_CAMERA(target, 2, x, y, z, frames)       // Camera_PanTo, frames かけて (x, y, z) へ動かして固定する
#define CAMERA_PAN_TO_PLAYER(target, frames) TO_CAMERA(target, 3, frames)                  // Camera_PanToPlayer, frames かけてプレイヤーへ戻す
#define CAMERA_SHAKE(target, amplitude, frames, stopOnEnd) TO_CAMERA(target, 4, amplitude, frames, stopOnEnd)  // Camera_StartShake, 画面を揺らし始める
#define CAMERA_RELEASE(target, frames) TO_CAMERA(target, 5, frames)                        // Camera_ReleaseLook, frames かけてカメラ本来の位置へ戻し注視をやめる

// EFFECT, CutsceneEffectManager_HandleMessages (src/cutscene_effect.c), フェードのほかに粒の演出と画面揺れも受け持つ
// out が 0 ならフェードイン (フェード色から元へ戻す), 0 以外ならフェードアウト, 長さは 1 << durationShift フレーム, 色は 0..31
// bgLow / bgRow12 / bgHigh が 0 以外なら BG パレットの 0-11 行 / 12 行 / 13-15 行もフェードする
#define EFFECT_RISING_PTCL_AT(target, x, y, z, radius, lifetime, count, kind) TO_EFFECT(target, 0, x, y, z, radius, lifetime, count, kind)  // SparkleEffect_CreateAt, (x, y, z) から粒を湧かせ続ける
#define EFFECT_RISING_PTCL_ON(target, moverID, radius, lifetime, count, kind) TO_EFFECT(target, 1, moverID, radius, lifetime, count, kind)  // 同じ粒を moverID の足元から
#define EFFECT_FADE(target, out, durationShift, r, g, b, bgLow, bgRow12, bgHigh, objSkipMask) TO_EFFECT(target, 2, out, durationShift, r, g, b, bgLow, bgRow12, bgHigh, objSkipMask)  // StartBgObjPlttFade, BG と OBJ を同時にフェード
#define EFFECT_FADE_BG(target, out, durationShift, r, g, b, bgLow, bgRow12, bgHigh) TO_EFFECT(target, 3, out, durationShift, r, g, b, bgLow, bgRow12, bgHigh)  // BgPlttController_PushCommand, BG だけフェード
#define EFFECT_SHAKE(target, frames, amplitude) TO_EFFECT(target, 5, frames, amplitude)  // frames の間 Camera_Shake(amplitude) を続ける, frames が負なら止めるまで
#define EFFECT_STOP_SHAKE(target) TO_EFFECT(target, 6)
#define EFFECT_RINGO_ANIM(target, x, y, z) TO_EFFECT(target, 7, x, y, z)  // RingoCutsceneAnim_Create

// ENEMY, Enemy_PollMessages (src/enedefault.c), 敵の種類によらず共通, cmd 4-7 は敵ごとの処理へ回すので番号のまま
#define ENEMY_TURN(target, dir) TO_ENEMY(target, 1, dir)                                // dir (8方向) と 2 以上ずれていれば振り向く
#define ENEMY_FACE(target, dir) TO_ENEMY(target, 2, dir)                                // すぐに dir を向く
#define ENEMY_EMOTE(target, kind) TO_ENEMY(target, 3, kind)                             // 頭上に吹き出しを出す
#define ENEMY_EMOTE_TIMED(target, kind, timer, duration) TO_ENEMY(target, 3, kind, timer, duration)

// BOSS のリンゴ, Ringo_PollMessages (src/boss/ringo.c), 多くの cmd は演出用のアニメを流すだけなので番号のまま
#define RINGO_HIDE() TO_BOSS(TGT_RINGO, 0)                                              // 当たり判定を消して姿を隠す (state 35)
#define RINGO_STAND(dir) TO_BOSS(TGT_RINGO, 2, dir)                                     // dir を向いて待機アニメ (state 36)
#define RINGO_EMOTE(kind) TO_BOSS(TGT_RINGO, 9, kind)                                   // Boss_ShowEmote
#define RINGO_BACK_AWAY_FROM(x, y, z) TO_BOSS(TGT_RINGO, 13, x, y, z)                   // (x, y, z) の方を向いたまま後ずさる (state 44)
#define RINGO_PLTT_FADE(on) TO_BOSS(TGT_RINGO, 30, on)                                  // on なら Ringo_StartPlttFade, 0 ならいつものパレットに戻す
// clang-format on

#include "data/cutscene/cutscenes.h"

// clang-format off
const MsgPacket* const* const* const gCutsceneTable[125] = {
    sCutscene_0,   sCutscene_1,   sCutscene_2,   sCutscene_3,   sCutscene_4,   sCutscene_5,   sCutscene_6,
    sCutscene_7,   sCutscene_8,   sCutscene_9,   sCutscene_10,  sCutscene_11,  sCutscene_12,  sCutscene_13,
    sCutscene_14,  sCutscene_15,  sCutscene_16,  sCutscene_17,  sCutscene_18,  sCutscene_19,  sCutscene_20,
    sCutscene_21,  sCutscene_22,  sCutscene_23,  sCutscene_24,  sCutscene_25,  sCutscene_26,  sCutscene_27,
    sCutscene_28,  sCutscene_29,  sCutscene_30,  sCutscene_31,  sCutscene_32,  sCutscene_33,  sCutscene_34,
    sCutscene_35,  sCutscene_36,  sCutscene_37,  sCutscene_38,  sCutscene_39,  sCutscene_40,  sCutscene_41,
    sCutscene_42,  sCutscene_43,  sCutscene_44,  sCutscene_45,  sCutscene_46,  sCutscene_47,  sCutscene_48,
    sCutscene_49,  sCutscene_50,  sCutscene_51,  sCutscene_52,  sCutscene_53,  sCutscene_54,  sCutscene_55,
    sCutscene_56,  sCutscene_57,  sCutscene_58,  sCutscene_59,  sCutscene_60,  sCutscene_61,  sCutscene_62,
    sCutscene_63,  sCutscene_64,  sCutscene_65,  sCutscene_66,  sCutscene_67,  sCutscene_68,  sCutscene_69,
    sCutscene_70,  sCutscene_71,  sCutscene_72,  sCutscene_73,  sCutscene_74,  sCutscene_75,  sCutscene_76,
    sCutscene_77,  sCutscene_78,  sCutscene_79,  sCutscene_80,  sCutscene_81,  sCutscene_82,  sCutscene_83,
    sCutscene_84,  sCutscene_85,  sCutscene_86,  sCutscene_87,  sCutscene_88,  sCutscene_89,  sCutscene_90,
    sCutscene_91,  sCutscene_92,  sCutscene_93,  sCutscene_94,  sCutscene_95,  sCutscene_96,  sCutscene_97,
    sCutscene_98,  sCutscene_99,  sCutscene_100, sCutscene_101, sCutscene_102, sCutscene_103, sCutscene_104,
    sCutscene_105, sCutscene_106, sCutscene_107, sCutscene_108, sCutscene_109, sCutscene_110, sCutscene_111,
    sCutscene_112, sCutscene_113, sCutscene_114, sCutscene_115, sCutscene_116, sCutscene_117, sCutscene_118,
    sCutscene_119, sCutscene_120, sCutscene_121, sCutscene_122, sCutscene_123, sCutscene_124,
}; // 0x08DBD564
// clang-format on

// カットシーン表から cutsceneID/step/idx のメッセージを1件引く (どの段でも NULL に当たったら終端)
MsgPacket* CutsceneTable_GetMsg(s32 cutsceneID, s32 step, s32 idx) {
  const MsgPacket* const* const* cutscene;
  const MsgPacket* const* stp;

  cutscene = gCutsceneTable[cutsceneID];
  if (cutscene != NULL) {
    stp = cutscene[step];
    if (stp != NULL) {
      return (MsgPacket*)stp[idx];
    }
  }
  return NULL;
}
