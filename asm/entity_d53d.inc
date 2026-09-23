	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804e9f4
FUN_0804e9f4: @ 0x0804E9F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl SignalStrengthIcon_Create
	cmp r0, #0
	beq _0804EA08
	adds r0, #0x44
	strh r4, [r0, #0x20]
	strh r5, [r0, #0x22]
_0804EA08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ea10
FUN_0804ea10: @ 0x0804EA10
	ldr r0, _0804EA18 @ =0x030000E8
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0804EA18: .4byte 0x030000E8

	thumb_func_start FUN_0804ea1c
FUN_0804ea1c: @ 0x0804EA1C
	push {lr}
	bl TextPanelManager_DestroyAll
	bl MosaicFader_Stop
	ldr r2, _0804EA54 @ =0x03003E78
	ldr r0, _0804EA58 @ =0xFFFFF9FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	bl Video_ResetFrameState
	ldr r1, _0804EA5C @ =nop_0822e738
	ldr r2, _0804EA60 @ =nop_0822b09c
	ldr r3, _0804EA64 @ =FUN_0822f584
	movs r0, #0
	bl Video_SetDrawPasses
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #0
	bl ClearBGTilemapBuffer
	pop {r0}
	bx r0
	.align 2, 0
_0804EA54: .4byte 0x03003E78
_0804EA58: .4byte 0xFFFFF9FF
_0804EA5C: .4byte nop_0822e738
_0804EA60: .4byte nop_0822b09c
_0804EA64: .4byte FUN_0822f584

	thumb_func_start FUN_0804ea68
FUN_0804ea68: @ 0x0804EA68
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0804EABC @ =0x0000C091
	ldr r1, _0804EAC0 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x24]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804EAC4 @ =0x000092B3
	ldr r1, _0804EAC8 @ =0x0000EFDA
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804EACC @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EABC: .4byte 0x0000C091
_0804EAC0: .4byte 0x0000A413
_0804EAC4: .4byte 0x000092B3
_0804EAC8: .4byte 0x0000EFDA
_0804EACC: .4byte 0x03004250

	thumb_func_start FUN_0804ead0
FUN_0804ead0: @ 0x0804EAD0
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0804EB24 @ =0x0000C091
	ldr r1, _0804EB28 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x24]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804EB2C @ =0x000092B3
	ldr r1, _0804EB30 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804EB34 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EB24: .4byte 0x0000C091
_0804EB28: .4byte 0x0000CD91
_0804EB2C: .4byte 0x000092B3
_0804EB30: .4byte 0x000026BB
_0804EB34: .4byte 0x03004250

	thumb_func_start FUN_0804eb38
FUN_0804eb38: @ 0x0804EB38
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	beq _0804EB46
	movs r0, #0
	strb r0, [r1, #0x19]
_0804EB46:
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start FUN_0804eb50
FUN_0804eb50: @ 0x0804EB50
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #4
	ldr r1, _0804EBC0 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EB6C
	movs r0, #0
	strb r0, [r4, #0x19]
	bl FUN_0804e5bc
_0804EB6C:
	ldr r0, [r4, #0x1c]
	cmp r0, #4
	bne _0804EBB4
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r0, r4, #0
	bl FUN_0804ea1c
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804ea68
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	str r0, [r4, #0x20]
	cmp r0, #0
	blt _0804EBB4
	ldr r1, [r4, #0x28]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x20]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r4, #0x20]
	bl TextPanel_Start
_0804EBB4:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EBC0: .4byte 0x030044BC

	thumb_func_start FUN_0804ebc4
FUN_0804ebc4: @ 0x0804EBC4
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #4
	ldr r1, _0804EC44 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EC22
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r0, r4, #0
	bl FUN_0804ea1c
	bl FUN_0804e5bc
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_0804ead0
	movs r0, #1
	movs r1, #0xe
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	str r0, [r4, #0x20]
	cmp r0, #0
	blt _0804EC1A
	ldr r1, [r4, #0x28]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x20]
	movs r1, #1
	bl TextPanel_SetMessage
	ldr r0, [r4, #0x20]
	bl TextPanel_Start
_0804EC1A:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804EC22:
	ldr r2, [r4, #0x1c]
	cmp r2, #0x3b
	bls _0804EC4C
	ldr r0, _0804EC48 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804EC4C
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x1c]
	b _0804EC50
	.align 2, 0
_0804EC44: .4byte 0x030044BC
_0804EC48: .4byte 0x030044E0
_0804EC4C:
	adds r0, r2, #1
	str r0, [r4, #0x1c]
_0804EC50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ec58
FUN_0804ec58: @ 0x0804EC58
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EC88
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r1, #4
	str r1, [sp]
	ldr r1, _0804ECC8 @ =0x0000FFFF
	str r1, [sp, #4]
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_0804e5e8
_0804EC88:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x14
	bne _0804EC92
	bl FUN_0804e604
_0804EC92:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x13
	bls _0804ECBA
	bl FUN_0804ba3c
	cmp r0, #0
	bne _0804ECBA
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0804ECBA
	ldr r1, _0804ECCC @ =FUN_0822db5c
	ldr r2, _0804ECD0 @ =FUN_0822aaac
	ldr r3, _0804ECD4 @ =MainSprite_DrawList
	movs r0, #0
	bl Video_SetDrawPasses
	ldr r0, [r4, #0x2c]
	movs r1, #0
	bl Script_ExecById
_0804ECBA:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804ECC8: .4byte 0x0000FFFF
_0804ECCC: .4byte FUN_0822db5c
_0804ECD0: .4byte FUN_0822aaac
_0804ECD4: .4byte MainSprite_DrawList

	thumb_func_start EntityD53D_Update
EntityD53D_Update: @ 0x0804ECD8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0x18]
	cmp r5, #0
	bne _0804ECFA
	bl FUN_0804e59c
	cmp r0, #1
	bne _0804ECEE
	strb r0, [r4, #0x18]
	b _0804ECF6
_0804ECEE:
	cmp r0, #2
	bne _0804ECFA
	strb r0, [r4, #0x18]
	movs r0, #1
_0804ECF6:
	strb r0, [r4, #0x19]
	str r5, [r4, #0x1c]
_0804ECFA:
	ldr r0, _0804ED14 @ =0x085AB664
	ldrb r1, [r4, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804ED14: .4byte 0x085AB664

	thumb_func_start EntityD53D_Destroy
EntityD53D_Destroy: @ 0x0804ED18
	push {lr}
	ldr r0, [r0, #0x20]
	bl TextPanel_Destroy
	ldr r1, _0804ED2C @ =0x030000E8
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0804ED2C: .4byte 0x030000E8

	thumb_func_start EntityD53D_Init
EntityD53D_Init: @ 0x0804ED30
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804ED58 @ =0x030000E8
	str r4, [r0]
	bl MosaicFader_Stop
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804ED50
	bl FUN_0823d340
	str r0, [r4, #0x28]
	cmp r0, #0
	bne _0804ED5C
_0804ED50:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804ED78
	.align 2, 0
_0804ED58: .4byte 0x030000E8
_0804ED5C:
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x2c]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x20]
	movs r1, #0
	strb r1, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x1c]
	movs r0, #0
_0804ED78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityD53D_Create
EntityD53D_Create: @ 0x0804ED80
	push {r4, lr}
	bl FUN_0804ea10
	adds r4, r0, #0
	cmp r4, #0
	bne _0804EDC2
	movs r0, #0xc
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804EDC0
	ldr r1, _0804EDB8 @ =EntityD53D_Update
	ldr r2, _0804EDBC @ =EntityD53D_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityD53D_Init
	cmp r0, #0
	bge _0804EDC0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804EDC2
	.align 2, 0
_0804EDB8: .4byte EntityD53D_Update
_0804EDBC: .4byte EntityD53D_Destroy
_0804EDC0:
	adds r0, r4, #0
_0804EDC2:
	pop {r4}
	pop {r1}
	bx r1

