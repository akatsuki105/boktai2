	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _080186EC @ =0x03000084
	str r6, [r0]
	ldr r0, _080186F0 @ =0x0000EA77
	bl GetTilemapFile
	adds r5, r0, #0
	movs r0, #1
	bl GetTilemapBuffer
	adds r1, r0, #0
	movs r4, #0
	str r4, [r6, #0x34]
	str r4, [r6, #0x3c]
	str r4, [r6, #0x38]
	str r4, [r6, #0x40]
	str r4, [r6, #0x50]
	ldrb r0, [r5]
	cmp r0, #0x4d
	bne _080186F4
	ldrb r0, [r5, #1]
	cmp r0, #0x50
	bne _080186F4
	str r4, [sp, #0x10]
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl Video_SetupBGLayout
	b _0801870A
	.align 2, 0
_080186EC: .4byte 0x03000084
_080186F0: .4byte 0x0000EA77
_080186F4:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl Video_SetupBG
_0801870A:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08018720
	bl Script_GetValue
	strh r0, [r6, #0x30]
	bl Script_GetValue
	b _08018724
_08018720:
	movs r0, #0x40
	strh r0, [r6, #0x30]
_08018724:
	strh r0, [r6, #0x32]
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801873C
	bl Script_GetValue
	strh r0, [r6, #0x28]
	bl Script_GetValue
	b _08018746
_0801873C:
	movs r0, #0xe1
	lsls r0, r0, #5
	strh r0, [r6, #0x28]
	movs r0, #0xe1
	lsls r0, r0, #4
_08018746:
	strh r0, [r6, #0x2a]
	ldr r4, _080187AC @ =0x03000080
	ldrh r1, [r6, #0x28]
	ldr r0, [r4]
	cmp r0, r1
	ble _0801877A
	str r1, [r4]
	ldrh r0, [r6, #0x2a]
	cmp r0, #0
	beq _0801877A
	ldr r2, _080187B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080187B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080187B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x2a]
	bl Mod
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r4]
_0801877A:
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08018794
	bl Script_GetValue
	ldr r1, _080187BC @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
_08018794:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080187C0
	bl Script_GetValue
	strh r0, [r6, #0x2c]
	bl Script_GetValue
	b _080187C6
	.align 2, 0
_080187AC: .4byte 0x03000080
_080187B0: .4byte 0x030046B8
_080187B4: .4byte 0x000003FF
_080187B8: .4byte 0x0203B400
_080187BC: .4byte 0x030046A0
_080187C0:
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r6, #0x2c]
_080187C6:
	strh r0, [r6, #0x2e]
	adds r0, r6, #0
	bl WeatherManager_ResetTimer
	movs r0, #0x61
	movs r1, #1
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r3, _08018828 @ =0x030046A0
	ldr r2, [r3]
	ldr r4, _0801882C @ =0x00000942
	adds r0, r2, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xb4
	lsls r4, r4, #2
	adds r2, r2, r4
	asrs r1, r1, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r3]
	adds r2, r0, r4
	ldr r0, _08018830 @ =0x03000074
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	blt _08018806
	str r0, [r2]
_08018806:
	movs r5, #0
	ldr r2, [r3]
	ldr r1, _0801882C @ =0x00000942
	adds r0, r2, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08018864
	ldr r1, _08018834 @ =0x03000080
	ldr r0, [r1]
	cmp r0, #0
	ble _08018838
	cmp r0, #0x63
	bgt _08018862
	movs r0, #0x64
	str r0, [r1]
	b _08018862
	.align 2, 0
_08018828: .4byte 0x030046A0
_0801882C: .4byte 0x00000942
_08018830: .4byte 0x03000074
_08018834: .4byte 0x03000080
_08018838:
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, #0
	bne _08018864
	adds r0, r6, #0
	bl WeatherManager_GetChance
	ldr r3, _080188D8 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _080188DC @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _080188E0 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0x3f
	ands r1, r2
	cmp r1, r0
	bge _08018864
_08018862:
	movs r5, #3
_08018864:
	movs r0, #0x6d
	adds r1, r5, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl WeatherManager_SetState
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r6, #0x54]
	movs r0, #0x4f
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r6, #0x58]
	ldr r4, _080188E0 @ =0x0203B400
	ldr r5, _080188D8 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080188DC @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x7f
	ands r0, r2
	adds r0, #0x80
	str r0, [r6, #0x4c]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	subs r0, #4
	str r0, [r6, #0x44]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	ands r0, r2
	subs r0, #4
	str r0, [r6, #0x48]
	adds r0, r6, #0
	bl WeatherManager_InitParticles
	movs r0, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080188D8: .4byte 0x030046B8
_080188DC: .4byte 0x000003FF
_080188E0: .4byte 0x0203B400
