	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c1b08
FUN_080c1b08: @ 0x080C1B08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x98
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	adds r0, r5, #0
	adds r0, #0xf8
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r0, _080C1B40 @ =0x0000021E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1B40: .4byte 0x0000021E

	thumb_func_start FUN_080c1b44
FUN_080c1b44: @ 0x080C1B44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080C1B74 @ =0x0000021E
	adds r6, r7, r0
	ldrh r0, [r6]
	cmp r0, #0x1d
	bhi _080C1B7C
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C1B78 @ =0x0000FFE2
	b _080C1CDE
	.align 2, 0
_080C1B74: .4byte 0x0000021E
_080C1B78: .4byte 0x0000FFE2
_080C1B7C:
	cmp r0, #0x2c
	bhi _080C1BA4
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	ldrh r0, [r6]
	lsls r0, r0, #1
	subs r0, #0x5a
	adds r3, r7, #0
	adds r3, #0xba
	strh r0, [r3]
	b _080C1CE0
_080C1BA4:
	cmp r0, #0x31
	bhi _080C1BF4
	ldr r0, _080C1BE8 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1BEC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1BF0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r2, [r6]
	movs r1, #0x2d
	subs r1, r1, r2
	b _080C1C34
	.align 2, 0
_080C1BE8: .4byte 0x0203B400
_080C1BEC: .4byte 0x030046B8
_080C1BF0: .4byte 0x000003FF
_080C1BF4:
	cmp r0, #0x36
	bhi _080C1C50
	ldr r0, _080C1C44 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C48 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C4C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x37
_080C1C34:
	lsls r1, r1, #1
	adds r1, r1, r0
	subs r1, #2
	adds r3, r7, #0
	adds r3, #0xba
	strh r1, [r3]
	b _080C1D56
	.align 2, 0
_080C1C44: .4byte 0x0203B400
_080C1C48: .4byte 0x030046B8
_080C1C4C: .4byte 0x000003FF
_080C1C50:
	cmp r0, #0x3b
	bhi _080C1C9C
	ldr r0, _080C1C90 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C94 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C98 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	subs r0, #2
	b _080C1CDA
	.align 2, 0
_080C1C90: .4byte 0x0203B400
_080C1C94: .4byte 0x030046B8
_080C1C98: .4byte 0x000003FF
_080C1C9C:
	cmp r0, #0x4f
	bhi _080C1CFC
	ldr r0, _080C1CF0 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1CF4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1CF8 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r0, #0x3b
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	subs r0, #1
_080C1CDA:
	adds r1, r7, #0
	adds r1, #0xba
_080C1CDE:
	strh r0, [r1]
_080C1CE0:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080C1D56
	.align 2, 0
_080C1CF0: .4byte 0x0203B400
_080C1CF4: .4byte 0x030046B8
_080C1CF8: .4byte 0x000003FF
_080C1CFC:
	cmp r0, #0x59
	bhi _080C1D10
	adds r0, r7, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	b _080C1D56
_080C1D10:
	ldrh r0, [r6]
	movs r1, #0x2d
	bl Div
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C1D3C
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _080C1D56
_080C1D3C:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_080C1D56:
	ldr r0, _080C1D6C @ =0x0000021E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1D6C: .4byte 0x0000021E

	thumb_func_start EntityB87B_Update
EntityB87B_Update: @ 0x080C1D70
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _080C1D86
	bl _call_via_r1
_080C1D86:
	ldr r3, _080C1DD8 @ =0x0000022E
	adds r6, r5, r3
	ldrh r1, [r6]
	adds r4, r1, #0
	cmp r4, #0
	beq _080C1DE0
	adds r1, #1
	strh r1, [r6]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x10
	bhi _080C1DA0
	b _080C1F2C
_080C1DA0:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C1DCE
	ldr r1, _080C1DDC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	add r3, sp, #0xc
	str r3, [r1, #4]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	bl VM_ExecByID
_080C1DCE:
	adds r0, r5, #0
	bl KillEntity
	b _080C1F2C
	.align 2, 0
_080C1DD8: .4byte 0x0000022E
_080C1DDC: .4byte 0xFFFF0000
_080C1DE0:
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1E2C @ =0x00000226
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	bne _080C1E34
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	adds r3, #4
	adds r1, r5, r3
	ldrh r1, [r1]
	subs r1, #0x10
	cmp r2, r1
	bne _080C1E34
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E30 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r4, [r1]
	movs r1, #1
	strh r1, [r6]
	b _080C1F14
	.align 2, 0
_080C1E2C: .4byte 0x00000226
_080C1E30: .4byte 0x0000FFFF
_080C1E34:
	movs r3, #0x88
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	cmp r1, #0x10
	bls _080C1E84
	ldr r1, _080C1E78 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r1, #9
	ands r1, r2
	cmp r1, #0
	beq _080C1E84
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E7C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #1
	strh r2, [r1]
	ldr r3, _080C1E80 @ =0x0000022E
	adds r1, r5, r3
	strh r2, [r1]
	b _080C1F14
	.align 2, 0
_080C1E78: .4byte 0x030044E0
_080C1E7C: .4byte 0x0000FFFF
_080C1E80: .4byte 0x0000022E
_080C1E84:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1EE0 @ =0x0000022A
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	blo _080C1F14
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0
	strh r1, [r0]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r6, [r0]
	cmp r6, #1
	bne _080C1EE4
	adds r0, r5, #0
	adds r0, #0xf8
	adds r4, r5, #0
	adds r4, #0x18
	str r2, [sp]
	adds r1, r4, #0
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _080C1EF8
	.align 2, 0
_080C1EE0: .4byte 0x0000022A
_080C1EE4:
	cmp r6, #3
	bne _080C1EF8
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, _080C1F34 @ =FUN_080c1b44
	str r1, [r0]
	ldr r1, _080C1F38 @ =0x0000021E
	adds r0, r5, r1
	strh r2, [r0]
_080C1EF8:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	bl TextBox_SetInstant
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	bl TextBox_ShowLine
_080C1F14:
	movs r1, #0x88
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
_080C1F2C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C1F34: .4byte FUN_080c1b44
_080C1F38: .4byte 0x0000021E

	thumb_func_start EntityB87B_Destroy
EntityB87B_Destroy: @ 0x080C1F3C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x38
	movs r5, #4
_080C1F44:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080C1F44
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1f5c
FUN_080c1f5c: @ 0x080C1F5C
	push {lr}
	ldr r0, _080C1F80 @ =0x03003ED0
	ldr r1, [r0, #0x2c]
	movs r0, #0
	ldr r2, _080C1F84 @ =0x0000F001
	adds r3, r2, #0
_080C1F68:
	adds r2, r0, #1
	movs r0, #0x1f
_080C1F6C:
	strh r3, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _080C1F6C
	adds r0, r2, #0
	cmp r0, #0x1f
	ble _080C1F68
	pop {r0}
	bx r0
	.align 2, 0
_080C1F80: .4byte 0x03003ED0
_080C1F84: .4byte 0x0000F001

	thumb_func_start FUN_080c1f88
FUN_080c1f88: @ 0x080C1F88
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C1FA8
	ldr r1, _080C1FA0 @ =0x0000CFE1
	ldr r7, _080C1FA4 @ =0x0000ACBD
	movs r6, #0
	b _080C1FAE
	.align 2, 0
_080C1FA0: .4byte 0x0000CFE1
_080C1FA4: .4byte 0x0000ACBD
_080C1FA8:
	ldr r1, _080C2020 @ =0x0000A413
	ldr r7, _080C2024 @ =0x0000EFDA
	movs r6, #0xc
_080C1FAE:
	ldr r0, _080C2028 @ =0x0000C091
	bl GetFile
	adds r5, r0, #0
	movs r4, #0
	str r4, [sp, #0xc]
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Video_SetBGLayer
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _080C202C @ =0x000092B3
	adds r1, r7, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r1, #0xd
	ldr r5, _080C2030 @ =0x03004250
_080C1FFA:
	lsls r0, r1, #5
	adds r4, r1, #1
	adds r1, r0, r5
	movs r2, #0xf
_080C2002:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080C2002
	adds r1, r4, #0
	cmp r1, #0xf
	ble _080C1FFA
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2020: .4byte 0x0000A413
_080C2024: .4byte 0x0000EFDA
_080C2028: .4byte 0x0000C091
_080C202C: .4byte 0x000092B3
_080C2030: .4byte 0x03004250

	thumb_func_start FUN_080c2034
FUN_080c2034: @ 0x080C2034
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C20F0 @ =0x0000CB05
	ldr r1, _080C20F4 @ =0x0000DF11
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x18
	adds r0, r6, #0
	bl OpenMainSpriteFile
	ldr r1, _080C20F8 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x38
	str r4, [sp]
	str r4, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xf
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0x98
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x30
	bl MainSprite_Add
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #0x30
	bl MainSprite_Add
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C20F0: .4byte 0x0000CB05
_080C20F4: .4byte 0x0000DF11
_080C20F8: .4byte 0xFFFF0000

	thumb_func_start FUN_080c20fc
FUN_080c20fc: @ 0x080C20FC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, [r7, #0x40]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _080C21DC
	lsls r0, r0, #2
	ldr r1, _080C2124 @ =_080C2128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C2124: .4byte _080C2128
_080C2128: @ jump table
	.4byte _080C2160 @ case 0
	.4byte _080C216A @ case 1
	.4byte _080C2176 @ case 2
	.4byte _080C2182 @ case 3
	.4byte _080C2182 @ case 4
	.4byte _080C218E @ case 5
	.4byte _080C219A @ case 6
	.4byte _080C21A6 @ case 7
	.4byte _080C21A6 @ case 8
	.4byte _080C21B2 @ case 9
	.4byte _080C21B2 @ case 10
	.4byte _080C21B2 @ case 11
	.4byte _080C21BE @ case 12
	.4byte _080C21CA @ case 13
_080C2160:
	ldr r0, [r7, #0x40]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x40]
	b _080C21E2
_080C216A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0xf
	b _080C21D4
_080C2176:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x10
	b _080C21D4
_080C2182:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x11
	b _080C21D4
_080C218E:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x12
	b _080C21D4
_080C219A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x13
	b _080C21D4
_080C21A6:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x14
	b _080C21D4
_080C21B2:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x15
	b _080C21D4
_080C21BE:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x16
	b _080C21D4
_080C21CA:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x17
_080C21D4:
	movs r3, #1
	bl MainSprite_SetPose
	b _080C21E2
_080C21DC:
	movs r0, #1
	orrs r1, r0
	str r1, [r7, #0x40]
_080C21E2:
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc
	bls _080C21F0
	b _080C24BC
_080C21F0:
	lsls r0, r0, #2
	ldr r1, _080C21FC @ =_080C2200
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C21FC: .4byte _080C2200
_080C2200: @ jump table
	.4byte _080C2234 @ case 0
	.4byte _080C22B0 @ case 1
	.4byte _080C23B4 @ case 2
	.4byte _080C2430 @ case 3
	.4byte _080C2338 @ case 4
	.4byte _080C24BC @ case 5
	.4byte _080C24BC @ case 6
	.4byte _080C24BC @ case 7
	.4byte _080C24BC @ case 8
	.4byte _080C23B4 @ case 9
	.4byte _080C24BC @ case 10
	.4byte _080C24BC @ case 11
	.4byte _080C2338 @ case 12
_080C2234:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C22AC @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C22AC: .4byte FUN_080c1b08
_080C22B0:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C2334 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C2334: .4byte FUN_080c1b08
_080C2338:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C23B0 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C23B0: .4byte FUN_080c1b08
_080C23B4:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C242C @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C242C: .4byte FUN_080c1b08
_080C2430:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x98
	adds r5, r7, #0
	adds r5, #0x18
	movs r6, #0
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C24B4 @ =0x0000FFE2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _080C24B8 @ =0x0000FFBF
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x28
	strh r0, [r1]
	subs r2, #0x18
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [r0]
	b _080C24FA
	.align 2, 0
_080C24B4: .4byte 0x0000FFE2
_080C24B8: .4byte 0x0000FFBF
_080C24BC:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_080c1f5c
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
_080C24F8:
	str r0, [r1]
_080C24FA:
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c250c
FUN_080c250c: @ 0x080C250C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C252C
	movs r2, #0x89
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _080C2580
_080C252C:
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25B2
	bl FUN_0823d340
	movs r1, #0x86
	lsls r1, r1, #2
	adds r6, r5, r1
	str r0, [r6]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25B2
	bl VM_GetValue
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r5, r2
	strh r0, [r4]
	bl VM_GetValue
	ldrh r1, [r4]
	adds r1, r1, r0
	subs r1, #1
	ldr r2, _080C2594 @ =0x00000226
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080C2598 @ =0x0000EFDA
	bl TextBox_SetBgPltt
	ldr r0, [r6]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	ldrh r0, [r4]
	bl TextBox_ShowLine
_080C2580:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25A0
	bl VM_GetValue
	ldr r2, _080C259C @ =0x0000022A
	adds r1, r5, r2
	b _080C25A6
	.align 2, 0
_080C2594: .4byte 0x00000226
_080C2598: .4byte 0x0000EFDA
_080C259C: .4byte 0x0000022A
_080C25A0:
	ldr r0, _080C25B8 @ =0x0000022A
	adds r1, r5, r0
	movs r0, #0x3c
_080C25A6:
	strh r0, [r1]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
_080C25B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C25B8: .4byte 0x0000022A

	thumb_func_start EntityB87B_Init
EntityB87B_Init: @ 0x080C25BC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25DC
	bl VM_GetValue
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _080C25E4
_080C25DC:
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_080C25E4:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25FE
	bl VM_GetValue
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _080C2606
_080C25FE:
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
_080C2606:
	adds r0, r4, #0
	bl FUN_080c1f88
	adds r0, r4, #0
	bl FUN_080c2034
	adds r0, r4, #0
	bl FUN_080c20fc
	adds r0, r4, #0
	bl FUN_080c250c
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C263C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C263C: .4byte 0x0000FFFF

	thumb_func_start EntityB87B_Create
EntityB87B_Create: @ 0x080C2640
	push {r4, lr}
	movs r1, #0x8e
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C2678
	ldr r1, _080C2670 @ =EntityB87B_Update
	ldr r2, _080C2674 @ =EntityB87B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB87B_Init
	cmp r0, #0
	bge _080C2678
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C267A
	.align 2, 0
_080C2670: .4byte EntityB87B_Update
_080C2674: .4byte EntityB87B_Destroy
_080C2678:
	adds r0, r4, #0
_080C267A:
	pop {r4}
	pop {r1}
	bx r1

