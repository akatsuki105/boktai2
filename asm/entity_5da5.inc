	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800891c
FUN_0800891c: @ 0x0800891C
	movs r2, #0
	strb r1, [r0, #1]
	str r2, [r0, #4]
	movs r1, #1
	strb r1, [r0, #2]
	bx lr

	thumb_func_start FUN_08008928
FUN_08008928: @ 0x08008928
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08008936
	movs r0, #0
	b _0800893C
_08008936:
	movs r0, #0
	strb r0, [r1, #2]
	movs r0, #1
_0800893C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08008940
FUN_08008940: @ 0x08008940
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r2, #0
	ldr r0, _08008980 @ =0x03000038
	ldr r5, [r0]
	cmp r5, #0
	beq _080089B0
	ldrb r4, [r6, #1]
	cmp r4, #0
	bne _08008984
	movs r1, #4
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0800891c
	movs r1, #1
	adds r0, r1, #0
	ldrb r2, [r6]
	lsls r0, r2
	ldrh r2, [r5, #0x34]
	orrs r0, r2
	strh r0, [r5, #0x34]
	ldrb r6, [r6]
	lsls r1, r6
	ldrh r0, [r5, #0x38]
	orrs r1, r0
	strh r1, [r5, #0x38]
	b _080089B0
	.align 2, 0
_08008980: .4byte 0x03000038
_08008984:
	cmp r4, #1
	bne _080089B0
	movs r1, #8
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0800891c
	adds r0, r4, #0
	ldrb r1, [r6]
	lsls r0, r1
	ldrh r1, [r5, #0x36]
	orrs r0, r1
	strh r0, [r5, #0x36]
	ldrb r6, [r6]
	lsls r4, r6
	ldrh r0, [r5, #0x38]
	orrs r4, r0
	strh r4, [r5, #0x38]
_080089B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080089b8
FUN_080089b8: @ 0x080089B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	movs r4, #0
	strb r7, [r1]
	mov r0, r8
	movs r1, #0
	bl FUN_0800891c
	mov r0, r8
	strb r4, [r0, #3]
	mov r5, r8
	adds r5, #0x58
	mov r6, sb
	adds r6, #0x4c
	movs r0, #2
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sb
	adds r0, #0x44
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	adds r2, r7, #2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
	subs r5, #0x50
	subs r0, r7, #1
	cmp r0, #1
	bhi _08008A3C
	ldr r2, _08008A34 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x18
	orrs r0, r1
	ldr r1, _08008A38 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x60
	b _08008A58
	.align 2, 0
_08008A34: .4byte 0xFFFF0000
_08008A38: .4byte 0x0000FFFF
_08008A3C:
	ldr r2, _08008AD4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x60
	orrs r0, r1
	ldr r1, _08008AD8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x18
_08008A58:
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, _08008ADC @ =0x085AA690
	lsls r2, r7, #1
	adds r0, r2, r0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r0, #0x10
	lsls r0, r0, #0x10
	ldr r4, _08008AD4 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _08008AE0 @ =0x085AA698
	adds r2, r2, r0
	ldrh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	ldr r2, _08008AE4 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0x10
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08008AE8 @ =FUN_08008940
	adds r0, r5, #0
	mov r2, r8
	bl FUN_0823651c
	mov r1, sb
	adds r1, #0x3c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008AD4: .4byte 0xFFFF0000
_08008AD8: .4byte 0x0000FFFF
_08008ADC: .4byte 0x085AA690
_08008AE0: .4byte 0x085AA698
_08008AE4: .4byte 0x00004001
_08008AE8: .4byte FUN_08008940

	thumb_func_start FUN_08008aec
FUN_08008aec: @ 0x08008AEC
	push {r4, lr}
	sub sp, #0x28
	adds r3, r0, #0
	adds r4, r1, #0
	ldrh r0, [r3, #0x1a]
	cmp r0, #0
	beq _08008B5C
	str r2, [sp]
	cmp r4, #1
	bne _08008B12
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	beq _08008B28
	movs r0, #0
	str r0, [sp, #8]
	b _08008B2A
_08008B12:
	cmp r4, #0
	bne _08008B2A
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08008B28
	movs r0, #1
	str r0, [sp, #8]
	b _08008B2A
_08008B28:
	str r4, [sp, #8]
_08008B2A:
	ldrh r0, [r3, #0x38]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0x24]
	str r0, [sp, #0x10]
	ldr r0, [r3, #0x28]
	str r0, [sp, #0x14]
	ldr r0, [r3, #0x2c]
	str r0, [sp, #0x18]
	ldr r0, [r3, #0x30]
	str r0, [sp, #0x1c]
	ldr r1, _08008B64 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r3, #0x1a]
	bl Script_ExecById
_08008B5C:
	add sp, #0x28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008B64: .4byte 0xFFFF0000

	thumb_func_start FUN_08008b68
FUN_08008b68: @ 0x08008B68
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08008928
	cmp r0, #0
	beq _08008BF0
	ldr r0, [r5, #0x60]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5]
	lsls r1, r0
	ldrh r0, [r6, #0x1c]
	bics r0, r1
	movs r3, #0
	strh r0, [r6, #0x1c]
	ldr r1, _08008BF8 @ =0x085AA690
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x3c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r4, _08008BFC @ =0xFFFF0000
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r2, [r6, #0x3e]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r2, r6, #0
	adds r2, #0x40
	ldr r1, _08008C00 @ =0x085AA698
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r2, _08008C04 @ =0x00002001
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015ce0
_08008BF0:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008BF8: .4byte 0x085AA690
_08008BFC: .4byte 0xFFFF0000
_08008C00: .4byte 0x085AA698
_08008C04: .4byte 0x00002001

	thumb_func_start FUN_08008c08
FUN_08008c08: @ 0x08008C08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08008928
	cmp r0, #0
	beq _08008C2E
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	movs r0, #1
	ldrb r1, [r4]
	lsls r0, r1
	ldrh r1, [r5, #0x1c]
	orrs r0, r1
	strh r0, [r5, #0x1c]
_08008C2E:
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	str r0, [r4, #0x78]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x4c
	bl MainSprite_AdvanceAnim
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start Entity5DA5_Update
Entity5DA5_Update: @ 0x08008C48
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08008C94 @ =0x030047A4
	ldr r1, _08008C98 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08008C6E
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08009064
_08008C6E:
	adds r5, r6, #0
	adds r5, #0x44
	adds r2, r6, #0
	adds r2, #0x3c
	ldrh r0, [r6, #0x3c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r2, #0
	cmp r0, #0
	blt _08008C9C
	asrs r0, r0, #8
	b _08008CA2
	.align 2, 0
_08008C94: .4byte 0x030047A4
_08008C98: .4byte 0x030047A0
_08008C9C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CA2:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008CB4
	asrs r0, r0, #8
	b _08008CBA
_08008CB4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CBA:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008CCE
	asrs r0, r0, #8
	b _08008CD4
_08008CCE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CD4:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08008D30 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r4, r6, #0
	adds r4, #0xcc
	movs r5, #3
_08008CF8:
	ldr r1, _08008D34 @ =0x085AA6A0
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	adds r0, r4, #0
	adds r0, #8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r1, [r4, #3]
	cmp r1, #0
	beq _08008D44
	subs r1, #1
	strb r1, [r4, #3]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008D3C
	ldrh r1, [r4, #0xe]
	ldr r3, _08008D38 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008D42
	.align 2, 0
_08008D30: .4byte 0x030047C8
_08008D34: .4byte 0x085AA6A0
_08008D38: .4byte 0x0000FFFB
_08008D3C:
	ldrh r2, [r4, #0xe]
	movs r1, #4
	orrs r1, r2
_08008D42:
	strh r1, [r4, #0xe]
_08008D44:
	ldr r1, [r4, #4]
	adds r1, #1
	str r1, [r4, #4]
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008CF8
	movs r5, #4
	ldrh r2, [r6, #0x1c]
	movs r1, #0xf
	ands r1, r2
	cmp r1, #0xf
	bne _08008DC4
	ldr r0, [r6, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x6c
	adds r1, r6, #0
	adds r1, #0x4c
	bl MainSprite_AdvanceAnim
	adds r3, r6, #0
	adds r3, #0x8c
	ldr r1, [r6, #0x44]
	ldr r2, [r6, #0x48]
	str r1, [r3]
	str r2, [r3, #4]
	adds r1, r6, #0
	adds r1, #0x89
	ldrb r1, [r1]
	ands r5, r1
	cmp r5, #0
	beq _08008DD6
	movs r0, #0x10
	str r0, [sp]
	ldr r2, _08008DBC @ =0x085AA6A8
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r2, #2
	mov r3, sp
	bl FUN_08000fac
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, _08008DC0 @ =0x03003E78
	ldrh r2, [r3]
	orrs r1, r2
	strh r1, [r3]
	b _08008DD6
	.align 2, 0
_08008DBC: .4byte 0x085AA6A8
_08008DC0: .4byte 0x03003E78
_08008DC4:
	ldr r3, _08008E34 @ =0x03003E78
	ldr r1, _08008E38 @ =0xFFFFFDFF
	ldrh r2, [r3]
	ands r1, r2
	strh r1, [r3]
	ldr r1, [r6, #0x74]
	movs r2, #1
	orrs r1, r2
	str r1, [r6, #0x74]
_08008DD6:
	ldrh r1, [r6, #0x34]
	cmp r1, #0
	beq _08008E00
	ldr r0, _08008E3C @ =0x0000014B
	bl PlaySound_082406e0
	movs r5, #0
_08008DE4:
	ldrh r1, [r6, #0x34]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008DFA
	adds r0, r6, #0
	movs r1, #1
	adds r2, r5, #0
	bl FUN_08008aec
_08008DFA:
	adds r5, #1
	cmp r5, #3
	ble _08008DE4
_08008E00:
	ldrh r1, [r6, #0x36]
	cmp r1, #0
	beq _08008E24
	movs r5, #0
_08008E08:
	ldrh r1, [r6, #0x36]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008E1E
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_08008aec
_08008E1E:
	adds r5, #1
	cmp r5, #3
	ble _08008E08
_08008E24:
	movs r1, #0
	strh r1, [r6, #0x34]
	strh r1, [r6, #0x36]
	strh r1, [r6, #0x38]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008E34: .4byte 0x03003E78
_08008E38: .4byte 0xFFFFFDFF
_08008E3C: .4byte 0x0000014B

	thumb_func_start Entity5DA5_Destroy
Entity5DA5_Destroy: @ 0x08008E40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x6c
	bl FUN_0822f1c0
	adds r4, #0xcc
	movs r5, #3
_08008E4E:
	adds r0, r4, #0
	adds r0, #8
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x58
	bl FUN_0822f1c0
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008E4E
	ldr r2, _08008E74 @ =0x03000038
	movs r1, #0
	str r1, [r2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08008E74: .4byte 0x03000038

	thumb_func_start Entity5DA5_Init
Entity5DA5_Init: @ 0x08008E78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08008EA0 @ =0x03000038
	str r7, [r0]
	ldr r0, _08008EA4 @ =0x0000CB05
	ldr r1, _08008EA8 @ =0x0000F099
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008EAC
	movs r0, #1
	rsbs r0, r0, #0
	b _08009000
	.align 2, 0
_08008EA0: .4byte 0x03000038
_08008EA4: .4byte 0x0000CB05
_08008EA8: .4byte 0x0000F099
_08008EAC:
	adds r1, r7, #0
	adds r1, #0x4c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x4c
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r4, #0
	movs r5, #0
	mov r0, r8
	strh r0, [r7, #0x18]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7, #0x1a]
	strh r5, [r7, #0x1c]
	strb r4, [r7, #0x1e]
	strb r4, [r7, #0x1f]
	str r5, [r7, #0x20]
	movs r0, #0x61
	bl VM_SeekToKeyword
	str r6, [sp, #0x10]
	subs r6, #0xc
	movs r1, #0x44
	adds r1, r1, r7
	mov sb, r1
	movs r3, #0x3c
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0x6c
	adds r4, r4, r7
	mov sl, r4
	adds r5, r7, #0
	adds r5, #0xcc
	str r5, [sp, #0x14]
	cmp r0, #0
	beq _08008F24
	subs r5, #0xa8
	movs r4, #3
_08008F0E:
	bl VM_GetPC
	cmp r0, #0
	beq _08008F1C
	bl Script_GetValue
	str r0, [r5]
_08008F1C:
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _08008F0E
_08008F24:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08008F40
	bl Script_GetValue
	strh r0, [r7, #0x3c]
	bl Script_GetValue
	strh r0, [r7, #0x3e]
	bl Script_GetValue
	b _08008F44
_08008F40:
	strh r0, [r7, #0x3c]
	strh r0, [r7, #0x3e]
_08008F44:
	strh r0, [r6]
	mov r6, sb
	mov r5, r8
	ldrh r0, [r7, #0x3c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F66
	asrs r0, r0, #8
	b _08008F6C
_08008F66:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F6C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F7E
	asrs r0, r0, #8
	b _08008F84
_08008F7E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F84:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008F98
	asrs r0, r0, #8
	b _08008F9E
_08008F98:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F9E:
	subs r2, r4, r0
	movs r5, #0
	strh r2, [r6, #2]
	adds r4, r4, r0
	strh r4, [r6, #4]
	ldr r3, _08009010 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	str r5, [sp]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #6
	movs r3, #1
	bl FUN_082370cc
	ldr r5, [sp, #0x14]
	movs r4, #0
_08008FEE:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080089b8
	adds r4, #1
	adds r5, #0xb8
	cmp r4, #3
	ble _08008FEE
_08009000:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08009010: .4byte 0x030047C8

	thumb_func_start Entity5DA5_Create
Entity5DA5_Create: @ 0x08009014
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08009050 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _0800905E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800905C
	ldr r1, _08009054 @ =Entity5DA5_Update
	ldr r2, _08009058 @ =Entity5DA5_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity5DA5_Init
	cmp r0, #0
	bge _0800905C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800905E
	.align 2, 0
_08009050: .4byte 0x03000038
_08009054: .4byte Entity5DA5_Update
_08009058: .4byte Entity5DA5_Destroy
_0800905C:
	adds r0, r4, #0
_0800905E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009064
FUN_08009064: @ 0x08009064
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r1, _08009080 @ =0x03000038
	ldr r4, [r1]
	cmp r4, #0
	bne _08009084
	movs r0, #1
	rsbs r0, r0, #0
	b _08009116
	.align 2, 0
_08009080: .4byte 0x03000038
_08009084:
	cmp r6, #0
	bge _080090D6
	adds r5, r4, #0
	adds r5, #0xcc
	movs r6, #0
	movs r3, #1
_08009090:
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _080090CC
	adds r0, r5, #0
	adds r1, r7, #0
	str r3, [sp]
	bl FUN_0800891c
	ldr r3, [sp]
	cmp r7, #0
	bne _080090B2
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _080090BC
_080090B2:
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_080090BC:
	mov r1, r8
	cmp r1, #0
	beq _080090CC
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_080090CC:
	adds r6, #1
	adds r5, #0xb8
	cmp r6, #3
	ble _08009090
	b _08009116
_080090D6:
	movs r1, #0xb8
	muls r1, r6, r1
	adds r1, #0xcc
	adds r5, r4, r1
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _08009116
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0800891c
	cmp r7, #0
	bne _080090FC
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _08009106
_080090FC:
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_08009106:
	mov r1, r8
	cmp r1, #0
	beq _08009116
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_08009116:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009124
FUN_08009124: @ 0x08009124
	push {r4, r5, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x69
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009064
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009154
FUN_08009154: @ 0x08009154
	push {lr}
	ldr r0, _08009164 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _08009168
	movs r0, #1
	rsbs r0, r0, #0
	b _08009188
	.align 2, 0
_08009164: .4byte 0x03000038
_08009168:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_08009170:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _08009178
	adds r3, #1
_08009178:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _08009170
	movs r0, #0
	cmp r3, #4
	bne _08009188
	movs r0, #1
_08009188:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800918c
FUN_0800918c: @ 0x0800918C
	push {lr}
	ldr r0, _0800919C @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _080091A0
	movs r0, #1
	rsbs r0, r0, #0
	b _080091C0
	.align 2, 0
_0800919C: .4byte 0x03000038
_080091A0:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_080091A8:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _080091B0
	adds r3, #1
_080091B0:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _080091A8
	movs r0, #0
	cmp r3, #0
	bne _080091C0
	movs r0, #1
_080091C0:
	pop {r1}
	bx r1

