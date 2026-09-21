	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08007f00
FUN_08007f00: @ 0x08007F00
	push {lr}
	ldr r1, [r0, #0x1c]
	movs r2, #0
	ldr r0, [r0, #0x18]
	cmp r2, r0
	bhs _08007F20
	adds r3, r0, #0
_08007F0E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08007F18
	adds r0, r1, #0
	b _08007F22
_08007F18:
	adds r2, #1
	adds r1, #0xe8
	cmp r2, r3
	blo _08007F0E
_08007F20:
	movs r0, #0
_08007F22:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007f28
FUN_08007f28: @ 0x08007F28
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	movs r1, #1
	strb r1, [r0, #4]
	bx lr

	thumb_func_start FUN_08007f34
FUN_08007f34: @ 0x08007F34
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _08007F42
	movs r0, #0
	b _08007F48
_08007F42:
	movs r0, #0
	strb r0, [r1, #4]
	movs r0, #1
_08007F48:
	pop {r1}
	bx r1

	thumb_func_start FUN_08007f4c
FUN_08007f4c: @ 0x08007F4C
	push {lr}
	adds r3, r2, #0
	ldrb r1, [r2, #2]
	cmp r1, #1
	bne _08007F6A
	movs r1, #4
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r2, #0
	movs r1, #3
	bl FUN_08007f28
	b _08007F80
_08007F6A:
	cmp r1, #2
	bne _08007F80
	movs r1, #8
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r3, #0
	movs r1, #4
	bl FUN_08007f28
_08007F80:
	pop {r0}
	bx r0

	thumb_func_start FUN_08007f84
FUN_08007f84: @ 0x08007F84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0xe4
	adds r0, r0, r7
	mov sb, r0
	adds r4, #0x20
	str r4, [r0]
	add r5, sp, #0x14
	movs r0, #0
	mov r8, r0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0800804C @ =0x05000002
	bl CpuSet
	adds r6, r7, #0
	adds r6, #0x34
	movs r0, #2
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_Setup
	mov r0, sb
	ldr r1, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r5, r7, #0
	adds r5, #0x94
	ldr r2, _08008050 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08008054 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r4, sp, #0x1c
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	str r1, [sp, #0x24]
	add r3, sp, #0x24
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r7, #0x10]
	ldr r2, _08008058 @ =0x00004001
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0800805C @ =FUN_08007f4c
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800804C: .4byte 0x05000002
_08008050: .4byte 0xFFFF0000
_08008054: .4byte 0x0000FFFF
_08008058: .4byte 0x00004001
_0800805C: .4byte FUN_08007f4c

	thumb_func_start FUN_08008060
FUN_08008060: @ 0x08008060
	push {lr}
	sub sp, #0x14
	adds r2, r0, #0
	ldrh r0, [r2, #0x12]
	cmp r0, #0
	beq _0800809E
	ldrh r0, [r2, #0x10]
	str r0, [sp]
	ldrb r0, [r2, #2]
	cmp r0, #3
	bne _0800807A
	movs r0, #1
	b _08008080
_0800807A:
	cmp r0, #4
	bne _08008082
	movs r0, #0
_08008080:
	str r0, [sp, #4]
_08008082:
	ldr r0, [r2, #0x1c]
	str r0, [sp, #8]
	ldr r1, _080080A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2, #0x12]
	bl Script_ExecById
_0800809E:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_080080A4: .4byte 0xFFFF0000

	thumb_func_start FUN_080080a8
FUN_080080a8: @ 0x080080A8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080080ac
FUN_080080ac: @ 0x080080AC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _080080EE
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _080080F8 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _080080FC @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl MainSprite_SetPlttID
_080080EE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080080F8: .4byte 0x085AA670
_080080FC: .4byte 0x085AA678

	thumb_func_start FUN_08008100
FUN_08008100: @ 0x08008100
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _08008142
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _08008164 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _08008168 @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl MainSprite_SetPlttID
_08008142:
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _0800815A
	adds r1, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, r1
	blt _0800815A
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08007f28
_0800815A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08008164: .4byte 0x085AA670
_08008168: .4byte 0x085AA678

	thumb_func_start FUN_0800816c
FUN_0800816c: @ 0x0800816C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _080081BE
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _080081D4 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _080081D8 @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl MainSprite_SetPlttID
	movs r0, #0xa
	strb r0, [r5, #5]
	ldr r0, _080081DC @ =0x0000014B
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08008060
_080081BE:
	ldr r0, [r5, #0xc]
	cmp r0, #0xa
	ble _080081CC
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08007f28
_080081CC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080081D4: .4byte 0x085AA670
_080081D8: .4byte 0x085AA678
_080081DC: .4byte 0x0000014B

	thumb_func_start FUN_080081e0
FUN_080081e0: @ 0x080081E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r1, #0
	adds r0, r7, #0
	bl FUN_08007f34
	cmp r0, #0
	bne _080081FA
	b _080082FE
_080081FA:
	adds r5, r7, #0
	adds r5, #0x34
	adds r0, r7, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _0800831C @ =0x085AA670
	ldr r0, [r7, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _08008320 @ =0x085AA678
	ldr r0, [r7, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r5, #0
	bl MainSprite_SetPlttID
	movs r0, #0xa
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl FUN_08008060
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	adds r6, r7, #0
	adds r6, #0x54
	ldr r2, _08008324 @ =0xFFFF0000
	movs r0, #0x56
	adds r0, r0, r7
	mov sl, r0
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r1, r3, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldrh r0, [r6]
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x58
	adds r1, r1, r7
	mov sb, r1
	ldrh r1, [r1]
	add r5, sp, #0x1c
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r3, #4
	str r3, [sp, #0x10]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	subs r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	adds r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	adds r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	subs r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
_080082FE:
	ldr r0, [r7, #0xc]
	cmp r0, #0xa
	ble _0800830C
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08007f28
_0800830C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800831C: .4byte 0x085AA670
_08008320: .4byte 0x085AA678
_08008324: .4byte 0xFFFF0000
_08008328: .4byte 0x00002001

	thumb_func_start FUN_0800832c
FUN_0800832c: @ 0x0800832C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x28
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	beq _08008342
	subs r0, #1
	strh r0, [r4, #0xa]
	b _08008388
_08008342:
	adds r6, r4, #0
	adds r6, #0x54
	add r7, sp, #0x10
	ldrh r0, [r4, #0x26]
	str r0, [sp]
	str r0, [sp, #4]
	ldrh r0, [r4, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	add r3, sp, #0xc
	bl FUN_08234e78
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08008374
	adds r0, r5, #0
	bl FUN_08234e3c
	ldr r0, [r5, #8]
	ldrh r1, [r0, #4]
	ldr r0, _08008390 @ =0x00000FFF
	ands r0, r1
	strh r0, [r4, #0xa]
_08008374:
	ldrh r0, [r7]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r7, #4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08008388:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008390: .4byte 0x00000FFF

	thumb_func_start FUN_08008394
FUN_08008394: @ 0x08008394
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x20]
	cmp r3, #0
	beq _080083B8
	ldrh r1, [r3]
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r2, #6]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x58
	strh r1, [r0]
_080083B8:
	pop {r0}
	bx r0

	thumb_func_start Entity2D2B_Update
Entity2D2B_Update: @ 0x080083BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x1c]
	movs r1, #0
	mov r8, r1
	ldr r1, [r7, #0x18]
	cmp r8, r1
	bhs _080084AC
	adds r6, r4, #0
	adds r6, #0x94
_080083D4:
	ldrb r1, [r4]
	adds r5, r4, #0
	adds r5, #0x9a
	cmp r1, #0
	beq _0800849E
	ldr r2, [r4, #0x14]
	cmp r2, #0
	blt _08008414
	ldr r1, _080083F8 @ =0x030046A0
	ldr r1, [r1]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r1, r3
	ldr r1, [r1]
	cmp r1, r2
	bne _080083FC
	movs r1, #1
	b _080083FE
	.align 2, 0
_080083F8: .4byte 0x030046A0
_080083FC:
	movs r1, #0
_080083FE:
	cmp r1, #0
	bne _08008414
	ldr r1, [r4, #0x3c]
	movs r2, #1
	orrs r1, r2
	str r1, [r4, #0x3c]
	ldrh r2, [r6, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r6, #6]
	b _0800849E
_08008414:
	ldr r0, [r4, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x3c]
	ldrh r0, [r6, #6]
	ldr r2, _08008448 @ =0x0000FFFB
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r1, _0800844C @ =0x085AA67C
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _08008450
	adds r0, r4, #0
	bl FUN_0800832c
	b _0800845A
	.align 2, 0
_08008448: .4byte 0x0000FFFB
_0800844C: .4byte 0x085AA67C
_08008450:
	cmp r0, #2
	bne _0800845A
	adds r0, r4, #0
	bl FUN_08008394
_0800845A:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, [r6, #0x50]
	bl MainSprite_AdvanceAnim
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r1, [r4, #5]
	cmp r1, #0
	beq _08008498
	subs r1, #1
	strb r1, [r4, #5]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008490
	ldrh r1, [r5]
	ldr r3, _0800848C @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008496
	.align 2, 0
_0800848C: .4byte 0x0000FFFB
_08008490:
	ldrh r2, [r5]
	movs r1, #4
	orrs r1, r2
_08008496:
	strh r1, [r5]
_08008498:
	ldr r1, [r4, #0xc]
	adds r1, #1
	str r1, [r4, #0xc]
_0800849E:
	movs r1, #1
	add r8, r1
	adds r6, #0xe8
	adds r4, #0xe8
	ldr r1, [r7, #0x18]
	cmp r8, r1
	blo _080083D4
_080084AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity2D2B_Destroy
Entity2D2B_Destroy: @ 0x080084B8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _080084DC
_080084C2:
	ldrb r1, [r4]
	cmp r1, #0
	beq _080084D8
	adds r0, r4, #0
	adds r0, #0x94
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x34
	bl MainSprite_Remove
_080084D8:
	adds r5, #1
	adds r4, #0xe8
_080084DC:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _080084C2
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _080084F2
	adds r0, r1, #0
	bl Free
	movs r1, #0
	str r1, [r6, #0x1c]
_080084F2:
	ldr r2, _08008500 @ =0x03000034
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08008500: .4byte 0x03000034

	thumb_func_start Entity2D2B_Init
Entity2D2B_Init: @ 0x08008504
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, _08008538 @ =0x03000034
	str r6, [r0]
	movs r5, #0
	movs r0, #0x20
	adds r0, r0, r6
	mov r8, r0
	mov sb, r6
_0800851C:
	ldr r0, _0800853C @ =0x085AA66C
	lsls r1, r5, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, _08008540 @ =0x0000CB05
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008544
	movs r0, #1
	rsbs r0, r0, #0
	b _080085A2
	.align 2, 0
_08008538: .4byte 0x03000034
_0800853C: .4byte 0x085AA66C
_08008540: .4byte 0x0000CB05
_08008544:
	mov r1, sb
	adds r1, #0x20
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r0, r8
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r7, #0x20
	add r8, r7
	movs r0, #0x20
	add sb, r0
	adds r5, #1
	cmp r5, #1
	ble _0800851C
	movs r0, #0x6e
	movs r1, #8
	bl VM_GetKeywordValue
	str r0, [r6, #0x18]
	movs r1, #0xe8
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl Malloc
	str r0, [r6, #0x1c]
	adds r1, r4, #0
	bl ClearMemory
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _0800859C
_08008590:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08007f84
	adds r5, #1
	adds r4, #0xe8
_0800859C:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _08008590
_080085A2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity2D2B_Create
Entity2D2B_Create: @ 0x080085B0
	push {r4, lr}
	ldr r0, _080085E4 @ =0x03000034
	ldr r0, [r0]
	cmp r0, #0
	bne _080085F2
	movs r0, #0xa
	movs r1, #0x60
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080085F0
	ldr r1, _080085E8 @ =Entity2D2B_Update
	ldr r2, _080085EC @ =Entity2D2B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity2D2B_Init
	cmp r0, #0
	bge _080085F0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080085F2
	.align 2, 0
_080085E4: .4byte 0x03000034
_080085E8: .4byte Entity2D2B_Update
_080085EC: .4byte Entity2D2B_Destroy
_080085F0:
	adds r0, r4, #0
_080085F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080085f8
FUN_080085f8: @ 0x080085F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _080086C8 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _080086C2
	adds r0, r7, #0
	bl FUN_08007f00
	adds r6, r0, #0
	cmp r6, #0
	beq _080086C2
	movs r0, #0
	strb r0, [r6, #1]
	movs r4, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800866A
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r0, #0x28
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08234de8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080086C2
	movs r0, #1
	strb r0, [r6, #1]
	ldr r0, [r6, #0x30]
	ldrh r1, [r0, #4]
	ldr r0, _080086CC @ =0x00000FFF
	ands r0, r1
	strh r0, [r6, #0xa]
	bl Script_GetValue
	strh r0, [r6, #0x24]
	bl Script_GetValue
	strh r0, [r6, #0x26]
	ldr r1, [r6, #0x30]
	add r0, sp, #4
	movs r2, #0
	bl FUN_08234f80
	movs r4, #1
_0800866A:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800869C
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	strh r0, [r6, #6]
	adds r0, r4, #0
	bl FUN_081d553c
	adds r1, r0, #0
	str r1, [r6, #0x20]
	cmp r1, #0
	beq _080086C2
	movs r0, #2
	strb r0, [r6, #1]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r4, #1
_0800869C:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080086BE
	bl Script_GetValue
	add r1, sp, #4
	strh r0, [r1]
	bl Script_GetValue
	add r4, sp, #4
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	movs r4, #1
_080086BE:
	cmp r4, #0
	bne _080086D0
_080086C2:
	movs r0, #1
	rsbs r0, r0, #0
	b _08008860
	.align 2, 0
_080086C8: .4byte 0x03000034
_080086CC: .4byte 0x00000FFF
_080086D0:
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08007f28
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #3]
	movs r0, #0x64
	movs r1, #0x78
	bl VM_GetKeywordValue
	strh r0, [r6, #8]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x10]
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0xe4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r7, r0
	str r0, [r4]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x12]
	movs r0, #0x61
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r6, #0x1c]
	ldrb r0, [r6, #1]
	adds r7, r4, #0
	cmp r0, #2
	beq _080087B8
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08008758
	cmp r1, #0
	blt _08008758
	ldr r0, _0800875C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08008758
	ldr r0, _08008760 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08008764
_08008758:
	movs r4, #0
	b _08008772
	.align 2, 0
_0800875C: .4byte 0x030046A8
_08008760: .4byte 0x030046AC
_08008764:
	ldr r0, _08008784 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08008772:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08008788
	adds r0, #4
	b _08008794
	.align 2, 0
_08008784: .4byte 0x030046A4
_08008788:
	ldr r0, _080087A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08008794:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080087AC
	cmp r2, #2
	beq _080087B0
	b _080087B4
	.align 2, 0
_080087A8: .4byte 0x030046A4
_080087AC:
	ldrb r0, [r5, #4]
	b _080087B2
_080087B0:
	ldrb r0, [r5]
_080087B2:
	subs r1, r1, r0
_080087B4:
	add r0, sp, #4
	strh r1, [r0, #2]
_080087B8:
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _080087CC
	add r0, sp, #4
	bl FUN_08241574
	b _080087D0
_080087CC:
	movs r0, #1
	rsbs r0, r0, #0
_080087D0:
	str r0, [r6, #0x14]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x3c]
	ldrb r0, [r6, #2]
	cmp r0, #1
	bne _08008824
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _0800881C @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _08008820 @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl MainSprite_SetPlttID
	b _08008852
	.align 2, 0
_0800881C: .4byte 0x085AA670
_08008820: .4byte 0x085AA678
_08008824:
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _08008868 @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _0800886C @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl MainSprite_SetPlttID
_08008852:
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddMainSpriteIntoDrawList
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
_08008860:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008868: .4byte 0x085AA670
_0800886C: .4byte 0x085AA678

	thumb_func_start FUN_08008870
FUN_08008870: @ 0x08008870
	push {r4, r5, lr}
	ldr r0, _08008898 @ =0x03000034
	ldr r4, [r0]
	cmp r4, #0
	beq _080088B4
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl VM_GetKeywordValue
	adds r3, r0, #0
	ldr r1, [r4, #0x1c]
	movs r2, #0
	b _080088AE
	.align 2, 0
_08008898: .4byte 0x03000034
_0800889C:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080088AA
	ldrh r0, [r1, #0x10]
	cmp r0, r5
	bne _080088AA
	strh r3, [r1, #8]
_080088AA:
	adds r2, #1
	adds r1, #0xe8
_080088AE:
	ldr r0, [r4, #0x18]
	cmp r2, r0
	blo _0800889C
_080088B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080088bc
FUN_080088bc: @ 0x080088BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080088F0 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _08008912
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x6d
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	cmp r6, r4
	beq _08008912
	cmp r6, #4
	bgt _08008912
	ldr r4, [r7, #0x1c]
	movs r5, #0
	b _0800890C
	.align 2, 0
_080088F0: .4byte 0x03000034
_080088F4:
	ldrb r0, [r4]
	cmp r0, #1
	bne _08008908
	ldrh r0, [r4, #0x10]
	cmp r0, r8
	bne _08008908
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08007f28
_08008908:
	adds r5, #1
	adds r4, #0xe8
_0800890C:
	ldr r0, [r7, #0x18]
	cmp r5, r0
	blo _080088F4
_08008912:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
