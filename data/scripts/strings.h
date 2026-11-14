#ifndef __DATA_SCRIPTS_STRINGS_H__
#define __DATA_SCRIPTS_STRINGS_H__

// data/scripts/scripts.bokc が StringRef で直接参照している文字列IDだけを定義する
// 名前は src/data/text/*.h の Str_XXXX / Bin_XXXX と同じ

#define Str_SavePrompt 0x0000                // セーブしますか? <ALTER>はい</ALTER>  <ALTER>いいえ</ALTER>
#define Str_0002 0x0002                      // ""
#define Bin_001E 0x001E
#define Bin_001F 0x001F
#define Str_Prologue 0x0020                  // 太陽と月、闇に帰りし時
#define Str_KeySquare 0x0024                 // □
#define Str_KeyTriangle 0x0025               // △
#define Str_KeyCircle 0x0026                 // ○
#define Str_UseKey 0x0028                    // <EXTEND=0>のカギを使った!!
#define Str_KeyDoor 0x002A                   // <MOJISE=MOJISE_SYSTEM>カギがかかっている。扉には<EXTEND=0>が描か…
#define Str_Missions 0x002C                  // <LABEL>敵をみな殺しにしろッ!!</LABEL>
#define Str_GetMapA 0x006A                   // <LABEL>「地図A」を手に入れた!!</LABEL><PROC=1>
#define Str_GetMapB 0x006C                   // <LABEL>「地図B」を手に入れた!!</LABEL><PROC=1>
#define Str_GetMap 0x006E                    // <LABEL>「地図」を手に入れた!!</LABEL><PROC=1>
#define Str_0074 0x0074                      // <LABEL=OTENKO>おてんこさま</LABEL>「大丈夫(だいじょうぶ)か、<NAME>…
#define Str_007C 0x007C                      // <LABEL=OTENKO>おてんこさま</LABEL>「大丈夫(だいじょうぶ)か、<NAME>…
#define Str_0084 0x0084                      // <LABEL=SABATA>サバタ</LABEL>「カーモスの呪(のろ)いか。
#define Str_0089 0x0089                      // <LABEL=NONE>???</LABEL>「呪(のろ)われたようだね、<NAME>・・・
#define Str_008D 0x008D                      // <LABEL=NONE>???</LABEL>「<NAME>・・・
#define Str_PhotoDjangoSolar 0x0094          // <LABEL>「赤<NAME>のブロマイド」を手に入れた!!</LABEL>
#define Str_00CE 0x00CE                      // 暗黒ローンの暗子ちゃん「いつもご利用ありがとうございます。暗黒ローンです。
#define Str_00D3 0x00D3                      // 暗黒ローンの暗子ちゃん「いつもご利用ありがとうございます。暗黒ローンです。
#define Str_00D8 0x00D8                      // 暗黒ローンの暗子ちゃん「いつもご利用ありがとうございます。暗黒ローンです。
#define Str_00DE 0x00DE                      // 暗黒ローンの暗子ちゃん「・・・
#define Str_00E7 0x00E7                      // 暗黒ローンの暗子ちゃん「さあ、着きました。
#define Str_00EB 0x00EB                      // 暗黒ローンの暗子ちゃん「・・・またあなたですか?<NAME>さん・・・
#define Str_00F0 0x00F0                      // 暗黒ローンの暗子ちゃん「・・・<NAME>さん、あなたわざとやっていますね?
#define Str_00F5 0x00F5                      // 暗黒ローンの暗子ちゃん「・・・<NAME>さん、
#define Str_00FC 0x00FC                      // 暗黒ローンの暗子ちゃん「さあ、<NAME>さん。おしおきですよ♥」
#define Str_00FE 0x00FE                      // 暗黒ローンの暗子ちゃん「あなたには今からここで、発電をしてもらいます。
#define Str_0104 0x0104                      // ✚ボタン左
#define Str_0106 0x0106                      // ✚ボタン上
#define Str_0108 0x0108                      // ✚ボタン右
#define Str_010A 0x010A                      // ✚ボタン下
#define Str_010C 0x010C                      // 暗黒ローンの暗子ちゃん「はい、けっこうです!
#define Str_0112 0x0112                      // 暗黒ローンの暗子ちゃん「はい、もうけっこうです。
#define Str_0118 0x0118                      // 暗黒ローンの暗子ちゃん「はい、お疲れさまでした!ご返済ありがとうございます。
#define Str_011C 0x011C                      // 「チョコレート」を手に入れた!!
#define Str_011E 0x011E                      // それでは今後とも暗黒ローンをよろしくお願いします。<PROC=1>ありがとうございました!!」<…
#define Str_0120 0x0120                      // 暗黒ローンの暗子ちゃん「はい、お疲れさまでした!ご返済ありがとうございます。
#define Str_0124 0x0124                      // 「太陽の実」を手に入れた!!
#define Str_0126 0x0126                      // それでは今後とも暗黒ローンをよろしくお願いします。<PROC=1>ありがとうございました!!」<…
#define Str_0128 0x0128                      // 暗黒ローンの暗子ちゃん「はい、お疲れさまでした!ご返済ありがとうございます。
#define Str_012C 0x012C                      // 「魔法薬」を手に入れた!!
#define Str_012E 0x012E                      // それでは今後とも暗黒ローンをよろしくお願いします。<PROC=1>ありがとうございました!!」<…
#define Str_MorningDew 0x0130                // 太陽樹の朝露により・・・
#define Str_MorningDewRecover 0x0132         // ライフとエナジーが回復した!!
#define Str_MorningDewCurseRemoved 0x0134    // カーモスの呪いが解かれた!!
#define Str_0136 0x0136                      // 「ズーボルテルテ」が浄化され「テルテルボーズ」となった!!
#define Str_0138 0x0138                      // <ALTER>クロスオーバーバトル</ALTER>　　<ALTER>　　ゲームの説明　　</AL…
#define Str_013A 0x013A                      // <ALTER>対戦の内容</ALTER>　　<ALTER>対戦の流れ</ALTER> <ALTE…
#define Str_013C 0x013C                      // クロスオーバーバトルでは、
#define Str_0142 0x0142                      // クロスオーバーバトルはラウンド制で行われる。
#define Str_014C 0x014C                      // シェードマンに特定の攻撃を当てると、ライバルにオジャマバットを送ることができる。
#define Str_0152 0x0152                      // ライバルがシェードマンに特定の攻撃を当てると、オジャマバットを送られてしまう。
#define Str_CrossoverBlocking 0x0159         // ブロッキングを使えば、
#define Str_015E 0x015E                      // 対戦の成績に応じて得られるクロスオーバーポイントは、
#define Str_GetMMBNPet 0x0161                // <LABEL>「PET」を手に入れた!!</LABEL>
#define Str_0163 0x0163                      // セーブしますか? <ALTER>はい</ALTER>　<ALTER>いいえ</ALTER>
#define Str_0165 0x0165                      // <LABEL=OTENKO>おてんこさま</LABEL>「もうすぐだな・・・
#define Str_016E 0x016E                      // <LABEL=OTENKO></LABEL>行くぞ、太陽少年<NAME>!!
#define Str_0172 0x0172                      // <LABEL=OTENKO>おてんこさま</LABEL>「まて、<NAME>!!
#define Str_0175 0x0175                      // <LABEL=OTENKO>おてんこさま</LABEL>「ん?
#define Str_0178 0x0178                      // <LABEL=OTENKO></LABEL>ヒントパネルは、先人が残した冒険者(ぼうけんしゃ)へ…
#define Str_017D 0x017D                      // <LABEL=OTENKO>おてんこさま</LABEL>「ここが太陽の街サン・ミゲル
#define Str_0183 0x0183                      // <LABEL=RINGO1>帽子(ぼうし)の男</LABEL>「・・・」
#define Str_0185 0x0185                      // <LABEL=OTENKO>おてんこさま</LABEL>「気をつけろ!!この男は・・・
#define Str_0188 0x0188                      // <LABEL=RINGO1>ヴァンパイア</LABEL>「・・・う!?
#define Str_018B 0x018B                      // <LABEL=RINGO1>ヴァンパイア</LABEL>「たい・・・よう・・・
#define Str_0190 0x0190                      // <LABEL=OTENKO>おてんこさま</LABEL>「太陽銃を奪(うば)われた!?・・・しか…
#define Str_0194 0x0194                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>!!
#define Str_0196 0x0196                      // バカな、なぜヴァンパイアが!?」
#define Str_019A 0x019A                      // <LABEL=OTENKO>おてんこさま</LABEL>「助かった・・・のか?
#define Str_019F 0x019F                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>、
#define Str_01A7 0x01A7                      // <LABEL=OTENKO>おてんこさま</LABEL>「行こう、<NAME>。
#define Str_01AC 0x01AC                      // <LABEL=NONE>黒い影</LABEL>「やはり現われたね。太陽少年<NAME>・・・」
#define Str_01BA 0x01BA                      // <LABEL=OTENKO>おてんこさま</LABEL>「さすがだな、<NAME>!
#define Str_01C7 0x01C7                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>、
#define Str_01CB 0x01CB                      // <LABEL=OTENKO>おてんこさま</LABEL>「グラディウスか・・・ソード(けん)タイ…
#define Str_01D2 0x01D2                      // <LABEL=OTENKO>おてんこさま</LABEL>「太陽機ソル・デ・バイスに月光魔法か・・…
#define Str_01DA 0x01DA                      // <LABEL=ZAJI>魔法少女</LABEL>「あかん、あかんて。
#define Str_01DE 0x01DE                      // <LABEL=ZAJI></LABEL>あ?
#define Str_GetSolorDevice 0x01E4            // 太陽機「ソル・デ・バイス」を手に入れた!!
#define Str_01E6 0x01E6                      // <LABEL=ZAJI>魔法少女</LABEL>「その手甲(てっこう)は太陽機ソル・デ・バイス。
#define Str_01EC 0x01EC                      // <LABEL=ZAJI>魔法少女</LABEL>「ちゃうねん!!ほんまは知ってんねんで?
#define Str_LearnSol 0x01F2                  // <LOCK=106>月光魔法「エンチャント・ソル」を覚えた!!
#define Str_01F4 0x01F4                      // <LABEL=ZAJI>魔法少女</LABEL>「ええか?
#define Str_01FE 0x01FE                      // 自らの目指すべき道に迷うことなかれ。
#define Str_0201 0x0201                      // 危険は事前に察知せよ。
#define Str_Guide_0205 0x0205                // 倒(たお)せ!!
#define Str_0209 0x0209                      // あきらめは死の友と知れ。
#define Str_020D 0x020D                      // 太陽の光、その力を知れ。
#define Str_0210 0x0210                      // 自らのライフ(命)、その限界を知れ。
#define Str_0216 0x0216                      // 自らのエナジー(太陽エネルギー)、その限界を知れ。
#define Str_021F 0x021F                      // 状況(じょうきょう)を理解し、万事に備えよ。
#define Str_0225 0x0225                      // アイテムを集め、有効に活用せよ。
#define Str_Guide_022B 0x022B                // 張りつけ!!
#define Str_GuidePush 0x0231                 // 押(お)せ!!
#define Str_GuideSkylight 0x0235             // 天窓を探し出し、有効に活用せよ。
#define Str_GuideKnock 0x023C                // 叩(たた)け!!
#define Str_Guide_0241 0x0241                // 己の武器を知れ。
#define Str_Guide_0245 0x0245                // 守れ!!
#define Str_GuideBackAttack 0x0249           // 敵の後ろを取れ。
#define Str_ZajiBok1TitleTOS 0x024F          // <LABEL=ZAJI></LABEL>これでトリガー・オブ・ソルやなんて、かあちゃん情けないわ
#define Str_ZajiBok1TitleGunMaster 0x0251    // <LABEL=ZAJI></LABEL>ガンマスターの称号(しょうごう)も返さなあかんなぁ。
#define Str_ZajiBok1TitleDeath 0x0253        // <LABEL=ZAJI></LABEL>コンティニューに頼(たよ)っとるからそんなことになんねん…
#define Str_ZajiBok1TitleBerserker 0x0255    // <LABEL=ZAJI></LABEL>もうちょい考えて行動しぃや。
#define Str_ZajiBok1TitleBishop 0x0257       // <LABEL=ZAJI></LABEL>ザコをなんぼ倒(たお)したかて意味ないで。
#define Str_ZajiBok1TitleQueen 0x0259        // <LABEL=ZAJI></LABEL>アンデッドに情けかけとる場合ちゃうで。
#define Str_ZajiBok1TitleGladiator 0x025B    // <LABEL=ZAJI></LABEL>グラディエーターちゅうのはまぐれなん?
#define Str_ZajiBok1TitleRunningMan 0x025D   // <LABEL=ZAJI></LABEL>暗子ちゃんもあきれとるで。
#define Str_ZajiBok1TitleAkindo 0x025F       // <LABEL=ZAJI></LABEL>太陽商人言うなら、せめて他の武器と交換(こうかん)しぃや…
#define Str_ZajiBok1TitleDjango 0x0261       // <LABEL=ZAJI></LABEL>ほんまはパチモンちゃうん?
#define Str_ZajiBok1TitleSabata 0x0263       // <LABEL=ZAJI></LABEL>太陽嫌(きら)いなん?
#define Str_ZajiBok1TitleKing 0x0265         // <LABEL=ZAJI></LABEL>キングの称号(しょうごう)に泥(どろ)ぬりなや。
#define Str_ZajiBok1TitleLuke 0x0267         // <LABEL=ZAJI></LABEL>称号(しょうごう)ルークが聞いてあきれるわ。
#define Str_ZajiBok1TitleKnight 0x0269       // <LABEL=ZAJI></LABEL>称号(しょうごう)ナイトで満足しとる場合ちゃうで。
#define Str_ZajiBok1TitlePawn 0x026B         // <LABEL=ZAJI></LABEL>称号(しょうごう)ポーンはダテやないな?
#define Str_026D 0x026D                      // 赤の水晶
#define Str_026E 0x026E                      // 青の水晶
#define Str_026F 0x026F                      // 緑の水晶
#define Str_0270 0x0270                      // 黄の水晶
#define Str_0271 0x0271                      // 丸いくぼみがある。何かをはめ込(こ)む穴のようだ
#define Str_0273 0x0273                      // 何をはめ込みますか? <ALTER><EXTEND=0></ALTER>
#define Str_0274 0x0274                      // 何をはめ込みますか? <ALTER><EXTEND=0></ALTER>　<ALTER><EXT…
#define Str_0275 0x0275                      // 何をはめ込みますか? <ALTER><EXTEND=0></ALTER>　<ALTER><EXT…
#define Str_0276 0x0276                      // 何をはめ込みますか? <ALTER><EXTEND=0></ALTER>　<ALTER><EXT…
#define Str_0277 0x0277                      // はまらないようだ・・・
#define Str_0279 0x0279                      // 「<EXTEND=0>」がはまっている。
#define Str_027B 0x027B                      // いつわりの墓、その全てが暴かれるとき、道は開かれる。
#define Str_027E 0x027E                      // よく見ると、メッセージが書き足されている。
#define Str_0281 0x0281
#define Str_0285 0x0285                      // 2つ目の色、それは暗黒なる瞳(ひとみ)、その赤き輝(かがや)き。
#define Str_0289 0x0289                      // 4つ目の色、それは大いなる空と海、その青き輝(かがや)き。
#define Str_028C 0x028C                      // 3つ目の色、それは豊かなる緑、その葉の輝(かがや)き。
#define Str_BookA 0x0290                     // 「暗黒物質と吸血変異」「ヴァンパイア・血の歴史」
#define Str_BookB 0x0292                     // 「ガンマン10ヶ条」「荒野(こうや)の歩き方」
#define Str_BookC 0x0294                     // 「最後の竜・残された言葉」「世紀末の輪廻(りんね)」
#define Str_BookD 0x0296                     // 「太陽の一族・太陽仔の謎」「トロールの姫」
#define Str_BookE 0x0298                     // 「奈落(ならく)のナイトメア」「呪(のろ)いと浄化」
#define Str_BookF 0x029A                     // 「発掘(はっくつ)の魔法機械」「滅びの一族・月光仔の謎」
#define Str_BookG 0x029C                     // 「魔法使いになる方法」「魔法カード・タロット入門」
#define Str_BookH 0x029E                     // 「闇の一族・イモータルの謎」「ユグドラシル幻想」
#define Str_BookI 0x02A0                     // 「ラグナロク大崩壊」「螺旋(らせん)の伝承」
#define Str_02A2 0x02A2                      // 「」「」
#define Str_BookSwitch 0x02A4                // 本の奥にスイッチがある。
#define Str_BookSwitchPrompt 0x02A6          // スイッチを押しますか? <ALTER>押す</ALTER>　<ALTER>押さない</ALTER…
#define Str_BookSwitchDone 0x02A7            // 本の奥のスイッチは、すでに押(お)されている。
#define Str_Guide_02A9 0x02A9                // 壊(こわ)せ!!
#define Str_02AF 0x02AF                      // 火と水が合わさるとき、世界の姿は色となって現れる。
#define Str_Guide_02B3 0x02B3                // 載(の)せろ!!
#define Str_Guide_02B8 0x02B8                // 灯(とも)せ!!
#define Str_Guide_02BC 0x02BC                // 叩(たた)け!!
#define Str_Guide_02C0 0x02C0                // たどり着け!!
#define Str_GuideQuickChange 0x02C3          // クイックチェンジを使いこなせ
#define Str_02C8 0x02C8                      // 上空にいるドゥネイルに攻撃(こうげき)を当てることはできない。
#define Str_02CB 0x02CB                      // 燭台(しょくだい)に火を灯(とも)すには2つの方法がある。
#define Str_02CF 0x02CF                      // <LABEL=OTENKO>おてんこさま</LABEL>「大聖堂はこの奥(おく)か。どこにいる、…
#define Str_02D1 0x02D1                      // <LABEL=OTENKO>おてんこさま</LABEL>「この扉(とびら)を開けるにはカギが必要…
#define Str_02D4 0x02D4                      // <LABEL=OTENKO>おてんこさま</LABEL>「クラブか・・・ハンマー(つち)タイプの…
#define Str_02D8 0x02D8                      // <LABEL=OTENKO>おてんこさま</LABEL>「ここは・・・
#define Str_02DB 0x02DB                      // <LABEL=OTENKO>おてんこさま</LABEL>「ショートスピアか・・・スピア(やり)タ…
#define Str_02E0 0x02E0                      // <LABEL=OTENKO>おてんこさま</LABEL>「この気配は・・・イモータル!!
#define Str_02E3 0x02E3                      // <LABEL=OTENKO>おてんこさま</LABEL>「まて、<NAME>!
#define Str_02E6 0x02E6                      // <LABEL=OTENKO>おてんこさま</LABEL>「カギを手に入れたようだな。
#define Str_02EB 0x02EB                      // <LABEL=OTENKO>おてんこさま</LABEL>「大広間の床絵(ゆかえ)が現れたようだが…
#define Str_02EF 0x02EF                      // <LABEL=OTENKO>おてんこさま</LABEL>「ここが砂漠(さばく)の遺跡(いせき)だ…
#define Str_02F2 0x02F2                      // <NAME>、あのときの借りを返すぞ!!
#define Str_02F5 0x02F5                      // <LABEL=OTENKO>おてんこさま</LABEL>「この暑さ、まさに砂漠だな。
#define Str_02FA 0x02FA                      // <LABEL=OTENKO>おてんこさま</LABEL>「待て、<NAME>!!
#define Str_0300 0x0300                      // <LABEL=OTENKO>おてんこさま</LABEL>「これはワープ魔方陣(まほうじん)・・・
#define Str_0306 0x0306                      // <LABEL>「おいしい水」を手に入れた!!</LABEL>
#define Str_0308 0x0308                      // <LABEL=OTENKO>おてんこさま</LABEL>「待つんだ、<NAME>!!
#define Str_030B 0x030B                      // ヴァンパイアに正面からの攻撃は通じない。
#define Str_030E 0x030E                      // サバタを守り、ブラックホールを完成させろ。
#define Str_0312 0x0312                      // <LABEL=SABATA>サバタ</LABEL>「なぜ俺(おれ)がここにいるのか、不思議に思う…
#define Str_031A 0x031A                      // <LABEL=SABATA>サバタ</LABEL>「ヤツは強い・・・
#define Str_0320 0x0320                      // <LABEL=SABATA>サバタ</LABEL>「道具屋のキッド?あの爆発頭か・・・
#define Str_0324 0x0324                      // <LABEL=SABATA>サバタ</LABEL>「この遺跡(いせき)に残された伝承を知っている…
#define Str_032B 0x032B                      // <LABEL=OTENKO>おてんこさま</LABEL>「大丈夫か、<NAME>!?」
#define Str_BlessingFire 0x032D              // 火の祝福を得た!!
#define Str_LearnDynamite 0x032F             // <PROC=1><LOCK=96>太陽魔法「ダイナマイト」を覚えた!!
#define Str_0334 0x0334                      // <LABEL=KID>キッド</LABEL>「くれぐれも注意しろよ?特に宝箱にはな」
#define Str_0336 0x0336                      // <EXTEND=0>(やられた・・・)
#define Str_0338 0x0338                      // <LABEL=R_DJUNGO><NAME></LABEL>
#define Str_033A 0x033A                      // <LABEL=B_DJUNGO><NAME></LABEL>
#define Str_Guide_033C 0x033C                // 太陽の光をコントロールせよ。
#define Str_Guide_0340 0x0340                // 砕(くだ)け!!
#define Str_Guide_0344 0x0344                // 消せ!!
#define Str_Guide_0347 0x0347                // 溶(と)かせ!!
#define Str_Guide_034A 0x034A                // 属性を使いこなせ。
#define Str_Guide_0351 0x0351                // 突(つ)け!!
#define Str_Guide_0355 0x0355                // 合わせろ!!
#define Str_0358 0x0358                      // 残されたメッセージ
#define Str_035B 0x035B                      // 吹(ふ)き出す炎のために近づくことはできないが、
#define Str_035E 0x035E                      // 音に注意せよ。
#define Str_DesertSlotA 0x0363               // 四角いくぼみがある。何かをはめ込(こ)む穴のようだ
#define Str_DesertSlotB 0x0365               // 石版のかけらをはめ込みますか? <ALTER>はい</ALTER>　<ALTER>いいえ</AL…
#define Str_DesertSlotC 0x0367               // 石版のかけらをはめ込んだ。
#define Str_DesertSlotD 0x0369               // 石版のかけらをはめ込んだ。石版が完成した!!
#define Str_DesertMsgRead 0x036B             // くぼみの下に文字が刻まれている。読んでみますか? <ALTER>はい</ALTER>　<ALTE…
#define Str_DesertMsg 0x036D                 // 遺跡(いせき)を守るため、カギとなる石版を3つに分け砂漠(さばく)に隠(かく)した。
#define Str_DesertMsgA 0x036F                // 2つのドクロの間。
#define Str_DesertMsgB 0x0371                // 朽(く)ちたゴーレムの後ろ。
#define Str_DesertMsgC 0x0373                // サボテンの輪の中。
#define Str_DesertMsgD 0x0375                // サボテンの王の下。
#define Str_DesertMsgE 0x0377                // バットの巣の下。
#define Str_DesertMsgF 0x0379                // 枯(か)れたオアシスの下。
#define Str_DesertMsgG 0x037B                // ミミックの下。
#define Str_DesertMsgH 0x037D                // 群れからはぐれた炎の下。
#define Str_RemainsPuzzle_037F 0x037F        // 影(かげ)を封(ふう)じた4人の兄弟王を称(たた)え、
#define Str_RemainsPuzzle_0383 0x0383        // 火の王の燭台「私は長男であり、最も賢(かしこ)い」
#define Str_RemainsPuzzle_0385 0x0385        // 水の王の燭台「私は最も若く美しい」
#define Str_RemainsPuzzle_0387 0x0387        // 大地の王の燭台「私は火の王よりも若いが、最も力が強い」
#define Str_RemainsPuzzle_0389 0x0389        // 風の王の燭台「私は水の王の兄であり最も素早いが、長男ではない」
#define Str_RemainsPuzzle_038B 0x038B        // 残されたメッセージ
#define Str_RemainsPuzzle_0390 0x0390        // 残されたメッセージ
#define Str_RemainsPuzzle_0397 0x0397        // 残されたメッセージ
#define Str_RemainsPuzzle_039D 0x039D        // 残されたメッセージ
#define Str_RemainsPuzzle_03A3 0x03A3        // 残されたメッセージ
#define Str_RemainsPuzzle_03A8 0x03A8        // 火の試練
#define Str_RemainsPuzzle_03AB 0x03AB        // 水の試練
#define Str_RemainsPuzzle_03AE 0x03AE        // 地の試練
#define Str_RemainsPuzzle_03B1 0x03B1        // 風の試練
#define Str_WarningDog 0x03B4                // 猛犬注意!!
#define Str_WarningOverhead 0x03B9           // 頭上注意!!
#define Str_WarningFeet 0x03BD               // 足元注意!!
#define Str_WarningDark 0x03C1               // 暗闇(くらやみ)注意!!
#define Str_GuideWeightLift 0x03C7           // 重量をコントロールせよ。
#define Str_TaiyoKekkai 0x03CB               // 太陽結界について。
#define Str_03CF 0x03CF                      // ???「<NAME>・・・
#define Str_03D5 0x03D5                      // ???「<NAME>・・・
#define Str_03DC 0x03DC                      // ???「<NAME>・・・
#define Str_03E3 0x03E3                      // ???「<NAME>・・・
#define Str_03EB 0x03EB                      // ???「<NAME>・・・
#define Str_03F2 0x03F2                      // ???「気をつけるんだ、<NAME>・・・
#define Str_DurathrorAdvice1 0x03F9          // 囮(おとり)のつぼみが現れたらつぼみの動きに注目し、ドゥラスロールを探し出せ。
#define Str_DurathrorAdvice2 0x03FC          // ドゥラスロールの後を取れば、
#define Str_TarrotSealed 0x03FF              // タロット封印により閉ざされている。
#define Str_Ringo2Tarrot3 0x0404             // <LABEL=RINGO2>リンゴ</LABEL>「さすがは<NAME>。
#define Str_Ringo2Tarrot2 0x0408             // <LABEL=RINGO2>リンゴ</LABEL>「残りのカードは1枚・・・
#define Str_Ringo2Tarrot1 0x040B             // <LABEL=RINGO2>リンゴ</LABEL>「残りのカードは2枚・・・
#define Str_Ringo2Tarrot0 0x040E             // <LABEL=RINGO2>リンゴ</LABEL>「黒のダーインはこの扉(とびら)の向こうだ。
#define Str_Ringo2TarrotGuide 0x0412         // <LABEL=RINGO2>リンゴ</LABEL>「いいか、<NAME>。
#define Str_DvalinAdvice1 0x0418             // ドヴァリンの弱点は頭だ。
#define Str_DvalinAdvice2 0x041C             // ドヴァリンのダークブレスや墨玉(すみだま)はダーク属性だ。
#define Str_GuideZeroShift 0x041F            // 月光魔法「ゼロシフト」は、瞬間移動を可能にする転移魔法だ
#define Str_GuideBlackSun 0x0422             // 月光魔法「ブラックサン」は、暗黒の欠片を呼び出す召喚(しょうかん)魔法だ。
#define Str_0425 0x0425                      // 像　ら<EXTEND=0>　 マ　　に<VAR=1>　スの　にブロ　　をお
#define Str_0427 0x0427                      // か　　に<VAR=0>　ス<EXTEND=1>　 マ　　所　　　ック　　け。
#define Str_0429 0x0429                      // 南
#define Str_042A 0x042A                      // 北
#define Str_042B 0x042B                      // 東
#define Str_042C 0x042C                      // 西
#define Str_042D 0x042D                      // 壁に何か書いてある。
#define Str_0430 0x0430                      // <LABEL=OTENKO>おてんこさま</LABEL>「覚悟(かくご)はいいな?」 <ALTE…
#define Str_0432 0x0432                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>、
#define Str_0436 0x0436                      // <LABEL=OTENKO>おてんこさま</LABEL>「銀河意志ダーク・・・
#define Str_043C 0x043C                      // <LABEL=SABATA>サバタ</LABEL>「この俺(おれ)が月下美人になろうとはな・・・
#define Str_0446 0x0446                      // <LABEL=SABATA>サバタ</LABEL>「母を失い、父を倒(たお)し、
#define Str_044D 0x044D                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>、
#define Str_0451 0x0451                      // <LABEL=SABATA>サバタ</LABEL>「無事、イモータルを始末したようだな。
#define Str_045F 0x045F                      // <LABEL=SABATA>サバタ</LABEL>「準備はいいな?」 <ALTER>いい</AL…
#define Str_0461 0x0461                      // <LABEL=SABATA>サバタ</LABEL>「時間はないぞ!!早く準備を済ませるんだ!」
#define Str_0463 0x0463                      // <LABEL=SABATA>サバタ</LABEL>「よし!
#define Str_0468 0x0468                      // <LABEL=SABATA>サバタ</LABEL>「何をやっている!!
#define Str_046B 0x046B                      // <LABEL=SABATA>サバタ</LABEL>「時間がない!!
#define Str_046F 0x046F                      // <LABEL=SABATA>サバタ</LABEL>「いいか、<NAME>。
#define Str_0475 0x0475                      // サバタの声「<NAME>!!何をやっている!
#define Str_0478 0x0478                      // サバタの声「<NAME>!!何をやっている!
#define Str_047B 0x047B                      // ダーインの攻撃(こうげき)、ダークブラストは、エリア全体を暗闇(くらやみ)にしてしまう。
#define Str_047E 0x047E                      // 足元からのつかみ攻撃(こうげき)、影(かげ)の腕(うで)に捕(つか)まれば、
#define Str_0482 0x0482                      // <LABEL=DAAIN>黒のダーイン</LABEL>「クッ・・・いまいましい身体だ!
#define Str_0488 0x0488                      // <LABEL=SABATA>サバタ</LABEL>「クロのことなら心配ない。
#define Str_048B 0x048B                      // <LABEL=SABATA>サバタ</LABEL>「悪いが、アイテムはおまえのバッグから使わせて…
#define Str_048F 0x048F                      // <LABEL=KURO_BAN>クロ</LABEL>「・・・」
#define Str_0491 0x0491                      // <LABEL=OTENKO>おてんこさま</LABEL>「どうした、<NAME>?
#define Str_0495 0x0495                      // <LABEL=OTENKO>おてんこさま</LABEL>「そうか、そんなことが・・・
#define Str_049C 0x049C                      // <LABEL=OTENKO>おてんこさま</LABEL>「ロックマン、
#define Str_04A0 0x04A0                      // <LABEL=OTENKO>おてんこさま</LABEL>「シェードマン・・・
#define Str_04A6 0x04A6                      // <LABEL=SABATA>サバタ</LABEL>「何をしている?
#define Str_04AA 0x04AA                      // <LABEL=SABATA>サバタ</LABEL><PROC=1>「フッ、
#define Str_04AF 0x04AF                      // <LABEL=ROCKMAN>ロックマン</LABEL>「<NAME>くん、
#define Str_MMBNKey1 0x04B2                  // 「キーデータ1」を手に入れた!!
#define Str_MMBNKey2 0x04B7                  // 「キーデータ2」を手に入れた!!
#define Str_MMBNKey3 0x04BB                  // 「キーデータ3」を手に入れた!!
#define Str_MMBNKey4 0x04BF                  // 「キーデータ4」を手に入れた!!
#define Str_04C4 0x04C4                      // 2つの塔に挑(いど)め。
#define Str_04D4 0x04D4                      // <LABEL=R_DJUNGO><NAME></LABEL>「あのとき、
#define Str_04D9 0x04D9                      // <LABEL=ZAJI>ザジ</LABEL>「黒きダーイン、やったて?」
#define Str_04DF 0x04DF                      // <LABEL=ZAJI>ザジ</LABEL>「そないなことも・・・
#define Str_04E2 0x04E2                      // <LABEL=R_DJUNGO><NAME></LABEL>「あのとき、
#define Str_04E7 0x04E7                      // <LABEL=RITA>リタ</LABEL>「黒きダーイン、ですか?」
#define Str_04ED 0x04ED                      // <LABEL=RITA>リタ</LABEL>「美しい・・・ですね」
#define Str_04EF 0x04EF                      // <LABEL=R_DJUNGO><NAME></LABEL>「あのとき、
#define Str_04F4 0x04F4                      // <LABEL=R_DJUNGO><NAME></LABEL>「光が強ければ・・・
#define Str_04F9 0x04F9                      // <LABEL=SUMIRE>スミレ</LABEL>「きれい・・・だね♪」
#define Str_04FB 0x04FB                      // <LABEL=R_DJUNGO><NAME></LABEL>「あのとき、
#define Str_0500 0x0500                      // <LABEL=SABATA>サバタ</LABEL>「ヤツが・・・?」
#define Str_0506 0x0506                      // <LABEL=SABATA>サバタ</LABEL><PROC=1>「フッ・・・
#define Str_0509 0x0509                      // <LABEL=R_DJUNGO><NAME></LABEL>「あのとき、
#define Str_050E 0x050E                      // <LABEL=LADY>レディ</LABEL>「例の・・・影のイモータル?」
#define Str_0514 0x0514                      // <LABEL=LADY>レディ</LABEL>「美しい・・・か。
#define Str_JormyAdvice1 0x0517              // 闇(やみ)の力に守られている状態では、ヨルムンガンドにダメージをあたえることはできない
#define Str_JormyAdvice2 0x051A              // ヨルムンガンドの弱点はその舌にある。
#define Str_ShademanAdvice1 0x051D           // 大量のバットを召喚(しょうかん)するシェードマンの特殊攻撃(とくしゅこうげき)、
#define Str_ShademanAdvice2 0x0522           // ウイングストームを放った後のシェードマンには、隙(すき)が生まれる。
#define Str_0525 0x0525                      // <LABEL=SHADEMAN>シェードマン</LABEL>「キ、キキ・・・キサマ!!
#define Str_052F 0x052F                      // <LABEL=SABATA>サバタ</LABEL>「ん?
#define Str_GetJokerCrest 0x0533             // <PROC=1>「ジョーカーの紋章」を手に入れた!!
#define Str_GuideJokerCrest 0x0535           // <LABEL=SABATA>サバタ</LABEL>「そのジョーカーの紋章(もんしょう)を持つ者は…
#define Str_053B 0x053B                      // いらっしゃいませ!
#define Str_054A 0x054A                      // <PROC=2><LABEL=NONE>???</LABEL>「<PROC=8><LOCK=48…
#define Str_0551 0x0551                      // バンクとローンについて <ALTER>太陽スタンド</ALTER>　<ALTER>太陽バンク</…
#define Str_0553 0x0553                      // <LABEL=NONE>太陽バンクの陽子ちゃん</LABEL><PROC=2>「それでは、わたし…
#define Str_055C 0x055C                      // <LABEL=NONE>太陽バンクの陽子ちゃん</LABEL><PROC=2>「それでは、わたし…
#define Str_0563 0x0563                      // <LABEL=NONE>暗黒ローンの暗子ちゃん</LABEL><PROC=1>「それでは、わたし…
#define Str_056C 0x056C                      // <LABEL=NONE>暗黒ローンの暗子ちゃん</LABEL><PROC=1>「それでは、わたし…
#define Str_0578 0x0578                      // <LABEL=NONE>???</LABEL>「あっ、<NAME>さま!!
#define Str_BuyConfirm 0x0581                // これを買いますか?
#define Str_059E 0x059E                      // 太陽鍛冶について <ALTER>太陽鍛冶とは</ALTER>　<ALTER>鍛冶の内容</ALT…
#define Str_05A0 0x05A0                      // 太陽鍛冶(たいようかじ)とは、
#define Str_05A3 0x05A3                      // 太陽鍛冶(たいようかじ)では、
#define Str_05A7 0x05A7                      // 鍛冶(かじ)を行なうにはまず、
#define Str_05AD 0x05AD                      // 武器について <ALTER>鍛冶</ALTER>　<ALTER>クオリティ</ALTER> <A…
#define Str_05AF 0x05AF                      // 太陽鍛冶(たいようかじ)においては、
#define Str_05B3 0x05B3                      // 鍛冶(かじ)による武器の出来の良さ、すなわちクオリティは、
#define Str_05B9 0x05B9                      // 特殊効果(とくしゅこうか)は通常、1つの武器に1つしか付かないが、
#define Str_05C0 0x05C0                      // 武器にはそれぞれにレベルが設定されている。
#define Str_05C4 0x05C4                      // <LABEL=OTENKO>おてんこさま</LABEL>「これは・・・
#define Str_05CE 0x05CE                      // <LABEL=OTENKO>おてんこさま</LABEL>「さあ、
#define Str_05D1 0x05D1                      // <LABEL=OTENKO>おてんこさま</LABEL>「よし!!
#define Str_05D7 0x05D7                      // <LABEL=OTENKO>おてんこさま</LABEL>「準備完了(じゅんびかんりょう)!!」
#define Str_05D9 0x05D9                      // <LABEL=OTENKO>おてんこさま</LABEL>「いいか、<NAME>。
#define Str_05DD 0x05DD                      // <ALTER>出ている</ALTER>　<ALTER>出ていない</ALTER>
#define Str_05DF 0x05DF                      // <LABEL=OTENKO>おてんこさま</LABEL>「よし!!太陽センサーに太陽の光を当て
#define Str_05E2 0x05E2                      // <LABEL=OTENKO>おてんこさま</LABEL>「ううむ・・・
#define Str_05E8 0x05E8                      // <LABEL=OTENKO>おてんこさま</LABEL>「ん?
#define Str_PileDriverTaiyoOtenko 0x05EC     // <LABEL=OTENKO>おてんこさま</LABEL>「太陽ぉーーーーーー!!」
#define Str_PileDriverTaiyoRDjango 0x05EE    // <LABEL=R_DJUNGO><NAME></LABEL>「太陽ぉーーーーーー!!」
#define Str_PileDriverTaiyoBDjango 0x05F0    // <LABEL=B_DJUNGO><NAME></LABEL>「太陽ぉーーーーーー!!」
#define Str_05F2 0x05F2                      // <LABEL=OTENKO>おてんこさま</LABEL>「バトルドライブ開始!!
#define Str_05FA 0x05FA                      // <LABEL=ZAJI>ザジ</LABEL>「サバタ、ええか?
#define Str_05FF 0x05FF                      // <LABEL=OTENKO>おてんこさま</LABEL>「いかん!!イモータルが逃(に)げるぞ!
#define Str_0604 0x0604                      // <LABEL=OTENKO>おてんこさま</LABEL>「まずい!!逃(に)げられたぞ!
#define Str_060A 0x060A                      // <LABEL=OTENKO>おてんこさま</LABEL>「くっ!!がんばれ、<NAME>!
#define Str_0611 0x0611                      // <LABEL=OTENKO>おてんこさま</LABEL>「イモータルの源、
#define Str_PurificationDuneyrr 0x0616       // <LABEL=NONE>白きドゥネイル</LABEL>「そ・・・そんな・・・
#define Str_PurificationDurathror 0x061B     // <LABEL=NONE>赤きドゥラスロール</LABEL>「私の世界に、光はなかった・・・
#define Str_PurificationDvalin 0x0622        // <LABEL=NONE>青きドヴァリン</LABEL>「う・・・く・・・
#define Str_PurificationDainn 0x0628         // <LABEL=NONE>黒きダーイン</LABEL>「クッ・・・
#define Str_0631 0x0631                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>・・・」
#define Str_0633 0x0633                      // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・」
#define Str_0635 0x0635                      // 倉庫を使いますか? <ALTER>はい</ALTER>　<ALTER>いいえ</ALTER>
#define Str_0637 0x0637                      // 何をしますか? <ALTER>倉庫を使う</ALTER>　<ALTER>アクセスする</ALTE…
#define Str_0639 0x0639                      // スミレの人形だ。足の裏に何か書かれている。
#define Str_063C 0x063C                      // アクセスしますか? <ALTER>はい</ALTER>　<ALTER>いいえ</ALTER>
#define Str_063E 0x063E                      // <LABEL=ROCKMAN>ロックマン</LABEL>「やあ、<NAME>くん!!
#define Str_0644 0x0644                      // <LABEL=NONE></LABEL><PROC=1>現在のクロスオーバーポイントは、<VAR…
#define Str_0646 0x0646                      // <VAR=1>ポイント使って、防具と交換(こうかん)しますか?
#define Str_0648 0x0648                      // <ALTER>はい</ALTER>　<ALTER>いいえ</ALTER>
#define Str_064A 0x064A                      // <EXTEND=0>を手に入れた!!
#define Str_064C 0x064C                      // 残りのクロスオーバーポイントは、<VAR=2>ポイントです。
#define Str_064E 0x064E                      // 防具と交換(こうかん)するにはあと<VAR=3>ポイント必要です。
#define Str_0650 0x0650                      // バッグがいっぱいです。防具を減らしてください。
#define Str_0656 0x0656                      // <LABEL=LADY>レディ</LABEL>「とうとうやったわね!
#define Str_065C 0x065C                      // <LABEL=LADY>レディ</LABEL>「とうとうやったわね!
#define Str_0662 0x0662                      // <LABEL=LADY>レディ</LABEL>「とうとうやったわね!
#define Str_0668 0x0668                      // <LABEL=LADY>レディ</LABEL>「とうとうやったわね!
#define Str_066F 0x066F                      // <LABEL=KURO>クロ</LABEL><PROC=1>「ミャア」
#define Str_0671 0x0671                      // <LABEL=KURO>クロ</LABEL><PROC=2>「ミャ?」
#define Str_0673 0x0673                      // <LABEL=KURO>クロ</LABEL><PROC=3>「・・・」
#define Str_0675 0x0675                      // <LABEL=KURO>クロ</LABEL><PROC=2>「ミャ?」 <ALTER>ミャ!</…
#define Str_0677 0x0677                      // <LABEL=KURO_BAN>クロ</LABEL><PROC=1>「ミャア」
#define Str_0679 0x0679                      // <LABEL=KURO_BAN>クロ</LABEL><PROC=2>「ミャ?」
#define Str_067B 0x067B                      // <LABEL=KURO_BAN>クロ</LABEL><PROC=3>「・・・」
#define Str_067D 0x067D                      // <LABEL=KURO_BAN>クロ</LABEL><PROC=2>「ミャ?」 <ALTER>ミ…
#define Str_067F 0x067F                      // <MOJISE=MOJISE_SYSTEM>「ブラックパンサー」ハイスコア　　　　<VAR=1>…
#define Str_0682 0x0682                      // <LABEL=NONE>サバタ</LABEL>「・・・」
#define Str_0684 0x0684                      // <LABEL=NONE>サバタ</LABEL>「カーミラ・・・」
#define Str_0686 0x0686                      // <LABEL=NONE>ザジ</LABEL>「んにゃ・・・?もうちょい寝(ね)かせてぇや」
#define Str_0688 0x0688                      // <LABEL=NONE>ザジ</LABEL><PROC=1>「・・・」
#define Str_068B 0x068B                      // <LABEL=NONE>ザジ</LABEL>「んにゃ・・・?もうちょい寝(ね)かせてぇや」
#define Str_ClosedShop 0x068D                // 閉店中のようだ・・・
#define Str_ClosedLibrary 0x068F             // 閉館中のようだ・・・
#define Str_0691 0x0691                      // カギがかかっている。
#define Str_0693 0x0693                      // <LABEL=ZAJI>ザジ</LABEL>「あぁ、<NAME>。
#define Str_0696 0x0696                      // <LABEL=ZAJI>ザジ</LABEL>「あっ、カン違(ちが)いせんといてや?
#define Str_069A 0x069A                      // <LABEL=RITA>リタ</LABEL>「あっ、<NAME>さま♥
#define Str_069E 0x069E                      // <LABEL=RITA>リタ</LABEL>「・・・
#define Str_06A3 0x06A3                      // <LABEL=SUMIRE>スミレ</LABEL>「あっ、おにいちゃん!!
#define Str_06A6 0x06A6                      // <LABEL=SUMIRE>スミレ</LABEL>「きょうはすきなひとにチョコレートをあげるひな…
#define Str_06A9 0x06A9                      // <LABEL=SABATA>サバタ</LABEL>「どうした、<NAME>。腹でも減ったのか?
#define Str_06AC 0x06AC                      // <LABEL=SABATA>サバタ</LABEL>「チョコレートは旧世界の太陽文明が生み出した回…
#define Str_06AF 0x06AF                      // <LABEL=LADY>レディ</LABEL>「いらっしゃい、<NAME>くん。
#define Str_06B2 0x06B2                      // <LABEL=LADY>レディ</LABEL>「リタちゃんにはないしょね♪」
#define Str_Ruins_06B4 0x06B4                // 赤：?青：?
#define Str_Ruins_06B6 0x06B6                // 赤：1青：2
#define Str_Ruins_06B8 0x06B8                // 赤：2青：1
#define Str_Ruins_06BA 0x06BA                // 赤：3青：0
#define Str_RuinsNavigation 0x06BC           // 左：進む右：戻る
#define Str_06BE 0x06BE                      // ウソじゃないって言ったのに...
#define Str_RuinsSwitches 0x06C0             // 5、7、3、の順にスイッチを入れよ。
#define Str_06C2 0x06C2                      // 残されたメッセージ
#define Str_06C8 0x06C8                      // 心得
#define Str_06CD 0x06CD                      // 太陽の光をコントロールせよ。
#define Str_06D0 0x06D0                      // クロロホルルンが示す時の方向に、4回進め。
#define Str_06D3 0x06D3                      // 太陽の導きに従え。
#define Str_06D5 0x06D5                      // 探せ!!
#define Str_06D8 0x06D8                      // ゼロの光の元で起動せよ。
#define Str_06DA 0x06DA                      // <EXTEND=0>を訪ねます。
#define Str_06DC 0x06DC                      // <EXTEND=0>を訪ねます。
#define Str_06DE 0x06DE                      // <ALTER><EXTEND=1>僕</ALTER>　<ALTER><EXTEND=2>岩</A…
#define Str_06E0 0x06E0                      // <ALTER><EXTEND=1>僕</ALTER>　<ALTER><EXTEND=2>岩</A…
#define Str_06E2 0x06E2                      // <ALTER><EXTEND=1>僕</ALTER>　<ALTER><EXTEND=2>岩</A…
#define Str_06E4 0x06E4                      // <ALTER><EXTEND=1>僕</ALTER>　<ALTER><EXTEND=2>岩</A…
#define Str_06E6 0x06E6                      // 「僕」
#define Str_06E7 0x06E7                      // 「岩」
#define Str_06E8 0x06E8                      // 「犬」
#define Str_06E9 0x06E9                      // 「骨」
#define Str_06EA 0x06EA                      // 「鳥」
#define Str_Treasury_06EC 0x06EC             // <EXTEND=0>岩の間
#define Str_Treasury_06EE 0x06EE             // <EXTEND=1>氷の間
#define Str_Treasury_06F0 0x06F0             // <EXTEND=2>紋章の間
#define Str_Treasury_06F2 0x06F2             // <EXTEND=3>パネルの間
#define Str_06F4 0x06F4                      // パネルの上でＡボタンを押(お)せば、そのパネルと、となり合うパネルが共に色を変える。
#define Str_TimeHouse_06F8 0x06F8            // <LABEL=NONE>???</LABEL>「キミは誰(だれ)・・・?
#define Str_TimeHouse_06FC 0x06FC            // がれきにふさがれて通れそうにない・・・
#define Str_TimeHouse_06FE 0x06FE            // 壊(こわ)せ!!
#define Str_TimeHouse_0703 0x0703            // 時を越(こ)えろ。
#define Str_TimeHouse_0707 0x0707            // 「 * * * * 」暗証番号を入力してください。
#define Str_TimeHouse_0709 0x0709            // 「 <EXTEND=0> <EXTEND=1> <EXTEND=2> <EXTEND=3> 」暗…
#define Str_TimeHouse_070B 0x070B            // 「 <EXTEND=0> <EXTEND=1> <EXTEND=2> <EXTEND=3> 」暗…
#define Str_TimeHouse_070D 0x070D            // 「 <EXTEND=0> <EXTEND=1> <EXTEND=2> <EXTEND=3> 」暗…
#define Str_TimeHouse_070F 0x070F            // 「 * * * * 」 <ALTER>0</ALTER>  <ALTER>1</ALTER>  …
#define Str_TimeHouse_0710 0x0710            // 「 <EXTEND=0> * * * 」 <ALTER>0</ALTER>  <ALTER>1<…
#define Str_TimeHouse_0711 0x0711            // 「 <EXTEND=0> <EXTEND=1> * * 」 <ALTER>0</ALTER>  …
#define Str_TimeHouse_0712 0x0712            // 「 <EXTEND=0> <EXTEND=1> <EXTEND=2> * 」 <ALTER>0<…
#define Str_TimeHouse_0713 0x0713            // 0
#define Str_TimeHouse_0714 0x0714            // 1
#define Str_TimeHouse_0715 0x0715            // 2
#define Str_TimeHouse_0716 0x0716            // 3
#define Str_TimeHouse_0717 0x0717            // 4
#define Str_TimeHouse_0718 0x0718            // 5
#define Str_TimeHouse_0719 0x0719            // 6
#define Str_TimeHouse_071A 0x071A            // 7
#define Str_TimeHouse_071B 0x071B            // 8
#define Str_TimeHouse_071C 0x071C            // 9
#define Str_TimeHouse_071D 0x071D            // ・・・
#define Str_TimeHouse_0720 0x0720            // 暗証番号を設定しますか? <ALTER>はい</ALTER>　<ALTER>いいえ</ALTER…
#define Str_TimeHouse_0722 0x0722            // 暗証番号として、4つの数字を入力してください
#define Str_TimeHouse_0724 0x0724            // 「 <EXTEND=0> <EXTEND=1> <EXTEND=2> <EXTEND=3> 」暗…
#define Str_TimeHouse_0726 0x0726            // 扉はかたく閉ざされている。
#define Str_TimeHouse_0728 0x0728            // <LABEL=NONE>幽霊少年</LABEL>「パパは現在の家の中にいるはずなんだ・・・
#define Str_TimeHouse_072B 0x072B            // <LABEL=NONE>幽霊少年</LABEL>「ゴーストたちがキミの邪魔(じゃま)をするかもし…
#define Str_DreamComplete 0x072E             // 夢幻のすべてを乗り越えた!!
#define Str_DreamLevel 0x0732                // 夢幻街：レベル<VAR=0>
#define Str_DreamGuide1 0x0734               // 夢幻の心得・その1
#define Str_DreamGuide2 0x0739               // 夢幻の心得・その2
#define Str_DreamGuide3 0x0740               // 夢幻の心得・その3
#define Str_DreamGuide4 0x0745               // 夢幻の心得・その4
#define Str_074A 0x074A                      // 財宝を発見した!!
#define Str_074C 0x074C                      // <LABEL=NONE>???</LABEL>「さすがはあいつの忘れ形見・・・
#define Str_0754 0x0754                      // 依頼の実行を中止しますか? <ALTER>はい</ALTER>　<ALTER>いいえ</ALTE…
#define Str_FourSealed 0x0755                // 四方封印により閉ざされている
#define Str_075B 0x075B                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>、イモータルの始末はどうした?
#define Str_075F 0x075F                      // <LABEL=SABATA>サバタ</LABEL>「クロなら無事だ。この先で休ませている」
#define Str_0761 0x0761                      // <LABEL=OTENKO>おてんこさま</LABEL>「外に出たようだな・・・
#define Str_0763 0x0763                      // いいか、<NAME>。エナジーを回復するには太陽の光が必要だが、
#define Str_076A 0x076A                      // <LABEL=OTENKO>おてんこさま</LABEL>「逃(に)げるのか!?
#define Str_076F 0x076F                      // <LABEL=OTENKO>おてんこさま</LABEL>「何という自己再生能力だ!!
#define Str_0773 0x0773                      // <LABEL=OTENKO>おてんこさま</LABEL>「これは・・・
#define Str_0778 0x0778                      // 閉ざされている。まだ、この扉を開けることはできないようだ・・・
#define Str_ArenaRankSelectLv1 0x077A        // どのランクに挑みますか? <ALTER><EXTEND=0>ブロンズ</ALTER>
#define Str_ArenaRankSelectLv2 0x077B        // どのランクに挑みますか? <ALTER><EXTEND=0>ブロンズ</ALTER>　<ALTE…
#define Str_ArenaRankSelectLv3 0x077C        // どのランクに挑みますか? <ALTER><EXTEND=0>ブロンズ</ALTER>　<ALTE…
#define Str_ArenaRankSelectLv4 0x077D        // どのランクに挑みますか? <ALTER><EXTEND=0>ブロンズ</ALTER>　<ALTE…
#define Str_ArenaBronze 0x077E               // ブロンズ
#define Str_ArenaSilver 0x077F               // シルバー
#define Str_ArenaGold 0x0780                 // ゴールド
#define Str_ArenaPlatinum 0x0781             // プラチナ
#define Str_Arena_0782 0x0782                // ★
#define Str_Arena_0783 0x0783
#define Str_Arena_0784 0x0784                // <EXTEND=0>に挑みます。
#define Str_0786 0x0786                      // <LABEL=OTENKO>おてんこさま</LABEL>「ここは・・・
#define Str_078C 0x078C                      // <LABEL=OTENKO></LABEL>これも世紀末現象の成せる業。気を抜(ぬ)くんじゃない…
#define Str_078E 0x078E                      // <LABEL=NONE>???</LABEL>「<NAME>、こんなところで寄り道かい?
#define Str_0794 0x0794                      // <LABEL=NONE>???</LABEL>「<NAME>・・・
#define Str_07A1 0x07A1                      // <LABEL=ZAJI>魔法少女</LABEL>「無事来よったな。くさっても太陽少年や。
#define Str_07A9 0x07A9                      // <LABEL=ZAJI></LABEL>くわしいことは、そこにある暗黒ローンで聞いといてな」
#define Str_07AB 0x07AB                      // <PROC=1>「暗黒カード」を手に入れた!!
#define Str_07AD 0x07AD                      // <LABEL=OTENKO>おてんこさま</LABEL>「なつかしいその言葉使い・・・
#define Str_07B6 0x07B6                      // <LABEL=OTENKO>おてんこさま</LABEL>「世紀末の終わり・・・
#define Str_07B9 0x07B9                      // <LABEL=ZAJI>ザジ</LABEL>「はい・・・」
#define Str_07BB 0x07BB                      // <LABEL=OTENKO>おてんこさま</LABEL>「ううむ・・・
#define Str_07BF 0x07BF                      // <LABEL=ZAJI>ザジ</LABEL>「ところで・・・
#define Str_07C7 0x07C7                      // <LABEL=ZAJI>ザジ</LABEL>「この太陽街に張られた結界のおかげやと思います。
#define Str_07CE 0x07CE                      // <LABEL=OTENKO>おてんこさま</LABEL>「鋼鉄のスミス・・・
#define Str_07D3 0x07D3                      // <LABEL=ZAJI>ザジ</LABEL>「うちの星読みによると、向かった先は北西にある大聖堂…
#define Str_07D8 0x07D8                      // <LABEL=SUMIRE>スミレ</LABEL>「これ・・・」
#define Str_07DD 0x07DD                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>やったっけ?
#define Str_07E1 0x07E1                      // <PROC=2>太陽銃レンズ「フレイム」を取り戻した!
#define Str_LearnFlame 0x07E3                // <PROC=1>月光魔法「エンチャント・フレイム」を覚えた!!
#define Str_07E5 0x07E5                      // <LABEL=OTENKO>おてんこさま</LABEL>「そのレンズが落ちていたということは・・…
#define Str_07EA 0x07EA                      // <LABEL=OTENKO>おてんこさま</LABEL>「今のは・・・」
#define Str_07EC 0x07EC                      // ???<PROC=1><LOCK=44>「お待ちなさい・・・」
#define Str_07EE 0x07EE                      // <LABEL=DUNEYRR>白いコートの女</LABEL>「あなたが太陽少年・・・?かわいらし…
#define Str_07F6 0x07F6                      // <LABEL=OTENKO>おてんこさま</LABEL>「スミス!!」
#define Str_07F9 0x07F9                      // <LABEL=SMITH>スミス</LABEL>「あんたは・・・おお、おてんこ!!」
#define Str_0800 0x0800                      // <LABEL=OTENKO>おてんこさま</LABEL>「そう、
#define Str_080B 0x080B                      // <LABEL=OTENKO>おてんこさま</LABEL>「・・・
#define Str_0810 0x0810                      // <LABEL=OTENKO>おてんこさま</LABEL>「これは・・・くさび?何かの封印(ふうい…
#define Str_081B 0x081B                      // <LABEL=OTENKO>おてんこさま</LABEL>「その猫(ねこ)は?」
#define Str_081D 0x081D                      // <LABEL=SMITH>スミス</LABEL>「こいつはクロ。孫娘(まごむすめ)の友達じゃ。
#define Str_0822 0x0822                      // <LABEL=OTENKO>おてんこさま</LABEL>「ともかく、
#define Str_0827 0x0827                      // <LABEL=OTENKO>おてんこさま</LABEL>「よし、<NAME>!!
#define Str_082C 0x082C                      // <LABEL=NONE>リボンの少女</LABEL>「<NAME>さま!!おてんこさま!!」
#define Str_083B 0x083B                      // <LABEL=RITA></LABEL>わたしにもできる限りのことをさせてください!!」
#define Str_0841 0x0841                      // <LABEL=RITA>リタ</LABEL>「ありがとうございます、おてんこさま・・・」
#define Str_0846 0x0846                      // <LABEL=RITA>リタ</LABEL>「はい・・・
#define Str_084E 0x084E                      // <LABEL=OTENKO>おてんこさま</LABEL>「これで我々の目標は定まった
#define Str_0854 0x0854                      // <LABEL=RITA>リタ</LABEL>「商店街といえば、
#define Str_0857 0x0857                      // <LABEL=RITA></LABEL>わたし、果物屋さんをさせていただくことになったんです!
#define Str_0859 0x0859                      // <LABEL=RITA></LABEL>お店であつかっている太陽の果実は、お2人の冒険(ぼうけん…
#define Str_085B 0x085B                      // <LABEL=RITA></LABEL>ぜひお立ち寄りくださいね、<NAME>さま♪
#define Str_085D 0x085D                      // <LABEL=RITA></LABEL><PROC=1><LOCK=90>いつも心に太陽を!」
#define Str_085F 0x085F                      // <LABEL=OTENKO>おてんこさま</LABEL>「ふっ・・・
#define Str_0863 0x0863                      // <ALTER>うれしい</ALTER>  <ALTER>不安かも</ALTER>
#define Str_0865 0x0865                      // <LABEL=OTENKO>おてんこさま</LABEL>「うむ。
#define Str_0867 0x0867                      // <LABEL=OTENKO></LABEL>彼女(かのじょ)の想いに応えるためにも・・・この戦い…
#define Str_0869 0x0869                      // <LABEL=OTENKO>おてんこさま</LABEL>「そうか・・・
#define Str_086D 0x086D                      // <LABEL=OTENKO>おてんこさま</LABEL>「がんばれよ、<NAME>・・・」
#define Str_086F 0x086F                      // <LABEL=SMITH>スミス</LABEL>「無事、イモータルを浄化(じょうか)したようじゃ…
#define Str_0872 0x0872                      // <LABEL=SUMIRE>スミレ</LABEL>「あの・・・
#define Str_0874 0x0874                      // <LABEL=SUMIRE></LABEL>おじいちゃんをたすけてくれてありがとう!!」
#define Str_0876 0x0876                      // <LABEL=SMITH>スミス</LABEL>「事情はひまわり娘(むすめ)から聞いた。
#define Str_0883 0x0883                      // <LABEL=ZAJI>ザジ</LABEL>「ご苦労やったな、<NAME>!!
#define Str_088C 0x088C                      // <LABEL=ZAJI></LABEL>遺跡はその道を行った先や。
#define Str_0890 0x0890                      // <LABEL=ZAJI></LABEL>ふわぁ・・・ほなうちは休ませてもらうわ。
#define Str_0894 0x0894                      // <LABEL=KID>アフロの男</LABEL>「何だ、またオマエか・・・
#define Str_08A1 0x08A1                      // <ALTER>ヴァンパイアを追っている</ALTER> <ALTER>道に迷っている</ALTE…
#define Str_08A3 0x08A3                      // <LABEL=KID>キッド</LABEL>「なるほど・・・
#define Str_08AB 0x08AB                      // <LABEL=KID>キッド</LABEL>「するってぇと・・・
#define Str_08B7 0x08B7                      // <PROC=2>太陽銃レンズ「フロスト」を取り戻した!
#define Str_LearnFrost 0x08B9                // <PROC=1><LOCK=96>月光魔法「エンチャント・フロスト」を覚えた!!
#define Str_08BB 0x08BB                      // <LABEL=KID>キッド</LABEL>「もう分かっているだろうが、この遺跡には罠(わな)が…
#define Str_08BF 0x08BF                      // <LABEL=OTENKO>おてんこさま</LABEL>「そのレンズ・・・やはりヤツはこの遺跡に…
#define Str_08C2 0x08C2                      // <LABEL=OTENKO>おてんこさま</LABEL>「暗黒少年サバタ!!
#define Str_08C5 0x08C5                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>・・・
#define Str_08C9 0x08C9                      // <LABEL=OTENKO>おてんこさま</LABEL>「どうしてそれを?」
#define Str_08CD 0x08CD                      // <LABEL=OTENKO>おてんこさま</LABEL>「ではあのヴァンパイアと?ヤツはどこに!…
#define Str_08D8 0x08D8                      // <ALTER>引き返す</ALTER>　<ALTER>そうはいかない</ALTER>
#define Str_08DA 0x08DA                      // <LABEL=SABATA>サバタ</LABEL>「・・・
#define Str_08DE 0x08DE                      // <ALTER>引き返す</ALTER>　<ALTER>そうはいかない</ALTER>
#define Str_08E0 0x08E0                      // <LABEL=SABATA>サバタ</LABEL>「どうしても行くというのか?
#define Str_08E6 0x08E6                      // <PROC=2>太陽銃レンズ「クラウド」を取り戻した!
#define Str_LearnCloud 0x08E8                // <PROC=1><LOCK=96>月光魔法「エンチャント・クラウド」を覚えた!!
#define Str_08EA 0x08EA                      // <LABEL=SABATA>サバタ</LABEL>「ヤツはこの先の扉(とびら)の向こうに去った。
#define Str_08ED 0x08ED                      // <LABEL=RINGO1>ヴァンパイア</LABEL>「来るな・・・
#define Str_08F2 0x08F2                      // <LABEL=OTENKO>おてんこさま</LABEL>「これは・・・あのときと同じ!?」
#define Str_08F8 0x08F8                      // <LABEL=DAAIN>黒い影</LABEL><PROC=1><LOCK=57>「クックックッ…
#define Str_08FE 0x08FE                      // <LABEL=RINGO1>ヴァンパイア</LABEL>「ああああああああああ!!」
#define Str_0900 0x0900                      // <LABEL=SABATA>サバタ</LABEL>「何をボサッとしている!<NAME>!!
#define Str_0905 0x0905                      // <LABEL=RINGO2>ヴァンパイア</LABEL>「おまえたちは・・・
#define Str_090A 0x090A                      // <LABEL=RINGO2>ヴァンパイア</LABEL>「・・・
#define Str_090D 0x090D                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>!!
#define Str_090F 0x090F                      // <LABEL=SABATA></LABEL>くっ、ヴァンパイアの血を受け吸血変異が進行している・…
#define Str_0915 0x0915                      // <LABEL=SABATA>サバタ</LABEL>「画面右上にあるのが<NAME>のライフゲージ…
#define Str_0918 0x0918                      // <LABEL=NONE></LABEL><PROC=1>暗黒少年サバタのエナジーは暗黒物質ダーク…
#define Str_091D 0x091D                      // <LABEL=SABATA>サバタ</LABEL>「破壊(はかい)されたくさび・・・
#define Str_0921 0x0921                      // <LABEL=SABATA></LABEL>フッ、やはり死を超越(ちょうえつ)できるのは不死者、…
#define Str_0923 0x0923                      // <LABEL=RITA>リタ</LABEL>「<NAME>さま!?」
#define Str_0925 0x0925                      // <LABEL=ZAJI>ザジ</LABEL>「サバタの言う通り・・・今の<NAME>を助けるには…
#define Str_092A 0x092A                      // <LABEL=RITA>リタ</LABEL>「そんな!!そんなのって・・・」
#define Str_092C 0x092C                      // <LABEL=ZAJI>ザジ</LABEL>「あんた、あいつのこと好きなんやろ?」
#define Str_092E 0x092E                      // <LABEL=RITA>リタ</LABEL>「えっ!!あの、その、わたし・・・」
#define Str_0937 0x0937                      // <LABEL=RITA>リタ</LABEL>「<NAME>さま、そのお身体は・・・!?」
#define Str_093A 0x093A                      // <LABEL=ZAJI>ザジ</LABEL>「サバタ!!」
#define Str_093C 0x093C                      // <PROC=2><LOCK=140>暗黒の力を手に入れた!
#define Str_0944 0x0944                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>、
#define Str_094D 0x094D                      // <LABEL=ZAJI>ザジ</LABEL>「サバタは?」
#define Str_0951 0x0951                      // <LABEL=ZAJI></LABEL>魔女の弟子やっちゅうても、無力なもんや。こんなとき、何も…
#define Str_Shaian_0953 0x0953               // <LABEL=SHAIAN>???</LABEL>「ヴァンパイア・・・
#define Str_Shaian_0956 0x0956               // <LABEL=SHAIAN></LABEL>私はシャイアン。サン・ミゲルの守人、太陽の4士族が風…
#define Str_Shaian_095B 0x095B               // <ALTER>待て!</ALTER>　<ALTER>来い!</ALTER>
#define Str_Shaian_095D 0x095D               // <LABEL=SHAIAN>シャイアン</LABEL>「問答無用!!」
#define Str_Shaian_095F 0x095F               // <LABEL=SHAIAN>シャイアン</LABEL>「おおおおおお!!」
#define Str_Shaian_0961 0x0961               // <LABEL=SHAIAN>シャイアン</LABEL>「まさか、<NAME>なのか・・・!!
#define Str_Shaian_096E 0x096E               // <LABEL=SHAIAN>シャイアン</LABEL>「我ら守人は、古よりこの太陽の街を守ってき…
#define Str_Shaian_0977 0x0977               // <LABEL=SHAIAN>シャイアン</LABEL>「あの植物・・・自然界のものではない。
#define Str_Shaian_097A 0x097A               // <LABEL=SHAIAN></LABEL>このようすでは、3つ目の封印も無事ではあるまい。
#define Str_Shaian_0980 0x0980               // <LABEL=SHAIAN>シャイアン</LABEL>「私の力では、あの暗黒樹にとどめを刺(さ)…
#define Str_Shaian_0988 0x0988               // <LABEL=SHAIAN></LABEL>このカギで1階の扉(とびら)が開く」
#define Str_Shaian_098A 0x098A               // <LABEL=NONE></LABEL><PROC=1>「○のカギ」を手に入れた!!
#define Str_Shaian_098C 0x098C               // <LABEL=SHAIAN>シャイアン</LABEL>「信じているぞ、太陽少年<NAME>!!」
#define Str_Dainn_098E 0x098E                // <LABEL=DAAIN>黒い影</LABEL>「とうとうここまでたどり着いたね。
#define Str_099A 0x099A                      // <LABEL=NONE>???</LABEL>「勝手に俺(おれ)の名を語ってもらっては困るな!」
#define Str_099C 0x099C                      // <LABEL=DAAIN>黒きダーイン</LABEL>「何・・・!!
#define Str_099E 0x099E                      // <LABEL=DAAIN></LABEL>記憶(きおく)が戻(もど)ったのか!?」
#define Str_09A4 0x09A4                      // <LABEL=DAAIN>黒きダーイン</LABEL>「クッ、
#define Str_Durathror_09A7 0x09A7            // <LABEL=DURATHROR>赤毛の少女</LABEL>「黒兄さまもお遊びが過ぎる・・・
#define Str_Durathror_09AC 0x09AC            // <LABEL=DURATHROR></LABEL>捨てられた街、暗黒街。その闇(やみ)が生んだ暗…
#define Str_Durathror_09B5 0x09B5            // <LABEL=DURATHROR>赤きドゥラスロール</LABEL>「・・・光は闇(やみ)を引き…
#define Str_09BA 0x09BA                      // リンゴの声「<NAME>・・・
#define Str_09BD 0x09BD                      // <LABEL=ZAJI>ザジ</LABEL>「それは・・・暗黒樹のイモータル?
#define Str_09C3 0x09C3                      // <ALTER>やる</ALTER>　<ALTER>やらない</ALTER>
#define Str_09C5 0x09C5                      // <LABEL=ZAJI>ザジ</LABEL>「・・・
#define Str_09CC 0x09CC                      // <LABEL=ZAJI>ザジ</LABEL>「・・・
#define Str_09D3 0x09D3                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>!?」
#define Str_09D5 0x09D5                      // <LABEL=NONE>???</LABEL>「<NAME>・・・
#define Str_09DC 0x09DC                      // <LABEL=ZAJI>ひまわり娘</LABEL>「こら<NAME>!!さっさと起きんかい!」
#define Str_09E3 0x09E3                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>、暗黒の力に屈(くっ)するのか?
#define Str_09E9 0x09E9                      // <LABEL=B_DJUNGO><NAME></LABEL>「それこそが・・・
#define Str_09EB 0x09EB                      // <LABEL=B_DJUNGO></LABEL><PROC=1><LOCK=42>ボクらの・・・…
#define Str_09ED 0x09ED                      // <PROC=2><LOCK=176>太陽の力を取り戻した!!
#define Str_09F6 0x09F6                      // <LABEL=ZAJI>ザジ</LABEL>「ほんま、びびらせるんやないで・・・」
#define Str_09F9 0x09F9                      // <LABEL=SUMIRE>スミレ</LABEL>「良かったね、おにいちゃん♪」
#define Str_09FB 0x09FB                      // <LABEL=KID>キッド</LABEL>「オマエがいないと、この街もつまんねーからな」
#define Str_09FE 0x09FE                      // <LABEL=RITA>リタ</LABEL>「<NAME>さま!!わたし・・・
#define Str_0A02 0x0A02                      // <LABEL=SABATA>サバタ</LABEL>「やれやれだな・・・」
#define Str_0A04 0x0A04                      // <LABEL=RITA>リタ</LABEL>「暗黒樹が消えた今、
#define Str_0A07 0x0A07                      // <LABEL=RITA></LABEL>見てください。太陽樹さまの芽がもうこんなに・・・
#define Str_0A09 0x0A09                      // <LABEL=RITA></LABEL>太陽樹さまもお喜びですわ」
#define Str_0A0B 0x0A0B                      // <LABEL=R_DJUNGO><NAME></LABEL>(ドゥラスロール!?)
#define Str_BlessingEarth 0x0A0D             // 大地の祝福を得た!!
#define Str_LearnHealing 0x0A0F              // <PROC=1><LOCK=96>太陽魔法「ヒーリング」を覚えた!!
#define Str_0A13 0x0A13                      // <LABEL=RITA>リタ</LABEL>「今はまだ小さいけれど・・・この新しい太陽樹さまと、
#define Str_0A18 0x0A18                      // <LABEL=SABATA>サバタ</LABEL>「どうだ?
#define Str_0A1B 0x0A1B                      // <LABEL=ZAJI>ザジ</LABEL>「あかんねん・・・
#define Str_0A29 0x0A29                      // <LABEL=ZAJI></LABEL>そや、うちにもできることが、やるべきことがあるんや・・・
#define Str_0A3A 0x0A3A                      // <LABEL=SABATA>サバタ</LABEL>「おい、ひまわり。のどちんこが見えてるぞ?」
#define Str_0A3D 0x0A3D                      // <LABEL=NONE>ザジ</LABEL>「んにゃーーーーーーっ!!」
#define Str_0A3F 0x0A3F                      // <LABEL=RINGO2>リンゴ</LABEL>「<NAME>!?
#define Str_0A45 0x0A45                      // <LABEL=RINGO2></LABEL>ダーインはこの奥だ・・・
#define Str_0A4C 0x0A4C                      // <LABEL=RINGO2>リンゴ</LABEL>「確かに並のイモータルに、この封印を破ることは…
#define Str_0A54 0x0A54                      // <PROC=1>太陽銃レンズ「アース」を取り戻した!
#define Str_LearnEarth 0x0A56                // <PROC=2><LOCK=96>月光魔法「エンチャント・アース」を覚えた!!
#define Str_0A58 0x0A58                      // <LABEL=NONE>???</LABEL>「待て、<NAME>!!そいつは親父ではない!」
#define Str_0A5A 0x0A5A                      // <LABEL=RINGO2>リンゴ</LABEL><PROC=1><LOCK=25>「遅(おそ)…
#define Str_TarrotUnseal 0x0A5C              // 3賢者のカードを使った!
#define Str_TarrotOpen 0x0A5E                // 扉が開いた!!
#define Str_0A60 0x0A60                      // <LABEL=SABATA>サバタ</LABEL>「行かせるか!!」
#define Str_0A62 0x0A62                      // <LABEL=NONE>リンゴの声</LABEL>「ありがとう、<NAME>。
#define Str_0A68 0x0A68                      // <LABEL=RINGO2>リンゴ</LABEL>「遅(おそ)かったな、<NAME>?
#define Str_0A6B 0x0A6B                      // <LABEL=SABATA>サバタ</LABEL>「いいかげんに本当の姿を現したらどうだ。
#define Str_0A75 0x0A75                      // <LABEL=RINGO3>黒のダーイン</LABEL>「イモータルの宿敵にしてキミたちの父親、…
#define Str_0A98 0x0A98                      // <LABEL=PLAYER><NAME></LABEL>(クロ・・・!!)
#define Str_0A9A 0x0A9A                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>!!」
#define Str_Dvalinn_0A9D 0x0A9D              // <LABEL=DVALINN>青いシルエットの女</LABEL>「サバタには逃(に)げられたか・…
#define Str_Dvalinn_0AA3 0x0AA3              // <LABEL=NONE>サバタの声</LABEL>「しっかりしろ、<NAME>!!
#define Str_Dvalinn_0AA5 0x0AA5              // <LABEL=NONE></LABEL>そいつの始末は任せたぞ!俺はヤツを追う!!」
#define Str_0AA7 0x0AA7                      // <LABEL=LADY>???</LABEL>「誰(だれ)かと思えば・・・
#define Str_0AAD 0x0AAD                      // <ALTER>覚えてる</ALTER>　<ALTER>知らない</ALTER>
#define Str_0AAF 0x0AAF                      // <LABEL=LADY>レディ</LABEL>「いい子ね♪
#define Str_0AB4 0x0AB4                      // <LABEL=LADY>レディ</LABEL>「あら、残念ね・・・
#define Str_0AB9 0x0AB9                      // <LABEL=LADY>レディ</LABEL>「タロット封印(ふういん)をすり抜(ぬ)けるなんて…
#define Str_0AC4 0x0AC4                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>!!
#define Str_0ACF 0x0ACF                      // <LABEL=SABATA>サバタ</LABEL>「ここが最上階・・・だが、
#define Str_0AD1 0x0AD1                      // <LABEL=SABATA></LABEL>・・・行き止まりか?
#define Str_0AD5 0x0AD5                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>、
#define Str_0ADF 0x0ADF                      // <LABEL=SABATA>サバタ</LABEL>「行くぞ!!」
#define Str_0AE1 0x0AE1                      // <LABEL=RINGO3>黒きダーイン</LABEL>「やはりドヴァリンでは足止めがいいところ…
#define Str_0AE5 0x0AE5                      // <LABEL=RINGO3>黒きダーイン</LABEL><PROC=1><LOCK=57>「クッ…
#define Str_0AEA 0x0AEA                      // <LABEL=RINGO3>黒きダーイン</LABEL>「やはり何も知らなかったか。
#define Str_0AFC 0x0AFC                      // <LABEL=SABATA>サバタ</LABEL>「いましめの槍と言ったな?ではこの塔が・・・」
#define Str_0B0F 0x0B0F                      // <ALTER>同志になる</ALTER>　<ALTER>断る!!</ALTER>
#define Str_0B11 0x0B11                      // <LABEL=SABATA>サバタ</LABEL>「愚問(ぐもん)だったな!行くぞ、<NAME>…
#define Str_0B15 0x0B15                      // <LABEL=SABATA>サバタ</LABEL>「バカな!?
#define Str_0B19 0x0B19                      // <LABEL=RINGO3>黒きダーイン</LABEL>「ボクが・・・
#define Str_0B23 0x0B23                      // <LABEL=SABATA>サバタ</LABEL>「これで塔は・・・いましめの槍(やり)は元通り…
#define Str_0B28 0x0B28                      // <LABEL=RINGO3>黒きダーイン</LABEL>「嫌(いや)だ・・・
#define Str_0B2E 0x0B2E                      // <LABEL=PLAYER><NAME></LABEL>「ボクは生きる・・・
#define Str_0B34 0x0B34                      // <LABEL=PLAYER></LABEL>そうだよね・・・おとうさん!!」
#define Str_0B36 0x0B36                      // <LABEL=RINGO2>リンゴ</LABEL>「・・・その通りだ!!
#define Str_0B3E 0x0B3E                      // <LABEL=PLAYER><NAME></LABEL>(さようなら、おとうさん・・・)
#define Str_GunMemento 0x0B40                // <LABEL=NONE></LABEL>太陽銃が残された・・・
#define Str_0B42 0x0B42                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>、今のは・・・
#define Str_0B46 0x0B46                      // <LABEL=ZAJI>ザジ</LABEL>「原種の欠片、ヨルムンガンド・・・
#define Str_0B55 0x0B55                      // <LABEL=ZAJI>ザジ</LABEL>「これは・・・!!まさかヨルムンガンドが!?
#define Str_0B59 0x0B59                      // <LABEL=ZAJI>ザジ</LABEL>「まさか・・・この子!?」
#define Str_0B5C 0x0B5C                      // <LABEL=SABATA>サバタ</LABEL>「かつてのダーインの身体、
#define Str_0B5F 0x0B5F                      // <LABEL=SABATA>サバタ</LABEL>「終末の獣は目覚めつつある。
#define Str_0B6A 0x0B6A                      // <LABEL=SABATA></LABEL>体力の回復した今のこいつなら魂の分離(ぶんり)にも耐…
#define Str_0B6D 0x0B6D                      // <LABEL=OTENKO>おてんこさま</LABEL>「ふう、ようやく実体化できたか・・・
#define Str_0B70 0x0B70                      // <LABEL=SABATA>サバタ</LABEL>「フンッ、別にあんたのためじゃない。
#define Str_0B76 0x0B76                      // <LABEL=OTENKO>おてんこさま</LABEL>「ああ、状況(じょうきょう)は分かってい…
#define Str_0B7A 0x0B7A                      // <LABEL=OTENKO>おてんこさま</LABEL>「方法は単純だ。
#define Str_0B80 0x0B80                      // <LABEL=OTENKO>おてんこさま</LABEL>「・・・
#define Str_0B87 0x0B87                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>・・・
#define Str_0B8D 0x0B8D                      // <LABEL=OTENKO>おてんこさま</LABEL>「準備はいいな、<NAME>?」
#define Str_0B8F 0x0B8F                      // <LABEL=OTENKO>おてんこさま</LABEL>「では頼(たの)むぞ、サバタ。
#define Str_0B9C 0x0B9C                      // <LABEL=OTENKO></LABEL>月の2面性、慈愛と狂気。その表裏を使いこなすものこそ…
#define Str_0B9E 0x0B9E                      // <LABEL=SABATA>サバタ</LABEL>「聞け、古の精霊よ!
#define Str_0BA5 0x0BA5                      // <LABEL=OTENKO>おてんこさま</LABEL>「大丈夫(だいじょうぶ)か、サバタ!!」
#define Str_0BA7 0x0BA7                      // <LABEL=SABATA>サバタ</LABEL>「さすがは終末の獣(けもの)、
#define Str_0BAF 0x0BAF                      // <LABEL=OTENKO>おてんこさま</LABEL>「持ちこたえてくれ、サバタ!!
#define Str_0BB2 0x0BB2                      // <LABEL=SABATA>サバタ</LABEL>「さあ、行け!太陽少年<NAME>!!」
#define Str_0BB4 0x0BB4                      // <LABEL=NONE>レディ</LABEL>「闇(やみ)に生まれし者たちよ・・・
#define Str_0BB7 0x0BB7                      // <LABEL=RITA>リタ</LABEL>「さすがですわ!マスター!!」
#define Str_0BBA 0x0BBA                      // <LABEL=RITA>リタ</LABEL>「今度はわたしが・・・!!」
#define Str_0BBC 0x0BBC                      // <LABEL=NONE>リタ</LABEL>「ザコはすっこんでな!!」
#define Str_0BC0 0x0BC0                      // <LABEL=KID>キッド</LABEL>「シャ、シャイアン!!」
#define Str_0BC2 0x0BC2                      // <LABEL=SHAIAN>シャイアン</LABEL>「だからついて来るなと言ったのだ・・・
#define Str_0BC6 0x0BC6                      // <LABEL=OTENKO>おてんこさま</LABEL>「これが原種の欠片・・・ヨルムンガンド!…
#define Str_0BC8 0x0BC8                      // <LABEL=OTENKO>おてんこさま</LABEL>「やはり原種の欠片に理性などはないか・・…
#define Str_0BCD 0x0BCD                      // <LABEL=OTENKO>おてんこさま</LABEL>「やったか・・・!?」
#define Str_0BCF 0x0BCF                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>!!」
#define Str_0BD1 0x0BD1                      // <LABEL=RITA>リタ</LABEL>「<NAME>さま!!」
#define Str_0BD4 0x0BD4                      // <LABEL=SABATA>サバタ</LABEL>「<NAME>!!
#define Str_0BD7 0x0BD7                      // <LABEL=NONE>ザジ</LABEL>「まだ終わってへんで!!」
#define Str_0BD9 0x0BD9                      // <LABEL=LADY>レディ</LABEL>「あきらめてはダメ!!
#define Str_0BDC 0x0BDC                      // <LABEL=SHAIAN>シャイアン</LABEL>「自分の力を信じるんだ!!
#define Str_0BDF 0x0BDF                      // <LABEL=KID>キッド</LABEL>「オレたちはまだ・・・
#define Str_0BE2 0x0BE2                      // <LABEL=SMITH>スミス</LABEL>「おまえまでわしを置いていくつもりなのか!?
#define Str_0BE6 0x0BE6                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>!!
#define Str_0BEB 0x0BEB                      // <LABEL=OTENKO>おてんこさま</LABEL>「これは・・・!!
#define Str_0BEE 0x0BEE                      // <LABEL=ROCKMAN>青い人</LABEL>「・・・くん、
#define Str_0BF4 0x0BF4                      // <ALTER>もちろん</ALTER>　<ALTER>知らない</ALTER>
#define Str_0BF6 0x0BF6                      // <LABEL=ROCKMAN>ロックマン</LABEL>「<NAME>くん!!またキミに会えるな…
#define Str_0BF9 0x0BF9                      // <LABEL=ROCKMAN>青い人</LABEL>「ボクは熱斗くんのネットナビロックマン!!
#define Str_0BFC 0x0BFC                      // <LABEL=ROCKMAN>ロックマン</LABEL>「<NAME>くん、
#define Str_0C03 0x0C03                      // <LABEL=ROCKMAN>ロックマン</LABEL>「ありがとう、<NAME>くん!!
#define Str_0C08 0x0C08                      // <LABEL=SHADEMAN>???</LABEL>「キキキ・・・
#define Str_0C19 0x0C19                      // <LABEL=ROCKMAN>ロックマン</LABEL>「<NAME>くん!!
#define Str_0C1D 0x0C1D                      // <LABEL=ROCKMAN>ロックマン</LABEL>「これで塔を上ることができるね。でも・・…
#define Str_0C22 0x0C22                      // <LABEL=SHADEMAN>シェードマン</LABEL>「キッキッキッ待ちかねたよ、太陽少年…
#define Str_0C28 0x0C28                      // <LABEL=ROCKMAN>ロックマン</LABEL>「何のことだ!?」
#define Str_0C2E 0x0C2E                      // <LABEL=ROCKMAN>ロックマン</LABEL>「そんなバカな・・・!!」
#define Str_0C33 0x0C33                      // <LABEL=ROCKMAN>ロックマン</LABEL>「<NAME>くん!!
#define Str_0C37 0x0C37                      // <LABEL=ROCKMAN>ロックマン</LABEL>「さあ、<NAME>くん、
#define Str_0C3A 0x0C3A                      // <LABEL=SHADEMAN>シェードマン</LABEL>「ぐぬぉぉぉぉぉぉっ!!
#define Str_0C3E 0x0C3E                      // <LABEL=ROCKMAN>ロックマン</LABEL>「<NAME>くん!!
#define Str_0C42 0x0C42                      // <LABEL=ROCKMAN>ロックマン</LABEL>「これは!?」
#define Str_0C44 0x0C44                      // <LABEL=FUTARI><NAME>&ロックマン</LABEL>「いっけーーーーーーっ!!」
#define Str_0C46 0x0C46                      // <LABEL=SHADEMAN>シェードマン</LABEL>「何だとっ!!」
#define Str_0C49 0x0C49                      // <LABEL=SHADEMAN>シェードマン</LABEL>「グォォォォォォォォォッ!!
#define Str_0C4E 0x0C4E                      // <LABEL=ROCKMAN>ロックマン</LABEL>「じゃあ、ボクは行くね。
#define Str_0C59 0x0C59                      // <LABEL=PLAYER><NAME></LABEL>「これは・・・
#define Str_0C5C 0x0C5C                      // ???「ロックマンか・・・
#define Str_0C64 0x0C64                      // <LABEL=RITA>リタ</LABEL>「<NAME>さま!!
#define Str_0C66 0x0C66                      // <LABEL=RITA></LABEL>太陽樹さまがついに成木になられました!
#define Str_0C68 0x0C68                      // <LABEL=RITA></LABEL>これも<NAME>さまのご活躍(かつやく)のおかげですわ…
#define Str_0C6A 0x0C6A                      // <LABEL=RITA>リタ</LABEL>「こちらは太陽樹さまからの贈(おく)り物です。
#define Str_0C6C 0x0C6C                      // <LABEL=RITA></LABEL>どうぞ、お納めください♪」
#define Str_0C6E 0x0C6E                      // <LABEL=RITA>リタ</LABEL>「<NAME>さま!!太陽樹さまが・・・!」
#define Str_0C70 0x0C70                      // <LABEL=RITA>リタ</LABEL>「す、す・・・
#define Str_0C73 0x0C73                      // <LABEL=RITA></LABEL>これも<NAME>さまのご活躍(かつやく)のおかげですわ…
#define Str_0C75 0x0C75                      // <LABEL=RITA>リタ</LABEL>「こちらは太陽樹さまからの贈(おく)り物です。
#define Str_0C77 0x0C77                      // <LABEL=RITA></LABEL>どうぞ、お納めください♪」
#define Str_0C79 0x0C79                      // <LABEL=PEOPLE1>青年</LABEL>「きみは確か・・・
#define Str_0C7D 0x0C7D                      // <LABEL=PEOPLE1>マルチェロ</LABEL>「なるほど・・・
#define Str_0C82 0x0C82                      // <LABEL=PEOPLE3>老人</LABEL>「おぬしは・・・?
#define Str_0C87 0x0C87                      // <LABEL=PEOPLE3>ルイス</LABEL>「ふむ・・・
#define Str_0C8C 0x0C8C                      // <LABEL=PEOPLE2>???</LABEL>「誰(だれ)だ!!
#define Str_0C90 0x0C90                      // <LABEL=PEOPLE2>???</LABEL>「ふうむ・・・
#define Str_0C98 0x0C98                      // <LABEL=PEOPLE2>???</LABEL>「そうだな・・・
#define Str_0C9E 0x0C9E                      // <LABEL=NONE>???</LABEL>「キミは・・・!?」
#define Str_0CA0 0x0CA0                      // <LABEL=NONE>幽霊少年</LABEL>「こんな時空のひずみの中で、よく迷子にならなかっ…
#define Str_0CA4 0x0CA4                      // <ALTER>いいよ</ALTER>　<ALTER>嫌(いや)かも</ALTER>
#define Str_0CA5 0x0CA5                      // <LABEL=NONE>幽霊少年</LABEL>「ありがとう!!
#define Str_0CAC 0x0CAC                      // <LABEL=NONE>幽霊少年</LABEL>「そんな・・・お礼もちゃんとするから!
#define Str_0CAF 0x0CAF                      // <ALTER>いいよ</ALTER>　<ALTER>嫌(いや)かも</ALTER>
#define Str_0CB0 0x0CB0                      // <LABEL=NONE>???</LABEL>「キミは・・・!?」
#define Str_0CB2 0x0CB2                      // <LABEL=NONE>幽霊少年</LABEL>「また会えたね!!
#define Str_0CB9 0x0CB9                      // <ALTER>いいよ</ALTER>　<ALTER>嫌(いや)かも</ALTER>
#define Str_0CBA 0x0CBA                      // <LABEL=NONE>幽霊少年</LABEL>「ありがとう!!
#define Str_0CC1 0x0CC1                      // <LABEL=NONE>幽霊少年</LABEL>「そんな・・・お礼もちゃんとするから!
#define Str_0CC4 0x0CC4                      // <ALTER>いいよ</ALTER>　<ALTER>嫌(いや)かも</ALTER>
#define Str_0CC5 0x0CC5                      // <LABEL=NONE>???</LABEL>「ここは・・・私はいったい何を・・・?
#define Str_0CC8 0x0CC8                      // <LABEL=NONE>???</LABEL>「そうだ、息子は・・・!?」
#define Str_0CCA 0x0CCA                      // <LABEL=NONE>父親の幽霊</LABEL>「<NAME>さん、本当にありがとうございまし…
#define Str_0CCF 0x0CCF                      // <LABEL=NONE>幽霊少年</LABEL>「でもそれはボクを助けるために・・・
#define Str_0CD3 0x0CD3                      // <LABEL=NONE>父親の幽霊</LABEL>「それでも、
#define Str_0CDC 0x0CDC                      // <LABEL=NONE>幽霊少年</LABEL>「それじゃあボクたちは行くね
#define Str_0CDF 0x0CDF                      // <LABEL=NONE>父親の幽霊</LABEL>「<NAME>さん、本当にありがとうございまし…
#define Str_0CE2 0x0CE2                      // <LABEL=NONE>幽霊少年</LABEL>「しっかりしてよ、パパ!!
#define Str_0CE6 0x0CE6                      // <LABEL=NONE>父親の幽霊</LABEL>「ジョルジョ・・・」
#define Str_0CE8 0x0CE8                      // <LABEL=NONE>幽霊少年</LABEL>「それじゃあボクたちは行くね
#define Str_0CEB 0x0CEB                      // <LABEL=SABATA>サバタ</LABEL>「・・・心配ない。
#define Str_0CEF 0x0CEF                      // <LABEL=SUMIRE>スミレ</LABEL>「あっ、おにいちゃん!!
#define Str_0CF6 0x0CF6                      // <LABEL=SABATA></LABEL>スミレ、俺は俺の戦いに行く。もうクロを助けてはやれん…
#define Str_0D03 0x0D03                      // <LABEL=ZAJI>ザジ</LABEL>「何やの!!
#define Str_0D07 0x0D07                      // <LABEL=ZAJI>ザジ</LABEL>「ほんまかんにんや。
#define Str_0D0A 0x0D0A                      // <ALTER>分かった</ALTER>  <ALTER>・・・</ALTER>
#define Str_0D0C 0x0D0C                      // <LABEL=ZAJI>ザジ</LABEL>「さすがは<NAME>!!
#define Str_0D10 0x0D10                      // <LABEL=ZAJI>ザジ</LABEL>「けつの穴の小さいやっちゃなぁ・・・
#define Str_0D14 0x0D14                      // <LABEL=ZAJI>ザジ</LABEL>「そや、あんたに1つ、魔法教えたるわ
#define Str_BlessingFrost 0x0D17             // 水の祝福を得た!
#define Str_LearnFreeze 0x0D19               // <PROC=1><LOCK=96>太陽魔法「フリーズ」を覚えた!!
#define Str_0D1E 0x0D1E                      // <LABEL=ZAJI>ザジ</LABEL>「太陽魔法は月光魔法と違(ちご)てエナジーを使わへん…
#define Str_0D26 0x0D26                      // <LABEL=SUMIRE>スミレ</LABEL>「あっ・・・カギ!そのカギでそうこがあくのよ」
#define Str_0D29 0x0D29                      // 倉庫の扉が開いた!!
#define Str_0D2B 0x0D2B                      // <LABEL=KID>キッド</LABEL>「来たな、ボーイ!!
#define Str_0D2E 0x0D2E                      // <LABEL=KID>キッド</LABEL>「来たな、ボーイ!!
#define Str_0D32 0x0D32                      // <LABEL=SHAIAN>シャイアン</LABEL>「無事帰ったか、<NAME>。
#define Str_0D37 0x0D37                      // <LABEL=SHAIAN>シャイアン</LABEL>「もう大丈夫(だいじょうぶ)なようだな、<…
#define Str_0D3C 0x0D3C                      // <LABEL=SHAIAN>シャイアン</LABEL>「待っていたぞ。
#define Str_0D3F 0x0D3F                      // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃんが・・・
#define Str_0D44 0x0D44                      // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃん、ねてなきゃダメよう!」
#define Str_0D46 0x0D46                      // <LABEL=SUMIRE>スミレ</LABEL>「おにいちゃん、ぬれてるよ?
#define Str_0D4A 0x0D4A                      // <LABEL=SUMIRE></LABEL>これあげる!」
#define Str_0D4E 0x0D4E                      // <LABEL=SUMIRE>スミレ</LABEL>「これであんしんだね♪」
#define Str_0D50 0x0D50                      // <LABEL=SHAIAN>シャイアン</LABEL>「よく来たな。
#define Str_0D57 0x0D57                      // <LABEL=OTENKO>おてんこさま</LABEL>「よし、ここだ。
#define Str_0D5A 0x0D5A                      // <LABEL=OTENKO>おてんこさま</LABEL>「あの黒猫(くろねこ)・・・気になるな。
#define Str_0D5E 0x0D5E                      // <LABEL=OTENKO>おてんこさま</LABEL>「白きドゥネイル・・・
#define Str_0D63 0x0D63                      // <LABEL=OTENKO>おてんこさま</LABEL>「やはりあの黒猫(くろねこ)のことが気に…
#define Str_0D66 0x0D66                      // <LABEL=OTENKO>おてんこさま</LABEL>「ここが地下最下層・・・何という瘴気(し…
#define Str_0D6A 0x0D6A                      // <LABEL=OTENKO></LABEL>急ぐぞ、<NAME>!!
#define Str_0D6F 0x0D6F                      // <LABEL=OTENKO>おてんこさま</LABEL>「ここだ・・・ここが塔の先端(せんたん)…
#define Str_0D72 0x0D72                      // <LABEL=OTENKO></LABEL>原種の欠片、エターナルであるヨルムンガンドを倒(たお…
#define Str_0D79 0x0D79                      // 封印されている。まだ、この本を読むことはできないようだ・・・
#define Str_0D7B 0x0D7B                      // 追憶の書
#define Str_0D7D 0x0D7D                      // <ALTER>総合記録</ALTER>　<ALTER>浄化記録</ALTER> <ALTER>通…
#define Str_0D7E 0x0D7E                      // <ALTER>総合記録</ALTER>　<ALTER>浄化記録</ALTER> <ALTER>通…
#define Str_0D80 0x0D80                      // 「総合記録」稼働時間　　    <VAR=0>：<VAR=1><VAR=2>プレイタイム    …
#define Str_0D88 0x0D88                      // 「浄化記録」倒した敵の数      <VAR=0>体
#define Str_0D96 0x0D96                      // 「通信販売」売った武器        <VAR=0>個買った武器        <VAR=1>個
#define Str_0D99 0x0D99                      // 「通信対戦」対戦ポイント      <VAR=0>pt
#define Str_0D9D 0x0D9D                      // 「クロスオーバーバトル」クロスオーバーポイント　　　　　　　<VAR=0>pt
#define Str_0DA1 0x0DA1                      // 太陽銃ガン・デル・ソルの継承者、太陽少年。太陽機ソル・デ・バイスをも使いこなす。その身にまとうは…
#define Str_0DBC 0x0DBC                      // 赤<NAME>
#define Str_0DD8 0x0DD8                      // クモの巣を張る。
#define Str_0E11 0x0E11                      // 「廃墟」の依頼書
#define Str_0E13 0x0E13                      // ★「廃墟」の依頼書★
#define Str_0E15 0x0E15                      // 「森」の依頼書
#define Str_0E17 0x0E17                      // ★「森」の依頼書★
#define Str_0E19 0x0E19                      // 「地下墓地」の依頼書
#define Str_0E1B 0x0E1B                      // ★「地下墓地」の依頼書★
#define Str_0E1D 0x0E1D                      // 「時の家」の依頼書
#define Str_0E1F 0x0E1F                      // ★「時の家」の依頼書★
#define Str_0E21 0x0E21                      // 「???」の依頼書
#define Str_0E24 0x0E24                      // ★
#define Str_0E25 0x0E25
#define Str_0E27 0x0E27                      // <EXTEND=1><ALTER>潜入任務・その1</ALTER>   ???   ???
#define Str_0E28 0x0E28                      // <EXTEND=1><ALTER>潜入任務・その1</ALTER><EXTEND=2><ALTE…
#define Str_0E29 0x0E29                      // <EXTEND=1><ALTER>潜入任務・その1</ALTER><EXTEND=2><ALTE…
#define Str_0E2A 0x0E2A                      // <EXTEND=4><ALTER>潜入任務・その2</ALTER>   ???   ???
#define Str_0E2B 0x0E2B                      // <EXTEND=4><ALTER>潜入任務・その2</ALTER><EXTEND=5><ALTE…
#define Str_0E2C 0x0E2C                      // <EXTEND=4><ALTER>潜入任務・その2</ALTER><EXTEND=5><ALTE…
#define Str_0E2D 0x0E2D                      // <EXTEND=7><ALTER>墓守</ALTER>   ???   ???
#define Str_0E2E 0x0E2E                      // <EXTEND=7><ALTER>墓守</ALTER><EXTEND=8><ALTER>挑戦状・…
#define Str_0E2F 0x0E2F                      // <EXTEND=7><ALTER>墓守</ALTER><EXTEND=8><ALTER>挑戦状・…
#define Str_0E30 0x0E30                      // <EXTEND=10><ALTER>戦術指南・その2</ALTER>   ???   ???
#define Str_0E31 0x0E31                      // <EXTEND=10><ALTER>戦術指南・その2</ALTER><EXTEND=11><AL…
#define Str_0E32 0x0E32                      // <EXTEND=10><ALTER>戦術指南・その2</ALTER><EXTEND=11><AL…
#define Str_0E33 0x0E33                      // <MOJISE=MOJISE_SYSTEM>   ???   ???   ???
#define Str_0E36 0x0E36                      // 廃墟(はいきょ)の下、閉ざされた扉の先にあるという財宝を探し出してほしい。
#define Str_0E39 0x0E39                      // 徒手空拳(としゅくうけん)を極めるには修練あるのみです。
#define Str_0E3C 0x0E3C                      // 実は私、トラップマスターでもあるのよね。
#define Str_0E40 0x0E40                      // 森の中、館の奥(おく)に眠(ねむ)るという財宝を探し出してほしい。
#define Str_0E43 0x0E43                      // ダンジョンの中の仕掛(しか)けを利用したり、同士討ちをさせれば、
#define Str_0E47 0x0E47                      // おまえの実力がどれほどのものか、試させてもらうぜ?
#define Str_0E4C 0x0E4C                      // 吸血変異によって復活したモンスターどもが、地下墓地からあふれだそうとしている。
#define Str_0E4F 0x0E4F                      // やるな、ボーイ!!さすがにまともに戦ったら勝ち目はないぜ。
#define Str_0E54 0x0E54                      // 地下の墓、その奥(おく)に眠(ねむ)るという財宝を探し出してほしい。
#define Str_0E58 0x0E58                      // アイテムをうまく利用すれば、
#define Str_0E5C 0x0E5C                      // さすがだな、ボーイ!!やっぱオレのかなう相手じゃないぜ。
#define Str_0E60 0x0E60                      // 過去にて待つ。
#define Str_0E63 0x0E63                      // この依頼を受けますか? <ALTER>はい</ALTER>　<ALTER>いいえ</ALTER>…
#define Str_0E65 0x0E65                      // 新たな依頼を受ける前に、前回の報酬(ほうしゅう)を受け取ってください。
#define Str_Lady_0E67 0x0E67                 // <LABEL=LADY>レディ</LABEL>「その前に前回の報酬(ほうしゅう)を受け取ってね?…
#define Str_Lady_0E69 0x0E69                 // <LABEL=LADY>レディ</LABEL>「それじゃあがんばってね、<NAME>くん♪」
#define Str_Lady_0E6B 0x0E6B                 // <LABEL=LADY>レディ</LABEL>「大丈夫(だいじょうぶ)、<NAME>くん?
#define Str_Lady_0E6F 0x0E6F                 // <LABEL=LADY>レディ</LABEL>「やったわね、<NAME>くん!!
#define Str_Library_0E72 0x0E72              // 調査記録
#define Str_Library_0E74 0x0E74              // ★調査記録★
#define Str_Library_0E76 0x0E76              // 封印されている。まだ、この本を読むことはできないようだ・・・
#define Str_Library_0E78 0x0E78              // <ALTER>イモータルダンジョン</ALTER>  <VAR=0>/6 <ALTER>アンデッ…
#define Str_Library_0E7A 0x0E7A              // ★ <ALTER>イモータルダンジョン</ALTER>  <VAR=0>/6★ <ALTER>ア…
#define Str_Library_0E7C 0x0E7C              // ★ <ALTER>イモータルダンジョン</ALTER>  <VAR=0>/6   <ALTER>…
#define Str_Library_0E7E 0x0E7E              // <ALTER>イモータルダンジョン</ALTER>  <VAR=0>/6★ <ALTER>アンデ…
#define Str_Library_0E80 0x0E80              // <EXTEND=0><EXTEND=1><EXTEND=2><EXTEND=3><EXTEND=…
#define Str_Library_0E83 0x0E83              // <EXTEND=0><EXTEND=1><EXTEND=2><EXTEND=3><EXTEND=…
#define Str_Library_0E88 0x0E88              // 大聖堂
#define Str_Library_0E89 0x0E89              // 遺跡
#define Str_Library_0E8A 0x0E8A              // 暗黒街
#define Str_Library_0E8B 0x0E8B              // 地下水路
#define Str_Library_0E8C 0x0E8C              // 螺旋の塔
#define Str_Library_0E8D 0x0E8D              // 変異域
#define Str_Library_0E8E 0x0E8E              // ★大聖堂
#define Str_Library_0E8F 0x0E8F              // ★遺跡
#define Str_Library_0E90 0x0E90              // ★暗黒街
#define Str_Library_0E91 0x0E91              // ★地下水路
#define Str_Library_0E92 0x0E92              // ★螺旋の塔
#define Str_Library_0E93 0x0E93              // ★変異域
#define Str_Library_0E94 0x0E94              // 廃墟
#define Str_Library_0E95 0x0E95              // 森
#define Str_Library_0E96 0x0E96              // 地下墓地
#define Str_Library_0E97 0x0E97              // 時の家
#define Str_Library_0E98 0x0E98              // 宝物庫
#define Str_Library_0E99 0x0E99              // 夢幻街
#define Str_Library_0E9A 0x0E9A              // 闘技場
#define Str_Library_0E9B 0x0E9B              // ★廃墟
#define Str_Library_0E9C 0x0E9C              // ★森
#define Str_Library_0E9D 0x0E9D              // ★地下墓地
#define Str_Library_0E9E 0x0E9E              // ★時の家
#define Str_Library_0E9F 0x0E9F              // ★宝物庫
#define Str_Library_0EA0 0x0EA0              // ★夢幻街
#define Str_Library_0EA1 0x0EA1              // ★闘技場
#define Str_Library_0EA2 0x0EA2              // ???
#define Str_Library_0EA3 0x0EA3              // 未調査
#define Str_Library_0EA4 0x0EA4              // 調査中
#define Str_Library_0EA5 0x0EA5              // 調査完了
#define Str_LibraryWelcome 0x0EA6            // 図書館へようこそ!!
#define Str_LibraryBookUnlocked 0x0EB0       // 封印されている。まだ、この本を読むことはできないようだ・・・
#define Str_LibraryTitle 0x0EB2              // <MOJISE=MOJISE_SYSTEM>          称号記録
#define Str_LibraryTitleCompleted 0x0EB9     // <MOJISE=MOJISE_SYSTEM>        ★称号記録★
#define Str_LibraryTitleUnlocked 0x0EC1      // ???
#define Str_LibraryTitleSwordMaster 0x0EC2   // ソードマスター
#define Str_LibraryTitleSpearMaster 0x0EC3   // スピアマスター
#define Str_LibraryTitleHammerMaster 0x0EC4  // ハンマーマスター
#define Str_LibraryTitleFistMaster 0x0EC5    // フィストマスター
#define Str_LibraryTitleGunMaster 0x0EC6     // ガンマスター
#define Str_LibraryTitleAdept 0x0EC7         // アデプト
#define Str_LibraryTitleDayWalker 0x0EC8     // デイウォーカー
#define Str_LibraryTitleAdventurer 0x0EC9    // アドベンチャラー
#define Str_LibraryTitleAgent 0x0ECA         // エージェント
#define Str_LibraryTitleCollector 0x0ECB     // コレクター
#define Str_LibraryTitleDarkHunter 0x0ECC    // ダークハンター
#define Str_LibraryTitleGrandMaster 0x0ECD   // グランドマスター
#define Str_CoffinSeller_0ECE 0x0ECE         // <LABEL=COFFIN>棺桶屋</LABEL>「やあ・・・がんばってるみたいだね。
#define Str_CoffinSeller_0ED5 0x0ED5         // <LABEL=COFFIN>棺桶屋</LABEL>「いいところに来たね・・・
#define Str_CoffinSeller_0ED9 0x0ED9         // <LABEL=COFFIN>棺桶屋</LABEL>「いいところに来たね・・・
#define Str_CoffinSeller_0EDF 0x0EDF         // <LABEL=COFFIN>棺桶屋</LABEL>「いいところに来たね・・・
#define Str_CoffinSeller_0EE4 0x0EE4         // <LABEL=COFFIN>棺桶屋</LABEL>「・・・
#define Str_CoffinSeller_0EE6 0x0EE6         // <LABEL=COFFIN>棺桶屋</LABEL>「やあ・・・
#define Str_CoffinSeller_0EE8 0x0EE8         // <LABEL=COFFIN></LABEL>棺桶(かんおけ)買うかい?古い棺桶は下取りするよ?」
#define Str_CoffinSellerPrompt 0x0EEA        // <ALTER>買う</ALTER>　<ALTER>買わない</ALTER>
#define Str_CoffinSeller_0EEC 0x0EEC         // <LABEL=COFFIN>棺桶屋</LABEL>「うん、君ほど棺桶が似合う少年はいないな。
#define Str_CoffinSeller_0EF0 0x0EF0         // <LABEL=COFFIN>棺桶屋</LABEL>「やはりいい・・・
#define Str_CoffinSeller_0EF4 0x0EF4         // <LABEL=COFFIN>棺桶屋</LABEL>「君にぴったりの棺桶があるんだがなぁ・・・」
#define Str_CoffinSeller_0EF6 0x0EF6         // <LABEL=COFFIN>棺桶屋</LABEL>「残念だな・・・
#define Str_Ennio_0EFA 0x0EFA                // <LABEL=CLOCK>時計塔管理人</LABEL>「何じゃ、小僧(こぞう)・・・この死の街で…
#define Str_Ennio_0EFF 0x0EFF                // <LABEL=CLOCK>エンニオ</LABEL>「何?時間がずれとるじゃと?
#define Str_Ennio_0F02 0x0F02                // <ALTER>狂ってる</ALTER>　<ALTER>狂ってない</ALTER>
#define Str_Ennio_0F04 0x0F04                // <LABEL=CLOCK>エンニオ</LABEL>「ううむ・・・仕方ないのう。
#define Str_Ennio_0F0A 0x0F0A                // <LABEL=CLOCK>エンニオ</LABEL>「またか・・・仕方ないのう。
#define Str_Ennio_0F0E 0x0F0E                // <LABEL=CLOCK></LABEL>どうする、小僧(こぞう)?時計を直すのか?」
#define Str_Ennio_0F10 0x0F10                // <ALTER>直す</ALTER>　<ALTER>直さない</ALTER>
#define Str_Ennio_0F12 0x0F12                // <LABEL=CLOCK>エンニオ</LABEL>「これでよし!!まったく骨が折(お)れるわい。
#define Str_Ennio_0F15 0x0F15                // <LABEL=CLOCK>エンニオ</LABEL>「何じゃ、冷やかしか?
#define Str_Ennio_0F1C 0x0F1C                // <LABEL=CLOCK></LABEL>何?
#define Str_Ennio_0F1F 0x0F1F                // <LABEL=CLOCK></LABEL>何?その話は前にも聞いたじゃと?
#define Str_Ennio_0F21 0x0F21                // <LABEL=CLOCK></LABEL>ええい、口の減らん小僧(こぞう)じゃな!
#define Str_Ennio_0F25 0x0F25                // <LABEL=CLOCK>エンニオ</LABEL>「ダメじゃ、ダメじゃ!!
#define Str_Kid_0F31 0x0F31                  // <LABEL=KID>キッド</LABEL>「よう、買い物かい?」 <ALTER>買い物</AL…
#define Str_Kid_0F33 0x0F33                  // <LABEL=KID>キッド</LABEL>「サンキュー!!
#define Str_Kid_0F36 0x0F36                  // <LABEL=KID>キッド</LABEL>「サンキュー!!
#define Str_Kid_0F3A 0x0F3A                  // <LABEL=KID>キッド</LABEL>「調子はどうだい、ボーイ?
#define Str_Kid_0F3D 0x0F3D                  // <LABEL=KID>キッド</LABEL>「そういえばここに戻(もど)る途中(とちゅう)、
#define Str_Kid_0F42 0x0F42                  // <LABEL=KID>キッド</LABEL>「ステータス異常って知ってるか?
#define Str_Kid_0F4B 0x0F4B                  // <LABEL=KID>キッド</LABEL>「まさかオマエがヴァンパイアになっていたとはな・・・
#define Str_Kid_0F50 0x0F50                  // <LABEL=KID>キッド</LABEL>「ボーイ、おまえゲームオーバーになったことはあるか?
#define Str_Kid_0F56 0x0F56                  // <LABEL=KID>キッド</LABEL>「ウチの店であつかっている回復アイテムは、
#define Str_Kid_0F5A 0x0F5A                  // <LABEL=KID>キッド</LABEL>「チョコレートはくさりはしないが熱には弱い。
#define Str_Kid_0F5F 0x0F5F                  // <LABEL=KID>キッド</LABEL>「聞いたぜ、ボーイ。
#define Str_Kid_0F67 0x0F67                  // <LABEL=KID>キッド</LABEL>「防具を装備すれば敵からのダメージを減らすことができ…
#define Str_Kid_0F6B 0x0F6B                  // <LABEL=KID>キッド</LABEL>「知ってるか?
#define Str_Shaian_0F82 0x0F82               // <LABEL=SHAIAN>シャイアン</LABEL>「<NAME>、
#define Str_BlessingWind 0x0F86              // 風の祝福を得た!
#define Str_LearnDash 0x0F88                 // <PROC=1>太陽魔法「ダッシュ」を覚えた!!
#define Str_Shaian_0F8D 0x0F8D               // <LABEL=SHAIAN>シャイアン</LABEL>「それから例のくさびについていくつか分かっ…
#define Str_Shaian_0F9D 0x0F9D               // <LABEL=SHAIAN>シャイアン</LABEL>「それから例のくさびについていくつか分かっ…
#define Str_Shaian_0FA6 0x0FA6               // <LABEL=SHAIAN>シャイアン</LABEL>「よく来たな、<NAME>」 <ALTER…
#define Str_Shaian_0FA8 0x0FA8               // <LABEL=SHAIAN>シャイアン</LABEL>「うむ。
#define Str_Shaian_0FAD 0x0FAD               // <LABEL=SHAIAN>シャイアン</LABEL>「うむ。
#define Str_Shaian_0FB2 0x0FB2               // <LABEL=SHAIAN>シャイアン</LABEL>「通信販売(つうしんはんばい)では、
#define Str_Shaian_0FB9 0x0FB9               // <LABEL=SHAIAN>シャイアン</LABEL>「くさびの封印(ふういん)についてはまだ調…
#define Str_Shaian_0FBD 0x0FBD               // <LABEL=SHAIAN>シャイアン</LABEL>「武器を手に入れるにはいくつかの方法がある…
#define Str_Shaian_0FC1 0x0FC1               // <LABEL=SHAIAN>シャイアン</LABEL>「レディを覚えているか?
#define Str_Shaian_0FC9 0x0FC9               // <LABEL=SHAIAN>シャイアン</LABEL>「武器を手に入れるにはいくつかの方法がある…
#define Str_Shaian_0FCD 0x0FCD               // <LABEL=SHAIAN>シャイアン</LABEL>「・・・
#define Str_Shaian_0FD4 0x0FD4               // <LABEL=SHAIAN>シャイアン</LABEL>「レディに会ったようだな。
#define Str_Shaian_0FDA 0x0FDA               // <LABEL=SHAIAN>シャイアン</LABEL>「敵モンスターにはそれぞれに得意とする属性…
#define Str_Shaian_0FE0 0x0FE0               // <LABEL=SHAIAN>シャイアン</LABEL>「・・・
#define Str_Shaian_0FEB 0x0FEB               // <LABEL=SHAIAN>シャイアン</LABEL>「敵モンスターの苦手属性を知るには、
#define Str_Shaian_0FEF 0x0FEF               // <LABEL=SHAIAN>シャイアン</LABEL>「苦手属性でのエンチャント攻撃ほどではない…
#define Str_Sumire_0FF5 0x0FF5               // <LABEL=SUMIRE>スミレ</LABEL>「わぁー・・・
#define Str_Sumire_0FF8 0x0FF8               // <LABEL=SUMIRE>スミレ</LABEL>「あっ・・・」
#define Str_Sumire_0FFA 0x0FFA               // <LABEL=SUMIRE>スミレ</LABEL>「・・・」
#define Str_Sumire_0FFC 0x0FFC               // <LABEL=SUMIRE>スミレ</LABEL>「あのね・・・
#define Str_Sumire_1001 0x1001               // <LABEL=SUMIRE>スミレ</LABEL>「・・・」
#define Str_Sumire_1003 0x1003               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃんのバカ!!
#define Str_Sumire_1007 0x1007               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃん・・・
#define Str_Sumire_100B 0x100B               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃん、だいじょうぶだよね?」
#define Str_Sumire_100D 0x100D               // <ALTER>だいじょうぶ</ALTER>　<ALTER>ダメかも</ALTER>
#define Str_Sumire_100F 0x100F               // <LABEL=SUMIRE>スミレ</LABEL>「うん・・・
#define Str_Sumire_1015 0x1015               // <LABEL=SUMIRE>スミレ</LABEL>「くすん・・・
#define Str_Sumire_1019 0x1019               // <LABEL=SUMIRE>スミレ</LABEL>「わぁー・・・
#define Str_Sumire_101C 0x101C               // <LABEL=SUMIRE>スミレ</LABEL>「あったよ!
#define Str_Sumire_101F 0x101F               // <LABEL=SUMIRE>スミレ</LABEL>「・・・おにいちゃん!!
#define Str_Sumire_1022 0x1022               // <LABEL=SUMIRE>スミレ</LABEL>「チョコレートおいしいよ。
#define Str_Sumire_1025 0x1025               // <LABEL=SUMIRE>スミレ</LABEL>「チョコレートおいしいよ。
#define Str_Sumire_1028 0x1028               // <LABEL=SUMIRE>スミレ</LABEL>「チョコレートおいしいよ。
#define Str_Sumire_102B 0x102B               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃんを・・・おねがい、おにいちゃん!!…
#define Str_Sumire_102D 0x102D               // <LABEL=SUMIRE>スミレ</LABEL>「あっ・・・カギ!
#define Str_Sumire_1031 0x1031               // <MOJISE=MOJISE_SYSTEM>倉庫のボックス数が増えた!!
#define Str_Sumire_1033 0x1033               // <LABEL=SUMIRE>スミレ</LABEL>「そうこつかうの?」 <ALTER>つかう</…
#define Str_Sumire_1036 0x1036               // <LABEL=SUMIRE>スミレ</LABEL>「おじいちゃん、だいじょうぶかなぁ・・・」
#define Str_Sumire_1038 0x1038               // <LABEL=SUMIRE>スミレ</LABEL>「チョコレートおいしかった?
#define Str_Sumire_103C 0x103C               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃんったらねてばっかりなのよ。ぷーだっ…
#define Str_Sumire_103E 0x103E               // <LABEL=SUMIRE>スミレ</LABEL>「アイテムはいっぱいもったらダメなの。
#define Str_Sumire_1041 0x1041               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃんったらまたどっかいっちゃった。ぷー…
#define Str_Sumire_1043 0x1043               // <LABEL=SUMIRE>スミレ</LABEL>「そうこにあずけたアイテムはくさらないの。
#define Str_Sumire_1046 0x1046               // <LABEL=SUMIRE>スミレ</LABEL>「・・・」
#define Str_Sumire_1048 0x1048               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃんのバカ!!
#define Str_Sumire_104C 0x104C               // <LABEL=SUMIRE>スミレ</LABEL>「・・・」
#define Str_Sumire_104E 0x104E               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃん・・・
#define Str_Sumire_1052 0x1052               // <LABEL=SUMIRE>スミレ</LABEL>「クロちゃん・・・
#define Str_Sumire_1055 0x1055               // <LABEL=SUMIRE>スミレ</LABEL>「そうこのカギは、ぜんぶで3つなんだって。
#define Str_Sumire_1058 0x1058               // <LABEL=SUMIRE>スミレ</LABEL>「そうこのカギは、ぜんぶで3つなんだって。
#define Str_Sumire_105B 0x105B               // <LABEL=SUMIRE>スミレ</LABEL>「そうこのカギは、ぜんぶで3つなんだって。
#define Str_Sumire_105E 0x105E               // <LABEL=SUMIRE>スミレ</LABEL>「おにいちゃんはカミナリへいき?
#define Str_Sumire_1062 0x1062               // <LABEL=SUMIRE>スミレ</LABEL>「あれ・・・?<NAME>のおにいちゃん?」
#define Str_Lady_106D 0x106D                 // <LABEL=LADY>レディ</LABEL>「いらっしゃい、<NAME>くん。
#define Str_Lady_1076 0x1076                 // <LABEL=LADY>レディ</LABEL>「いらっしゃい、<NAME>くん。
#define Str_Lady_107E 0x107E                 // <LABEL=LADY>レディ</LABEL>「ちょうどいいところに来たわね、<NAME>くん。
#define Str_Lady_1086 0x1086                 // <LABEL=LADY>レディ</LABEL>「終末の獣(けもの)だなんて・・・
#define Str_Lady_108E 0x108E                 // <LABEL=LADY>レディ</LABEL>「どう、調子は?」 <ALTER>仕事の話</AL…
#define Str_Lady_1090 0x1090                 // <LABEL=LADY>レディ</LABEL>「あら、ごめんなさい。
#define Str_Lady_1095 0x1095                 // <LABEL=LADY>レディ</LABEL>「<NAME>くんがいてくれてほんと、助かるわ。
#define Str_Lady_1098 0x1098                 // <LABEL=LADY>レディ</LABEL>「気に入った依頼(いらい)は、なかったかしら?
#define Str_Lady_109C 0x109C                 // <LABEL=LADY>レディ</LABEL>「そういえば・・・
#define Str_Lady_10A0 0x10A0                 // <LABEL=LADY>レディ</LABEL>「そういえば・・・
#define Str_Lady_10A4 0x10A4                 // <LABEL=LADY>レディ</LABEL>「そういえば・・・
#define Str_Lady_10A8 0x10A8                 // <LABEL=LADY>レディ</LABEL>「そういえば・・・
#define Str_Lady_10AD 0x10AD                 // <LABEL=LADY>レディ</LABEL>「そういえば・・・
#define Str_Lady_10B2 0x10B2                 // <LABEL=LADY>レディ</LABEL>「そういえば・・・
#define Str_Lady_10B6 0x10B6                 // <LABEL=LADY>レディ</LABEL>「そういえば・・・
#define Str_Lady_10B9 0x10B9                 // <LABEL=LADY>レディ</LABEL>「敵モンスターを倒(たお)すことで得られる経験値。
#define Str_Lady_10BD 0x10BD                 // <LABEL=LADY>レディ</LABEL>「魔法カードは使ってる?
#define Str_Lady_10C2 0x10C2                 // <LABEL=LADY>レディ</LABEL>「スキル(SKILL)って知ってる?
#define Str_Lady_10CB 0x10CB                 // <LABEL=LADY>レディ</LABEL>「景品交換(けいひんこうかん)では、
#define Str_Link_10D1 0x10D1                 // <MOJISE=MOJISE_SYSTEM>現在の対戦ポイントは、<VAR=1>ポイントです。
#define Str_Link_10D3 0x10D3                 // <MOJISE=MOJISE_SYSTEM><VAR=2>ポイント使って、魔法カードと交換(こう…
#define Str_Link_10D5 0x10D5                 // <ALTER>はい</ALTER>　<ALTER>いいえ</ALTER>
#define Str_LinkTheFool 0x10D9               // 「愚者のカード」を手に入れた!!
#define Str_LinkTheEmperor 0x10DC            // 「皇帝のカード」を手に入れた!!
#define Str_LinkTheLovers 0x10DF             // 「恋人のカード」を手に入れた!!
#define Str_LinkJustice 0x10E2               // 「正義のカード」を手に入れた!!
#define Str_LinkTheHangedMan 0x10E5          // 「吊るされた男のカード」を手に入れた!!
#define Str_LinkDeath 0x10E8                 // 「死神のカード」を手に入れた!!
#define Str_LinkTemperance 0x10EB            // 「節制のカード」を手に入れた!!
#define Str_LinkTheDevil 0x10EE              // 「悪魔のカード」を手に入れた!!
#define Str_LinkTheTower 0x10F1              // 「塔のカード」を手に入れた!!
#define Str_LinkTheStar 0x10F4               // 「星のカード」を手に入れた!!
#define Str_LinkTheMoon 0x10F7               // 「月のカード」を手に入れた!!
#define Str_LinkTheSun 0x10FA                // 「太陽のカード」を手に入れた!!
#define Str_LinkJudgement 0x10FD             // 「審判のカード」を手に入れた!!
#define Str_1100 0x1100                      // <MOJISE=MOJISE_SYSTEM>魔法カードと交換(こうかん)するには、あと<VAR=…
#define Str_1102 0x1102                      // <MOJISE=MOJISE_SYSTEM>バッグがいっぱいです。アイテムを減らしてください。
#define Str_SmithPanel 0x1105                // <LABEL=SMITH>スミス</LABEL>「パネルの説明は読んだか?」
#define Str_SmithPrompt 0x1107               // <LABEL=SMITH>スミス</LABEL>「鍛冶(かじ)をするか?」 <ALTER>鍛冶を…
#define Str_SmithForgePoor 0x1109            // <LABEL=SMITH>スミス</LABEL>「むう・・・いまいちな出来じゃな。
#define Str_SmithForgeAverage 0x110E         // <LABEL=SMITH>スミス</LABEL>「ふう・・・まずまずじゃな。
#define Str_SmithForgeGood 0x1112            // <LABEL=SMITH>スミス</LABEL>「ほう・・・いい出来じゃな!!
#define Str_SmithForgeGreat 0x1116           // <LABEL=SMITH>スミス</LABEL>「おお・・・すばらしい出来映えじゃな!
#define Str_Smith_111A 0x111A                // <LABEL=SMITH>スミス</LABEL>「なんと・・・めずらしい武器じゃな!?
#define Str_Smith_111E 0x111E                // <LABEL=SMITH>スミス</LABEL>「おお・・・すばらしい出来映えじゃな!
#define Str_Smith_1123 0x1123                // <LABEL=SMITH>スミス</LABEL>「わしはすでに戦いを退いた身・・・
#define Str_Smith_1127 0x1127                // <LABEL=SMITH>スミス</LABEL>「<NAME>、
#define Str_Smith_112A 0x112A                // <LABEL=SMITH>スミス</LABEL>「来たな。
#define Str_Smith_112E 0x112E                // <LABEL=SMITH>スミス</LABEL>「東に探索(たんさく)に出たシャイアンが、まだ戻…
#define Str_Smith_1133 0x1133                // <LABEL=SMITH>スミス</LABEL>「鍛冶が必要になったらいつでも声をかけてくれ。
#define Str_SmithSabata 0x1137               // <LABEL=SABATA>サバタ</LABEL>「アンタがスミスか?」
#define Str_Smith_114D 0x114D                // <LABEL=SMITH>スミス</LABEL>「リンゴ・・・」
#define Str_Smith_1150 0x1150                // <LABEL=SMITH>スミス</LABEL>「<NAME>・・・
#define Str_Smith_1155 0x1155                // <LABEL=SMITH>スミス</LABEL>「そういえば、シャイアンからの連絡が入ったぞ。
#define Str_Smith_115B 0x115B                // <LABEL=SMITH>スミス</LABEL>「シャイアンとやりあったようじゃな・・・
#define Str_Smith_1162 0x1162                // <LABEL=SMITH>スミス</LABEL>「武器は果物や肉のように太陽の光でくさったりはし…
#define Str_Smith_1168 0x1168                // <LABEL=SMITH>スミス</LABEL>「一時はどうなるかと思ったが・・・
#define Str_Smith_1170 0x1170                // <LABEL=SMITH>スミス</LABEL>「リンゴの記憶(きおく)を取り戻したのは、
#define Str_Smith_1178 0x1178                // <LABEL=SMITH>スミス</LABEL>「武器には、レベルに応じたランクというものがある…
#define Str_Smith_117E 0x117E                // <LABEL=SMITH>スミス</LABEL>「リンゴ・・・
#define Str_Smith_1185 0x1185                // <LABEL=SMITH>スミス</LABEL>「明日もまた日は昇(のぼ)る!
#define Str_Smith_1189 0x1189                // <LABEL=SMITH>スミス</LABEL>「武器には、レベルに応じたランクというものがある…
#define Str_Smith_118E 0x118E                // <LABEL=SMITH>スミス</LABEL>「封印(ふういん)のことは、わしら街の者に任せて…
#define Str_SmithGun 0x1193                  // <LABEL=SMITH>スミス</LABEL>「ん?おまえの持っているそれは、
#define Str_Smith_119B 0x119B                // <LABEL=SMITH>スミス</LABEL>「できたぞ!!」
#define Str_Smith_119D 0x119D                // <FACEOFF><PROC=1>太陽銃「ガン・デル・ソル」を手に入れた!!
#define Str_Smith_119F 0x119F                // <LABEL=SMITH>スミス</LABEL>「とりあえず使える状態にはなったが、
#define Str_Smith_11A5 0x11A5                // <LABEL=SMITH>スミス</LABEL>「リンゴ・・・
#define Str_Smith_11A9 0x11A9                // <LABEL=SMITH>スミス</LABEL>「太陽鍛冶(たいようかじ)においては、
#define Str_Smith_11B0 0x11B0                // <LABEL=SMITH>スミス</LABEL>「<NAME>、
#define Str_Smith_11B5 0x11B5                // <LABEL=SMITH>スミス</LABEL>「おまえが1番得意な武器は、ソードタイプのようじ…
#define Str_Smith_11B7 0x11B7                // <LABEL=SMITH>スミス</LABEL>「おまえが1番得意な武器は、スピアタイプのようじ…
#define Str_Smith_11B9 0x11B9                // <LABEL=SMITH>スミス</LABEL>「おまえが1番得意な武器は、ハンマータイプのよう…
#define Str_SmithAskLicenseSpade 0x11BB      // <LABEL=SMITH>スミス</LABEL>「ソードタイプの限定解除でいいか?」
#define Str_SmithAskLicenseDiamond 0x11BD    // <LABEL=SMITH>スミス</LABEL>「スピアタイプの限定解除でいいか?」
#define Str_SmithAskLicenseClub 0x11BF       // <LABEL=SMITH>スミス</LABEL>「ハンマータイプの限定解除でいいか?」
#define Str_SmithLicensePrompt 0x11C1        // <ALTER>いい</ALTER>　<ALTER>ダメ</ALTER>
#define Str_SmithSpadeCrest 0x11C3           // <LABEL=SMITH>スミス</LABEL>「ではソードタイプ限定解除の証、
#define Str_SmithDiamondCrest 0x11C6         // <LABEL=SMITH>スミス</LABEL>「ではスピアタイプ限定解除の証、
#define Str_SmithClubCrest 0x11C9            // <LABEL=SMITH>スミス</LABEL>「ではハンマータイプ限定解除の証、
#define Str_GetSpadeCrest 0x11CC             // <PROC=1>「スペードの紋章」を手に入れた!!
#define Str_GetDiamondCrest 0x11CE           // <PROC=1>「ダイヤの紋章」を手に入れた!!
#define Str_GetClubCrest 0x11D0              // <PROC=1>「クラブの紋章」を手に入れた!!
#define Str_Smith_11D2 0x11D2                // <LABEL=SMITH>スミス</LABEL>「Sランクとは、レベル49以上の武器のことを指す…
#define Str_Smith_11D5 0x11D5                // <LABEL=SMITH>スミス</LABEL>「<NAME>、
#define Str_Smith_11D9 0x11D9                // <LABEL=SMITH>スミス</LABEL>「<NAME>、
#define Str_Smith_11DD 0x11DD                // <LABEL=SMITH>スミス</LABEL>「<NAME>、
#define Str_Smith_11E1 0x11E1                // <LABEL=SMITH>スミス</LABEL>「<NAME>、
#define Str_Smith_11E9 0x11E9                // <ALTER>ソード</ALTER>　<ALTER>スピア</ALTER>　<ALTER>ハンマ…
#define Str_Smith_11EA 0x11EA                // <LABEL=SMITH>スミス</LABEL>「できたぞ!!」
#define Str_GetAstroSword 0x11EC             // <FACEOFF><PROC=1>「アストロソード」を手に入れた!!
#define Str_GetAstroSpear 0x11EE             // <FACEOFF><PROC=1>「アストロスピア」を手に入れた!!
#define Str_GetAstroHammer 0x11F0            // <FACEOFF><PROC=1>「アストロハンマー」を手に入れた!!
#define Str_Smith_11F2 0x11F2                // <LABEL=SMITH>スミス</LABEL>「その武器は鍛冶(かじ)の材料に使うことができな…
#define Str_RitaShopWelcome 0x11F9           // <LABEL=RITA>リタ</LABEL>「いらっしゃいませ!!お買い物ですか?」
#define Str_RitaShopTalk 0x11FB              // <ALTER>お買い物</ALTER>　<ALTER>お話</ALTER>
#define Str_RitaShopThanksA 0x11FD           // <LABEL=RITA>リタ</LABEL>「ありがとうございました!!
#define Str_RitaShopThanksB 0x1200           // <LABEL=RITA>リタ</LABEL>「ありがとうございました!!
#define Str_RitaShopThanksC 0x1203           // <LABEL=RITA>リタ</LABEL>「ありがとうございました!!
#define Str_RitaShopThanksD 0x1207           // <LABEL=RITA>リタ</LABEL>「ありがとうございました!!
#define Str_RitaShopThanksE 0x120C           // <LABEL=RITA>リタ</LABEL>「ありがとうございました!!」
#define Str_RitaShopThanksF 0x120E           // <LABEL=RITA>リタ</LABEL>「ありがとうございました!!
#define Str_RitaShopThanksG 0x1212           // <LABEL=RITA>リタ</LABEL>「ありがとうございました!!
#define Str_Rita_1219 0x1219                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま、
#define Str_Rita_121F 0x121F                 // <LABEL=RITA>リタ</LABEL><PROC=1><LOCK=90>「<NAME>さま…
#define Str_Rita_1221 0x1221                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・
#define Str_Rita_1226 0x1226                 // <LABEL=RITA>リタ</LABEL>「・・・」
#define Str_Rita_1228 0x1228                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま、アイテムは足りていますか?
#define Str_Rita_122B 0x122B                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま、
#define Str_Rita_1230 0x1230                 // <LABEL=RITA>リタ</LABEL>「サバタさま!!
#define Str_Rita_1236 0x1236                 // <LABEL=RITA>リタ</LABEL>「サバタさま、アイテムは足りていますか?
#define Str_Rita_1239 0x1239                 // <LABEL=RITA>リタ</LABEL>「サバタさま、お体は大丈夫(だいじょうぶ)ですか?
#define Str_Rita_123D 0x123D                 // <LABEL=RITA>リタ</LABEL>「<NAME>さまのこと・・・よろしくお願いします!…
#define Str_Rita_123F 0x123F                 // <LABEL=RITA>リタ</LABEL>「・・・」
#define Str_Rita_1241 0x1241                 // <LABEL=RITA>リタ</LABEL>「サバタさま、これをお使いください!!」<PROC=…
#define Str_Rita_1244 0x1244                 // <LABEL=RITA>リタ</LABEL>「大地から力を奪(うば)うもの・・・
#define Str_Rita_124D 0x124D                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま、
#define Str_Rita_1252 0x1252                 // <LABEL=RITA>リタ</LABEL>「<NAME>さまがご無事で本当によかった・・・
#define Str_Rita_1257 0x1257                 // <LABEL=RITA>リタ</LABEL>「ご存知ですか?
#define Str_Rita_125F 0x125F                 // <LABEL=RITA>リタ</LABEL>「ご存知ですか?
#define Str_Rita_1267 0x1267                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・
#define Str_Rita_126E 0x126E                 // <ALTER>信じている</ALTER>　<ALTER>分からない</ALTER>
#define Str_Rita_1270 0x1270                 // <LABEL=RITA>リタ</LABEL>「<PROC=2>それでこそ<NAME>さま!!
#define Str_Rita_1273 0x1273                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・
#define Str_Rita_1277 0x1277                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま、
#define Str_Rita_1280 0x1280                 // <LABEL=RITA>リタ</LABEL>「太陽の果実は太陽の光によって成長します。
#define Str_Rita_1288 0x1288                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま!!
#define Str_Rita_128F 0x128F                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま!!
#define Str_Rita_1296 0x1296                 // <LABEL=RITA>リタ</LABEL>「素手攻撃(すでこうげき)をご存知ですか?
#define Str_Rita_12A0 0x12A0                 // <LABEL=RITA>リタ</LABEL>「太陽の果実と同様に、
#define Str_Rita_12A5 0x12A5                 // <LABEL=RITA>リタ</LABEL>「太陽樹さまが成木へと成長された今、
#define Str_Rita_12AC 0x12AC                 // <LABEL=RITA>リタ</LABEL>「成木になられた太陽樹さまからは、
#define Str_Rita_12B4 0x12B4                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま!!
#define Str_Rita_12BB 0x12BB                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・
#define Str_Rita_12BF 0x12BF                 // <LABEL=RITA>リタ</LABEL><PROC=1>(うわーーーーーーっ!!何言ってんの…
#define Str_Rita_12C2 0x12C2                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・
#define Str_Rita_12C6 0x12C6                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・
#define Str_Rita_12CA 0x12CA                 // <LABEL=RITA>リタ</LABEL>「<NAME>さま・・・
#define Str_Rita_12CE 0x12CE                 // <LABEL=RITA>リタ</LABEL><PROC=1>(うわーーーーーーっ!!やっぱり言え…
#define Str_Rita_12D2 0x12D2                 // <LABEL=RITA>リタ</LABEL>「すごいです!!
#define Str_GetHeartCrest 0x12D8             // <PROC=1>「ハートの紋章」を手に入れた!!
#define Str_Rita_12DA 0x12DA                 // <LABEL=RITA>リタ</LABEL>「そのハートの紋章(もんしょう)を受け継いだ者は、
#define Str_12DE 0x12DE                      // <LABEL=OTENKO>おてんこさま</LABEL>「かつての太陽の街がこのありさまか・・・…
#define Str_12E0 0x12E0                      // <LABEL=OTENKO>おてんこさま</LABEL>「まずはあの少女から話を聞こう」
#define Str_12E2 0x12E2                      // <LABEL=OTENKO>おてんこさま</LABEL>「スミス・・・無事でいてくれるといいのだ…
#define Str_12E5 0x12E5                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>!!
#define Str_12E8 0x12E8                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>!!
#define Str_12EB 0x12EB                      // <LABEL=OTENKO>おてんこさま</LABEL>「どうやら・・・
#define Str_12F0 0x12F0                      // <LABEL=OTENKO>おてんこさま</LABEL>「とりあえずは何とかなったが・・・
#define Str_12F4 0x12F4                      // <LABEL=OTENKO>おてんこさま</LABEL>「結界は無事なようだな。
#define Str_12F7 0x12F7                      // <LABEL=OTENKO>おてんこさま</LABEL>「ようやくヴァンパイアの足取りがつかめた…
#define Str_12FB 0x12FB                      // <LABEL=OTENKO>おてんこさま</LABEL>「<NAME>、
#define Str_12FF 0x12FF                      // <LABEL=OTENKO>おてんこさま</LABEL>「今思うに・・・
#define Str_Luis_1303 0x1303                 // <LABEL=PEOPLE3>ルイス</LABEL>「おぬしは・・・」
#define Str_Luis_1305 0x1305                 // <LABEL=PEOPLE3>ルイス</LABEL>「おお、おぬしか!!
#define Str_Luis_130A 0x130A                 // <LABEL=PEOPLE3>ルイス</LABEL>「知っとるかの?
#define Str_Luis_1310 0x1310                 // <LABEL=PEOPLE3>ルイス</LABEL>「この年じゃ、
#define Str_Luis_1315 0x1315                 // <LABEL=PEOPLE3>ルイス</LABEL>「知っとるかの?
#define Str_Luis_1319 0x1319                 // <LABEL=PEOPLE3>ルイス</LABEL>「わしが何に気がついたのか、それを知りたいの…
#define Str_Luis_131E 0x131E                 // <LABEL=PEOPLE3>ルイス</LABEL>「この地震(じしん)は何なんじゃ?
#define Str_Luis_1322 0x1322                 // <LABEL=PEOPLE3>ルイス</LABEL>「たとえこれで終わりじゃとしても、
#define Str_Marcello_1326 0x1326             // <LABEL=PEOPLE1>マルチェロ</LABEL>「きみは・・・」
#define Str_Marcello_1328 0x1328             // <LABEL=PEOPLE1>マルチェロ</LABEL>「<NAME>くん!!
#define Str_Marcello_132E 0x132E             // <LABEL=PEOPLE1>マルチェロ</LABEL>「いいかい?
#define Str_Marcello_1334 0x1334             // <LABEL=PEOPLE1>マルチェロ</LABEL>「ぼくは争いが嫌(きら)いなんだ・・・
#define Str_Marcello_1338 0x1338             // <LABEL=PEOPLE1>マルチェロ</LABEL>「いいかい?
#define Str_Marcello_133E 0x133E             // <LABEL=PEOPLE1>マルチェロ</LABEL>「身体が大きいからね・・・よく誤解される…
#define Str_Marcello_1343 0x1343             // <LABEL=PEOPLE1>マルチェロ</LABEL>「新しい太陽樹が根づき、
#define Str_Marcello_1347 0x1347             // <LABEL=PEOPLE1>マルチェロ</LABEL>「終末の獣(けもの)、ヨルムンガンド・・…
#define Str_Hatena_134D 0x134D                // <LABEL=PEOPLE2>???</LABEL>「おう、少年!!
#define Str_Hatena_1356 0x1356                // <LABEL=PEOPLE2>???</LABEL>「終末の獣(けもの)とはな。
#define Str_Hatena_135A 0x135A                // <LABEL=PEOPLE2>???</LABEL>「最後の戦いだ。
#define Str_Hatena_1360 0x1360                // <LABEL=PEOPLE2>???</LABEL>「とうとうやったな、少年!!
#define Str_GetTheWorld 0x1365               // <PROC=1>「世界のカード」を手に入れた!!
#define Str_Hatena_1367 0x1367                // <LABEL=PEOPLE2>???</LABEL>「おまえのおかげで俺(おれ)の商売も順調だ。
#define Str_Hatena_136B 0x136B                // <LABEL=PEOPLE2>???</LABEL>「おう、少年!!
#define Str_Hatena_136F 0x136F                // <LABEL=PEOPLE2>???</LABEL>「おう、少年!!
#define Str_Hatena_1373 0x1373                // <LABEL=PEOPLE2>???</LABEL>「おう、少年!!
#define Str_Hatena_1377 0x1377                // <LABEL=PEOPLE2>???</LABEL>「まさか直撃(ちょくげき)を受けるとは・・・
#define Str_Hatena_1388 0x1388                // <LABEL=PEOPLE2>???</LABEL>「まさか直撃(ちょくげき)を受けるとは・・・
#define Str_Hatena_1399 0x1399                // <LABEL=PEOPLE2>???</LABEL>「少年、
#define Str_Hatena_139C 0x139C                // <LABEL=PEOPLE2>???</LABEL>「ん?俺(おれ)に用か?」
#define Str_HatenaBBPrice 0x139E              // <LABEL=PEOPLE2>???</LABEL>「ブラインドボックス・レベル<VAR=2>は…
#define Str_HatenaPrompt 0x13A1               // <ALTER>買う</ALTER>　<ALTER>話</ALTER>
#define Str_HatenaBBOpen 0x13A3               // <LABEL=PEOPLE2>???</LABEL>「何が出るかな?」
#define Str_HatenaBBNoMoney 0x13A5            // <LABEL=PEOPLE2>???</LABEL>「ん?太陽バンクが残高不足だぞ?
#define Str_Hatena_13A9 0x13A9                // <LABEL=PEOPLE2>???</LABEL>「いいか、少年。
#define Str_Hatena_13B0 0x13B0                // <LABEL=PEOPLE2>???</LABEL>「ところで少年、
#define Str_Hatena_13B7 0x13B7                // <LABEL=PEOPLE2>???</LABEL>「ところで少年、
#define Str_HatenaTitleSwordMaster 0x13BB     // <LABEL=PEOPLE2>???</LABEL>「ソードマスターは、
#define Str_HatenaTitleSpearMaster 0x13BE     // <LABEL=PEOPLE2>???</LABEL>「スピアマスターは、
#define Str_HatenaTitleHammerMaster 0x13C1    // <LABEL=PEOPLE2>???</LABEL>「ハンマーマスターは、
#define Str_HatenaTitleFistMaster 0x13C4      // <LABEL=PEOPLE2>???</LABEL>「フィストマスターは、
#define Str_HatenaTitleGunMaster 0x13C7       // <LABEL=PEOPLE2>???</LABEL>「ガンマスターは、
#define Str_HatenaTitleAdept 0x13CA           // <LABEL=PEOPLE2>???</LABEL>「アデプト(達人)は、
#define Str_HatenaTitleDayWalker 0x13CD       // <LABEL=PEOPLE2>???</LABEL>「デイウォーカー(日の下を歩く者)は、
#define Str_HatenaTitleAdventurer 0x13D1      // <LABEL=PEOPLE2>???</LABEL>「アドベンチャラー(冒険者)は
#define Str_HatenaTitleAgent 0x13D4           // <LABEL=PEOPLE2>???</LABEL>「エージェント(仕事人)は、
#define Str_HatenaTitleCollector 0x13D7       // <LABEL=PEOPLE2>???</LABEL>「コレクター(収集家)は、
#define Str_HatenaTitleDarkHunter 0x13DA      // <LABEL=PEOPLE2>???</LABEL>「ダークハンター(闇狩師)は、
#define Str_HatenaTitleGrandMaster 0x13DD     // <LABEL=PEOPLE2>???</LABEL>「グランドマスターは、
#define Str_Hatena_13E0 0x13E0                // <LABEL=PEOPLE2></LABEL>???「いいか、少年。
#define Str_Zaji_13E4 0x13E4                 // <LABEL=ZAJI>ザジ</LABEL>「言い忘れとったけど、
#define Str_Zaji_13E9 0x13E9                 // <LABEL=ZAJI>ザジ</LABEL>「星読みっちゅうのは、
#define Str_Zaji_13EE 0x13EE                 // <LABEL=ZAJI>ザジ</LABEL>「ええか?
#define Str_ZajiBok1S 0x13F1                 // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・Sや。
#define Str_ZajiBok1APlus 0x13F3             // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・A+や。
#define Str_ZajiBok1A 0x13F5                 // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・Aや。
#define Str_ZajiBok1AMinus 0x13F7            // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・A-や。
#define Str_ZajiBok1BPlus 0x13F9             // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・B+や。
#define Str_ZajiBok1B 0x13FB                 // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・Bや。
#define Str_ZajiBok1BMinus 0x13FD            // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・B-や。
#define Str_ZajiBok1CPlus 0x13FF             // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・C+や。
#define Str_ZajiBok1C 0x1401                 // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・Cや。
#define Str_ZajiBok1CMinus 0x1403            // <LABEL=ZAJI></LABEL>イストラカンの冒険(ぼうけん)でのランクは・・・C-や。
#define Str_Zaji_1405 0x1405                 // <LABEL=ZAJI></LABEL>図星やろ?ほんま、自分の才能が恐(おそ)ろしいで」
#define Str_Zaji_1407 0x1407                 // <ALTER>恐ろしい</ALTER>　<ALTER>すごい</ALTER>
#define Str_Zaji_1409 0x1409                 // <PROC=1><LABEL=ZAJI>ザジ</LABEL>「さよか・・・あんたなら分かってくれ…
#define Str_Zaji_140C 0x140C                 // <LABEL=ZAJI>ザジ</LABEL>「さよか!!
#define Str_Zaji_1411 0x1411                 // <LABEL=ZAJI>ザジ</LABEL>「あんた、呪(のろ)われてるやないの!?
#define Str_Zaji_1415 0x1415                 // <LABEL=ZAJI>ザジ</LABEL>「ライフ、大丈夫(だいじょうぶ)なん?
#define Str_Zaji_1418 0x1418                 // <LABEL=ZAJI>ザジ</LABEL>「エナジー、大丈夫(だいじょうぶ)なん?
#define Str_Zaji_141B 0x141B                 // <LABEL=ZAJI>ザジ</LABEL>「うちが結界守っとるうちは、
#define Str_Zaji_1420 0x1420                 // <LABEL=ZAJI>ザジ</LABEL>「太陽銃(たいようじゅう)のこと、
#define Str_ZajiSabataPileDriver 0x1426      // <LABEL=ZAJI>ザジ</LABEL>「あんたのその身体・・・」
#define Str_142F 0x142F                      // <LABEL=SABATA>サバタ</LABEL>「砂漠(さばく)の遺跡(いせき)に残された伝承…
#define Str_143C 0x143C                      // <LABEL=ZAJI>ザジ</LABEL>「ごめんな、<NAME>。
#define Str_1441 0x1441                      // <ALTER>情けない</ALTER> <ALTER>明日もまた日は昇る!</ALTER>
#define Str_1443 0x1443                      // <LABEL=ZAJI>ザジ</LABEL>「やっぱ、ばばあのようにはいかへんな・・・」
#define Str_1445 0x1445                      // <LABEL=ZAJI>ザジ</LABEL>「ありがとな、<NAME>・・・」
#define Str_1447 0x1447                      // <LABEL=ZAJI>ザジ</LABEL><PROC=1><LOCK=45>「もともとが無理し…
#define Str_144C 0x144C                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>、
#define Str_1453 0x1453                      // <LABEL=ZAJI>ザジ</LABEL>「闇夜(やみよ)にあり太陽を映す鏡、月・・・
#define Str_145D 0x145D                      // <LABEL=ZAJI>ザジ</LABEL>「あんたら兄弟は太陽と月、2つの血を受け継(つ)いど…
#define Str_1465 0x1465                      // <LABEL=ZAJI>ザジ</LABEL>「<NAME>、何やっとんねん!!
#define Str_1468 0x1468                      // <LABEL=ZAJI>ザジ</LABEL>「何や、<NAME>。そないにカード集めて?
#define Str_146C 0x146C                      // <LABEL=ZAJI>ザジ</LABEL>「はぁ・・・<PROC=1><LOCK=60>」
#define Str_146E 0x146E                      // <LABEL=ZAJI>ザジ</LABEL>「3賢者(けんじゃ)のカード?
#define Str_1477 0x1477                      // <LABEL=ZAJI>ザジ</LABEL>「魔術師のカードのありかは、
#define Str_147D 0x147D                      // <LABEL=ZAJI>ザジ</LABEL>「教皇のカードのありかは、
#define Str_1483 0x1483                      // <LABEL=ZAJI>ザジ</LABEL>「隠者(いんじゃ)のカードのありかは、
#define Str_1489 0x1489                      // <LABEL=ZAJI>ザジ</LABEL>「3賢者(けんじゃ)がすべてそろたみたいやね。
#define Str_148E 0x148E                      // <LABEL=ZAJI>ザジ</LABEL>「実はな・・・
#define Str_1491 0x1491                      // <LABEL=ZAJI>ザジ</LABEL>「太陽と月いうんは、
#define Str_149C 0x149C                      // <LABEL=ZAJI>ザジ</LABEL>「ばばあの星読み、もう1回聞くか?」
#define Str_149E 0x149E                      // <ALTER>聞く</ALTER>　<ALTER>聞かない</ALTER>
#define Str_14A0 0x14A0                      // <LABEL=ZAJI>ザジ</LABEL>「未来の出来事に関する星読みは、単なる未来予知やない…
#define Str_14A4 0x14A4                      // <LABEL=ZAJI>ザジ</LABEL>「ばばあは何も言わんかったけど、
#define Str_14A7 0x14A7                      // <LABEL=ZAJI>ザジ</LABEL>「なんや<NAME>、びびっとるんか?
#define Str_14B0 0x14B0                      // <LABEL=ZAJI>ザジ</LABEL>「結局、
#define Str_ZajiCarmilla 0x14B7              // <LABEL=ZAJI>ザジ</LABEL>「なぁ、<NAME>・・・カーミラって誰(だれ)なん…
#define Str_StaffRoll 0x14BE                 // <WEIGHT>キャスト</WEIGHT>
#define Str_Epilogue 0x14F0                  // 太陽と月、闇に帰りし時
#define Str_TheEnd 0x14F6                    // 続・ボクらの太陽         終
#define Bin_14F8 0x14F8
#define Str_AreaCodeName 0x14F9              // no_area
#define Str_1603 0x1603                      // コンティニューしますか?
#define Str_1605 0x1605                      // 暗黒ローンに<WEIGHT><VAR=0>ソル</WEIGHT>払ってコンティニューしますか?
#define gExpTable 0x1607
#define Str_StartMenuItems 0x1608            // 大地の実
#define Str_StartMenuWeapons 0x170D
#define Str_StartMenuArmors 0x17B7           // クロスアーマー
#define Str_StartMenuMagics 0x1802           // エンチャント・ソル
#define Str_AreaName 0x1826                  // 渓谷
#define Str_StartMenuMisc 0x1880             // <NAME>
#define Bin_1899 0x1899
#define Bin_189A 0x189A
#define Bin_189B 0x189B
#define Str_189C 0x189C                      // 廃墟
#define Str_18AA 0x18AA                      // ソード
#define Str_18B8 0x18B8                      // ★
#define Str_18B9 0x18B9
#define Str_18BA 0x18BA
#define Str_18BB 0x18BB                      // ジャンゴ
#define Bin_18BC 0x18BC
#define Str_18BD 0x18BD                      // <NAME>
#define Str_18F3 0x18F3
#define Bin_18F6 0x18F6
#define Str_18F7 0x18F7                      // 通信中です。相手からの接続を待っていますＢボタンでキャンセルします。
#define Str_18FF 0x18FF                      // <EXTEND=1>
#define Str_1918 0x1918                      // スパイダー
#define Bin_1952 0x1952
#define Bin_1953 0x1953
#define Str_1954 0x1954                      // 通常:
#define Str_1956 0x1956                      // ---
#define Str_1957 0x1957                      // 無属性
#define Str_195F 0x195F
#define Str_1999 0x1999                      // ビースト
#define Str_199E 0x199E                      // ???
#define Str_199F 0x199F
#define Str_19BA 0x19BA                      // 太陽センサーに太陽の光が当たらないようにして、<WEIGHT>Ａボタン</WEIGHT>を押して…
#define Bin_19BD 0x19BD
#define Str_19BE 0x19BE                      // お知らせ
#define Str_1A1C 0x1A1C                      // <NAME>
#define Str_1A24 0x1A24                      // <EXTEND=0>　<EXTEND=1><EXTEND=2>　<EXTEND=3>
#define Str_1A25 0x1A25                      // あ
#define Str_1A67 0x1A67                      // あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをがぎぐ…
#define Str_1A68 0x1A68                      // あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをがぎぐ…
#define Str_1A6A 0x1A6A                      // あ
#define Str_1ABF 0x1ABF                      // ア
#define Str_1B14 0x1B14                      // トリガー・オブ・ソル
#define Str_1B24 0x1B24                      // 太陽センサーとは
#define Str_1B2D 0x1B2D                      // 材料にする武器を2つ選ぶんだ。
#define Str_1B36 0x1B36                      // 材料を選択(せんたく)すると鍛冶(かじ)が開始される。
#define Bin_1B44 0x1B44
#define Str_1B45 0x1B45                      // 誰(だれ)を訪ねますか?
#define Str_1B47 0x1B47                      // <ALTER><EXTEND=1>僕</ALTER>
#define Str_1B48 0x1B48                      // ロードに失敗しました。セーブデータが存在しないか、壊れています。
#define Str_1B4C 0x1B4C                      // 通信エラーが発生しました。電源を切ってワイヤレスアダプタを接続しなおしてください。
#define Bin_1B54 0x1B54
#define Bin_1B55 0x1B55
#define Str_1B56 0x1B56                      // 通信ケーブルを正しく接続して下さい。
#define Str_1B61 0x1B61                      // 赤ジャンゴ
#define Str_1B93 0x1B93                      // あり
#define Str_1BA5 0x1BA5                      // <EXTEND=0>
#define Str_1BAB 0x1BAB                      // 今回の対戦ポイント
#define Str_1BB3 0x1BB3                      // きょうもクロスオーバー
#define Str_1BBB 0x1BBB                      // ジャンゴ
#define Str_1BCB 0x1BCB                      // ドバビブベボがぎぐげござじずぜぞだぢづでどばびぶべぼぱぴぷぺぽ　!{QT}　　　&'()　　,-…
#define Str_1BD0 0x1BD0                      // 通信エラーが発生しました。電源を切ってワイヤレスアダプタを接続しなおしてください。
#define Str_1BDD 0x1BDD                      // あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをがぎぐ…
#define Str_1BDE 0x1BDE                      // <EXTEND=0>　<EXTEND=1><EXTEND=2>　<EXTEND=3>
#define Bin_1BE1 0x1BE1
#define Bin_1BE2 0x1BE2
#define Bin_1BE3 0x1BE3
#define Bin_1BE4 0x1BE4

#endif // __DATA_SCRIPTS_STRINGS_H__
