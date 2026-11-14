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
	.4byte 0x0238, Cmd_GetEntityBA36Remaining
	.4byte 0x025E, Cmd_025E
	.4byte 0x0272, Cmd_SetPlayerName
	.4byte 0x0353, Cmd_SetPlayerDead
	.4byte 0x03CA, Cmd_OtenkoGuideWink
	.4byte 0x0447, Cmd_OtenkoGuideCheer
	.4byte 0x054A, Cmd_054A
	.4byte 0x058D, Cmd_058D
	.4byte 0x05A5, Boku_Create @ HashName("ボク")
	.4byte 0x05E2, Cmd_05E2
	.4byte 0x061E, Cmd_061E
	.4byte 0x0623, ShadeMan_Create @ HashName("シェードマン")
	.4byte 0x064E, Cmd_064E
	.4byte 0x0740, Cmd_0740
	.4byte 0x075C, Cmd_GetEntity4063Remaining
	.4byte 0x0866, Cmd_0866
	.4byte 0x08F4, Entity08F4_Create
	.4byte 0x0955, Cmd_0955
	.4byte 0x09EA, Cmd_09EA
	.4byte 0x0AC7, Centipede_Create
	.4byte 0x0AD8, Cmd_0AD8 @ HashName("センチピード")?
	.4byte 0x0B50, Coffin_Create @ HashName("棺桶")
	.4byte 0x0BCE, Cmd_0BCE
	.4byte 0x0BFD, Cmd_ClearMapIconFlag
	.4byte 0x0C1B, Cmd_SetMapIconFlag
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
	.4byte 0x1343, Cmd_KnockPlayerProne
	.4byte 0x138E, Cmd_SoftReset
	.4byte 0x13AC, Serpent_Create @ HashName("サーペント")
	.4byte 0x1422, Cmd_1422
	.4byte 0x1488, Cmd_HugeExplosion @ HashName("大爆発")
	.4byte 0x1500, Cmd_ShowBG @ HashName("BG表示")
	.4byte 0x150F, Entity150F_Create
	.4byte 0x15A9, Cmd_15A9
	.4byte 0x15B3, Cmd_15B3
	.4byte 0x15ED, Cmd_15ED
	.4byte 0x162E, CoffinTimer_Create
	.4byte 0x164D, Cmd_164D
	.4byte 0x1693, Cmd_1693
	.4byte 0x172B, Duneyrr_Create
	.4byte 0x172D, Cmd_BlowAwayPlayer
	.4byte 0x1744, DarkRoot_Create @ HashName("暗黒の根")
	.4byte 0x180B, Cmd_SetCameraBoundsType2
	.4byte 0x1833, Cmd_Nop_1833
	.4byte 0x184B, Cmd_ConnectCameraToTilemap
	.4byte 0x1870, Cmd_PlaySound
	.4byte 0x1887, Cmd_InitMagicData @ HashName("魔法初期化")
	.4byte 0x19CC, Cmd_SetEntity2D2BState
	.4byte 0x1A35, Cmd_MoveOtenkoGuideTo
	.4byte 0x1B24, Entity1B24_Create
	.4byte 0x1B77, Cmd_Nop_1B77
	.4byte 0x1BEE, Cmd_AddPlayerExp
	.4byte 0x1C3E, Cmd_GetDayOfWeek @ HashName("曜日取得")
	.4byte 0x1C64, Cmd_OpenMessageWindow
	.4byte 0x1DBE, Cmd_1DBE
	.4byte 0x1E97, Cmd_1E97
	.4byte 0x1E98, Entity1E98_Create
	.4byte 0x1EA4, Cmd_FreeDurathrorScriptArg
	.4byte 0x1ED1, Cmd_1ED1
	.4byte 0x1F3B, Cmd_PlayerFireGun
	.4byte 0x1F65, Cmd_SetInteractPointPos
	.4byte 0x2141, Cmd_2141
	.4byte 0x2207, Cmd_2207
	.4byte 0x225B, Cmd_225B
	.4byte 0x2306, Cmd_SpawnCactus
	.4byte 0x2354, Cmd_GetCrossoverBattleCount
	.4byte 0x237A, Cmd_GetWeaponKind
	.4byte 0x2502, Cmd_ResumeCutscene
	.4byte 0x2571, Cmd_2571
	.4byte 0x2575, Cmd_2575
	.4byte 0x2593, Cmd_SetPlayerProne
	.4byte 0x25F3, AlarmPanel_Create @ HashName("太陽警報機")
	.4byte 0x2740, Cmd_EndInteract
	.4byte 0x274E, Cmd_274E
	.4byte 0x277A, Cmd_SpawnEntity080ac574
	.4byte 0x286B, Cmd_286B
	.4byte 0x286F, ActorManager_Create
	.4byte 0x28CB, CoffinSealEffect_Create
	.4byte 0x2924, Cmd_StopRoomBlindFollowCamera
	.4byte 0x29F1, Cmd_29F1
	.4byte 0x2B06, AllySabata_Create @ HashName("サバタ")
	.4byte 0x2B68, Cmd_ClearElementalCond
	.4byte 0x2B8C, Cmd_SpawnFallingObject
	.4byte 0x2D2B, Entity2D2B_Create
	.4byte 0x2D30, EnemyAx_Create @ HashName("アックス")
	.4byte 0x2D36, Taiyo_Create
	.4byte 0x2D8F, Cmd_SpawnBreakable
	.4byte 0x2E1C, Cmd_AddEntity2D2BElem
	.4byte 0x2F01, Cmd_GetSpanOfTime @ HashName("時間帯取得")
	.4byte 0x2F51, Cmd_Nop_2F51
	.4byte 0x2FA0, Cmd_2FA0
	.4byte 0x2FA5, Cmd_2FA5
	.4byte 0x2FE4, Cmd_GetBackupValue
	.4byte 0x3004, Cmd_3004
	.4byte 0x300F, Cmd_300F
	.4byte 0x3019, RitaShop_Create
	.4byte 0x305A, Cmd_GetItem @ HashName("アイテム取得")
	.4byte 0x3062, Cmd_IsRoomDim
	.4byte 0x30A3, Cmd_SetOtenkoGuideFlip
	.4byte 0x30AD, Cmd_LoadMap
	.4byte 0x30CC, Cmd_30CC
	.4byte 0x3117, Entity3117_Create
	.4byte 0x31FE, Cmd_StartEntity3117Move
	.4byte 0x31FF, Cmd_GetSolarGauge
	.4byte 0x320C, Cmd_AddEntity5CCCBeam
	.4byte 0x3215, Cmd_3215
	.4byte 0x329B, Entity329B_Create
	.4byte 0x3361, Entity3361_Create
	.4byte 0x33AA, Cmd_33AA
	.4byte 0x33C4, Cmd_33C4
	.4byte 0x3469, Cmd_Random @ HashName("ランダム")
	.4byte 0x34C2, Cmd_ShowEntity3117
	.4byte 0x34EA, EnemyDexMenu_Create @ HashName("魔物図鑑")
	.4byte 0x352D, Cmd_SetMessageWindowExtend
	.4byte 0x3535, Cmd_StartMosaicFader
	.4byte 0x3613, Cmd_LockPlayer
	.4byte 0x364D, Cmd_StopSound
	.4byte 0x3699, Cmd_3699
	.4byte 0x3705, Cmd_PlayerLand
	.4byte 0x3757, Cmd_GiveWeapon @ HashName("武器取得")
	.4byte 0x377D, Cmd_377D
	.4byte 0x3A5D, Cmd_RemoveItem @ HashName("アイテム破棄")
	.4byte 0x3A89, Cmd_AddBgPlttBlenderSlot
	.4byte 0x3C3E, Cmd_3C3E
	.4byte 0x3C47, Cmd_GetSunriseTime @ HashName("日の出時間取得")
	.4byte 0x3C48, Cmd_3C48
	.4byte 0x3C8D, Cmd_ResetGameKeepingVars
	.4byte 0x3D0C, Cmd_Nop_3D0C
	.4byte 0x3D17, Cmd_3D17
	.4byte 0x3DB0, Barricade_Create
	.4byte 0x3DB8, Cmd_GetPathNodePos
	.4byte 0x3DF7, TextSlideshow_Create
	.4byte 0x3E17, Cmd_3E17
	.4byte 0x3E1F, Cmd_FreeTileOverrides
	.4byte 0x3E91, Cmd_DestroyElevator
	.4byte 0x3E93, Cmd_3E93
	.4byte 0x3EA2, Cmd_3EA2
	.4byte 0x3ED0, Cmd_SetBGMVolume
	.4byte 0x3F3B, Cmd_GetCrossoverBattleWins
	.4byte 0x3F4B, Cmd_UnlockPhoto
	.4byte 0x3F96, Cmd_3F96
	.4byte 0x3F99, Octopus_Create @ HashName("オクトパス")
	.4byte 0x3FFD, Entity3FFD_Create
	.4byte 0x4063, Entity4063_Create
	.4byte 0x409D, Cmd_409D
	.4byte 0x40A6, Cmd_40A6
	.4byte 0x40D7, Cmd_40D7
	.4byte 0x40F8, Cmd_40F8
	.4byte 0x4127, Cmd_PlayerGetUp
	.4byte 0x41D3, Cmd_41D3
	.4byte 0x4235, Cmd_StartWeather
	.4byte 0x42EF, Cmd_42EF
	.4byte 0x430D, Cmd_Delay @ HashName("delay")
	.4byte 0x435E, Cmd_DeleteShadow @ HashName("影削除")
	.4byte 0x4383, Cmd_SpawnPuffs
	.4byte 0x43A0, Cmd_ReadTable
	.4byte 0x43D6, Cmd_43D6
	.4byte 0x440F, Cmd_TestEquipBuff
	.4byte 0x44BF, Cmd_44BF
	.4byte 0x44CD, Cmd_SetEntity8AF6Pose
	.4byte 0x4561, Cmd_4561
	.4byte 0x4631, Cmd_RemoveAllSpiritBugs
	.4byte 0x4759, TimeMC_Create
	.4byte 0x48B3, Cmd_SetOtenkoGuidePriority
	.4byte 0x490F, Cmd_RevertToDarkDjango
	.4byte 0x4A16, Cmd_StopEntityEF66
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
	.4byte 0x4CDD, Cmd_ShowPlayerEmote
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
	.4byte 0x515D, Cmd_SetMapSpot
	.4byte 0x517B, BgPlttGroupFader_Create
	.4byte 0x522C, EnemyFlameSnake_Create
	.4byte 0x5276, Cmd_5276
	.4byte 0x5292, Entity5292_Create
	.4byte 0x52BF, AlbumMenu_Create
	.4byte 0x5365, Cmd_GetSunsetTime @ HashName("日没時間取得")
	.4byte 0x53BF, Cmd_PlayBGM
	.4byte 0x5460, Cmd_SetEntityBA36Remaining
	.4byte 0x546C, Cmd_546C
	.4byte 0x5470, Cmd_5470
	.4byte 0x54C1, Cmd_UnlockMap @ HashName("マップ取得")
	.4byte 0x54DF, Cmd_SetElevatorPltt
	.4byte 0x5517, Cmd_5517
	.4byte 0x554B, Cmd_BrightenRoom
	.4byte 0x55C2, Entity55C2_Create
	.4byte 0x55C5, Cmd_55C5
	.4byte 0x5645, BlackPanther_Create
	.4byte 0x56AD, Cmd_56AD
	.4byte 0x56DC, Entity56DC_Create
	.4byte 0x571D, CoffinShop_Create @ HashName("棺桶屋")
	.4byte 0x5844, Cmd_5844
	.4byte 0x58D7, Cmd_PlayerFall
	.4byte 0x5933, Cmd_GetMoonPhase
	.4byte 0x5941, CWolfTargetManager_Create
	.4byte 0x5986, Cmd_IsPlayerDead
	.4byte 0x5A36, Cmd_SetDoorClosed
	.4byte 0x5B01, Cmd_ShowOtenkoGuide
	.4byte 0x5C0B, Cmd_5C0B
	.4byte 0x5C9E, Cmd_BackupState
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
	.4byte 0x612E, Cmd_SetDoorOpen
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
	.4byte 0x650B, Cmd_ApplyBadCond
	.4byte 0x65E1, Cmd_65E1
	.4byte 0x65E2, Cmd_ResetWeapons @ HashName("武器初期化")
	.4byte 0x667C, Cmd_OtenkoGuidePout
	.4byte 0x6688, Cmd_6688
	.4byte 0x6790, Cmd_6790
	.4byte 0x680E, Curoro_Create
	.4byte 0x686E, Cmd_686E
	.4byte 0x6913, Mummy_Create @ HashName("マミー")
	.4byte 0x6978, Entity6978_Create
	.4byte 0x69CD, Cmd_69CD
	.4byte 0x6AFF, Cmd_FadeOutBGM
	.4byte 0x6B24, Cmd_6B24
	.4byte 0x6CBE, Cmd_6CBE
	.4byte 0x6D69, DoorManager_Create
	.4byte 0x6E7D, Cmd_6E7D
	.4byte 0x6F85, Cmd_StopPlayerPlttEffect
	.4byte 0x7017, Cmd_GetPlayerDir
	.4byte 0x706D, Sandworm_Create @ HashName("サンドウォーム")
	.4byte 0x7117, Cmd_7117
	.4byte 0x71BA, Entity71BA_Create
	.4byte 0x71C6, Cmd_ResetItems @ HashName("アイテム初期化")
	.4byte 0x71E7, Cmd_SetMessageChoiceText
	.4byte 0x723E, CrossoverResult_Create
	.4byte 0x727F, Cmd_SetMessageWindowInstant
	.4byte 0x7300, KidShop_Create @ HashName("道具屋")
	.4byte 0x730A, Entity730A_Create
	.4byte 0x7348, Cmd_StartCutscene
	.4byte 0x73FE, Cmd_CreateShadow @ HashName("影配置")
	.4byte 0x744F, WeaponShop_Create @ HashName("武器屋")
	.4byte 0x7539, Cmd_SetCameraTilemapOffset
	.4byte 0x7566, Cmd_7566
	.4byte 0x75AF, Cmd_SetMessageWindowScriptIds
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
	.4byte 0x79B7, Cmd_AddLoadingZoneIndicator
	.4byte 0x79EC, Cmd_79EC
	.4byte 0x7A0A, Cmd_GetCoffinID
	.4byte 0x7A25, Cmd_KnockbackPlayer @ HashName("シングルプレイ")
	.4byte 0x7A27, Cmd_LoadTileMap
	.4byte 0x7A75, Cmd_7A75
	.4byte 0x7A77, Cmd_SetBankBalance @ HashName("太陽バンク残高設定")
	.4byte 0x7A82, Cmd_7A82
	.4byte 0x7B7D, Cmd_7B7D
	.4byte 0x7B9F, Cmd_7B9F
	.4byte 0x7C62, ChangeMagicSquare_Create
	.4byte 0x7CE7, Cmd_GetMapIconFlags
	.4byte 0x7D90, Cmd_TakeEquippedWeapon
	.4byte 0x7E33, Cmd_StartElevator
	.4byte 0x7E73, Cmd_StopWeather
	.4byte 0x7EBA, Cmd_7EBA
	.4byte 0x7F44, Cmd_7F44
	.4byte 0x7F5E, SolarBank_Create @ HashName("太陽バンク")
	.4byte 0x7F67, Cmd_7F67
	.4byte 0x800C, Cmd_SetBgPlttGroupFaderMode
	.4byte 0x8071, Cmd_CameraPanTo
	.4byte 0x8089, Cmd_SpawnLoadingZoneIndicator
	.4byte 0x814C, Cmd_HasItem
	.4byte 0x8153, Cmd_DisableTileOverrides
	.4byte 0x815C, Cmd_815C
	.4byte 0x81C4, Cmd_81C4
	.4byte 0x820B, Cmd_820B
	.4byte 0x827A, Cmd_827A
	.4byte 0x82B3, Cmd_SetStageID
	.4byte 0x82B7, Entity82B7_Create
	.4byte 0x82C8, Cmd_82C8
	.4byte 0x8337, Cmd_AddEntity3117Entry
	.4byte 0x83B2, InteractPointManager_Create
	.4byte 0x83E5, GameResult_Create
	.4byte 0x83E7, Cmd_IsMagicUnlocked
	.4byte 0x8400, Cmd_8400
	.4byte 0x8459, Cmd_8459
	.4byte 0x8602, Cmd_SetEntity2D2BLitDuration
	.4byte 0x86F3, Cmd_SetShadowMode
	.4byte 0x877F, Cmd_877F
	.4byte 0x87E4, Spider_Create @ HashName("スパイダー")
	.4byte 0x87FE, MorningDew_Create
	.4byte 0x883A, Cmd_AddInteractPoint
	.4byte 0x8894, Cmd_8894
	.4byte 0x88B7, Cmd_88B7
	.4byte 0x8918, Cmd_8918
	.4byte 0x8954, Cmd_8954
	.4byte 0x898D, Cmd_898D
	.4byte 0x89C6, Cmd_ClearBadCond
	.4byte 0x8A21, Cmd_AddEntityAB4EElem
	.4byte 0x8AAB, OtenkoGuide_Create
	.4byte 0x8AF6, Entity8AF6_Create
	.4byte 0x8B67, Cmd_8B67
	.4byte 0x8B8E, Entity8B8E_Create
	.4byte 0x8C35, EnemyBombGolem_Create @ HashName("通信ゴーレム")
	.4byte 0x8CC7, Cmd_SpawnDove
	.4byte 0x8CFE, Cmd_8CFE
	.4byte 0x8D2D, WeaponDexMenu_Create @ HashName("武器図鑑")
	.4byte 0x8D5C, Entity8D5C_Create
	.4byte 0x8E9F, Shaian_Create @ HashName("シャイアン")
	.4byte 0x8EA3, Cmd_8EA3
	.4byte 0x8EC8, Entity8EC8_Create
	.4byte 0x8ECD, WeatherManager_Create
	.4byte 0x8F41, Cmd_SetMessageWindowBgPltt
	.4byte 0x8FA3, Cmd_StartPlayerPlttFadeIn
	.4byte 0x904B, Cmd_SetCrossoverPoint
	.4byte 0x9053, Cmd_9053
	.4byte 0x90B4, Cmd_90B4
	.4byte 0x9146, Cmd_Nop_9146
	.4byte 0x920F, Cmd_920F
	.4byte 0x9284, CrossoverLobby_Create
	.4byte 0x92BE, MissionMarker_Create
	.4byte 0x92ED, Entity92ED_Create
	.4byte 0x930F, Cmd_SetMessageWindowRect
	.4byte 0x9311, Cmd_9311
	.4byte 0x933C, Cmd_MovePlayerTo
	.4byte 0x9386, Durathror_Create @ HashName("ドゥラスロール")
	.4byte 0x94D9, EnemyBokuLink_Create @ HashName("通信ボク")
	.4byte 0x94EB, Cmd_94EB
	.4byte 0x9519, PasswordScreen_Create @ HashName("パスワード")
	.4byte 0x9531, Cmd_CreateMessageChoice
	.4byte 0x95A8, SolarBamboo_Create @ HashName("太陽竹")
	.4byte 0x95F8, SunCountdown_Create
	.4byte 0x9700, Cmd_9700
	.4byte 0x9763, Cmd_PullCoffinTo
	.4byte 0x9769, Cmd_9769
	.4byte 0x980B, PlayerLink_Create @ HashName("通信対戦プレイヤー")
	.4byte 0x9817, Cmd_SetCoffinStage
	.4byte 0x983A, Cmd_983A
	.4byte 0x98EC, Golem_Create @ HashName("ゴーレム")
	.4byte 0x997B, Cmd_MoveEntity8AF6To
	.4byte 0x99CA, Entity99CA_Create
	.4byte 0x99F8, Cmd_SetQCEnabled
	.4byte 0x99FA, Cmd_SetBossFlags
	.4byte 0x9A9F, LinkSession_Create
	.4byte 0x9AC8, Cmd_PlayerHammerSwing
	.4byte 0x9BC7, Cmd_9BC7
	.4byte 0x9C3F, Cmd_ShowEntity8AF6
	.4byte 0x9DFE, Cmd_9DFE
	.4byte 0x9E8B, Cmd_GetBankBalance @ HashName("太陽バンク残高取得")
	.4byte 0x9E8D, Crow_Create @ HashName("クロウ")
	.4byte 0x9EC0, Cmd_SetEntity6978Request
	.4byte 0x9FB7, Cmd_9FB7
	.4byte 0x9FFD, Cmd_TurnPlayerTo
	.4byte 0xA062, Cmd_A062
	.4byte 0xA0A6, EntityA0A6_Create
	.4byte 0xA133, Cmd_A133
	.4byte 0xA16F, ElevatorManager_Create
	.4byte 0xA1D7, Cmd_A1D7
	.4byte 0xA222, Cmd_ReadSystemDataOrInit
	.4byte 0xA285, Cmd_GetBestFriend
	.4byte 0xA288, EntityA288_Create
	.4byte 0xA2E1, Cmd_Riremito
	.4byte 0xA2E4, Cmd_A2E4
	.4byte 0xA301, Cmd_A301
	.4byte 0xA39F, Cmd_A39F
	.4byte 0xA3AA, Cmd_PlaceOtenkoPanels
	.4byte 0xA3B3, Cmd_A3B3
	.4byte 0xA4FC, Elevator_Create
	.4byte 0xA61C, Cmd_SetLoadingZoneIndicatorMode
	.4byte 0xA628, Cmd_CreateRoomBlind
	.4byte 0xA687, BgPlttDimmer_Create
	.4byte 0xA76D, Cmd_SetEnemyDexDropItemFlag
	.4byte 0xA7CE, Cmd_A7CE
	.4byte 0xA864, Cmd_A864
	.4byte 0xA8F1, WarpMagicSquare_Create @ HashName("ワープ魔方陣")
	.4byte 0xA995, Cmd_ClearMapIconFlags
	.4byte 0xA99F, Cmd_OtenkoGuideIdle
	.4byte 0xAA62, Cmd_SetCoffinMapSpot
	.4byte 0xAA65, CactusManager_Create
	.4byte 0xAB3C, Cmd_SetMessageWindowVar
	.4byte 0xAB41, Cmd_AB41
	.4byte 0xAB4E, EntityAB4E_Create
	.4byte 0xAB8E, Cmd_AB8E
	.4byte 0xAB9C, Cmd_HideOtenkoGuide
	.4byte 0xAC98, Cockatrice_Create @ HashName("コカトリス")
	.4byte 0xACE3, ClockAlarm_Create
	.4byte 0xAD03, Skeleton_Create @ HashName("スケルトン")
	.4byte 0xADB6, Cmd_ADB6
	.4byte 0xADD2, Cmd_EnableMessageWindowAutoAdvance
	.4byte 0xAE3A, Cmd_AE3A
	.4byte 0xAE4E, Cmd_AE4E
	.4byte 0xAE71, Cmd_AE71
	.4byte 0xAEB2, SunRangeWatcher_Create
	.4byte 0xAF33, CrossoverBattle_Create
	.4byte 0xAF43, Cmd_PlayerSwordSwing
	.4byte 0xAF8E, Cmd_CancelEntity4063
	.4byte 0xB005, Cmd_B005
	.4byte 0xB0B4, Cmd_SetEntity5DA5State
	.4byte 0xB0BC, SaveSequence_Create
	.4byte 0xB164, LevelUpper_Create
	.4byte 0xB189, Cmd_B189
	.4byte 0xB1C4, Cmd_ShakeElevator
	.4byte 0xB294, Cmd_B294
	.4byte 0xB3D1, Torture_Create
	.4byte 0xB3D7, Cmd_B3D7 @ HashName("アルバム")
	.4byte 0xB426, DungeonTitle_Create @ HashName("ダンジョンタイトル")
	.4byte 0xB45F, Cmd_GetCrossoverPoint
	.4byte 0xB47E, Cmd_SetEntity3117Priority
	.4byte 0xB4B4, Cmd_CreateBG
	.4byte 0xB50D, Cmd_B50D
	.4byte 0xB55A, Cmd_GetDateTime @ HashName("時間取得")
	.4byte 0xB603, Cmd_ClearAllBadConds
	.4byte 0xB639, ZoneList_Create
	.4byte 0xB683, Cmd_PlayerHammerReady
	.4byte 0xB6CE, Cmd_B6CE
	.4byte 0xB6FF, EntityB6FF_Create
	.4byte 0xB76C, Cmd_B76C
	.4byte 0xB838, Cmd_OtenkoGuideSad
	.4byte 0xB83E, Cmd_B83E
	.4byte 0xB85F, LinkBattleResult_Create
	.4byte 0xB87B, SensorGuide_Create
	.4byte 0xB88C, EntityB88C_Create
	.4byte 0xB8B9, MoverList_Create
	.4byte 0xB8C7, Cmd_SetTileOverrideParams
	.4byte 0xBA36, EntityBA36_Create
	.4byte 0xBA4B, Ringo_Create @ HashName("リンゴ")
	.4byte 0xBB01, Cmd_Retry
	.4byte 0xBB34, Cmd_BB34 @ HashName("おてんこ")
	.4byte 0xBBAA, Cmd_BBAA
	.4byte 0xBD74, BlackHole_Create @ HashName("ブラックホール")
	.4byte 0xBE46, Cmd_BE46
	.4byte 0xBEC2, Cmd_GetMoverPos
	.4byte 0xBEF5, Mimic_Create @ HashName("ミミック")
	.4byte 0xC015, Cmd_LoadCrossoverMappingBuf
	.4byte 0xC0B0, Camera_Create
	.4byte 0xC12A, Cmd_C12A
	.4byte 0xC12D, Cmd_StartPlayerPlttPulse
	.4byte 0xC15E, Cmd_C15E
	.4byte 0xC1F2, Cmd_SleepEnemy
	.4byte 0xC233, Cmd_PlayerSpearSwing
	.4byte 0xC347, Cmd_C347
	.4byte 0xC3BC, Slime_Create @ HashName("スライム")
	.4byte 0xC419, PitfallManager_Create
	.4byte 0xC438, DungeonMarker_Create
	.4byte 0xC46E, Cmd_C46E
	.4byte 0xC556, Cmd_CloseMessageWindow
	.4byte 0xC5D8, Cmd_FreeShadeManCrossoverScriptArg
	.4byte 0xC60F, EntityC60F_Create
	.4byte 0xC673, Cmd_C673
	.4byte 0xC6AA, Cmd_SetHUDMode
	.4byte 0xC765, Cmd_SetEntity3117Pose
	.4byte 0xC783, LinkBattleLobby_Create
	.4byte 0xC7DC, Cmd_C7DC
	.4byte 0xC814, EntityC814_Create
	.4byte 0xC946, PreviewStage_Create
	.4byte 0xC9BC, PropertyCubeManager_Create
	.4byte 0xCA3D, Cmd_CA3D
	.4byte 0xCA73, EnemyDogLink_Create @ HashName("通信ドッグ")
	.4byte 0xCA7D, Cmd_CA7D
	.4byte 0xCAEE, Cmd_CAEE
	.4byte 0xCAFE, Cmd_PlayerSwordReady
	.4byte 0xCB30, Cmd_CB30
	.4byte 0xCBB0, PileDriver_Create @ HashName("パイルドライバー")
	.4byte 0xCC28, MainMenu_Create
	.4byte 0xCCD3, Ghost_Create @ HashName("ゴースト")
	.4byte 0xCCD9, Cmd_RestoreHUDMode
	.4byte 0xCD57, Cmd_SetPlayerForbidFlags
	.4byte 0xCE28, Cmd_CE28
	.4byte 0xCED9, Cmd_CED9
	.4byte 0xCF58, EntityCF58_Create
	.4byte 0xCF79, Title_Create @ HashName("タイトル")
	.4byte 0xCF82, EntityCF82_Create
	.4byte 0xD0C3, Cmd_StopCutscene
	.4byte 0xD0C7, Cmd_FadeOutBGMTemporarily
	.4byte 0xD0CE, Cmd_D0CE
	.4byte 0xD169, Cmd_D169
	.4byte 0xD1C0, Cmd_SetEnemyDexSeenFlag
	.4byte 0xD229, Cmd_D229
	.4byte 0xD24B, Cmd_ReturnCoffinToBag
	.4byte 0xD25F, Cmd_AddEntity5CCCLightArea
	.4byte 0xD285, Cmd_D285
	.4byte 0xD37F, Jormungandr_Create @ HashName("ヨルムンガンド")
	.4byte 0xD3A9, EntityD3A9_Create
	.4byte 0xD401, Cmd_SetMessageWindowPendingLine
	.4byte 0xD40E, Cmd_PlayerGunReady
	.4byte 0xD438, EntityD438_Create
	.4byte 0xD4B5, Cmd_AddForgeExp
	.4byte 0xD4E3, Cmd_AddDoor
	.4byte 0xD53D, CrossoverError_Create
	.4byte 0xD562, Cmd_Nop_D562
	.4byte 0xD6F7, Cmd_D6F7
	.4byte 0xD774, Cmd_D774
	.4byte 0xD7F4, Cmd_StartEntity3117PlttFade
	.4byte 0xD852, ArrowManager_Create
	.4byte 0xD854, EnemyTargetManager_Create
	.4byte 0xD8DF, Cmd_PlayerSpecialDeath
	.4byte 0xD916, Cmd_ReplaceWeapon
	.4byte 0xD935, RfuSession_Create
	.4byte 0xD9AE, MovableBlockManager_Create @ HashName("パス")?
	.4byte 0xD9B7, Cmd_RemoveKaamos
	.4byte 0xD9D3, BgPlttAnimator_Create
	.4byte 0xDA0B, Forge_Create
	.4byte 0xDA19, Cmd_SetWorldMapFlag
	.4byte 0xDA5A, Cmd_GetZoneBounds
	.4byte 0xDAA4, Cmd_GetPrefecture
	.4byte 0xDB6C, Cmd_MoveShadow @ HashName("影位置変更")
	.4byte 0xDC21, SolarStation_Create @ HashName("太陽スタンド")
	.4byte 0xDD0E, Cmd_HasBadCond
	.4byte 0xDD91, Cmd_ConfigureMessageWindow
	.4byte 0xDDCF, Cmd_DDCF
	.4byte 0xDDD0, Cmd_DDD0
	.4byte 0xDDEE, Cmd_PlayerSpearReady
	.4byte 0xDDF8, Cmd_StartRoomBlindFollowCamera
	.4byte 0xDEA2, Cmd_StartEntity3117Scale
	.4byte 0xDED5, Cmd_StartGameOver
	.4byte 0xDF85, Cmd_SaveHUDMode
	.4byte 0xDFAB, Cmd_DFAB
	.4byte 0xDFC6, Marquee_Create
	.4byte 0xE019, Cmd_E019
	.4byte 0xE02A, Cmd_E02A
	.4byte 0xE02E, Warehouse_Create @ HashName("倉庫")
	.4byte 0xE06A, EntityE06A_Create
	.4byte 0xE083, Cmd_UnlockMagic @ HashName("魔法取得")
	.4byte 0xE0A5, Cmd_E0A5
	.4byte 0xE0E1, Cmd_E0E1
	.4byte 0xE131, Bee_Create @ HashName("ビー")
	.4byte 0xE14B, Cmd_SetPlayerPos
	.4byte 0xE1C6, Cmd_E1C6
	.4byte 0xE28B, EntityE28B_Create
	.4byte 0xE435, EntityE435_Create
	.4byte 0xE4A3, Cmd_E4A3
	.4byte 0xE4B1, Cmd_SetBGLayer
	.4byte 0xE534, CutsceneBatSwarm_Create
	.4byte 0xE6CA, Cmd_SoundResume @ HashName("サウンド再開")
	.4byte 0xE6F2, Cmd_E6F2
	.4byte 0xE70E, Cmd_E70E
	.4byte 0xE756, Cmd_E756
	.4byte 0xE77C, Cmd_SetEntity3117Anim
	.4byte 0xE7CA, Cmd_PlayTrackedSound
	.4byte 0xE990, Cmd_DashPlayerTo
	.4byte 0xE9D3, DarkLoans_Create @ HashName("暗黒ローン")
	.4byte 0xE9DA, Cmd_E9DA
	.4byte 0xE9E2, Cmd_E9E2
	.4byte 0xEA00, Cmd_ApplyItemEffect
	.4byte 0xEA96, Cmd_WarpInPlayer
	.4byte 0xEAAC, Cmd_StopPlayTime
	.4byte 0xEAAF, Cmd_GetDoorPos
	.4byte 0xEAB4, Cmd_AddEntity8AF6Entry
	.4byte 0xEB42, Cmd_EB42
	.4byte 0xEBFF, Cmd_HideEntity8AF6
	.4byte 0xEC1F, Cmd_Assert @ HashName("assert")
	.4byte 0xEC2A, EnemyManager_Create
	.4byte 0xEC5B, Cmd_ResumePlayTime
	.4byte 0xEC96, EntityEC96_Create
	.4byte 0xED07, BreakableManager_Create
	.4byte 0xED1F, Cmd_ED1F
	.4byte 0xED2E, Cmd_IsCrossoverUnlocked
	.4byte 0xEDE2, Cmd_HideBG @ HashName("BG非表示")
	.4byte 0xEE18, Cmd_SetBGMTempo
	.4byte 0xEF19, Cmd_DimRoom
	.4byte 0xEF66, EntityEF66_Create
	.4byte 0xEF6F, EntityEF6F_Create
	.4byte 0xEFD1, Cmd_EFD1
	.4byte 0xEFE6, Cmd_HidePlayer
	.4byte 0xF04A, Cmd_CancelGameOver
	.4byte 0xF04B, Cmd_F04B
	.4byte 0xF0CC, Cmd_EnableTileOverrides
	.4byte 0xF11C, Cmd_HasWeapon
	.4byte 0xF156, SolarBarrier_Create @ HashName("太陽結界")
	.4byte 0xF1F9, Cmd_CreateBeeNest @ HashName("蜂の巣")
	.4byte 0xF200, Cmd_F200
	.4byte 0xF33F, Cmd_F33F
	.4byte 0xF341, Cmd_ResetCamera
	.4byte 0xF404, Cmd_ReleaseAllMovableBlocks
	.4byte 0xF41A, EntityF41A_Create
	.4byte 0xF5EB, Player_Create @ HashName("プレイヤー")
	.4byte 0xF661, Cmd_HideEntity3117
	.4byte 0xF836, Dog_Create @ HashName("ドッグ")
	.4byte 0xF8BE, EnemyBat_Create @ HashName("バット")
	.4byte 0xF982, Cmd_F982
	.4byte 0xF993, Cmd_F993
	.4byte 0xF9F1, Cmd_CountFoundArmors
	.4byte 0xFA5D, Cmd_OtenkoGuideSleep
	.4byte 0xFB53, JoyspotManager_Create
	.4byte 0xFB8C, GameOverManager_Create
	.4byte 0xFBC1, Cmd_GetDayDiff @ HashName("日数差取得")
	.4byte 0xFBE5, EntityFBE5_Create
	.4byte 0xFD12, Cmd_FD12
	.4byte 0xFD6B, Cmd_AddEntity778BElem
	.4byte 0xFD86, Cmd_FD86
	.4byte 0xFEBB, Cmd_AddTileOverride
	.4byte 0xFEE0, Cmd_RequestCoffinKill
	.4byte 0xFEF2, Cmd_ResetArmors
	.4byte 0x0000, 0x00000000

@ おそらくこのコマンドテーブルのビルド日時
Timestamp:
  .4byte 1089259575 @ 2004-07-09 18:04:39 UTC
