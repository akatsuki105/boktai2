	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080acdf8
FUN_080acdf8: @ 0x080ACDF8
	push {r4, r5, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0x48
	adds r0, #0x50
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	ldr r3, _080ACE88 @ =0x00000FFF
	adds r2, r3, #0
	ands r0, r2
	strh r0, [r1]
	mov r3, ip
	adds r3, #0x4a
	mov r0, ip
	adds r0, #0x52
	ldrh r0, [r0]
	ldrh r4, [r3]
	adds r0, r0, r4
	ands r0, r2
	strh r0, [r3]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	mov r1, ip
	strh r0, [r1, #0x1c]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r1, #0x1e]
	adds r1, #0x5c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #3
	ands r0, r1
	mov r2, ip
	strh r0, [r2, #0x10]
	mov r1, ip
	adds r1, #0x5e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080ACF44
	ldr r2, _080ACE8C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080ACE90 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080ACE94 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r3, r0, #0
	subs r3, #0xf
	adds r5, r2, #0
	cmp r3, #0
	ble _080ACE98
	mov r4, ip
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
	b _080ACEA6
	.align 2, 0
_080ACE88: .4byte 0x00000FFF
_080ACE8C: .4byte 0x030046B8
_080ACE90: .4byte 0x000003FF
_080ACE94: .4byte 0x0203B400
_080ACE98:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080ACEA6:
	mov r0, ip
	adds r0, #0x60
	ldrh r0, [r0]
	adds r3, r3, r0
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080ACEEC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r4, _080ACEF0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r2, ip
	adds r2, #0x62
	asrs r0, r0, #3
	movs r1, #0xf
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r4, r0, #7
	ldr r2, _080ACEF4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080ACEF8
	asrs r1, r0, #0xc
	b _080ACEFE
	.align 2, 0
_080ACEEC: .4byte 0x000003FF
_080ACEF0: .4byte 0x0203B400
_080ACEF4: .4byte 0x085B0A08
_080ACEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ACEFE:
	mov r0, ip
	adds r0, #0x50
	strh r1, [r0]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080ACF1A
	asrs r0, r0, #0xc
	b _080ACF20
_080ACF1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080ACF20:
	mov r1, ip
	adds r1, #0x52
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080ACF4C @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _080ACF50 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	mov r1, ip
	adds r1, #0x5e
	strh r0, [r1]
_080ACF44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACF4C: .4byte 0x000003FF
_080ACF50: .4byte 0x0203B400

	thumb_func_start Entity5292_Update
Entity5292_Update: @ 0x080ACF54
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x2c
	movs r5, #0xf
_080ACF5C:
	adds r0, r4, #0
	bl FUN_080acdf8
	adds r4, #0x64
	subs r5, #1
	cmp r5, #0
	bge _080ACF5C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity5292_Destroy
Entity5292_Destroy: @ 0x080ACF74
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x2c
	movs r5, #0xf
_080ACF7C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x64
	subs r5, #1
	cmp r5, #0
	bge _080ACF7C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080acf94
FUN_080acf94: @ 0x080ACF94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	movs r0, #0
	mov sl, r0
	ldr r1, _080AD084 @ =0x0203B400
	mov r8, r1
	ldr r6, _080AD088 @ =0x030046B8
	ldr r7, _080AD08C @ =0x000003FF
_080ACFAC:
	movs r0, #0x64
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, #0x2c
	mov r3, sb
	adds r5, r3, r0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _080AD090 @ =0x0000CC88
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r5]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r5]
	movs r0, #1
	strb r0, [r5, #7]
	mov r0, sb
	ldrh r1, [r0, #0x26]
	adds r0, r5, #0
	adds r0, #0x60
	strh r1, [r0]
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r2, #0xf
	ands r0, r2
	adds r0, #0x10
	adds r2, r5, #0
	adds r2, #0x62
	strh r0, [r2]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r3, _080AD094 @ =0x00000FFF
	ands r0, r3
	subs r2, #0x1a
	strh r0, [r2]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	ands r0, r3
	adds r3, r5, #0
	adds r3, #0x4a
	strh r0, [r3]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r5, #0x1c]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r5, #0x1e]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x5c
	strh r0, [r1]
	lsrs r0, r0, #2
	strh r0, [r5, #0x10]
	mov r2, sb
	ldrh r1, [r2, #0x2a]
	ldr r3, _080AD098 @ =0x000001D3
	adds r1, r1, r3
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [r6]
	adds r0, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r3, r0, #0
	subs r3, #0xf
	cmp r3, #0
	ble _080AD09C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080AD0A4
	.align 2, 0
_080AD084: .4byte 0x0203B400
_080AD088: .4byte 0x030046B8
_080AD08C: .4byte 0x000003FF
_080AD090: .4byte 0x0000CC88
_080AD094: .4byte 0x00000FFF
_080AD098: .4byte 0x000001D3
_080AD09C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080AD0A4:
	str r0, [r5]
	adds r0, r5, #0
	adds r0, #0x60
	ldrh r0, [r0]
	adds r3, r3, r0
	ldr r0, [r6]
	adds r0, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AD0E8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r2, r5, #0
	adds r2, #0x62
	asrs r1, r1, #3
	movs r0, #3
	ands r1, r0
	ldrh r2, [r2]
	adds r4, r1, r2
	ldr r2, _080AD0EC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AD0F0
	asrs r1, r0, #0xc
	b _080AD0F6
	.align 2, 0
_080AD0E8: .4byte 0x0203B400
_080AD0EC: .4byte 0x085B0A08
_080AD0F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AD0F6:
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AD112
	asrs r0, r0, #0xc
	b _080AD118
_080AD112:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AD118:
	adds r3, r5, #0
	adds r3, #0x52
	strh r0, [r3]
	ldr r0, [r6]
	adds r0, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _080AD154 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	adds r1, r5, #0
	adds r1, #0x5e
	strh r0, [r1]
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #0xf
	bgt _080AD146
	b _080ACFAC
_080AD146:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD154: .4byte 0x0203B400

	thumb_func_start Entity5292_Init
Entity5292_Init: @ 0x080AD158
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x60
	strh r0, [r4, #0x26]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AD170
	bl Script_GetValue
	b _080AD172
_080AD170:
	movs r0, #6
_080AD172:
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	bl FUN_080acf94
	ldr r2, _080AD19C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AD1A0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AD1A4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r4, #0x24]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD19C: .4byte 0x030046B8
_080AD1A0: .4byte 0x000003FF
_080AD1A4: .4byte 0x0203B400

	thumb_func_start Entity5292_Create
Entity5292_Create: @ 0x080AD1A8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080AD1D8 @ =0x0000066C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AD1E4
	strh r5, [r4, #0x18]
	ldr r1, _080AD1DC @ =Entity5292_Update
	ldr r2, _080AD1E0 @ =Entity5292_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity5292_Init
	cmp r0, #0
	bge _080AD1E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AD1E6
	.align 2, 0
_080AD1D8: .4byte 0x0000066C
_080AD1DC: .4byte Entity5292_Update
_080AD1E0: .4byte Entity5292_Destroy
_080AD1E4:
	adds r0, r4, #0
_080AD1E6:
	pop {r4, r5}
	pop {r1}
	bx r1
