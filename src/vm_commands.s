.section .rodata

.balign 4, 0
.space 256, 0

@ ID, handler
@ ID は EUC-JP文字列 を HashName したもの (参考: tools/hash.ts)
@ コメントの HashName("XXX") は あくまでハッシュが一致しただけで本来の文字列とは限らない, ハッシュは16bitなので衝突の可能性は低くない
@ なので、実際の処理と一致するものを HashName のコメントとして付けている
.global gCommandList
gCommandList: @ 0x085A9208
	.4byte 0x0074, Dvalinn_Create @ HashName("ドヴァリン")
	.4byte 0x0101, Cmd_0101
	.4byte 0x0238, EntityBA36_GetRemaining
	.4byte 0x025E, Cmd_025E
	.4byte 0x0272, Cmd_SetPlayerName
	.4byte 0x0353, Cmd_0353
	.4byte 0x03CA, Cmd_03CA
	.4byte 0x0447, Cmd_0447
	.4byte 0x054A, Cmd_054A
	.4byte 0x058D, Cmd_058D
	.4byte 0x05A5, EnemyBoku_Create @ HashName("ボク")
	.4byte 0x05E2, Cmd_05E2
	.4byte 0x061E, Cmd_061E
	.4byte 0x0623, ShadeMan_Create @ HashName("シェードマン")
	.4byte 0x064E, Cmd_064E
	.4byte 0x0740, Cmd_0740
	.4byte 0x075C, Entity4063_GetRemaining
	.4byte 0x0866, Cmd_0866
	.4byte 0x08F4, Entity08F4_Create
	.4byte 0x0955, Cmd_0955
	.4byte 0x09EA, Cmd_09EA
	.4byte 0x0AC7, EnemyCentipede_Create
	.4byte 0x0AD8, Cmd_0AD8 @ HashName("センチピード")?
	.4byte 0x0B50, Coffin_Create @ HashName("棺桶")
	.4byte 0x0BCE, Cmd_0BCE
	.4byte 0x0BFD, Cmd_0BFD
	.4byte 0x0C1B, Cmd_0C1B
	.4byte 0x0CD4, Cmd_0CD4
	.4byte 0x0E15, Cmd_GetGoodCond
	.4byte 0x0E37, MessageWindow_Create
	.4byte 0x0E76, Cmd_0E76
	.4byte 0x0E7C, Cmd_0E7C
	.4byte 0x0EE4, Cmd_0EE4
	.4byte 0x0FC5, OpRunner_Create
	.4byte 0x11D4, Cmd_LoadTileSet
	.4byte 0x11D9, Cmd_11D9
	.4byte 0x12C4, Entity12C4_Create
	.4byte 0x1320, Cmd_1320
	.4byte 0x1343, Cmd_1343
	.4byte 0x138E, Cmd_SoftReset
	.4byte 0x13AC, EnemySerpent_Create @ HashName("サーペント")
	.4byte 0x1422, Cmd_1422
	.4byte 0x1488, Cmd_1488
	.4byte 0x1500, Cmd_ShowBG @ HashName("BG表示")
	.4byte 0x150F, Entity150F_Create
	.4byte 0x15A9, Cmd_15A9
	.4byte 0x15B3, Cmd_15B3
	.4byte 0x15ED, Cmd_15ED
	.4byte 0x162E, Entity162E_Create
	.4byte 0x164D, Cmd_164D
	.4byte 0x1693, Cmd_1693
	.4byte 0x172B, Duneyrr_Create
	.4byte 0x172D, Cmd_172D
	.4byte 0x1744, EnemyRootOfDarkness_Create @ HashName("暗黒の根")
	.4byte 0x180B, Camera_SetBoundsType2Scripted
	.4byte 0x1833, Cmd_1833
	.4byte 0x184B, Camera_ConnectToTilemap
	.4byte 0x1870, sound_08240728
	.4byte 0x1887, Cmd_InitMagicData @ HashName("魔法初期化")
	.4byte 0x19CC, Entity2D2B_SetStateScripted
	.4byte 0x1A35, Cmd_1A35
	.4byte 0x1B24, Entity1B24_Create
	.4byte 0x1B77, Cmd_1B77
	.4byte 0x1BEE, Cmd_AddPlayerExp
	.4byte 0x1C3E, Cmd_GetDayOfWeek @ HashName("曜日取得")
	.4byte 0x1C64, MessageWindow_Open
	.4byte 0x1DBE, Cmd_1DBE
	.4byte 0x1E97, Cmd_1E97
	.4byte 0x1E98, Entity1E98_Create
	.4byte 0x1EA4, Cmd_FreeDurathrorScriptArg
	.4byte 0x1ED1, Cmd_1ED1
	.4byte 0x1F3B, Cmd_1F3B
	.4byte 0x1F65, Cmd_1F65
	.4byte 0x2141, Cmd_2141
	.4byte 0x2207, Cmd_2207
	.4byte 0x225B, Cmd_225B
	.4byte 0x2306, HazardManager_SpawnScripted
	.4byte 0x2354, Cmd_GetCrossoverBattleCount
	.4byte 0x237A, Cmd_GetWeaponKind
	.4byte 0x2502, Demo_Resume
	.4byte 0x2571, Cmd_2571
	.4byte 0x2575, Cmd_2575
	.4byte 0x2593, Cmd_2593
	.4byte 0x25F3, AlarmPanel_Create @ HashName("太陽警報機")
	.4byte 0x2740, Cmd_2740
	.4byte 0x274E, Cmd_274E
	.4byte 0x277A, Entity080ac574_SpawnScripted
	.4byte 0x286B, Cmd_286B
	.4byte 0x286F, Entity286F_Create
	.4byte 0x28CB, CoffinSealEffect_Create
	.4byte 0x2924, EntityA628_StopFollowCameraScripted
	.4byte 0x29F1, Cmd_29F1
	.4byte 0x2B06, AllySabata_Create @ HashName("サバタ")
	.4byte 0x2B68, Cmd_2B68
	.4byte 0x2B8C, Cmd_2B8C
	.4byte 0x2D2B, Entity2D2B_Create
	.4byte 0x2D30, EnemyAx_Create @ HashName("アックス")
	.4byte 0x2D36, Taiyo_Create
	.4byte 0x2D8F, Breakable_Spawn
	.4byte 0x2E1C, Entity2D2B_AddElemScripted
	.4byte 0x2F01, Cmd_GetSpanOfTime @ HashName("時間帯取得")
	.4byte 0x2F51, Cmd_2F51
	.4byte 0x2FA0, Cmd_2FA0
	.4byte 0x2FA5, Cmd_2FA5
	.4byte 0x2FE4, Cmd_2FE4
	.4byte 0x3004, Cmd_3004
	.4byte 0x300F, Cmd_300F
	.4byte 0x3019, RitaShop_Create
	.4byte 0x305A, Cmd_GetItem @ HashName("アイテム取得")
	.4byte 0x3062, EntityA628_IsActiveScripted
	.4byte 0x30A3, Cmd_30A3
	.4byte 0x30AD, Map_LoadMapScripted
	.4byte 0x30CC, Cmd_30CC
	.4byte 0x3117, Entity3117_Create
	.4byte 0x31FE, Entity3117_StartMoveScripted
	.4byte 0x31FF, Cmd_GetSolarGauge
	.4byte 0x320C, Entity5CCC_AddBeamScripted
	.4byte 0x3215, Cmd_3215
	.4byte 0x329B, Entity329B_Create
	.4byte 0x3361, Entity3361_Create
	.4byte 0x33AA, Cmd_33AA
	.4byte 0x33C4, Cmd_33C4
	.4byte 0x3469, Cmd_Random @ HashName("ランダム")
	.4byte 0x34C2, Entity3117_ShowScripted
	.4byte 0x34EA, EnemyDexMenu_Create @ HashName("魔物図鑑")
	.4byte 0x352D, MessageWindow_SetExtend
	.4byte 0x3535, MosaicFader_StartFromScript
	.4byte 0x3613, Cmd_LockPlayer
	.4byte 0x364D, sound_08240344
	.4byte 0x3699, Cmd_3699
	.4byte 0x3705, Cmd_3705
	.4byte 0x3757, Cmd_GiveWeapon @ HashName("武器取得")
	.4byte 0x377D, Cmd_377D
	.4byte 0x3A5D, Cmd_RemoveItem @ HashName("アイテム破棄")
	.4byte 0x3A89, BgPlttBlender_AddSlotFromScript
	.4byte 0x3C3E, Cmd_3C3E
	.4byte 0x3C47, Cmd_GetSunriseTime @ HashName("日の出時間取得")
	.4byte 0x3C48, Cmd_3C48
	.4byte 0x3C8D, VM_ResetGameKeepingVars
	.4byte 0x3D0C, Cmd_3D0C
	.4byte 0x3D17, Cmd_3D17
	.4byte 0x3DB0, Entity3DB0_Create
	.4byte 0x3DB8, Cmd_GetPathNodePos
	.4byte 0x3DF7, TextSlideshow_Create
	.4byte 0x3E17, Cmd_3E17
	.4byte 0x3E1F, Cmd_3E1F
	.4byte 0x3E91, Elevator_Destroy
	.4byte 0x3E93, Cmd_3E93
	.4byte 0x3EA2, Cmd_3EA2
	.4byte 0x3ED0, Cmd_3ED0
	.4byte 0x3F3B, Cmd_GetCrossoverBattleWins
	.4byte 0x3F4B, Cmd_UnlockPhoto
	.4byte 0x3F96, Cmd_3F96
	.4byte 0x3F99, EnemyOctopus_Create @ HashName("オクトパス")
	.4byte 0x3FFD, Entity3FFD_Create
	.4byte 0x4063, Entity4063_Create
	.4byte 0x409D, Cmd_409D
	.4byte 0x40A6, Cmd_40A6
	.4byte 0x40D7, Cmd_40D7
	.4byte 0x40F8, Cmd_40F8
	.4byte 0x4127, Cmd_4127
	.4byte 0x41D3, Cmd_41D3
	.4byte 0x4235, WeatherManager_StartScripted
	.4byte 0x42EF, Cmd_42EF
	.4byte 0x430D, Cmd_Delay @ HashName("delay")
	.4byte 0x435E, Cmd_DeleteShadow @ HashName("影削除")
	.4byte 0x4383, Cmd_4383
	.4byte 0x43A0, Cmd_ReadTable
	.4byte 0x43D6, Cmd_43D6
	.4byte 0x440F, Cmd_TestEquipBuff
	.4byte 0x44BF, Cmd_44BF
	.4byte 0x44CD, Entity8AF6_SetPoseScripted
	.4byte 0x4561, Cmd_4561
	.4byte 0x4631, Cmd_RemoveAllSpiritBugs
	.4byte 0x4759, TimeMC_Create
	.4byte 0x48B3, Entity8AAB_SetPriorityScripted
	.4byte 0x490F, Cmd_490F
	.4byte 0x4A16, EntityEF66_StopScripted
	.4byte 0x4A8D, Cmd_IsKaamos
	.4byte 0x4AB1, ShadeManCrossover_Create @ HashName("クロスオーバーシェードマン")
	.4byte 0x4AE5, Entity4AE5_Create
	.4byte 0x4B15, Entity4B15_Create
	.4byte 0x4B39, Cmd_4B39
	.4byte 0x4B41, Cmd_4B41
	.4byte 0x4B57, Cmd_4B57
	.4byte 0x4C4D, Cmd_UnlockPlayer
	.4byte 0x4CBB, Cmd_4CBB
	.4byte 0x4CCD, Cmd_4CCD
	.4byte 0x4CDD, Cmd_4CDD
	.4byte 0x4D4D, ObjPlttBlender_Create
	.4byte 0x4D88, Cmd_CheckEmptySlotExist
	.4byte 0x4DDF, Entity4DDF_Create
	.4byte 0x4E22, Cmd_4E22
	.4byte 0x4E30, Cmd_GetRtcStatus
	.4byte 0x4E69, MsgBus_Create
	.4byte 0x4EBF, Cmd_4EBF
	.4byte 0x4ED4, Cmd_FadeInBGM @ HashName("ＢＧＭフェードイン")
	.4byte 0x4F5C, Entity4F5C_Create
	.4byte 0x4FD1, Cmd_4FD1
	.4byte 0x501B, Entity501B_Create
	.4byte 0x515D, Cmd_515D
	.4byte 0x517B, BgPlttGroupFader_Create
	.4byte 0x522C, EnemyFlameSnake_Create
	.4byte 0x5276, Cmd_5276
	.4byte 0x5292, Entity5292_Create
	.4byte 0x52BF, AlbumMenu_Create
	.4byte 0x5365, Cmd_GetSunsetTime @ HashName("日没時間取得")
	.4byte 0x53BF, Cmd_53BF
	.4byte 0x5460, EntityBA36_SetRemaining
	.4byte 0x546C, Cmd_546C
	.4byte 0x5470, Cmd_5470
	.4byte 0x54C1, UnlockMap @ HashName("マップ取得")
	.4byte 0x54DF, Elevator_SetPltt
	.4byte 0x5517, Cmd_5517
	.4byte 0x554B, EntityA628_DeactivateScripted
	.4byte 0x55C2, Entity55C2_Create
	.4byte 0x55C5, Cmd_55C5
	.4byte 0x5645, Entity5645_Create
	.4byte 0x56AD, Cmd_56AD
	.4byte 0x56DC, Entity56DC_Create
	.4byte 0x571D, CoffinShop_Create @ HashName("棺桶屋")
	.4byte 0x5844, Cmd_5844
	.4byte 0x58D7, Cmd_58D7
	.4byte 0x5933, Cmd_GetMoonPhase
	.4byte 0x5941, Entity5941_Create
	.4byte 0x5986, Cmd_5986
	.4byte 0x5A36, Cmd_5A36
	.4byte 0x5B01, Cmd_5B01
	.4byte 0x5C0B, Cmd_5C0B
	.4byte 0x5C9E, Cmd_5C9E
	.4byte 0x5CC4, Cmd_5CC4
	.4byte 0x5CCC, Cmd_5CCC
	.4byte 0x5D74, Cmd_5D74
	.4byte 0x5DA5, Entity5DA5_Create
	.4byte 0x5E27, Entity5E27_Create
	.4byte 0x5F5F, Cmd_GetInputKeys
	.4byte 0x5FDA, Cmd_RemoveGoodCond
	.4byte 0x6057, Cmd_6057
	.4byte 0x60FB, Cmd_60FB
	.4byte 0x610A, Cmd_610A
	.4byte 0x612E, Cmd_612E
	.4byte 0x619C, Cmd_619C
	.4byte 0x61A0, Cmd_CalcInterestRate
	.4byte 0x6206, Cmd_6206
	.4byte 0x6273, TextPanelManager_Create
	.4byte 0x62AA, Cmd_62AA
	.4byte 0x62BC, Cmd_62BC
	.4byte 0x6367, Entity6367_Create @ HashName("エンディング")
	.4byte 0x6414, Cmd_6414
	.4byte 0x641D, Cmd_641D
	.4byte 0x6487, Cmd_6487
	.4byte 0x650B, Cmd_650B
	.4byte 0x65E1, Cmd_65E1
	.4byte 0x65E2, Cmd_ResetWeapons @ HashName("武器初期化")
	.4byte 0x667C, Cmd_667C
	.4byte 0x6688, Cmd_6688
	.4byte 0x6790, Cmd_6790
	.4byte 0x680E, EnemyCuroro_Create
	.4byte 0x686E, Cmd_686E
	.4byte 0x6913, EnemyMummy_Create @ HashName("マミー")
	.4byte 0x6978, Entity6978_Create
	.4byte 0x69CD, Cmd_69CD
	.4byte 0x6AFF, Cmd_6AFF
	.4byte 0x6B24, Cmd_6B24
	.4byte 0x6CBE, Cmd_6CBE
	.4byte 0x6D69, DoorManager_Create
	.4byte 0x6E7D, Cmd_6E7D
	.4byte 0x6F85, Cmd_6F85
	.4byte 0x7017, Cmd_7017
	.4byte 0x706D, EnemySandWorm_Create @ HashName("サンドウォーム")
	.4byte 0x7117, Cmd_7117
	.4byte 0x71BA, Entity71BA_Create
	.4byte 0x71C6, Cmd_ResetItems @ HashName("アイテム初期化")
	.4byte 0x71E7, MessageChoice_SetTextFromScript
	.4byte 0x723E, Entity723E_Create
	.4byte 0x727F, MessageWindow_SetInstantScripted
	.4byte 0x7300, KidShop_Create @ HashName("道具屋")
	.4byte 0x730A, Entity730A_Create
	.4byte 0x7348, Demo_Start
	.4byte 0x73FE, Cmd_CreateShadow @ HashName("影配置")
	.4byte 0x744F, WeaponShop_Create @ HashName("武器屋")
	.4byte 0x7539, Camera_SetTilemapOffset
	.4byte 0x7566, Cmd_7566
	.4byte 0x75AF, MessageWindow_SetScriptIdsScripted
	.4byte 0x75B7, Cmd_75B7
	.4byte 0x75B9, Cmd_75B9
	.4byte 0x7636, Cmd_ForEach @ HashName("foreach")
	.4byte 0x7659, Cmd_7659
	.4byte 0x778B, Entity778B_Create
	.4byte 0x779F, Cmd_779F
	.4byte 0x7806, Cmd_7806
	.4byte 0x7843, Cmd_7843
	.4byte 0x78C9, Entity78C9_Create
	.4byte 0x78EE, Cmd_78EE
	.4byte 0x7935, Cmd_InitArray
	.4byte 0x794C, Entity794C_Create
	.4byte 0x7974, Cmd_SetMessageWindowWait
	.4byte 0x7999, Entity7999_Create
	.4byte 0x79B7, Map_AddLoadingZoneIndicatorScripted
	.4byte 0x79EC, Cmd_79EC
	.4byte 0x7A0A, Cmd_7A0A
	.4byte 0x7A25, Cmd_7A25 @ HashName("シングルプレイ")
	.4byte 0x7A27, Cmd_LoadTileMap
	.4byte 0x7A75, Cmd_7A75
	.4byte 0x7A77, Cmd_SetSolarBankBalance
	.4byte 0x7A82, Cmd_7A82
	.4byte 0x7B7D, Cmd_7B7D
	.4byte 0x7B9F, Cmd_7B9F
	.4byte 0x7C62, Entity7C62_Create
	.4byte 0x7CE7, Cmd_7CE7
	.4byte 0x7D90, Cmd_TakeEquippedWeapon
	.4byte 0x7E33, Elevator_Start
	.4byte 0x7E73, WeatherManager_StopScripted
	.4byte 0x7EBA, Cmd_7EBA
	.4byte 0x7F44, Cmd_7F44
	.4byte 0x7F5E, SolarBank_Create @ HashName("太陽バンク")
	.4byte 0x7F67, Cmd_7F67
	.4byte 0x800C, BgPlttGroupFader_SetModeScripted
	.4byte 0x8071, Cmd_CameraPanTo
	.4byte 0x8089, Map_SpawnLoadingZoneIndicator
	.4byte 0x814C, Cmd_HasItem
	.4byte 0x8153, Cmd_8153
	.4byte 0x815C, Cmd_815C
	.4byte 0x81C4, Cmd_81C4
	.4byte 0x820B, Cmd_820B
	.4byte 0x827A, Cmd_827A
	.4byte 0x82B3, Cmd_82B3
	.4byte 0x82B7, Entity82B7_Create
	.4byte 0x82C8, Cmd_82C8
	.4byte 0x8337, Entity3117_AddEntryScripted
	.4byte 0x83B2, Entity83B2_Create
	.4byte 0x83E5, GameResult_Create
	.4byte 0x83E7, Cmd_IsMagicUnlocked
	.4byte 0x8400, Cmd_8400
	.4byte 0x8459, Cmd_8459
	.4byte 0x8602, Entity2D2B_SetLitDurationScripted
	.4byte 0x86F3, Cmd_SetShadowMode
	.4byte 0x877F, Cmd_877F
	.4byte 0x87E4, EnemySpider_Create @ HashName("スパイダー")
	.4byte 0x87FE, MorningDew_Create
	.4byte 0x883A, Cmd_883A
	.4byte 0x8894, Cmd_8894
	.4byte 0x88B7, Cmd_88B7
	.4byte 0x8918, Cmd_8918
	.4byte 0x8954, Cmd_8954
	.4byte 0x898D, Cmd_898D
	.4byte 0x89C6, Cmd_89C6
	.4byte 0x8A21, EntityAB4E_AddElemScripted
	.4byte 0x8AAB, Entity8AAB_Create
	.4byte 0x8AF6, Entity8AF6_Create
	.4byte 0x8B67, Cmd_8B67
	.4byte 0x8B8E, Entity8B8E_Create
	.4byte 0x8C35, EnemyBombGolem_Create @ HashName("通信ゴーレム")
	.4byte 0x8CC7, Cmd_8CC7
	.4byte 0x8CFE, Cmd_8CFE
	.4byte 0x8D2D, WeaponDexMenu_Create @ HashName("武器図鑑")
	.4byte 0x8D5C, Entity8D5C_Create
	.4byte 0x8E9F, EnemyCheyenne_Create @ HashName("シャイアン")
	.4byte 0x8EA3, Cmd_8EA3
	.4byte 0x8EC8, Entity8EC8_Create
	.4byte 0x8ECD, WeatherManager_Create
	.4byte 0x8F41, MessageWindow_SetBgPlttScripted
	.4byte 0x8FA3, Cmd_8FA3
	.4byte 0x904B, Cmd_SetCrossoverPoint
	.4byte 0x9053, Cmd_9053
	.4byte 0x90B4, Cmd_90B4
	.4byte 0x9146, Cmd_9146
	.4byte 0x920F, Cmd_920F
	.4byte 0x9284, CrossoverLobby_Create
	.4byte 0x92BE, MissionMarker_Create
	.4byte 0x92ED, Entity92ED_Create
	.4byte 0x930F, Cmd_SetMessageWindowRect
	.4byte 0x9311, Cmd_9311
	.4byte 0x933C, Player_MoveTo @ HashName("バロメータ")?
	.4byte 0x9386, Durathror_Create @ HashName("ドゥラスロール")
	.4byte 0x94D9, EnemyBokuLink_Create @ HashName("通信ボク")
	.4byte 0x94EB, Cmd_94EB
	.4byte 0x9519, PasswordScreen_Create @ HashName("パスワード")
	.4byte 0x9531, MessageChoice_CreateFromScript
	.4byte 0x95A8, SolarBamboo_Create @ HashName("太陽竹")
	.4byte 0x95F8, SunCountdown_Create
	.4byte 0x9700, Cmd_9700
	.4byte 0x9763, Cmd_9763
	.4byte 0x9769, Cmd_9769
	.4byte 0x980B, PlayerLink_Create @ HashName("通信対戦プレイヤー")
	.4byte 0x9817, Cmd_9817
	.4byte 0x983A, Cmd_983A
	.4byte 0x98EC, EnemyGolem_Create @ HashName("ゴーレム")
	.4byte 0x997B, Entity8AF6_MoveToScripted
	.4byte 0x99CA, Entity99CA_Create
	.4byte 0x99F8, Cmd_99F8
	.4byte 0x99FA, Cmd_SetBossFlags
	.4byte 0x9A9F, Entity9A9F_Create
	.4byte 0x9AC8, Cmd_9AC8
	.4byte 0x9BC7, Cmd_9BC7
	.4byte 0x9C3F, Entity8AF6_ShowScripted
	.4byte 0x9DFE, Cmd_9DFE
	.4byte 0x9E8B, Cmd_GetSolarBankBalance
	.4byte 0x9E8D, EnemyCrow_Create @ HashName("クロウ")
	.4byte 0x9EC0, Entity6978_SetRequestScripted
	.4byte 0x9FB7, Cmd_9FB7
	.4byte 0x9FFD, Cmd_9FFD
	.4byte 0xA062, Cmd_A062
	.4byte 0xA0A6, EntityA0A6_Create
	.4byte 0xA133, Cmd_A133
	.4byte 0xA16F, ElevatorController_Create
	.4byte 0xA1D7, Cmd_A1D7
	.4byte 0xA222, Save_ReadSystemDataOrInit
	.4byte 0xA285, Cmd_A285
	.4byte 0xA288, EntityA288_Create
	.4byte 0xA2E1, Cmd_A2E1
	.4byte 0xA2E4, Cmd_A2E4
	.4byte 0xA301, Cmd_A301
	.4byte 0xA39F, Cmd_A39F
	.4byte 0xA3AA, Cmd_A3AA
	.4byte 0xA3B3, Cmd_A3B3
	.4byte 0xA4FC, Elevator_Create
	.4byte 0xA61C, Map_SetLoadingZoneIndicatorMode
	.4byte 0xA628, EntityA628_CreateScripted
	.4byte 0xA687, BgPlttDimmer_Create
	.4byte 0xA76D, Cmd_SetEnemyDexDropItemFlag
	.4byte 0xA7CE, Cmd_A7CE
	.4byte 0xA864, Cmd_A864
	.4byte 0xA8F1, EntityA8F1_Create
	.4byte 0xA995, Cmd_A995
	.4byte 0xA99F, Cmd_A99F
	.4byte 0xAA62, Cmd_AA62
	.4byte 0xAA65, CactusManager_Create
	.4byte 0xAB3C, Cmd_SetMessageWindowVar
	.4byte 0xAB41, Cmd_AB41
	.4byte 0xAB4E, EntityAB4E_Create
	.4byte 0xAB8E, Cmd_AB8E
	.4byte 0xAB9C, Cmd_AB9C
	.4byte 0xAC98, EnemyCockatrice_Create @ HashName("コカトリス")
	.4byte 0xACE3, ClockAlarm_Create
	.4byte 0xAD03, EnemySkeleton_Create @ HashName("スケルトン")
	.4byte 0xADB6, Cmd_ADB6
	.4byte 0xADD2, MessageWindow_EnableAutoAdvance
	.4byte 0xAE3A, Cmd_AE3A
	.4byte 0xAE4E, Cmd_AE4E
	.4byte 0xAE71, Cmd_AE71
	.4byte 0xAEB2, Entity080e18e0_Create
	.4byte 0xAF33, EntityAF33_Create
	.4byte 0xAF43, Cmd_AF43
	.4byte 0xAF8E, Entity4063_Cancel
	.4byte 0xB005, Cmd_B005
	.4byte 0xB0B4, Entity5DA5_SetStateScripted
	.4byte 0xB0BC, SaveSequence_Create
	.4byte 0xB164, LevelUpper_Create
	.4byte 0xB189, Cmd_B189
	.4byte 0xB1C4, Cmd_ShakeElevator
	.4byte 0xB294, Cmd_B294
	.4byte 0xB3D1, EntityB3D1_Create
	.4byte 0xB3D7, Cmd_B3D7 @ HashName("アルバム")
	.4byte 0xB426, DungeonTitle_Create @ HashName("ダンジョンタイトル")
	.4byte 0xB45F, Cmd_GetCrossoverPoint
	.4byte 0xB47E, Entity3117_SetPriorityScripted
	.4byte 0xB4B4, Cmd_CreateBG
	.4byte 0xB50D, Cmd_B50D
	.4byte 0xB55A, Cmd_GetDateTime @ HashName("時間取得")
	.4byte 0xB603, Cmd_B603
	.4byte 0xB639, ZoneList_Create
	.4byte 0xB683, Cmd_B683
	.4byte 0xB6CE, Cmd_B6CE
	.4byte 0xB6FF, EntityB6FF_Create
	.4byte 0xB76C, Cmd_B76C
	.4byte 0xB838, Cmd_B838
	.4byte 0xB83E, Cmd_B83E
	.4byte 0xB85F, LinkBattleResult_Create
	.4byte 0xB87B, EntityB87B_Create
	.4byte 0xB88C, EntityB88C_Create
	.4byte 0xB8B9, MoverList_Create
	.4byte 0xB8C7, Cmd_B8C7
	.4byte 0xBA36, EntityBA36_Create
	.4byte 0xBA4B, Ringo_Create @ HashName("リンゴ")
	.4byte 0xBB01, Cmd_BB01
	.4byte 0xBB34, Cmd_BB34 @ HashName("おてんこ")
	.4byte 0xBBAA, Cmd_BBAA
	.4byte 0xBD74, BlackHole_Create @ HashName("ブラックホール")
	.4byte 0xBE46, Cmd_BE46
	.4byte 0xBEC2, Cmd_GetMoverPos
	.4byte 0xBEF5, EnemyMimic_Create @ HashName("ミミック")
	.4byte 0xC015, Crossover_LoadMappingBuf
	.4byte 0xC0B0, Camera_Create
	.4byte 0xC12A, Cmd_C12A
	.4byte 0xC12D, Cmd_C12D
	.4byte 0xC15E, Cmd_C15E
	.4byte 0xC1F2, Enemy_Sleep
	.4byte 0xC233, Cmd_C233
	.4byte 0xC347, Cmd_C347
	.4byte 0xC3BC, EnemySlime_Create @ HashName("スライム")
	.4byte 0xC419, Entity081d0e20_Create
	.4byte 0xC438, DungeonMarker_Create
	.4byte 0xC46E, Cmd_C46E
	.4byte 0xC556, MessageWindow_CloseScripted
	.4byte 0xC5D8, Cmd_FreeShadeManCrossoverScriptArg
	.4byte 0xC60F, EntityC60F_Create
	.4byte 0xC673, Cmd_C673
	.4byte 0xC6AA, Textbox_CloseBox
	.4byte 0xC765, Entity3117_SetPoseScripted
	.4byte 0xC783, LinkBattleLobby_Create
	.4byte 0xC7DC, Cmd_C7DC
	.4byte 0xC814, EntityC814_Create
	.4byte 0xC946, PreviewStage_Create
	.4byte 0xC9BC, EntityC9BC_Create
	.4byte 0xCA3D, Cmd_CA3D
	.4byte 0xCA73, EnemyDogLink_Create @ HashName("通信ドッグ")
	.4byte 0xCA7D, Cmd_CA7D
	.4byte 0xCAEE, Cmd_CAEE
	.4byte 0xCAFE, Cmd_CAFE
	.4byte 0xCB30, Cmd_CB30
	.4byte 0xCBB0, PileDriver_Create @ HashName("パイルドライバー")
	.4byte 0xCC28, MainMenu_Create
	.4byte 0xCCD3, EnemyGhost_Create @ HashName("ゴースト")
	.4byte 0xCCD9, Cmd_CCD9
	.4byte 0xCD57, Cmd_CD57
	.4byte 0xCE28, Cmd_CE28
	.4byte 0xCED9, Cmd_CED9
	.4byte 0xCF58, EntityCF58_Create
	.4byte 0xCF79, Title_Create @ HashName("タイトル")
	.4byte 0xCF82, EntityCF82_Create
	.4byte 0xD0C3, Demo_Stop
	.4byte 0xD0C7, Cmd_D0C7
	.4byte 0xD0CE, Cmd_D0CE
	.4byte 0xD169, Cmd_D169
	.4byte 0xD1C0, Cmd_SetEnemyDexSeenFlag
	.4byte 0xD229, Cmd_D229
	.4byte 0xD24B, coffin_0808623c
	.4byte 0xD25F, Entity5CCC_AddLightAreaScripted
	.4byte 0xD285, Cmd_D285
	.4byte 0xD37F, Jormungandr_Create @ HashName("ヨルムンガンド")
	.4byte 0xD3A9, EntityD3A9_Create
	.4byte 0xD401, MessageWindow_SetPendingLineScripted
	.4byte 0xD40E, Cmd_D40E
	.4byte 0xD438, EntityD438_Create
	.4byte 0xD4B5, Cmd_AddForgeExp
	.4byte 0xD4E3, Cmd_D4E3
	.4byte 0xD53D, EntityD53D_Create
	.4byte 0xD562, Cmd_D562
	.4byte 0xD6F7, Cmd_D6F7
	.4byte 0xD774, Cmd_D774
	.4byte 0xD7F4, Entity3117_StartPlttFadeScripted
	.4byte 0xD852, ArrowManager_Create
	.4byte 0xD854, EnemyTargetManager_Create
	.4byte 0xD8DF, Cmd_D8DF
	.4byte 0xD916, Cmd_ReplaceWeapon
	.4byte 0xD935, Entity0804e2c0_Create
	.4byte 0xD9AE, EntityD9AE_Create @ HashName("パス")?
	.4byte 0xD9B7, Cmd_RemoveKaamos
	.4byte 0xD9D3, BgPlttAnimator_Create
	.4byte 0xDA0B, EntityDA0B_Create
	.4byte 0xDA19, Cmd_DA19
	.4byte 0xDA5A, Cmd_GetZoneBounds
	.4byte 0xDAA4, Cmd_GetPrefecture
	.4byte 0xDB6C, Cmd_MoveShadow @ HashName("影位置変更")
	.4byte 0xDC21, SolarStation_Create @ HashName("太陽スタンド")
	.4byte 0xDD0E, Cmd_DD0E
	.4byte 0xDD91, MessageWindow_ConfigureScripted
	.4byte 0xDDCF, Cmd_DDCF
	.4byte 0xDDD0, Cmd_DDD0
	.4byte 0xDDEE, Cmd_DDEE
	.4byte 0xDDF8, EntityA628_StartFollowCameraScripted
	.4byte 0xDEA2, Entity3117_StartScaleScripted
	.4byte 0xDED5, GameOverManager_StartScripted
	.4byte 0xDF85, Cmd_DF85
	.4byte 0xDFAB, Cmd_DFAB
	.4byte 0xDFC6, Marquee_Create
	.4byte 0xE019, Cmd_E019
	.4byte 0xE02A, Cmd_E02A
	.4byte 0xE02E, Warehouse_Create @ HashName("倉庫")
	.4byte 0xE06A, EntityE06A_Create
	.4byte 0xE083, Cmd_UnlockMagic @ HashName("魔法取得")
	.4byte 0xE0A5, Cmd_E0A5
	.4byte 0xE0E1, Cmd_E0E1
	.4byte 0xE131, EnemyBee_Create @ HashName("ビー")
	.4byte 0xE14B, Cmd_E14B
	.4byte 0xE1C6, Cmd_E1C6
	.4byte 0xE28B, EntityE28B_Create
	.4byte 0xE435, EntityE435_Create
	.4byte 0xE4A3, Cmd_E4A3
	.4byte 0xE4B1, Cmd_SetBGLayer
	.4byte 0xE534, EntityE534_Create
	.4byte 0xE6CA, Cmd_SoundResume @ HashName("サウンド再開")
	.4byte 0xE6F2, Cmd_E6F2
	.4byte 0xE70E, Cmd_E70E
	.4byte 0xE756, Cmd_E756
	.4byte 0xE77C, Entity3117_SetAnimScripted
	.4byte 0xE7CA, Cmd_E7CA
	.4byte 0xE990, Cmd_E990
	.4byte 0xE9D3, DarkLoans_Create @ HashName("暗黒ローン")
	.4byte 0xE9DA, Cmd_E9DA
	.4byte 0xE9E2, Cmd_E9E2
	.4byte 0xEA00, Cmd_EA00
	.4byte 0xEA96, Cmd_EA96
	.4byte 0xEAAC, Cmd_EAAC
	.4byte 0xEAAF, Cmd_EAAF
	.4byte 0xEAB4, Entity8AF6_AddEntryScripted
	.4byte 0xEB42, Cmd_EB42
	.4byte 0xEBFF, Entity8AF6_HideScripted
	.4byte 0xEC1F, Cmd_Assert @ HashName("assert")
	.4byte 0xEC2A, EnemyManager_Create
	.4byte 0xEC5B, Cmd_EC5B
	.4byte 0xEC96, EntityEC96_Create
	.4byte 0xED07, BreakableManager_Create
	.4byte 0xED1F, Cmd_ED1F
	.4byte 0xED2E, Cmd_IsCrossoverUnlocked
	.4byte 0xEDE2, Cmd_HideBG @ HashName("BG非表示")
	.4byte 0xEE18, Cmd_EE18
	.4byte 0xEF19, EntityA628_ActivateScripted
	.4byte 0xEF66, EntityEF66_Create
	.4byte 0xEF6F, EntityEF6F_Create
	.4byte 0xEFD1, Cmd_EFD1
	.4byte 0xEFE6, Cmd_EFE6
	.4byte 0xF04A, GameOver_CancelScripted
	.4byte 0xF04B, Cmd_F04B
	.4byte 0xF0CC, Cmd_F0CC
	.4byte 0xF11C, Cmd_HasWeapon
	.4byte 0xF156, SolarCircle_Create @ HashName("太陽結界")
	.4byte 0xF1F9, Cmd_CreateBeeNest @ HashName("蜂の巣")
	.4byte 0xF200, Cmd_F200
	.4byte 0xF33F, Cmd_F33F
	.4byte 0xF341, Camera_Reset
	.4byte 0xF404, EntityD9AE_ReleaseAll
	.4byte 0xF41A, EntityF41A_Create
	.4byte 0xF5EB, CreatePlayer @ HashName("プレイヤー")
	.4byte 0xF661, Entity3117_HideScripted
	.4byte 0xF836, EnemyDog_Create @ HashName("ドッグ")
	.4byte 0xF8BE, EnemyBat_Create @ HashName("バット")
	.4byte 0xF982, Cmd_F982
	.4byte 0xF993, Cmd_F993
	.4byte 0xF9F1, Cmd_CountFoundArmors
	.4byte 0xFA5D, Cmd_FA5D
	.4byte 0xFB53, JoyspotManager_Create
	.4byte 0xFB8C, GameOverManager_Create
	.4byte 0xFBC1, Cmd_GetDayDiff @ HashName("日数差取得")
	.4byte 0xFBE5, EntityFBE5_Create
	.4byte 0xFD12, Cmd_FD12
	.4byte 0xFD6B, Entity778B_AddElemScripted
	.4byte 0xFD86, Cmd_FD86
	.4byte 0xFEBB, Cmd_FEBB
	.4byte 0xFEE0, Coffin_RequestKill
	.4byte 0xFEF2, armor_082433bc
	.4byte 0x0000, 0x00000000

@ おそらくこのコマンドテーブルのビルド日時
Timestamp:
  .4byte 1089259575 @ 2004-07-09 18:04:39 UTC
