	.include "asm/macros.inc"

	.syntax unified
	
	.text


	thumb_func_start FUN_081cf944
FUN_081cf944: @ 0x081CF944
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r4, r0, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081CF990
	mov r0, sp
	movs r1, #0x20
	bl ClearMemory
	adds r5, r4, #0
	adds r5, #0x8c
	ldrh r0, [r5]
	cmp r0, #0
	beq _081CF990
	adds r0, r4, #0
	adds r0, #0x88
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp]
	ldr r1, _081CFA1C @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5]
	bl Script_ExecById
	movs r0, #0
	strh r0, [r5]
_081CF990:
	adds r2, r4, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _081CFA0A
	mov r0, sp
	movs r1, #0x20
	bl ClearMemory
	adds r5, r4, #0
	adds r5, #0x8a
	ldrh r0, [r5]
	cmp r0, #0
	beq _081CFA0A
	adds r0, r4, #0
	adds r0, #0x88
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x94
	ldr r0, [r0]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r0, #0xa0
	ldr r0, [r0]
	str r0, [sp, #0x14]
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	lsrs r0, r0, #0xa
	movs r1, #1
	ands r0, r1
	str r0, [sp, #0x1c]
	movs r4, #0
	movs r0, #8
	add r1, sp, #0x20
	strh r0, [r1]
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5]
	bl Script_ExecById
	strh r4, [r5]
_081CFA0A:
	ldrh r1, [r6]
	ldr r0, _081CFA20 @ =0x0000FA7F
	ands r0, r1
	strh r0, [r6]
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CFA1C: .4byte 0xFFFF0000
_081CFA20: .4byte 0x0000FA7F

	thumb_func_start FUN_081cfa24
FUN_081cfa24: @ 0x081CFA24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp, #0x1c]
	ldr r2, _081CFACC @ =0xFFFF0000
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	movs r2, #0x80
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r0, r2
	str r0, [sp, #0x14]
	mov sl, r1
	add r0, sp, #0x10
	mov r8, r0
	adds r1, #8
	str r1, [sp, #0x28]
	mov r2, r8
	movs r1, #0
	mov r0, sp
	adds r0, #0x13
_081CFA5E:
	strb r1, [r0]
	subs r0, #1
	cmp r0, r2
	bge _081CFA5E
	movs r2, #0
	str r2, [sp, #0x24]
	movs r3, #0
	str r3, [sp, #0x20]
	movs r4, #0
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	adds r6, r7, #0
	adds r6, #0xb8
	mov r5, sp
_081CFA7C:
	mov r0, sb
	mov r1, sl
	adds r2, r4, #0
	bl FUN_080e11a8
	str r0, [r5]
	cmp r0, #0
	beq _081CFA9C
	mov r2, r8
	adds r1, r2, r4
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r6]
	movs r0, #0x80
	orrs r0, r1
	strh r0, [r6]
_081CFA9C:
	adds r5, #4
	adds r4, #1
	cmp r4, #3
	ble _081CFA7C
	adds r0, r7, #0
	bl FUN_081cfcb8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CFAC2
	movs r3, #1
	str r3, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	adds r3, #0xff
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
_081CFAC2:
	movs r4, #0
	movs r5, #1
	movs r6, #3
	b _081CFB32
	.align 2, 0
_081CFACC: .4byte 0xFFFF0000
_081CFAD0:
	ldr r0, _081CFB88 @ =0x00000553
	adds r2, r1, r0
	ldrb r0, [r2]
	subs r0, #0x16
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081CFB32
	ldr r3, _081CFB8C @ =0x0000046D
	adds r0, r1, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r1, r3
	strb r4, [r0]
	movs r0, #0x16
	strb r0, [r2]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, _081CFB90 @ =FUN_080f54e4
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r1, r2
	strh r4, [r0]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r1, r3
	strb r6, [r0]
	ldr r2, _081CFB94 @ =0x00000469
	adds r0, r1, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r1, r3
	strb r4, [r0]
	adds r2, #0x1b
	adds r0, r1, r2
	str r4, [r0]
	adds r3, #2
	adds r0, r1, r3
	strb r5, [r0]
	adds r2, #0x3a
	adds r0, r1, r2
	strh r4, [r0]
	adds r0, r1, #0
	bl FUN_080e64e4
	movs r3, #1
	str r3, [sp, #0x24]
_081CFB32:
	mov r0, sb
	mov r1, sl
	ldr r2, [sp, #0x28]
	bl FUN_080e1100
	adds r1, r0, #0
	cmp r1, #0
	bne _081CFAD0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _081CFB5C
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _081CFB5C
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _081CFB5C
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _081CFC18
_081CFB5C:
	ldr r0, _081CFB98 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081CFB9C
	adds r0, r7, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081CFBA4
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #5
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	b _081CFBA4
	.align 2, 0
_081CFB88: .4byte 0x00000553
_081CFB8C: .4byte 0x0000046D
_081CFB90: .4byte FUN_080f54e4
_081CFB94: .4byte 0x00000469
_081CFB98: .4byte 0x030047A4
_081CFB9C:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #7
	strh r0, [r1]
_081CFBA4:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq _081CFBE4
	movs r4, #0
	adds r6, r7, #0
	adds r6, #0xb8
	mov r5, sp
_081CFBB2:
	mov r3, r8
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CFBD4
	ldr r0, [r5]
	movs r1, #1
	bl FUN_0807a570
	cmp r0, #0
	beq _081CFBD4
	ldrh r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r6]
_081CFBD4:
	adds r5, #4
	adds r4, #1
	cmp r4, #3
	ble _081CFBB2
	movs r0, #1
	bl FUN_080868b8
	b _081CFC4E
_081CFBE4:
	movs r4, #0
	adds r6, r7, #0
	adds r6, #0xb8
	mov r5, sp
_081CFBEC:
	mov r3, r8
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CFC0E
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0807a570
	cmp r0, #0
	beq _081CFC0E
	ldrh r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r6]
_081CFC0E:
	adds r5, #4
	adds r4, #1
	cmp r4, #3
	ble _081CFBEC
	b _081CFC4E
_081CFC18:
	ldr r3, [sp, #0x20]
	cmp r3, #0
	beq _081CFC2C
	adds r0, r7, #0
	bl FUN_081cf944
	movs r0, #0
	bl FUN_080868b8
	b _081CFC40
_081CFC2C:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _081CFC4E
	adds r0, r7, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081CFC4E
_081CFC40:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #5
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
_081CFC4E:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081cfc60
FUN_081cfc60: @ 0x081CFC60
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r7, #1
_081CFC68:
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x68]
	ands r0, r1
	cmp r0, #0
	beq _081CFC78
	movs r0, #1
	b _081CFC7A
_081CFC78:
	movs r0, #0
_081CFC7A:
	cmp r0, #0
	bne _081CFCAA
	movs r0, #0xc0
	bl Malloc
	adds r4, r0, #0
	movs r1, #0xc0
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x68]
	orrs r0, r1
	str r0, [r5, #0x68]
	adds r0, r4, #0
	adds r0, #0xb4
	strh r6, [r0]
	lsls r1, r6, #2
	adds r0, r5, #0
	adds r0, #0x38
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r4, #0
	b _081CFCB2
_081CFCAA:
	adds r6, #1
	cmp r6, #0xb
	ble _081CFC68
	movs r0, #0
_081CFCB2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081cfcb8
FUN_081cfcb8: @ 0x081CFCB8
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081CFD2C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081CFD30
	movs r0, #6
	bl FUN_0808660c
	cmp r0, #0
	bne _081CFD30
	movs r0, #7
	bl FUN_0808660c
	cmp r0, #0
	bne _081CFD30
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _081CFD30
	mov r4, sp
	adds r2, r5, #0
	adds r2, #0x80
	ldrh r0, [r3]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _081CFD16
	rsbs r0, r0, #0
_081CFD16:
	cmp r0, #0x80
	bgt _081CFD30
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _081CFD24
	rsbs r0, r0, #0
_081CFD24:
	cmp r0, #0x80
	bgt _081CFD30
	movs r0, #1
	b _081CFD32
	.align 2, 0
_081CFD2C: .4byte 0x030047A4
_081CFD30:
	movs r0, #0
_081CFD32:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081cfd3c
FUN_081cfd3c: @ 0x081CFD3C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081cfd40
FUN_081cfd40: @ 0x081CFD40
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	ldr r1, _081CFDB4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r0, r1
	str r0, [sp]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x80
_081CFD68:
	adds r0, r5, #0
	adds r0, #0x80
	mov r1, sp
	adds r2, r4, #0
	bl FUN_080e11a8
	cmp r0, #0
	bne _081CFD9C
	adds r4, #1
	cmp r4, #3
	ble _081CFD68
	adds r0, r5, #0
	bl FUN_081cfcb8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _081CFD9C
	str r0, [sp, #8]
	add r2, sp, #8
	adds r0, r6, #0
	mov r1, sp
	bl FUN_080e1100
	cmp r0, #0
	beq _081CFDAC
_081CFD9C:
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #0
	movs r1, #2
	strh r1, [r2]
	adds r1, r5, #0
	adds r1, #0xbb
	strb r0, [r1]
_081CFDAC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CFDB4: .4byte 0xFFFF0000

	thumb_func_start FUN_081cfdb8
FUN_081cfdb8: @ 0x081CFDB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r1, r0, #0
	ldr r0, _081D0058 @ =0x030047A4
	ldr r7, [r0]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r7, r0
	cmp r7, #0
	beq _081CFDD6
	b _081D0046
_081CFDD6:
	adds r0, r1, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	cmp r0, #1
	ble _081CFDE2
	b _081D0046
_081CFDE2:
	cmp r0, #0
	bge _081CFDE8
	b _081D0046
_081CFDE8:
	adds r6, r1, #0
	adds r6, #0x80
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _081D005C @ =0x0203B400
	mov sl, r0
	ldr r4, _081D0060 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r1, _081D0064 @ =0x000003FF
	mov r8, r1
	ands r2, r1
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	add r0, sp, #0x20
	ldrh r1, [r0]
	adds r1, #0x5c
	movs r0, #0x3f
	mov sb, r0
	mov r0, sb
	ands r3, r0
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _081D0068 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	str r2, [r4]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	add r5, sp, #0x20
	ldrh r1, [r5, #4]
	adds r1, #0x5c
	mov r2, sb
	ands r0, r2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x24]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r3, #4
	str r3, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x20
	str r0, [sp, #0xc]
	movs r1, #0x40
	str r1, [sp, #0x10]
	movs r2, #1
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	movs r3, #0x80
	lsls r3, r3, #2
	str r3, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r1, [r4]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	add r0, sl
	ldrh r2, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	subs r0, #0x5c
	mov r3, sb
	ands r2, r3
	subs r0, r0, r2
	add r2, sp, #0x20
	strh r0, [r2]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r1, [r1]
	ldrh r0, [r5, #4]
	subs r0, #0x5c
	ands r1, r3
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #4
	str r1, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r2, #0x20
	str r2, [sp, #0xc]
	movs r3, #0x40
	str r3, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r1, [r4]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	lsls r0, r1, #1
	add r0, sl
	ldrh r2, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	subs r0, #0x5c
	mov r3, sb
	ands r2, r3
	subs r0, r0, r2
	add r2, sp, #0x20
	strh r0, [r2]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r1, [r1]
	ldrh r0, [r5, #4]
	adds r0, #0x5c
	ands r1, r3
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #4
	str r1, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r2, #0x20
	str r2, [sp, #0xc]
	movs r3, #0x40
	str r3, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r1, [r4]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	lsls r0, r1, #1
	add r0, sl
	ldrh r2, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	adds r0, #0x5c
	mov r3, sb
	ands r2, r3
	subs r0, r0, r2
	add r2, sp, #0x20
	strh r0, [r2]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r1, [r1]
	ldrh r0, [r5, #4]
	subs r0, #0x5c
	ands r1, r3
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r5, #2
	str r5, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r1, #0x20
	str r1, [sp, #0xc]
	movs r2, #0x40
	str r2, [sp, #0x10]
	movs r3, #1
	str r3, [sp, #0x14]
	str r3, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [r4]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r1, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	subs r0, #0x5c
	mov r2, sb
	ands r1, r2
	subs r0, r0, r1
	add r1, sp, #0x20
	strh r0, [r1]
	str r5, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r3, #0x20
	str r3, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r2, #0x80
	lsls r2, r2, #2
	str r2, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [r4]
	adds r0, #1
	mov r3, r8
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r1, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	adds r0, #0x5c
	mov r2, sb
	ands r1, r2
	subs r0, r0, r1
	add r1, sp, #0x20
	strh r0, [r1]
	movs r3, #4
	str r3, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x20
	str r0, [sp, #0xc]
	movs r1, #0x40
	str r1, [sp, #0x10]
	movs r2, #1
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	movs r3, #0x80
	lsls r3, r3, #2
	str r3, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
_081D0046:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D0058: .4byte 0x030047A4
_081D005C: .4byte 0x0203B400
_081D0060: .4byte 0x030046B8
_081D0064: .4byte 0x000003FF
_081D0068: .4byte 0xFFFF0000

	thumb_func_start FUN_081d006c
FUN_081d006c: @ 0x081D006C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D00CC @ =0x03000188
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #0xbb
	ldrb r0, [r6]
	adds r1, r5, #0
	adds r1, #0xb2
	ldrh r1, [r1]
	cmp r0, r1
	blo _081D00E4
	adds r0, r5, #0
	bl FUN_081cfdb8
	adds r0, r5, #0
	adds r0, #0x70
	ldr r1, [r4, #0x18]
	adds r4, r5, #0
	adds r4, #0xb0
	ldrb r3, [r4]
	movs r2, #0
	str r2, [sp]
	bl FUN_08236fac
	adds r1, r5, #0
	adds r1, #0xb6
	movs r2, #0
	movs r0, #4
	strh r0, [r1]
	strb r2, [r6]
	ldrh r0, [r4]
	cmp r0, #1
	bgt _081D00E8
	cmp r0, #0
	blt _081D00E8
	ldr r0, _081D00D0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081D00D8
	ldr r0, _081D00D4 @ =0x0000026D
	bl PlaySound_082406e0
	b _081D00E8
	.align 2, 0
_081D00CC: .4byte 0x03000188
_081D00D0: .4byte 0x030047A4
_081D00D4: .4byte 0x0000026D
_081D00D8:
	ldr r0, _081D00E0 @ =0x000001AB
	bl PlaySound_082406e0
	b _081D00E8
	.align 2, 0
_081D00E0: .4byte 0x000001AB
_081D00E4:
	adds r0, #1
	strb r0, [r6]
_081D00E8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d00f0
FUN_081d00f0: @ 0x081D00F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081D016C @ =0x03000188
	ldr r4, [r0]
	adds r7, r6, #0
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _081D0112
	b _081D02A8
_081D0112:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r0, #0xba
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	movs r1, #0x70
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _081D017E
	adds r0, r6, #0
	bl FUN_081cfdb8
	ldr r1, [r4, #0x18]
	adds r5, r6, #0
	adds r5, #0xb0
	ldrb r3, [r5]
	movs r4, #0
	str r4, [sp]
	mov r0, sb
	movs r2, #0
	bl FUN_08236fac
	mov r2, r8
	strb r4, [r2]
	ldrh r0, [r5]
	cmp r0, #1
	bgt _081D017E
	cmp r0, #0
	blt _081D017E
	ldr r0, _081D0170 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081D0178
	ldr r0, _081D0174 @ =0x0000026D
	bl PlaySound_082406e0
	b _081D017E
	.align 2, 0
_081D016C: .4byte 0x03000188
_081D0170: .4byte 0x030047A4
_081D0174: .4byte 0x0000026D
_081D0178:
	ldr r0, _081D01D4 @ =0x000001AB
	bl PlaySound_082406e0
_081D017E:
	adds r0, r6, #0
	adds r0, #0x78
	ldrh r1, [r0]
	cmp r1, #0
	bne _081D0190
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #2
	bhi _081D019E
_081D0190:
	cmp r1, #1
	bne _081D01A4
	adds r0, r6, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D01A4
_081D019E:
	adds r0, r6, #0
	bl FUN_081cfa24
_081D01A4:
	mov r4, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D01D8
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D01E0
	.align 2, 0
_081D01D4: .4byte 0x000001AB
_081D01D8:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D01E0:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0204
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D020C
_081D0204:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D020C:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D0244 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D028A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D024E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D0248
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D0264
	.align 2, 0
_081D0244: .4byte 0x0000FFFF
_081D0248:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D0262
_081D024E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D0262
	strh r1, [r4, #8]
	movs r2, #1
	b _081D0264
_081D0262:
	movs r2, #0
_081D0264:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D028C
	movs r0, #1
	strb r0, [r4, #7]
	b _081D028C
_081D028A:
	movs r2, #0
_081D028C:
	cmp r2, #0
	beq _081D02A8
	adds r1, r6, #0
	adds r1, #0xb6
	movs r0, #6
	strh r0, [r1]
	adds r2, r6, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	ldr r0, _081D02B8 @ =0x0000FFDF
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
_081D02A8:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D02B8: .4byte 0x0000FFDF

	thumb_func_start FUN_081d02bc
FUN_081d02bc: @ 0x081D02BC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	mov ip, r6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	adds r0, #0x78
	ldrh r0, [r0]
	cmp r0, #1
	bne _081D02F4
	adds r0, r6, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D02F4
	adds r0, r6, #0
	bl FUN_081cfa24
	adds r1, r6, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r3, r1, #0
	b _081D03DC
_081D02F4:
	adds r4, r6, #0
	adds r4, #0x70
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0328
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D0334
_081D0328:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D0334:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D035A
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D0364
_081D035A:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D0364:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D03A0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r6, #0
	adds r3, #0xbb
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D03DC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D03A4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D039A
	ldrb r0, [r4, #5]
_081D039A:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D03B4
	.align 2, 0
_081D03A0: .4byte 0x0000FFFF
_081D03A4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D03B4
	strh r1, [r4, #8]
_081D03B4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	adds r3, r6, #0
	adds r3, #0xbb
	cmp r0, #0
	bne _081D03DC
	movs r0, #1
	strb r0, [r4, #7]
_081D03DC:
	ldrb r0, [r3]
	cmp r0, #0x1e
	bls _081D03F4
	adds r1, r6, #0
	adds r1, #0xb6
	movs r2, #0
	movs r0, #5
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	strb r2, [r3]
_081D03F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d03fc
FUN_081d03fc: @ 0x081D03FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r7, #0
	ldr r0, _081D0480 @ =0x03000188
	ldr r1, [r0]
	adds r0, r7, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0x1e
	bgt _081D0418
	b _081D0552
_081D0418:
	adds r5, r7, #0
	adds r5, #0xba
	ldrb r0, [r5]
	movs r2, #0x70
	adds r2, r2, r7
	mov r8, r2
	cmp r0, #0
	beq _081D0452
	ldr r1, [r1, #0x18]
	adds r4, r7, #0
	adds r4, #0xb0
	ldrb r3, [r4]
	movs r0, #4
	str r0, [sp]
	mov r0, r8
	movs r2, #0
	bl FUN_08237040
	movs r0, #0
	strb r0, [r5]
	ldrh r0, [r4]
	cmp r0, #1
	bgt _081D0452
	cmp r0, #0
	blt _081D0452
	movs r0, #0xd6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081D0452:
	mov r4, r8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0484
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D048C
	.align 2, 0
_081D0480: .4byte 0x03000188
_081D0484:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D048C:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D04B0
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D04B8
_081D04B0:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D04B8:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D04F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D0536
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D04FA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D04F4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D0510
	.align 2, 0
_081D04F0: .4byte 0x0000FFFF
_081D04F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D050E
_081D04FA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D050E
	strh r1, [r4, #8]
	movs r2, #1
	b _081D0510
_081D050E:
	movs r2, #0
_081D0510:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D0538
	movs r0, #1
	strb r0, [r4, #7]
	b _081D0538
_081D0536:
	movs r2, #0
_081D0538:
	cmp r2, #0
	beq _081D0562
	ldr r0, [r6]
	movs r2, #1
	orrs r0, r2
	str r0, [r6]
	adds r0, r7, #0
	adds r0, #0xb6
	movs r1, #0
	strh r2, [r0]
	adds r0, #6
	str r1, [r0]
	b _081D056C
_081D0552:
	adds r0, r7, #0
	adds r0, #0x78
	ldrh r0, [r0]
	cmp r0, #1
	bne _081D0562
	adds r0, r7, #0
	bl FUN_081cfa24
_081D0562:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081D056C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d0578
FUN_081d0578: @ 0x081D0578
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r6, #0
	ldr r0, _081D060C @ =0x03000188
	ldr r2, [r0]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _081D05A2
	b _081D06F0
_081D05A2:
	adds r5, r6, #0
	adds r5, #0xba
	ldrb r0, [r5]
	movs r1, #0x70
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #0
	beq _081D05DC
	ldr r1, [r2, #0x18]
	adds r4, r6, #0
	adds r4, #0xb0
	ldrb r3, [r4]
	movs r0, #4
	str r0, [sp]
	mov r0, r8
	movs r2, #0
	bl FUN_08237040
	movs r0, #0
	strb r0, [r5]
	ldrh r0, [r4]
	cmp r0, #1
	bgt _081D05DC
	cmp r0, #0
	blt _081D05DC
	movs r0, #0xd6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081D05DC:
	mov r4, r8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0610
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D0618
	.align 2, 0
_081D060C: .4byte 0x03000188
_081D0610:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D0618:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D063C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D0644
_081D063C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D0644:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D067C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D06C2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D0686
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D0680
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D069C
	.align 2, 0
_081D067C: .4byte 0x0000FFFF
_081D0680:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D069A
_081D0686:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D069A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D069C
_081D069A:
	movs r2, #0
_081D069C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D06C4
	movs r0, #1
	strb r0, [r4, #7]
	b _081D06C4
_081D06C2:
	movs r2, #0
_081D06C4:
	cmp r2, #0
	beq _081D06F6
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	adds r2, r6, #0
	adds r2, #0xb6
	movs r1, #0
	movs r0, #3
	strh r0, [r2]
	adds r0, r6, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r2, #2
	ldrh r1, [r2]
	ldr r0, _081D06EC @ =0x0000FFBD
	ands r0, r1
	strh r0, [r2]
	b _081D0700
	.align 2, 0
_081D06EC: .4byte 0x0000FFBD
_081D06F0:
	adds r0, r6, #0
	bl FUN_081cfa24
_081D06F6:
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081D0700:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d070c
FUN_081d070c: @ 0x081D070C
	push {lr}
	bl FUN_081cf944
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d0718
FUN_081d0718: @ 0x081D0718
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r1, [r5]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	adds r4, r5, #0
	adds r4, #0x70
	ldr r1, [r0, #0x18]
	adds r0, r5, #0
	adds r0, #0xb0
	ldrb r3, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x78
	movs r3, #1
	strh r3, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x70]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0772
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D077A
_081D0772:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D077A:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D079E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D07A6
_081D079E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D07A6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D07DC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D0814
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D07E0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D07D6
	ldrb r0, [r4, #5]
_081D07D6:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D07F0
	.align 2, 0
_081D07DC: .4byte 0x0000FFFF
_081D07E0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D07F0
	strh r1, [r4, #8]
_081D07F0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D0814
	movs r0, #1
	strb r0, [r4, #7]
_081D0814:
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #6
	strh r0, [r1]
	adds r2, r5, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	ldr r0, _081D0834 @ =0x0000FFDF
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D0834: .4byte 0x0000FFDF

	thumb_func_start FUN_081d0838
FUN_081d0838: @ 0x081D0838
	adds r2, r1, #0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r3, r2, #0
	adds r3, #0xb6
	movs r1, #0
	movs r0, #3
	strh r0, [r3]
	adds r0, r2, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r2, #0xb8
	ldrh r1, [r2]
	ldr r0, _081D0860 @ =0x0000FFBD
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_081D0860: .4byte 0x0000FFBD

	thumb_func_start FUN_081d0864
FUN_081d0864: @ 0x081D0864
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _081D092C @ =0x03000188
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _081D0886
	bl FUN_081d0e20
	mov sl, r0
	cmp r0, #0
	bne _081D0886
	b _081D0B6C
_081D0886:
	mov r0, sl
	bl FUN_081cfc60
	adds r5, r0, #0
	cmp r5, #0
	bne _081D0894
	b _081D0B6C
_081D0894:
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r5, #0
	adds r1, #0x80
	str r1, [sp, #0x10]
	cmp r0, #0
	beq _081D08C8
	bl Script_GetValue
	ldr r2, [sp, #0x10]
	strh r0, [r2]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x82
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x84
	strh r0, [r1]
_081D08C8:
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r5, #0
	adds r4, #0x88
	strh r0, [r4]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x8a
	strh r0, [r1]
	movs r0, #0x47
	bl prepare_08231510
	str r4, [sp, #0x14]
	adds r7, r5, #0
	adds r7, #0x8c
	movs r1, #0xb0
	adds r1, r1, r5
	mov r8, r1
	movs r2, #0x1c
	add r2, sl
	mov sb, r2
	adds r1, r5, #0
	adds r1, #0x70
	str r1, [sp, #0x28]
	adds r2, r5, #0
	adds r2, #0xbb
	str r2, [sp, #0x24]
	adds r1, #0x4a
	str r1, [sp, #0x20]
	subs r2, #3
	str r2, [sp, #0x1c]
	subs r1, #8
	str r1, [sp, #0x18]
	cmp r0, #0
	beq _081D093A
	adds r6, r5, #0
	adds r6, #0x90
	movs r4, #5
_081D091E:
	bl VM_GetPC
	cmp r0, #0
	beq _081D0930
	bl Script_GetValue
	b _081D0932
	.align 2, 0
_081D092C: .4byte 0x03000188
_081D0930:
	movs r0, #0
_081D0932:
	stm r6!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D091E
_081D093A:
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r7]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081D096C
	adds r6, r5, #0
	adds r6, #0xa8
	movs r4, #1
_081D0954:
	bl VM_GetPC
	cmp r0, #0
	beq _081D0962
	bl Script_GetValue
	b _081D0964
_081D0962:
	movs r0, #0
_081D0964:
	stm r6!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D0954
_081D096C:
	movs r0, #0x54
	movs r1, #0
	bl Script_GetKeywordValue
	mov r2, r8
	strh r0, [r2]
	adds r1, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _081D0984
	movs r1, #4
_081D0984:
	mov r0, r8
	strh r1, [r0]
	adds r7, r5, #0
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r1, _081D09AC @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r5, #0x1c]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D09B0
	cmp r0, #1
	beq _081D09C0
	b _081D09C8
	.align 2, 0
_081D09AC: .4byte 0xFFFFFF00
_081D09B0:
	ldr r1, _081D09BC @ =0x00000282
	mov r0, sb
	bl FUN_0822b20c
	b _081D09C8
	.align 2, 0
_081D09BC: .4byte 0x00000282
_081D09C0:
	ldr r1, _081D0A14 @ =0x00000283
	mov r0, sb
	bl FUN_0822b20c
_081D09C8:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl FUN_0822a470
	mov r2, sl
	ldr r1, [r2, #0x18]
	mov r0, r8
	ldrb r3, [r0]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x28]
	movs r2, #0
	bl FUN_08236fac
	ldr r4, [sp, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x70]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0A18
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D0A20
	.align 2, 0
_081D0A14: .4byte 0x00000283
_081D0A18:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D0A20:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0A44
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D0A4C
_081D0A44:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D0A4C:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D0A84 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D0ABC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D0A88
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D0A7C
	ldrb r0, [r4, #5]
_081D0A7C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D0A98
	.align 2, 0
_081D0A84: .4byte 0x0000FFFF
_081D0A88:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D0A98
	strh r1, [r4, #8]
_081D0A98:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D0ABC
	movs r0, #1
	strb r0, [r4, #7]
_081D0ABC:
	ldr r0, [r7]
	movs r2, #1
	orrs r0, r2
	str r0, [r7]
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #7]
	ldr r0, [sp, #0x24]
	strb r1, [r0]
	ldr r0, [sp, #0x20]
	strb r1, [r0]
	ldr r1, [sp, #0x1c]
	strh r2, [r1]
	movs r0, #0x6f
	movs r1, #0x3c
	bl Script_GetKeywordValue
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D0B1E
	ldr r1, [sp, #0x1c]
	ldrh r0, [r1]
	movs r1, #0x10
	orrs r0, r1
	ldr r2, [sp, #0x1c]
	strh r0, [r2]
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D0B0C
	cmp r0, #1
	beq _081D0B16
	b _081D0B1E
_081D0B0C:
	mov r0, sl
	adds r1, r5, #0
	bl FUN_081d0838
	b _081D0B1E
_081D0B16:
	mov r0, sl
	adds r1, r5, #0
	bl FUN_081d0718
_081D0B1E:
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	bl FUN_081ee9bc
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D0B6C
	ldr r0, [sp, #0x1c]
	ldrh r1, [r0]
	movs r0, #8
	orrs r0, r1
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0x10]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0823b46c
	adds r0, r4, #0
	bl FUN_08002a48
_081D0B6C:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d0b7c
FUN_081d0b7c: @ 0x081D0B7C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D0B90 @ =0x03000188
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x38
	ldr r0, [r0, #0x68]
	cmp r0, #0
	bne _081D0B98
	b _081D0BCA
	.align 2, 0
_081D0B90: .4byte 0x03000188
_081D0B94:
	adds r0, r1, #0
	b _081D0BCC
_081D0B98:
	movs r3, #0
	movs r6, #1
	adds r4, r0, #0
	adds r2, r1, #0
_081D0BA0:
	adds r0, r6, #0
	lsls r0, r3
	ands r0, r4
	cmp r0, #0
	beq _081D0BAE
	movs r0, #1
	b _081D0BB0
_081D0BAE:
	movs r0, #0
_081D0BB0:
	cmp r0, #0
	beq _081D0BC2
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0x88
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r5
	beq _081D0B94
_081D0BC2:
	adds r2, #4
	adds r3, #1
	cmp r3, #0xb
	ble _081D0BA0
_081D0BCA:
	movs r0, #0
_081D0BCC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0bd4
FUN_081d0bd4: @ 0x081D0BD4
	push {r4, r5, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x69
	bl Script_GetKeywordValue
	adds r4, r0, #0
	cmp r4, #0
	blt _081D0C2C
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_081d0b7c
	adds r3, r0, #0
	cmp r3, #0
	beq _081D0C2C
	cmp r5, #1
	bne _081D0C18
	adds r2, r3, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, [r3]
	orrs r0, r5
	str r0, [r3]
	b _081D0C2C
_081D0C18:
	adds r2, r3, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	ldr r0, _081D0C34 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0xb6
	movs r0, #1
	strh r0, [r1]
_081D0C2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D0C34: .4byte 0x0000FDFF

	thumb_func_start FUN_081d0c38
FUN_081d0c38: @ 0x081D0C38
	push {lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x69
	bl Script_GetKeywordValue
	cmp r0, #0
	blt _081D0C60
	bl FUN_081d0b7c
	cmp r0, #0
	beq _081D0C60
	adds r0, #0xb8
	ldrh r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, r1
	beq _081D0C64
_081D0C60:
	movs r0, #0
	b _081D0C66
_081D0C64:
	movs r0, #1
_081D0C66:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0c6c
FUN_081d0c6c: @ 0x081D0C6C
	push {r4, lr}
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	bl FUN_081d0b7c
	adds r2, r0, #0
	cmp r2, #0
	beq _081D0CE6
	cmp r4, #0
	beq _081D0C94
	cmp r4, #1
	beq _081D0CC0
	b _081D0CE6
_081D0C94:
	adds r3, r2, #0
	adds r3, #0xb8
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _081D0CE6
	movs r0, #0x40
	orrs r0, r1
	ldr r1, _081D0CBC @ =0x0000FFDF
	ands r0, r1
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb6
	movs r0, #6
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	b _081D0CE6
	.align 2, 0
_081D0CBC: .4byte 0x0000FFDF
_081D0CC0:
	adds r3, r2, #0
	adds r3, #0xb8
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _081D0CE6
	movs r0, #0x20
	orrs r0, r1
	ldr r1, _081D0CEC @ =0x0000FFBF
	ands r0, r1
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb6
	movs r0, #3
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xba
	strb r4, [r0]
_081D0CE6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D0CEC: .4byte 0x0000FFBF

	thumb_func_start FUN_081d0cf0
FUN_081d0cf0: @ 0x081D0CF0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x38
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081D0D34 @ =0x030047A4
	ldr r1, _081D0D38 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081D0D7A
	movs r1, #4
	ldr r0, _081D0D3C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D0D7A
	ldr r0, [r6, #0x68]
	cmp r0, #0
	beq _081D0D7A
	movs r5, #0
	ldr r7, _081D0D40 @ =0x085AE098
	adds r4, r3, #0
_081D0D24:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x68]
	ands r0, r1
	cmp r0, #0
	beq _081D0D44
	movs r0, #1
	b _081D0D46
	.align 2, 0
_081D0D34: .4byte 0x030047A4
_081D0D38: .4byte 0x030047A0
_081D0D3C: .4byte 0x03002BC0
_081D0D40: .4byte 0x085AE098
_081D0D44:
	movs r0, #0
_081D0D46:
	cmp r0, #0
	beq _081D0D72
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081D0D72
	adds r0, r2, #0
	adds r0, #0xb6
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
_081D0D72:
	adds r4, #4
	adds r5, #1
	cmp r5, #0xb
	ble _081D0D24
_081D0D7A:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0d84
FUN_081d0d84: @ 0x081D0D84
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
_081D0D8A:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7, #0x68]
	ands r0, r1
	cmp r0, #0
	beq _081D0D9A
	movs r0, #1
	b _081D0D9C
_081D0D9A:
	movs r0, #0
_081D0D9C:
	cmp r0, #0
	beq _081D0DD4
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x38
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081D0DCE
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_081D0DCE:
	adds r0, r5, #0
	bl Free
_081D0DD4:
	adds r6, #1
	cmp r6, #0xb
	ble _081D0D8A
	ldr r1, _081D0DE8 @ =0x03000188
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D0DE8: .4byte 0x03000188

	thumb_func_start FUN_081d0dec
FUN_081d0dec: @ 0x081D0DEC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	ldr r1, _081D0E10 @ =0x0000A945
	bl FUN_0822b16c
	ldr r0, _081D0E14 @ =0x0000922E
	ldr r1, _081D0E18 @ =0x00000AE9
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D0E1C @ =0x03000188
	str r4, [r0]
	movs r0, #0
	str r0, [r4, #0x68]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D0E10: .4byte 0x0000A945
_081D0E14: .4byte 0x0000922E
_081D0E18: .4byte 0x00000AE9
_081D0E1C: .4byte 0x03000188

	thumb_func_start FUN_081d0e20
FUN_081d0e20: @ 0x081D0E20
	push {r4, lr}
	ldr r0, _081D0E54 @ =0x03000188
	ldr r0, [r0]
	cmp r0, #0
	bne _081D0E62
	movs r0, #8
	movs r1, #0x6c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D0E60
	ldr r1, _081D0E58 @ =FUN_081d0cf0
	ldr r2, _081D0E5C @ =FUN_081d0d84
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d0dec
	cmp r0, #0
	bge _081D0E60
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D0E62
	.align 2, 0
_081D0E54: .4byte 0x03000188
_081D0E58: .4byte FUN_081d0cf0
_081D0E5C: .4byte FUN_081d0d84
_081D0E60:
	adds r0, r4, #0
_081D0E62:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d0e68
FUN_081d0e68: @ 0x081D0E68
	ldr r1, _081D0E70 @ =0x03000188
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D0E70: .4byte 0x03000188

	thumb_func_start FUN_081d0e74
FUN_081d0e74: @ 0x081D0E74
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0xb6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d0e84
FUN_081d0e84: @ 0x081D0E84
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0xb6
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d0e94
FUN_081d0e94: @ 0x081D0E94
	push {lr}
	adds r0, #0xb6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D0EA4
	movs r0, #0
	b _081D0EA6
_081D0EA4:
	movs r0, #1
_081D0EA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0eac
FUN_081d0eac: @ 0x081D0EAC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081D0EC8 @ =0x0000097C
	adds r2, r3, r0
	movs r6, #1
_081D0EB8:
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D0ECC
	movs r0, #1
	b _081D0ECE
	.align 2, 0
_081D0EC8: .4byte 0x0000097C
_081D0ECC:
	movs r0, #0
_081D0ECE:
	cmp r0, #0
	bne _081D0EF8
	movs r0, #0xc8
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r3, r4
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #0xc8
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0xb4
	strh r5, [r0]
	adds r0, r4, #0
	b _081D0F00
_081D0EF8:
	adds r5, #1
	cmp r5, #0xb
	ble _081D0EB8
	movs r0, #0
_081D0F00:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0f08
FUN_081d0f08: @ 0x081D0F08
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081D0F18 @ =0x0300018C
	ldr r1, [r0]
	cmp r1, #0
	bne _081D0F20
	b _081D0F5A
	.align 2, 0
_081D0F18: .4byte 0x0300018C
_081D0F1C:
	adds r0, r1, #0
	b _081D0F5C
_081D0F20:
	movs r3, #0
	ldr r2, _081D0F40 @ =0x0000097C
	adds r0, r1, r2
	ldr r4, [r0]
	movs r6, #1
	adds r2, r1, #0
	adds r2, #0xda
	adds r1, #0x1c
_081D0F30:
	adds r0, r6, #0
	lsls r0, r3
	ands r0, r4
	cmp r0, #0
	beq _081D0F44
	movs r0, #1
	b _081D0F46
	.align 2, 0
_081D0F40: .4byte 0x0000097C
_081D0F44:
	movs r0, #0
_081D0F46:
	cmp r0, #0
	beq _081D0F50
	ldrh r0, [r2]
	cmp r0, r5
	beq _081D0F1C
_081D0F50:
	adds r2, #0xc8
	adds r1, #0xc8
	adds r3, #1
	cmp r3, #0xb
	ble _081D0F30
_081D0F5A:
	movs r0, #0
_081D0F5C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0f64
FUN_081d0f64: @ 0x081D0F64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _081D105C @ =0x0300018C
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _081D0F86
	bl FUN_081d16ec
	mov sb, r0
	cmp r0, #0
	bne _081D0F86
	b _081D11A6
_081D0F86:
	mov r0, sb
	bl FUN_081d0eac
	adds r6, r0, #0
	cmp r6, #0
	bne _081D0F94
	b _081D11A6
_081D0F94:
	mov r8, r6
	adds r4, r6, #0
	adds r4, #0x3c
	ldr r1, _081D1060 @ =0x0000BB68
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc6
	strb r2, [r0]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _081D0FD8
	bl Script_GetValue
	strh r0, [r6, #0x1c]
	bl Script_GetValue
	strh r0, [r6, #0x1e]
	bl Script_GetValue
	strh r0, [r6, #0x20]
_081D0FD8:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
	movs r0, #0x52
	movs r1, #2
	bl Script_GetKeywordValue
	strb r0, [r6, #7]
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r6, #0
	adds r5, #0xbc
	strb r0, [r5]
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xbe
	strh r0, [r1]
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xb2
	strh r0, [r1]
	movs r0, #0x73
	movs r1, #1
	bl Script_GetKeywordValue
	adds r4, r6, #0
	adds r4, #0xb6
	strh r0, [r4]
	movs r0, #0x6b
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r6, #0
	adds r7, #0xba
	strh r0, [r7]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	lsls r0, r0, #0x10
	mov sl, r4
	cmp r0, #0
	beq _081D104E
	adds r0, r6, #0
	movs r1, #4
	bl FUN_081d0e74
_081D104E:
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	beq _081D1064
	cmp r0, #1
	beq _081D1074
	b _081D107E
	.align 2, 0
_081D105C: .4byte 0x0300018C
_081D1060: .4byte 0x0000BB68
_081D1064:
	ldr r0, [r6, #0xc]
	ldr r1, _081D1070 @ =0x00000139
	bl FUN_0822b20c
	b _081D107E
	.align 2, 0
_081D1070: .4byte 0x00000139
_081D1074:
	ldr r0, [r6, #0xc]
	movs r1, #0x9d
	lsls r1, r1, #1
	bl FUN_0822b20c
_081D107E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D10A4
	adds r4, r6, #0
	adds r4, #0x2c
	mov r2, sb
	ldr r1, [r2, #0x18]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	b _081D10BA
_081D10A4:
	adds r4, r6, #0
	adds r4, #0x2c
	mov r0, sb
	ldr r1, [r0, #0x18]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_081D10BA:
	mov r2, sl
	ldrh r1, [r2]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D10F4
	mov r2, r8
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D1100
_081D10F4:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
_081D1100:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D1126
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D1130
_081D1126:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1130:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D1168 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D11A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D116C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1162
	ldrb r0, [r4, #5]
_081D1162:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D117C
	.align 2, 0
_081D1168: .4byte 0x0000FFFF
_081D116C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D117C
	strh r1, [r4, #8]
_081D117C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D11A0
	movs r0, #1
	strb r0, [r4, #7]
_081D11A0:
	adds r0, r6, #0
	bl FUN_081d1924
_081D11A6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d11b8
FUN_081d11b8: @ 0x081D11B8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _081D11E8 @ =0x0300018C
	ldr r5, [r0]
	movs r0, #0xa6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	cmp r0, #2
	bne _081D1200
	adds r2, r4, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D11EC
	movs r0, #0xfb
	ands r0, r1
	b _081D11F0
	.align 2, 0
_081D11E8: .4byte 0x0300018C
_081D11EC:
	movs r0, #4
	orrs r0, r1
_081D11F0:
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x33
	ldrb r0, [r0]
	ldrh r1, [r4, #0x3a]
	subs r0, r0, r1
	strh r0, [r4, #0x3a]
	b _081D1258
_081D1200:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D122E
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d0e84
	b _081D1250
_081D122E:
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r3, [r2]
	movs r2, #4
	orrs r2, r3
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081d0e84
_081D1250:
	adds r1, r4, #0
	adds r1, #0xb0
	movs r0, #2
	strh r0, [r1]
_081D1258:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d1260
FUN_081d1260: @ 0x081D1260
	push {r4, lr}
	adds r2, r0, #0
	mov ip, r2
	adds r3, r2, #0
	adds r3, #0xa4
	ldrh r0, [r3]
	cmp r0, #0
	beq _081D1282
	adds r4, r2, #0
	adds r4, #0x66
	ldrh r0, [r4]
	movs r1, #4
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r3]
	subs r0, #1
	b _081D128C
_081D1282:
	adds r3, r2, #0
	adds r3, #0x66
	ldrh r1, [r3]
	ldr r0, _081D12AC @ =0x0000FFFB
	ands r0, r1
_081D128C:
	strh r0, [r3]
	mov r4, ip
	adds r4, #0xbd
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D12B0
	ldr r0, [r2, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _081D12DA
	.align 2, 0
_081D12AC: .4byte 0x0000FFFB
_081D12B0:
	mov r0, ip
	adds r0, #0xba
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _081D12C2
	cmp r0, #1
	beq _081D12D0
	b _081D12DA
_081D12C2:
	ldr r0, [r2, #0xc]
	ldr r1, _081D12CC @ =0x00000139
	bl FUN_0822b20c
	b _081D12DA
	.align 2, 0
_081D12CC: .4byte 0x00000139
_081D12D0:
	ldr r0, [r2, #0xc]
	movs r1, #0x9d
	lsls r1, r1, #1
	bl FUN_0822b20c
_081D12DA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d12e0
FUN_081d12e0: @ 0x081D12E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_081d1260
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D131E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D1326
_081D131E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D1326:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D134A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D1352
_081D134A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1352:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D138C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D13D2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D1396
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1390
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D13AC
	.align 2, 0
_081D138C: .4byte 0x0000FFFF
_081D1390:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D13AA
_081D1396:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D13AA
	strh r1, [r4, #8]
	movs r2, #1
	b _081D13AC
_081D13AA:
	movs r2, #0
_081D13AC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D13D4
	movs r0, #1
	strb r0, [r4, #7]
	b _081D13D4
_081D13D2:
	movs r2, #0
_081D13D4:
	cmp r2, #0
	beq _081D145E
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1406
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x18]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081d0e74
	b _081D1424
_081D1406:
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x18]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d0e74
_081D1424:
	adds r1, r5, #0
	adds r1, #0xb0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc6
	strb r2, [r0]
	subs r0, #8
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	str r0, [sp, #8]
	add r1, sp, #0xc
	add r0, sp, #4
	str r0, [r1, #4]
	ldr r2, _081D1468 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r2, #2
	orrs r0, r2
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	bl Script_ExecById
_081D145E:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D1468: .4byte 0xFFFF0000

	thumb_func_start FUN_081d146c
FUN_081d146c: @ 0x081D146C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d1470
FUN_081d1470: @ 0x081D1470
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D14DA
	adds r0, r4, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D1494
	adds r0, r4, #0
	movs r1, #1
	b _081D1498
_081D1494:
	adds r0, r4, #0
	movs r1, #2
_081D1498:
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D14DA
	adds r2, r4, #0
	adds r2, #0x66
	ldrh r0, [r2]
	movs r1, #4
	orrs r1, r0
	strh r1, [r2]
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D14DA
	adds r0, r4, #0
	adds r0, #0xc2
	adds r1, r4, #0
	adds r1, #0xc4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081D14DA
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d11b8
_081D14DA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d14e0
FUN_081d14e0: @ 0x081D14E0
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xc6
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D1502
	adds r1, #0xc4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	strb r2, [r3]
_081D1502:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D1532
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D153A
_081D1532:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D153A:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D155E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D1566
_081D155E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1566:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D159C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D15D4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D15A0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1596
	ldrb r0, [r4, #5]
_081D1596:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D15B0
	.align 2, 0
_081D159C: .4byte 0x0000FFFF
_081D15A0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D15B0
	strh r1, [r4, #8]
_081D15B0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D15D4
	movs r0, #1
	strb r0, [r4, #7]
_081D15D4:
	adds r0, r5, #0
	bl FUN_081d1260
	adds r0, r5, #0
	bl FUN_081d1470
	adds r0, r5, #0
	bl FUN_081d1744
	adds r1, r5, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d15f8
FUN_081d15f8: @ 0x081D15F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d15fc
FUN_081d15fc: @ 0x081D15FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D162C @ =0x0000097C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D165A
	movs r4, #0
	ldr r0, _081D162C @ =0x0000097C
	adds r6, r5, r0
	ldr r1, _081D1630 @ =0x085AE0B8
	mov r8, r1
_081D161C:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D1634
	movs r0, #1
	b _081D1636
	.align 2, 0
_081D162C: .4byte 0x0000097C
_081D1630: .4byte 0x085AE0B8
_081D1634:
	movs r0, #0
_081D1636:
	cmp r0, #0
	beq _081D1654
	movs r0, #0xc8
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D1654:
	adds r4, #1
	cmp r4, #0xb
	ble _081D161C
_081D165A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d1668
FUN_081d1668: @ 0x081D1668
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _081D1684 @ =0x0000097C
	adds r7, r6, r0
_081D1672:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D1688
	movs r0, #1
	b _081D168A
	.align 2, 0
_081D1684: .4byte 0x0000097C
_081D1688:
	movs r0, #0
_081D168A:
	cmp r0, #0
	beq _081D16A6
	movs r0, #0xc8
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r6, r4
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x60
	adds r0, r4, #0
	bl FUN_08236424
_081D16A6:
	adds r5, #1
	cmp r5, #0xb
	ble _081D1672
	ldr r1, _081D16B8 @ =0x0300018C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D16B8: .4byte 0x0300018C

	thumb_func_start FUN_081d16bc
FUN_081d16bc: @ 0x081D16BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D16DC @ =0x0000922E
	ldr r1, _081D16E0 @ =0x0000B952
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D16E4 @ =0x0300018C
	str r4, [r0]
	ldr r0, _081D16E8 @ =0x0000097C
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D16DC: .4byte 0x0000922E
_081D16E0: .4byte 0x0000B952
_081D16E4: .4byte 0x0300018C
_081D16E8: .4byte 0x0000097C

	thumb_func_start FUN_081d16ec
FUN_081d16ec: @ 0x081D16EC
	push {r4, lr}
	ldr r0, _081D1724 @ =0x0300018C
	ldr r0, [r0]
	cmp r0, #0
	bne _081D1732
	movs r1, #0x98
	lsls r1, r1, #4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D1730
	ldr r1, _081D1728 @ =FUN_081d15fc
	ldr r2, _081D172C @ =FUN_081d1668
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d16bc
	cmp r0, #0
	bge _081D1730
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D1732
	.align 2, 0
_081D1724: .4byte 0x0300018C
_081D1728: .4byte FUN_081d15fc
_081D172C: .4byte FUN_081d1668
_081D1730:
	adds r0, r4, #0
_081D1732:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d1738
FUN_081d1738: @ 0x081D1738
	ldr r1, _081D1740 @ =0x0300018C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D1740: .4byte 0x0300018C

	thumb_func_start FUN_081d1744
FUN_081d1744: @ 0x081D1744
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0xc7
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D1762
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x5c]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _081D17B0
_081D1762:
	ldr r6, _081D17BC @ =0x0203B400
	ldr r4, _081D17C0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D17C4 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	adds r1, r7, #0
	adds r1, #0x58
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	adds r1, r7, #0
	adds r1, #0x5c
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x20]
	mov r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081D17B0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D17BC: .4byte 0x0203B400
_081D17C0: .4byte 0x030046B8
_081D17C4: .4byte 0x000003FF

	thumb_func_start FUN_081d17c8
FUN_081d17c8: @ 0x081D17C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r4, r0, #0
	adds r7, r2, #0
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D1806
	adds r0, r7, #0
	adds r0, #0xba
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r5, r0, #0
	cmp r1, #1
	bne _081D17F8
	movs r1, #4
	b _081D17FE
_081D17F8:
	cmp r1, #0
	bne _081D1820
	movs r1, #0x17
_081D17FE:
	ldr r0, [r4, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081D1820
_081D1806:
	adds r4, r7, #0
	adds r4, #0xc7
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D1816
	ldr r0, _081D181C @ =0x0000014D
	bl PlaySound_082406e0
_081D1816:
	movs r0, #0xa
	strb r0, [r4]
	b _081D18FA
	.align 2, 0
_081D181C: .4byte 0x0000014D
_081D1820:
	adds r1, r7, #0
	adds r1, #0xa4
	ldrh r4, [r1]
	cmp r4, #0
	bne _081D18FA
	adds r0, r7, #0
	adds r0, #0xbd
	movs r2, #3
	strb r2, [r0]
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_081d11b8
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne _081D18E4
	add r6, sp, #0x10
	str r4, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r6, #0
	ldr r2, _081D190C @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r6, #2]
	ldr r5, _081D1910 @ =0x0203B400
	ldr r2, _081D1914 @ =0x030046B8
	mov sl, r2
	ldr r2, [r2]
	adds r2, #1
	ldr r4, _081D1918 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #3
	mov r8, r1
	mov r1, r8
	ands r0, r1
	adds r0, #0xf
	ldr r1, _081D191C @ =0xFFFF0000
	mov sb, r1
	ldr r3, [sp, #0x18]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r0, _081D1920 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	mov r0, r8
	ands r1, r0
	adds r1, #0xf
	mov r8, r1
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	mov r1, sb
	ands r0, r1
	mov r1, r8
	orrs r0, r1
	str r0, [r3, #4]
	adds r2, #1
	ands r2, r4
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r2, r7, #0
	adds r2, #0x1c
	str r3, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xf
	str r1, [sp, #8]
	movs r1, #0x11
	adds r3, r6, #0
	bl FUN_08014730
_081D18E4:
	adds r0, r7, #0
	movs r1, #8
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D18FA
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_081d0e74
_081D18FA:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D190C: .4byte 0x05000002
_081D1910: .4byte 0x0203B400
_081D1914: .4byte 0x030046B8
_081D1918: .4byte 0x000003FF
_081D191C: .4byte 0xFFFF0000
_081D1920: .4byte 0x0000FFFF

	thumb_func_start FUN_081d1924
FUN_081d1924: @ 0x081D1924
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x60
	ldr r2, _081D1998 @ =0xFFFF0000
	ldr r5, _081D199C @ =0x0000FFFF
	movs r1, #0x80
	lsls r1, r1, #0x10
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r6, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D19A0 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081D19A4 @ =FUN_081d17c8
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1998: .4byte 0xFFFF0000
_081D199C: .4byte 0x0000FFFF
_081D19A0: .4byte 0x00004001
_081D19A4: .4byte FUN_081d17c8

	thumb_func_start FUN_081d19a8
FUN_081d19a8: @ 0x081D19A8
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D19C4
	bl FUN_081d0f08
	cmp r0, #0
	beq _081D19C4
	adds r0, #0xb6
	ldrh r0, [r0]
	b _081D19C8
_081D19C4:
	movs r0, #1
	rsbs r0, r0, #0
_081D19C8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081d19cc
FUN_081d19cc: @ 0x081D19CC
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D19F2
	bl FUN_081d0f08
	adds r4, r0, #0
	cmp r4, #0
	beq _081D19F2
	movs r1, #0x18
	bl FUN_081d0e74
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081d0e84
_081D19F2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d19f8
FUN_081d19f8: @ 0x081D19F8
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D1A74
	bl FUN_081d0f08
	adds r4, r0, #0
	cmp r4, #0
	beq _081D1A74
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D1A48
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D1A74
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d11b8
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_081d0e74
	b _081D1A74
_081D1A48:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D1A74
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D1A74
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d11b8
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_081d0e74
_081D1A74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d1a7c
FUN_081d1a7c: @ 0x081D1A7C
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D1A98
	bl FUN_081d0f08
	cmp r0, #0
	beq _081D1A98
	movs r1, #0x10
	bl FUN_081d0e84
_081D1A98:
	pop {r0}
	bx r0

	thumb_func_start FUN_081d1a9c
FUN_081d1a9c: @ 0x081D1A9C
	push {r4, r5, r6, lr}
	movs r2, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r3, r0, r1
	movs r6, #1
	adds r4, r0, #0
	adds r4, #0x94
	adds r5, r0, #0
	adds r5, #0x18
_081D1AB0:
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081D1AC0
	movs r0, #1
	b _081D1AC2
_081D1AC0:
	movs r0, #0
_081D1AC2:
	cmp r0, #0
	bne _081D1AD6
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	strh r2, [r4]
	adds r0, r5, #0
	b _081D1AE2
_081D1AD6:
	adds r4, #0x88
	adds r5, #0x88
	adds r2, #1
	cmp r2, #7
	ble _081D1AB0
	movs r0, #0
_081D1AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d1ae8
FUN_081d1ae8: @ 0x081D1AE8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d1aec
FUN_081d1aec: @ 0x081D1AEC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x58
	ldr r0, _081D1B0C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D1B10
	movs r0, #1
	b _081D1B12
	.align 2, 0
_081D1B0C: .4byte 0x030046A0
_081D1B10:
	movs r0, #0
_081D1B12:
	cmp r0, #0
	bne _081D1B22
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	b _081D1B2E
_081D1B22:
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
_081D1B2E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d1b34
FUN_081d1b34: @ 0x081D1B34
	push {lr}
	sub sp, #0x30
	adds r1, r0, #0
	adds r0, #0x80
	ldrh r2, [r0]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081D1BA0
	adds r2, r1, #0
	adds r2, #0x4c
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D1BF2
	adds r0, r1, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, [r1, #0x5c]
	str r0, [sp, #4]
	ldr r0, [r1, #0x60]
	str r0, [sp, #8]
	ldr r0, [r1, #0x64]
	str r0, [sp, #0xc]
	ldr r0, [r1, #0x68]
	str r0, [sp, #0x10]
	ldr r0, [r1, #0x6c]
	str r0, [sp, #0x14]
	ldr r0, [r1, #0x70]
	str r0, [sp, #0x18]
	ldr r0, [r1, #0x74]
	str r0, [sp, #0x1c]
	ldr r0, [r1, #0x78]
	str r0, [sp, #0x20]
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _081D1B9C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
	b _081D1BF2
	.align 2, 0
_081D1B9C: .4byte 0xFFFF0000
_081D1BA0:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081D1BF2
	adds r2, r1, #0
	adds r2, #0x4e
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D1BF2
	adds r0, r1, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, [r1, #0x5c]
	str r0, [sp, #4]
	ldr r0, [r1, #0x60]
	str r0, [sp, #8]
	ldr r0, [r1, #0x64]
	str r0, [sp, #0xc]
	ldr r0, [r1, #0x68]
	str r0, [sp, #0x10]
	ldr r0, [r1, #0x6c]
	str r0, [sp, #0x14]
	ldr r0, [r1, #0x70]
	str r0, [sp, #0x18]
	ldr r0, [r1, #0x74]
	str r0, [sp, #0x1c]
	ldr r0, [r1, #0x78]
	str r0, [sp, #0x20]
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	movs r0, #0xa
	add r1, sp, #0x28
	strh r0, [r1]
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D1BF2:
	add sp, #0x30
	pop {r0}
	bx r0

	thumb_func_start FUN_081d1bf8
FUN_081d1bf8: @ 0x081D1BF8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x5a
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x80
	ldrh r1, [r5]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _081D1C5A
	movs r0, #2
	orrs r0, r1
	movs r1, #0
	orrs r0, r1
	ldr r1, _081D1C4C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d1b34
	strh r6, [r4, #0x10]
	ldr r0, [r4, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1C54
	ldr r0, _081D1C50 @ =0x00000389
	bl PlaySound_082406e0
	b _081D1C5A
	.align 2, 0
_081D1C4C: .4byte 0x0000FFFE
_081D1C50: .4byte 0x00000389
_081D1C54:
	ldr r0, _081D1C60 @ =0x00000155
	bl PlaySound_082406e0
_081D1C5A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1C60: .4byte 0x00000155

	thumb_func_start FUN_081d1c64
FUN_081d1c64: @ 0x081D1C64
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x80
	ldrh r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D1CD2
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	ldr r1, _081D1CB4 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r6]
	adds r0, r5, #0
	bl FUN_081d1b34
	strh r4, [r5, #0x10]
	ldr r0, [r5, #0xc]
	ldr r1, _081D1CB8 @ =0x0000011F
	bl FUN_0822b20c
	ldr r0, _081D1CBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081D1CCA
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1CC4
	ldr r0, _081D1CC0 @ =0x00000389
	bl PlaySound_082406e0
	b _081D1CCA
	.align 2, 0
_081D1CB4: .4byte 0x0000FFFD
_081D1CB8: .4byte 0x0000011F
_081D1CBC: .4byte 0x030047A4
_081D1CC0: .4byte 0x00000389
_081D1CC4:
	ldr r0, _081D1CD8 @ =0x00000155
	bl PlaySound_082406e0
_081D1CCA:
	adds r1, r5, #0
	adds r1, #0x5a
	movs r0, #0
	strh r0, [r1]
_081D1CD2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1CD8: .4byte 0x00000155

	thumb_func_start FUN_081d1cdc
FUN_081d1cdc: @ 0x081D1CDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	bl FUN_0823b3ec
	adds r3, r0, #0
	cmp r3, #0
	beq _081D1DDC
	movs r0, #0
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x82
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D1D04
	mov r5, sb
	strb r5, [r1]
_081D1D04:
	ldr r4, [r3, #0x18]
	cmp r4, #0
	beq _081D1DBA
	mov r7, sp
	movs r0, #0x1c
	adds r0, r0, r6
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #0x11
	mov r8, r1
_081D1D18:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081D1DB4
	ldr r0, _081D1DAC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081D1D4A
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _081D1D4A
	ldr r0, _081D1DB0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081D1DB4
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D1DB4
_081D1D4A:
	adds r3, r4, #0
	adds r3, #8
	ldrh r2, [r4, #8]
	ldrh r0, [r6, #0x1c]
	subs r2, r2, r0
	strh r2, [r7]
	ldrh r1, [r3, #2]
	mov r5, ip
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r7, #2]
	ldrh r1, [r3, #4]
	mov r3, ip
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	lsls r2, r2, #0x10
	mov r0, r8
	lsrs r3, r0, #0x10
	cmp r2, r8
	bhi _081D1DB4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	bgt _081D1DB4
	cmp r0, #0
	blt _081D1DB4
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bgt _081D1DB4
	cmp r0, #0
	blt _081D1DB4
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081d1bf8
	adds r2, r6, #0
	adds r2, #0x84
	ldrh r1, [r2]
	adds r0, r6, #0
	adds r0, #0x86
	ldrh r0, [r0]
	subs r0, #1
	cmp r1, r0
	bge _081D1DDC
	adds r0, r1, #1
	b _081D1DDA
	.align 2, 0
_081D1DAC: .4byte 0x030047A4
_081D1DB0: .4byte 0x03002BE0
_081D1DB4:
	ldr r4, [r4, #0x40]
	cmp r4, #0
	bne _081D1D18
_081D1DBA:
	mov r1, sb
	cmp r1, #0
	bne _081D1DDC
	adds r2, r6, #0
	adds r2, #0x84
	adds r1, r6, #0
	adds r1, #0x86
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	blo _081D1DD8
	adds r0, r6, #0
	bl FUN_081d1c64
	b _081D1DDC
_081D1DD8:
	adds r0, #1
_081D1DDA:
	strh r0, [r2]
_081D1DDC:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d1dec
FUN_081d1dec: @ 0x081D1DEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r0, _081D1E64 @ =0x03000190
	ldr r0, [r0]
	cmp r0, #0
	bne _081D1E0A
	bl FUN_081d2180
	cmp r0, #0
	bne _081D1E0A
	b _081D209C
_081D1E0A:
	bl FUN_081d1a9c
	adds r6, r0, #0
	cmp r6, #0
	bne _081D1E16
	b _081D209C
_081D1E16:
	adds r1, r6, #0
	adds r1, #0x7e
	movs r0, #1
	strh r0, [r1]
	mov sl, r6
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _081D1E3C
	bl Script_GetValue
	strh r0, [r6, #0x1c]
	bl Script_GetValue
	strh r0, [r6, #0x1e]
	bl Script_GetValue
	strh r0, [r6, #0x20]
_081D1E3C:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sl
	adds r1, #0x48
	strh r0, [r1]
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _081D1E86
	bl VM_GetPC
	cmp r0, #0
	beq _081D1E68
	bl Script_GetValue
	adds r1, r0, #0
	b _081D1E6A
	.align 2, 0
_081D1E64: .4byte 0x03000190
_081D1E68:
	movs r1, #0
_081D1E6A:
	adds r0, r6, #0
	adds r0, #0x4c
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081D1E7E
	bl Script_GetValue
	b _081D1E80
_081D1E7E:
	movs r0, #0
_081D1E80:
	adds r1, r6, #0
	adds r1, #0x4e
	strh r0, [r1]
_081D1E86:
	movs r0, #0x53
	bl prepare_08231510
	adds r7, r6, #0
	adds r7, #0x4a
	movs r1, #0x2c
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0x80
	adds r2, r2, r6
	mov sb, r2
	adds r3, r6, #0
	adds r3, #0x84
	str r3, [sp, #0x10]
	adds r5, r6, #0
	adds r5, #0x86
	str r5, [sp, #0x14]
	mov r1, sl
	adds r1, #0x1c
	str r1, [sp, #0x18]
	adds r2, r6, #0
	adds r2, #0x58
	str r2, [sp, #0x1c]
	subs r3, #1
	str r3, [sp, #0xc]
	subs r5, #4
	str r5, [sp, #8]
	cmp r0, #0
	beq _081D1EDC
	subs r5, #0x26
	movs r4, #3
_081D1EC4:
	bl VM_GetPC
	cmp r0, #0
	beq _081D1ED2
	bl Script_GetValue
	b _081D1ED4
_081D1ED2:
	movs r0, #0
_081D1ED4:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D1EC4
_081D1EDC:
	movs r0, #0x57
	bl prepare_08231510
	cmp r0, #0
	beq _081D1F04
	adds r5, r6, #0
	adds r5, #0x6c
	movs r4, #3
_081D1EEC:
	bl VM_GetPC
	cmp r0, #0
	beq _081D1EFA
	bl Script_GetValue
	b _081D1EFC
_081D1EFA:
	movs r0, #0
_081D1EFC:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D1EEC
_081D1F04:
	movs r0, #0x54
	movs r1, #0
	bl Script_GetKeywordValue
	movs r5, #0
	movs r4, #0
	strh r0, [r7]
	ldrh r1, [r7]
	mov r0, r8
	bl FUN_0822b16c
	mov r0, sb
	strh r4, [r0]
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _081D1F38
	mov r1, sb
	ldrh r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, sb
	strh r0, [r2]
	b _081D1F42
_081D1F38:
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #2
	orrs r0, r1
	strh r0, [r3]
_081D1F42:
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _081D1F58
	mov r5, sb
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
_081D1F58:
	mov r0, sl
	mov r1, r8
	movs r2, #0
	bl FUN_0822a470
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _081D1F84
	movs r0, #1
	mov r1, sl
	strh r0, [r1, #0x10]
	ldr r0, [r6, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _081D1F90
_081D1F84:
	mov r2, sl
	strh r0, [r2, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, _081D1F9C @ =0x0000011F
	bl FUN_0822b20c
_081D1F90:
	bl FUN_0823b3ec
	cmp r0, #0
	bne _081D1FD0
	b _081D203C
	.align 2, 0
_081D1F9C: .4byte 0x0000011F
_081D1FA0:
	ldrh r0, [r4]
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #2
	orrs r0, r1
	ldr r1, _081D1FCC @ =0x0000FFFE
	ands r0, r1
	strh r0, [r3]
	mov r0, ip
	ldr r5, [sp, #0x10]
	strh r0, [r5]
	movs r0, #1
	strh r0, [r6, #0x10]
	ldr r0, [r6, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _081D203C
	.align 2, 0
_081D1FCC: .4byte 0x0000FFFE
_081D1FD0:
	bl FUN_0823b3ec
	ldr r4, [r0, #0x18]
	cmp r4, #0
	beq _081D203C
	mov r7, sp
	movs r1, #0x1c
	adds r1, r1, r6
	mov r8, r1
_081D1FE2:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp r0, #0
	bne _081D2036
	adds r3, r4, #0
	adds r3, #8
	ldrh r2, [r4, #8]
	ldrh r0, [r6, #0x1c]
	subs r2, r2, r0
	strh r2, [r7]
	ldrh r1, [r3, #2]
	mov r5, r8
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r7, #2]
	ldrh r1, [r3, #4]
	mov r3, r8
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	lsls r2, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsrs r3, r0, #0x10
	cmp r2, r0
	bhi _081D2036
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	bgt _081D2036
	cmp r0, #0
	blt _081D2036
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bgt _081D2036
	cmp r0, #0
	bge _081D1FA0
_081D2036:
	ldr r4, [r4, #0x40]
	cmp r4, #0
	bne _081D1FE2
_081D203C:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	movs r1, #0
	ldr r2, [sp, #0x14]
	strh r0, [r2]
	ldr r3, [sp, #0x10]
	strh r1, [r3]
	ldr r0, [sp, #0x18]
	bl FUN_08241574
	ldr r5, [sp, #0x1c]
	strh r0, [r5]
	ldr r0, _081D2070 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r2, [r5]
	cmp r0, r2
	bne _081D2074
	movs r0, #1
	b _081D2076
	.align 2, 0
_081D2070: .4byte 0x030046A0
_081D2074:
	movs r0, #0
_081D2076:
	cmp r0, #0
	bne _081D2086
	mov r3, sl
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	b _081D2092
_081D2086:
	mov r5, sl
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_081D2092:
	movs r0, #0
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	ldr r2, [sp, #8]
	strb r0, [r2]
_081D209C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d20ac
FUN_081d20ac: @ 0x081D20AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x18
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _081D2118
	movs r6, #0
	movs r0, #0x8b
	lsls r0, r0, #3
	adds r7, r1, r0
	ldr r3, _081D20E8 @ =0x085AE0C8
	mov r8, r3
	adds r5, r1, #0
	adds r5, #0x96
	adds r4, r2, #0
_081D20D6:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D20EC
	movs r0, #1
	b _081D20EE
	.align 2, 0
_081D20E8: .4byte 0x085AE0C8
_081D20EC:
	movs r0, #0
_081D20EE:
	cmp r0, #0
	beq _081D210E
	adds r0, r4, #0
	bl FUN_081d1aec
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D210E
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081D210E:
	adds r5, #0x88
	adds r4, #0x88
	adds r6, #1
	cmp r6, #7
	ble _081D20D6
_081D2118:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d2124
FUN_081d2124: @ 0x081D2124
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x18
_081D2132:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D2142
	movs r0, #1
	b _081D2144
_081D2142:
	movs r0, #0
_081D2144:
	cmp r0, #0
	beq _081D214E
	adds r0, r4, #0
	bl FUN_0822a4e0
_081D214E:
	adds r4, #0x88
	adds r5, #1
	cmp r5, #7
	ble _081D2132
	movs r1, #0
	ldr r0, _081D2164 @ =0x03000190
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081D2164: .4byte 0x03000190

	thumb_func_start FUN_081d2168
FUN_081d2168: @ 0x081D2168
	ldr r1, _081D217C @ =0x03000190
	str r0, [r1]
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_081D217C: .4byte 0x03000190

	thumb_func_start FUN_081d2180
FUN_081d2180: @ 0x081D2180
	push {r4, lr}
	ldr r0, _081D21B4 @ =0x03000190
	ldr r0, [r0]
	cmp r0, #0
	bne _081D21C6
	ldr r1, _081D21B8 @ =0x0000045C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D21C4
	ldr r1, _081D21BC @ =FUN_081d20ac
	ldr r2, _081D21C0 @ =FUN_081d2124
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d2168
	cmp r0, #0
	bge _081D21C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D21C6
	.align 2, 0
_081D21B4: .4byte 0x03000190
_081D21B8: .4byte 0x0000045C
_081D21BC: .4byte FUN_081d20ac
_081D21C0: .4byte FUN_081d2124
_081D21C4:
	adds r0, r4, #0
_081D21C6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d21cc
FUN_081d21cc: @ 0x081D21CC
	ldr r1, _081D21D4 @ =0x03000190
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D21D4: .4byte 0x03000190

	thumb_func_start FUN_081d21d8
FUN_081d21d8: @ 0x081D21D8
	push {lr}
	adds r1, r0, #0
	adds r0, #0xd6
	ldrh r2, [r0]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _081D2226
	adds r0, r1, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	cmp r0, #2
	bgt _081D21FC
	cmp r0, #1
	bge _081D2212
	cmp r0, #0
	beq _081D2208
	b _081D2220
_081D21FC:
	cmp r0, #3
	bne _081D2220
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081D2212
_081D2208:
	movs r0, #0xac
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D2226
_081D2212:
	ldr r0, _081D221C @ =0x00000261
	bl PlaySound_082406e0
	b _081D2226
	.align 2, 0
_081D221C: .4byte 0x00000261
_081D2220:
	ldr r0, _081D222C @ =0x00000261
	bl PlaySound_082406e0
_081D2226:
	pop {r0}
	bx r0
	.align 2, 0
_081D222C: .4byte 0x00000261

	thumb_func_start FUN_081d2230
FUN_081d2230: @ 0x081D2230
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov ip, r0
	ldr r0, _081D2254 @ =0x03000194
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	beq _081D22FE
	ldr r1, _081D2258 @ =0x000012AC
	add r1, sb
	ldr r0, [r1]
	cmp r0, #0
	bne _081D2264
	b _081D22FE
	.align 2, 0
_081D2254: .4byte 0x03000194
_081D2258: .4byte 0x000012AC
_081D225C:
	mov r0, r8
	adds r0, #0x1c
	add r0, sb
	b _081D2300
_081D2264:
	movs r7, #0
	mov sl, r1
	mov r6, sp
	movs r0, #0
	mov r8, r0
_081D226E:
	movs r1, #1
	lsls r1, r7
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D2280
	movs r0, #1
	b _081D2282
_081D2280:
	movs r0, #0
_081D2282:
	cmp r0, #0
	beq _081D22F2
	mov r3, sp
	mov r2, r8
	add r2, sb
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r2, r2, r4
	mov r5, ip
	ldrh r0, [r5]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r5, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r5, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	str r1, [sp, #8]
	strh r1, [r3, #4]
	ldr r2, _081D2310 @ =0x085AE0D0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D22F2
	cmn r1, r0
	blt _081D22F2
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #2
	ldrsh r1, [r3, r5]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D22F2
	ldr r5, [sp, #8]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D225C
_081D22F2:
	movs r4, #0xc6
	lsls r4, r4, #1
	add r8, r4
	adds r7, #1
	cmp r7, #0xb
	ble _081D226E
_081D22FE:
	movs r0, #0
_081D2300:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D2310: .4byte 0x085AE0D0

	thumb_func_start FUN_081d2314
FUN_081d2314: @ 0x081D2314
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r1, _081D233C @ =0x000012AC
	adds r3, r0, r1
	movs r7, #1
	adds r4, r0, #0
	adds r4, #0xcc
	adds r5, r0, #0
	adds r5, #0x1c
	movs r6, #0xc6
	lsls r6, r6, #1
_081D232A:
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081D2340
	movs r0, #1
	b _081D2342
	.align 2, 0
_081D233C: .4byte 0x000012AC
_081D2340:
	movs r0, #0
_081D2342:
	cmp r0, #0
	bne _081D2356
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	strh r2, [r4]
	adds r0, r5, #0
	b _081D2362
_081D2356:
	adds r4, r4, r6
	adds r5, r5, r6
	adds r2, #1
	cmp r2, #0xb
	ble _081D232A
	movs r0, #0
_081D2362:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d2368
FUN_081d2368: @ 0x081D2368
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xb8
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081D2388
	subs r0, r2, #1
	b _081D2644
_081D2388:
	adds r0, r5, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsrs r6, r0, #6
	cmp r6, #1
	beq _081D23C8
	cmp r6, #1
	bgt _081D239E
	cmp r6, #0
	beq _081D23A8
	b _081D2646
_081D239E:
	cmp r6, #2
	beq _081D23E0
	cmp r6, #3
	beq _081D2410
	b _081D2646
_081D23A8:
	add r0, sp, #0x38
	ldr r1, _081D23C0 @ =0x0000FF40
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r6, [r0, #4]
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	adds r1, r0, #0
	ldr r0, _081D23C4 @ =0x0000FF80
	strh r0, [r1, #0xc]
	movs r0, #0x3e
	b _081D242C
	.align 2, 0
_081D23C0: .4byte 0x0000FF40
_081D23C4: .4byte 0x0000FF80
_081D23C8:
	add r0, sp, #0x38
	ldr r2, _081D23D8 @ =0x0000FFC0
	strh r2, [r0]
	ldr r3, _081D23DC @ =0x0000FF40
	strh r3, [r0, #2]
	strh r2, [r0, #4]
	adds r1, r0, #0
	b _081D2420
	.align 2, 0
_081D23D8: .4byte 0x0000FFC0
_081D23DC: .4byte 0x0000FF40
_081D23E0:
	add r0, sp, #0x38
	ldr r3, _081D2404 @ =0x0000FF7C
	strh r3, [r0]
	ldr r2, _081D2408 @ =0x0000FF40
	strh r2, [r0, #2]
	adds r1, r0, #0
	ldr r0, _081D240C @ =0x0000FFE0
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r3, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x3e
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x18
	b _081D2434
	.align 2, 0
_081D2404: .4byte 0x0000FF7C
_081D2408: .4byte 0x0000FF40
_081D240C: .4byte 0x0000FFE0
_081D2410:
	add r1, sp, #0x38
	ldr r0, _081D2448 @ =0x0000FFC0
	strh r0, [r1]
	adds r0, r1, #0
	ldr r3, _081D244C @ =0x0000FF40
	strh r3, [r0, #2]
	ldr r2, _081D2450 @ =0x0000FFE0
	strh r2, [r0, #4]
_081D2420:
	ldr r0, _081D2454 @ =0x0000FF24
	strh r0, [r1, #8]
	adds r0, r1, #0
	strh r3, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x40
_081D242C:
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x20
_081D2434:
	mov sb, r3
	adds r0, r5, #0
	adds r0, #0xe7
	ldrb r7, [r0]
	cmp r7, #0
	beq _081D2458
	cmp r7, #3
	bne _081D2446
	b _081D254A
_081D2446:
	b _081D2646
	.align 2, 0
_081D2448: .4byte 0x0000FFC0
_081D244C: .4byte 0x0000FF40
_081D2450: .4byte 0x0000FFE0
_081D2454: .4byte 0x0000FF24
_081D2458:
	movs r0, #0xca
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D24EC
	adds r1, r5, #0
	adds r1, #0xfc
	add r0, sp, #0x38
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D24E4 @ =0xFFFF0000
	ldr r2, [sp, #0x48]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x48]
	adds r4, r5, #0
	adds r4, #0xfe
	add r0, sp, #0x38
	ldrh r1, [r0, #2]
	ldrh r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _081D24E8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	add r0, sp, #0x38
	ldrh r2, [r0, #4]
	ldrh r1, [r1]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x48
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	b _081D263E
	.align 2, 0
_081D24E4: .4byte 0xFFFF0000
_081D24E8: .4byte 0x0000FFFF
_081D24EC:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r5, r3
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	mov r0, r8
	strh r7, [r0]
	b _081D263E
_081D254A:
	movs r1, #0xca
	adds r1, r1, r5
	mov r8, r1
	ldrh r3, [r1]
	cmp r3, #0
	bne _081D25D0
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #2]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _081D25C8 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D25CC @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	movs r0, #1
	mov r3, r8
	strh r0, [r3]
	b _081D263E
	.align 2, 0
_081D25C8: .4byte 0x0000F422
_081D25CC: .4byte 0x0000121B
_081D25D0:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	movs r4, #0
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r3, sb
	str r3, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r4, [sp, #0x20]
	ldr r1, _081D2658 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D265C @ =0x0000121B
	str r1, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	mov r3, r8
	strh r4, [r3]
_081D263E:
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #4
_081D2644:
	strh r0, [r1]
_081D2646:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2658: .4byte 0x0000F422
_081D265C: .4byte 0x0000121B

	thumb_func_start FUN_081d2660
FUN_081d2660: @ 0x081D2660
	push {r4, r5, r6, r7, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, [r0, #8]
	ldrh r4, [r0]
	movs r2, #0
	ldrsh r3, [r1, r2]
	ldrh r2, [r0, #2]
	movs r7, #4
	ldrsh r0, [r1, r7]
	subs r2, r2, r0
	subs r4, r4, r3
	cmp r4, #0
	bge _081D267E
	rsbs r4, r4, #0
_081D267E:
	cmp r4, r5
	bhi _081D2690
	cmp r2, #0
	bge _081D2688
	rsbs r2, r2, #0
_081D2688:
	cmp r2, r6
	bhi _081D2690
	movs r0, #1
	b _081D2692
_081D2690:
	movs r0, #0
_081D2692:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d2698
FUN_081d2698: @ 0x081D2698
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	adds r0, r6, #0
	movs r1, #8
	bl ClearMemory
	ldr r2, [r4, #8]
	ldrh r1, [r2]
	movs r3, #8
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	ldrh r1, [r2, #2]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _081D26C4
	rsbs r0, r3, #0
_081D26C4:
	cmp r0, r7
	bhi _081D26EA
	adds r2, r1, #0
	cmp r1, #0
	bge _081D26D0
	rsbs r2, r1, #0
_081D26D0:
	ldr r0, [sp, #0x14]
	cmp r2, r0
	bhi _081D26EA
	ldrh r0, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r3, [r6]
	strh r1, [r6, #4]
	movs r0, #1
	b _081D2764
_081D26EA:
	cmp r3, #0
	bne _081D26F2
	cmp r1, #0
	beq _081D2762
_081D26F2:
	adds r0, r3, #0
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r3, r0, #6
	strb r3, [r5, #5]
	ldr r1, _081D2724 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D2728
	asrs r0, r0, #0xc
	b _081D272E
	.align 2, 0
_081D2724: .4byte 0x085B0A08
_081D2728:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D272E:
	adds r2, r0, #0
	ldr r0, _081D2748 @ =0x085B0A08
	lsls r1, r3, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D274C
	asrs r1, r0, #0xc
	b _081D2752
	.align 2, 0
_081D2748: .4byte 0x085B0A08
_081D274C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D2752:
	ldrh r0, [r5, #8]
	adds r0, r0, r2
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r2, [r6]
	strh r1, [r6, #4]
_081D2762:
	movs r0, #0
_081D2764:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d276c
FUN_081d276c: @ 0x081D276C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r0, _081D27A8 @ =0x03000194
	ldr r0, [r0]
	adds r6, r3, #0
	adds r6, #0xd4
	ldr r1, _081D27AC @ =0x000012B0
	adds r5, r0, r1
	ldr r2, _081D27B0 @ =0x03002BE0
	movs r4, #0
_081D2780:
	ldr r1, [r2]
	cmp r1, #0
	beq _081D27B8
	ldrh r0, [r6]
	ldrh r7, [r5]
	cmp r0, r7
	bne _081D27B8
	adds r0, r3, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081D27B4
	movs r7, #0xde
	lsls r7, r7, #1
	adds r0, r1, r7
	b _081D27B6
	.align 2, 0
_081D27A8: .4byte 0x03000194
_081D27AC: .4byte 0x000012B0
_081D27B0: .4byte 0x03002BE0
_081D27B4:
	movs r0, #0
_081D27B6:
	str r0, [r1, #0x3c]
_081D27B8:
	adds r2, #4
	subs r4, #1
	cmp r4, #0
	bge _081D2780
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d27c8
FUN_081d27c8: @ 0x081D27C8
	push {r4, lr}
	ldr r4, _081D27E4 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D27E8
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	bne _081D2804
	b _081D27F2
	.align 2, 0
_081D27E4: .4byte 0x03002BE0
_081D27E8:
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	beq _081D2804
_081D27F2:
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D2804
	movs r0, #1
	b _081D2806
_081D2804:
	movs r0, #0
_081D2806:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d280c
FUN_081d280c: @ 0x081D280C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d2810
FUN_081d2810: @ 0x081D2810
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
	ldr r0, _081D2874 @ =0x03002BE0
	mov r4, sp
	adds r2, r5, #0
	adds r2, #0xfc
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r4, r5, #0
	adds r4, #0xb6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D2860
	adds r0, r5, #0
	bl FUN_081d21d8
	movs r0, #0
	strb r0, [r4]
_081D2860:
	movs r2, #4
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081D2878
	movs r0, #1
	b _081D287A
	.align 2, 0
_081D2874: .4byte 0x03002BE0
_081D2878:
	movs r0, #0
_081D287A:
	cmp r0, #0
	beq _081D2880
	b _081D29F2
_081D2880:
	movs r1, #2
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D288E
	movs r0, #1
	b _081D2890
_081D288E:
	movs r0, #0
_081D2890:
	mov sb, r0
	cmp r0, #0
	beq _081D2950
	adds r4, r5, #0
	adds r4, #0xfe
	adds r1, r5, #0
	adds r1, #0xba
	ldrh r0, [r1]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r1]
	movs r1, #0x5a
	adds r1, r1, r5
	mov r8, r1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	ble _081D28C0
	b _081D29F2
_081D28C0:
	strh r0, [r4]
	ldr r6, _081D293C @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D28F4
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	movs r0, #0
	mov r1, r8
	strh r0, [r1]
_081D28F4:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2940 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2944 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2948 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D294C @ =0x00000159
	bl PlaySound_082406e0
	b _081D29F2
	.align 2, 0
_081D293C: .4byte 0x03002BE0
_081D2940: .4byte 0x00000261
_081D2944: .4byte 0x00000289
_081D2948: .4byte 0x0000028A
_081D294C: .4byte 0x00000159
_081D2950:
	adds r4, r5, #0
	adds r4, #0xfe
	adds r2, r5, #0
	adds r2, #0xba
	ldrh r0, [r4]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2]
	rsbs r0, r0, #0
	movs r2, #0x5a
	adds r2, r2, r5
	mov r8, r2
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xcc
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	blt _081D29F2
	strh r0, [r4]
	ldr r6, _081D2A00 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D29AE
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	mov r1, sb
	mov r0, r8
	strh r1, [r0]
_081D29AE:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2A04 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2A08 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2A0C @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2A10 @ =0x00000159
	bl PlaySound_082406e0
_081D29F2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2A00: .4byte 0x03002BE0
_081D2A04: .4byte 0x00000261
_081D2A08: .4byte 0x00000289
_081D2A0C: .4byte 0x0000028A
_081D2A10: .4byte 0x00000159

	thumb_func_start FUN_081d2a14
FUN_081d2a14: @ 0x081D2A14
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xf4
	adds r1, r5, #0
	adds r1, #0xe8
	adds r2, r5, #0
	adds r2, #0x58
	adds r4, r5, #0
	adds r4, #0xba
	movs r6, #0
	ldrsh r3, [r4, r6]
	str r3, [sp]
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	bl FUN_081d2698
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2A54
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_081d5588
	b _081D2A5A
_081D2A54:
	adds r0, r5, #0
	bl FUN_081d2368
_081D2A5A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d2a64
FUN_081d2a64: @ 0x081D2A64
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r4, #0
	adds r3, r5, #0
	adds r3, #0xce
	movs r0, #0x1c
	adds r0, r0, r5
	mov ip, r0
_081D2A76:
	ldr r1, _081D2A8C @ =0x000012AC
	adds r0, r5, r1
	movs r1, #1
	lsls r1, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2A90
	movs r0, #1
	b _081D2A92
	.align 2, 0
_081D2A8C: .4byte 0x000012AC
_081D2A90:
	movs r0, #0
_081D2A92:
	cmp r0, #0
	beq _081D2B10
	movs r0, #0
	ldrsh r2, [r3, r0]
	cmp r2, #6
	beq _081D2B10
	ldrh r1, [r3, #0x24]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081D2B10
	cmp r2, #1
	beq _081D2AE0
	ldr r1, _081D2AD4 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	beq _081D2AB8
	b _081D2BFC
_081D2AB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2AD8 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2ADC @ =0x00000289
	bl sound_08240740
	movs r0, #0
	strb r0, [r4]
	b _081D2BFC
	.align 2, 0
_081D2AD4: .4byte 0x000012B4
_081D2AD8: .4byte 0x0000028A
_081D2ADC: .4byte 0x00000289
_081D2AE0:
	ldr r1, _081D2B00 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2AEC
	b _081D2BFC
_081D2AEC:
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2B08
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2B04 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2B00: .4byte 0x000012B4
_081D2B04: .4byte 0x00000289
_081D2B08:
	ldr r0, _081D2B0C @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2B0C: .4byte 0x0000028A
_081D2B10:
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r3, r3, r1
	add ip, r1
	adds r4, #1
	cmp r4, #0xb
	ble _081D2A76
	ldr r4, _081D2B84 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D2B2E
	movs r7, #1
_081D2B2E:
	ldr r0, [r4]
	ldr r1, _081D2B88 @ =0x00000392
	adds r0, r0, r1
	ldrh r0, [r0]
	bl FUN_081d3118
	adds r2, r0, #0
	cmp r2, #0
	beq _081D2BFC
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _081D2BFC
	cmp r7, #0
	beq _081D2BDC
	adds r0, r2, #0
	adds r0, #0xb2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081D2B98
	ldr r0, _081D2B8C @ =0x000012B4
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2B90 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2B94 @ =0x00000289
	bl sound_08240740
	strb r6, [r4]
	b _081D2BFC
	.align 2, 0
_081D2B84: .4byte 0x03002BE0
_081D2B88: .4byte 0x00000392
_081D2B8C: .4byte 0x000012B4
_081D2B90: .4byte 0x0000028A
_081D2B94: .4byte 0x00000289
_081D2B98:
	ldr r1, _081D2BB4 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D2BFC
	adds r0, r2, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2BBC
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2BB8 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2BB4: .4byte 0x000012B4
_081D2BB8: .4byte 0x00000289
_081D2BBC:
	ldr r0, _081D2BC0 @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2BC0: .4byte 0x0000028A
_081D2BC4:
	movs r0, #0xa2
	lsls r0, r0, #2
_081D2BC8:
	bl PlaySound_082406e0
	ldr r0, _081D2BD8 @ =0x000012B4
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _081D2BFC
	.align 2, 0
_081D2BD8: .4byte 0x000012B4
_081D2BDC:
	ldr r1, _081D2C04 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2C08 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2C0C @ =0x00000289
	bl sound_08240740
	strb r7, [r4]
_081D2BFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2C04: .4byte 0x000012B4
_081D2C08: .4byte 0x0000028A
_081D2C0C: .4byte 0x00000289

	thumb_func_start FUN_081d2c10
FUN_081d2c10: @ 0x081D2C10
	push {lr}
	sub sp, #8
	ldr r0, _081D2C58 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	mov r1, sp
	ldrh r2, [r1]
	adds r2, #0x80
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _081D2C5C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	mov r1, sp
	bl FUN_0807a91c
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x80
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl FUN_08086a4c
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_081D2C58: .4byte 0x03002BE0
_081D2C5C: .4byte 0xFFFF0000

	thumb_func_start FUN_081d2c60
FUN_081d2c60: @ 0x081D2C60
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	ldr r0, _081D2CE4 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081D2CEC
	mov r4, sp
	adds r2, #0xfc
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	subs r5, r1, r0
	strh r5, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r2, r1, r0
	strh r2, [r4, #4]
	ldr r3, _081D2CE8 @ =0x085AE0D0
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bgt _081D2CEC
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmn r1, r0
	blt _081D2CEC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r3, r5]
	cmp r0, r1
	bgt _081D2CEC
	movs r6, #2
	ldrsh r1, [r4, r6]
	movs r5, #2
	ldrsh r0, [r3, r5]
	cmn r1, r0
	blt _081D2CEC
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r3, r6]
	cmp r0, r1
	bgt _081D2CEC
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D2CEC
	movs r0, #1
	b _081D2CEE
	.align 2, 0
_081D2CE4: .4byte 0x03002BE0
_081D2CE8: .4byte 0x085AE0D0
_081D2CEC:
	movs r0, #0
_081D2CEE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d2cf8
FUN_081d2cf8: @ 0x081D2CF8
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2D96
	ldr r0, _081D2D3C @ =0x03000194
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd4
	ldr r2, _081D2D40 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2D88
	adds r0, r4, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D2D88
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D2D52
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2D44
	movs r0, #1
	b _081D2D46
	.align 2, 0
_081D2D3C: .4byte 0x03000194
_081D2D40: .4byte 0x000012B0
_081D2D44:
	movs r0, #0
_081D2D46:
	cmp r0, #0
	beq _081D2D4E
	movs r0, #2
	b _081D2D58
_081D2D4E:
	movs r0, #1
	b _081D2D58
_081D2D52:
	adds r0, r4, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D2D58:
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D2DF0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D2D88:
	adds r1, r4, #0
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
_081D2D96:
	adds r0, r4, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2DA4
	b _081D2EFA
_081D2DA4:
	adds r0, r4, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D2E78
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r4, #0
	adds r1, #0xbc
	adds r5, r0, #0
	adds r6, r1, #0
	ldrh r0, [r6]
	cmp r2, r0
	blt _081D2E60
	adds r0, r4, #0
	bl FUN_081d2c60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2E60
	adds r0, r4, #0
	adds r0, #0xb2
	movs r2, #2
	strh r2, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081D2DF4
	movs r0, #1
	b _081D2DF6
	.align 2, 0
_081D2DF0: .4byte 0xFFFF0000
_081D2DF4:
	movs r0, #0
_081D2DF6:
	cmp r0, #0
	beq _081D2E04
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	b _081D2E0A
_081D2E04:
	movs r0, #2
	ldrh r1, [r2]
	orrs r0, r1
_081D2E0A:
	strh r0, [r2]
	movs r0, #0
	strh r0, [r5]
	adds r0, r4, #0
	adds r0, #0xb6
	movs r5, #1
	strb r5, [r0]
	ldr r0, _081D2E54 @ =0x03000194
	ldr r0, [r0]
	adds r3, r4, #0
	adds r3, #0xd4
	ldr r1, _081D2E58 @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2EFA
	adds r2, r4, #0
	adds r2, #0xc4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D2EFA
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D2E5C @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r5
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
	b _081D2EFA
	.align 2, 0
_081D2E54: .4byte 0x03000194
_081D2E58: .4byte 0x000012B0
_081D2E5C: .4byte 0xFFFF0000
_081D2E60:
	movs r2, #0
	ldrsh r1, [r5, r2]
	ldrh r0, [r6]
	subs r0, #0xa
	cmp r1, r0
	ble _081D2E78
	movs r0, #0x20
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D2E78:
	ldr r0, _081D2EAC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x2c
	bl FUN_081d2230
	adds r3, r0, #0
	cmp r3, #0
	beq _081D2EF0
	adds r0, #0xd4
	adds r1, r4, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D2EFA
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2EB0
	movs r0, #1
	b _081D2EB2
	.align 2, 0
_081D2EAC: .4byte 0x03002BE0
_081D2EB0:
	movs r0, #0
_081D2EB2:
	adds r5, r4, #0
	adds r5, #0xb8
	cmp r0, #0
	bne _081D2ED0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _081D2ED0
	adds r0, r4, #0
	adds r0, #0xc6
	ldr r1, _081D2EE4 @ =0x0000FFE0
	strh r1, [r0]
	ldr r0, _081D2EE8 @ =0x00000222
	bl PlaySound_082406e0
_081D2ED0:
	ldrh r2, [r5]
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldr r0, _081D2EEC @ =0x00007CFF
	cmp r1, r0
	bgt _081D2EFA
	adds r0, r2, #1
	strh r0, [r5]
	b _081D2EFA
	.align 2, 0
_081D2EE4: .4byte 0x0000FFE0
_081D2EE8: .4byte 0x00000222
_081D2EEC: .4byte 0x00007CFF
_081D2EF0:
	adds r0, r4, #0
	adds r0, #0xb8
	strh r3, [r0]
	adds r0, #0xe
	strh r3, [r0]
_081D2EFA:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d2f04
FUN_081d2f04: @ 0x081D2F04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xc6
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _081D2F2C
	ldrh r2, [r7, #0x1e]
	adds r0, r1, r2
	strh r0, [r7, #0x1e]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	strh r0, [r4]
_081D2F2C:
	movs r2, #0x80
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081D2F40
	movs r0, #1
	b _081D2F42
_081D2F40:
	movs r0, #0
_081D2F42:
	cmp r0, #0
	bne _081D2FAE
	movs r1, #0x20
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D2F54
	movs r0, #1
	b _081D2F56
_081D2F54:
	movs r0, #0
_081D2F56:
	cmp r0, #0
	beq _081D2FB8
	ldr r2, _081D2FC4 @ =0x0203B400
	mov r8, r2
	ldr r4, _081D2FC8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D2FCC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	ldrh r2, [r7, #0x1e]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x20]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x20]
_081D2FAE:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
_081D2FB8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2FC4: .4byte 0x0203B400
_081D2FC8: .4byte 0x030046B8
_081D2FCC: .4byte 0x000003FF

	thumb_func_start FUN_081d2fd0
FUN_081d2fd0: @ 0x081D2FD0
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r5, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D306E
	ldr r0, _081D3014 @ =0x03000194
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0xd4
	ldr r2, _081D3018 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3060
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D3060
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D302A
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D301C
	movs r0, #1
	b _081D301E
	.align 2, 0
_081D3014: .4byte 0x03000194
_081D3018: .4byte 0x000012B0
_081D301C:
	movs r0, #0
_081D301E:
	cmp r0, #0
	beq _081D3026
	movs r0, #2
	b _081D3030
_081D3026:
	movs r0, #1
	b _081D3030
_081D302A:
	adds r0, r5, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D3030:
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D3060:
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	subs r0, #2
	strb r2, [r0]
_081D306E:
	ldr r6, _081D30F4 @ =0x03000194
	adds r0, r5, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3108
	adds r4, r5, #0
	adds r4, #0xe8
	ldrb r1, [r4, #3]
	adds r0, r1, #1
	strb r0, [r4, #3]
	lsls r1, r1, #0x18
	ldr r0, [r4, #8]
	ldrh r2, [r0, #4]
	ldr r0, _081D30F8 @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	blo _081D3108
	adds r0, r4, #0
	bl FUN_08234e3c
	adds r1, r5, #0
	adds r1, #0xfc
	adds r0, r4, #0
	movs r2, #0x10
	movs r3, #0x10
	bl FUN_08235038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3100
	adds r0, r5, #0
	adds r0, #0xb2
	movs r4, #1
	strh r4, [r0]
	ldr r0, [r6]
	adds r2, r5, #0
	adds r2, #0xd4
	ldr r1, _081D30FC @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3108
	adds r3, r5, #0
	adds r3, #0xc4
	ldrh r0, [r3]
	cmp r0, #0
	beq _081D3108
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r4
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r3]
	bl Script_ExecById
	b _081D3108
	.align 2, 0
_081D30F0: .4byte 0xFFFF0000
_081D30F4: .4byte 0x03000194
_081D30F8: .4byte 0x00000FFF
_081D30FC: .4byte 0x000012B0
_081D3100:
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D3108:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d3110
FUN_081d3110: @ 0x081D3110
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d3114
FUN_081d3114: @ 0x081D3114
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d3118
FUN_081d3118: @ 0x081D3118
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081D3138 @ =0x03000194
	ldr r0, [r0]
	movs r4, #0
	adds r2, r0, #0
	adds r2, #0x1c
	adds r1, r0, #0
	adds r1, #0xf0
	movs r3, #0xc6
	lsls r3, r3, #1
_081D312E:
	ldrh r0, [r1]
	cmp r0, r5
	bne _081D313C
	adds r0, r2, #0
	b _081D3148
	.align 2, 0
_081D3138: .4byte 0x03000194
_081D313C:
	adds r2, r2, r3
	adds r1, r1, r3
	adds r4, #1
	cmp r4, #0xb
	ble _081D312E
	movs r0, #0
_081D3148:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d3150
FUN_081d3150: @ 0x081D3150
	push {r4, r5, lr}
	ldr r0, _081D3180 @ =0x03000194
	ldr r1, [r0]
	movs r3, #0
	ldr r2, _081D3184 @ =0x000012B0
	adds r0, r1, r2
	ldrh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x1c
	adds r1, #0xf0
	movs r2, #0xc6
	lsls r2, r2, #1
_081D3168:
	ldrh r5, [r1]
	cmp r4, r5
	beq _081D317A
	adds r0, r0, r2
	adds r1, r1, r2
	adds r3, #1
	cmp r3, #0xb
	ble _081D3168
	movs r0, #0
_081D317A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081D3180: .4byte 0x03000194
_081D3184: .4byte 0x000012B0

	thumb_func_start FUN_081d3188
FUN_081d3188: @ 0x081D3188
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D31A2
	movs r0, #1
	b _081D31A4
_081D31A2:
	movs r0, #0
_081D31A4:
	cmp r0, #0
	beq _081D31E0
	movs r6, #0
	movs r0, #0xb4
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r5, r7, r1
_081D31B6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r4, r0, r6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D31CE
	adds r0, r5, #0
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4]
_081D31CE:
	adds r5, #0x10
	adds r6, #1
	cmp r6, #3
	ble _081D31B6
	ldr r0, _081D31EC @ =0xFFFFF7FF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D31E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D31EC: .4byte 0xFFFFF7FF

	thumb_func_start FUN_081d31f0
FUN_081d31f0: @ 0x081D31F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	ldr r0, _081D3244 @ =0x03000194
	ldr r1, [r0]
	cmp r1, #0
	beq _081D323C
	mov r0, r8
	adds r0, #0xd4
	ldr r2, _081D3248 @ =0x000012B0
	adds r1, r1, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D323C
	mov r0, r8
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D323C
	ldr r0, _081D324C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D323C
	mov r0, r8
	adds r0, #0xb2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	beq _081D3250
_081D323C:
	mov r0, r8
	bl FUN_081d3188
	b _081D33E2
	.align 2, 0
_081D3244: .4byte 0x03000194
_081D3248: .4byte 0x000012B0
_081D324C: .4byte 0x03002BE0
_081D3250:
	movs r2, #0x80
	lsls r2, r2, #4
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D3266
	movs r0, #1
	b _081D3268
_081D3266:
	movs r0, #0
_081D3268:
	cmp r0, #0
	beq _081D326E
	b _081D33E2
_081D326E:
	mov r0, r8
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3296
	cmp r1, #0
	blt _081D3296
	ldr r0, _081D329C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3296
	ldr r0, _081D32A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D32A4
_081D3296:
	movs r0, #0
	b _081D32B2
	.align 2, 0
_081D329C: .4byte 0x030046A8
_081D32A0: .4byte 0x030046AC
_081D32A4:
	ldr r0, _081D32D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D32B2:
	str r0, [sp, #0x10]
	ldr r5, [sp, #0x10]
	adds r5, #1
	movs r1, #0
	mov sl, r1
	movs r2, #0xa4
	lsls r2, r2, #1
	add r2, r8
	str r2, [sp, #0x18]
_081D32C4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D32D8
	adds r0, #4
	b _081D32E4
	.align 2, 0
_081D32D4: .4byte 0x030046A4
_081D32D8:
	ldr r0, _081D32F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D32E4:
	ldrh r0, [r0, #2]
	movs r1, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _081D32F8
	movs r0, #0
	b _081D32FA
	.align 2, 0
_081D32F4: .4byte 0x030046A4
_081D32F8:
	movs r0, #1
_081D32FA:
	cmp r0, #0
	beq _081D3390
	mov r0, r8
	adds r0, #0xfe
	ldrh r3, [r0]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r0, #0xff
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r5, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #0xc4
	lsls r0, r0, #1
	add r0, r8
	add r0, sl
	movs r1, #1
	strb r1, [r0]
	add r0, sp, #8
	mov sb, r0
	ldr r6, _081D3364 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3368
	adds r0, #4
	b _081D3372
	.align 2, 0
_081D3364: .4byte 0x030046A4
_081D3368:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D3372:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3390:
	mov r0, sl
	cmp r0, #1
	beq _081D33BC
	cmp r0, #1
	bgt _081D33A0
	cmp r0, #0
	beq _081D33A8
	b _081D33D0
_081D33A0:
	mov r1, sl
	cmp r1, #2
	beq _081D33C2
	b _081D33D0
_081D33A8:
	ldr r0, _081D33B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	adds r5, r1, r0
	b _081D33D0
	.align 2, 0
_081D33B8: .4byte 0x030046A4
_081D33BC:
	ldr r5, [sp, #0x10]
	subs r5, #1
	b _081D33D0
_081D33C2:
	ldr r0, _081D33F4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	subs r5, r1, r0
_081D33D0:
	ldr r2, [sp, #0x18]
	adds r2, #0x10
	str r2, [sp, #0x18]
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _081D33E2
	b _081D32C4
_081D33E2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D33F4: .4byte 0x030046A4

	thumb_func_start FUN_081d33f8
FUN_081d33f8: @ 0x081D33F8
	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D343A
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D3420
	movs r0, #1
	b _081D3422
_081D3420:
	movs r0, #0
_081D3422:
	cmp r0, #0
	beq _081D34E0
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	bl FUN_082342a8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	b _081D34DE
_081D343A:
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D344E
	movs r0, #1
	b _081D3450
_081D344E:
	movs r0, #0
_081D3450:
	cmp r0, #0
	bne _081D34E0
	ldr r0, _081D34A0 @ =0x030046A4
	ldr r3, [r0]
	cmp r3, #0
	beq _081D34E0
	mov r2, ip
	adds r2, #0xfe
	ldr r0, _081D34A4 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0x2e
	ldrsh r0, [r0, r5]
	adds r5, r2, #0
	cmp r1, r0
	bne _081D34E0
	mov r0, ip
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D349A
	cmp r1, #0
	blt _081D349A
	ldr r0, _081D34A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D349A
	ldr r0, _081D34AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D34B0
_081D349A:
	movs r2, #0
	b _081D34BC
	.align 2, 0
_081D34A0: .4byte 0x030046A4
_081D34A4: .4byte 0x03002BE0
_081D34A8: .4byte 0x030046A8
_081D34AC: .4byte 0x030046AC
_081D34B0:
	lsls r0, r1, #1
	adds r1, r3, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r2, r0, r2
_081D34BC:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	ldrh r3, [r5]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	ldrh r1, [r4]
	orrs r0, r1
_081D34DE:
	strh r0, [r4]
_081D34E0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d34e8
FUN_081d34e8: @ 0x081D34E8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D3508 @ =0x03000194
	movs r3, #0
	movs r6, #1
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0xd0
	movs r4, #0xc6
	lsls r4, r4, #1
_081D34FC:
	ldrh r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _081D350C
	movs r0, #1
	b _081D350E
	.align 2, 0
_081D3508: .4byte 0x03000194
_081D350C:
	movs r0, #0
_081D350E:
	cmp r0, #0
	beq _081D3522
	movs r7, #0xab
	lsls r7, r7, #1
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r5
	bne _081D3522
	movs r0, #1
	b _081D352E
_081D3522:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, #0xb
	ble _081D34FC
	movs r0, #0
_081D352E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d3534
FUN_081d3534: @ 0x081D3534
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	movs r0, #0
	str r0, [sp, #8]
	ldr r7, _081D3578 @ =0x03002BE0
	movs r1, #0xfc
	add r1, sl
	mov r8, r1
_081D354E:
	ldr r0, [r7]
	cmp r0, #0
	bne _081D3556
	b _081D3694
_081D3556:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D3562
	b _081D3694
_081D3562:
	movs r2, #8
	mov r1, sl
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D357C
	movs r0, #1
	b _081D357E
	.align 2, 0
_081D3578: .4byte 0x03002BE0
_081D357C:
	movs r0, #0
_081D357E:
	cmp r0, #0
	bne _081D3584
	b _081D3694
_081D3584:
	ldr r0, [r7]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D35AA
	cmp r1, #0
	blt _081D35AA
	ldr r0, _081D35B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D35AA
	ldr r0, _081D35B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D35B8
_081D35AA:
	movs r4, #0
	b _081D35C6
	.align 2, 0
_081D35B0: .4byte 0x030046A8
_081D35B4: .4byte 0x030046AC
_081D35B8:
	ldr r0, _081D35E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D35C6:
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3694
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D35E8
	adds r0, #4
	b _081D35F4
	.align 2, 0
_081D35E4: .4byte 0x030046A4
_081D35E8:
	ldr r0, _081D36B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D35F4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3694
	mov r3, sp
	ldr r0, [r7]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r1, [r0, #0x2c]
	mov r4, r8
	ldrh r0, [r4]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	ldrh r0, [r4, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r2, #4]
	mov r6, r8
	ldrh r0, [r6, #4]
	subs r5, r1, r0
	strh r5, [r3, #4]
	ldr r2, _081D36B8 @ =0x085AE0D0
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	ldr r6, _081D36BC @ =0x03002BE0
	mov ip, r6
	mov r6, sl
	adds r6, #0xfc
	str r6, [sp, #0xc]
	cmp r1, r0
	bgt _081D367C
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmn r1, r0
	blt _081D367C
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D367C
	movs r6, #2
	ldrsh r1, [r3, r6]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D367C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r2, r6]
	cmp r0, r1
	bgt _081D367C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D3694
_081D367C:
	ldr r0, [sp, #8]
	add r0, ip
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	bl FUN_0807a9b8
	movs r0, #0x80
	lsls r0, r0, #1
	mov r4, sb
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_081D3694:
	ldr r6, [sp, #8]
	adds r6, #4
	str r6, [sp, #8]
	adds r7, #4
	ldr r0, _081D36BC @ =0x03002BE0
	cmp r7, r0
	bgt _081D36A4
	b _081D354E
_081D36A4:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D36B4: .4byte 0x030046A4
_081D36B8: .4byte 0x085AE0D0
_081D36BC: .4byte 0x03002BE0

	thumb_func_start FUN_081d36c0
FUN_081d36c0: @ 0x081D36C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _081D3710 @ =0x03002BE0
	mov sl, r0
	mov r6, sp
	mov r8, sl
_081D36D6:
	movs r1, #0
	mov sb, r1
	mov r3, r8
	ldr r0, [r3]
	cmp r0, #0
	bne _081D36E4
	b _081D3884
_081D36E4:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	mov r4, r8
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	b _081D388E
_081D36FE:
	movs r1, #8
	adds r0, r7, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D3714
	movs r0, #1
	b _081D3716
	.align 2, 0
_081D3710: .4byte 0x03002BE0
_081D3714:
	movs r0, #0
_081D3716:
	cmp r0, #0
	bne _081D371C
	b _081D3884
_081D371C:
	mov r1, r8
	ldr r0, [r1]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3744
	cmp r1, #0
	blt _081D3744
	ldr r0, _081D3748 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3744
	ldr r0, _081D374C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3750
_081D3744:
	movs r4, #0
	b _081D375E
	.align 2, 0
_081D3748: .4byte 0x030046A8
_081D374C: .4byte 0x030046AC
_081D3750:
	ldr r0, _081D3770 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D375E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3774
	adds r0, #4
	b _081D3780
	.align 2, 0
_081D3770: .4byte 0x030046A4
_081D3774:
	ldr r0, _081D3818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3780:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3884
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3884
	mov r5, sp
	adds r2, r7, #0
	adds r2, #0xfc
	mov r3, r8
	ldr r0, [r3]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r5, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r3, r1, r0
	strh r3, [r5, #4]
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081D3820
	ldr r2, _081D381C @ =0x085AE0D0
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D3874
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D3874
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3874
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D3874
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D3874
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
	b _081D3874
	.align 2, 0
_081D3818: .4byte 0x030046A4
_081D381C: .4byte 0x085AE0D0
_081D3820:
	ldr r2, _081D38A0 @ =0x085AE0D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D386A
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D386A
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D386A
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D386A
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D386A
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
_081D386A:
	movs r4, #1
	mov sb, r4
_081D386E:
	mov r0, sb
	cmp r0, #0
	beq _081D3884
_081D3874:
	adds r1, r7, #0
	adds r1, #0xc0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D3884
	movs r1, #0
	bl Script_ExecById
_081D3884:
	movs r1, #4
	add r8, r1
	cmp r8, sl
	bgt _081D388E
	b _081D36D6
_081D388E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D38A0: .4byte 0x085AE0D8

	thumb_func_start FUN_081d38a4
FUN_081d38a4: @ 0x081D38A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	mov r6, sp
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _081D38F8 @ =0x03002BE0
	mov sl, r1
_081D38BC:
	mov r2, sl
	ldr r1, [r2]
	cmp r1, #0
	bne _081D38C6
	b _081D3A66
_081D38C6:
	mov r0, sb
	adds r0, #0xb2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #4
	bne _081D38D4
	b _081D3A66
_081D38D4:
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D38E2
	b _081D3A66
_081D38E2:
	movs r2, #8
	mov r1, sb
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #8]
	cmp r0, #0
	beq _081D38FC
	movs r0, #1
	b _081D38FE
	.align 2, 0
_081D38F8: .4byte 0x03002BE0
_081D38FC:
	movs r0, #0
_081D38FE:
	cmp r0, #0
	bne _081D3904
	b _081D3A78
_081D3904:
	mov r0, sb
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r2, #0
	blt _081D392E
	cmp r1, #0
	blt _081D392E
	ldr r0, _081D3934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D392E
	ldr r0, _081D3938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D393C
_081D392E:
	movs r0, #0
	b _081D394A
	.align 2, 0
_081D3934: .4byte 0x030046A8
_081D3938: .4byte 0x030046AC
_081D393C:
	ldr r0, _081D39F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D394A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D396A
	mov r4, sl
	ldr r0, [r4]
	mov r2, sb
	adds r2, #0xfe
	movs r5, #0x2e
	ldrsh r1, [r0, r5]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _081D396A
	b _081D3A66
_081D396A:
	mov r3, sp
	mov r4, sl
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	mov r5, r8
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r2, #2]
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r3, #2]
	ldrh r1, [r2, #4]
	mov r2, r8
	ldrh r0, [r2, #4]
	subs r7, r1, r0
	strh r7, [r3, #4]
	ldr r0, _081D39F4 @ =0x085AE0E0
	movs r4, #0
	ldrsh r2, [r6, r4]
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r4, _081D39F8 @ =0x03002BE0
	mov ip, r4
	adds r4, r0, #0
	cmp r2, r1
	bgt _081D39EC
	adds r1, r2, #0
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r5, #4
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bge _081D3A66
_081D39DE:
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldrh r2, [r4]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D39FC
_081D39EC:
	ldrh r0, [r4]
	b _081D3A0A
	.align 2, 0
_081D39F0: .4byte 0x030046A4
_081D39F4: .4byte 0x085AE0E0
_081D39F8: .4byte 0x03002BE0
_081D39FC:
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmn r1, r0
	bge _081D3A0C
	rsbs r0, r2, #0
_081D3A0A:
	strh r0, [r6]
_081D3A0C:
	mov r2, sp
	movs r5, #4
	ldrsh r1, [r2, r5]
	ldrh r3, [r4, #4]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D3A20
	strh r3, [r2, #4]
	b _081D3A30
_081D3A20:
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmn r1, r0
	bge _081D3A30
	rsbs r0, r3, #0
	strh r0, [r2, #4]
_081D3A30:
	ldrh r0, [r6]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
	mov r0, sb
	adds r0, #0xfe
	ldrh r0, [r0]
	strh r0, [r6, #2]
	movs r4, #0x80
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [sp, #0xc]
	add r0, ip
	ldr r0, [r0]
	mov r1, sp
	bl FUN_0807a91c
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	orrs r4, r0
	strh r4, [r3]
_081D3A66:
	ldr r4, [sp, #0xc]
	adds r4, #4
	str r4, [sp, #0xc]
	movs r5, #4
	add sl, r5
	ldr r0, _081D3A88 @ =0x03002BE0
	cmp sl, r0
	bgt _081D3A78
	b _081D38BC
_081D3A78:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D3A88: .4byte 0x03002BE0

	thumb_func_start FUN_081d3a8c
FUN_081d3a8c: @ 0x081D3A8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3AA2
	b _081D3C18
_081D3AA2:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D3AB6
	movs r0, #1
	b _081D3AB8
_081D3AB6:
	movs r0, #0
_081D3AB8:
	cmp r0, #0
	bne _081D3ABE
	b _081D3C18
_081D3ABE:
	mov r0, sp
	bl FUN_08086a28
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D3AEE
	cmp r1, #0
	blt _081D3AEE
	ldr r0, _081D3AF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3AEE
	ldr r0, _081D3AF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3AFC
_081D3AEE:
	movs r0, #0
	b _081D3B0A
	.align 2, 0
_081D3AF4: .4byte 0x030046A8
_081D3AF8: .4byte 0x030046AC
_081D3AFC:
	ldr r0, _081D3BA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D3B0A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3B28
	mov r0, sp
	adds r1, r7, #0
	adds r1, #0xfe
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	beq _081D3C18
_081D3B28:
	add r3, sp, #8
	mov r4, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r6]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r4, #2]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r5, ip
	strh r5, [r3, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r6, #4]
	subs r4, r2, r0
	strh r4, [r3, #4]
	ldr r2, _081D3BAC @ =0x085AE0E0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D3BA4
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r2, r5]
	cmp r0, r1
	bgt _081D3B96
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r5, #2
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3B96
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r4, #4
	ldrsh r0, [r2, r4]
	cmn r1, r0
	bge _081D3C18
_081D3B96:
	movs r5, #0
	ldrsh r1, [r3, r5]
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BB0
_081D3BA4:
	ldrh r0, [r2]
	b _081D3BBE
	.align 2, 0
_081D3BA8: .4byte 0x030046A4
_081D3BAC: .4byte 0x085AE0E0
_081D3BB0:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BC0
	rsbs r0, r4, #0
_081D3BBE:
	strh r0, [r3]
_081D3BC0:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r4, [r2, #4]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BD2
	strh r4, [r3, #4]
	b _081D3BE2
_081D3BD2:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BE2
	rsbs r0, r4, #0
	strh r0, [r3, #4]
_081D3BE2:
	ldrh r0, [r3]
	ldrh r6, [r6]
	adds r0, r0, r6
	mov r1, sp
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3C18:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d3c24
FUN_081d3c24: @ 0x081D3C24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3C3C
	b _081D3DC0
_081D3C3C:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3C50
	movs r0, #1
	b _081D3C52
_081D3C50:
	movs r0, #0
_081D3C52:
	cmp r0, #0
	bne _081D3C58
	b _081D3DC0
_081D3C58:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3C86
	cmp r1, #0
	blt _081D3C86
	ldr r0, _081D3C8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3C86
	ldr r0, _081D3C90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3C94
_081D3C86:
	movs r4, #0
	b _081D3CA2
	.align 2, 0
_081D3C8C: .4byte 0x030046A8
_081D3C90: .4byte 0x030046AC
_081D3C94:
	ldr r0, _081D3CB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3CA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3CB8
	adds r0, #4
	b _081D3CC4
	.align 2, 0
_081D3CB4: .4byte 0x030046A4
_081D3CB8:
	ldr r0, _081D3D50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3CC4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3DC0
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3D54 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3D4A
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3DC0
_081D3D3C:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D58
_081D3D4A:
	ldrh r0, [r5]
	b _081D3D66
	.align 2, 0
_081D3D50: .4byte 0x030046A4
_081D3D54: .4byte 0x085AE0D0
_081D3D58:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D68
	rsbs r0, r2, #0
_081D3D66:
	strh r0, [r3]
_081D3D68:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D7A
	strh r2, [r3, #4]
	b _081D3D8A
_081D3D7A:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D8A
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3D8A:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3DC0:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d3dd0
FUN_081d3dd0: @ 0x081D3DD0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3DE8
	b _081D3F9C
_081D3DE8:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3DFC
	movs r0, #1
	b _081D3DFE
_081D3DFC:
	movs r0, #0
_081D3DFE:
	cmp r0, #0
	bne _081D3E04
	b _081D3F9C
_081D3E04:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3E32
	cmp r1, #0
	blt _081D3E32
	ldr r0, _081D3E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3E32
	ldr r0, _081D3E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3E40
_081D3E32:
	movs r4, #0
	b _081D3E4E
	.align 2, 0
_081D3E38: .4byte 0x030046A8
_081D3E3C: .4byte 0x030046AC
_081D3E40:
	ldr r0, _081D3E64 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3E4E:
	mov r0, sp
	movs r1, #2
	ldrsh r5, [r0, r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E68
	adds r0, #4
	b _081D3E74
	.align 2, 0
_081D3E64: .4byte 0x030046A4
_081D3E68:
	ldr r0, _081D3E90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3E74:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r5, r0
	bne _081D3EAA
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E94
	adds r0, #4
	b _081D3EA0
	.align 2, 0
_081D3E90: .4byte 0x030046A4
_081D3E94:
	ldr r0, _081D3F2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3EA0:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3F9C
_081D3EAA:
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3F30 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3F26
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3F9C
_081D3F18:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F34
_081D3F26:
	ldrh r0, [r5]
	b _081D3F42
	.align 2, 0
_081D3F2C: .4byte 0x030046A4
_081D3F30: .4byte 0x085AE0D0
_081D3F34:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F44
	rsbs r0, r2, #0
_081D3F42:
	strh r0, [r3]
_081D3F44:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F56
	strh r2, [r3, #4]
	b _081D3F66
_081D3F56:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F66
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3F66:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3F9C:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d3fac
FUN_081d3fac: @ 0x081D3FAC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov ip, r1
	ldr r0, _081D3FEC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D3FF0 @ =0x000012AC
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _081D4026
	movs r4, #0
	adds r6, r1, #0
	movs r0, #9
	rsbs r0, r0, #0
	mov r8, r0
	subs r0, #8
	mov sb, r0
	adds r3, r2, #0
	adds r3, #0xd0
	movs r5, #0xc6
	lsls r5, r5, #1
_081D3FDC:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D3FF4
	movs r0, #1
	b _081D3FF6
	.align 2, 0
_081D3FEC: .4byte 0x03000194
_081D3FF0: .4byte 0x000012AC
_081D3FF4:
	movs r0, #0
_081D3FF6:
	cmp r0, #0
	beq _081D401C
	ldrh r0, [r3, #0x20]
	cmp r0, r7
	bne _081D401C
	mov r0, ip
	cmp r0, #0
	bne _081D4010
	ldrh r1, [r3]
	mov r0, r8
	ands r0, r1
	strh r0, [r3]
	b _081D4026
_081D4010:
	adds r2, #0xd0
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	strh r0, [r2]
	b _081D4026
_081D401C:
	adds r3, r3, r5
	adds r2, r2, r5
	adds r4, #1
	cmp r4, #0xb
	ble _081D3FDC
_081D4026:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d4034
FUN_081d4034: @ 0x081D4034
	push {r4, lr}
	adds r1, r0, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D405C
	ldr r0, _081D4058 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0xd4
	ldrh r2, [r1]
	movs r1, #5
	bl FUN_0807a97c
	b _081D4072
	.align 2, 0
_081D4058: .4byte 0x03002BE0
_081D405C:
	ldr r4, _081D4078 @ =0x03002BE0
	ldr r0, [r4]
	adds r1, #0xd4
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_0807a97c
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0807a99c
_081D4072:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D4078: .4byte 0x03002BE0

	thumb_func_start FUN_081d407c
FUN_081d407c: @ 0x081D407C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D409C
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	movs r0, #7
	bl FUN_080869c8
	b _081D40AE
_081D409C:
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #4
	bl FUN_080869f8
_081D40AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d40b4
FUN_081d40b4: @ 0x081D40B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081D41B0 @ =0x03002BE0
	mov r8, r0
	ldr r3, [r0]
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r3, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081D41B4 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r0, r7, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	ldrh r0, [r3, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D41B8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	ldrh r3, [r3, #0x30]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r5, sp
	ldr r0, [sp, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	add r4, sp, #8
	adds r3, r7, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r5, #2]
	ldrh r0, [r3, #2]
	subs r6, r2, r0
	strh r6, [r4, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r3, #4]
	subs r5, r2, r0
	strh r5, [r4, #4]
	ldr r0, _081D41BC @ =0x03000194
	ldr r0, [r0]
	mov ip, r0
	ldr r0, _081D41C0 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r3, r0, #0
	cmp r1, r2
	bgt _081D41CC
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	ldr r4, _081D41C4 @ =0x000012B0
	add r4, ip
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	adds r0, r7, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_081d4034
	movs r0, #8
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D41C8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	b _081D42AC
	.align 2, 0
_081D41B0: .4byte 0x03002BE0
_081D41B4: .4byte 0xFFFF0000
_081D41B8: .4byte 0x0000FFFF
_081D41BC: .4byte 0x03000194
_081D41C0: .4byte 0x085AE0D0
_081D41C4: .4byte 0x000012B0
_081D41C8: .4byte 0x0000060E
_081D41CC:
	ldr r0, _081D422C @ =0x000012B0
	add r0, ip
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D42AE
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D4234
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4234
	ldr r2, _081D4230 @ =0x085AE0D8
	movs r3, #0
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #2
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	b _081D4266
	.align 2, 0
_081D422C: .4byte 0x000012B0
_081D4230: .4byte 0x085AE0D8
_081D4234:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
_081D4266:
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	adds r0, r7, #0
	bl FUN_081d4034
	b _081D42AE
_081D4276:
	ldr r1, _081D42BC @ =0x000012B0
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r0, r2
	str r1, [r0, #0x3c]
	movs r1, #5
	bl FUN_0807a99c
	adds r2, r7, #0
	adds r2, #0xb4
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D42C0 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xfe
	ands r0, r2
_081D42AC:
	strb r0, [r1]
_081D42AE:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D42BC: .4byte 0x000012B0
_081D42C0: .4byte 0x0000060E

	thumb_func_start FUN_081d42c4
FUN_081d42c4: @ 0x081D42C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	add r6, sp, #8
	adds r3, r5, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r6]
	ldrh r2, [r4, #2]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r2, ip
	strh r2, [r6, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r3, #4]
	subs r2, r2, r0
	strh r2, [r6, #4]
	ldr r0, _081D4394 @ =0x03000194
	ldr r4, [r0]
	ldr r3, _081D4398 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bgt _081D43A0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r7, #2
	ldrsh r1, [r3, r7]
	cmp r0, r1
	bgt _081D43A0
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r7, #2
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D43A0
	movs r7, #4
	ldrsh r1, [r6, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D43A0
	ldr r7, _081D439C @ =0x000012B2
	adds r4, r4, r7
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r0, r5, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_081d407c
	movs r0, #0x10
	adds r2, r5, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	b _081D43C6
	.align 2, 0
_081D4394: .4byte 0x03000194
_081D4398: .4byte 0x085AE0D0
_081D439C: .4byte 0x000012B2
_081D43A0:
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r1, _081D43D0 @ =0x000012B2
	adds r4, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	bne _081D43C8
	movs r0, #0
	strh r0, [r4]
	movs r0, #7
	bl FUN_080869f8
	adds r2, r5, #0
	adds r2, #0xb4
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
_081D43C6:
	strh r0, [r2]
_081D43C8:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D43D0: .4byte 0x000012B2

	thumb_func_start FUN_081d43d4
FUN_081d43d4: @ 0x081D43D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov ip, r2
	mov r1, ip
	adds r1, #0xfc
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D4440 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	orrs r1, r0
	adds r2, #0xfe
	mov r6, r8
	ldrh r0, [r6, #2]
	ldrh r2, [r2]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	ldr r2, _081D4444 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r3, r5
	adds r5, r3, #0
	orrs r5, r0
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D442A
	b _081D4530
_081D442A:
	cmp r0, #1
	bne _081D444C
	mov r0, ip
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D444C
	ldr r0, _081D4448 @ =0x085AE0D8
	b _081D444E
	.align 2, 0
_081D4440: .4byte 0xFFFF0000
_081D4444: .4byte 0x0000FFFF
_081D4448: .4byte 0x085AE0D8
_081D444C:
	ldr r0, _081D4470 @ =0x085AE0D0
_081D444E:
	ldr r6, [r0]
	ldr r7, [r0, #4]
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D4474
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D4486
	.align 2, 0
_081D4470: .4byte 0x085AE0D0
_081D4474:
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D4486:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D44AC @ =0xFFFF0000
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_081D4492:
	adds r2, r4, #0
	asrs r0, r2, #0x10
	cmp r0, #0
	bge _081D44B0
	asrs r1, r6, #0x10
	cmn r0, r1
	bge _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r1
	b _081D44BE
	.align 2, 0
_081D44AC: .4byte 0xFFFF0000
_081D44B0:
	asrs r1, r6, #0x10
	cmp r0, r1
	ble _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r1, r0
_081D44BE:
	lsls r0, r0, #0x10
	ldr r1, _081D44E4 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
_081D44C8:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D44E8
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D44FA
	.align 2, 0
_081D44E4: .4byte 0x0000FFFF
_081D44E8:
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D44FA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D453C @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_081D4506:
	mov r1, ip
	adds r1, #0xfc
	adds r0, r4, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	asrs r0, r4, #0x10
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	adds r0, r5, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
_081D4530:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D453C: .4byte 0xFFFF0000

	thumb_func_start FUN_081d4540
FUN_081d4540: @ 0x081D4540
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _081D458C @ =0x03002BE0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D4584
	adds r0, r4, #0
	bl FUN_081d40b4
	adds r0, r4, #0
	bl FUN_081d42c4
	ldr r0, [r5]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D456A
	adds r0, r4, #0
	bl FUN_081d4590
_081D456A:
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	beq _081D457A
	adds r0, r4, #0
	bl FUN_081d4658
_081D457A:
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
_081D4584:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D458C: .4byte 0x03002BE0

	thumb_func_start FUN_081d4590
FUN_081d4590: @ 0x081D4590
	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D45CC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D45D0 @ =0x03002BE0
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _081D4642
	mov r0, ip
	adds r0, #0xd4
	ldr r3, _081D45D4 @ =0x000012B0
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D4642
	movs r2, #0x80
	lsls r2, r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081D45D8
	movs r0, #1
	b _081D45DA
	.align 2, 0
_081D45CC: .4byte 0x03000194
_081D45D0: .4byte 0x03002BE0
_081D45D4: .4byte 0x000012B0
_081D45D8:
	movs r0, #0
_081D45DA:
	cmp r0, #0
	bne _081D463A
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D464C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5a
	ldrh r1, [r1]
	ldrh r0, [r0, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D4650 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r1, #0x30]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldr r1, [r4]
	adds r1, #0x2c
	mov r0, sp
	mov r2, ip
	bl FUN_081d43d4
	ldr r0, [r4]
	mov r1, sp
	bl FUN_0807a91c
_081D463A:
	ldr r0, _081D4654 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081D4642:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D464C: .4byte 0xFFFF0000
_081D4650: .4byte 0x0000FFFF
_081D4654: .4byte 0xFFFFFEFF

	thumb_func_start FUN_081d4658
FUN_081d4658: @ 0x081D4658
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D46B0 @ =0x03000194
	ldr r0, [r0]
	ldr r1, _081D46B4 @ =0x000012B2
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D46F6
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r2, r5, #0
	adds r2, #0xfc
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D46B8
	movs r0, #1
	b _081D46BA
	.align 2, 0
_081D46B0: .4byte 0x03000194
_081D46B4: .4byte 0x000012B2
_081D46B8:
	movs r0, #0
_081D46BA:
	cmp r0, #0
	bne _081D46EE
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r2, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
_081D46EE:
	ldr r0, _081D4700 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_081D46F6:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D4700: .4byte 0xFFFFFDFF

	thumb_func_start FUN_081d4704
FUN_081d4704: @ 0x081D4704
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D479E
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r5, r7, #0
	adds r5, #0xfc
	mov r0, sp
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r6, r1, r0
	strh r6, [r3, #4]
	ldr r4, _081D47AC @ =0x085AE0D0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r2, r0
	bgt _081D479E
	movs r2, #0
	ldrsh r1, [r3, r2]
	cmn r1, r0
	blt _081D479E
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bgt _081D479E
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D479E
	adds r0, r5, #0
	bl FUN_08086a4c
	ldr r4, _081D47B0 @ =0x000012B2
	add r4, r8
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r1, [r1]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D479E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D47AC: .4byte 0x085AE0D0
_081D47B0: .4byte 0x000012B2

	thumb_func_start Elevator_Create
Elevator_Create: @ 0x081D47B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r0, _081D4824 @ =0x03000194
	ldr r0, [r0]
	str r0, [sp, #8]
	cmp r0, #0
	bne _081D47CC
	b _081D4E72
_081D47CC:
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	bl FUN_081d2314
	mov r8, r0
	cmp r0, #0
	bne _081D47DE
	b _081D4E72
_081D47DE:
	mov r4, r8
	adds r4, #0xb4
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r4]
	mov r5, r8
	adds r5, #0xb8
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r5]
	mov sb, r8
	movs r0, #0x72
	bl prepare_08231510
	mov sl, r4
	str r5, [sp, #0x1c]
	mov r1, r8
	adds r1, #0xe4
	str r1, [sp, #0x20]
	mov r2, r8
	adds r2, #0xe5
	str r2, [sp, #0x10]
	adds r1, #2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D4862
	bl VM_GetPC
	cmp r0, #0
	beq _081D4828
	bl Script_GetValue
	adds r1, r0, #0
	b _081D482A
	.align 2, 0
_081D4824: .4byte 0x03000194
_081D4828:
	movs r1, #0
_081D482A:
	mov r5, r8
	adds r5, #0xe4
	movs r0, #0
	strb r1, [r5]
	mov r4, r8
	adds r4, #0xe5
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x20]
	str r4, [sp, #0x10]
	cmp r0, #0
	beq _081D484A
	bl Script_GetValue
	b _081D484C
_081D484A:
	movs r0, #0
_081D484C:
	mov r4, r8
	adds r4, #0xe6
	strb r0, [r4]
	mov r0, sb
	adds r0, #0x1c
	ldr r2, [sp, #0x20]
	ldrb r1, [r2]
	ldrb r2, [r4]
	bl FUN_08234f90
	str r4, [sp, #0x14]
_081D4862:
	movs r0, #0x6b
	movs r1, #0
	bl Script_GetKeywordValue
	mov r4, r8
	adds r4, #0xe7
	strb r0, [r4]
	movs r0, #0x59
	bl prepare_08231510
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _081D4900
	subs r4, #0x1b
	bl VM_GetPC
	adds r5, r4, #0
	cmp r0, #0
	beq _081D488E
	bl Script_GetValue
	b _081D4890
_081D488E:
	movs r0, #0
_081D4890:
	str r0, [r4]
	mov r4, r8
	adds r4, #0xd0
	bl VM_GetPC
	adds r6, r4, #0
	cmp r0, #0
	beq _081D48A6
	bl Script_GetValue
	b _081D48A8
_081D48A6:
	movs r0, #0
_081D48A8:
	str r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _081D48BA
	bl Script_GetValue
	adds r2, r0, #0
	b _081D48BC
_081D48BA:
	movs r2, #0
_081D48BC:
	ldr r0, [sp, #0x18]
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D48F0
	ldr r0, [r5]
	cmp r2, r0
	bne _081D48DC
	mov r1, sb
	strh r2, [r1, #0x1e]
	movs r0, #3
	rsbs r0, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081D48F6
_081D48DC:
	ldr r0, [r6]
	cmp r2, r0
	bne _081D48F6
	mov r0, sb
	strh r2, [r0, #0x1e]
	mov r2, sl
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	b _081D48F6
_081D48F0:
	ldr r0, [r5]
	mov r1, sb
	strh r0, [r1, #0x1e]
_081D48F6:
	mov r2, sb
	ldrh r0, [r2, #0x1e]
	mov r1, r8
	adds r1, #0xfe
	strh r0, [r1]
_081D4900:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r6, r8
	adds r6, #0xd4
	strh r0, [r6]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, r8
	adds r1, #0xc0
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, r8
	adds r1, #0xc2
	strh r0, [r1]
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, r8
	adds r1, #0xc4
	strh r0, [r1]
	movs r0, #0x54
	movs r1, #0
	bl Script_GetKeywordValue
	mov r5, r8
	adds r5, #0xc8
	strh r0, [r5]
	mov r4, r8
	adds r4, #0x2c
	ldr r1, _081D4964 @ =0x0000B019
	adds r0, r4, #0
	bl FUN_0822b16c
	ldr r0, [sp, #0x18]
	ldrb r7, [r0]
	cmp r7, #1
	beq _081D4A1C
	cmp r7, #1
	bgt _081D4968
	cmp r7, #0
	beq _081D4974
	b _081D4B4E
	.align 2, 0
_081D4964: .4byte 0x0000B019
_081D4968:
	cmp r7, #2
	bne _081D496E
	b _081D4AA8
_081D496E:
	cmp r7, #3
	beq _081D49C8
	b _081D4B4E
_081D4974:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D49BC @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C0 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C4 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r4, #0
	bl FUN_0822b20c
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D49B8
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D49B8:
	strh r7, [r5]
	b _081D4B4E
	.align 2, 0
_081D49BC: .4byte FUN_081d3534
_081D49C0: .4byte FUN_081d3c24
_081D49C4: .4byte FUN_081d33f8
_081D49C8:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4A10 @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A14 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A18 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	bl FUN_0822b20c
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D4A9C
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	b _081D4A9C
	.align 2, 0
_081D4A10: .4byte FUN_081d3534
_081D4A14: .4byte FUN_081d3c24
_081D4A18: .4byte FUN_081d33f8
_081D4A1C:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r0, r8
	adds r0, #0xb2
	strh r7, [r0]
	mov r1, r8
	adds r1, #0xd8
	ldr r0, _081D4A54 @ =FUN_081d36c0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A58 @ =FUN_081d3dd0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A5C @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #2
	str r2, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4A70
	cmp r0, #1
	bgt _081D4A60
	cmp r0, #0
	beq _081D4A66
	b _081D4A84
	.align 2, 0
_081D4A54: .4byte FUN_081d36c0
_081D4A58: .4byte FUN_081d3dd0
_081D4A5C: .4byte FUN_081d33f8
_081D4A60:
	cmp r0, #2
	beq _081D4A7C
	b _081D4A84
_081D4A66:
	ldr r1, _081D4A6C @ =0x000001B9
	b _081D4A74
	.align 2, 0
_081D4A6C: .4byte 0x000001B9
_081D4A70:
	movs r1, #0xde
	lsls r1, r1, #1
_081D4A74:
	adds r0, r4, #0
	bl FUN_0822b20c
	b _081D4A84
_081D4A7C:
	ldr r1, _081D4AA4 @ =0x000001BD
	adds r0, r4, #0
	bl FUN_0822b20c
_081D4A84:
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D4A96
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D4A96:
	ldrh r0, [r5]
	cmp r0, #2
	bls _081D4B4E
_081D4A9C:
	movs r0, #0
	strh r0, [r5]
	b _081D4B4E
	.align 2, 0
_081D4AA4: .4byte 0x000001BD
_081D4AA8:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4AD8 @ =FUN_081d38a4
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4ADC @ =FUN_081d3a8c
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4AE0 @ =FUN_081d33f8
	str r0, [r1]
	movs r0, #0
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4AFC
	cmp r0, #1
	bgt _081D4AE4
	cmp r0, #0
	beq _081D4AEE
	b _081D4B20
	.align 2, 0
_081D4AD8: .4byte FUN_081d38a4
_081D4ADC: .4byte FUN_081d3a8c
_081D4AE0: .4byte FUN_081d33f8
_081D4AE4:
	cmp r0, #2
	beq _081D4B0C
	cmp r0, #3
	beq _081D4B18
	b _081D4B20
_081D4AEE:
	adds r0, r4, #0
	ldr r1, _081D4AF8 @ =0x000001B7
	bl FUN_0822b20c
	b _081D4B20
	.align 2, 0
_081D4AF8: .4byte 0x000001B7
_081D4AFC:
	adds r0, r4, #0
	ldr r1, _081D4B08 @ =0x000001B9
	bl FUN_0822b20c
	b _081D4B20
	.align 2, 0
_081D4B08: .4byte 0x000001B9
_081D4B0C:
	adds r0, r4, #0
	movs r1, #0xdf
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _081D4B20
_081D4B18:
	adds r0, r4, #0
	ldr r1, _081D4BA0 @ =0x000001BD
	bl FUN_0822b20c
_081D4B20:
	movs r0, #0x6d
	movs r1, #1
	bl Script_GetKeywordValue
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	movs r0, #0x77
	movs r1, #0x78
	bl Script_GetKeywordValue
	mov r7, r8
	adds r7, #0xbc
	strh r0, [r7]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D4B4E
	ldrh r0, [r7]
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
_081D4B4E:
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	mov r4, r8
	adds r4, #0x48
	ldr r2, [sp, #8]
	ldr r1, [r2, #0x18]
	ldr r2, [sp, #0xc]
	ldrb r3, [r5]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, r8
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, sb
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D4BA4
	mov r2, sb
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D4BB0
	.align 2, 0
_081D4BA0: .4byte 0x000001BD
_081D4BA4:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
_081D4BB0:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D4BD6
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D4BE0
_081D4BD6:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D4BE0:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D4C18 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D4C50
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D4C1C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D4C12
	ldrb r0, [r4, #5]
_081D4C12:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D4C2C
	.align 2, 0
_081D4C18: .4byte 0x0000FFFF
_081D4C1C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D4C2C
	strh r1, [r4, #8]
_081D4C2C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D4C50
	movs r0, #1
	strb r0, [r4, #7]
_081D4C50:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	movs r7, #0
	movs r0, #2
	strb r0, [r2, #7]
	mov r4, r8
	adds r4, #0xf4
	mov r0, r8
	adds r0, #0xb0
	ldr r2, _081D4D20 @ =0xFFFFD0E9
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sb
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0823b46c
	mov r5, r8
	adds r5, #0xe8
	ldr r1, [sp, #0x20]
	ldrb r2, [r1]
	ldr r0, [sp, #0x10]
	ldrb r3, [r0]
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0823b490
	str r7, [r4, #0x18]
	ldr r2, _081D4D24 @ =0xFFFFFF00
	adds r0, r2, #0
	mov r1, sb
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r5
	cmp r0, #0
	beq _081D4CD6
	movs r0, #0x80
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CD6:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D4CEE
	movs r0, #0x80
	lsls r0, r0, #5
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CEE:
	mov r1, r8
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xc6
	strh r7, [r0]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #0
	bne _081D4D0C
	b _081D4E26
_081D4D0C:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
	cmp r0, #2
	beq _081D4D34
	cmp r0, #2
	bgt _081D4D28
	cmp r0, #0
	blt _081D4D3C
	b _081D4D2C
	.align 2, 0
_081D4D20: .4byte 0xFFFFD0E9
_081D4D24: .4byte 0xFFFFFF00
_081D4D28:
	cmp r0, #3
	bne _081D4D3C
_081D4D2C:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	b _081D4D3A
_081D4D34:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
_081D4D3A:
	strh r0, [r1]
_081D4D3C:
	ldr r2, [sp, #8]
	ldr r0, _081D4DA0 @ =0x000012B0
	adds r4, r2, r0
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldr r4, _081D4DA4 @ =0x03002BE0
	ldr r0, [r4]
	ldrh r2, [r6]
	movs r1, #1
	bl FUN_0807a97c
	movs r0, #8
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [r4]
	ldr r0, _081D4DA8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1]
	mov r1, r8
	adds r1, #0xfc
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r7, r1, #0
	cmp r3, #0
	blt _081D4D9C
	cmp r2, #0
	blt _081D4D9C
	ldr r0, _081D4DAC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081D4D9C
	ldr r0, _081D4DB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081D4DB4
_081D4D9C:
	movs r2, #0
	b _081D4DC2
	.align 2, 0
_081D4DA0: .4byte 0x000012B0
_081D4DA4: .4byte 0x03002BE0
_081D4DA8: .4byte 0x0000060E
_081D4DAC: .4byte 0x030046A8
_081D4DB0: .4byte 0x030046AC
_081D4DB4:
	ldr r0, _081D4E84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r3
_081D4DC2:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, r8
	mov r1, r8
	adds r1, #0xfe
	ldrh r3, [r1]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	mov r2, sl
	ldrh r1, [r2]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081D4E88 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r7, #0
	bl FUN_0807a91c
	cmp r5, #2
	bne _081D4E26
	adds r0, r7, #0
	bl FUN_08086a4c
	ldr r0, [sp, #8]
	ldr r1, _081D4E8C @ =0x000012B2
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldrh r1, [r6]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4E26:
	ldr r0, [sp, #8]
	mov r1, r8
	bl FUN_081d4704
	movs r0, #0x73
	movs r1, #6
	bl Script_GetKeywordValue
	mov r2, r8
	adds r2, #0xba
	strh r0, [r2]
	ldr r0, [sp, #0x18]
	ldrb r4, [r0]
	cmp r4, #0
	blt _081D4E6A
	cmp r4, #1
	ble _081D4E4C
	cmp r4, #3
	bne _081D4E6A
_081D4E4C:
	mov r1, r8
	adds r1, #0xfc
	movs r0, #0
	ldrsh r3, [r2, r0]
	mov r0, sb
	adds r2, r3, #0
	bl FUN_081d2660
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D4E6A
	mov r1, r8
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D4E6A:
	mov r1, r8
	adds r1, #0xb7
	movs r0, #0
	strb r0, [r1]
_081D4E72:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D4E84: .4byte 0x030046A4
_081D4E88: .4byte 0x03002BE0
_081D4E8C: .4byte 0x000012B2

	thumb_func_start ElevatorController_Update
ElevatorController_Update: @ 0x081D4E90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov r3, r8
	adds r3, #0x1c
	ldr r0, _081D4EF0 @ =0x000012AC
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _081D4EAA
	b _081D4FC6
_081D4EAA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081D4EF4 @ =0x030047A4
	ldr r1, _081D4EF8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081D4ECA
	movs r1, #4
	ldr r0, _081D4EFC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F0C
_081D4ECA:
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D4F00 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D4F04 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D4F08 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	b _081D4FC6
	.align 2, 0
_081D4EF0: .4byte 0x000012AC
_081D4EF4: .4byte 0x030047A4
_081D4EF8: .4byte 0x030047A0
_081D4EFC: .4byte 0x03002BC0
_081D4F00: .4byte 0x00000261
_081D4F04: .4byte 0x00000289
_081D4F08: .4byte 0x0000028A
_081D4F0C:
	ldr r0, _081D4F40 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4FC6
	movs r0, #0
	mov sb, r0
	mov r6, r8
	adds r6, #0x38
	mov r7, r8
	adds r7, #0xce
	mov r5, r8
	adds r5, #0xf4
	adds r4, r3, #0
_081D4F2A:
	ldr r0, _081D4F44 @ =0x000012AC
	add r0, r8
	movs r1, #1
	mov r2, sb
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F48
	movs r0, #1
	b _081D4F4A
	.align 2, 0
_081D4F40: .4byte 0x030044BC
_081D4F44: .4byte 0x000012AC
_081D4F48:
	movs r0, #0
_081D4F4A:
	cmp r0, #0
	beq _081D4FAA
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #6
	beq _081D4FAA
	ldr r1, [r5]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _081D4FD4 @ =0x085AE0E8
	movs r2, #0
	ldrsh r0, [r7, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #4]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #8]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_081d31f0
	adds r0, r4, #0
	bl FUN_081d4540
	adds r0, r4, #0
	bl FUN_081d276c
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	str r0, [r6]
	str r1, [r6, #4]
	ldr r1, _081D4FD8 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r6]
	adds r0, r0, r2
	strh r0, [r6]
	adds r0, r4, #0
	bl FUN_081d2f04
_081D4FAA:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r7, r7, r0
	adds r5, r5, r0
	adds r4, r4, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xb
	ble _081D4F2A
	mov r0, r8
	bl FUN_081d2a64
_081D4FC6:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D4FD4: .4byte 0x085AE0E8
_081D4FD8: .4byte 0xFFFFFF00

	thumb_func_start ElevatorController_Destroy
ElevatorController_Destroy: @ 0x081D4FDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D502C @ =0x00000261
	bl sound_08240740
	ldr r0, _081D5030 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D5034 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	movs r7, #0
	movs r0, #1
	mov sb, r0
	mov r6, r8
	adds r6, #0xd0
	mov r5, r8
	adds r5, #0x1c
_081D5016:
	ldr r0, _081D5038 @ =0x000012AC
	add r0, r8
	mov r1, sb
	lsls r1, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D503C
	movs r0, #1
	b _081D503E
	.align 2, 0
_081D502C: .4byte 0x00000261
_081D5030: .4byte 0x00000289
_081D5034: .4byte 0x0000028A
_081D5038: .4byte 0x000012AC
_081D503C:
	movs r0, #0
_081D503E:
	cmp r0, #0
	beq _081D5076
	adds r4, r5, #0
	ldrh r0, [r6]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _081D5052
	movs r0, #1
	b _081D5054
_081D5052:
	movs r0, #0
_081D5054:
	cmp r0, #0
	beq _081D5062
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
_081D5062:
	adds r0, r4, #0
	bl FUN_081d3188
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_0822a4e0
_081D5076:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #0xb
	ble _081D5016
	movs r1, #0
	ldr r0, _081D5098 @ =0x03000194
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D5098: .4byte 0x03000194

	thumb_func_start FUN_081d509c
FUN_081d509c: @ 0x081D509C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D50BC @ =0x0000922E
	ldr r1, _081D50C0 @ =0x000013F9
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D50C4 @ =0x03000194
	str r4, [r0]
	ldr r0, _081D50C8 @ =0x000012AC
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D50BC: .4byte 0x0000922E
_081D50C0: .4byte 0x000013F9
_081D50C4: .4byte 0x03000194
_081D50C8: .4byte 0x000012AC

	thumb_func_start ElevatorController_Create
ElevatorController_Create: @ 0x081D50CC
	push {r4, lr}
	ldr r0, _081D5100 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	bne _081D5112
	ldr r1, _081D5104 @ =0x000012B8
	movs r0, #5
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5110
	ldr r1, _081D5108 @ =ElevatorController_Update
	ldr r2, _081D510C @ =ElevatorController_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d509c
	cmp r0, #0
	bge _081D5110
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D5112
	.align 2, 0
_081D5100: .4byte 0x03000194
_081D5104: .4byte 0x000012B8
_081D5108: .4byte ElevatorController_Update
_081D510C: .4byte ElevatorController_Destroy
_081D5110:
	adds r0, r4, #0
_081D5112:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d5118
FUN_081d5118: @ 0x081D5118
	ldr r1, _081D5120 @ =0x03000194
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D5120: .4byte 0x03000194

	thumb_func_start Elevator_Shake
Elevator_Shake: @ 0x081D5124
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5158 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5152
	cmp r1, #0
	beq _081D5152
	adds r0, r1, #0
	bl FUN_081d3118
	adds r2, r0, #0
	cmp r2, #0
	beq _081D5152
	movs r0, #0x20
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D5152:
	pop {r0}
	bx r0
	.align 2, 0
_081D5158: .4byte 0x03000194

	thumb_func_start FUN_081d515c
FUN_081d515c: @ 0x081D515C
	push {r4, r5, r6, r7, lr}
	ldr r0, _081D5180 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D51D4
	adds r4, r0, #0
	ldr r0, _081D5184 @ =0x000012AC
	adds r5, r4, r0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D51D4
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D5190
	b _081D51D4
	.align 2, 0
_081D5180: .4byte 0x03000194
_081D5184: .4byte 0x000012AC
_081D5188:
	adds r0, r4, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	b _081D51D8
_081D5190:
	movs r3, #0
	ldr r6, [r5]
	movs r7, #0x10
	adds r2, r4, #0
	adds r2, #0xd0
	adds r1, r4, #0
	adds r1, #0x1c
	movs r5, #0xc6
	lsls r5, r5, #1
_081D51A2:
	movs r0, #1
	lsls r0, r3
	ands r0, r6
	cmp r0, #0
	beq _081D51B0
	movs r0, #1
	b _081D51B2
_081D51B0:
	movs r0, #0
_081D51B2:
	cmp r0, #0
	beq _081D51CA
	adds r4, r1, #0
	ldrh r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _081D51C4
	movs r0, #1
	b _081D51C6
_081D51C4:
	movs r0, #0
_081D51C6:
	cmp r0, #0
	bne _081D5188
_081D51CA:
	adds r2, r2, r5
	adds r1, r1, r5
	adds r3, #1
	cmp r3, #0xb
	ble _081D51A2
_081D51D4:
	movs r0, #1
	rsbs r0, r0, #0
_081D51D8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Elevator_Start
Elevator_Start: @ 0x081D51E0
	push {r4, r5, r6, lr}
	movs r0, #0x6d
	movs r1, #1
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5238 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5260
	cmp r1, #0
	beq _081D5260
	adds r0, r1, #0
	bl FUN_081d3118
	adds r3, r0, #0
	cmp r3, #0
	beq _081D5260
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r6, #2
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081D5260
	adds r0, r3, #0
	adds r0, #0xb2
	movs r5, #0
	strh r2, [r0]
	cmp r4, #4
	bne _081D523C
	adds r0, #2
	mvns r1, r6
	ldrh r2, [r0]
	ands r1, r2
	orrs r1, r4
	strh r1, [r0]
	b _081D5260
	.align 2, 0
_081D5238: .4byte 0x03000194
_081D523C:
	adds r1, r3, #0
	adds r1, #0xb4
	movs r2, #5
	rsbs r2, r2, #0
	ldrh r0, [r1]
	ands r2, r0
	strh r2, [r1]
	cmp r4, #2
	bne _081D5254
	orrs r4, r2
	strh r4, [r1]
	b _081D525A
_081D5254:
	mvns r0, r6
	ands r0, r2
	strh r0, [r1]
_081D525A:
	adds r0, r3, #0
	bl FUN_081d21d8
_081D5260:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5268
FUN_081d5268: @ 0x081D5268
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D529C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5296
	cmp r1, #0
	beq _081D5296
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6d
	bl Script_GetKeywordValue
	adds r4, #0xd6
	strh r0, [r4]
_081D5296:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D529C: .4byte 0x03000194

	thumb_func_start FUN_081d52a0
FUN_081d52a0: @ 0x081D52A0
	push {r4, r5, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r5, _081D52D4 @ =0x03000194
	ldr r0, [r5]
	cmp r0, #0
	beq _081D5332
	cmp r1, #0
	beq _081D5332
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	ldr r5, [r5]
	movs r1, #1
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D52D8
	movs r0, #1
	b _081D52DA
	.align 2, 0
_081D52D4: .4byte 0x03000194
_081D52D8:
	movs r0, #0
_081D52DA:
	cmp r0, #0
	beq _081D52F6
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
	adds r2, r4, #0
	adds r2, #0xb4
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D52F6:
	adds r0, r4, #0
	bl FUN_081d3188
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r1, r4, #0
	adds r1, #0xd4
	movs r0, #0
	strh r0, [r1]
	subs r1, #0x22
	movs r0, #6
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r3, r4, #0
	adds r3, #0xb0
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D5338 @ =0x000012AC
	adds r2, r5, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D533C @ =0x0000FFFF
	strh r0, [r3]
_081D5332:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D5338: .4byte 0x000012AC
_081D533C: .4byte 0x0000FFFF

	thumb_func_start FUN_081d5340
FUN_081d5340: @ 0x081D5340
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5388 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D53C2
	cmp r1, #0
	beq _081D53C2
	adds r0, r1, #0
	bl FUN_081d3118
	adds r6, r0, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	movs r5, #0
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _081D53AA
	bl VM_GetPC
	cmp r0, #0
	beq _081D538C
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _081D538E
	.align 2, 0
_081D5388: .4byte 0x03000194
_081D538C:
	movs r1, #0
_081D538E:
	adds r7, r1, #0
	movs r1, #0
	mov r8, r1
	bl VM_GetPC
	cmp r0, #0
	beq _081D53A6
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	b _081D53A8
_081D53A6:
	movs r3, #0
_081D53A8:
	adds r5, r3, #0
_081D53AA:
	adds r4, r6, #0
	adds r4, #0xe8
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, r8
	adds r3, r5, #0
	bl FUN_08234de8
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
_081D53C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d53cc
FUN_081d53cc: @ 0x081D53CC
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D540C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5406
	cmp r1, #0
	beq _081D5406
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5406
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r2, _081D5410 @ =0x000001B7
	adds r1, r1, r2
	bl FUN_0822b20c
_081D5406:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D540C: .4byte 0x03000194
_081D5410: .4byte 0x000001B7

	thumb_func_start FUN_081d5414
FUN_081d5414: @ 0x081D5414
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D544C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5446
	cmp r1, #0
	beq _081D5446
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5446
	movs r0, #0x73
	movs r1, #6
	bl Script_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
_081D5446:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D544C: .4byte 0x03000194

	thumb_func_start FUN_081d5450
FUN_081d5450: @ 0x081D5450
	push {r4, r5, lr}
	ldr r0, _081D5498 @ =0x03000194
	ldr r4, [r0]
	bl FUN_081d3150
	adds r5, r0, #0
	ldr r0, _081D549C @ =0x000012B0
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	ldr r4, _081D54A0 @ =0x03002BE0
	ldr r0, [r4]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r0, r2
	str r1, [r0, #0x3c]
	movs r1, #1
	bl FUN_0807a99c
	adds r5, #0xb4
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r1, [r4]
	ldr r0, _081D54A4 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D5498: .4byte 0x03000194
_081D549C: .4byte 0x000012B0
_081D54A0: .4byte 0x03002BE0
_081D54A4: .4byte 0x0000060E

	thumb_func_start FUN_081d54a8
FUN_081d54a8: @ 0x081D54A8
	push {r4, r5, r6, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5500 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D54F8
	cmp r1, #0
	beq _081D54F8
	adds r0, r1, #0
	bl FUN_081d3118
	adds r5, r0, #0
	cmp r5, #0
	beq _081D54F8
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x68
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6c
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	cmp r6, #0
	ble _081D54EE
	adds r0, r5, #0
	adds r0, #0xd0
	str r6, [r0]
_081D54EE:
	cmp r1, #0
	ble _081D54F8
	adds r0, r5, #0
	adds r0, #0xcc
	str r1, [r0]
_081D54F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D5500: .4byte 0x03000194

	thumb_func_start FUN_081d5504
FUN_081d5504: @ 0x081D5504
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5534 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5530
	cmp r1, #0
	beq _081D5530
	adds r0, r1, #0
	bl FUN_081d3118
	cmp r0, #0
	beq _081D5530
	adds r0, #0xb4
	ldr r1, _081D5538 @ =0xFFFFEFFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081D5530:
	pop {r0}
	bx r0
	.align 2, 0
_081D5534: .4byte 0x03000194
_081D5538: .4byte 0xFFFFEFFF

	thumb_func_start FUN_081d553c
FUN_081d553c: @ 0x081D553C
	push {lr}
	adds r1, r0, #0
	ldr r0, _081D555C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5560
	cmp r1, #0
	beq _081D5560
	adds r0, r1, #0
	bl FUN_081d3118
	cmp r0, #0
	beq _081D5560
	adds r0, #0xfc
	b _081D5562
	.align 2, 0
_081D555C: .4byte 0x03000194
_081D5560:
	movs r0, #0
_081D5562:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5568
FUN_081d5568: @ 0x081D5568
	push {lr}
	adds r1, r0, #0
	ldr r0, _081D557C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5580
	adds r0, r1, #0
	adds r0, #0xfc
	b _081D5582
	.align 2, 0
_081D557C: .4byte 0x03000194
_081D5580:
	movs r0, #0
_081D5582:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5588
FUN_081d5588: @ 0x081D5588
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D5600 @ =0x03000194
	ldr r4, [r0]
	cmp r4, #0
	bne _081D5596
	b _081D5814
_081D5596:
	adds r6, r5, #0
	adds r6, #0xd6
	ldrh r1, [r6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081D55D2
	ldr r0, _081D5604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D55B4
	b _081D5814
_081D55B4:
	ldr r1, _081D5608 @ =0x000012B0
	adds r0, r4, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081D55C6
	b _081D5814
_081D55C6:
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D55D2
	b _081D5814
_081D55D2:
	adds r0, r5, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D55FA
	cmp r1, #0
	blt _081D55FA
	ldr r0, _081D560C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D55FA
	ldr r0, _081D5610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D5614
_081D55FA:
	movs r7, #0
	b _081D5622
	.align 2, 0
_081D5600: .4byte 0x03000194
_081D5604: .4byte 0x03002BE0
_081D5608: .4byte 0x000012B0
_081D560C: .4byte 0x030046A8
_081D5610: .4byte 0x030046AC
_081D5614:
	ldr r0, _081D5640 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_081D5622:
	adds r0, r5, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	adds r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5644
	adds r0, #4
	b _081D5650
	.align 2, 0
_081D5640: .4byte 0x030046A4
_081D5644:
	ldr r0, _081D566C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5650:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D5686
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5670
	adds r0, #4
	b _081D567C
	.align 2, 0
_081D566C: .4byte 0x030046A4
_081D5670:
	ldr r0, _081D568C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D567C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5690
_081D5686:
	movs r0, #0
	b _081D5692
	.align 2, 0
_081D568C: .4byte 0x030046A4
_081D5690:
	movs r0, #1
_081D5692:
	cmp r0, #0
	beq _081D56A4
	ldr r0, _081D56A0 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D56A6
	.align 2, 0
_081D56A0: .4byte 0x00000151
_081D56A4:
	movs r0, #0
_081D56A6:
	cmp r0, #0
	beq _081D56AC
	b _081D5814
_081D56AC:
	subs r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56BE
	adds r0, #4
	b _081D56CA
_081D56BE:
	ldr r0, _081D56E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56CA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D56FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56E8
	adds r0, #4
	b _081D56F4
	.align 2, 0
_081D56E4: .4byte 0x030046A4
_081D56E8:
	ldr r0, _081D5704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5708
_081D56FE:
	movs r0, #0
	b _081D570A
	.align 2, 0
_081D5704: .4byte 0x030046A4
_081D5708:
	movs r0, #1
_081D570A:
	cmp r0, #0
	beq _081D571C
	ldr r0, _081D5718 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D571E
	.align 2, 0
_081D5718: .4byte 0x00000151
_081D571C:
	movs r0, #0
_081D571E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D5740 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5744
	adds r0, #4
	b _081D574E
	.align 2, 0
_081D5740: .4byte 0x030046A4
_081D5744:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D574E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D577E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5768
	adds r0, #4
	b _081D5774
_081D5768:
	ldr r0, _081D5784 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5774:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5788
_081D577E:
	movs r0, #0
	b _081D578A
	.align 2, 0
_081D5784: .4byte 0x030046A4
_081D5788:
	movs r0, #1
_081D578A:
	cmp r0, #0
	beq _081D579C
	ldr r0, _081D5798 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D579E
	.align 2, 0
_081D5798: .4byte 0x00000151
_081D579C:
	movs r0, #0
_081D579E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D57C0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57C4
	adds r0, #4
	b _081D57CE
	.align 2, 0
_081D57C0: .4byte 0x030046A4
_081D57C4:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D57CE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D57FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57E8
	adds r0, #4
	b _081D57F4
_081D57E8:
	ldr r0, _081D5804 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D57F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5808
_081D57FE:
	movs r0, #0
	b _081D580A
	.align 2, 0
_081D5804: .4byte 0x030046A4
_081D5808:
	movs r0, #1
_081D580A:
	cmp r0, #0
	beq _081D5814
	ldr r0, _081D581C @ =0x00000151
	bl PlaySound_082406e0
_081D5814:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D581C: .4byte 0x00000151

	thumb_func_start FUN_081d5820
FUN_081d5820: @ 0x081D5820
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5834
FUN_081d5834: @ 0x081D5834
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5848
FUN_081d5848: @ 0x081D5848
	push {lr}
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D585C
	movs r0, #0
	b _081D585E
_081D585C:
	movs r0, #1
_081D585E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5864
FUN_081d5864: @ 0x081D5864
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r1, _081D588C @ =0x0000057C
	adds r2, r0, r1
	movs r3, #1
	movs r7, #0xac
	lsls r7, r7, #1
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081D587C:
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D5890
	movs r0, #1
	b _081D5892
	.align 2, 0
_081D588C: .4byte 0x0000057C
_081D5890:
	movs r0, #0
_081D5892:
	cmp r0, #0
	bne _081D58AE
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r1, r7, #0
	bl ClearMemory
	strh r5, [r6]
	adds r0, r4, #0
	b _081D58BE
_081D58AE:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081D587C
	movs r0, #0
_081D58BE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d58c4
FUN_081d58c4: @ 0x081D58C4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081D58D4 @ =0x03000198
	ldr r1, [r0]
	cmp r1, #0
	bne _081D58DC
	b _081D591A
	.align 2, 0
_081D58D4: .4byte 0x03000198
_081D58D8:
	adds r0, r1, #0
	b _081D591C
_081D58DC:
	movs r2, #0
	ldr r3, _081D58F8 @ =0x0000057C
	adds r0, r1, r3
	ldr r3, [r0]
	movs r5, #1
	adds r1, #0x1c
_081D58E8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r3
	cmp r0, #0
	beq _081D58FC
	movs r0, #1
	b _081D58FE
	.align 2, 0
_081D58F8: .4byte 0x0000057C
_081D58FC:
	movs r0, #0
_081D58FE:
	cmp r0, #0
	beq _081D590E
	movs r6, #0xa8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, r4
	beq _081D58D8
_081D590E:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #3
	ble _081D58E8
_081D591A:
	movs r0, #0
_081D591C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5924
FUN_081d5924: @ 0x081D5924
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D59A8 @ =0x03000198
	ldr r6, [r0]
	cmp r6, #0
	bne _081D5944
	bl FUN_081d63ec
	adds r6, r0, #0
	cmp r6, #0
	bne _081D5944
	b _081D5C9C
_081D5944:
	adds r0, r6, #0
	bl FUN_081d5864
	adds r5, r0, #0
	cmp r5, #0
	bne _081D5952
	b _081D5C9C
_081D5952:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D59AC @ =0x00009385
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0x6d
	bl Script_GetKeywordValue
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D59B0
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _081D59B8
	.align 2, 0
_081D59A8: .4byte 0x03000198
_081D59AC: .4byte 0x00009385
_081D59B0:
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_081D59B8:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _081D59D4
	bl Script_GetValue
	strh r0, [r7, #0x1c]
	bl Script_GetValue
	strh r0, [r7, #0x1e]
	bl Script_GetValue
	strh r0, [r7, #0x20]
_081D59D4:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x61
	bl Script_GetKeywordValue
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	str r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081D5A44 @ =0x0000013D
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081D5AC2
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A48
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5A4A
	.align 2, 0
_081D5A44: .4byte 0x0000013D
_081D5A48:
	movs r1, #0
_081D5A4A:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A60
	bl Script_GetValue
	b _081D5A62
_081D5A60:
	movs r0, #0
_081D5A62:
	ldr r2, _081D5A78 @ =0x00000147
	adds r1, r5, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A7C
	bl Script_GetValue
	b _081D5A7E
	.align 2, 0
_081D5A78: .4byte 0x00000147
_081D5A7C:
	movs r0, #0
_081D5A7E:
	movs r3, #0xa3
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A94
	bl Script_GetValue
	b _081D5A96
_081D5A94:
	movs r0, #0
_081D5A96:
	mov sl, r0
	bl VM_GetPC
	cmp r0, #0
	beq _081D5AA8
	bl Script_GetValue
	mov sb, r0
	b _081D5AAC
_081D5AA8:
	movs r1, #0
	mov sb, r1
_081D5AAC:
	bl VM_GetPC
	cmp r0, #0
	beq _081D5ABC
	bl Script_GetValue
	mov r8, r0
	b _081D5AE6
_081D5ABC:
	movs r2, #0
	mov r8, r2
	b _081D5AE6
_081D5AC2:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x64
	strh r0, [r1]
	adds r0, #0xe3
	adds r1, r5, r0
	movs r0, #3
	strb r0, [r1]
	movs r2, #0xa3
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sl, r3
	mov sb, r3
	mov r8, r3
_081D5AE6:
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r3, #5
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, #1
	bl Div
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _081D5B32
	bl VM_GetPC
	cmp r0, #0
	beq _081D5B28
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5B2A
_081D5B28:
	movs r1, #0
_081D5B2A:
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_081D5B32:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _081D5B76
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x60
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl FUN_08013ba8
	movs r2, #0xa7
	lsls r2, r2, #1
	adds r1, r5, r2
	b _081D5BA6
_081D5B76:
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x80
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl FUN_08013ba8
	movs r3, #0xa7
	lsls r3, r3, #1
	adds r1, r5, r3
_081D5BA6:
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D5BEE
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D5BF6
_081D5BEE:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D5BF6:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D5C1A
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D5C22
_081D5C1A:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D5C22:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081D5C58 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D5C90
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D5C5C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D5C52
	ldrb r0, [r4, #5]
_081D5C52:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D5C6C
	.align 2, 0
_081D5C58: .4byte 0x0000FFFF
_081D5C5C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D5C6C
	strh r1, [r4, #8]
_081D5C6C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D5C90
	movs r0, #1
	strb r0, [r4, #7]
_081D5C90:
	adds r0, r5, #0
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl FUN_081d66c0
_081D5C9C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d5cac
FUN_081d5cac: @ 0x081D5CAC
	push {r4, lr}
	mov ip, r0
	mov r4, ip
	mov r2, ip
	adds r2, #0x9c
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D5CCE
	mov r3, ip
	adds r3, #0x5e
	ldrh r0, [r3]
	movs r1, #4
	orrs r1, r0
	strh r1, [r3]
	ldrh r0, [r2]
	subs r0, #1
	b _081D5CD8
_081D5CCE:
	mov r2, ip
	adds r2, #0x5e
	ldrh r1, [r2]
	ldr r0, _081D5CF8 @ =0x0000FFFB
	ands r0, r1
_081D5CD8:
	strh r0, [r2]
	ldr r0, _081D5CFC @ =0x00000153
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D5D00
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _081D5D0C
	.align 2, 0
_081D5CF8: .4byte 0x0000FFFB
_081D5CFC: .4byte 0x00000153
_081D5D00:
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0xbe
	lsls r1, r1, #1
	bl FUN_0822b20c
_081D5D0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5d14
FUN_081d5d14: @ 0x081D5D14
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5d18
FUN_081d5d18: @ 0x081D5D18
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D5D40
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	strb r2, [r3]
_081D5D40:
	adds r0, r4, #0
	bl FUN_081d5cac
	adds r0, r4, #0
	bl FUN_081d6444
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D5D62
	adds r0, r4, #0
	bl FUN_081d6c24
_081D5D62:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5d70
FUN_081d5d70: @ 0x081D5D70
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D5D84
	b _081D5E88
_081D5D84:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0
	movs r2, #0
	strh r2, [r0]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	strb r3, [r4]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	str r2, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081D5DE0 @ =0x05000002
	bl CpuSet
	movs r0, #0x29
	strh r0, [r4]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x94
	strh r0, [r1]
	movs r0, #0
	ldrsh r3, [r4, r0]
	ldr r2, _081D5DE4 @ =0x085B0A08
	ldrb r0, [r5, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D5DE8
	asrs r0, r0, #0xc
	b _081D5DEE
	.align 2, 0
_081D5DE0: .4byte 0x05000002
_081D5DE4: .4byte 0x085B0A08
_081D5DE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5DEE:
	adds r6, r0, #0
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r3, [r0, r4]
	ldr r1, _081D5E14 @ =0x085B0A08
	ldrb r2, [r5, #6]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r7, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _081D5E18
	asrs r0, r0, #0xc
	b _081D5E1E
	.align 2, 0
_081D5E14: .4byte 0x085B0A08
_081D5E18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5E1E:
	adds r6, r6, r0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D5E3E
	asrs r0, r0, #0xc
	b _081D5E42
_081D5E3E:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D5E42:
	adds r3, r0, #0
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D5E68
	asrs r2, r0, #0xc
	b _081D5E6E
_081D5E68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D5E6E:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, r0, r6
	strh r0, [r5, #0x1c]
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r1, r5, r4
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
_081D5E88:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D5F36
	adds r0, r5, #0
	bl FUN_081d6cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D5F36
	ldr r2, _081D5F24 @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081D5F36
	ldr r0, _081D5F28 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _081D5EC6
	ldr r0, _081D5F2C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D5EC6
	movs r1, #1
_081D5EC6:
	cmp r1, #0
	bne _081D5F36
	ldr r0, [r2]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D5F36
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _081D5F36
	subs r4, #0x10
	adds r1, r5, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _081D5F36
	movs r0, #4
	strh r0, [r1]
	adds r4, #0x24
	adds r1, r5, r4
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081D5F30
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #3
	strh r1, [r0]
	movs r2, #0xab
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081D5F48
	.align 2, 0
_081D5F24: .4byte 0x03002BE0
_081D5F28: .4byte 0x03002B8C
_081D5F2C: .4byte 0x03002B60
_081D5F30:
	ldr r0, _081D5F50 @ =0x000003C9
	bl PlaySound_082406e0
_081D5F36:
	adds r0, r5, #0
	bl FUN_081d5f54
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D5F48:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D5F50: .4byte 0x000003C9

	thumb_func_start FUN_081d5f54
FUN_081d5f54: @ 0x081D5F54
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldrb r1, [r0, #6]
	cmp r1, #0x80
	ble _081D5F68
	ldr r0, _081D5F64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081D5F76
	.align 2, 0
_081D5F64: .4byte 0xFFFFFF00
_081D5F68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081D5F76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081D5F76:
	adds r5, r1, #0
	cmp r5, #0
	bne _081D5F8C
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081D5F8C
	b _081D60C0
_081D5F8C:
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r3, _081D5FBC @ =0x085B0A08
	mov r0, ip
	ldrb r2, [r0, #6]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r0, #0
	blt _081D5FC0
	asrs r0, r0, #0xc
	b _081D5FC6
	.align 2, 0
_081D5FBC: .4byte 0x085B0A08
_081D5FC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FC6:
	adds r2, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D5FE4
	asrs r0, r0, #0xc
	b _081D5FEA
_081D5FE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FEA:
	adds r7, r2, r0
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D600A
	asrs r0, r0, #0xc
	b _081D600E
_081D600A:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D600E:
	adds r3, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D6034
	asrs r2, r0, #0xc
	b _081D603A
_081D6034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D603A:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r0, r0, r7
	mov r1, ip
	strh r0, [r1, #0x1c]
	movs r1, #0x8c
	lsls r1, r1, #1
	add r1, ip
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x20]
	movs r1, #0x8e
	lsls r1, r1, #1
	add r1, ip
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _081D6080
	cmp r5, #0
	ble _081D6076
	mov r1, ip
	ldrb r0, [r1, #6]
	subs r0, #1
	strb r0, [r1, #6]
	b _081D60C0
_081D6076:
	mov r2, ip
	ldrb r0, [r2, #6]
	adds r0, #1
	strb r0, [r2, #6]
	b _081D60C0
_081D6080:
	mov r3, ip
	ldrb r0, [r3, #6]
	adds r0, r2, r0
	strb r0, [r3, #6]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _081D609A
	cmp r5, r0
	ble _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	b _081D60C0
_081D609A:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r5, r0
	bge _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _081D60B2
	asrs r1, r0, #1
	b _081D60B8
_081D60B2:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081D60B8:
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
_081D60C0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d60c8
FUN_081d60c8: @ 0x081D60C8
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D618C
	adds r0, r5, #0
	adds r0, #0x1c
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D6104
	cmp r1, #0
	blt _081D6104
	ldr r0, _081D6108 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D6104
	ldr r0, _081D610C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D6110
_081D6104:
	movs r4, #0
	b _081D611E
	.align 2, 0
_081D6108: .4byte 0x030046A8
_081D610C: .4byte 0x030046AC
_081D6110:
	ldr r0, _081D6130 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D611E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D6134
	adds r0, #4
	b _081D6140
	.align 2, 0
_081D6130: .4byte 0x030046A4
_081D6134:
	ldr r0, _081D6154 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D6140:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081D6158
	cmp r2, #2
	beq _081D615C
	b _081D6160
	.align 2, 0
_081D6154: .4byte 0x030046A4
_081D6158:
	ldrb r0, [r6, #4]
	b _081D615E
_081D615C:
	ldrb r0, [r6]
_081D615E:
	subs r3, r3, r0
_081D6160:
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	movs r2, #0
	strh r3, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r5, r0
	str r2, [sp, #0x20]
	add r0, sp, #0x20
	ldr r2, _081D6188 @ =0x05000002
	bl CpuSet
	b _081D61F6
	.align 2, 0
_081D6188: .4byte 0x05000002
_081D618C:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r5, #0x1e]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _081D61F6
	strh r1, [r5, #0x1e]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #4
	strh r1, [r0]
	movs r0, #1
	strb r0, [r3]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x1c
	movs r5, #1
_081D61C8:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #7
	ble _081D61C8
_081D61F6:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d6200
FUN_081d6200: @ 0x081D6200
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	ldrb r6, [r0]
	cmp r6, #0
	beq _081D627C
	adds r0, r5, #0
	bl FUN_081d6764
	ldr r1, _081D6270 @ =0x0000013D
	adds r6, r5, r1
	ldrb r0, [r6]
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrb r1, [r4]
	subs r0, r0, r1
	cmp r0, #0
	blt _081D6238
	ldr r0, _081D6274 @ =0x000003C7
	bl PlaySound_082406e0
_081D6238:
	ldrb r1, [r6]
	ldrb r0, [r4]
	subs r1, r1, r0
	adds r0, r5, #0
	bl FUN_081d6ae8
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D6262
	adds r0, r5, #0
	adds r0, #0xa8
	bl FUN_08013c70
	movs r0, #0xff
	strb r0, [r4]
_081D6262:
	ldr r0, _081D6278 @ =0x000003C6
	bl PlaySound_082406e0
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	b _081D62B4
	.align 2, 0
_081D6270: .4byte 0x0000013D
_081D6274: .4byte 0x000003C7
_081D6278: .4byte 0x000003C6
_081D627C:
	ldr r0, [r5]
	movs r4, #1
	orrs r0, r4
	str r0, [r5]
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x58
	bl FUN_08236424
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r6, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r3, _081D62C0 @ =0x0000057C
	adds r1, r7, r3
	lsls r4, r0
	ldr r0, [r1]
	bics r0, r4
	str r0, [r1]
	ldr r0, _081D62C4 @ =0x0000FFFF
	strh r0, [r2]
_081D62B4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D62C0: .4byte 0x0000057C
_081D62C4: .4byte 0x0000FFFF

	thumb_func_start FUN_081d62c8
FUN_081d62c8: @ 0x081D62C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D62F8 @ =0x0000057C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D632A
	movs r4, #0
	ldr r2, _081D62F8 @ =0x0000057C
	adds r6, r5, r2
	ldr r0, _081D62FC @ =0x085AE104
	mov r8, r0
_081D62E8:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6300
	movs r0, #1
	b _081D6302
	.align 2, 0
_081D62F8: .4byte 0x0000057C
_081D62FC: .4byte 0x085AE104
_081D6300:
	movs r0, #0
_081D6302:
	cmp r0, #0
	beq _081D6324
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D6324:
	adds r4, #1
	cmp r4, #3
	ble _081D62E8
_081D632A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6338
FUN_081d6338: @ 0x081D6338
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _081D6364 @ =0x0000057C
	adds r0, r0, r7
	mov r8, r0
	movs r2, #1
	rsbs r2, r2, #0
	mov sb, r2
_081D6350:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6368
	movs r0, #1
	b _081D636A
	.align 2, 0
_081D6364: .4byte 0x0000057C
_081D6368:
	movs r0, #0
_081D636A:
	cmp r0, #0
	beq _081D63A0
	movs r0, #0xac
	lsls r0, r0, #1
	muls r0, r6, r0
	adds r0, #0x1c
	adds r4, r7, r0
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x58
	bl FUN_08236424
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, sb
	beq _081D63A0
	adds r0, r4, #0
	adds r0, #0xa8
	bl FUN_08013c70
	movs r0, #0xff
	strb r0, [r5]
_081D63A0:
	adds r6, #1
	cmp r6, #3
	ble _081D6350
	ldr r1, _081D63B8 @ =0x03000198
	movs r0, #0
	str r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D63B8: .4byte 0x03000198

	thumb_func_start FUN_081d63bc
FUN_081d63bc: @ 0x081D63BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D63DC @ =0x0000922E
	ldr r1, _081D63E0 @ =0x000074C9
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D63E4 @ =0x03000198
	str r4, [r0]
	ldr r0, _081D63E8 @ =0x0000057C
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D63DC: .4byte 0x0000922E
_081D63E0: .4byte 0x000074C9
_081D63E4: .4byte 0x03000198
_081D63E8: .4byte 0x0000057C

	thumb_func_start FUN_081d63ec
FUN_081d63ec: @ 0x081D63EC
	push {r4, lr}
	ldr r0, _081D6424 @ =0x03000198
	ldr r0, [r0]
	cmp r0, #0
	bne _081D6432
	movs r1, #0xb0
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D6430
	ldr r1, _081D6428 @ =FUN_081d62c8
	ldr r2, _081D642C @ =FUN_081d6338
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d63bc
	cmp r0, #0
	bge _081D6430
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D6432
	.align 2, 0
_081D6424: .4byte 0x03000198
_081D6428: .4byte FUN_081d62c8
_081D642C: .4byte FUN_081d6338
_081D6430:
	adds r0, r4, #0
_081D6432:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d6438
FUN_081d6438: @ 0x081D6438
	ldr r1, _081D6440 @ =0x03000198
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D6440: .4byte 0x03000198

	thumb_func_start FUN_081d6444
FUN_081d6444: @ 0x081D6444
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _081D6468 @ =0x00000157
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D646C
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _081D64BE
	.align 2, 0
_081D6468: .4byte 0x00000157
_081D646C:
	ldr r6, _081D64C8 @ =0x0203B400
	ldr r4, _081D64CC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D64D0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x20]
	mov r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081D64BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D64C8: .4byte 0x0203B400
_081D64CC: .4byte 0x030046B8
_081D64D0: .4byte 0x000003FF

	thumb_func_start FUN_081d64d4
FUN_081d64d4: @ 0x081D64D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov sb, r1
	adds r5, r2, #0
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D65C8
	adds r0, r4, #0
	bl FUN_08236524
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	adds r0, #0x96
	ldrh r2, [r0]
	subs r6, r1, r2
	adds r1, r0, #0
	cmp r6, #0
	bge _081D651C
	adds r6, r6, r2
	b _081D651E
_081D651C:
	adds r6, r2, #0
_081D651E:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r7, r5, r3
	ldrh r0, [r7]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r4, #0
	mov r8, r4
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D653A
	mov r0, r8
	strh r0, [r7]
_081D653A:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r7, r2]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r4, #0
	ldrsh r2, [r2, r4]
	ldr r4, _081D65D8 @ =0x00000147
	adds r3, r5, r4
	ldrb r3, [r3]
	mov r4, r8
	str r4, [sp]
	bl FUN_0809c344
	add r4, sp, #0xc
	mov r0, r8
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _081D65DC @ =0x05000002
	bl CpuSet
	adds r3, r5, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r4, #1
	str r4, [sp, #4]
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldr r2, _081D65E0 @ =0x00000153
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
	ldr r3, _081D65E4 @ =0x00000157
	adds r1, r5, r3
	movs r0, #0xa
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081d65e8
	adds r0, r5, #0
	bl FUN_081d6bc0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bgt _081D65C8
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #4
	strh r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r4, [r0]
_081D65C8:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D65D8: .4byte 0x00000147
_081D65DC: .4byte 0x05000002
_081D65E0: .4byte 0x00000153
_081D65E4: .4byte 0x00000157

	thumb_func_start FUN_081d65e8
FUN_081d65e8: @ 0x081D65E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	add r0, sp, #0x10
	mov r8, r0
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _081D66A8 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	mov r1, r8
	strh r0, [r1, #2]
	ldr r5, _081D66AC @ =0x0203B400
	ldr r7, _081D66B0 @ =0x030046B8
	mov ip, r7
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _081D66B4 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #3
	mov sb, r1
	mov r7, sb
	ands r0, r7
	adds r0, #0xf
	ldr r1, _081D66B8 @ =0xFFFF0000
	mov sl, r1
	ldr r3, [sp, #0x18]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r0, _081D66BC @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ands r1, r7
	adds r1, #0xf
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	mov r7, sl
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	adds r2, #1
	ands r2, r4
	mov r0, ip
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r6, #0x1c
	str r3, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xf
	str r1, [sp, #8]
	movs r1, #0x11
	adds r2, r6, #0
	mov r3, r8
	bl FUN_08014730
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D66A8: .4byte 0x05000002
_081D66AC: .4byte 0x0203B400
_081D66B0: .4byte 0x030046B8
_081D66B4: .4byte 0x000003FF
_081D66B8: .4byte 0xFFFF0000
_081D66BC: .4byte 0x0000FFFF

	thumb_func_start FUN_081d66c0
FUN_081d66c0: @ 0x081D66C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	adds r4, r7, #0
	adds r4, #0x58
	ldr r2, _081D6754 @ =0xFFFF0000
	ldr r5, _081D6758 @ =0x0000FFFF
	movs r1, #0xa0
	lsls r1, r1, #0xf
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D675C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, r8
	mov r3, sb
	bl FUN_08236514
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081D6760 @ =FUN_081d64d4
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6754: .4byte 0xFFFF0000
_081D6758: .4byte 0x0000FFFF
_081D675C: .4byte 0x00005001
_081D6760: .4byte FUN_081d64d4

	thumb_func_start FUN_081d6764
FUN_081d6764: @ 0x081D6764
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	mov r8, r0
	ldr r2, _081D67A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D67A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D67AC @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _081D67B0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67B4
	asrs r1, r0, #0xc
	b _081D67BA
	.align 2, 0
_081D67A4: .4byte 0x030046B8
_081D67A8: .4byte 0x000003FF
_081D67AC: .4byte 0x0203B400
_081D67B0: .4byte 0x085B0A08
_081D67B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D67BA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D67D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67D8
	asrs r0, r0, #0xc
	b _081D67DE
	.align 2, 0
_081D67D4: .4byte 0x085B0A08
_081D67D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D67DE:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x40
	strh r0, [r2, #2]
	mov r4, r8
	adds r4, #0x1c
	ldr r2, _081D6850 @ =0x00009385
	ldr r3, _081D6854 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r4, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6858 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D685C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6860 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r6, #0xa
	ldr r1, _081D6864 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _081D6868
	asrs r1, r0, #0xc
	b _081D686E
	.align 2, 0
_081D6850: .4byte 0x00009385
_081D6854: .4byte 0x000074C9
_081D6858: .4byte 0x030046B8
_081D685C: .4byte 0x000003FF
_081D6860: .4byte 0x0203B400
_081D6864: .4byte 0x085B0A08
_081D6868:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D686E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6888 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081D688C
	asrs r0, r0, #0xc
	b _081D6892
	.align 2, 0
_081D6888: .4byte 0x085B0A08
_081D688C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6892:
	movs r1, #0
	strh r0, [r5, #4]
	add r2, sp, #0x2c
	movs r0, #0x22
	strh r0, [r2, #2]
	ldr r2, _081D68FC @ =0x00009385
	ldr r3, _081D6900 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D690C @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6910 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6914
	asrs r1, r0, #0xc
	b _081D691A
	.align 2, 0
_081D68FC: .4byte 0x00009385
_081D6900: .4byte 0x000074C9
_081D6904: .4byte 0x030046B8
_081D6908: .4byte 0x000003FF
_081D690C: .4byte 0x0203B400
_081D6910: .4byte 0x085B0A08
_081D6914:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D691A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6934 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6938
	asrs r0, r0, #0xc
	b _081D693E
	.align 2, 0
_081D6934: .4byte 0x085B0A08
_081D6938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D693E:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D69A8 @ =0x00009385
	ldr r3, _081D69AC @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r1, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D69B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D69B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D69B8 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D69BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69C0
	asrs r1, r0, #0xc
	b _081D69C6
	.align 2, 0
_081D69A8: .4byte 0x00009385
_081D69AC: .4byte 0x000074C9
_081D69B0: .4byte 0x030046B8
_081D69B4: .4byte 0x000003FF
_081D69B8: .4byte 0x0203B400
_081D69BC: .4byte 0x085B0A08
_081D69C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D69C6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D69E0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69E4
	asrs r0, r0, #0xc
	b _081D69EA
	.align 2, 0
_081D69E0: .4byte 0x085B0A08
_081D69E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D69EA:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6A54 @ =0x00009385
	ldr r3, _081D6A58 @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6A5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6A60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6A64 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6A68 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A6C
	asrs r1, r0, #0xc
	b _081D6A72
	.align 2, 0
_081D6A54: .4byte 0x00009385
_081D6A58: .4byte 0x000074C9
_081D6A5C: .4byte 0x030046B8
_081D6A60: .4byte 0x000003FF
_081D6A64: .4byte 0x0203B400
_081D6A68: .4byte 0x085B0A08
_081D6A6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D6A72:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6A8C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A90
	asrs r0, r0, #0xc
	b _081D6A96
	.align 2, 0
_081D6A8C: .4byte 0x085B0A08
_081D6A90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6A96:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6AE0 @ =0x00009385
	ldr r3, _081D6AE4 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	mov r0, r8
	bl FUN_081d65e8
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6AE0: .4byte 0x00009385
_081D6AE4: .4byte 0x000074C9

	thumb_func_start FUN_081d6ae8
FUN_081d6ae8: @ 0x081D6AE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	ble _081D6BA0
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D6BA0
	ldr r1, _081D6BB0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r7, sp
	str r7, [r0, #4]
	mov sl, r0
	cmp r2, #0
	ble _081D6BA0
	ldr r0, _081D6BB4 @ =0x0203B400
	mov r8, r0
	ldr r1, _081D6BB8 @ =0x030046B8
	mov sb, r1
	ldr r3, _081D6BBC @ =0x000003FF
	adds r6, r2, #0
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r5, r4, r2
_081D6B32:
	mov r7, sb
	ldr r1, [r7]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1c
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1e
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp, #4]
	adds r1, #1
	ands r1, r3
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	subs r0, #0x40
	ands r1, r7
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5]
	str r0, [sp, #0xc]
	adds r7, #0xb9
	adds r0, r4, r7
	ldrh r0, [r0]
	mov r1, sl
	str r3, [sp, #0x18]
	bl Script_ExecById
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	subs r6, #1
	ldr r3, [sp, #0x18]
	cmp r6, #0
	bne _081D6B32
_081D6BA0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6BB0: .4byte 0xFFFF0000
_081D6BB4: .4byte 0x0203B400
_081D6BB8: .4byte 0x030046B8
_081D6BBC: .4byte 0x000003FF

	thumb_func_start FUN_081d6bc0
FUN_081d6bc0: @ 0x081D6BC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081D6C20 @ =0x0000013D
	adds r0, r4, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r6, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r6]
	cmp r0, r1
	bls _081D6C1A
	adds r2, #6
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r5, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D6C00
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081d6ae8
_081D6C00:
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrb r1, [r6]
	subs r1, #1
	muls r0, r1, r0
	cmp r5, r0
	blt _081D6C1A
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d6ae8
_081D6C1A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D6C20: .4byte 0x0000013D

	thumb_func_start FUN_081d6c24
FUN_081d6c24: @ 0x081D6C24
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #1
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D6C9E
	ldr r0, _081D6CA8 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r0, r5, r3
	str r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	bge _081D6C9E
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d6ae8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081d5820
	ldr r0, _081D6CAC @ =0x000003C7
	bl PlaySound_082406e0
_081D6C9E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6CA8: .4byte 0x03002BE0
_081D6CAC: .4byte 0x000003C7

	thumb_func_start FUN_081d6cb0
FUN_081d6cb0: @ 0x081D6CB0
	push {r4, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D6D18 @ =0x03002BE0
	mov r3, sp
	movs r2, #0x8a
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0x96
	lsls r1, r1, #1
	add r1, ip
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	str r0, [r1]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [r2]
	movs r0, #0x9a
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	cmp r1, r0
	blt _081D6D1C
	movs r0, #0
	b _081D6D1E
	.align 2, 0
_081D6D18: .4byte 0x03002BE0
_081D6D1C:
	movs r0, #1
_081D6D1E:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6d28
FUN_081d6d28: @ 0x081D6D28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r1, #8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D6D4A
	movs r0, #1
	b _081D6D4C
_081D6D4A:
	movs r0, #0
_081D6D4C:
	cmp r0, #0
	beq _081D6D52
	b _081D6EA8
_081D6D52:
	ldr r1, _081D6D70 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6D74
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	bne _081D6D90
	b _081D6D94
	.align 2, 0
_081D6D70: .4byte 0x00000109
_081D6D74:
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081D6D9A
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D6D94
_081D6D90:
	movs r0, #1
	b _081D6D96
_081D6D94:
	movs r0, #0
_081D6D96:
	cmp r0, #0
	beq _081D6DA6
_081D6D9A:
	movs r1, #0
	strh r1, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	b _081D6EA8
_081D6DA6:
	movs r1, #8
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081D6E80
	adds r1, r7, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081D6DEC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D6DF4
	ldr r2, _081D6DF0 @ =0x00000105
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D6E02
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #3
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D6E2A
	.align 2, 0
_081D6DEC: .4byte 0x00000109
_081D6DF0: .4byte 0x00000105
_081D6DF4:
	cmp r0, #1
	bne _081D6E2A
	ldr r0, _081D6E08 @ =0x00000105
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D6E0C
_081D6E02:
	subs r0, #1
	strb r0, [r4]
	b _081D6E2A
	.align 2, 0
_081D6E08: .4byte 0x00000105
_081D6E0C:
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #2
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081D6E2A:
	movs r1, #4
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6E3A
	movs r0, #1
	b _081D6E3C
_081D6E3A:
	movs r0, #0
_081D6E3C:
	cmp r0, #0
	beq _081D6E80
	ldr r1, _081D6E64 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6E68
	adds r1, r5, #0
	adds r1, #0xf4
	ldrh r0, [r1]
	subs r0, #0xc8
	strh r0, [r1]
	adds r2, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E5E
	movs r2, #0
_081D6E5E:
	strh r2, [r1]
	b _081D6E80
	.align 2, 0
_081D6E64: .4byte 0x00000109
_081D6E68:
	adds r2, r5, #0
	adds r2, #0xf4
	ldrh r0, [r2]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r2]
	adds r1, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E7E
	movs r1, #0
_081D6E7E:
	strh r1, [r2]
_081D6E80:
	ldr r2, _081D6EB4 @ =0x00000109
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EA8
	ldr r2, [r6, #0x4c]
	cmp r2, #0
	beq _081D6EA8
	ldr r3, [r6, #0x48]
	cmp r3, #0
	beq _081D6EA8
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081D6EA8
	adds r0, r6, #0
	adds r1, r7, #0
	bl _call_via_r3
_081D6EA8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6EB4: .4byte 0x00000109

	thumb_func_start FUN_081d6eb8
FUN_081d6eb8: @ 0x081D6EB8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r1, _081D6EDC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EE8
	ldr r2, _081D6EE0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x56
	orrs r0, r3
	ldr r1, _081D6EE4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	b _081D6EFA
	.align 2, 0
_081D6EDC: .4byte 0x00000109
_081D6EE0: .4byte 0xFFFF0000
_081D6EE4: .4byte 0x0000FFFF
_081D6EE8:
	ldr r2, _081D6F50 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x60
	orrs r0, r3
	ldr r1, _081D6F54 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
_081D6EFA:
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0xa4
	ldr r2, _081D6F58 @ =0x00004003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r5, #0
	adds r1, #0x9c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081D6F5C @ =FUN_081d6d28
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6F50: .4byte 0xFFFF0000
_081D6F54: .4byte 0x0000FFFF
_081D6F58: .4byte 0x00004003
_081D6F5C: .4byte FUN_081d6d28

	thumb_func_start FUN_081d6f60
FUN_081d6f60: @ 0x081D6F60
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d6f64
FUN_081d6f64: @ 0x081D6F64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	mov r6, r8
	adds r6, #0xa0
	movs r0, #1
	mov sb, r0
	movs r7, #0x8e
	lsls r7, r7, #1
_081D6F7C:
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6F8C
	movs r0, #1
	b _081D6F8E
_081D6F8C:
	movs r0, #0
_081D6F8E:
	cmp r0, #0
	bne _081D6FBE
	adds r0, r7, #0
	bl Malloc
	adds r4, r0, #0
	adds r1, r7, #0
	bl ClearMemory
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xfc
	strh r5, [r0]
	lsls r1, r5, #2
	mov r0, r8
	adds r0, #0x20
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r4, #0
	b _081D6FC6
_081D6FBE:
	adds r5, #1
	cmp r5, #0x1f
	ble _081D6F7C
	movs r0, #0
_081D6FC6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6fd4
FUN_081d6fd4: @ 0x081D6FD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7014 @ =0x0300019C
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _081D6FEE
	b _081D7342
_081D6FEE:
	adds r2, r5, #0
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	mov sl, r2
	cmp r0, #0
	bne _081D7020
	movs r2, #4
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7018
	movs r0, #1
	b _081D701A
	.align 2, 0
_081D7014: .4byte 0x0300019C
_081D7018:
	movs r0, #0
_081D701A:
	cmp r0, #0
	bne _081D7020
	b _081D72A0
_081D7020:
	adds r0, r5, #0
	adds r0, #0xf4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r6, r0, #0
	cmp r1, #0
	ble _081D7030
	b _081D713A
_081D7030:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x28
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D707C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7084
_081D707C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7084:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D70A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D70B0
_081D70A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D70B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D70E8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081D7120
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D70EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D70E0
	ldrb r0, [r4, #5]
_081D70E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D70FC
	.align 2, 0
_081D70E8: .4byte 0x0000FFFF
_081D70EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D70FC
	strh r1, [r4, #8]
_081D70FC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7120
	movs r0, #1
	strb r0, [r4, #7]
_081D7120:
	adds r1, r5, #0
	adds r1, #0xfe
	movs r2, #0
	movs r0, #3
	strh r0, [r1]
	movs r6, #0x82
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	b _081D7342
_081D713A:
	movs r2, #1
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7150
	movs r0, #1
	b _081D7152
_081D7150:
	movs r0, #0
_081D7152:
	adds r7, r0, #0
	cmp r7, #0
	beq _081D7194
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #3
	beq _081D7188
	ldrh r4, [r6]
	cmp r4, #3
	ble _081D7174
	subs r0, r4, #6
	cmp r0, #0
	bge _081D7172
	rsbs r0, r0, #0
_081D7172:
	adds r4, r0, #0
_081D7174:
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl FUN_08237040
	strh r4, [r6]
_081D7188:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x22
	str r0, [r1]
	b _081D7342
_081D7194:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x24
	str r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r4, r0, r4
	adds r6, r5, #0
	adds r6, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	str r7, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, r4
	bge _081D72A0
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D71FE
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7206
_081D71FE:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7206:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D722A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7232
_081D722A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7232:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081D7268 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D72A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D726C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7262
	ldrb r0, [r4, #5]
_081D7262:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D727C
	.align 2, 0
_081D7268: .4byte 0x0000FFFF
_081D726C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D727C
	strh r1, [r4, #8]
_081D727C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D72A0
	movs r0, #1
	strb r0, [r4, #7]
_081D72A0:
	mov r6, sl
	ldrb r1, [r6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081D733C
	adds r0, r5, #0
	adds r0, #0xf4
	adds r2, r5, #0
	adds r2, #0xf6
	ldrh r4, [r0]
	movs r1, #0
	ldrsh r3, [r0, r1]
	movs r6, #0
	ldrsh r1, [r2, r6]
	adds r6, r0, #0
	adds r7, r2, #0
	cmp r3, r1
	bge _081D72CE
	adds r0, r4, #0
	adds r0, #0xa
	strh r0, [r6]
	b _081D7334
_081D72CE:
	movs r1, #4
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D72DE
	movs r0, #1
	b _081D72E0
_081D72DE:
	movs r0, #0
_081D72E0:
	cmp r0, #0
	beq _081D7334
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #4
	str r4, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	mov r1, sb
	ldr r0, [r1]
	ands r0, r4
	cmp r0, #0
	beq _081D7306
	movs r0, #1
	b _081D7308
_081D7306:
	movs r0, #0
_081D7308:
	cmp r0, #0
	beq _081D7326
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r0, r0, r4
	adds r1, r5, #0
	adds r1, #0x94
	strh r0, [r1]
_081D7326:
	ldrh r0, [r7]
	strh r0, [r6]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x30
	str r0, [r1]
_081D7334:
	ldr r0, _081D7354 @ =0x00000105
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081D733C:
	movs r0, #0
	mov r1, sl
	strb r0, [r1]
_081D7342:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D7354: .4byte 0x00000105

	thumb_func_start FUN_081d7358
FUN_081d7358: @ 0x081D7358
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov ip, r6
	ldr r0, _081D7390 @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D736E
	b _081D76B0
_081D736E:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D7394
	movs r0, #1
	b _081D7396
	.align 2, 0
_081D7390: .4byte 0x0300019C
_081D7394:
	movs r0, #0
_081D7396:
	cmp r0, #0
	bne _081D739C
	b _081D74B8
_081D739C:
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D73D2
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D73DE
_081D73D2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D73DE:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7404
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D740E
_081D7404:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D740E:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7448 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D748E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7452
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D744C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7468
	.align 2, 0
_081D7448: .4byte 0x0000FFFF
_081D744C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7466
_081D7452:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7466
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7468
_081D7466:
	movs r2, #0
_081D7468:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7490
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7490
_081D748E:
	movs r2, #0
_081D7490:
	cmp r2, #0
	bne _081D7496
	b _081D76B0
_081D7496:
	ldr r1, [r7, #0x18]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #3
	strh r0, [r1]
	adds r0, #0xfd
	adds r1, r6, r0
	movs r0, #0x21
	str r0, [r1]
	b _081D76B0
_081D74B8:
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D74C6
	movs r0, #1
	b _081D74C8
_081D74C6:
	movs r0, #0
_081D74C8:
	cmp r0, #0
	beq _081D75C2
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7500
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D750C
_081D7500:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D750C:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7532
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D753C
_081D7532:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D753C:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7574 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D75AC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7578
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D756E
	ldrb r0, [r4, #5]
_081D756E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7588
	.align 2, 0
_081D7574: .4byte 0x0000FFFF
_081D7578:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7588
	strh r1, [r4, #8]
_081D7588:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D75AC
	movs r0, #1
	strb r0, [r4, #7]
_081D75AC:
	adds r0, r6, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #3
	bne _081D76B0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x24
	str r0, [r1]
	b _081D76B0
_081D75C2:
	adds r0, r6, #0
	bl FUN_081d6fd4
	movs r1, #1
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D75D6
	movs r0, #1
	b _081D75D8
_081D75D6:
	movs r0, #0
_081D75D8:
	cmp r0, #0
	beq _081D76B0
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D760C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D7614
_081D760C:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7614:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7638
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D7640
_081D7638:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7640:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7678 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D76B0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D767C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7670
	ldrb r0, [r4, #5]
_081D7670:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D768C
	.align 2, 0
_081D7678: .4byte 0x0000FFFF
_081D767C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D768C
	strh r1, [r4, #8]
_081D768C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D76B0
	movs r0, #1
	strb r0, [r4, #7]
_081D76B0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d76bc
FUN_081d76bc: @ 0x081D76BC
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	mov r7, ip
	ldr r5, [r0]
	movs r0, #2
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
	ldr r0, _081D770C @ =0x0300019C
	ldr r0, [r0]
	cmp r0, #0
	bne _081D76D8
	b _081D780E
_081D76D8:
	mov r4, ip
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r2, ip
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7710
	movs r0, #4
	orrs r5, r0
	mov r0, ip
	str r5, [r0]
	b _081D771A
	.align 2, 0
_081D770C: .4byte 0x0300019C
_081D7710:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
_081D771A:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D773C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D7744
_081D773C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7744:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D777C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D77B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7780
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7774
	ldrb r0, [r4, #5]
_081D7774:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7790
	.align 2, 0
_081D777C: .4byte 0x0000FFFF
_081D7780:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7790
	strh r1, [r4, #8]
_081D7790:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D77B4
	movs r0, #1
	strb r0, [r4, #7]
_081D77B4:
	mov r2, ip
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _081D77F2
	mov r0, ip
	adds r0, #0xf4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _081D77EC
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x28
	str r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	movs r0, #4
	strh r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, ip
	strb r3, [r0]
	b _081D780E
_081D77EC:
	movs r0, #0
	strb r0, [r2]
	b _081D780E
_081D77F2:
	mov r2, ip
	adds r2, #0xf4
	mov r0, ip
	adds r0, #0xf6
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D780E
	adds r0, r3, #0
	adds r0, #0xa
	strh r0, [r2]
_081D780E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d7814
FUN_081d7814: @ 0x081D7814
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081D7856
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D783C
	movs r0, #1
	b _081D783E
_081D783C:
	movs r0, #0
_081D783E:
	cmp r0, #0
	beq _081D7856
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r3, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D7856:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d785c
FUN_081d785c: @ 0x081D785C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081D78BC @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D786C
	b _081D7A58
_081D786C:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D788C
	adds r0, r5, #0
	bl FUN_081d7814
	movs r1, #0x83
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
_081D788C:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D78C0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D78C8
	.align 2, 0
_081D78BC: .4byte 0x0300019C
_081D78C0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D78C8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D78EC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D78F4
_081D78EC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D78F4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D792C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7972
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7936
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7930
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D794C
	.align 2, 0
_081D792C: .4byte 0x0000FFFF
_081D7930:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D794A
_081D7936:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D794A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D794C
_081D794A:
	movs r2, #0
_081D794C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7974
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7974
_081D7972:
	movs r2, #0
_081D7974:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1f
	bhi _081D7A4C
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081D79BA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081D7A48 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79BA:
	ldrh r0, [r4]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081D79EA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r0, [r0]
	adds r0, #0x40
	add r1, sp, #4
	strh r0, [r1]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79EA:
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081D7A18
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r1, sp, #4
	ldrh r0, [r1, #4]
	adds r0, #0x20
	strh r0, [r1, #4]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7A18:
	ldrh r0, [r4]
	movs r1, #7
	bl Mod
	cmp r0, #0
	bne _081D7A3C
	adds r4, r7, #0
	adds r4, #0xa4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _081D7A3C
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
_081D7A3C:
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	b _081D7A56
	.align 2, 0
_081D7A48: .4byte 0xFFFF0000
_081D7A4C:
	cmp r2, #0
	beq _081D7A58
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
_081D7A56:
	strh r0, [r1]
_081D7A58:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d7a60
FUN_081d7a60: @ 0x081D7A60
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7AC8 @ =0x0300019C
	ldr r4, [r0]
	cmp r4, #0
	bne _081D7A70
	b _081D7C9E
_081D7A70:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r7, r5, #0
	adds r7, #0x8c
	cmp r0, #0
	bne _081D7A82
	b _081D7B96
_081D7A82:
	adds r0, r5, #0
	bl FUN_081d7814
	ldr r1, [r4, #0x1c]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r7, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7ACC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7AD4
	.align 2, 0
_081D7AC8: .4byte 0x0300019C
_081D7ACC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7AD4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7AF8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7B00
_081D7AF8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7B00:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7B38 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7B70
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7B3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7B30
	ldrb r0, [r4, #5]
_081D7B30:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7B4C
	.align 2, 0
_081D7B38: .4byte 0x0000FFFF
_081D7B3C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7B4C
	strh r1, [r4, #8]
_081D7B4C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7B70
	movs r0, #1
	strb r0, [r4, #7]
_081D7B70:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #1
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7B96:
	adds r4, r7, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7BC4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7BCC
_081D7BC4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7BCC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7BF0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7BF8
_081D7BF0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7BF8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7C30 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7C76
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7C3A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7C34
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7C50
	.align 2, 0
_081D7C30: .4byte 0x0000FFFF
_081D7C34:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7C4E
_081D7C3A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7C4E
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7C50
_081D7C4E:
	movs r2, #0
_081D7C50:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7C78
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7C78
_081D7C76:
	movs r2, #0
_081D7C78:
	cmp r2, #0
	beq _081D7C9E
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #3
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7C9E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d7ca8
FUN_081d7ca8: @ 0x081D7CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D7D18 @ =0x0300019C
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _081D7CC0
	b _081D7FD2
_081D7CC0:
	bl FUN_081d6f64
	adds r7, r0, #0
	cmp r7, #0
	bne _081D7CCC
	b _081D7FD2
_081D7CCC:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #1
	str r1, [r0]
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r7, #0
	adds r2, #0x9c
	str r2, [sp, #0x14]
	cmp r0, #0
	beq _081D7D02
	bl Script_GetValue
	ldr r1, [sp, #0x14]
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xa0
	strh r0, [r1]
_081D7D02:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _081D7D1C
	bl Script_GetValue
	str r0, [sp, #8]
	bl Script_GetValue
	b _081D7D22
	.align 2, 0
_081D7D18: .4byte 0x0300019C
_081D7D1C:
	movs r2, #0
	str r2, [sp, #8]
	movs r0, #0
_081D7D22:
	str r0, [sp, #0xc]
	movs r0, #0x68
	movs r1, #0
	bl Script_GetKeywordValue
	movs r1, #0xf4
	adds r1, r1, r7
	mov sb, r1
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xf6
	strh r0, [r1]
	mov r8, r7
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x2c
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r6, r7, #0
	adds r6, #0x8c
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r3
	mov r1, sb
	str r1, [sp, #0x18]
	mov sb, r4
	str r6, [sp, #0x10]
	cmp r2, r0
	beq _081D7D8C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D7D94
_081D7D8C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7D94:
	str r0, [r7]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7DBA
	mov r2, r8
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _081D7DC6
_081D7DBA:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
_081D7DC6:
	str r0, [r2]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081D7DFC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081D7E34
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7E00
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081D7DF6
	ldrb r0, [r6, #5]
_081D7DF6:
	subs r0, #1
	strh r0, [r6, #8]
	b _081D7E10
	.align 2, 0
_081D7DFC: .4byte 0x0000FFFF
_081D7E00:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081D7E10
	strh r1, [r6, #8]
_081D7E10:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7E34
	movs r0, #1
	strb r0, [r6, #7]
_081D7E34:
	mov r1, r8
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081D7E60 @ =0x00000109
	adds r1, r7, r2
	movs r6, #0
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D7E64
	cmp r0, #1
	beq _081D7E94
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r7, r0
	b _081D7EC8
	.align 2, 0
_081D7E60: .4byte 0x00000109
_081D7E64:
	ldr r1, _081D7E90 @ =0x00004FDA
	mov r0, sb
	bl FUN_0822b16c
	mov r2, sl
	ldr r1, [r2, #0x18]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r0, r7, #0
	adds r0, #0xfe
	strh r4, [r0]
	movs r0, #3
	mov r1, r8
	strb r0, [r1, #7]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r4, r7, r2
	b _081D7EC8
	.align 2, 0
_081D7E90: .4byte 0x00004FDA
_081D7E94:
	ldr r1, _081D7F1C @ =0x0000863A
	mov r0, sb
	bl FUN_0822b16c
	mov r0, sl
	ldr r1, [r0, #0x1c]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r1, r7, #0
	adds r1, #0xfe
	movs r3, #2
	movs r0, #2
	strh r0, [r1]
	movs r2, #4
	adds r0, #0xfe
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	strb r3, [r2, #7]
	adds r4, r1, #0
_081D7EC8:
	ldr r0, _081D7F20 @ =0x00000105
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #3
	bl Div
	adds r1, r7, #0
	adds r1, #0xf8
	str r0, [r1]
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r7, #0
	bl FUN_081d6eb8
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D7F18
	cmp r1, #0
	blt _081D7F18
	ldr r0, _081D7F24 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D7F18
	ldr r0, _081D7F28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D7F2C
_081D7F18:
	movs r2, #0
	b _081D7F3A
	.align 2, 0
_081D7F1C: .4byte 0x0000863A
_081D7F20: .4byte 0x00000105
_081D7F24: .4byte 0x030046A8
_081D7F28: .4byte 0x030046AC
_081D7F2C:
	ldr r0, _081D7FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_081D7F3A:
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r3, [r7, #0x1e]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0
	str r1, [sp]
	movs r5, #0x80
	str r5, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r1, #0x20
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x50
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D7F70
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
_081D7F70:
	ldr r0, [sp, #0x14]
	bl FUN_08241574
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081D7FC8
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	adds r4, r7, #0
	adds r4, #0x48
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	adds r1, #0x6f
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0x14]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_0823b46c
	adds r0, r4, #0
	bl FUN_08002a48
	b _081D7FD2
	.align 2, 0
_081D7FC4: .4byte 0x030046A4
_081D7FC8:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_081D7FD2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d7fe4
FUN_081d7fe4: @ 0x081D7FE4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r3, #0x20
	adds r2, r1, #0
	adds r2, #0xa0
	ldr r0, [r2]
	cmp r0, #0
	beq _081D8092
	movs r5, #0
	adds r6, r2, #0
	adds r7, r1, #0
	adds r7, #0xa4
	ldr r0, _081D8018 @ =0x085AE118
	mov r8, r0
	adds r4, r3, #0
_081D8008:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D801C
	movs r0, #1
	b _081D801E
	.align 2, 0
_081D8018: .4byte 0x085AE118
_081D801C:
	movs r0, #0
_081D801E:
	cmp r0, #0
	beq _081D8086
	ldr r0, [r4]
	movs r1, #0x80
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8038
	movs r0, #1
	b _081D803A
_081D8038:
	movs r0, #0
_081D803A:
	cmp r0, #0
	beq _081D8072
	ldr r0, [r4]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, _081D805C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D8060
	movs r0, #1
	b _081D8062
	.align 2, 0
_081D805C: .4byte 0x030046A0
_081D8060:
	movs r0, #0
_081D8062:
	cmp r0, #0
	bne _081D8072
	ldr r0, [r4]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _081D8086
_081D8072:
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #2
	add r1, r8
	ldr r1, [r1]
	bl _call_via_r1
_081D8086:
	adds r4, #4
	adds r5, #1
	cmp r5, #0x1f
	ble _081D8008
	movs r0, #0xff
	strb r0, [r7]
_081D8092:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d80a0
FUN_081d80a0: @ 0x081D80A0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
_081D80A6:
	adds r0, r7, #0
	adds r0, #0xa0
	movs r1, #1
	lsls r1, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D80BA
	movs r0, #1
	b _081D80BC
_081D80BA:
	movs r0, #0
_081D80BC:
	cmp r0, #0
	beq _081D8122
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x20
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r5, #0
	bl FUN_0822a4e0
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D80EC
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_081D80EC:
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D8102
	movs r0, #1
	b _081D8104
_081D8102:
	movs r0, #0
_081D8104:
	cmp r0, #0
	beq _081D811C
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D811C:
	adds r0, r5, #0
	bl Free
_081D8122:
	adds r6, #1
	cmp r6, #0x1f
	ble _081D80A6
	ldr r1, _081D8134 @ =0x0300019C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8134: .4byte 0x0300019C

	thumb_func_start FUN_081d8138
FUN_081d8138: @ 0x081D8138
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _081D816C @ =0x0000922E
	ldr r1, _081D8170 @ =0x00001003
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x18]
	ldr r1, _081D8174 @ =0x0000931E
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x1c]
	ldr r0, _081D8178 @ =0x0300019C
	str r4, [r0]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	str r0, [r1]
	adds r4, #0xa4
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081D816C: .4byte 0x0000922E
_081D8170: .4byte 0x00001003
_081D8174: .4byte 0x0000931E
_081D8178: .4byte 0x0300019C

	thumb_func_start FUN_081d817c
FUN_081d817c: @ 0x081D817C
	push {r4, lr}
	movs r0, #0xa
	movs r1, #0xa8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D81B0
	ldr r1, _081D81A8 @ =FUN_081d7fe4
	ldr r2, _081D81AC @ =FUN_081d80a0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d8138
	cmp r0, #0
	bge _081D81B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D81B2
	.align 2, 0
_081D81A8: .4byte FUN_081d7fe4
_081D81AC: .4byte FUN_081d80a0
_081D81B0:
	adds r0, r4, #0
_081D81B2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d81b8
FUN_081d81b8: @ 0x081D81B8
	ldr r1, _081D81C0 @ =0x0300019C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D81C0: .4byte 0x0300019C

	thumb_func_start FUN_081d81c4
FUN_081d81c4: @ 0x081D81C4
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r7, #1
_081D81D2:
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D81E2
	movs r0, #1
	b _081D81E4
_081D81E2:
	movs r0, #0
_081D81E4:
	cmp r0, #0
	bne _081D821C
	movs r0, #0xdc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r2, r4
	adds r0, r4, #0
	movs r1, #0xdc
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xd0
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0xd2
	ldr r0, _081D8218 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r4, #0
	b _081D8224
	.align 2, 0
_081D8218: .4byte 0x0000FFFF
_081D821C:
	adds r5, #1
	cmp r5, #3
	ble _081D81D2
	movs r0, #0
_081D8224:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d822c
FUN_081d822c: @ 0x081D822C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081D828C @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	beq _081D8286
	adds r1, r5, #0
	adds r1, #0xd8
	ldr r0, _081D8290 @ =FUN_081d8368
	str r0, [r1]
	adds r3, r5, #0
	adds r3, #0xd0
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xea
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r0, #0
	ldr r0, _081D8294 @ =0x0000FFFF
	strh r0, [r3]
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r4, r5, #0
	adds r4, #0xd2
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D8286
	adds r0, r5, #0
	adds r0, #0x8c
	bl FUN_080138fc
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_081D8286:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D828C: .4byte 0x030001A0
_081D8290: .4byte FUN_081d8368
_081D8294: .4byte 0x0000FFFF

	thumb_func_start FUN_081d8298
FUN_081d8298: @ 0x081D8298
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r2, r0, #0
	ldr r6, _081D8350 @ =0xFFFF0000
	ldr r5, [sp, #0xc]
	ands r5, r6
	ldr r0, _081D8354 @ =0x0000FFF4
	mov sl, r0
	orrs r5, r0
	str r5, [sp, #0xc]
	ldr r3, _081D8358 @ =0x0203B400
	mov sb, r3
	ldr r7, _081D835C @ =0x030046B8
	ldr r1, [r7]
	adds r1, #1
	ldr r0, _081D8360 @ =0x000003FF
	mov r8, r0
	ands r1, r0
	lsls r0, r1, #1
	add r0, sb
	ldrh r3, [r0]
	movs r7, #7
	mov ip, r7
	mov r0, ip
	ands r3, r0
	lsls r3, r3, #0x10
	ldr r4, _081D8364 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r5
	orrs r0, r3
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	mov r3, sl
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r3, [sp, #0x14]
	ands r3, r6
	movs r5, #0x18
	orrs r3, r5
	str r3, [sp, #0x14]
	adds r1, #1
	mov r7, r8
	ands r1, r7
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	mov r7, ip
	ands r0, r7
	adds r0, #3
	lsls r0, r0, #0x10
	ands r4, r3
	orrs r4, r0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r5
	str r0, [r3, #4]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	ldr r7, _081D835C @ =0x030046B8
	str r1, [r7]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #3
	ands r0, r1
	adds r0, #3
	adds r2, #0x1c
	str r3, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #2
	add r3, sp, #0xc
	bl FUN_08014730
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8350: .4byte 0xFFFF0000
_081D8354: .4byte 0x0000FFF4
_081D8358: .4byte 0x0203B400
_081D835C: .4byte 0x030046B8
_081D8360: .4byte 0x000003FF
_081D8364: .4byte 0x0000FFFF

	thumb_func_start FUN_081d8368
FUN_081d8368: @ 0x081D8368
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d836c
FUN_081d836c: @ 0x081D836C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D839A
	cmp r1, #0
	blt _081D839A
	ldr r0, _081D83A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D839A
	ldr r0, _081D83A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D83A8
_081D839A:
	movs r0, #0
	b _081D83B6
	.align 2, 0
_081D83A0: .4byte 0x030046A8
_081D83A4: .4byte 0x030046AC
_081D83A8:
	ldr r0, _081D8424 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D83B6:
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0xd4
	ldrb r1, [r0]
	mov sb, r0
	adds r7, r6, #0
	adds r7, #0xd6
	adds r4, r6, #0
	adds r4, #0x2c
	cmp r1, #0
	beq _081D83F6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	adds r0, #0x8c
	bl FUN_08013698
	movs r1, #0
	movs r0, #0
	strh r0, [r7]
	mov r2, sb
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0xd5
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08237098
_081D83F6:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8428
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D8430
	.align 2, 0
_081D8424: .4byte 0x030046A4
_081D8428:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8430:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8454
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D845C
_081D8454:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D845C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8494 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D84CC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8498
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D848C
	ldrb r0, [r4, #5]
_081D848C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D84A8
	.align 2, 0
_081D8494: .4byte 0x0000FFFF
_081D8498:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D84A8
	strh r1, [r4, #8]
_081D84A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D84CC
	movs r0, #1
	strb r0, [r4, #7]
_081D84CC:
	ldrh r0, [r6, #0x1e]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r6, #0x1e]
	adds r4, r6, #0
	adds r4, #0x3c
	adds r5, r6, #0
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	mov r0, r8
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D84FC
	adds r0, #4
	b _081D850A
_081D84FC:
	ldr r0, _081D8520 @ =0x030046A4
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D850A:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081D8524
	cmp r3, #2
	beq _081D8528
	b _081D852C
	.align 2, 0
_081D8520: .4byte 0x030046A4
_081D8524:
	ldrb r0, [r5, #4]
	b _081D852A
_081D8528:
	ldrb r0, [r5]
_081D852A:
	subs r2, r2, r0
_081D852C:
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bgt _081D854C
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r1, _081D8548 @ =FUN_081d85a8
	str r1, [r0]
	strh r2, [r6, #0x1e]
	movs r0, #1
	mov r2, sb
	strb r0, [r2]
	b _081D8552
	.align 2, 0
_081D8548: .4byte FUN_081d85a8
_081D854C:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_081D8552:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d8560
FUN_081d8560: @ 0x081D8560
	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	movs r4, #0
_081D8568:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #2
	ble _081D8568
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d85a8
FUN_081d85a8: @ 0x081D85A8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D8640 @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	bne _081D85B8
	b _081D8706
_081D85B8:
	adds r1, r5, #0
	adds r1, #0xd4
	ldrb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	beq _081D85E6
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r1, [r2, #0x34]
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #6
	movs r3, #1
	bl FUN_08236fac
	adds r0, r6, #0
	movs r1, #0x20
	bl FUN_08237098
_081D85E6:
	adds r4, r5, #0
	adds r4, #0xd6
	ldrh r0, [r4]
	lsls r0, r0, #3
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	subs r4, #0x9a
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8644
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D864C
	.align 2, 0
_081D8640: .4byte 0x030001A0
_081D8644:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D864C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8670
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D8678
_081D8670:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8678:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D86B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D86E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D86B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D86A8
	ldrb r0, [r4, #5]
_081D86A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D86C4
	.align 2, 0
_081D86B0: .4byte 0x0000FFFF
_081D86B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D86C4
	strh r1, [r4, #8]
_081D86C4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D86E8
	movs r0, #1
	strb r0, [r4, #7]
_081D86E8:
	ldrh r0, [r5, #0x34]
	cmp r0, #3
	bne _081D8706
	adds r0, r5, #0
	bl FUN_081d8298
	adds r0, r5, #0
	bl FUN_081d8560
	adds r0, r5, #0
	bl FUN_081d822c
	ldr r0, _081D8710 @ =0x000001E1
	bl PlaySound_082406e0
_081D8706:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D8710: .4byte 0x000001E1

	thumb_func_start FUN_081d8714
FUN_081d8714: @ 0x081D8714
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _081D8768 @ =0x030001A0
	ldr r5, [r0]
	cmp r5, #0
	beq _081D8760
	adds r4, r5, #0
	adds r4, #0x18
	ldr r1, _081D876C @ =0x00005290
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, _081D8770 @ =0x0000922E
	ldr r1, _081D8774 @ =0x00001E38
	bl GetFile
	adds r1, r0, #0
	str r1, [r5, #0x34]
	adds r0, r6, #0
	adds r0, #0x2c
	movs r2, #1
	str r2, [sp]
	movs r2, #8
	movs r3, #1
	bl FUN_08236fac
	ldr r0, _081D8778 @ =0x00000201
	adds r1, r7, r0
	adds r0, r4, #0
	bl FUN_0822b20c
_081D8760:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8768: .4byte 0x030001A0
_081D876C: .4byte 0x00005290
_081D8770: .4byte 0x0000922E
_081D8774: .4byte 0x00001E38
_081D8778: .4byte 0x00000201

	thumb_func_start FUN_081d877c
FUN_081d877c: @ 0x081D877C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r5, r0
_081D8788:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D8798
	movs r0, #1
	b _081D879A
_081D8798:
	movs r0, #0
_081D879A:
	cmp r0, #0
	beq _081D87B4
	movs r0, #0xdc
	muls r0, r4, r0
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r0
	adds r0, #0x38
	adds r0, r5, r0
	ldr r1, [r1]
	bl _call_via_r1
_081D87B4:
	adds r4, #1
	cmp r4, #3
	ble _081D8788
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d87c4
FUN_081d87c4: @ 0x081D87C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r6, #0
	movs r7, #0xea
	lsls r7, r7, #2
	add r7, r8
	movs r0, #1
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_081D87E2:
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D87F2
	movs r0, #1
	b _081D87F4
_081D87F2:
	movs r0, #0
_081D87F4:
	cmp r0, #0
	beq _081D882A
	movs r0, #0xdc
	muls r0, r6, r0
	adds r0, #0x38
	mov r1, r8
	adds r4, r1, r0
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r5, r4, #0
	adds r5, #0xd2
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, sl
	beq _081D882A
	adds r0, r4, #0
	adds r0, #0x8c
	bl FUN_080138fc
	ldr r0, _081D8844 @ =0x0000FFFF
	strh r0, [r5]
_081D882A:
	adds r6, #1
	cmp r6, #3
	ble _081D87E2
	ldr r1, _081D8848 @ =0x030001A0
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8844: .4byte 0x0000FFFF
_081D8848: .4byte 0x030001A0

	thumb_func_start FUN_081d884c
FUN_081d884c: @ 0x081D884C
	ldr r1, _081D8854 @ =0x030001A0
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081D8854: .4byte 0x030001A0

	thumb_func_start FUN_081d8858
FUN_081d8858: @ 0x081D8858
	push {r4, lr}
	ldr r0, _081D8890 @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D889E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D889C
	ldr r1, _081D8894 @ =FUN_081d877c
	ldr r2, _081D8898 @ =FUN_081d87c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d884c
	cmp r0, #0
	bge _081D889C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D889E
	.align 2, 0
_081D8890: .4byte 0x030001A0
_081D8894: .4byte FUN_081d877c
_081D8898: .4byte FUN_081d87c4
_081D889C:
	adds r0, r4, #0
_081D889E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d88a4
FUN_081d88a4: @ 0x081D88A4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d88a8
FUN_081d88a8: @ 0x081D88A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r7, #0
	adds r4, #0x3c
	ldr r2, _081D8934 @ =0xFFFF0000
	ldr r1, _081D8938 @ =0x0000FFFF
	movs r0, #0xc8
	lsls r0, r0, #0xe
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x54
	orrs r0, r3
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r7, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D893C @ =0x00002001
	movs r0, #0x20
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x80
	lsls r3, r3, #6
	ldr r0, _081D8940 @ =0x00440008
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_082364f8
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081D8944 @ =FUN_081d88a4
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8934: .4byte 0xFFFF0000
_081D8938: .4byte 0x0000FFFF
_081D893C: .4byte 0x00002001
_081D8940: .4byte 0x00440008
_081D8944: .4byte FUN_081d88a4

	thumb_func_start FUN_081d8948
FUN_081d8948: @ 0x081D8948
	push {r4, r5, r6, r7, lr}
	ldr r0, _081D89AC @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D895A
	bl FUN_081d8858
	cmp r0, #0
	beq _081D89EC
_081D895A:
	bl FUN_081d81c4
	adds r5, r0, #0
	cmp r5, #0
	beq _081D89EC
	movs r1, #2
	bl FUN_081d8714
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _081D8986
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	strh r0, [r5, #0x1e]
	bl Script_GetValue
	strh r0, [r5, #0x20]
_081D8986:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0xcc
	strh r0, [r1]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _081D89B0
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r6, r0, #0
	b _081D89B4
	.align 2, 0
_081D89AC: .4byte 0x030001A0
_081D89B0:
	movs r7, #0x64
	movs r6, #0x64
_081D89B4:
	adds r1, r5, #0
	adds r1, #0xd4
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd5
	strb r2, [r0]
	adds r1, #4
	ldr r0, _081D89F4 @ =FUN_081d836c
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	subs r1, #0xbc
	adds r0, r4, #0
	bl FUN_0801385c
	adds r1, r5, #0
	adds r1, #0xd2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080136b4
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_081d88a8
_081D89EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D89F4: .4byte FUN_081d836c

	thumb_func_start FUN_081d89f8
FUN_081d89f8: @ 0x081D89F8
	ldr r1, _081D8A00 @ =0x030001A0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D8A00: .4byte 0x030001A0

	thumb_func_start FUN_081d8a04
FUN_081d8a04: @ 0x081D8A04
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0x6e
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8a14
FUN_081d8a14: @ 0x081D8A14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0x6e
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8a24
FUN_081d8a24: @ 0x081D8A24
	push {lr}
	adds r0, #0x6e
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D8A34
	movs r0, #0
	b _081D8A36
_081D8A34:
	movs r0, #1
_081D8A36:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8a3c
FUN_081d8a3c: @ 0x081D8A3C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081D8A58 @ =0x00000ECC
	adds r2, r3, r0
	movs r6, #1
_081D8A48:
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D8A5C
	movs r0, #1
	b _081D8A5E
	.align 2, 0
_081D8A58: .4byte 0x00000ECC
_081D8A5C:
	movs r0, #0
_081D8A5E:
	cmp r0, #0
	bne _081D8A88
	movs r0, #0xbc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r3, r4
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #0xbc
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0x6c
	strh r5, [r0]
	adds r0, r4, #0
	b _081D8A90
_081D8A88:
	adds r5, #1
	cmp r5, #0x13
	ble _081D8A48
	movs r0, #0
_081D8A90:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8a98
FUN_081d8a98: @ 0x081D8A98
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _081D8B34 @ =0x030001A4
	ldr r6, [r0]
	cmp r6, #0
	bne _081D8AB0
	bl FUN_081d9a08
	adds r6, r0, #0
	cmp r6, #0
	bne _081D8AB0
	b _081D8C78
_081D8AB0:
	adds r0, r6, #0
	bl FUN_081d8a3c
	adds r5, r0, #0
	cmp r5, #0
	bne _081D8ABE
	b _081D8C78
_081D8ABE:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D8B38 @ =0x00005A6E
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r5, #0xc]
	ldr r1, _081D8B3C @ =0x0000014F
	bl FUN_0822b20c
	adds r1, r5, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	strb r2, [r0]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _081D8B0A
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	strh r0, [r5, #0x1e]
	bl Script_GetValue
	strh r0, [r5, #0x20]
_081D8B0A:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _081D8B40
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x60
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x62
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x64
	strh r0, [r1]
	b _081D8B52
	.align 2, 0
_081D8B34: .4byte 0x030001A4
_081D8B38: .4byte 0x00005A6E
_081D8B3C: .4byte 0x0000014F
_081D8B40:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_081D8B52:
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #7]
	adds r0, r5, #0
	adds r0, #0x6e
	strh r1, [r0]
	ldr r2, _081D8BB4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8BB8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D8BBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BC0
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D8BC8
	.align 2, 0
_081D8BB4: .4byte 0x030046B8
_081D8BB8: .4byte 0x000003FF
_081D8BBC: .4byte 0x0203B400
_081D8BC0:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8BC8:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BEC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D8BF4
_081D8BEC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8BF4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8C2C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D8C64
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8C30
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D8C24
	ldrb r0, [r4, #5]
_081D8C24:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D8C40
	.align 2, 0
_081D8C2C: .4byte 0x0000FFFF
_081D8C30:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D8C40
	strh r1, [r4, #8]
_081D8C40:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8C64
	movs r0, #1
	strb r0, [r4, #7]
_081D8C64:
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0
	bl FUN_0801385c
	adds r1, r5, #0
	adds r1, #0x79
	strb r0, [r1]
_081D8C78:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d8c80
FUN_081d8c80: @ 0x081D8C80
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	ble _081D8CA6
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081D8CAC
_081D8CA6:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081D8CAC:
	pop {r0}
	bx r0

	thumb_func_start FUN_081d8cb0
FUN_081d8cb0: @ 0x081D8CB0
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _081D8D14 @ =0x03002BE0
	ldr r3, [r0]
	cmp r3, #0
	beq _081D8D18
	movs r0, #0x1c
	ldrsh r1, [r2, r0]
	movs r4, #0x2c
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CCC
	rsbs r1, r1, #0
_081D8CCC:
	adds r0, r2, #0
	adds r0, #0x60
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x20
	ldrsh r1, [r2, r0]
	movs r4, #0x30
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CE8
	rsbs r1, r1, #0
_081D8CE8:
	adds r0, r2, #0
	adds r0, #0x64
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x1e
	ldrsh r1, [r2, r0]
	movs r4, #0x2e
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D04
	rsbs r1, r1, #0
_081D8D04:
	adds r0, r2, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D18
	movs r0, #1
	b _081D8D1A
	.align 2, 0
_081D8D14: .4byte 0x03002BE0
_081D8D18:
	movs r0, #0
_081D8D1A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d8d20
FUN_081d8d20: @ 0x081D8D20
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r2, r0, #0
	cmp r2, #0
	beq _081D8D86
	movs r0, #0x1c
	ldrsh r1, [r4, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D3E
	rsbs r1, r1, #0
_081D8D3E:
	adds r0, r4, #0
	adds r0, #0x60
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x20
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D5A
	rsbs r1, r1, #0
_081D8D5A:
	adds r0, r4, #0
	adds r0, #0x64
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D76
	rsbs r1, r1, #0
_081D8D76:
	adds r0, r4, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D86
	movs r0, #1
	b _081D8D88
_081D8D86:
	movs r0, #0
_081D8D88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8d90
FUN_081d8d90: @ 0x081D8D90
	push {lr}
	movs r2, #0xed
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _081D8DA6
	subs r0, #1
	str r0, [r1]
	movs r0, #0
	b _081D8DBA
_081D8DA6:
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [r1]
	bl FUN_0823e1b0
	cmp r0, #2
	bgt _081D8DB8
	movs r0, #0
	b _081D8DBA
_081D8DB8:
	movs r0, #1
_081D8DBA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8dc0
FUN_081d8dc0: @ 0x081D8DC0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8dc4
FUN_081d8dc4: @ 0x081D8DC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r0
	adds r6, r1, #0
	adds r3, r6, #0
	adds r3, #0x74
	ldrb r0, [r3]
	cmp r0, #0
	bne _081D8DDC
	b _081D8F10
_081D8DDC:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r2, r6, #0
	adds r2, #0x72
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
	ldr r5, _081D8E48 @ =0x0203B400
	ldr r2, _081D8E4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8E50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r3, #1
	strb r0, [r3]
	ldrb r4, [r3]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r5, r6, #0
	adds r5, #0x58
	adds r7, r4, #0
	adds r1, #3
	mov ip, r1
	ldr r4, _081D8E54 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E58
	asrs r1, r0, #0xc
	b _081D8E5E
	.align 2, 0
_081D8E48: .4byte 0x0203B400
_081D8E4C: .4byte 0x030046B8
_081D8E50: .4byte 0x000003FF
_081D8E54: .4byte 0x085B0A08
_081D8E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D8E5E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r7, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E7A
	asrs r0, r0, #0xc
	b _081D8E80
_081D8E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D8E80:
	strh r0, [r5, #4]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8EC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081D8ECC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #4
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D8EC4
	cmp r1, #0
	blt _081D8EC4
	ldr r0, _081D8ED0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8EC4
	ldr r0, _081D8ED4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8ED8
_081D8EC4:
	movs r0, #0
	b _081D8EE6
	.align 2, 0
_081D8EC8: .4byte 0x000003FF
_081D8ECC: .4byte 0x0203B400
_081D8ED0: .4byte 0x030046A8
_081D8ED4: .4byte 0x030046AC
_081D8ED8:
	ldr r0, _081D8F40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D8EE6:
	adds r2, r6, #0
	adds r2, #0x76
	strh r0, [r2]
	ldrb r0, [r3]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r6, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #4
	bl FUN_08236fac
_081D8F10:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D8F44 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _081D8F48 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8F4C
	movs r0, #1
	b _081D8F4E
	.align 2, 0
_081D8F40: .4byte 0x030046A4
_081D8F44: .4byte 0x030046A0
_081D8F48: .4byte 0x00000934
_081D8F4C:
	movs r0, #0
_081D8F4E:
	cmp r0, #0
	bne _081D8F5E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D8F6E
_081D8F5E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D918E
_081D8F6E:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r2, #0
	blt _081D8F98
	cmp r1, #0
	blt _081D8F98
	ldr r0, _081D8F9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8F98
	ldr r0, _081D8FA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8FA4
_081D8F98:
	movs r4, #0
	b _081D8FB2
	.align 2, 0
_081D8F9C: .4byte 0x030046A8
_081D8FA0: .4byte 0x030046AC
_081D8FA4:
	ldr r0, _081D8FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D8FB2:
	adds r7, r5, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D8FC8
	adds r0, #4
	b _081D8FD4
	.align 2, 0
_081D8FC4: .4byte 0x030046A4
_081D8FC8:
	ldr r0, _081D8FE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D8FD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081D8FEC
	cmp r2, #2
	beq _081D8FF0
	b _081D8FF4
	.align 2, 0
_081D8FE8: .4byte 0x030046A4
_081D8FEC:
	ldrb r0, [r7, #4]
	b _081D8FF2
_081D8FF0:
	ldrb r0, [r7]
_081D8FF2:
	subs r1, r1, r0
_081D8FF4:
	adds r7, r1, #0
	add r3, sp, #0xc
	adds r2, r6, #0
	adds r2, #0x58
	ldrh r1, [r6, #0x1c]
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r3]
	ldrh r0, [r5, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r5, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081D9034
	cmp r1, #0
	blt _081D9034
	ldr r0, _081D9038 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081D9034
	ldr r0, _081D903C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D9040
_081D9034:
	movs r1, #0
	b _081D904E
	.align 2, 0
_081D9038: .4byte 0x030046A8
_081D903C: .4byte 0x030046AC
_081D9040:
	ldr r0, _081D9064 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r4
_081D904E:
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, r1
	bne _081D9068
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	b _081D9076
	.align 2, 0
_081D9064: .4byte 0x030046A4
_081D9068:
	movs r0, #0
	strh r0, [r2]
	adds r1, r6, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r3, #2]
	strh r0, [r6, #0x1e]
_081D9076:
	adds r1, r6, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r7, r0
	blt _081D90B0
	strh r7, [r6, #0x1e]
	add r0, sp, #8
	movs r1, #0
	str r1, [sp, #8]
	adds r1, r2, #0
	ldr r2, _081D90AC @ =0x05000002
	bl CpuSet
	adds r1, r6, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	strb r2, [r0]
	b _081D918E
	.align 2, 0
_081D90AC: .4byte 0x05000002
_081D90B0:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D90E0
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D90E8
_081D90E0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D90E8:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D910C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9114
_081D910C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9114:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D914C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9184
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9150
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9144
	ldrb r0, [r4, #5]
_081D9144:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9160
	.align 2, 0
_081D914C: .4byte 0x0000FFFF
_081D9150:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9160
	strh r1, [r4, #8]
_081D9160:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9184
	movs r0, #1
	strb r0, [r4, #7]
_081D9184:
	adds r1, r6, #0
	adds r1, #0x72
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D918E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d919c
FUN_081d919c: @ 0x081D919C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x74
	ldrb r0, [r7]
	cmp r0, #0
	beq _081D91F8
	ldr r5, _081D9228 @ =0x0203B400
	ldr r2, _081D922C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _081D9230 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x5a
	adds r3, r6, #0
	adds r3, #0x70
	movs r1, #0
	strh r0, [r3]
	strb r1, [r7]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r7, r3, #0
	cmp r0, #0x17
	bgt _081D91F8
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a04
	ldrh r0, [r7]
	adds r0, #0x3c
	strh r0, [r7]
_081D91F8:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D9234 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081D9238 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D923C
	movs r0, #1
	b _081D923E
	.align 2, 0
_081D9228: .4byte 0x0203B400
_081D922C: .4byte 0x030046B8
_081D9230: .4byte 0x000003FF
_081D9234: .4byte 0x030046A0
_081D9238: .4byte 0x00000934
_081D923C:
	movs r0, #0
_081D923E:
	cmp r0, #0
	bne _081D924E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9256
_081D924E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	b _081D939A
_081D9256:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a24
	lsls r0, r0, #0x18
	adds r7, r6, #0
	adds r7, #0x70
	adds r5, r6, #0
	adds r5, #0x2c
	cmp r0, #0
	beq _081D92A0
	ldrh r0, [r7]
	cmp r0, #0x28
	bhi _081D92A0
	adds r0, r6, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	mov r0, r8
	ldr r1, [r0, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #6
	bl FUN_08236fac
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a14
_081D92A0:
	adds r4, r5, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D92CE
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D92D6
_081D92CE:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D92D6:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D92FA
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9302
_081D92FA:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9302:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D933C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9382
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9346
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9340
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D935C
	.align 2, 0
_081D933C: .4byte 0x0000FFFF
_081D9340:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D935A
_081D9346:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D935A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D935C
_081D935A:
	movs r2, #0
_081D935C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9384
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9384
_081D9382:
	movs r2, #0
_081D9384:
	ldrh r0, [r7]
	cmp r0, #0
	beq _081D9390
	subs r0, #1
	strh r0, [r7]
	b _081D93A2
_081D9390:
	cmp r2, #0
	beq _081D93A2
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #2
_081D939A:
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D93A2:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d93b0
FUN_081d93b0: @ 0x081D93B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D93CC
	b _081D94F8
_081D93CC:
	movs r0, #0x75
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	movs r6, #0
	mov r2, sl
	strb r0, [r2]
	ldr r4, _081D9480 @ =0x0203B400
	mov sb, r4
	ldr r5, _081D9484 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081D9488 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	ldrb r2, [r2]
	adds r0, r0, r2
	mov r4, sl
	strb r0, [r4]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r7, #0
	adds r0, #0x2c
	ldr r2, [sp, #0xc]
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #7
	bl FUN_08236fac
	adds r0, r7, #0
	adds r0, #0x78
	strb r6, [r0]
	subs r0, #8
	strh r6, [r0]
	add r0, sp, #8
	adds r4, r7, #0
	adds r4, #0x58
	str r6, [sp, #8]
	adds r1, r4, #0
	ldr r2, _081D948C @ =0x05000002
	bl CpuSet
	mov r0, sl
	ldrb r2, [r0]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r3, r1, #2
	ldr r1, _081D9490 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	movs r5, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D9494
	asrs r1, r0, #0xc
	b _081D949A
	.align 2, 0
_081D9480: .4byte 0x0203B400
_081D9484: .4byte 0x030046B8
_081D9488: .4byte 0x000003FF
_081D948C: .4byte 0x05000002
_081D9490: .4byte 0x085B0A08
_081D9494:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D949A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D94B4 @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D94B8
	asrs r0, r0, #0xc
	b _081D94BE
	.align 2, 0
_081D94B4: .4byte 0x085B0A08
_081D94B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D94BE:
	movs r3, #0
	strh r0, [r4, #4]
	ldr r2, _081D9558 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D955C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081D9560 @ =0x0203B400
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, _081D9564 @ =0x03002BE0
	ldr r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r4, _081D9568 @ =0x000001FF
	adds r1, r4, #0
	ands r2, r1
	adds r0, r0, r2
	adds r1, r7, #0
	adds r1, #0x7a
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	strb r3, [r0]
_081D94F8:
	movs r5, #0x1e
	ldrsh r0, [r7, r5]
	adds r1, r7, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	cmp r0, r1
	bge _081D956C
	adds r4, r7, #0
	adds r4, #0x70
	ldrh r0, [r4]
	movs r1, #4
	bl Mod
	mov sb, r4
	adds r1, r7, #0
	adds r1, #0x5a
	cmp r0, #0
	bne _081D9522
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
_081D9522:
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1]
	ldrh r4, [r7, #0x1e]
	adds r0, r0, r4
	strh r0, [r7, #0x1e]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r5, [r7, #0x20]
	adds r0, r0, r5
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x78
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _081D9588
	ldrh r0, [r7, #0x34]
	cmp r0, #5
	bne _081D9588
	b _081D957C
	.align 2, 0
_081D9558: .4byte 0x030046B8
_081D955C: .4byte 0x000003FF
_081D9560: .4byte 0x0203B400
_081D9564: .4byte 0x03002BE0
_081D9568: .4byte 0x000001FF
_081D956C:
	adds r1, r7, #0
	adds r1, #0x68
	movs r0, #4
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D96A8
_081D957C:
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne _081D9588
	movs r0, #0xf6
	bl PlaySound_082406e0
_081D9588:
	adds r4, r7, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D95BA
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D95C2
_081D95BA:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D95C2:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D95E6
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D95EE
_081D95E6:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D95EE:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9628 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _081D966E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9632
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D962C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D9648
	.align 2, 0
_081D9628: .4byte 0x0000FFFF
_081D962C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9646
_081D9632:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9646
	strh r1, [r4, #8]
	movs r2, #1
	b _081D9648
_081D9646:
	movs r2, #0
_081D9648:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9670
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9670
_081D966E:
	movs r2, #0
_081D9670:
	cmp r2, #0
	beq _081D96A0
	adds r0, r7, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	ldr r5, [sp, #0xc]
	ldr r1, [r5, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	mov r0, r8
	movs r2, #1
	bl FUN_08236fac
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_081D96A0:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D96A8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d96b8
FUN_081d96b8: @ 0x081D96B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	adds r1, #0x74
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D978C
	movs r0, #0
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x75
	ldrb r3, [r4]
	ldr r2, _081D9714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D9718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D971C @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r6, r5, #0
	adds r6, #0x58
	adds r7, r1, #0
	adds r7, #0xc
	ldr r2, _081D9720 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9724
	asrs r1, r0, #0xc
	b _081D972A
	.align 2, 0
_081D9714: .4byte 0x030046B8
_081D9718: .4byte 0x000003FF
_081D971C: .4byte 0x0203B400
_081D9720: .4byte 0x085B0A08
_081D9724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D972A:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9742
	asrs r1, r0, #0xc
	b _081D9748
_081D9742:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D9748:
	movs r0, #0
	strh r1, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r5, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #1
	strb r0, [r5, #7]
_081D978C:
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r2, [r5, #0x20]
	adds r0, r0, r2
	strh r0, [r5, #0x20]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D97D4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D97DC
_081D97D4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D97DC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D9800
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D9808
_081D9800:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9808:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9840 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9878
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9844
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9838
	ldrb r0, [r4, #5]
_081D9838:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9854
	.align 2, 0
_081D9840: .4byte 0x0000FFFF
_081D9844:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9854
	strh r1, [r4, #8]
_081D9854:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9878
	movs r0, #1
	strb r0, [r4, #7]
_081D9878:
	adds r0, r5, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9892
	adds r1, r5, #0
	adds r1, #0x68
	movs r0, #5
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D9892:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d98a0
FUN_081d98a0: @ 0x081D98A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x74
	ldrb r0, [r5]
	cmp r0, #0
	beq _081D98E6
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D98C8
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_080138fc
_081D98C8:
	adds r3, r4, #0
	adds r3, #0x6c
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D98FC @ =0x00000ECC
	adds r2, r6, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D9900 @ =0x0000FFFF
	strh r0, [r3]
	movs r0, #0
	strb r0, [r5]
_081D98E6:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D98FC: .4byte 0x00000ECC
_081D9900: .4byte 0x0000FFFF

	thumb_func_start FUN_081d9904
FUN_081d9904: @ 0x081D9904
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D9934 @ =0x00000ECC
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D9962
	movs r4, #0
	ldr r0, _081D9934 @ =0x00000ECC
	adds r6, r5, r0
	ldr r1, _081D9938 @ =0x085AE12C
	mov r8, r1
_081D9924:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D993C
	movs r0, #1
	b _081D993E
	.align 2, 0
_081D9934: .4byte 0x00000ECC
_081D9938: .4byte 0x085AE12C
_081D993C:
	movs r0, #0
_081D993E:
	cmp r0, #0
	beq _081D995C
	movs r0, #0xbc
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0x68
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D995C:
	adds r4, #1
	cmp r4, #0x13
	ble _081D9924
_081D9962:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d9970
FUN_081d9970: @ 0x081D9970
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _081D998C @ =0x00000ECC
	adds r7, r6, r0
_081D997A:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D9990
	movs r0, #1
	b _081D9992
	.align 2, 0
_081D998C: .4byte 0x00000ECC
_081D9990:
	movs r0, #0
_081D9992:
	cmp r0, #0
	beq _081D99B6
	movs r0, #0xbc
	muls r0, r5, r0
	adds r0, #0x1c
	adds r4, r6, r0
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D99B6
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_080138fc
_081D99B6:
	adds r5, #1
	cmp r5, #0x13
	ble _081D997A
	ldr r1, _081D99C8 @ =0x030001A4
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D99C8: .4byte 0x030001A4

	thumb_func_start FUN_081d99cc
FUN_081d99cc: @ 0x081D99CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D99F8 @ =0x0000922E
	ldr r1, _081D99FC @ =0x00007B03
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D9A00 @ =0x030001A4
	str r4, [r0]
	ldr r0, _081D9A04 @ =0x00000ECC
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	movs r0, #0xed
	lsls r0, r0, #4
	adds r4, r4, r0
	subs r0, #0xc0
	str r0, [r4]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D99F8: .4byte 0x0000922E
_081D99FC: .4byte 0x00007B03
_081D9A00: .4byte 0x030001A4
_081D9A04: .4byte 0x00000ECC

	thumb_func_start FUN_081d9a08
FUN_081d9a08: @ 0x081D9A08
	push {r4, lr}
	ldr r0, _081D9A3C @ =0x030001A4
	ldr r0, [r0]
	cmp r0, #0
	bne _081D9A4E
	ldr r1, _081D9A40 @ =0x00000ED4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D9A4C
	ldr r1, _081D9A44 @ =FUN_081d9904
	ldr r2, _081D9A48 @ =FUN_081d9970
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d99cc
	cmp r0, #0
	bge _081D9A4C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D9A4E
	.align 2, 0
_081D9A3C: .4byte 0x030001A4
_081D9A40: .4byte 0x00000ED4
_081D9A44: .4byte FUN_081d9904
_081D9A48: .4byte FUN_081d9970
_081D9A4C:
	adds r0, r4, #0
_081D9A4E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d9a54
FUN_081d9a54: @ 0x081D9A54
	ldr r1, _081D9A5C @ =0x030001A4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D9A5C: .4byte 0x030001A4

	thumb_func_start FUN_081d9a60
FUN_081d9a60: @ 0x081D9A60
	ldr r1, _081D9A68 @ =0x03002C64
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D9A68: .4byte 0x03002C64

	thumb_func_start FUN_081d9a6c
FUN_081d9a6c: @ 0x081D9A6C
	push {lr}
	ldr r1, [r0, #0x34]
	adds r1, #1
	str r1, [r0, #0x34]
	ldr r0, [r0, #0x18]
	cmp r1, r0
	bge _081D9A7E
	movs r0, #0
	b _081D9A80
_081D9A7E:
	movs r0, #1
_081D9A80:
	pop {r1}
	bx r1

	thumb_func_start FUN_081d9a84
FUN_081d9a84: @ 0x081D9A84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	beq _081D9AD0
	bl FUN_08238bf4
	movs r0, #1
	str r0, [r6, #0x30]
	ldr r0, [r6, #0x28]
	cmp r0, #0
	beq _081D9AB8
	ldr r3, [r6, #0x68]
	cmp r3, #0
	beq _081D9AC8
	ldr r0, [r6, #0x70]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x20]
	bl _call_via_r3
	b _081D9AC8
_081D9AB8:
	ldr r3, [r6, #0x6c]
	cmp r3, #0
	beq _081D9AC8
	ldr r0, [r6, #0x70]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x20]
	bl _call_via_r3
_081D9AC8:
	adds r0, r6, #0
	bl KillEntity
	b _081D9C82
_081D9AD0:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r1, #0
	mov sl, r1
	movs r4, #1
	mov sb, r4
	ldr r0, [r6, #0x24]
	cmp r0, #0
	bge _081D9B24
	ldr r0, [r6, #0x54]
	adds r0, #1
	str r0, [r6, #0x54]
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	cmp r0, #0
	bge _081D9B0C
	ldr r0, [r6, #0x40]
	cmp r0, #0x1d
	ble _081D9B08
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	mov r0, sl
	b _081D9B0A
_081D9B08:
	adds r0, #1
_081D9B0A:
	str r0, [r6, #0x40]
_081D9B0C:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9B1C
	movs r0, #1
	str r0, [r6, #0x2c]
_081D9B1C:
	movs r0, #0
	str r0, [r6, #0x3c]
	str r0, [r6, #0x38]
	b _081D9C5E
_081D9B24:
	adds r5, r6, #0
	adds r5, #0x5e
	adds r0, r5, #0
	bl FUN_08238da8
	str r0, [r6, #0x48]
	adds r4, r6, #0
	adds r4, #0x5c
	ldrh r0, [r4]
	bl FUN_08238e14
	str r0, [r6, #0x44]
	ldr r0, [r6, #0x2c]
	str r4, [sp]
	cmp r0, #0
	bne _081D9B4E
	ldr r0, [r6, #0x24]
	cmp r0, #0
	bne _081D9B4E
	bl FUN_08238d84
_081D9B4E:
	ldr r0, [r6, #0x48]
	cmp r0, #0
	blt _081D9BD8
	ldr r0, [r6, #0x58]
	adds r0, #1
	str r0, [r6, #0x58]
	movs r1, #0
	ldr r3, _081D9B78 @ =0x0000FFFF
	movs r2, #0xc9
	lsls r2, r2, #1
_081D9B62:
	ldrh r0, [r5]
	cmp r0, r3
	beq _081D9B8C
	mov r4, sb
	cmp r4, #0
	beq _081D9B86
	cmp r0, r2
	bne _081D9B7C
	adds r7, #1
	b _081D9B86
	.align 2, 0
_081D9B78: .4byte 0x0000FFFF
_081D9B7C:
	cmp r0, #0xe2
	bne _081D9B86
	adds r7, #1
	movs r0, #1
	add sl, r0
_081D9B86:
	movs r4, #1
	add r8, r4
	b _081D9B90
_081D9B8C:
	movs r0, #0
	mov sb, r0
_081D9B90:
	adds r5, #2
	adds r1, #1
	cmp r1, #3
	ble _081D9B62
	mov r1, r8
	cmp r1, #2
	bne _081D9BB8
	cmp r7, #2
	bne _081D9BB8
	ldr r0, [r6, #0x38]
	adds r0, #1
	str r0, [r6, #0x38]
	cmp r0, #0x77
	ble _081D9BB2
	movs r0, #0xe2
	ldr r4, [sp]
	strh r0, [r4]
_081D9BB2:
	movs r0, #0
	str r0, [r6, #0x34]
	b _081D9BCC
_081D9BB8:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9BC8
	movs r0, #1
	str r0, [r6, #0x2c]
_081D9BC8:
	movs r0, #0
	str r0, [r6, #0x38]
_081D9BCC:
	mov r0, sl
	cmp r0, #2
	bne _081D9C5A
	movs r0, #1
	str r0, [r6, #0x28]
	b _081D9C58
_081D9BD8:
	movs r5, #0
	movs r0, #0xc9
	lsls r0, r0, #1
	ldr r1, [sp]
	strh r0, [r1]
	ldr r1, [r6, #0x48]
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bne _081D9C26
	ldr r0, [r6, #0x4c]
	adds r0, #1
	str r0, [r6, #0x4c]
	ldr r0, [r6, #0x3c]
	cmp r0, #0x1d
	ble _081D9C10
	bl FUN_08238bf4
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	str r5, [r6, #0x38]
	str r5, [r6, #0x50]
	str r5, [r6, #0x3c]
	str r5, [r6, #0x40]
	b _081D9C14
_081D9C10:
	adds r0, #1
	str r0, [r6, #0x3c]
_081D9C14:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9C5E
	movs r0, #1
	str r0, [r6, #0x2c]
	b _081D9C5E
_081D9C26:
	str r5, [r6, #0x38]
	ldr r0, [r6, #0x50]
	cmp r0, #0x1d
	ble _081D9C46
	bl FUN_08238bf4
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	str r5, [r6, #0x38]
	str r5, [r6, #0x50]
	str r5, [r6, #0x3c]
	str r5, [r6, #0x40]
	b _081D9C4A
_081D9C46:
	adds r0, #1
	str r0, [r6, #0x50]
_081D9C4A:
	adds r0, r6, #0
	bl FUN_081d9a6c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9C5A
	movs r0, #1
_081D9C58:
	str r0, [r6, #0x2c]
_081D9C5A:
	movs r0, #0
	str r0, [r6, #0x3c]
_081D9C5E:
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	beq _081D9C82
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	bne _081D9C82
	ldr r2, [r6, #0x28]
	cmp r2, #0
	bne _081D9C82
	ldr r0, _081D9C94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D9C82
	movs r0, #1
	str r0, [r6, #0x2c]
	str r0, [r6, #0x20]
_081D9C82:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D9C94: .4byte 0x030044E0

	thumb_func_start FUN_081d9c98
FUN_081d9c98: @ 0x081D9C98
	push {lr}
	ldr r0, [r0, #0x30]
	cmp r0, #0
	bne _081D9CA4
	bl FUN_08238bf4
_081D9CA4:
	ldr r1, _081D9CB0 @ =0x03002C64
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_081D9CB0: .4byte 0x03002C64

	thumb_func_start FUN_081d9cb4
FUN_081d9cb4: @ 0x081D9CB4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _081D9CE0 @ =0x03002C64
	str r4, [r0]
	bl FUN_08241704
	ldr r1, _081D9CE4 @ =0x0300481C
	movs r0, #1
	str r0, [r1]
	bl FUN_08237e98
	bl FUN_08238b04
	cmp r5, #0
	bne _081D9CE8
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r4, #0x18]
	b _081D9CEA
	.align 2, 0
_081D9CE0: .4byte 0x03002C64
_081D9CE4: .4byte 0x0300481C
_081D9CE8:
	str r5, [r4, #0x18]
_081D9CEA:
	str r6, [r4, #0x1c]
	movs r1, #0
	str r1, [r4, #0x20]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	str r1, [r4, #0x34]
	str r1, [r4, #0x38]
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	adds r2, r4, #0
	adds r2, #0x5c
	movs r0, #0xc9
	lsls r0, r0, #1
	strh r0, [r2]
	adds r2, #2
	ldr r0, _081D9D34 @ =0x0000FFFF
	strh r0, [r2]
	adds r2, #2
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	str r1, [r4, #0x70]
	str r1, [r4, #0x68]
	str r1, [r4, #0x6c]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081D9D34: .4byte 0x0000FFFF

	thumb_func_start FUN_081d9d38
FUN_081d9d38: @ 0x081D9D38
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _081D9D74 @ =0x03002C64
	ldr r0, [r0]
	cmp r0, #0
	bne _081D9D82
	movs r0, #2
	movs r1, #0x74
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D9D80
	ldr r1, _081D9D78 @ =FUN_081d9a84
	ldr r2, _081D9D7C @ =FUN_081d9c98
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_081d9cb4
	cmp r0, #0
	bge _081D9D80
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D9D82
	.align 2, 0
_081D9D74: .4byte 0x03002C64
_081D9D78: .4byte FUN_081d9a84
_081D9D7C: .4byte FUN_081d9c98
_081D9D80:
	adds r0, r4, #0
_081D9D82:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d9d88
FUN_081d9d88: @ 0x081D9D88
	push {lr}
	adds r3, r0, #0
	ldr r0, _081D9DA0 @ =0x03002C64
	ldr r0, [r0]
	cmp r0, #0
	beq _081D9D9A
	str r3, [r0, #0x70]
	str r1, [r0, #0x68]
	str r2, [r0, #0x6c]
_081D9D9A:
	pop {r0}
	bx r0
	.align 2, 0
_081D9DA0: .4byte 0x03002C64

	thumb_func_start FUN_081d9da4
FUN_081d9da4: @ 0x081D9DA4
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081D9DC4 @ =0x03002C68
	ldr r0, [r0]
	mov ip, r0
	cmp r0, #0
	beq _081D9DBC
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, ip
	cmp r4, #0
	bne _081D9DC8
_081D9DBC:
	movs r0, #1
	rsbs r0, r0, #0
	b _081D9E48
	.align 2, 0
_081D9DC4: .4byte 0x03002C68
_081D9DC8:
	ldr r1, _081D9DF0 @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	subs r1, #0xea
	add r1, ip
	strb r0, [r1]
	ldr r2, _081D9DF4 @ =0x00000287
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r2, #0xea
	add r2, ip
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #1
	beq _081D9E14
	cmp r0, #1
	bgt _081D9DF8
	cmp r0, #0
	beq _081D9DFE
	b _081D9E38
	.align 2, 0
_081D9DF0: .4byte 0x00000286
_081D9DF4: .4byte 0x00000287
_081D9DF8:
	cmp r0, #2
	beq _081D9E1C
	b _081D9E38
_081D9DFE:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r2, #0xf2
	b _081D9E2E
_081D9E14:
	ldr r1, _081D9E18 @ =0x085AE160
	b _081D9E1E
	.align 2, 0
_081D9E18: .4byte 0x085AE160
_081D9E1C:
	ldr r1, _081D9E34 @ =0x085AE168
_081D9E1E:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r2, #0xea
_081D9E2E:
	add r2, ip
	strb r0, [r2]
	b _081D9E46
	.align 2, 0
_081D9E34: .4byte 0x085AE168
_081D9E38:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
_081D9E46:
	movs r0, #0
_081D9E48:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d9e50
FUN_081d9e50: @ 0x081D9E50
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _081D9E68 @ =0x00000286
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081D9E9C
	cmp r0, #1
	bgt _081D9E6C
	cmp r0, #0
	beq _081D9E72
	b _081D9EE4
	.align 2, 0
_081D9E68: .4byte 0x00000286
_081D9E6C:
	cmp r0, #2
	beq _081D9EBC
	b _081D9EE4
_081D9E72:
	movs r2, #0
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bge _081D9EEE
	subs r3, #4
	adds r5, r1, r3
	adds r3, #8
	adds r4, r1, r3
	ldrb r1, [r5]
	adds r3, r0, #0
_081D9E8C:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	beq _081D9EDC
	adds r2, #1
	cmp r2, r3
	blt _081D9E8C
	b _081D9EEE
_081D9E9C:
	movs r2, #0
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrb r1, [r4]
	ldr r3, _081D9EB8 @ =0x085AE160
_081D9EA8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #1
	ble _081D9EA8
	b _081D9EEE
	.align 2, 0
_081D9EB8: .4byte 0x085AE160
_081D9EBC:
	movs r2, #0
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r4, r1, r3
	ldrb r1, [r4]
	ldr r3, _081D9ED8 @ =0x085AE168
_081D9EC8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #0
	ble _081D9EC8
	b _081D9EEE
	.align 2, 0
_081D9ED8: .4byte 0x085AE168
_081D9EDC:
	strb r2, [r5]
	b _081D9EEE
_081D9EE0:
	strb r2, [r4]
	b _081D9EEE
_081D9EE4:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
_081D9EEE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d9ef4
FUN_081d9ef4: @ 0x081D9EF4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081da370
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_081da5d0
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F36
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081D9F36:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d9f3c
FUN_081d9f3c: @ 0x081D9F3C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da370
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081da5d0
	bl FUN_081df974
	ldr r0, _081D9F88 @ =0x000002A2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F82
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081D9F82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D9F88: .4byte 0x000002A2

	thumb_func_start FUN_081d9f8c
FUN_081d9f8c: @ 0x081D9F8C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D9FF0 @ =0x0000C091
	ldr r1, _081D9FF4 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #5
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081D9FF8 @ =0x000092B3
	ldr r1, _081D9FFC @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DA000 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	ldr r0, _081DA004 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DA008
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DA008
	movs r0, #1
	b _081DA00A
	.align 2, 0
_081D9FF0: .4byte 0x0000C091
_081D9FF4: .4byte 0x0000CD91
_081D9FF8: .4byte 0x000092B3
_081D9FFC: .4byte 0x000026BB
_081DA000: .4byte 0x03004250
_081DA004: .4byte 0x03002C68
_081DA008:
	movs r0, #0
_081DA00A:
	cmp r0, #0
	bne _081DA02E
	movs r4, #0
	movs r5, #3
_081DA012:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DA012
_081DA02E:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da038
FUN_081da038: @ 0x081DA038
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r5, #0
	ldr r4, _081DA070 @ =0x085AE144
	movs r6, #6
_081DA042:
	ldr r0, [r4]
	bl IsMagicUnlocked
	cmp r0, #0
	beq _081DA05A
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r0, r0, r5
	ldr r1, [r4]
	strb r1, [r0]
	adds r5, #1
_081DA05A:
	adds r4, #4
	subs r6, #1
	cmp r6, #0
	bge _081DA042
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA070: .4byte 0x085AE144

	thumb_func_start FUN_081da074
FUN_081da074: @ 0x081DA074
	push {lr}
	adds r2, r0, #0
	ldr r1, _081DA08C @ =0x00000286
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA0A6
	cmp r0, #1
	bgt _081DA090
	cmp r0, #0
	beq _081DA096
	b _081DA0BC
	.align 2, 0
_081DA08C: .4byte 0x00000286
_081DA090:
	cmp r0, #2
	beq _081DA0B4
	b _081DA0BC
_081DA096:
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r1, [r0]
	subs r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	b _081DA0BC
_081DA0A6:
	ldr r0, _081DA0B0 @ =0x0000028B
	adds r1, r2, r0
	movs r0, #2
	b _081DA0BA
	.align 2, 0
_081DA0B0: .4byte 0x0000028B
_081DA0B4:
	ldr r3, _081DA0C0 @ =0x0000028B
	adds r1, r2, r3
	movs r0, #1
_081DA0BA:
	strb r0, [r1]
_081DA0BC:
	pop {r0}
	bx r0
	.align 2, 0
_081DA0C0: .4byte 0x0000028B

	thumb_func_start FUN_081da0c4
FUN_081da0c4: @ 0x081DA0C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081DA0FC @ =0x0000029D
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DA100 @ =0x00000286
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _081DA104 @ =0x030046A0
	ldr r1, [r0]
	subs r2, #0x48
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081DA10C
	ldr r0, _081DA108 @ =0x00000289
	adds r1, r4, r0
	movs r0, #3
	b _081DA128
	.align 2, 0
_081DA0FC: .4byte 0x0000029D
_081DA100: .4byte 0x00000286
_081DA104: .4byte 0x030046A0
_081DA108: .4byte 0x00000289
_081DA10C:
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _081DA122
	adds r2, #0x51
	adds r1, r4, r2
	movs r0, #2
	b _081DA128
_081DA122:
	ldr r0, _081DA144 @ =0x00000289
	adds r1, r4, r0
	movs r0, #1
_081DA128:
	strb r0, [r1]
	ldr r2, _081DA148 @ =0x0000028A
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081da038
	adds r0, r4, #0
	bl FUN_081da074
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DA144: .4byte 0x00000289
_081DA148: .4byte 0x0000028A

	thumb_func_start FUN_081da14c
FUN_081da14c: @ 0x081DA14C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DA164 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA17C
	cmp r0, #1
	bgt _081DA168
	cmp r0, #0
	beq _081DA16E
	b _081DA1E0
	.align 2, 0
_081DA164: .4byte 0x0000029D
_081DA168:
	cmp r0, #2
	beq _081DA18C
	b _081DA1E0
_081DA16E:
	ldr r2, _081DA178 @ =0x00000286
	adds r0, r5, r2
	ldrb r1, [r0]
	b _081DA1E2
	.align 2, 0
_081DA178: .4byte 0x00000286
_081DA17C:
	ldr r1, _081DA188 @ =0x00000287
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #3
	b _081DA1E2
	.align 2, 0
_081DA188: .4byte 0x00000287
_081DA18C:
	ldr r2, _081DA1A0 @ =0x00000286
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA1C0
	cmp r0, #1
	bgt _081DA1A4
	cmp r0, #0
	beq _081DA1AA
	b _081DA1E0
	.align 2, 0
_081DA1A0: .4byte 0x00000286
_081DA1A4:
	cmp r0, #2
	beq _081DA1C8
	b _081DA1E0
_081DA1AA:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r1, r0, #7
	b _081DA1E2
_081DA1C0:
	ldr r1, _081DA1C4 @ =0x085AE160
	b _081DA1CA
	.align 2, 0
_081DA1C4: .4byte 0x085AE160
_081DA1C8:
	ldr r1, _081DA1DC @ =0x085AE168
_081DA1CA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #7
	b _081DA1E2
	.align 2, 0
_081DA1DC: .4byte 0x085AE168
_081DA1E0:
	movs r1, #0
_081DA1E2:
	ldr r0, _081DA214 @ =0x0000029B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #0x19
	cmp r0, r4
	beq _081DA20E
	bl FUN_08049e5c
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r4, [r6]
_081DA20E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA214: .4byte 0x0000029B

	thumb_func_start FUN_081da218
FUN_081da218: @ 0x081DA218
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r5, r7, r1
	ldr r1, [r5]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r2, _081DA288 @ =0x00000286
	adds r6, r7, r2
	ldrb r1, [r6]
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r1, [r6]
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	ldr r1, [r5]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r1, _081DA28C @ =0x00000287
	adds r5, r7, r1
	ldrb r1, [r5]
	adds r1, #3
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r1, [r5]
	ldr r2, _081DA290 @ =0x00000299
	adds r0, r7, r2
	strb r1, [r0]
	ldrb r0, [r6]
	cmp r0, #1
	beq _081DA2AE
	cmp r0, #1
	bgt _081DA294
	cmp r0, #0
	beq _081DA29A
	b _081DA2D0
	.align 2, 0
_081DA288: .4byte 0x00000286
_081DA28C: .4byte 0x00000287
_081DA290: .4byte 0x00000299
_081DA294:
	cmp r0, #2
	beq _081DA2B8
	b _081DA2D0
_081DA29A:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r5, [r0]
	b _081DA2D2
_081DA2AE:
	ldr r1, _081DA2B4 @ =0x085AE160
	b _081DA2BA
	.align 2, 0
_081DA2B4: .4byte 0x085AE160
_081DA2B8:
	ldr r1, _081DA2CC @ =0x085AE168
_081DA2BA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA2D2
	.align 2, 0
_081DA2CC: .4byte 0x085AE168
_081DA2D0:
	movs r5, #0
_081DA2D2:
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #7
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _081DA308 @ =0x0000029A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA308: .4byte 0x0000029A

	thumb_func_start FUN_081da30c
FUN_081da30c: @ 0x081DA30C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x12
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x12
	movs r1, #8
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x10
	movs r1, #0xc
	movs r2, #0xc
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	bl FUN_08049f5c
	bl FUN_08049e5c
	movs r2, #1
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081da0c4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da370
FUN_081da370: @ 0x081DA370
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da3a0
FUN_081da3a0: @ 0x081DA3A0
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r4, _081DA3EC @ =0x0000CB05
	ldr r1, _081DA3F0 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	bl OpenSpriteSetFile
	ldr r1, _081DA3F4 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x24
	adds r0, r5, r2
	bl OpenSpriteSetFile
	movs r4, #0
_081DA3DE:
	cmp r4, #4
	bhi _081DA434
	lsls r0, r4, #2
	ldr r1, _081DA3F8 @ =_081DA3FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA3EC: .4byte 0x0000CB05
_081DA3F0: .4byte 0x0000DCC1
_081DA3F4: .4byte 0x00005D04
_081DA3F8: .4byte _081DA3FC
_081DA3FC: @ jump table
	.4byte _081DA410 @ case 0
	.4byte _081DA418 @ case 1
	.4byte _081DA420 @ case 2
	.4byte _081DA428 @ case 3
	.4byte _081DA42C @ case 4
_081DA410:
	movs r2, #0x33
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA418:
	movs r2, #0x34
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA420:
	movs r2, #0x35
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA428:
	movs r2, #0xb6
	b _081DA436
_081DA42C:
	movs r2, #0x15
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA434:
	movs r2, #0
_081DA436:
	movs r0, #0x88
	lsls r0, r0, #2
_081DA43A:
	adds r3, r5, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r5, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r4, #1
	cmp r4, #4
	ble _081DA3DE
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da468
FUN_081da468: @ 0x081DA468
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r7, #0
_081DA46E:
	cmp r7, #4
	bls _081DA474
	b _081DA5C0
_081DA474:
	lsls r0, r7, #2
	ldr r1, _081DA480 @ =_081DA484
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA480: .4byte _081DA484
_081DA484: @ jump table
	.4byte _081DA498 @ case 0
	.4byte _081DA4CC @ case 1
	.4byte _081DA50C @ case 2
	.4byte _081DA594 @ case 3
	.4byte _081DA5AC @ case 4
_081DA498:
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #5
	adds r1, r6, r1
	ldr r3, _081DA4C4 @ =0x085AE16C
	ldr r0, _081DA4C8 @ =0x0000029D
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r2, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r2, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r3, #4
	adds r0, r0, r3
	ldr r0, [r0]
	adds r1, #0x42
	strh r0, [r1]
	b _081DA5C0
	.align 2, 0
_081DA4C4: .4byte 0x085AE16C
_081DA4C8: .4byte 0x0000029D
_081DA4CC:
	ldr r1, _081DA4FC @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA4E0
	ldr r2, _081DA500 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4E0:
	cmp r1, #2
	bne _081DA4EE
	ldr r1, _081DA504 @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4EE:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA508 @ =0x085AE184
	b _081DA55A
	.align 2, 0
_081DA4FC: .4byte 0x0000029D
_081DA500: .4byte 0x00000289
_081DA504: .4byte 0x0000028B
_081DA508: .4byte 0x085AE184
_081DA50C:
	ldr r1, _081DA544 @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA520
	ldr r2, _081DA548 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA520:
	cmp r1, #2
	bne _081DA550
	ldr r1, _081DA54C @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _081DA550
_081DA52E:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA544: .4byte 0x0000029D
_081DA548: .4byte 0x00000289
_081DA54C: .4byte 0x0000028B
_081DA550:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA58C @ =0x085AE19C
_081DA55A:
	ldr r0, _081DA590 @ =0x0000029D
	adds r5, r6, r0
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x42
	strh r0, [r4]
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA58C: .4byte 0x085AE19C
_081DA590: .4byte 0x0000029D
_081DA594:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r2, r0, #0
	adds r2, #0x40
	movs r1, #0x48
	strh r1, [r2]
	adds r0, #0x42
	movs r1, #0x60
	strh r1, [r0]
	b _081DA5C0
_081DA5AC:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	strh r2, [r1]
	adds r0, #0x42
	strh r2, [r0]
_081DA5C0:
	adds r7, #1
	cmp r7, #4
	bgt _081DA5C8
	b _081DA46E
_081DA5C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da5d0
FUN_081da5d0: @ 0x081DA5D0
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #4
_081DA5DA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DA5DA
	pop {r0}
	bx r0

	thumb_func_start FUN_081da5ec
FUN_081da5ec: @ 0x081DA5EC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #4
_081DA5F4:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DA5F4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081da608
FUN_081da608: @ 0x081DA608
	push {lr}
	mov ip, r0
	ldr r0, _081DA644 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _081DA648 @ =0x00005260
	adds r2, r0, r1
	movs r1, #0x92
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0xf
_081DA61C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081DA61C
	movs r0, #0x92
	lsls r0, r0, #2
	add r0, ip
	mov r1, ip
	str r0, [r1, #0x68]
	movs r1, #0x9a
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081DA644: .4byte 0x03003584
_081DA648: .4byte 0x00005260

	thumb_func_start FUN_081da64c
FUN_081da64c: @ 0x081DA64C
	push {lr}
	adds r3, r0, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081DA678
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081DA678
	movs r2, #0x12
	cmp r0, #0x19
	bls _081DA678
	movs r2, #0xa
	cmp r0, #0x21
	bls _081DA678
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081DA678
	movs r2, #0x12
_081DA678:
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DA690
	movs r0, #0
	strh r0, [r1]
_081DA690:
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0

	thumb_func_start FUN_081da69c
FUN_081da69c: @ 0x081DA69C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	adds r1, #0x12
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	beq _081DA724
	subs r1, #0x14
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA6DC
	cmp r0, #1
	bgt _081DA6CA
	cmp r0, #0
	beq _081DA6D0
	b _081DA6F4
_081DA6CA:
	cmp r0, #2
	beq _081DA6E4
	b _081DA6F4
_081DA6D0:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r6, r1
	adds r0, r0, r2
	ldrb r5, [r0]
	b _081DA6F6
_081DA6DC:
	ldr r1, _081DA6E0 @ =0x085AE160
	b _081DA6E6
	.align 2, 0
_081DA6E0: .4byte 0x085AE160
_081DA6E4:
	ldr r1, _081DA6F0 @ =0x085AE168
_081DA6E6:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA6F6
	.align 2, 0
_081DA6F0: .4byte 0x085AE168
_081DA6F4:
	movs r5, #0
_081DA6F6:
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r4, r6, r2
	ldr r0, [r4]
	subs r2, #0x10
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #7
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r1, [r0]
	ldr r2, _081DA72C @ =0x0000029A
	adds r0, r6, r2
	strb r1, [r0]
_081DA724:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA72C: .4byte 0x0000029A

	thumb_func_start FUN_081da730
FUN_081da730: @ 0x081DA730
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _081DA74C @ =0x0000029D
	adds r0, r5, r1
	ldrb r7, [r0]
	cmp r7, #1
	beq _081DA7C0
	cmp r7, #1
	bgt _081DA750
	cmp r7, #0
	beq _081DA756
	b _081DA80A
	.align 2, 0
_081DA74C: .4byte 0x0000029D
_081DA750:
	cmp r7, #2
	beq _081DA804
	b _081DA80A
_081DA756:
	ldr r2, _081DA7B8 @ =0x00000286
	adds r6, r5, r2
	ldrb r1, [r6]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x16
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r6]
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, _081DA7BC @ =0x0000029A
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r7, [r0]
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da69c
	adds r0, r5, #0
	bl FUN_081da814
	b _081DA80A
	.align 2, 0
_081DA7B8: .4byte 0x00000286
_081DA7BC: .4byte 0x0000029A
_081DA7C0:
	ldr r2, _081DA7FC @ =0x00000287
	adds r6, r5, r2
	ldrb r1, [r6]
	ldr r0, _081DA800 @ =0x00000299
	adds r7, r5, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x17
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r6]
	adds r1, #3
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r0, [r6]
	strb r0, [r7]
	b _081DA80A
	.align 2, 0
_081DA7FC: .4byte 0x00000287
_081DA800: .4byte 0x00000299
_081DA804:
	adds r0, r5, #0
	bl FUN_081da69c
_081DA80A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081da814
FUN_081da814: @ 0x081DA814
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _081DA82C @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA84A
	cmp r0, #1
	bgt _081DA830
	cmp r0, #0
	beq _081DA836
	b _081DA870
	.align 2, 0
_081DA82C: .4byte 0x00000286
_081DA830:
	cmp r0, #2
	beq _081DA858
	b _081DA870
_081DA836:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r4, #0xa4
	lsls r4, r4, #2
	adds r0, r3, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	b _081DA872
_081DA84A:
	ldr r1, _081DA854 @ =0x085AE160
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	b _081DA860
	.align 2, 0
_081DA854: .4byte 0x085AE160
_081DA858:
	ldr r1, _081DA86C @ =0x085AE168
	movs r4, #0xa2
	lsls r4, r4, #2
	adds r0, r3, r4
_081DA860:
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	b _081DA872
	.align 2, 0
_081DA86C: .4byte 0x085AE168
_081DA870:
	movs r2, #0
_081DA872:
	adds r2, #0xb6
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r4, #0x88
	lsls r4, r4, #2
	adds r1, r3, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da890
FUN_081da890: @ 0x081DA890
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DA8AC
	ldr r1, _081DA8D0 @ =0x0000029E
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081DA8AC:
	ldr r0, _081DA8D0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DA8C2
	adds r0, r5, #0
	bl FUN_081d9da4
	adds r0, r5, #0
	bl FUN_081d9ef4
_081DA8C2:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DA8D0: .4byte 0x0000029E

	thumb_func_start FUN_081da8d4
FUN_081da8d4: @ 0x081DA8D4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA908
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DA928 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _081DA92C @ =0x0000029E
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
_081DA908:
	ldr r0, _081DA92C @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x14
	bne _081DA918
	adds r0, r5, #0
	bl FUN_081d9f3c
_081DA918:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA928: .4byte 0x0000FFFF
_081DA92C: .4byte 0x0000029E

	thumb_func_start FUN_081da930
FUN_081da930: @ 0x081DA930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA97A
	bl FUN_08049e5c
	ldr r1, _081DA998 @ =0x00000286
	adds r0, r5, r1
	ldrb r4, [r0]
	movs r3, #0x9c
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	adds r4, #0x19
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	adds r0, r5, #0
	bl FUN_081da730
	ldr r1, _081DA99C @ =0x0000029D
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081DA9A0 @ =0x0000029E
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	strb r1, [r6]
_081DA97A:
	ldr r0, _081DA9A0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DA9A4
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DAC98
	.align 2, 0
_081DA998: .4byte 0x00000286
_081DA99C: .4byte 0x0000029D
_081DA9A0: .4byte 0x0000029E
_081DA9A4:
	ldr r1, _081DA9C0 @ =0x0000029D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r3, _081DA9C4 @ =0x00000285
	adds r6, r5, r3
	movs r3, #0
	ldr r1, _081DA9C8 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DA9CC
	movs r3, #1
	b _081DAA06
	.align 2, 0
_081DA9C0: .4byte 0x0000029D
_081DA9C4: .4byte 0x00000285
_081DA9C8: .4byte 0x030044E0
_081DA9CC:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DA9D8
	movs r3, #2
	b _081DAA06
_081DA9D8:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DA9E4
	movs r3, #4
	b _081DAA06
_081DA9E4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DA9F0
	movs r3, #8
	b _081DAA06
_081DA9F0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DA9FC
	movs r3, #0x20
	b _081DAA06
_081DA9FC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DAA06
	movs r3, #0x10
_081DAA06:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DAA4E
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DAA4C
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DAA22
	movs r0, #1
	b _081DAA2C
_081DAA22:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DAA2E
	movs r0, #2
_081DAA2C:
	orrs r3, r0
_081DAA2E:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DAA3C
	movs r0, #4
	b _081DAA46
_081DAA3C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DAA48
	movs r0, #8
_081DAA46:
	orrs r3, r0
_081DAA48:
	movs r0, #0
	b _081DAA4E
_081DAA4C:
	adds r0, #1
_081DAA4E:
	strb r0, [r6]
	movs r6, #1
	adds r0, r3, #0
	ands r0, r6
	cmp r0, #0
	beq _081DAA70
	cmp r4, #0
	bne _081DAA62
	movs r4, #2
	b _081DAA64
_081DAA62:
	subs r4, #1
_081DAA64:
	ldr r0, _081DAA6C @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAA6C: .4byte 0x00000285
_081DAA70:
	movs r2, #2
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _081DAA86
	cmp r4, #2
	bne _081DAA82
	movs r4, #0
	b _081DABE8
_081DAA82:
	adds r4, #1
	b _081DABE8
_081DAA86:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DAB54
	ldr r1, _081DAAA4 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAAD8
	cmp r0, #1
	bgt _081DAAA8
	cmp r0, #0
	beq _081DAAAE
	b _081DAB42
	.align 2, 0
_081DAAA4: .4byte 0x0000029D
_081DAAA8:
	cmp r0, #2
	beq _081DAB0C
	b _081DAB42
_081DAAAE:
	ldr r3, _081DAAC4 @ =0x00000286
	adds r0, r5, r3
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAACC
	ldr r1, _081DAAC8 @ =0x00000289
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAACE
	.align 2, 0
_081DAAC4: .4byte 0x00000286
_081DAAC8: .4byte 0x00000289
_081DAACC:
	subs r1, r2, #1
_081DAACE:
	ldr r3, _081DAAD4 @ =0x00000286
	b _081DAAF8
	.align 2, 0
_081DAAD4: .4byte 0x00000286
_081DAAD8:
	ldr r1, _081DAAEC @ =0x00000287
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAAF4
	ldr r3, _081DAAF0 @ =0x0000028A
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAAF6
	.align 2, 0
_081DAAEC: .4byte 0x00000287
_081DAAF0: .4byte 0x0000028A
_081DAAF4:
	subs r1, r2, #1
_081DAAF6:
	ldr r3, _081DAB08 @ =0x00000287
_081DAAF8:
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB42
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DAB42
	.align 2, 0
_081DAB08: .4byte 0x00000287
_081DAB0C:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAB28
	ldr r3, _081DAB24 @ =0x0000028B
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAB2A
	.align 2, 0
_081DAB24: .4byte 0x0000028B
_081DAB28:
	subs r1, r2, #1
_081DAB2A:
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB3C
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAB3C:
	adds r0, r5, #0
	bl FUN_081da814
_081DAB42:
	adds r0, r5, #0
	bl FUN_081da730
	ldr r0, _081DAB50 @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAB50: .4byte 0x00000285
_081DAB54:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DABFC
	ldr r1, _081DAB70 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAB8C
	cmp r0, #1
	bgt _081DAB74
	cmp r0, #0
	beq _081DAB7A
	b _081DABE2
	.align 2, 0
_081DAB70: .4byte 0x0000029D
_081DAB74:
	cmp r0, #2
	beq _081DABB8
	b _081DABE2
_081DAB7A:
	ldr r0, _081DAB84 @ =0x00000286
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DAB88 @ =0x00000289
	b _081DAB94
	.align 2, 0
_081DAB84: .4byte 0x00000286
_081DAB88: .4byte 0x00000289
_081DAB8C:
	ldr r0, _081DABB0 @ =0x00000287
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABB4 @ =0x0000028A
_081DAB94:
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABA2
	movs r1, #0
_081DABA2:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABE2
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DABE2
	.align 2, 0
_081DABB0: .4byte 0x00000287
_081DABB4: .4byte 0x0000028A
_081DABB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABF4 @ =0x0000028B
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABD0
	movs r1, #0
_081DABD0:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABDC
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DABDC:
	adds r0, r5, #0
	bl FUN_081da814
_081DABE2:
	adds r0, r5, #0
	bl FUN_081da730
_081DABE8:
	ldr r3, _081DABF8 @ =0x00000285
	adds r1, r5, r3
_081DABEC:
	movs r0, #0
	strb r0, [r1]
	b _081DAC74
	.align 2, 0
_081DABF4: .4byte 0x0000028B
_081DABF8: .4byte 0x00000285
_081DABFC:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DAC28
	ldr r1, _081DAC24 @ =FUN_081da890
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r6, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC24: .4byte FUN_081da890
_081DAC28:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DAC74
	ldr r0, _081DAC44 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAC48
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DAC48
	movs r0, #1
	b _081DAC4A
	.align 2, 0
_081DAC44: .4byte 0x03002C68
_081DAC48:
	movs r0, #0
_081DAC4A:
	cmp r0, #0
	bne _081DAC74
	ldr r1, _081DAC70 @ =FUN_081da8d4
	movs r2, #1
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC70: .4byte FUN_081da8d4
_081DAC74:
	ldr r0, _081DACA0 @ =0x0000029D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DAC8C
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081da468
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAC8C:
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
_081DAC98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DACA0: .4byte 0x0000029D

	thumb_func_start FUN_081daca4
FUN_081daca4: @ 0x081DACA4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DACC6
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da5d0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DACDA
_081DACC6:
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DACD8
	adds r0, r4, #0
	bl _call_via_r1
_081DACD8:
	movs r0, #1
_081DACDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dace0
FUN_081dace0: @ 0x081DACE0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081da5ec
	adds r0, r4, #0
	bl FUN_081da370
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dacf8
FUN_081dacf8: @ 0x081DACF8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081DAD1E
	bl FUN_0823d340
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DAD1E
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAE0E
_081DAD1E:
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r4, #0
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081DAE18 @ =0x000002A2
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081d9f8c
	adds r0, r5, #0
	bl FUN_081da30c
	adds r0, r5, #0
	bl FUN_081da3a0
	adds r0, r5, #0
	bl FUN_081da468
	adds r0, r5, #0
	bl FUN_081da608
	ldr r3, _081DAE1C @ =0x0000029B
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r2, _081DAE20 @ =0x00000299
	adds r1, r5, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	ldr r1, _081DAE24 @ =FUN_081da930
	subs r2, #0x2d
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081DADB8
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DAE28 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081DADB8:
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _081DAE2C @ =0x03002C68
	ldr r0, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r0, r3
	cmp r0, #0
	bne _081DADCE
	movs r2, #0
_081DADCE:
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r1, [r0]
	ldr r3, _081DAE30 @ =0x00000286
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x41
	ldrb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r1, [r0]
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_081d9e50
	adds r0, r5, #0
	bl FUN_081da814
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da218
	movs r0, #1
_081DAE0E:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DAE18: .4byte 0x000002A2
_081DAE1C: .4byte 0x0000029B
_081DAE20: .4byte 0x00000299
_081DAE24: .4byte FUN_081da930
_081DAE28: .4byte 0x0000FFFF
_081DAE2C: .4byte 0x03002C68
_081DAE30: .4byte 0x00000286

	thumb_func_start FUN_081dae34
FUN_081dae34: @ 0x081DAE34
	push {r4, lr}
	movs r1, #0xa9
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DAE6C
	ldr r1, _081DAE64 @ =FUN_081daca4
	ldr r2, _081DAE68 @ =FUN_081dace0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081dacf8
	cmp r0, #0
	bge _081DAE6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DAE6E
	.align 2, 0
_081DAE64: .4byte FUN_081daca4
_081DAE68: .4byte FUN_081dace0
_081DAE6C:
	adds r0, r4, #0
_081DAE6E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dae74
FUN_081dae74: @ 0x081DAE74
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DAE90 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAE8A
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r1, r0, r3
	cmp r1, #0
	bne _081DAE94
_081DAE8A:
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAEAE
	.align 2, 0
_081DAE90: .4byte 0x03002C68
_081DAE94:
	ldr r3, _081DAEB4 @ =0x00000322
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #2]
	movs r0, #0
_081DAEAE:
	pop {r1}
	bx r1
	.align 2, 0
_081DAEB4: .4byte 0x00000322

	thumb_func_start FUN_081daeb8
FUN_081daeb8: @ 0x081DAEB8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DAF30 @ =0x0000C091
	ldr r1, _081DAF34 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DAF38 @ =0x000092B3
	ldr r1, _081DAF3C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DAF40 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	movs r5, #3
_081DAF0A:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DAF0A
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DAF30: .4byte 0x0000C091
_081DAF34: .4byte 0x0000CD91
_081DAF38: .4byte 0x000092B3
_081DAF3C: .4byte 0x000026BB
_081DAF40: .4byte 0x03004250

	thumb_func_start FUN_081daf44
FUN_081daf44: @ 0x081DAF44
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _081DAF94 @ =0x0000032D
	adds r0, r3, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DAF98 @ =0x00000323
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, _081DAF9C @ =0x00000326
	adds r1, r3, r0
	movs r0, #3
	strb r0, [r1]
	adds r2, #3
	adds r1, r3, r2
	movs r0, #4
	strb r0, [r1]
	movs r6, #0
	ldr r0, _081DAFA0 @ =0x03002C68
	ldr r0, [r0]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0
	beq _081DAF7C
	ldrh r5, [r0, #0x1a]
_081DAF7C:
	movs r1, #0
	cmp r6, r5
	bge _081DAFB6
	adds r2, r0, #0
	movs r4, #0xd2
	lsls r4, r4, #1
_081DAF88:
	cmp r2, #0
	beq _081DAF90
	cmp r1, #0
	bge _081DAFA4
_081DAF90:
	movs r0, #0
	b _081DAFA6
	.align 2, 0
_081DAF94: .4byte 0x0000032D
_081DAF98: .4byte 0x00000323
_081DAF9C: .4byte 0x00000326
_081DAFA0: .4byte 0x03002C68
_081DAFA4:
	adds r0, r2, r4
_081DAFA6:
	ldr r0, [r0, #0x18]
	cmp r0, #2
	bhi _081DAFAE
	movs r6, #1
_081DAFAE:
	adds r4, #0x48
	adds r1, #1
	cmp r1, r5
	blt _081DAF88
_081DAFB6:
	cmp r6, #0
	beq _081DAFD4
	ldr r1, _081DAFCC @ =0x00000325
	adds r0, r3, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _081DAFD0 @ =0x00000322
	adds r0, r3, r2
	strb r1, [r0]
	b _081DAFE2
	.align 2, 0
_081DAFCC: .4byte 0x00000325
_081DAFD0: .4byte 0x00000322
_081DAFD4:
	ldr r1, _081DAFE8 @ =0x00000325
	adds r0, r3, r1
	movs r1, #2
	strb r1, [r0]
	ldr r2, _081DAFEC @ =0x00000322
	adds r0, r3, r2
	strb r6, [r0]
_081DAFE2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DAFE8: .4byte 0x00000325
_081DAFEC: .4byte 0x00000322

	thumb_func_start FUN_081daff0
FUN_081daff0: @ 0x081DAFF0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DB008 @ =0x0000032D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB020
	cmp r0, #1
	bgt _081DB00C
	cmp r0, #0
	beq _081DB012
	b _081DB03C
	.align 2, 0
_081DB008: .4byte 0x0000032D
_081DB00C:
	cmp r0, #2
	beq _081DB030
	b _081DB03C
_081DB012:
	ldr r1, _081DB01C @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	b _081DB03E
	.align 2, 0
_081DB01C: .4byte 0x00000322
_081DB020:
	ldr r1, _081DB02C @ =0x00000323
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #2
	b _081DB03E
	.align 2, 0
_081DB02C: .4byte 0x00000323
_081DB030:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #5
	b _081DB03E
_081DB03C:
	movs r1, #0
_081DB03E:
	ldr r0, _081DB070 @ =0x0000032B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #9
	cmp r0, r4
	beq _081DB06A
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r4, [r6]
_081DB06A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB070: .4byte 0x0000032B

	thumb_func_start FUN_081db074
FUN_081db074: @ 0x081DB074
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x16
	movs r1, #4
	movs r2, #6
	movs r3, #2
	bl FUN_0804a084
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r5, r7, r1
	str r0, [r5]
	movs r0, #0x14
	movs r1, #0xc
	movs r2, #8
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r6, r7, r2
	str r0, [r6]
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_081daf44
	ldr r0, [r5]
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5]
	ldr r2, _081DB120 @ =0x00000322
	adds r4, r7, r2
	ldrb r1, [r4]
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
	ldrb r1, [r4]
	movs r2, #0xca
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, [r6]
	mov r2, r8
	ldr r1, [r2]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r4, r7, r1
	ldrb r1, [r4]
	adds r1, #5
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	ldrb r1, [r4]
	ldr r2, _081DB124 @ =0x0000032A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB120: .4byte 0x00000322
_081DB124: .4byte 0x0000032A

	thumb_func_start FUN_081db128
FUN_081db128: @ 0x081DB128
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db14c
FUN_081db14c: @ 0x081DB14C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DB17C @ =0x0000CB05
	ldr r1, _081DB180 @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #0x20
	adds r0, r4, r2
	bl OpenSpriteSetFile
	movs r5, #0
_081DB16E:
	cmp r5, #6
	bhi _081DB1B4
	lsls r0, r5, #2
	ldr r1, _081DB184 @ =_081DB188
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DB17C: .4byte 0x0000CB05
_081DB180: .4byte 0x0000DCC1
_081DB184: .4byte _081DB188
_081DB188: @ jump table
	.4byte _081DB1A4 @ case 0
	.4byte _081DB1A8 @ case 1
	.4byte _081DB1AC @ case 2
	.4byte _081DB1B4 @ case 3
	.4byte _081DB1B4 @ case 4
	.4byte _081DB1B4 @ case 5
	.4byte _081DB1B0 @ case 6
_081DB1A4:
	movs r2, #0x33
	b _081DB1B6
_081DB1A8:
	movs r2, #0x34
	b _081DB1B6
_081DB1AC:
	movs r2, #0x35
	b _081DB1B6
_081DB1B0:
	movs r2, #0x15
	b _081DB1B6
_081DB1B4:
	movs r2, #0
_081DB1B6:
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r3, r4, r0
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r4, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r5, #1
	cmp r5, #6
	ble _081DB16E
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db1e8
FUN_081db1e8: @ 0x081DB1E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _081DB220 @ =0x085AE1B4
	mov sl, r0
	ldr r1, _081DB224 @ =0x0000032D
	adds r3, r2, r1
	movs r7, #4
	add r7, sl
	mov sb, r7
	ldr r6, _081DB228 @ =0x085AE1CC
	adds r0, r6, #4
	mov r8, r0
	ldr r5, _081DB22C @ =0x085AE1E4
	adds r1, r5, #4
	mov ip, r1
_081DB210:
	cmp r4, #1
	beq _081DB252
	cmp r4, #1
	bgt _081DB230
	cmp r4, #0
	beq _081DB236
	b _081DB28C
	.align 2, 0
_081DB220: .4byte 0x085AE1B4
_081DB224: .4byte 0x0000032D
_081DB228: .4byte 0x085AE1CC
_081DB22C: .4byte 0x085AE1E4
_081DB230:
	cmp r4, #2
	beq _081DB26E
	b _081DB28C
_081DB236:
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sl
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sb
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0x42
	b _081DB28A
_081DB252:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0xa0
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0xa2
	b _081DB28A
_081DB26E:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0]
	adds r7, #2
	adds r1, r2, r7
_081DB28A:
	strh r0, [r1]
_081DB28C:
	adds r4, #1
	cmp r4, #6
	ble _081DB210
	adds r4, r2, #0
	adds r4, #0x88
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r3, r2, #0
	adds r3, #0xe8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r1, _081DB2E8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DB2CA
	ldr r7, _081DB2EC @ =0x00000325
	adds r0, r2, r7
	ldrb r1, [r0]
	cmp r1, #1
	bne _081DB2CA
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081DB2CA:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	ldr r3, _081DB2F0 @ =0x00000282
	adds r0, r2, r3
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB2E8: .4byte 0x0000032D
_081DB2EC: .4byte 0x00000325
_081DB2F0: .4byte 0x00000282

	thumb_func_start FUN_081db2f4
FUN_081db2f4: @ 0x081DB2F4
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #6
_081DB2FE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DB2FE
	pop {r0}
	bx r0

	thumb_func_start FUN_081db310
FUN_081db310: @ 0x081DB310
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #6
_081DB318:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DB318
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081db32c
FUN_081db32c: @ 0x081DB32C
	push {lr}
	mov ip, r0
	ldr r0, _081DB368 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _081DB36C @ =0x00005260
	adds r2, r0, r1
	movs r1, #0xb9
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0xf
_081DB340:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081DB340
	movs r0, #0xb9
	lsls r0, r0, #2
	add r0, ip
	mov r1, ip
	str r0, [r1, #0x68]
	movs r1, #0xc1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081DB368: .4byte 0x03003584
_081DB36C: .4byte 0x00005260

	thumb_func_start FUN_081db370
FUN_081db370: @ 0x081DB370
	push {lr}
	adds r3, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081DB39C
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081DB39C
	movs r2, #0x12
	cmp r0, #0x19
	bls _081DB39C
	movs r2, #0xa
	cmp r0, #0x21
	bls _081DB39C
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081DB39C
	movs r2, #0x12
_081DB39C:
	movs r0, #0xc1
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DB3B4
	movs r0, #0
	strh r0, [r1]
_081DB3B4:
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0

	thumb_func_start FUN_081db3c0
FUN_081db3c0: @ 0x081DB3C0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0x63
	ble _081DB410
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xcc
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc4
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x60
	adds r1, r5, r3
	movs r0, #0xbc
	strh r0, [r1]
	ldr r1, _081DB40C @ =0x00000222
	adds r0, r5, r1
	strh r2, [r0]
	subs r3, #0x18
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _081DB440
	.align 2, 0
_081DB40C: .4byte 0x00000222
_081DB410:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xc8
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc0
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x48
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
_081DB440:
	str r0, [r2]
	movs r2, #0
	cmp r4, #0x63
	ble _081DB450
_081DB448:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081DB448
_081DB450:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r4, #9
	ble _081DB472
_081DB46A:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081DB46A
_081DB472:
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r4, #0
	ble _081DB494
_081DB48C:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081DB48C
_081DB494:
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db4b0
FUN_081db4b0: @ 0x081DB4B0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r1, _081DB4C8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB504
	cmp r0, #1
	bgt _081DB4CC
	cmp r0, #0
	beq _081DB4D2
	b _081DB572
	.align 2, 0
_081DB4C8: .4byte 0x0000032D
_081DB4CC:
	cmp r0, #2
	beq _081DB538
	b _081DB572
_081DB4D2:
	ldr r3, _081DB500 @ =0x00000322
	adds r5, r2, r3
	ldrb r1, [r5]
	movs r0, #0xca
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x16
	adds r1, r2, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r5]
	b _081DB564
	.align 2, 0
_081DB500: .4byte 0x00000322
_081DB504:
	ldr r0, _081DB52C @ =0x00000323
	adds r5, r2, r0
	ldrb r3, [r5]
	ldr r1, _081DB530 @ =0x00000329
	adds r4, r2, r1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	beq _081DB572
	ldr r1, _081DB534 @ =0x085AE1FC
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	bl FUN_081db3c0
	ldrb r0, [r5]
	strb r0, [r4]
	b _081DB572
	.align 2, 0
_081DB52C: .4byte 0x00000323
_081DB530: .4byte 0x00000329
_081DB534: .4byte 0x085AE1FC
_081DB538:
	movs r3, #0xc9
	lsls r3, r3, #2
	adds r5, r2, r3
	ldrb r1, [r5]
	ldr r0, _081DB578 @ =0x0000032A
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x18
	adds r1, r2, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r5]
	adds r1, #5
_081DB564:
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldrb r0, [r5]
	strb r0, [r6]
_081DB572:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB578: .4byte 0x0000032A

	thumb_func_start FUN_081db57c
FUN_081db57c: @ 0x081DB57C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DB5D0
	bl FUN_08049f5c
	movs r2, #1
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #9
	bl Textbox_LookupString
	bl FUN_08049e30
	adds r0, r5, #0
	bl FUN_081db4b0
	ldr r2, _081DB5F0 @ =0x0000032D
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB5F4 @ =0x0000032E
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	strb r1, [r4]
_081DB5D0:
	ldr r2, _081DB5F4 @ =0x0000032E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DB5F8
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DB8D0
	.align 2, 0
_081DB5F0: .4byte 0x0000032D
_081DB5F4: .4byte 0x0000032E
_081DB5F8:
	ldr r1, _081DB614 @ =0x0000032D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _081DB618 @ =0x00000321
	adds r6, r5, r2
	movs r3, #0
	ldr r1, _081DB61C @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB620
	movs r3, #1
	b _081DB65A
	.align 2, 0
_081DB614: .4byte 0x0000032D
_081DB618: .4byte 0x00000321
_081DB61C: .4byte 0x030044E0
_081DB620:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB62C
	movs r3, #2
	b _081DB65A
_081DB62C:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DB638
	movs r3, #4
	b _081DB65A
_081DB638:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DB644
	movs r3, #8
	b _081DB65A
_081DB644:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DB650
	movs r3, #0x20
	b _081DB65A
_081DB650:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DB65A
	movs r3, #0x10
_081DB65A:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DB6A2
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DB6A0
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB676
	movs r0, #1
	b _081DB680
_081DB676:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB682
	movs r0, #2
_081DB680:
	orrs r3, r0
_081DB682:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DB690
	movs r0, #4
	b _081DB69A
_081DB690:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DB69C
	movs r0, #8
_081DB69A:
	orrs r3, r0
_081DB69C:
	movs r0, #0
	b _081DB6A2
_081DB6A0:
	adds r0, #1
_081DB6A2:
	strb r0, [r6]
	movs r1, #0
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _081DB6BA
	cmp r4, #0
	bne _081DB6B6
	movs r4, #2
	b _081DB83C
_081DB6B6:
	subs r4, #1
	b _081DB83C
_081DB6BA:
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _081DB6D8
	cmp r4, #2
	bne _081DB6CA
	movs r4, #0
	b _081DB6CC
_081DB6CA:
	adds r4, #1
_081DB6CC:
	ldr r2, _081DB6D4 @ =0x00000321
	adds r1, r5, r2
	b _081DB840
	.align 2, 0
_081DB6D4: .4byte 0x00000321
_081DB6D8:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DB77A
	ldr r2, _081DB6F4 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB730
	cmp r0, #1
	bgt _081DB6F8
	cmp r0, #0
	beq _081DB6FE
	b _081DB82C
	.align 2, 0
_081DB6F4: .4byte 0x0000032D
_081DB6F8:
	cmp r0, #2
	beq _081DB750
	b _081DB82C
_081DB6FE:
	ldr r0, _081DB71C @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	bne _081DB70A
	b _081DB82C
_081DB70A:
	ldr r1, _081DB720 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB724
	ldrb r0, [r2]
	subs r1, r0, #1
	b _081DB726
	.align 2, 0
_081DB71C: .4byte 0x00000325
_081DB720: .4byte 0x00000322
_081DB724:
	subs r1, #1
_081DB726:
	ldr r2, _081DB72C @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB72C: .4byte 0x00000322
_081DB730:
	ldr r1, _081DB744 @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB74C
	ldr r2, _081DB748 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB7F6
	.align 2, 0
_081DB744: .4byte 0x00000323
_081DB748: .4byte 0x00000326
_081DB74C:
	subs r1, #1
	b _081DB7F6
_081DB750:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB76C
	ldr r2, _081DB768 @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB76E
	.align 2, 0
_081DB768: .4byte 0x00000327
_081DB76C:
	subs r1, #1
_081DB76E:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
	b _081DB830
_081DB77A:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DB84C
	ldr r2, _081DB798 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB7D4
	cmp r0, #1
	bgt _081DB79C
	cmp r0, #0
	beq _081DB7A2
	b _081DB82C
	.align 2, 0
_081DB798: .4byte 0x0000032D
_081DB79C:
	cmp r0, #2
	beq _081DB804
	b _081DB82C
_081DB7A2:
	ldr r0, _081DB7C0 @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	beq _081DB82C
	ldr r1, _081DB7C4 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	bne _081DB7C8
	movs r1, #0
	b _081DB7CA
	.align 2, 0
_081DB7C0: .4byte 0x00000325
_081DB7C4: .4byte 0x00000322
_081DB7C8:
	adds r1, #1
_081DB7CA:
	ldr r2, _081DB7D0 @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB7D0: .4byte 0x00000322
_081DB7D4:
	ldr r1, _081DB7EC @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB7F0 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB7F4
	movs r1, #0
	b _081DB7F6
	.align 2, 0
_081DB7EC: .4byte 0x00000323
_081DB7F0: .4byte 0x00000326
_081DB7F4:
	adds r1, #1
_081DB7F6:
	ldr r2, _081DB800 @ =0x00000323
_081DB7F8:
	adds r0, r5, r2
	strb r1, [r0]
	b _081DB830
	.align 2, 0
_081DB800: .4byte 0x00000323
_081DB804:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB81C @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB820
	movs r1, #0
	b _081DB822
	.align 2, 0
_081DB81C: .4byte 0x00000327
_081DB820:
	adds r1, #1
_081DB822:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
_081DB82C:
	cmp r1, #0
	beq _081DB83C
_081DB830:
	adds r0, r5, #0
	bl FUN_081db4b0
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB83C:
	ldr r0, _081DB848 @ =0x00000321
	adds r1, r5, r0
_081DB840:
	movs r0, #0
	strb r0, [r1]
	b _081DB8AC
	.align 2, 0
_081DB848: .4byte 0x00000321
_081DB84C:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DB87E
	adds r0, r5, #0
	bl FUN_081dae74
	movs r0, #1
	bl FUN_081df95c
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08049fa8
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r5, #0
	bl FUN_081db2f4
	b _081DB8A4
_081DB87E:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DB8AC
	movs r0, #2
	bl FUN_081df95c
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r5, #0
	bl FUN_081db2f4
	movs r0, #0xde
	bl PlaySound_082406e0
_081DB8A4:
	adds r0, r5, #0
	bl KillEntity
	b _081DB8D0
_081DB8AC:
	ldr r2, _081DB8D8 @ =0x0000032D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DB8C4
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081db1e8
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB8C4:
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
_081DB8D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB8D8: .4byte 0x0000032D

	thumb_func_start FUN_081db8dc
FUN_081db8dc: @ 0x081DB8DC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DB8FE
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081db2f4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DB912
_081DB8FE:
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DB910
	adds r0, r4, #0
	bl _call_via_r1
_081DB910:
	movs r0, #1
_081DB912:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081db918
FUN_081db918: @ 0x081DB918
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081db310
	adds r0, r4, #0
	bl FUN_081db128
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081db930
FUN_081db930: @ 0x081DB930
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081DB954
	bl FUN_0823d340
	movs r2, #0xc3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DB954
	movs r0, #1
	rsbs r0, r0, #0
	b _081DB9A4
_081DB954:
	movs r0, #0
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081daeb8
	adds r0, r4, #0
	bl FUN_081db074
	adds r0, r4, #0
	bl FUN_081db14c
	adds r0, r4, #0
	bl FUN_081db1e8
	adds r0, r4, #0
	bl FUN_081db32c
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_081db3c0
	ldr r3, _081DB9AC @ =0x00000329
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB9B0 @ =FUN_081db57c
	subs r3, #0x21
	adds r0, r4, r3
	str r1, [r0]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #1
_081DB9A4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DB9AC: .4byte 0x00000329
_081DB9B0: .4byte FUN_081db57c

	thumb_func_start FUN_081db9b4
FUN_081db9b4: @ 0x081DB9B4
	push {r4, lr}
	movs r1, #0xcc
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DB9EC
	ldr r1, _081DB9E4 @ =FUN_081db8dc
	ldr r2, _081DB9E8 @ =FUN_081db918
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081db930
	cmp r0, #0
	bge _081DB9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DB9EE
	.align 2, 0
_081DB9E4: .4byte FUN_081db8dc
_081DB9E8: .4byte FUN_081db918
_081DB9EC:
	adds r0, r4, #0
_081DB9EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081db9f4
FUN_081db9f4: @ 0x081DB9F4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DBA40 @ =0x0000C091
	ldr r1, _081DBA44 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #7
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r0, _081DBA48 @ =0x000092B3
	ldr r1, _081DBA4C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x1c]
	ldr r1, _081DBA50 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBA40: .4byte 0x0000C091
_081DBA44: .4byte 0x0000CD91
_081DBA48: .4byte 0x000092B3
_081DBA4C: .4byte 0x000026BB
_081DBA50: .4byte 0x03004250

	thumb_func_start FUN_081dba54
FUN_081dba54: @ 0x081DBA54
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	adds r0, #0x40
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0x10
	bl CpuSet
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dba78
FUN_081dba78: @ 0x081DBA78
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DBAC0
	ldr r3, _081DBAB4 @ =0x0000039A
	adds r0, r2, r3
	ldr r1, _081DBAB8 @ =0x00006739
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, _081DBABC @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	b _081DBC08
	.align 2, 0
_081DBAB4: .4byte 0x0000039A
_081DBAB8: .4byte 0x00006739
_081DBABC: .4byte 0x03004290
_081DBAC0:
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	movs r3, #0x1f
	cmp r0, #9
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x11
	bls _081DBAE8
	movs r3, #0x12
	cmp r0, #0x19
	bls _081DBAE8
	movs r3, #0xa
	cmp r0, #0x21
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x29
	bhi _081DBAE8
	movs r3, #0x12
_081DBAE8:
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DBB02
	movs r0, #0
	strh r0, [r1]
_081DBB02:
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB20
	ldr r0, _081DBB18 @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB1C @ =0x00006739
	b _081DBB26
	.align 2, 0
_081DBB18: .4byte 0x0000039A
_081DBB1C: .4byte 0x00006739
_081DBB20:
	ldr r0, _081DBB3C @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB40 @ =0x000035B4
_081DBB26:
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB4C
	ldr r0, _081DBB44 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB48 @ =0x00006739
	b _081DBB52
	.align 2, 0
_081DBB3C: .4byte 0x0000039A
_081DBB40: .4byte 0x000035B4
_081DBB44: .4byte 0x0000039E
_081DBB48: .4byte 0x00006739
_081DBB4C:
	ldr r0, _081DBB68 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB6C @ =0x000035B4
_081DBB52:
	strh r0, [r1]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB78
	ldr r0, _081DBB70 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB74 @ =0x00006739
	b _081DBB7E
	.align 2, 0
_081DBB68: .4byte 0x0000039E
_081DBB6C: .4byte 0x000035B4
_081DBB70: .4byte 0x000003A2
_081DBB74: .4byte 0x00006739
_081DBB78:
	ldr r0, _081DBB94 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB98 @ =0x000035B4
_081DBB7E:
	strh r0, [r1]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBBA4
	ldr r0, _081DBB9C @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBA0 @ =0x00006739
	b _081DBBAA
	.align 2, 0
_081DBB94: .4byte 0x000003A2
_081DBB98: .4byte 0x000035B4
_081DBB9C: .4byte 0x000003A6
_081DBBA0: .4byte 0x00006739
_081DBBA4:
	ldr r0, _081DBBC4 @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBC8 @ =0x000035B4
_081DBBAA:
	strh r0, [r1]
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _081DBBDC
	cmp r0, #1
	bgt _081DBBCC
	cmp r0, #0
	beq _081DBBD6
	b _081DBBFA
	.align 2, 0
_081DBBC4: .4byte 0x000003A6
_081DBBC8: .4byte 0x000035B4
_081DBBCC:
	cmp r0, #2
	beq _081DBBE2
	cmp r0, #3
	beq _081DBBE8
	b _081DBBFA
_081DBBD6:
	movs r1, #0xeb
	lsls r1, r1, #2
	b _081DBBEC
_081DBBDC:
	movs r1, #0xec
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE2:
	movs r1, #0xed
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE8:
	movs r1, #0xee
	lsls r1, r1, #2
_081DBBEC:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DBBFA
	subs r1, #0x12
	adds r0, r2, r1
	strh r3, [r0]
_081DBBFA:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r1, _081DBC10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
_081DBC08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBC10: .4byte 0x03004290

	thumb_func_start FUN_081dbc14
FUN_081dbc14: @ 0x081DBC14
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
	strh r2, [r1]
	ldr r3, _081DBC58 @ =0x00000362
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3a
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x3b
	strh r1, [r2]
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3c
	strh r1, [r2]
	ldr r2, _081DBC5C @ =0x0000036E
	adds r0, r0, r2
	movs r1, #0x3d
	strh r1, [r0]
	bx lr
	.align 2, 0
_081DBC58: .4byte 0x00000362
_081DBC5C: .4byte 0x0000036E

	thumb_func_start FUN_081dbc60
FUN_081dbc60: @ 0x081DBC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBCD8 @ =0x0000CB05
	ldr r1, _081DBCDC @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xc8
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenSpriteSetFile
	movs r0, #4
	mov r8, r0
	movs r7, #0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r6, r5, r1
_081DBC92:
	mov r2, r8
	lsls r4, r2, #1
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r5, r3
	adds r0, r0, r4
	ldrh r2, [r0]
	str r7, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r6, #0
	subs r3, #0x40
	adds r1, r5, r3
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r4
	ldr r1, _081DBCE0 @ =0x0000FFFF
	strh r1, [r0]
	adds r6, #0x60
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #7
	ble _081DBC92
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBCD8: .4byte 0x0000CB05
_081DBCDC: .4byte 0x0000DCC1
_081DBCE0: .4byte 0x0000FFFF

	thumb_func_start FUN_081dbce4
FUN_081dbce4: @ 0x081DBCE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r1, r0, #0
	movs r2, #0
	adds r4, r1, #0
	adds r4, #0x40
	movs r0, #0x1d
	mov r8, r0
	movs r7, #0x40
	mov ip, r7
	movs r0, #0xd3
	mov sb, r0
	movs r6, #0x70
	adds r3, r4, #0
	movs r5, #0
_081DBD06:
	cmp r2, #1
	beq _081DBD28
	cmp r2, #1
	bgt _081DBD14
	cmp r2, #0
	beq _081DBD1E
	b _081DBD5C
_081DBD14:
	cmp r2, #2
	beq _081DBD38
	cmp r2, #3
	beq _081DBD48
	b _081DBD5C
_081DBD1E:
	mov r7, r8
	strh r7, [r4]
	adds r0, r1, #0
	adds r0, #0x42
	b _081DBD32
_081DBD28:
	adds r0, r1, #0
	adds r0, #0xa0
	mov r7, sb
	strh r7, [r0]
	adds r0, #2
_081DBD32:
	mov r7, ip
	strh r7, [r0]
	b _081DBD60
_081DBD38:
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, r8
	strh r7, [r0]
	movs r7, #0x81
	lsls r7, r7, #1
	b _081DBD56
_081DBD48:
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, sb
	strh r7, [r0]
	movs r7, #0xb1
	lsls r7, r7, #1
_081DBD56:
	adds r0, r1, r7
	strh r6, [r0]
	b _081DBD60
_081DBD5C:
	strh r5, [r3]
	strh r5, [r3, #2]
_081DBD60:
	adds r3, #0x60
	adds r2, #1
	cmp r2, #7
	ble _081DBD06
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbd74
FUN_081dbd74: @ 0x081DBD74
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBDE8 @ =0x0000CB05
	ldr r1, _081DBDEC @ =0x0000DE23
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenSpriteSetFile
	movs r4, #0
	mov sb, r4
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x20
	movs r0, #0
	mov r8, r0
_081DBDAA:
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r3, r8
	str r3, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldr r1, _081DBDF0 @ =0x0000FFFF
	strh r1, [r0]
	cmp r4, #1
	beq _081DBE02
	cmp r4, #1
	bgt _081DBDF4
	cmp r4, #0
	beq _081DBDFE
	b _081DBE0E
	.align 2, 0
_081DBDE8: .4byte 0x0000CB05
_081DBDEC: .4byte 0x0000DE23
_081DBDF0: .4byte 0x0000FFFF
_081DBDF4:
	cmp r4, #2
	beq _081DBE06
	cmp r4, #3
	beq _081DBE0A
	b _081DBE0E
_081DBDFE:
	movs r3, #0x22
	b _081DBE10
_081DBE02:
	movs r3, #0x23
	b _081DBE10
_081DBE06:
	movs r3, #0x24
	b _081DBE10
_081DBE0A:
	movs r3, #0x25
	b _081DBE10
_081DBE0E:
	movs r3, #0
_081DBE10:
	adds r1, r5, #0
	adds r1, #0x68
	add r1, sb
	ldr r0, _081DBE40 @ =0x03003584
	lsls r2, r3, #5
	ldr r0, [r0]
	adds r0, r0, r2
	str r0, [r1]
	strh r3, [r6, #0x3a]
	movs r2, #0x60
	add sb, r2
	adds r7, #2
	adds r6, #0x60
	adds r4, #1
	cmp r4, #3
	ble _081DBDAA
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBE40: .4byte 0x03003584

	thumb_func_start FUN_081dbe44
FUN_081dbe44: @ 0x081DBE44
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_082372cc
	adds r2, r0, #0
	ldrb r1, [r4, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081DBE5C
	cmp r2, #0
	beq _081DBE60
_081DBE5C:
	movs r0, #1
	b _081DBE62
_081DBE60:
	movs r0, #0
_081DBE62:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dbe68
FUN_081dbe68: @ 0x081DBE68
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #7
_081DBE72:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DBE72
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbe84
FUN_081dbe84: @ 0x081DBE84
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #7
_081DBE8C:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DBE8C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbea0
FUN_081dbea0: @ 0x081DBEA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r1, r6, r1
	str r1, [sp, #4]
	adds r2, r6, #0
	adds r2, #0x20
	str r2, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r1, #0x28
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0
	str r2, [sp, #0x14]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r7, r6, r3
	movs r0, #0xda
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x18]
_081DBEE2:
	ldr r0, _081DBF24 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _081DBF04
	mov r1, sb
	cmp r1, #0
	blt _081DBF04
	mov r3, sb
	lsls r0, r3, #3
	add r0, sb
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r3, r2, r0
	cmp r3, #0
	bne _081DBF28
_081DBF04:
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r1, r8
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, r8
	b _081DC01C
	.align 2, 0
_081DBF24: .4byte 0x03002C68
_081DBF28:
	mov r1, sb
	lsls r0, r1, #2
	adds r0, r6, r0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _081DC000
	ldrb r0, [r2, #0x1c]
	cmp r0, #5
	bgt _081DBF5C
	mov r2, r8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	ldr r0, [r7]
	subs r1, #3
	ands r0, r1
	str r0, [r7]
	b _081DC01E
_081DBF5C:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
	mov r1, sb
	cmp r1, #1
	bgt _081DBFC0
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFA6
	cmp r0, #1
	bgt _081DBF94
	cmp r0, #0
	beq _081DBF9A
	b _081DC050
_081DBF94:
	cmp r0, #2
	beq _081DBFB2
	b _081DC050
_081DBF9A:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	b _081DC050
_081DBFA6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcf
	strh r0, [r1]
	b _081DC050
_081DBFB2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd3
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DBFC0:
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFE6
	cmp r0, #1
	bgt _081DBFD4
	cmp r0, #0
	beq _081DBFDA
	b _081DC050
_081DBFD4:
	cmp r0, #2
	beq _081DBFF2
	b _081DC050
_081DBFDA:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #6
	strh r0, [r1]
	b _081DC050
_081DBFE6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcd
	strh r0, [r1]
	b _081DC050
_081DBFF2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd2
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DC000:
	cmp r1, #1
	bne _081DC02A
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
_081DC01C:
	str r0, [r2]
_081DC01E:
	mov r2, sb
	adds r2, #4
	movs r3, #0x28
	adds r3, r3, r6
	mov sl, r3
	b _081DC050
_081DC02A:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
_081DC050:
	lsls r0, r2, #1
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r5, r6, r3
	adds r0, r5, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	beq _081DC076
	ldr r0, [sp, #0xc]
	subs r3, #0x50
	adds r1, r6, r3
	bl Sprite_LoadSprite
_081DC076:
	ldr r0, [sp, #0x14]
	adds r4, r4, r0
	ldrh r1, [r4]
	adds r5, r5, r0
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r1, r0
	beq _081DC0AE
	ldr r2, [sp, #0x10]
	add r2, sl
	ldr r0, _081DC0FC @ =0x085AE204
	add r0, sb
	ldrb r1, [r0]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldrh r2, [r4]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r3, #1
	bl FUN_082370cc
	ldrh r0, [r4]
	strh r0, [r5]
_081DC0AE:
	ldr r0, [sp, #8]
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r1, r6, r2
	bl FUN_082372cc
	ldr r3, [sp, #8]
	adds r3, #0x60
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	adds r0, #0x60
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, #0x60
	str r1, [sp, #0x10]
	movs r2, #0x60
	add r8, r2
	ldr r3, [sp, #0x14]
	adds r3, #2
	str r3, [sp, #0x14]
	adds r7, #0x60
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	bgt _081DC0EA
	b _081DBEE2
_081DC0EA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC0FC: .4byte 0x085AE204

	thumb_func_start FUN_081dc100
FUN_081dc100: @ 0x081DC100
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DC144
	ldr r0, _081DC140 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _081DC11E
	b _081DC2D4
_081DC11E:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #2
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC140: .4byte 0x000003D1
_081DC144:
	bl FUN_081dfa04
	adds r2, r0, #0
	subs r0, r2, #5
	cmp r0, #1
	bhi _081DC184
	ldr r0, _081DC180 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #4
	bne _081DC15E
	b _081DC2D4
_081DC15E:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #4
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #4
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC180: .4byte 0x000003D1
_081DC184:
	ldr r0, _081DC198 @ =0x03002C68
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _081DC19C
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	beq _081DC19C
	movs r0, #1
	b _081DC19E
	.align 2, 0
_081DC198: .4byte 0x03002C68
_081DC19C:
	movs r0, #0
_081DC19E:
	cmp r0, #0
	beq _081DC1D8
	cmp r2, #8
	bne _081DC1D8
	ldr r0, _081DC1D4 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _081DC1B4
	b _081DC2D4
_081DC1B4:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #6
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #6
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC1D4: .4byte 0x000003D1
_081DC1D8:
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC1EA
	movs r6, #0
	b _081DC1F0
_081DC1EA:
	adds r0, #0x68
	adds r0, r0, r1
	ldrb r6, [r0]
_081DC1F0:
	cmp r6, #2
	beq _081DC234
	cmp r6, #2
	ble _081DC1FE
	cmp r6, #3
	beq _081DC264
	b _081DC2D4
_081DC1FE:
	cmp r6, #0
	blt _081DC2D4
	ldr r0, _081DC230 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	beq _081DC2D4
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #1
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #1
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC230: .4byte 0x000003D1
_081DC234:
	ldr r0, _081DC260 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	beq _081DC2D4
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r6, [r5]
	b _081DC2D4
	.align 2, 0
_081DC260: .4byte 0x000003D1
_081DC264:
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r5, r4, r0
	adds r0, #6
	adds r1, r4, r0
	ldr r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081DC2A4
	bl FUN_08049e5c
	ldr r1, [r5]
	movs r0, #0
	bl FUN_08049e6c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r1, _081DC2A0 @ =0x000003D1
	adds r0, r4, r1
	strb r6, [r0]
	b _081DC2D4
	.align 2, 0
_081DC2A0: .4byte 0x000003D1
_081DC2A4:
	ldr r0, _081DC2DC @ =0x000003D1
	adds r7, r4, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #3
	beq _081DC2D4
	bl FUN_08049e5c
	ldr r1, [r5]
	movs r0, #0
	bl FUN_08049e6c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r6, [r7]
_081DC2D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC2DC: .4byte 0x000003D1

	thumb_func_start FUN_081dc2e0
FUN_081dc2e0: @ 0x081DC2E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08049e5c
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081dbe68
	movs r0, #2
	bl FUN_081df95c
	ldr r0, _081DC328 @ =0x000003DA
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC322
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081DC322:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC328: .4byte 0x000003DA

	thumb_func_start FUN_081dc32c
FUN_081dc32c: @ 0x081DC32C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC348
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081DC348:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dc350
FUN_081dc350: @ 0x081DC350
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DC36C
	ldr r1, _081DC388 @ =0x000003D6
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DC36C:
	ldr r0, _081DC388 @ =0x000003D6
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DC37C
	adds r0, r3, #0
	bl FUN_081dc2e0
_081DC37C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC388: .4byte 0x000003D6

	thumb_func_start FUN_081dc38c
FUN_081dc38c: @ 0x081DC38C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DC3F2
	ldr r2, _081DC42C @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, [r5, #0x18]
	movs r0, #3
	movs r2, #7
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r4, #0
	movs r6, #3
_081DC3C4:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC3C4
	ldr r3, _081DC430 @ =0x000003D6
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0xf5
	lsls r4, r4, #2
	adds r0, r5, r4
	strb r2, [r0]
_081DC3F2:
	bl FUN_0823812c
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r3, _081DC434 @ =0x03002C68
	ldr r0, [r3]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #0
	beq _081DC40C
	ldrh r2, [r0, #0x1a]
_081DC40C:
	movs r4, #0xf3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r2, [r0]
	movs r4, #0
	adds r2, r1, #0
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
_081DC420:
	ldr r0, [r2]
	cmp r0, #0
	bge _081DC438
	strb r6, [r1]
	b _081DC44A
	.align 2, 0
_081DC42C: .4byte 0x000003D1
_081DC430: .4byte 0x000003D6
_081DC434: .4byte 0x03002C68
_081DC438:
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC442
	movs r0, #0
	b _081DC448
_081DC442:
	adds r0, #0x68
	adds r0, r0, r4
	ldrb r0, [r0]
_081DC448:
	strb r0, [r1]
_081DC44A:
	adds r1, #4
	adds r4, #1
	cmp r4, #3
	ble _081DC420
	adds r0, r5, #0
	bl FUN_081dbea0
	adds r0, r5, #0
	bl FUN_081dba78
	adds r0, r5, #0
	bl FUN_081dc100
	movs r1, #0xf3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _081DC484 @ =0x000003D2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081DC488 @ =0x000003D6
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081DC48C
	adds r0, #1
	strh r0, [r1]
	b _081DC524
	.align 2, 0
_081DC484: .4byte 0x000003D2
_081DC488: .4byte 0x000003D6
_081DC48C:
	ldr r0, _081DC4A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DC4A4
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DC4A4
	movs r0, #1
	b _081DC4A6
	.align 2, 0
_081DC4A0: .4byte 0x03002C68
_081DC4A4:
	movs r0, #0
_081DC4A6:
	cmp r0, #0
	bne _081DC506
	ldr r0, _081DC4DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DC4E4
	ldr r1, _081DC4E0 @ =FUN_081dc350
	movs r2, #1
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DC524
	.align 2, 0
_081DC4DC: .4byte 0x030044E0
_081DC4E0: .4byte FUN_081dc350
_081DC4E4:
	movs r4, #0
	movs r5, #3
_081DC4E8:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC4E8
	b _081DC524
_081DC506:
	movs r4, #0
	movs r6, #1
	movs r5, #3
_081DC50C:
	adds r0, r4, #0
	adds r0, #0x19
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC50C
_081DC524:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dc52c
FUN_081dc52c: @ 0x081DC52C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DC548
	bl FUN_08049fa8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC55C
_081DC548:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DC55A
	adds r0, r4, #0
	bl _call_via_r1
_081DC55A:
	movs r0, #1
_081DC55C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dc564
FUN_081dc564: @ 0x081DC564
	push {lr}
	bl FUN_081dbe84
	ldr r1, _081DC578 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081DC578: .4byte 0x030001A8

	thumb_func_start FUN_081dc57c
FUN_081dc57c: @ 0x081DC57C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081DC5A2
	bl FUN_0823d340
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DC5A2
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC622
_081DC5A2:
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081DC62C @ =0x000003DA
	adds r1, r5, r2
	movs r4, #0
	strh r0, [r1]
	movs r0, #0
	bl FUN_0822b644
	adds r0, r5, #0
	bl FUN_081db9f4
	adds r0, r5, #0
	bl FUN_081dbc14
	adds r0, r5, #0
	bl FUN_081dbc60
	adds r0, r5, #0
	bl FUN_081dbd74
	adds r0, r5, #0
	bl FUN_081dbce4
	adds r0, r5, #0
	bl FUN_081dba54
	ldr r1, _081DC630 @ =FUN_081dc38c
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081DC61C
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DC634 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081DC61C:
	ldr r0, _081DC638 @ =0x030001A8
	str r5, [r0]
	movs r0, #1
_081DC622:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DC62C: .4byte 0x000003DA
_081DC630: .4byte FUN_081dc38c
_081DC634: .4byte 0x0000FFFF
_081DC638: .4byte 0x030001A8

	thumb_func_start FUN_081dc63c
FUN_081dc63c: @ 0x081DC63C
	push {r4, lr}
	ldr r0, _081DC674 @ =0x030001A8
	ldr r0, [r0]
	cmp r0, #0
	bne _081DC682
	movs r1, #0xf7
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DC680
	ldr r1, _081DC678 @ =FUN_081dc52c
	ldr r2, _081DC67C @ =FUN_081dc564
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081dc57c
	cmp r0, #0
	bge _081DC680
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DC682
	.align 2, 0
_081DC674: .4byte 0x030001A8
_081DC678: .4byte FUN_081dc52c
_081DC67C: .4byte FUN_081dc564
_081DC680:
	adds r0, r4, #0
_081DC682:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dc688
FUN_081dc688: @ 0x081DC688
	ldr r1, _081DC690 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081DC690: .4byte 0x030001A8

	thumb_func_start FUN_081dc694
FUN_081dc694: @ 0x081DC694
	push {r4, lr}
	ldr r4, _081DC6CC @ =0x030001A8
	ldr r0, [r4]
	cmp r0, #0
	beq _081DC6C4
	bl FUN_081dbe68
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	bl FUN_08049e5c
	ldr r0, [r4]
	bl KillEntity
_081DC6C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC6CC: .4byte 0x030001A8

	thumb_func_start FUN_081dc6d0
FUN_081dc6d0: @ 0x081DC6D0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081DC768 @ =0x0000C091
	ldr r1, _081DC76C @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	ldr r1, _081DC770 @ =0x0000082C
	adds r5, r6, r1
	str r0, [r5]
	ldr r1, _081DC774 @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	movs r1, #0x83
	lsls r1, r1, #4
	adds r1, r1, r6
	mov r8, r1
	str r0, [r1]
	movs r0, #9
	str r0, [sp, #0xc]
	ldr r2, [r5]
	movs r4, #0
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #3
	str r0, [sp, #0xc]
	mov r1, r8
	ldr r2, [r1]
	str r4, [sp]
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DC778 @ =0x000092B3
	ldr r1, _081DC77C @ =0x000026BB
	bl GetFile
	ldr r1, _081DC780 @ =0x00000834
	adds r6, r6, r1
	adds r0, #0x14
	str r0, [r6]
	ldr r1, _081DC784 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC768: .4byte 0x0000C091
_081DC76C: .4byte 0x0000CD91
_081DC770: .4byte 0x0000082C
_081DC774: .4byte 0x0000A413
_081DC778: .4byte 0x000092B3
_081DC77C: .4byte 0x000026BB
_081DC780: .4byte 0x00000834
_081DC784: .4byte 0x03004250

	thumb_func_start FUN_081dc788
FUN_081dc788: @ 0x081DC788
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xc
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081DC808 @ =0x00000844
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #8
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081DC80C @ =0x00000848
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #0xc
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081DC810 @ =0x0000084C
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #0x10
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0x85
	lsls r2, r2, #4
	adds r1, r6, r2
	str r0, [r1]
	movs r5, #0
_081DC7D8:
	lsls r0, r5, #2
	ldr r1, _081DC808 @ =0x00000844
	adds r4, r6, r1
	adds r4, r4, r0
	ldr r0, [r4]
	ldr r2, _081DC814 @ =0x0000083C
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a210
	adds r5, #1
	cmp r5, #3
	ble _081DC7D8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC808: .4byte 0x00000844
_081DC80C: .4byte 0x00000848
_081DC810: .4byte 0x0000084C
_081DC814: .4byte 0x0000083C

	thumb_func_start FUN_081dc818
FUN_081dc818: @ 0x081DC818
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r1, _081DC874 @ =0x000006FC
	adds r0, r3, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	ldr r0, _081DC878 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _081DC86C
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r6, r2, r0
	cmp r6, #0
	beq _081DC86C
	lsls r0, r5, #2
	ldr r2, _081DC87C @ =0x00000844
	adds r4, r3, r2
	adds r4, r4, r0
	ldr r0, [r4]
	subs r2, #8
	adds r1, r3, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	bl FUN_0804a1f0
_081DC86C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC874: .4byte 0x000006FC
_081DC878: .4byte 0x03002C68
_081DC87C: .4byte 0x00000844

	thumb_func_start FUN_081dc880
FUN_081dc880: @ 0x081DC880
	push {r4, r5, lr}
	ldr r1, _081DC89C @ =0x00000844
	adds r5, r0, r1
	movs r4, #3
_081DC888:
	ldm r5!, {r0}
	bl FUN_0804a210
	subs r4, #1
	cmp r4, #0
	bge _081DC888
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DC89C: .4byte 0x00000844

	thumb_func_start FUN_081dc8a0
FUN_081dc8a0: @ 0x081DC8A0
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _081DC8BC @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_081DC8BC: .4byte 0x03003ED0

	thumb_func_start FUN_081dc8c0
FUN_081dc8c0: @ 0x081DC8C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov sl, r1
	movs r7, #0
	movs r5, #0
	mov r0, sl
	lsls r0, r0, #2
	str r0, [sp, #8]
	ldr r1, [sp]
	ldr r2, _081DC984 @ =0x000006FC
	adds r0, r1, r2
	add r0, sl
	mov sb, r0
	mov r0, sl
	lsls r0, r0, #5
	mov r8, r0
_081DC8EA:
	ldr r4, _081DC988 @ =0x085AE248
	add r4, r8
	movs r6, #6
_081DC8F0:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	lsls r1, r7, #1
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, _081DC98C @ =0x085AE208
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC8F0
	movs r0, #0x10
	add r8, r0
	adds r5, #1
	cmp r5, #1
	ble _081DC8EA
	movs r7, #0
	movs r5, #0
	ldr r0, [sp, #8]
	add r0, sl
	lsls r0, r0, #3
	str r0, [sp, #4]
	ldr r1, [sp]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r1, r2
	add r0, sl
	mov r8, r0
_081DC942:
	adds r0, r5, #1
	mov sb, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldr r2, _081DC990 @ =0x085AE32C
	adds r4, r0, r2
	movs r6, #8
_081DC956:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _081DC998
	lsls r2, r7, #1
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _081DC994 @ =0x085AE2C8
	adds r2, r2, r0
	ldrh r0, [r2]
	movs r2, #0xc0
	lsls r2, r2, #6
	b _081DC9B0
	.align 2, 0
_081DC984: .4byte 0x000006FC
_081DC988: .4byte 0x085AE248
_081DC98C: .4byte 0x085AE208
_081DC990: .4byte 0x085AE32C
_081DC994: .4byte 0x085AE2C8
_081DC998:
	lsls r2, r7, #1
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, _081DC9D8 @ =0x085AE2C8
	adds r2, r2, r1
	ldrh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
_081DC9B0:
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC956
	mov r5, sb
	cmp r5, #1
	ble _081DC942
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC9D8: .4byte 0x085AE2C8

	thumb_func_start FUN_081dc9dc
FUN_081dc9dc: @ 0x081DC9DC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081DCA94 @ =0x0000CB05
	ldr r1, _081DCA98 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenSpriteSetFile
	ldr r1, _081DCA9C @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081DCAA0 @ =0x000006BC
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenSpriteSetFile
	movs r7, #0
	movs r4, #0
	adds r5, r6, #0
	adds r5, #0x18
_081DCA22:
	lsls r0, r7, #1
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r1, r1, r0
	strh r4, [r1]
	ldrh r2, [r1]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r2, r0, #0
	cmp r2, #0
	bne _081DCA8C
	adds r5, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _081DCA22
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #4
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r1, r6, r3
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0x10
	bl FUN_0822f3fc
	cmp r0, #0
	bne _081DCA8C
	movs r1, #0xc4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081DCA8C:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCA94: .4byte 0x0000CB05
_081DCA98: .4byte 0x0000DCC1
_081DCA9C: .4byte 0x0000B343
_081DCAA0: .4byte 0x000006BC

	thumb_func_start FUN_081dcaa4
FUN_081dcaa4: @ 0x081DCAA4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r3, r7, r1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r5, #0xd8
	adds r1, r7, #0
	movs r6, #3
_081DCAC0:
	strh r5, [r1, #0x38]
	strh r5, [r2, #0x38]
	strh r5, [r3, #0x38]
	strh r5, [r4]
	movs r0, #0x20
	strh r0, [r1, #0x3a]
	movs r0, #0x40
	strh r0, [r2, #0x3a]
	movs r0, #0x60
	strh r0, [r3, #0x3a]
	movs r0, #0x80
	strh r0, [r4, #2]
	adds r4, #0x60
	adds r3, #0x60
	adds r2, #0x60
	subs r5, #8
	adds r1, #0x60
	subs r6, #1
	cmp r6, #0
	bge _081DCAC0
	ldr r1, _081DCB44 @ =0x00000859
	adds r0, r7, r1
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #3
	bgt _081DCB2C
	movs r3, #1
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #7
	adds r1, r0, #0
	adds r1, #0xe0
	adds r1, r1, r7
	adds r0, #0x20
	adds r2, r0, r7
	movs r4, #0xc0
	lsls r4, r4, #1
_081DCB0A:
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, [r2, #0x60]
	orrs r0, r3
	str r0, [r2, #0x60]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r0, [r1, #0x60]
	orrs r0, r3
	str r0, [r1, #0x60]
	adds r1, r1, r4
	adds r2, r2, r4
	adds r6, #1
	cmp r6, #3
	ble _081DCB0A
_081DCB2C:
	movs r0, #0xc7
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081DCB48 @ =0x0000FFF8
	strh r0, [r1]
	ldr r0, _081DCB4C @ =0x0000063A
	adds r1, r7, r0
	ldr r0, _081DCB50 @ =0x0000FFC8
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCB44: .4byte 0x00000859
_081DCB48: .4byte 0x0000FFF8
_081DCB4C: .4byte 0x0000063A
_081DCB50: .4byte 0x0000FFC8

	thumb_func_start FUN_081dcb54
FUN_081dcb54: @ 0x081DCB54
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x20
	movs r2, #0x10
_081DCB5E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DCB5E
	pop {r0}
	bx r0

	thumb_func_start FUN_081dcb70
FUN_081dcb70: @ 0x081DCB70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #0x10
_081DCB78:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DCB78
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dcb8c
FUN_081dcb8c: @ 0x081DCB8C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r2, r1, #1
	ldr r3, _081DCC3C @ =0x000006E4
	adds r0, r6, r3
	adds r0, r0, r2
	ldrh r5, [r0]
	lsls r7, r1, #2
	movs r2, #0
	ldr r0, _081DCC40 @ =0x000003E7
	cmp r5, r0
	ble _081DCBAE
	ldr r1, _081DCC44 @ =0xFFFFFC18
_081DCBA6:
	adds r2, #1
	adds r5, r5, r1
	cmp r5, r0
	bgt _081DCBA6
_081DCBAE:
	lsls r4, r7, #1
	adds r0, r4, r7
	lsls r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r5, #0x63
	ble _081DCBD8
_081DCBD0:
	adds r2, #1
	subs r5, #0x64
	cmp r5, #0x63
	bgt _081DCBD0
_081DCBD8:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0xd8
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r5, #9
	ble _081DCBFC
_081DCBF4:
	adds r2, #1
	subs r5, #0xa
	cmp r5, #9
	bgt _081DCBF4
_081DCBFC:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x78
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r5, #0
	ble _081DCC20
_081DCC18:
	adds r2, #1
	subs r5, #1
	cmp r5, #0
	bgt _081DCC18
_081DCC20:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x18
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCC3C: .4byte 0x000006E4
_081DCC40: .4byte 0x000003E7
_081DCC44: .4byte 0xFFFFFC18

	thumb_func_start FUN_081dcc48
FUN_081dcc48: @ 0x081DCC48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	mov r8, r1
	ldr r0, _081DCCD4 @ =0x00000856
	add r0, ip
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r7, r0, #2
	ldr r4, _081DCCD8 @ =0x030046B4
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _081DCCDC @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	ldr r6, _081DCCE0 @ =0x085B0200
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r3, #7
	ands r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	movs r2, #0x64
	muls r0, r2, r0
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ands r1, r3
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r7, r7, r0
	ldr r0, _081DCCE4 @ =0x0000270F
	cmp r7, r0
	ble _081DCCB6
	adds r7, r0, #0
_081DCCB6:
	mov r0, r8
	lsls r1, r0, #1
	ldr r0, _081DCCE8 @ =0x000006E4
	add r0, ip
	adds r0, r0, r1
	strh r7, [r0]
	mov r0, ip
	mov r1, r8
	bl FUN_081dcb8c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCCD4: .4byte 0x00000856
_081DCCD8: .4byte 0x030046B4
_081DCCDC: .4byte 0x000003FF
_081DCCE0: .4byte 0x085B0200
_081DCCE4: .4byte 0x0000270F
_081DCCE8: .4byte 0x000006E4

	thumb_func_start FUN_081dccec
FUN_081dccec: @ 0x081DCCEC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _081DCD10 @ =0x00000856
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081DCD06
	ldr r0, _081DCD14 @ =0x000002A5
	bl PlaySound_082406e0
_081DCD06:
	movs r4, #0
	ldr r2, _081DCD18 @ =0x00000859
	adds r0, r5, r2
	b _081DCD38
	.align 2, 0
_081DCD10: .4byte 0x00000856
_081DCD14: .4byte 0x000002A5
_081DCD18: .4byte 0x00000859
_081DCD1C:
	lsls r0, r4, #1
	ldr r2, _081DCD48 @ =0x000006EC
	adds r1, r5, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DCD32
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081dcc48
_081DCD32:
	adds r4, #1
	ldr r1, _081DCD4C @ =0x00000859
	adds r0, r5, r1
_081DCD38:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r4, r0
	blt _081DCD1C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DCD48: .4byte 0x000006EC
_081DCD4C: .4byte 0x00000859

	thumb_func_start FUN_081dcd50
FUN_081dcd50: @ 0x081DCD50
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DCDAC @ =0x00000834
	adds r4, r5, r0
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe9
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r1, _081DCDB0 @ =0x00000704
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _081DCDB4 @ =0x00000828
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _081DCDB8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DCDBC
	movs r0, #1
	rsbs r0, r0, #0
	b _081DCDC0
	.align 2, 0
_081DCDAC: .4byte 0x00000834
_081DCDB0: .4byte 0x00000704
_081DCDB4: .4byte 0x00000828
_081DCDB8: .4byte 0x03002C68
_081DCDBC:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_081DCDC0:
	cmp r0, #1
	beq _081DCDD2
	cmp r0, #1
	ble _081DCDEC
	cmp r0, #2
	beq _081DCDDC
	cmp r0, #3
	beq _081DCDE2
	b _081DCDEC
_081DCDD2:
	ldr r0, _081DCDD8 @ =0x0000075C
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDD8: .4byte 0x0000075C
_081DCDDC:
	movs r2, #0xec
	lsls r2, r2, #3
	b _081DCDF0
_081DCDE2:
	ldr r0, _081DCDE8 @ =0x00000764
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDE8: .4byte 0x00000764
_081DCDEC:
	movs r2, #0xeb
	lsls r2, r2, #3
_081DCDF0:
	adds r1, r5, r2
_081DCDF2:
	ldr r0, _081DCE0C @ =0x00007FFF
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, _081DCE10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DCE0C: .4byte 0x00007FFF
_081DCE10: .4byte 0x03004290

	thumb_func_start FUN_081dce14
FUN_081dce14: @ 0x081DCE14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sl, r1
	movs r0, #0
	mov sb, r0
	movs r1, #0xf
	str r1, [sp]
_081DCE2C:
	ldr r2, _081DCE40 @ =0x00000828
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081DCE44
	movs r3, #0xe5
	lsls r3, r3, #3
	adds r0, r7, r3
	b _081DCE4A
	.align 2, 0
_081DCE40: .4byte 0x00000828
_081DCE44:
	movs r5, #0xe9
	lsls r5, r5, #3
	adds r0, r7, r5
_081DCE4A:
	add r0, sb
	ldrh r1, [r0]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	ldrh r4, [r0]
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r2, r7, r3
	add r2, sb
	adds r0, r1, #0
	movs r5, #0x1f
	ands r0, r5
	mov r8, r4
	mov r3, r8
	ands r3, r5
	mov r8, r3
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r2]
	movs r5, #0xfd
	lsls r5, r5, #3
	adds r6, r7, r5
	add r6, sb
	asrs r0, r1, #5
	movs r3, #0x1f
	ands r0, r3
	asrs r3, r4, #5
	movs r5, #0x1f
	ands r3, r5
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r6]
	ldr r0, _081DCF28 @ =0x00000808
	adds r5, r7, r0
	add r5, sb
	asrs r0, r1, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r4, r4, #0xa
	ands r4, r1
	subs r0, r0, r4
	lsls r0, r0, #5
	strh r0, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, sl
	str r2, [sp, #4]
	str r3, [sp, #8]
	bl Div
	ldr r2, [sp, #4]
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r6, r2]
	mov r1, sl
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	strh r0, [r5]
	movs r2, #0xed
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	mov r5, r8
	lsls r5, r5, #5
	strh r5, [r0]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r7, r1
	add r0, sb
	ldr r3, [sp, #8]
	lsls r3, r3, #5
	strh r3, [r0]
	adds r2, #0x40
	adds r0, r7, r2
	add r0, sb
	lsls r4, r4, #5
	strh r4, [r0]
	movs r3, #2
	add sb, r3
	ldr r5, [sp]
	subs r5, #1
	str r5, [sp]
	cmp r5, #0
	bge _081DCE2C
	ldr r0, _081DCF2C @ =0x00000828
	adds r2, r7, r0
	ldrh r0, [r2]
	movs r1, #1
	eors r0, r1
	strh r0, [r2]
	ldr r1, _081DCF30 @ =0x00000706
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCF28: .4byte 0x00000808
_081DCF2C: .4byte 0x00000828
_081DCF30: .4byte 0x00000706

	thumb_func_start FUN_081dcf34
FUN_081dcf34: @ 0x081DCF34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _081DCF68 @ =0x0000082A
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _081DCF6C
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DCF5A
	b _081DD060
_081DCF5A:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
	strh r5, [r4]
	b _081DD060
	.align 2, 0
_081DCF68: .4byte 0x0000082A
_081DCF6C:
	ldr r1, _081DCFB4 @ =0x03004290
	mov sl, r1
	movs r2, #0xf1
	lsls r2, r2, #3
	adds r3, r7, r2
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r2, #0xf
	mov sb, r2
	adds r0, #0x60
	adds r6, r7, r0
_081DCF88:
	ldrh r0, [r6]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #0x20]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldr r1, _081DCFB8 @ =0x00000808
	adds r0, r7, r1
	add r0, r8
	ldrh r0, [r0]
	ldrh r2, [r3, #0x20]
	adds r0, r0, r2
	strh r0, [r3, #0x20]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _081DCFBC
	asrs r0, r0, #5
	b _081DCFC2
	.align 2, 0
_081DCFB4: .4byte 0x03004290
_081DCFB8: .4byte 0x00000808
_081DCFBC:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFC2:
	mov ip, r0
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFD0
	asrs r0, r0, #5
	b _081DCFD6
_081DCFD0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFD6:
	adds r1, r0, #0
	movs r2, #0x20
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFE4
	asrs r0, r0, #5
	b _081DCFEA
_081DCFE4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFEA:
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r4, r7, r2
	mov r2, r8
	adds r2, r4, r2
	str r2, [sp]
	lsls r1, r1, #5
	mov r2, ip
	orrs r1, r2
	lsls r0, r0, #0xa
	orrs r0, r1
	ldr r1, [sp]
	strh r0, [r1]
	adds r3, #2
	adds r5, #2
	adds r6, #2
	movs r2, #2
	add r8, r2
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _081DCF88
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x10
	bl CpuSet
	ldr r2, _081DD048 @ =0x00000706
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081DD060
	ldr r1, _081DD04C @ =0x00000828
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081DD054
	ldr r2, _081DD050 @ =0x0000082A
	adds r1, r7, r2
	movs r0, #0x14
	strh r0, [r1]
	b _081DD05C
	.align 2, 0
_081DD048: .4byte 0x00000706
_081DD04C: .4byte 0x00000828
_081DD050: .4byte 0x0000082A
_081DD054:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
_081DD05C:
	movs r0, #1
	b _081DD062
_081DD060:
	movs r0, #0
_081DD062:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dd074
FUN_081dd074: @ 0x081DD074
	push {r4, r5, r6, lr}
	sub sp, #0x20
	mov r6, sp
	lsls r4, r1, #1
	ldr r3, _081DD0B0 @ =0x000006F4
	adds r5, r0, r3
	adds r4, r5, r4
	ldrh r3, [r4]
	strh r3, [r6, #0x10]
	mov r3, sp
	ldr r6, _081DD0B4 @ =0x000006FC
	adds r0, r0, r6
	adds r1, r0, r1
	ldrb r6, [r1]
	strb r6, [r3, #0x18]
	lsls r3, r2, #1
	adds r5, r5, r3
	ldrh r3, [r5]
	strh r3, [r4]
	adds r0, r0, r2
	ldrb r2, [r0]
	strb r2, [r1]
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	strb r6, [r0]
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DD0B0: .4byte 0x000006F4
_081DD0B4: .4byte 0x000006FC

	thumb_func_start FUN_081dd0b8
FUN_081dd0b8: @ 0x081DD0B8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	b _081DD106
_081DD0C0:
	movs r2, #0
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	adds r7, r1, #1
	cmp r2, r0
	bge _081DD104
	ldr r0, _081DD11C @ =0x000006F4
	adds r5, r6, r0
_081DD0D6:
	lsls r0, r2, #1
	adds r0, r5, r0
	adds r4, r2, #1
	lsls r1, r4, #1
	adds r1, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _081DD0F2
	adds r0, r6, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_081dd074
_081DD0F2:
	adds r2, r4, #0
	ldr r1, _081DD120 @ =0x00000859
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r2, r0
	blt _081DD0D6
_081DD104:
	adds r1, r7, #0
_081DD106:
	ldr r3, _081DD120 @ =0x00000859
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _081DD0C0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD11C: .4byte 0x000006F4
_081DD120: .4byte 0x00000859

	thumb_func_start FUN_081dd124
FUN_081dd124: @ 0x081DD124
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r4, #0
	movs r7, #1
	movs r3, #0
	ldr r0, _081DD188 @ =0x00000859
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r4, r0
	bge _081DD1A8
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _081DD18C @ =0x000006EC
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _081DD190 @ =0x000006F4
	adds r5, r6, r2
	ldr r0, _081DD194 @ =0x085AE3CC
	mov sl, r0
	mov ip, r1
_081DD15C:
	mov r1, sb
	adds r0, r1, r3
	strb r4, [r0]
	lsls r1, r3, #1
	mov r0, r8
	adds r2, r0, r1
	lsls r0, r4, #1
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, r5, r1
	adds r2, r3, #1
	lsls r0, r2, #1
	adds r0, r5, r0
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _081DD198
	adds r4, r4, r7
	movs r7, #1
	b _081DD19A
	.align 2, 0
_081DD188: .4byte 0x00000859
_081DD18C: .4byte 0x000006EC
_081DD190: .4byte 0x000006F4
_081DD194: .4byte 0x085AE3CC
_081DD198:
	adds r7, #1
_081DD19A:
	adds r3, r2, #0
	mov r1, ip
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r3, r0
	blt _081DD15C
_081DD1A8:
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r0, r0, r3
	strb r4, [r0]
	lsls r0, r3, #1
	subs r2, #0x14
	adds r1, r6, r2
	adds r1, r1, r0
	lsls r0, r4, #1
	ldr r2, _081DD1D4 @ =0x085AE3CC
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD1D4: .4byte 0x085AE3CC

	thumb_func_start FUN_081dd1d8
FUN_081dd1d8: @ 0x081DD1D8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _081DD232
_081DD1E0:
	lsls r2, r5, #1
	ldr r3, _081DD248 @ =0x000006EC
	adds r0, r4, r3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DD230
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081DD230
	ldr r0, _081DD24C @ =0x000006E4
	adds r1, r4, r0
	adds r1, r1, r2
	adds r3, #8
	adds r0, r4, r3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dcb8c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dc8c0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dc818
	ldr r0, _081DD250 @ =0x00000167
	bl PlaySound_082406e0
	ldr r0, _081DD254 @ =0x00000858
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081DD230:
	adds r5, #1
_081DD232:
	ldr r1, _081DD258 @ =0x00000859
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r5, r0
	blt _081DD1E0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD248: .4byte 0x000006EC
_081DD24C: .4byte 0x000006E4
_081DD250: .4byte 0x00000167
_081DD254: .4byte 0x00000858
_081DD258: .4byte 0x00000859

	thumb_func_start FUN_081dd25c
FUN_081dd25c: @ 0x081DD25C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DD270 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DD274
	movs r4, #1
	rsbs r4, r4, #0
	b _081DD278
	.align 2, 0
_081DD270: .4byte 0x03002C68
_081DD274:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
_081DD278:
	movs r2, #0
	ldr r0, _081DD2B4 @ =0x00000859
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _081DD2D4
	adds r3, r1, #0
	ldr r0, _081DD2B8 @ =0x000006FC
	adds r1, r5, r0
	ldr r5, _081DD2BC @ =0x030046A0
_081DD28E:
	ldrb r0, [r1]
	cmp r0, r4
	bne _081DD2C8
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _081DD2D4
	ldr r0, [r5]
	ldr r2, _081DD2C0 @ =0x00000916
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	ldr r2, _081DD2C4 @ =0x0000270F
	cmp r0, r2
	ble _081DD2AE
	adds r0, r2, #0
_081DD2AE:
	strh r0, [r1]
	b _081DD2D4
	.align 2, 0
_081DD2B4: .4byte 0x00000859
_081DD2B8: .4byte 0x000006FC
_081DD2BC: .4byte 0x030046A0
_081DD2C0: .4byte 0x00000916
_081DD2C4: .4byte 0x0000270F
_081DD2C8:
	adds r1, #1
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _081DD28E
_081DD2D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dd2dc
FUN_081dd2dc: @ 0x081DD2DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r3, #0
	ldr r0, _081DD308 @ =0x00000859
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r3, r0
	bge _081DD328
	ldr r0, _081DD30C @ =0x03002C68
	ldr r5, [r0]
	adds r6, r1, #0
	ldr r7, _081DD310 @ =0x000006F4
	adds r2, r4, r7
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r5, r0
_081DD2FE:
	cmp r5, #0
	bne _081DD314
	movs r0, #0
	b _081DD318
	.align 2, 0
_081DD308: .4byte 0x00000859
_081DD30C: .4byte 0x03002C68
_081DD310: .4byte 0x000006F4
_081DD314:
	movs r7, #0
	ldrsh r0, [r1, r7]
_081DD318:
	strh r0, [r2]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r3, r0
	blt _081DD2FE
_081DD328:
	ldr r0, _081DD360 @ =0x000006FC
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r7, _081DD364 @ =0x000006FD
	adds r1, r4, r7
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081DD368 @ =0x000006FE
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	adds r7, #2
	adds r1, r4, r7
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd0b8
	adds r0, r4, #0
	bl FUN_081dd124
	adds r0, r4, #0
	bl FUN_081dd25c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD360: .4byte 0x000006FC
_081DD364: .4byte 0x000006FD
_081DD368: .4byte 0x000006FE

	thumb_func_start FUN_081dd36c
FUN_081dd36c: @ 0x081DD36C
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _081DD37C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DD388
	b _081DD3BA
	.align 2, 0
_081DD37C: .4byte 0x03002C68
_081DD380:
	movs r0, #0xa9
	bl sound_08240264
	b _081DD3BA
_081DD388:
	movs r2, #0x18
	ldrsh r3, [r0, r2]
	cmp r3, #0
	blt _081DD3BA
	movs r2, #0
	ldr r4, _081DD3C0 @ =0x00000859
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	bge _081DD3BA
	adds r4, r0, #0
	ldr r0, _081DD3C4 @ =0x000006FC
	adds r1, r1, r0
_081DD3A6:
	ldrb r0, [r1]
	cmp r0, r3
	bne _081DD3B2
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081DD380
_081DD3B2:
	adds r1, #1
	adds r2, #1
	cmp r2, r4
	blt _081DD3A6
_081DD3BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DD3C0: .4byte 0x00000859
_081DD3C4: .4byte 0x000006FC

	thumb_func_start FUN_081dd3c8
FUN_081dd3c8: @ 0x081DD3C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DD428 @ =0x00000855
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD3E8
	movs r0, #1
	bl FUN_081df8f0
	ldr r1, _081DD42C @ =0x00000856
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DD3E8:
	ldr r0, _081DD42C @ =0x00000856
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r1, r0, #0
	cmp r1, #9
	bls _081DD406
	cmp r1, #0xa
	bne _081DD40A
	ldr r1, _081DD430 @ =0x00000844
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #5
	bl FUN_0804a2f8
	ldrh r0, [r4]
_081DD406:
	adds r0, #1
	strh r0, [r4]
_081DD40A:
	bl FUN_081dfa04
	cmp r0, #0x11
	beq _081DD416
	cmp r0, #0x14
	bne _081DD422
_081DD416:
	adds r0, r5, #0
	bl FUN_081dcb54
	adds r0, r5, #0
	bl KillEntity
_081DD422:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD428: .4byte 0x00000855
_081DD42C: .4byte 0x00000856
_081DD430: .4byte 0x00000844

	thumb_func_start FUN_081dd434
FUN_081dd434: @ 0x081DD434
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081DD518 @ =0x00000855
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081DD4E0
	adds r0, r6, #0
	bl FUN_081dc880
	adds r0, r6, #0
	bl FUN_081dcb54
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, _081DD51C @ =0x00000844
	adds r4, r6, r1
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081DD520 @ =0x0000083C
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r2, r6, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD528 @ =0x00000856
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r3, #0x78
	adds r1, r6, r3
	adds r3, #0x48
	adds r2, r6, r3
	ldrh r2, [r2]
	str r5, [sp]
	movs r3, #1
	bl FUN_082370cc
_081DD4E0:
	ldr r0, _081DD52C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DD530
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	ldrb r5, [r1]
	cmp r5, #0
	beq _081DD4FC
	b _081DD610
_081DD4FC:
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r4, r6, r2
	movs r0, #4
	strh r0, [r4]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r6, r3
	b _081DD55C
	.align 2, 0
_081DD518: .4byte 0x00000855
_081DD51C: .4byte 0x00000844
_081DD520: .4byte 0x0000083C
_081DD524: .4byte 0x0000085A
_081DD528: .4byte 0x00000856
_081DD52C: .4byte 0x030044E0
_081DD530:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DD574
	ldr r3, _081DD570 @ =0x0000085A
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #0
	beq _081DD610
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0
	movs r0, #5
	strh r0, [r4]
	strb r1, [r2]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
_081DD55C:
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r2, [r4]
	str r5, [sp]
	movs r3, #1
	bl FUN_082370cc
	b _081DD610
	.align 2, 0
_081DD570: .4byte 0x0000085A
_081DD574:
	movs r5, #1
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081DD5CC
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081DD5BC @ =0x0000085A
	adds r4, r6, r0
	ldrb r0, [r4]
	bl FUN_081df8a0
	ldr r1, _081DD5C0 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD5C4 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD5C8 @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD5FC
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD5BC: .4byte 0x0000085A
_081DD5C0: .4byte FUN_081dd3c8
_081DD5C4: .4byte 0x00000838
_081DD5C8: .4byte 0x00000855
_081DD5CC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DD610
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	bl FUN_081df8a0
	ldr r1, _081DD604 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD608 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD60C @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
_081DD5FC:
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD604: .4byte FUN_081dd3c8
_081DD608: .4byte 0x00000838
_081DD60C: .4byte 0x00000855
_081DD610:
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	bl FUN_082372cc
_081DD620:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dd628
FUN_081dd628: @ 0x081DD628
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DD660 @ =0x00000855
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081DD648
	adds r0, r4, #0
	bl FUN_081dd36c
	ldr r1, _081DD664 @ =0x00000856
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r5]
_081DD648:
	adds r0, r4, #0
	bl FUN_081dcf34
	ldr r3, _081DD664 @ =0x00000856
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #9
	bhi _081DD668
	adds r0, #1
	strh r0, [r1]
	b _081DD692
	.align 2, 0
_081DD660: .4byte 0x00000855
_081DD664: .4byte 0x00000856
_081DD668:
	ldr r0, _081DD698 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _081DD692
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _081DD69C @ =FUN_081dd434
	movs r2, #3
	ldr r3, _081DD6A0 @ =0x00000838
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081DD6A4 @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD6A8 @ =0x00000854
	adds r0, r4, r1
	strb r2, [r0]
_081DD692:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD698: .4byte 0x030044E0
_081DD69C: .4byte FUN_081dd434
_081DD6A0: .4byte 0x00000838
_081DD6A4: .4byte 0x00000855
_081DD6A8: .4byte 0x00000854

	thumb_func_start FUN_081dd6ac
FUN_081dd6ac: @ 0x081DD6AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DD738 @ =0x00000855
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DD6C6
	ldr r1, _081DD73C @ =0x00000856
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081DD6C6:
	ldr r0, _081DD740 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081DD744 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081DD6FC
	movs r2, #0
	ldr r3, _081DD748 @ =0x00000859
	adds r1, r4, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _081DD6FC
	movs r5, #1
	adds r3, r1, #0
	ldr r0, _081DD74C @ =0x000006EC
	adds r1, r4, r0
_081DD6E8:
	ldrh r0, [r1]
	cmp r0, #1
	bls _081DD6F0
	strh r5, [r1]
_081DD6F0:
	adds r1, #2
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _081DD6E8
_081DD6FC:
	adds r0, r4, #0
	bl FUN_081dccec
	adds r0, r4, #0
	bl FUN_081dd1d8
	ldr r1, _081DD750 @ =0x00000858
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _081DD748 @ =0x00000859
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _081DD760
	ldr r1, _081DD754 @ =FUN_081dd628
	movs r2, #2
	ldr r3, _081DD758 @ =0x00000838
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081DD738 @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD75C @ =0x00000854
	adds r0, r4, r1
	strb r2, [r0]
	b _081DD76A
	.align 2, 0
_081DD738: .4byte 0x00000855
_081DD73C: .4byte 0x00000856
_081DD740: .4byte 0x030044E0
_081DD744: .4byte 0x0000030F
_081DD748: .4byte 0x00000859
_081DD74C: .4byte 0x000006EC
_081DD750: .4byte 0x00000858
_081DD754: .4byte FUN_081dd628
_081DD758: .4byte 0x00000838
_081DD75C: .4byte 0x00000854
_081DD760:
	ldr r2, _081DD770 @ =0x00000856
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081DD76A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD770: .4byte 0x00000856

	thumb_func_start FUN_081dd774
FUN_081dd774: @ 0x081DD774
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _081DD7EC @ =0x00000855
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD792
	ldr r1, _081DD7F0 @ =0x00000856
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DD792:
	ldr r2, _081DD7F0 @ =0x00000856
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0xa
	bls _081DD80C
	ldr r0, _081DD7F4 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081DD7F8 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081DD80C
	movs r2, #0
	ldr r4, _081DD7FC @ =0x00000859
	adds r1, r3, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r4, _081DD800 @ =FUN_081dd6ac
	mov r8, r4
	ldr r4, _081DD804 @ =0x00000838
	adds r4, r4, r3
	mov ip, r4
	ldr r4, _081DD7EC @ =0x00000855
	adds r7, r3, r4
	subs r4, #1
	adds r6, r3, r4
	cmp r2, r0
	bge _081DD7DE
	movs r5, #1
	adds r4, r1, #0
	ldr r0, _081DD808 @ =0x000006EC
	adds r1, r3, r0
_081DD7D0:
	strh r5, [r1]
	adds r1, #2
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r2, r0
	blt _081DD7D0
_081DD7DE:
	movs r0, #1
	mov r1, r8
	mov r2, ip
	str r1, [r2]
	strb r0, [r7]
	strb r0, [r6]
	b _081DD84C
	.align 2, 0
_081DD7EC: .4byte 0x00000855
_081DD7F0: .4byte 0x00000856
_081DD7F4: .4byte 0x030044E0
_081DD7F8: .4byte 0x0000030F
_081DD7FC: .4byte 0x00000859
_081DD800: .4byte FUN_081dd6ac
_081DD804: .4byte 0x00000838
_081DD808: .4byte 0x000006EC
_081DD80C:
	ldr r0, _081DD830 @ =0x00000856
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0x40
	bls _081DD840
	ldr r1, _081DD834 @ =FUN_081dd6ac
	movs r2, #1
	ldr r4, _081DD838 @ =0x00000838
	adds r0, r3, r4
	str r1, [r0]
	ldr r1, _081DD83C @ =0x00000855
	adds r0, r3, r1
	strb r2, [r0]
	adds r4, #0x1c
	adds r0, r3, r4
	strb r2, [r0]
	b _081DD84C
	.align 2, 0
_081DD830: .4byte 0x00000856
_081DD834: .4byte FUN_081dd6ac
_081DD838: .4byte 0x00000838
_081DD83C: .4byte 0x00000855
_081DD840:
	adds r0, r3, #0
	bl FUN_081dccec
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081DD84C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityB85F_Update
EntityB85F_Update: @ 0x081DD858
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DD870
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DD882
_081DD870:
	ldr r1, _081DD888 @ =0x00000838
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DD880
	adds r0, r4, #0
	bl _call_via_r1
_081DD880:
	movs r0, #1
_081DD882:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DD888: .4byte 0x00000838

	thumb_func_start EntityB85F_Destroy
EntityB85F_Destroy: @ 0x081DD88C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dc880
	adds r0, r4, #0
	bl FUN_081dcb70
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB85F_Init
EntityB85F_Init: @ 0x081DD8A4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081DD8C0
	bl FUN_0823d340
	ldr r2, _081DD934 @ =0x0000083C
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081DD954
_081DD8C0:
	movs r0, #0
	bl FUN_081df8f0
	ldr r0, _081DD938 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081DD8D4
	ldrh r1, [r0, #0x1a]
_081DD8D4:
	ldr r2, _081DD93C @ =0x00000859
	adds r0, r4, r2
	movs r5, #0
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _081DD954
	adds r0, r4, #0
	bl FUN_081dc6d0
	adds r0, r4, #0
	bl FUN_081dc788
	adds r0, r4, #0
	bl FUN_081dc9dc
	adds r0, r4, #0
	bl FUN_081dcaa4
	adds r0, r4, #0
	bl FUN_081dcd50
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_081dce14
	ldr r1, _081DD940 @ =0x00000858
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_081dd2dc
	ldr r1, _081DD944 @ =FUN_081dd774
	ldr r2, _081DD948 @ =0x00000838
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081DD94C @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD950 @ =0x00000854
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #1
	b _081DD958
	.align 2, 0
_081DD934: .4byte 0x0000083C
_081DD938: .4byte 0x03002C68
_081DD93C: .4byte 0x00000859
_081DD940: .4byte 0x00000858
_081DD944: .4byte FUN_081dd774
_081DD948: .4byte 0x00000838
_081DD94C: .4byte 0x00000855
_081DD950: .4byte 0x00000854
_081DD954:
	movs r0, #1
	rsbs r0, r0, #0
_081DD958:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB85F_Create
EntityB85F_Create: @ 0x081DD960
	push {r4, lr}
	ldr r1, _081DD98C @ =0x0000085C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DD998
	ldr r1, _081DD990 @ =EntityB85F_Update
	ldr r2, _081DD994 @ =EntityB85F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB85F_Init
	cmp r0, #0
	bge _081DD998
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DD99A
	.align 2, 0
_081DD98C: .4byte 0x0000085C
_081DD990: .4byte EntityB85F_Update
_081DD994: .4byte EntityB85F_Destroy
_081DD998:
	adds r0, r4, #0
_081DD99A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dd9a0
FUN_081dd9a0: @ 0x081DD9A0
	ldr r0, _081DD9A8 @ =0x03002C68
	ldr r0, [r0]
	bx lr
	.align 2, 0
_081DD9A8: .4byte 0x03002C68

	thumb_func_start FUN_081dd9ac
FUN_081dd9ac: @ 0x081DD9AC
	ldr r1, _081DD9B4 @ =0x03002C68
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081DD9B4: .4byte 0x03002C68

	thumb_func_start FUN_081dd9b8
FUN_081dd9b8: @ 0x081DD9B8
	push {r4, lr}
	movs r3, #0
	strb r1, [r0, #0x1c]
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r1, r0, r4
	str r2, [r1]
	str r3, [r0, #0x34]
	adds r0, #0x22
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dd9d4
FUN_081dd9d4: @ 0x081DD9D4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0
	bne _081DD9E4
	movs r0, #0
	b _081DD9EA
_081DD9E4:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_081DD9EA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dd9f0
FUN_081dd9f0: @ 0x081DD9F0
	push {lr}
	adds r2, r0, #0
	adds r2, #0x7e
	movs r1, #0
	strh r1, [r2]
	movs r2, #0
	movs r1, #3
	adds r0, #0x86
_081DDA00:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _081DDA00
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dda10
FUN_081dda10: @ 0x081DDA10
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x50
	ldrb r3, [r2]
	cmp r3, #0
	bne _081DDA2A
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x51
	strb r3, [r0]
	b _081DDA34
_081DDA2A:
	movs r0, #0
	strb r0, [r2]
	adds r1, #0x51
	movs r0, #1
	strb r0, [r1]
_081DDA34:
	pop {r0}
	bx r0

	thumb_func_start FUN_081dda38
FUN_081dda38: @ 0x081DDA38
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x64
	movs r0, #0
	strh r0, [r1]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _081DDA8C
	adds r7, r1, #0
_081DDA4E:
	ldr r0, _081DDA5C @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _081DDA60
	movs r0, #0
	b _081DDA70
	.align 2, 0
_081DDA5C: .4byte 0x03002C68
_081DDA60:
	adds r0, r1, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r1, #0x58
	adds r1, r1, r0
	ldrb r0, [r1]
_081DDA70:
	adds r4, r0, #0
	bl GetSunLevel
	adds r1, r5, #0
	adds r1, #0x60
	adds r1, r1, r6
	strb r0, [r1]
	ldrh r0, [r7]
	adds r4, r4, r0
	strh r4, [r7]
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _081DDA4E
_081DDA8C:
	ldrh r1, [r5, #0x1a]
	cmp r1, #0
	bne _081DDA9A
	adds r0, r5, #0
	adds r0, #0x66
	strh r1, [r0]
	b _081DDAAC
_081DDA9A:
	adds r0, r5, #0
	adds r0, #0x64
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1a]
	bl Div
	adds r1, r5, #0
	adds r1, #0x66
	strh r0, [r1]
_081DDAAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ddab4
FUN_081ddab4: @ 0x081DDAB4
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x4c]
	cmp r1, #0
	blt _081DDB06
	movs r2, #0x18
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bne _081DDB06
	ldrb r0, [r3, #0x1f]
	cmp r0, #0xe
	bhi _081DDB06
	movs r4, #0
	movs r2, #0
	ldrh r5, [r3, #0x1a]
	ldr r6, _081DDADC @ =0x0000FFFF
_081DDAD4:
	cmp r2, #0
	bge _081DDAE0
	ldr r0, _081DDADC @ =0x0000FFFF
	b _081DDAE8
	.align 2, 0
_081DDADC: .4byte 0x0000FFFF
_081DDAE0:
	ldr r1, [r3, #0x44]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DDAE8:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	beq _081DDAF2
	adds r4, #1
_081DDAF2:
	adds r2, #1
	cmp r2, #3
	ble _081DDAD4
	cmp r4, r5
	bne _081DDB00
	movs r0, #1
	b _081DDB02
_081DDB00:
	movs r0, #0
_081DDB02:
	cmp r0, #0
	bne _081DDB0C
_081DDB06:
	movs r0, #1
	rsbs r0, r0, #0
	b _081DDB0E
_081DDB0C:
	movs r0, #0
_081DDB0E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ddb14
FUN_081ddb14: @ 0x081DDB14
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x7e
	adds r0, r0, r4
	mov ip, r0
	ldrh r3, [r0]
	cmp r3, r2
	bge _081DDB54
	ldr r0, [r4, #0x48]
	cmp r0, #0
	blt _081DDB50
	adds r0, r1, r3
	ldrb r1, [r0]
	movs r0, #3
	ands r3, r0
	lsls r0, r3, #8
	orrs r1, r0
	movs r0, #0x80
	lsls r0, r0, #4
	orrs r1, r0
	adds r0, r4, #0
	adds r0, #0x42
	strh r1, [r0]
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, r2
	bge _081DDB54
_081DDB50:
	movs r0, #0
	b _081DDB56
_081DDB54:
	movs r0, #1
_081DDB56:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ddb5c
FUN_081ddb5c: @ 0x081DDB5C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	lsls r2, r5, #1
	adds r0, #0x80
	adds r0, r0, r2
	ldrh r1, [r0]
	cmp r1, r7
	bge _081DDBCE
	adds r4, r4, r1
	mov ip, r4
	cmp r5, #0
	bge _081DDB84
	ldr r0, _081DDB80 @ =0x0000FFFF
	b _081DDB8A
	.align 2, 0
_081DDB80: .4byte 0x0000FFFF
_081DDB84:
	ldr r0, [r6, #0x44]
	adds r0, r2, r0
	ldrh r0, [r0]
_081DDB8A:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bne _081DDBA0
	movs r0, #1
	b _081DDBA2
_081DDBA0:
	movs r0, #0
_081DDBA2:
	cmp r0, #0
	beq _081DDBD2
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r1, r4
	lsls r2, r5, #1
	adds r0, r6, #0
	adds r0, #0x80
	adds r2, r0, r2
	ldrh r3, [r2]
	movs r0, #3
	lsrs r1, r1, #8
	ands r0, r3
	cmp r1, r0
	bne _081DDBD2
	mov r0, ip
	strb r4, [r0]
	adds r0, r3, #1
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, r7
	blt _081DDBD2
_081DDBCE:
	movs r0, #1
	b _081DDBD4
_081DDBD2:
	movs r0, #0
_081DDBD4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ddbdc
FUN_081ddbdc: @ 0x081DDBDC
	push {lr}
	movs r1, #0
	strh r1, [r0, #0x1a]
	ldrb r2, [r0, #0x1c]
	adds r1, r0, #0
	adds r1, #0x20
	strb r2, [r1]
	ldr r2, _081DDC00 @ =FUN_081de130
	movs r1, #0
	bl FUN_081dd9b8
	bl FUN_080a5e4c
	bl FUN_08238bf4
	pop {r0}
	bx r0
	.align 2, 0
_081DDC00: .4byte FUN_081de130

	thumb_func_start FUN_081ddc04
FUN_081ddc04: @ 0x081DDC04
	push {lr}
	adds r2, r0, #0
	movs r1, #0
	ldrh r0, [r2, #0x1a]
	cmp r1, r0
	bge _081DDC22
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r3, r2, r0
_081DDC16:
	adds r0, r3, r1
	strb r1, [r0]
	adds r1, #1
	ldrh r0, [r2, #0x1a]
	cmp r1, r0
	blt _081DDC16
_081DDC22:
	cmp r1, #4
	bgt _081DDC38
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r3, #4
_081DDC2E:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, #1
	cmp r1, #4
	ble _081DDC2E
_081DDC38:
	pop {r0}
	bx r0

	thumb_func_start FUN_081ddc3c
FUN_081ddc3c: @ 0x081DDC3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _081DDCC6
	movs r1, #0
	mov sb, r1
	ldr r2, _081DDCB8 @ =0x270F0000
	mov r8, r2
_081DDC56:
	adds r0, r7, #0
	bl FUN_081df720
	lsls r5, r7, #1
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r4, r1, r5
	lsls r0, r0, #4
	subs r2, #0x10
	adds r1, r6, r2
	adds r1, r1, r5
	ldrh r2, [r1]
	lsls r1, r2, #3
	adds r1, r1, r2
	adds r0, r0, r1
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r1, r1, r5
	ldrh r1, [r1]
	lsls r1, r1, #2
	subs r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081DDC90
	mov r0, sb
	strh r0, [r4]
_081DDC90:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, r8
	asrs r3, r2, #0x10
	cmp r0, r3
	ble _081DDC9E
	strh r3, [r4]
_081DDC9E:
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, r0, r5
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0
	ldrsh r0, [r4, r5]
	adds r1, r1, r0
	cmp r1, r3
	ble _081DDCBC
	strh r3, [r2]
	b _081DDCBE
	.align 2, 0
_081DDCB8: .4byte 0x270F0000
_081DDCBC:
	strh r1, [r2]
_081DDCBE:
	adds r7, #1
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	blt _081DDC56
_081DDCC6:
	cmp r7, #3
	bgt _081DDCEC
	ldr r1, _081DDCF8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r7, #1
	movs r5, #0x98
	lsls r5, r5, #1
	adds r0, r0, r5
	adds r1, r0, r6
_081DDCD8:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldrh r0, [r1, #8]
	orrs r0, r2
	strh r0, [r1, #8]
	adds r1, #2
	adds r7, #1
	cmp r7, #3
	ble _081DDCD8
_081DDCEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DDCF8: .4byte 0x0000FFFF

	thumb_func_start FUN_081ddcfc
FUN_081ddcfc: @ 0x081DDCFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov sb, r0
	movs r0, #0
	mov r8, r0
	mov r1, sb
	ldrh r0, [r1, #0x1a]
	add r2, sp, #0x20
	mov sl, r2
	cmp r8, r0
	bge _081DDD3A
	adds r3, r0, #0
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, sb
	mov r1, sp
_081DDD24:
	mov r4, r8
	str r4, [r1]
	movs r4, #0
	ldrsh r0, [r2, r4]
	str r0, [r1, #0x10]
	adds r2, #2
	adds r1, #4
	movs r0, #1
	add r8, r0
	cmp r8, r3
	blt _081DDD24
_081DDD3A:
	mov r1, sb
	ldrh r1, [r1, #0x1a]
	mov ip, r1
	mov r2, r8
	cmp r2, #3
	bgt _081DDD5E
	movs r1, #1
	rsbs r1, r1, #0
	lsls r0, r2, #2
	add r0, sp
_081DDD4E:
	str r1, [r0]
	str r1, [r0, #0x10]
	adds r0, #4
	movs r4, #1
	add r8, r4
	mov r2, r8
	cmp r2, #3
	ble _081DDD4E
_081DDD5E:
	movs r4, #0
	mov r8, r4
_081DDD62:
	movs r0, #3
	cmp r0, r8
	ble _081DDD94
	add r7, sp, #0x10
_081DDD6A:
	subs r6, r0, #1
	lsls r5, r6, #2
	adds r3, r7, r5
	lsls r4, r0, #2
	adds r2, r7, r4
	ldr r0, [r3]
	ldr r1, [r2]
	cmp r0, r1
	bge _081DDD8E
	str r0, [r2]
	str r1, [r3]
	mov r0, sp
	adds r2, r0, r4
	ldr r3, [r2]
	adds r1, r0, r5
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
_081DDD8E:
	adds r0, r6, #0
	cmp r0, r8
	bgt _081DDD6A
_081DDD94:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #2
	ble _081DDD62
	mov r1, sl
	movs r2, #0
	mov r0, sl
	adds r0, #0xc
_081DDDA6:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _081DDDA6
	movs r3, #0
	movs r0, #1
	str r0, [sp, #0x20]
	str r3, [sp, #0x30]
	mov r8, r0
	cmp r8, ip
	bge _081DDDE4
	mov r6, sl
	add r2, sp, #0x10
	mov r4, ip
	add r5, sp, #0x34
_081DDDC4:
	ldr r1, [r2, #4]
	ldr r0, [r2]
	cmp r1, r0
	bge _081DDDCE
	mov r3, r8
_081DDDCE:
	stm r5!, {r3}
	lsls r1, r3, #2
	adds r1, r6, r1
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r2, #4
	movs r0, #1
	add r8, r0
	cmp r8, r4
	blt _081DDDC4
_081DDDE4:
	movs r1, #0
	mov r8, r1
	mov r2, ip
	cmp r8, r2
	bge _081DDE86
	movs r4, #0xa0
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x40]
	mov r6, sp
_081DDDF8:
	mov r0, r8
	lsls r1, r0, #2
	ldr r7, [r6]
	add r0, sp, #0x30
	adds r0, r0, r1
	ldr r5, [r0]
	lsls r1, r5, #1
	movs r0, #0xaa
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r1, _081DDE34 @ =0x085AE3D4
	lsls r0, r2, #2
	adds r0, r5, r0
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r2, [sp, #0x40]
	ldr r0, [r2]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	cmp r0, #0
	blt _081DDE38
	asrs r0, r0, #6
	b _081DDE3E
	.align 2, 0
_081DDE34: .4byte 0x085AE3D4
_081DDE38:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081DDE3E:
	cmp r0, #0
	ble _081DDE4A
	cmp r0, #0x3c
	ble _081DDE54
	movs r0, #0x3c
	b _081DDE54
_081DDE4A:
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081DDE54
	adds r0, r1, #0
_081DDE54:
	adds r4, r4, r0
	lsls r0, r5, #2
	add r0, sl
	ldr r1, [r0]
	cmp r1, #1
	ble _081DDE68
	adds r0, r4, #0
	bl Div
	adds r4, r0, #0
_081DDE68:
	lsls r0, r7, #2
	movs r1, #0xa2
	lsls r1, r1, #1
	add r1, sb
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r4
	str r0, [r1]
	adds r6, #4
	movs r4, #1
	add r8, r4
	mov r0, sb
	ldrh r2, [r0, #0x1a]
	cmp r8, r2
	blt _081DDDF8
_081DDE86:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dde98
FUN_081dde98: @ 0x081DDE98
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	movs r4, #0
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	bge _081DDECE
	mov r3, ip
	adds r3, #0x88
	movs r2, #0xd2
	lsls r2, r2, #1
	add r2, ip
_081DDEAE:
	adds r1, r3, #0
	adds r0, r2, #0
	adds r0, #0x1c
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	adds r3, #0x24
	adds r2, #0x48
	adds r4, #1
	mov r0, ip
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	blt _081DDEAE
_081DDECE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dded4
FUN_081dded4: @ 0x081DDED4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	movs r1, #0
	strh r0, [r4, #0x32]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	bl FUN_081ddc04
	movs r3, #0
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, _081DDF38 @ =0x000003FF
	ldr r1, _081DDF3C @ =0x03004510
_081DDEF4:
	strh r2, [r0]
	strh r2, [r0, #8]
	strh r2, [r0, #0x10]
	strh r5, [r1]
	adds r0, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DDEF4
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081dde98
	ldr r2, _081DDF40 @ =0x030046B8
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _081DDF38 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DDF38: .4byte 0x000003FF
_081DDF3C: .4byte 0x03004510
_081DDF40: .4byte 0x030046B8

	thumb_func_start FUN_081ddf44
FUN_081ddf44: @ 0x081DDF44
	push {lr}
	sub sp, #0x14
	adds r1, r0, #0
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081DDF7A
	ldrh r0, [r1, #0x1a]
	str r0, [sp]
	ldrh r0, [r1, #0x38]
	str r0, [sp, #4]
	ldrh r0, [r1, #0x3a]
	str r0, [sp, #8]
	ldr r1, _081DDF80 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081DDF7A:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_081DDF80: .4byte 0xFFFF0000

	thumb_func_start FUN_081ddf84
FUN_081ddf84: @ 0x081DDF84
	push {r4, r5, r6, lr}
	movs r3, #0
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r5, r0, r1
	movs r6, #0
	ldr r4, _081DDFAC @ =0x085AE3E8
_081DDF92:
	adds r2, r5, r3
	ldrb r1, [r2]
	ldr r0, [r4]
	cmp r1, r0
	blt _081DDF9E
	strb r6, [r2]
_081DDF9E:
	adds r4, #4
	adds r3, #1
	cmp r3, #2
	ble _081DDF92
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DDFAC: .4byte 0x085AE3E8

	thumb_func_start FUN_081ddfb0
FUN_081ddfb0: @ 0x081DDFB0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r2, _081DDFE0 @ =0x0000FFFF
	movs r1, #0
	cmp r1, r4
	bhs _081DDFF4
	movs r6, #0x80
	lsls r6, r6, #8
	ldr r5, _081DDFE4 @ =0x00001021
_081DDFC4:
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	eors r2, r0
	movs r3, #0
	adds r1, #1
_081DDFD0:
	adds r0, r2, #0
	ands r0, r6
	cmp r0, #0
	beq _081DDFE8
	lsls r2, r2, #1
	eors r2, r5
	b _081DDFEA
	.align 2, 0
_081DDFE0: .4byte 0x0000FFFF
_081DDFE4: .4byte 0x00001021
_081DDFE8:
	lsls r2, r2, #1
_081DDFEA:
	adds r3, #1
	cmp r3, #7
	bls _081DDFD0
	cmp r1, r4
	blo _081DDFC4
_081DDFF4:
	ldr r0, _081DE000 @ =0x0000FFFF
	bics r0, r2
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DE000: .4byte 0x0000FFFF

	thumb_func_start FUN_081de004
FUN_081de004: @ 0x081DE004
	push {lr}
	movs r1, #0
	ldrh r2, [r0, #0x1a]
	cmp r1, r2
	bge _081DE024
	adds r3, r0, #0
	adds r3, #0x78
_081DE012:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DE01E
	movs r0, #1
	b _081DE026
_081DE01E:
	adds r1, #1
	cmp r1, r2
	blt _081DE012
_081DE024:
	movs r0, #0
_081DE026:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081de02c
FUN_081de02c: @ 0x081DE02C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xae
	lsls r0, r0, #1
	adds r3, r5, r0
	ldr r1, _081DE068 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r4, r0, r2
	movs r2, #0
	adds r6, r1, #0
_081DE044:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xf
	ble _081DE044
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	bne _081DE070
	ldr r2, _081DE06C @ =0x030047E0
	ldrb r1, [r2, #6]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrb r2, [r2, #7]
	adds r0, r0, r2
	b _081DE072
	.align 2, 0
_081DE068: .4byte 0x030046A0
_081DE06C: .4byte 0x030047E0
_081DE070:
	movs r0, #0
_081DE072:
	strh r0, [r3, #0x10]
	movs r0, #0x64
	strh r0, [r3, #0x12]
	ldr r0, [r6]
	ldrh r1, [r0, #0x10]
	strh r1, [r3, #0x14]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r3, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081de090
FUN_081de090: @ 0x081DE090
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081de02c
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DE0D4 @ =0x000002C5
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #4
	bl ClearMemory
	ldr r2, _081DE0D8 @ =0x00000173
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	bl FUN_0823e1b0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DE0D4: .4byte 0x000002C5
_081DE0D8: .4byte 0x00000173

	thumb_func_start FUN_081de0dc
FUN_081de0dc: @ 0x081DE0DC
	push {r4, lr}
	mov ip, r0
	movs r1, #4
	movs r3, #4
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
_081DE0EA:
	strb r1, [r0]
	subs r0, #1
	subs r3, #1
	cmp r3, #0
	bge _081DE0EA
	movs r3, #0
	movs r2, #0
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0xa2
	lsls r4, r4, #1
	add r4, ip
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
_081DE10A:
	strh r2, [r0]
	strh r2, [r0, #8]
	strh r2, [r0, #0x10]
	strh r2, [r1]
	stm r4!, {r2}
	adds r0, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE10A
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081de130
FUN_081de130: @ 0x081DE130
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE182
	ldr r0, _081DE1F4 @ =0x030044D0
	movs r3, #0
	str r3, [r0]
	movs r2, #4
	ldr r1, _081DE1F8 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x55
	strb r3, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0x80
	lsls r0, r0, #7
	strh r0, [r1]
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	movs r2, #0xb6
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	movs r0, #1
	bl sound_fadeout_08240440
	bl FUN_08049fa8
	movs r0, #0
	bl FUN_0822b644
_081DE182:
	adds r4, r5, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #0
	bne _081DE1D2
	bl FUN_0804771c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE1D2
	movs r0, #1
	strb r0, [r4]
	movs r0, #5
	bl FUN_0809c08c
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r2, _081DE1FC @ =0x03003E78
	ldr r0, _081DE200 @ =0xFFFFF1FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	bl FUN_0822b41c
_081DE1D2:
	ldr r1, _081DE204 @ =FUN_0822e738
	ldr r2, _081DE208 @ =FUN_0822b09c
	ldr r3, _081DE20C @ =FUN_0822f584
	movs r0, #0
	bl FUN_0822a448
	ldr r0, [r5, #0x34]
	cmp r0, #0x1d
	bhi _081DE1EA
	ldr r1, _081DE210 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081DE1EA:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DE1F4: .4byte 0x030044D0
_081DE1F8: .4byte 0x030044BC
_081DE1FC: .4byte 0x03003E78
_081DE200: .4byte 0xFFFFF1FF
_081DE204: .4byte FUN_0822e738
_081DE208: .4byte FUN_0822b09c
_081DE20C: .4byte FUN_0822f584
_081DE210: .4byte 0x030047B8

	thumb_func_start FUN_081de214
FUN_081de214: @ 0x081DE214
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DE22C
	adds r2, r4, #0
	adds r2, #0x23
	movs r1, #0
	strb r1, [r2]
_081DE22C:
	adds r5, r4, #0
	adds r5, #0x23
	ldrb r1, [r5]
	cmp r1, #3
	bne _081DE244
	ldr r2, _081DE24C @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	movs r0, #0
	strb r0, [r5]
_081DE244:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DE24C: .4byte FUN_081de250

	thumb_func_start FUN_081de250
FUN_081de250: @ 0x081DE250
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DE280
	bl FUN_08238c24
	movs r3, #0
	adds r5, r4, #0
	adds r5, #0x68
	movs r6, #1
_081DE26C:
	adds r2, r5, r3
	ldrb r1, [r2]
	cmp r1, #0
	beq _081DE276
	strb r6, [r2]
_081DE276:
	adds r3, #1
	cmp r3, #3
	ble _081DE26C
	movs r1, #0
	strh r1, [r4, #0x2e]
_081DE280:
	ldr r1, [r4, #0x34]
	cmp r1, #2
	bls _081DE2D2
	bl FUN_08238bc0
	adds r1, r0, #0
	cmp r1, #0
	blt _081DE2A4
	strb r1, [r4, #0x1d]
	ldr r2, _081DE2A0 @ =FUN_081de2dc
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081dd9b8
	movs r0, #0
	b _081DE2D2
	.align 2, 0
_081DE2A0: .4byte FUN_081de2dc
_081DE2A4:
	ldrh r1, [r4, #0x2e]
	adds r1, #1
	strh r1, [r4, #0x2e]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x1d
	bls _081DE2D2
	ldr r2, _081DE2D8 @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	bl FUN_08238bf4
	adds r2, r4, #0
	adds r2, #0x68
	movs r3, #0
	adds r1, r4, #0
	adds r1, #0x6b
_081DE2CA:
	strb r3, [r1]
	subs r1, #1
	cmp r1, r2
	bge _081DE2CA
_081DE2D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081DE2D8: .4byte FUN_081de250

	thumb_func_start FUN_081de2dc
FUN_081de2dc: @ 0x081DE2DC
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE2F0
	movs r0, #0
	strh r0, [r4, #0x2e]
_081DE2F0:
	mov r0, sp
	bl FUN_08238e48
	adds r1, r0, #0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	blt _081DE324
	cmp r1, #0
	blt _081DE324
	lsls r0, r0, #1
	add r0, sp
	ldrh r1, [r0]
	ldr r0, _081DE31C @ =0x0000FFFF
	cmp r1, r0
	beq _081DE324
	ldr r2, _081DE320 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081dd9b8
	b _081DE352
	.align 2, 0
_081DE31C: .4byte 0x0000FFFF
_081DE320: .4byte FUN_081de360
_081DE324:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _081DE352
	ldr r2, _081DE35C @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	bl FUN_08238bf4
	adds r1, r4, #0
	adds r1, #0x68
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x6b
_081DE34A:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE34A
_081DE352:
	movs r0, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE35C: .4byte FUN_081de250

	thumb_func_start FUN_081de360
FUN_081de360: @ 0x081DE360
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov r0, sp
	bl FUN_08238e48
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE3B2
	movs r2, #0
	movs r0, #0
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0x28
	strb r0, [r1]
	ldr r0, _081DE3D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE3A0
	adds r0, #0x2c
	strb r2, [r0]
_081DE3A0:
	adds r1, r4, #0
	adds r1, #0x74
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x77
_081DE3AA:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE3AA
_081DE3B2:
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	bge _081DE46C
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _081DE3E0
_081DE3C6:
	ldr r2, _081DE3DC @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	bl FUN_08238bf4
	b _081DE6D4
	.align 2, 0
_081DE3D8: .4byte 0x03002C68
_081DE3DC: .4byte FUN_081de250
_081DE3E0:
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081DE444
	adds r5, r4, #0
	adds r5, #0x78
	adds r6, r4, #0
	adds r6, #0x23
	adds r1, r4, #0
	adds r1, #0x74
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x77
_081DE3FA:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE3FA
	movs r3, #0
	ldr r0, _081DE42C @ =0x0000FFFF
	mov r8, r0
	movs r7, #0
	adds r2, r4, #0
	adds r2, #0x68
	adds r1, r5, #0
	mov r5, sp
_081DE412:
	ldrh r0, [r5]
	cmp r0, r8
	bne _081DE430
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _081DE422
	adds r0, #1
	strb r0, [r1]
_081DE422:
	ldrb r0, [r1]
	cmp r0, #0x77
	bls _081DE436
	strb r7, [r2]
	b _081DE436
	.align 2, 0
_081DE42C: .4byte 0x0000FFFF
_081DE430:
	strb r7, [r1]
	movs r0, #1
	strb r0, [r2]
_081DE436:
	adds r2, #1
	adds r1, #1
	adds r5, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE412
	b _081DE6C0
_081DE444:
	ldrb r0, [r4, #0x1d]
	adds r6, r4, #0
	adds r6, #0x23
	cmp r0, #0
	beq _081DE450
	b _081DE6C0
_081DE450:
	ldr r0, _081DE468 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081DE45E
	b _081DE6C0
_081DE45E:
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	b _081DE6C0
	.align 2, 0
_081DE468: .4byte 0x030044E0
_081DE46C:
	movs r3, #0
	ldr r7, _081DE498 @ =0x0000FFFF
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0x68
	adds r1, r4, #0
	adds r1, #0x78
	mov r5, sp
_081DE47C:
	ldrh r0, [r5]
	cmp r0, r7
	bne _081DE49C
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _081DE48C
	adds r0, #1
	strb r0, [r1]
_081DE48C:
	ldrb r0, [r1]
	cmp r0, #0x77
	bls _081DE4A2
	strb r6, [r2]
	b _081DE4A2
	.align 2, 0
_081DE498: .4byte 0x0000FFFF
_081DE49C:
	strb r6, [r1]
	movs r0, #1
	strb r0, [r2]
_081DE4A2:
	adds r2, #1
	adds r1, #1
	adds r5, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE47C
	movs r3, #0
	strh r3, [r4, #0x2e]
	ldr r1, [r4, #0x4c]
	lsls r0, r1, #1
	add r0, sp
	ldrh r0, [r0]
	ldr r2, _081DE4F4 @ =0x0000FFFF
	cmp r0, r2
	bne _081DE4C2
	b _081DE3C6
_081DE4C2:
	strh r1, [r4, #0x18]
	strh r3, [r4, #0x1a]
	movs r1, #0
	mov sb, r1
	movs r7, #1
	mov r8, r1
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x2d
	str r0, [sp, #8]
	adds r1, r4, #0
	adds r1, #0x74
	str r1, [sp, #0x10]
	adds r0, #0x3b
	str r0, [sp, #0xc]
	mov sl, r2
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
	adds r6, r0, #0
	ldr r5, [sp, #0x10]
_081DE4EC:
	cmp r3, #0
	bge _081DE4F8
	ldr r0, _081DE4F4 @ =0x0000FFFF
	b _081DE500
	.align 2, 0
_081DE4F4: .4byte 0x0000FFFF
_081DE4F8:
	ldr r1, [r4, #0x44]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DE500:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, sl
	beq _081DE570
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bne _081DE51A
	movs r0, #1
	b _081DE51C
_081DE51A:
	movs r0, #0
_081DE51C:
	cmp r0, #0
	beq _081DE528
	movs r0, #0xff
	ands r0, r2
	cmp r0, #0x3e
	beq _081DE540
_081DE528:
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE53A
	movs r0, #1
	b _081DE53C
_081DE53A:
	movs r0, #0
_081DE53C:
	cmp r0, #0
	beq _081DE56C
_081DE540:
	movs r0, #1
	add sb, r0
	ldrb r0, [r5]
	cmp r0, #0xfe
	bhi _081DE54E
	adds r0, #1
	strb r0, [r5]
_081DE54E:
	ldrb r0, [r5]
	cmp r0, #0x59
	bls _081DE564
	movs r0, #2
	strb r0, [r6]
	cmp r7, #0
	beq _081DE58C
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _081DE58C
_081DE564:
	movs r7, #0
	movs r0, #1
	strb r0, [r6]
	b _081DE58C
_081DE56C:
	cmp r2, sl
	bne _081DE574
_081DE570:
	movs r0, #0
	b _081DE57A
_081DE574:
	movs r1, #1
	mov r8, r1
	mov r0, r8
_081DE57A:
	strb r0, [r6]
	movs r7, #0
	strb r7, [r5]
	ldr r0, _081DE5D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE58C
	adds r0, #0x2c
	strb r7, [r0]
_081DE58C:
	adds r6, #1
	adds r5, #1
	adds r3, #1
	cmp r3, #3
	ble _081DE4EC
	mov r1, r8
	cmp r1, #0
	beq _081DE5C2
	movs r3, #0
	ldr r0, _081DE5DC @ =0x0000FFFF
	mov ip, r0
	mov r1, sp
	ldr r5, [sp, #0xc]
	movs r7, #1
	ldr r2, [sp, #0x10]
	movs r6, #0
_081DE5AC:
	ldrh r0, [r1]
	cmp r0, ip
	beq _081DE5B6
	adds r0, r5, r3
	strb r7, [r0]
_081DE5B6:
	adds r0, r2, r3
	strb r6, [r0]
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE5AC
_081DE5C2:
	ldr r0, [r4, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE5E0
	movs r0, #1
	b _081DE5E2
	.align 2, 0
_081DE5D8: .4byte 0x03002C68
_081DE5DC: .4byte 0x0000FFFF
_081DE5E0:
	movs r0, #0
_081DE5E2:
	cmp r0, #0
	beq _081DE654
	ldr r0, _081DE624 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE5F6
	adds r1, r0, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_081DE5F6:
	ldr r1, [sp, #8]
	ldrb r0, [r1]
	cmp r0, #0
	beq _081DE628
	subs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldrb r0, [r4, #0x1d]
	adds r6, r4, #0
	adds r6, #0x23
	cmp r0, #0
	bne _081DE6C0
	movs r0, #3
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	b _081DE6C0
	.align 2, 0
_081DE624: .4byte 0x03002C68
_081DE628:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldr r2, _081DE650 @ =FUN_081de6f0
	adds r0, r4, #0
	movs r1, #5
	bl FUN_081dd9b8
	adds r0, r4, #0
	bl FUN_081dd9f0
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DE6D4
	.align 2, 0
_081DE650: .4byte FUN_081de6f0
_081DE654:
	movs r0, #0x28
	ldr r1, [sp, #8]
	strb r0, [r1]
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _081DE6B4
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldr r0, _081DE6AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	adds r3, r4, #0
	adds r3, #0x28
	cmp r0, #0
	bne _081DE686
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DE6A4
_081DE686:
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r2, r4, #0
	adds r2, #0x42
	movs r0, #0
	strh r1, [r2]
	strb r0, [r3]
	ldr r0, _081DE6B0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE6A4
	adds r1, r0, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_081DE6A4:
	movs r0, #3
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	b _081DE6BC
	.align 2, 0
_081DE6AC: .4byte 0x030044E0
_081DE6B0: .4byte 0x03002C68
_081DE6B4:
	ldr r0, _081DE6E8 @ =0x0000043E
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
_081DE6BC:
	adds r6, r4, #0
	adds r6, #0x23
_081DE6C0:
	ldrb r0, [r6]
	cmp r0, #2
	bne _081DE6D4
	bl FUN_08238c24
	ldr r2, _081DE6EC @ =FUN_081de214
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081dd9b8
_081DE6D4:
	movs r0, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DE6E8: .4byte 0x0000043E
_081DE6EC: .4byte FUN_081de214

	thumb_func_start FUN_081de6f0
FUN_081de6f0: @ 0x081DE6F0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE724
	adds r0, r5, #0
	bl FUN_081dd9f0
	adds r0, r5, #0
	bl FUN_081de02c
	adds r0, r5, #0
	bl FUN_081ddc04
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x46
	bl FUN_081ddfb0
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
_081DE724:
	adds r0, r5, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE73A
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE7E2
_081DE73A:
	ldr r0, [r5, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE750
	movs r0, #1
	b _081DE752
_081DE750:
	movs r0, #0
_081DE752:
	cmp r0, #0
	beq _081DE770
	adds r0, r5, #0
	bl FUN_081dde98
	ldr r2, _081DE76C @ =FUN_081de7e8
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081dd9b8
	movs r0, #0
	b _081DE7E2
	.align 2, 0
_081DE76C: .4byte FUN_081de7e8
_081DE770:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x48
	bl FUN_081ddb14
	movs r7, #0
	movs r6, #0
	ldrh r1, [r5, #0x1a]
	cmp r7, r1
	bge _081DE7B8
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r4, r5, r2
_081DE78E:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x48
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DE7AE
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_081ddfb0
	adds r7, #1
_081DE7AE:
	adds r4, #0x48
	adds r6, #1
	ldrh r1, [r5, #0x1a]
	cmp r6, r1
	blt _081DE78E
_081DE7B8:
	ldrh r2, [r5, #0x1a]
	cmp r7, r2
	bne _081DE7CE
	ldrb r1, [r5, #0x1d]
	cmp r1, #0
	bne _081DE7CE
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x42
	strh r1, [r2]
_081DE7CE:
	ldr r2, [r5, #0x34]
	movs r1, #0xe1
	lsls r1, r1, #4
	cmp r2, r1
	bls _081DE7E2
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
_081DE7E2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081de7e8
FUN_081de7e8: @ 0x081DE7E8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE800
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE838
_081DE800:
	ldr r0, [r4, #0x34]
	cmp r0, #0x78
	bls _081DE836
	ldr r0, _081DE824 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE82C
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE82C
	ldr r2, _081DE828 @ =FUN_081de844
	adds r0, r4, #0
	movs r1, #7
	bl FUN_081dd9b8
	b _081DE836
	.align 2, 0
_081DE824: .4byte 0x03002C68
_081DE828: .4byte FUN_081de844
_081DE82C:
	ldr r2, _081DE840 @ =FUN_081de960
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081dd9b8
_081DE836:
	movs r0, #0
_081DE838:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE840: .4byte FUN_081de960

	thumb_func_start FUN_081de844
FUN_081de844: @ 0x081DE844
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE878
	bl FUN_081dc694
	ldr r1, _081DE890 @ =0x000002EA
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl Script_ExecById
	ldr r0, _081DE894 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE878
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE878
	movs r0, #0xa8
	bl sound_08240264
_081DE878:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE898
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE95A
	.align 2, 0
_081DE890: .4byte 0x000002EA
_081DE894: .4byte 0x03002C68
_081DE898:
	ldr r2, [r4, #0x44]
	ldrh r1, [r2]
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r1, r0
	movs r0, #0xe0
	lsls r0, r0, #5
	cmp r1, r0
	bne _081DE8AE
	movs r0, #1
	b _081DE8B0
_081DE8AE:
	movs r0, #0
_081DE8B0:
	cmp r0, #0
	beq _081DE8C4
	ldr r2, _081DE8C0 @ =FUN_081de9d8
	adds r0, r4, #0
	movs r1, #9
	bl FUN_081dd9b8
	b _081DE958
	.align 2, 0
_081DE8C0: .4byte FUN_081de9d8
_081DE8C4:
	ldrh r0, [r2]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bne _081DE8D8
	movs r0, #1
	b _081DE8DA
_081DE8D8:
	movs r0, #0
_081DE8DA:
	cmp r0, #0
	beq _081DE908
	ldr r2, _081DE900 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081dd9b8
	ldr r0, _081DE904 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE958
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE958
	movs r0, #1
	bl sound_fadeout_08240440
	b _081DE958
	.align 2, 0
_081DE900: .4byte FUN_081de360
_081DE904: .4byte 0x03002C68
_081DE908:
	ldr r0, _081DE934 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE958
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE958
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _081DE958
	cmp r1, #1
	bne _081DE938
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, #0x1f
	strh r1, [r0]
	b _081DE954
	.align 2, 0
_081DE934: .4byte 0x03002C68
_081DE938:
	cmp r1, #2
	bne _081DE954
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl Script_ExecById
_081DE954:
	movs r0, #0
	strb r0, [r5]
_081DE958:
	movs r0, #0
_081DE95A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081de960
FUN_081de960: @ 0x081DE960
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DE97A
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE9CE
_081DE97A:
	ldr r3, [r4, #0x44]
	ldrh r2, [r3]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r2, r1
	movs r1, #0xe0
	lsls r1, r1, #5
	cmp r2, r1
	bne _081DE990
	movs r1, #1
	b _081DE992
_081DE990:
	movs r1, #0
_081DE992:
	cmp r1, #0
	beq _081DE9A8
	ldr r2, _081DE9A4 @ =FUN_081de9d8
	adds r0, r4, #0
	movs r1, #9
	bl FUN_081dd9b8
	movs r0, #0
	b _081DE9CE
	.align 2, 0
_081DE9A4: .4byte FUN_081de9d8
_081DE9A8:
	ldrh r1, [r3]
	movs r2, #0xf0
	lsls r2, r2, #6
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r1, r2
	bne _081DE9BC
	movs r1, #1
	b _081DE9BE
_081DE9BC:
	movs r1, #0
_081DE9BE:
	cmp r1, #0
	beq _081DE9CE
	ldr r2, _081DE9D4 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081dd9b8
	movs r0, #0
_081DE9CE:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE9D4: .4byte FUN_081de360

	thumb_func_start FUN_081de9d8
FUN_081de9d8: @ 0x081DE9D8
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEA0E
	adds r0, r4, #0
	bl FUN_081dd9f0
	ldr r0, _081DEA24 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DEA0E
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DEA0E
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #6
	bl FUN_081ddfb0
	ldr r3, _081DEA28 @ =0x000002CA
	adds r1, r4, r3
	strh r0, [r1]
_081DEA0E:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DEA2C
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEAD2
	.align 2, 0
_081DEA24: .4byte 0x03002C68
_081DEA28: .4byte 0x000002CA
_081DEA2C:
	ldr r0, _081DEAD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DEA4A
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DEA4A
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #8
	bl FUN_081ddb14
_081DEA4A:
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r5, r4, r3
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #8
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DEAD2
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081ddfb0
	ldr r2, _081DEADC @ =FUN_081deaf4
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_081dd9b8
	bl FUN_08049fa8
	movs r0, #0
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081ddf84
	ldr r2, _081DEAE0 @ =0x030046B8
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldr r5, _081DEAE4 @ =0x000003FF
	adds r1, r5, #0
	ands r1, r0
	str r1, [r2]
	ldr r3, _081DEAE8 @ =0x000002CE
	adds r0, r4, r3
	ldrb r0, [r0]
	strh r0, [r4, #0x38]
	cmp r0, #2
	bls _081DEABC
	adds r0, r1, #1
	ands r0, r5
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081DEAEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	strh r0, [r4, #0x38]
_081DEABC:
	adds r0, r4, #0
	bl FUN_081ddf44
	ldr r1, _081DEAF0 @ =0x03004510
	adds r2, r5, #0
	adds r0, r1, #6
_081DEAC8:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _081DEAC8
	movs r0, #0
_081DEAD2:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DEAD8: .4byte 0x03002C68
_081DEADC: .4byte FUN_081deaf4
_081DEAE0: .4byte 0x030046B8
_081DEAE4: .4byte 0x000003FF
_081DEAE8: .4byte 0x000002CE
_081DEAEC: .4byte 0x0203B400
_081DEAF0: .4byte 0x03004510

	thumb_func_start FUN_081deaf4
FUN_081deaf4: @ 0x081DEAF4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _081DEB38 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEB10
	movs r0, #1
	bl sound_fadeout_08240440
_081DEB10:
	ldr r0, [r4, #0x34]
	cmp r0, #1
	bne _081DEB20
	movs r2, #4
	ldr r1, _081DEB3C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081DEB20:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEB40
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEBB4
	.align 2, 0
_081DEB38: .4byte 0x030044D0
_081DEB3C: .4byte 0x030044BC
_081DEB40:
	movs r6, #0
	movs r3, #0
	ldrh r5, [r4, #0x1a]
	cmp r6, r5
	bge _081DEB82
	movs r7, #0xf0
	lsls r7, r7, #6
_081DEB4E:
	cmp r3, #0
	bge _081DEB5C
	ldr r2, _081DEB58 @ =0x0000FFFF
	b _081DEB64
	.align 2, 0
_081DEB58: .4byte 0x0000FFFF
_081DEB5C:
	ldr r2, [r4, #0x44]
	lsls r1, r3, #1
	adds r1, r1, r2
	ldrh r2, [r1]
_081DEB64:
	adds r1, r7, #0
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #6
	cmp r1, r2
	bne _081DEB74
	movs r1, #1
	b _081DEB76
_081DEB74:
	movs r1, #0
_081DEB76:
	cmp r1, #0
	beq _081DEB7C
	adds r6, #1
_081DEB7C:
	adds r3, #1
	cmp r3, r5
	blt _081DEB4E
_081DEB82:
	cmp r6, r5
	bne _081DEB98
	ldr r2, _081DEB94 @ =FUN_081debd4
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_081dd9b8
	movs r0, #0
	b _081DEBB4
	.align 2, 0
_081DEB94: .4byte FUN_081debd4
_081DEB98:
	ldr r1, [r4, #0x34]
	cmp r1, #9
	bls _081DEBB4
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
	ldr r3, _081DEBBC @ =0x030044BC
	movs r2, #5
	rsbs r2, r2, #0
	ldr r1, [r3]
	ands r1, r2
	str r1, [r3]
_081DEBB4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DEBBC: .4byte 0x030044BC

	thumb_func_start FUN_081debc0
FUN_081debc0: @ 0x081DEBC0
	push {lr}
	ldr r2, _081DEBD0 @ =FUN_081dec1c
	movs r1, #0xc
	bl FUN_081dd9b8
	pop {r0}
	bx r0
	.align 2, 0
_081DEBD0: .4byte FUN_081dec1c

	thumb_func_start FUN_081debd4
FUN_081debd4: @ 0x081DEBD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081DEC14 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEBF6
	ldr r2, _081DEC18 @ =FUN_081debc0
	movs r0, #0
	movs r1, #0
	adds r3, r4, #0
	bl FUN_080a6180
_081DEBF6:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEC0C
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
_081DEC0C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DEC14: .4byte 0x030044D0
_081DEC18: .4byte FUN_081debc0

	thumb_func_start FUN_081dec1c
FUN_081dec1c: @ 0x081DEC1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _081DEC68 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEC9C
	ldr r1, _081DEC6C @ =0x085AE3F4
	ldr r2, _081DEC70 @ =0x000002CD
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x32]
	ldr r0, _081DEC74 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x94
	lsls r3, r3, #4
	adds r0, r0, r3
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x54
	strb r1, [r0]
	subs r0, #0x22
	bl FUN_0809c544
	movs r6, #0
	ldr r5, _081DEC78 @ =0x03002BE0
	b _081DEC8A
	.align 2, 0
_081DEC68: .4byte 0x030044D0
_081DEC6C: .4byte 0x085AE3F4
_081DEC70: .4byte 0x000002CD
_081DEC74: .4byte 0x030046A0
_081DEC78: .4byte 0x03002BE0
_081DEC7C:
	ldr r0, [r5]
	cmp r0, #0
	beq _081DEC86
	bl FUN_0807d118
_081DEC86:
	adds r5, #4
	adds r6, #1
_081DEC8A:
	ldr r0, _081DECD4 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081DEC98
	ldrh r1, [r0, #0x1a]
_081DEC98:
	cmp r6, r1
	blt _081DEC7C
_081DEC9C:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DECA8
	b _081DEE98
_081DECA8:
	ldr r0, _081DECD8 @ =0x04000130
	ldrh r0, [r0]
	ldr r1, _081DECDC @ =0x0000FFF3
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
	movs r7, #0
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DED8E
	movs r0, #0xf0
	lsls r0, r0, #6
	mov ip, r0
	movs r6, #0
	ldr r1, _081DECE0 @ =0x000003FF
	mov sb, r1
_081DECCC:
	cmp r5, #0
	bge _081DECE8
	ldr r0, _081DECE4 @ =0x0000FFFF
	b _081DECEE
	.align 2, 0
_081DECD4: .4byte 0x03002C68
_081DECD8: .4byte 0x04000130
_081DECDC: .4byte 0x0000FFF3
_081DECE0: .4byte 0x000003FF
_081DECE4: .4byte 0x0000FFFF
_081DECE8:
	ldr r0, [r4, #0x44]
	adds r0, r6, r0
	ldrh r0, [r0]
_081DECEE:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r0, r3, #0
	mov r2, ip
	ands r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bne _081DED04
	movs r0, #1
	b _081DED06
_081DED04:
	movs r0, #0
_081DED06:
	cmp r0, #0
	beq _081DED54
	ldr r2, _081DED50 @ =0x03004510
	adds r2, r6, r2
	adds r0, r3, #0
	mov r1, sb
	ands r0, r1
	movs r1, #0xc
	orrs r0, r1
	strh r0, [r2]
	lsrs r2, r3, #2
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r1, r4, #0
	adds r1, #0x58
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x52
	ldrb r0, [r0]
	lsls r2, r0
	ldrb r0, [r1]
	orrs r2, r0
	strb r2, [r1]
	cmp r5, #0
	bne _081DED84
	movs r7, #1
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DED84
	movs r7, #3
	b _081DED84
	.align 2, 0
_081DED50: .4byte 0x03004510
_081DED54:
	ldr r0, _081DED78 @ =0x0000FFFF
	cmp r3, r0
	bne _081DED5C
	b _081DEE98
_081DED5C:
	movs r2, #0x18
	ldrsh r0, [r4, r2]
	cmp r5, r0
	bne _081DED84
	adds r0, r3, #0
	mov r3, ip
	ands r0, r3
	movs r1, #0xa0
	lsls r1, r1, #6
	cmp r0, r1
	bne _081DED7C
	movs r0, #1
	b _081DED7E
	.align 2, 0
_081DED78: .4byte 0x0000FFFF
_081DED7C:
	movs r0, #0
_081DED7E:
	cmp r0, #0
	beq _081DED84
	b _081DEEA4
_081DED84:
	adds r6, #2
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DECCC
_081DED8E:
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _081DEDA0
	adds r1, r4, #0
	adds r1, #0x52
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081DEDA0:
	movs r0, #2
	ands r7, r0
	movs r1, #0x42
	adds r1, r1, r4
	mov sb, r1
	cmp r7, #0
	beq _081DEDF8
	adds r0, r4, #0
	bl FUN_081dda10
	adds r0, r4, #0
	bl FUN_081dda38
	adds r1, r4, #0
	adds r1, #0x52
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081DEE54 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x54
	strb r1, [r0]
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DEDF8
	adds r2, r4, #0
	adds r2, #0x50
	adds r1, r4, #0
	adds r1, #0x58
	movs r3, #0
_081DEDE6:
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r0, r1, r0
	strb r3, [r0]
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DEDE6
_081DEDF8:
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r0, #0xe1
	lsls r0, r0, #3
	cmp r1, r0
	beq _081DEE0C
	movs r0, #0xe1
	lsls r0, r0, #2
	cmp r1, r0
	bne _081DEE34
_081DEE0C:
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DEE34
	ldr r6, _081DEE58 @ =0x03002BE0
_081DEE16:
	adds r0, r5, #0
	bl FUN_081df720
	cmp r0, #2
	ble _081DEE2A
	ldr r1, [r6]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0801a108
_081DEE2A:
	adds r6, #4
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DEE16
_081DEE34:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _081DEE60
	bl FUN_0809c58c
	movs r0, #0xa0
	lsls r0, r0, #6
	mov r2, sb
	strh r0, [r2]
	ldr r2, _081DEE5C @ =FUN_081deef8
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_081dd9b8
	b _081DEEEA
	.align 2, 0
_081DEE54: .4byte 0x030046A0
_081DEE58: .4byte 0x03002BE0
_081DEE5C: .4byte FUN_081deef8
_081DEE60:
	ldr r0, _081DEE70 @ =0x03002C68
	ldr r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	bne _081DEE74
	adds r3, r4, #0
	adds r3, #0x53
	b _081DEE8E
	.align 2, 0
_081DEE70: .4byte 0x03002C68
_081DEE74:
	movs r3, #0x18
	ldrsh r0, [r2, r3]
	adds r3, r4, #0
	adds r3, #0x53
	cmp r0, #0
	bne _081DEE8E
	ldrb r0, [r3]
	cmp r0, #7
	bne _081DEE8E
	movs r0, #8
	mov r2, r8
	orrs r2, r0
	mov r8, r2
_081DEE8E:
	ldr r1, [r1]
	cmp r1, #0
	bne _081DEEB4
	movs r0, #0
	b _081DEEC4
_081DEE98:
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEEEC
_081DEEA4:
	ldr r2, _081DEEB0 @ =FUN_081deef8
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_081dd9b8
	b _081DEEEA
	.align 2, 0
_081DEEB0: .4byte FUN_081deef8
_081DEEB4:
	adds r0, r1, #0
	adds r0, #0x54
	ldrb r0, [r0]
	adds r1, #0x53
	ldrb r1, [r1]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
_081DEEC4:
	lsls r0, r0, #2
	mov r1, r8
	orrs r1, r0
	lsls r2, r1, #0x10
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	strb r0, [r3]
	movs r0, #0xc0
	lsls r0, r0, #0x14
	orrs r0, r2
	lsls r0, r0, #2
	lsrs r0, r0, #0x12
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r4, #0x32]
	subs r0, #1
	strh r0, [r4, #0x32]
_081DEEEA:
	movs r0, #0
_081DEEEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081deef8
FUN_081deef8: @ 0x081DEEF8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEF54
	bl FUN_082407b8
	movs r0, #1
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FUN_080a6180
	movs r2, #4
	ldr r1, _081DEF6C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_08016f84
	ldr r1, _081DEF70 @ =0x030044D0
	movs r0, #0
	str r0, [r1]
	ldr r4, _081DEF74 @ =0x030046A0
	ldr r0, [r4]
	ldr r3, _081DEF78 @ =0x00000914
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0
	bge _081DEF3E
	movs r2, #0
_081DEF3E:
	strh r2, [r1]
	ldr r0, [r4]
	adds r1, r0, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	ldr r2, _081DEF7C @ =0x0000270F
	cmp r0, r2
	ble _081DEF52
	adds r0, r2, #0
_081DEF52:
	strh r0, [r1]
_081DEF54:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEF80
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF00C
	.align 2, 0
_081DEF6C: .4byte 0x030044BC
_081DEF70: .4byte 0x030044D0
_081DEF74: .4byte 0x030046A0
_081DEF78: .4byte 0x00000914
_081DEF7C: .4byte 0x0000270F
_081DEF80:
	movs r7, #0
	movs r4, #0
	ldrh r6, [r5, #0x1a]
	cmp r7, r6
	bge _081DEFD0
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
_081DEF90:
	cmp r4, #0
	bge _081DEF9C
	ldr r1, _081DEF98 @ =0x0000FFFF
	b _081DEFA4
	.align 2, 0
_081DEF98: .4byte 0x0000FFFF
_081DEF9C:
	ldr r2, [r5, #0x44]
	lsls r1, r4, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DEFA4:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DEFBA
	movs r1, #1
	b _081DEFBC
_081DEFBA:
	movs r1, #0
_081DEFBC:
	cmp r1, #0
	beq _081DEFCA
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #0
	bne _081DEFCA
	adds r7, #1
_081DEFCA:
	adds r4, #1
	cmp r4, r6
	blt _081DEF90
_081DEFD0:
	cmp r7, r6
	bne _081DEFFC
	ldr r2, _081DEFF8 @ =FUN_081df014
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_081dd9b8
	adds r1, r5, #0
	adds r1, #0x21
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_081ddc3c
	adds r0, r5, #0
	bl FUN_081ddcfc
	movs r0, #0
	b _081DF00C
	.align 2, 0
_081DEFF8: .4byte FUN_081df014
_081DEFFC:
	ldr r1, [r5, #0x34]
	cmp r1, #0x59
	bls _081DF00C
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF00C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df014
FUN_081df014: @ 0x081DF014
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF036
	ldr r1, _081DF04C @ =0x000002E2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl Script_ExecById
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0xff
	strb r0, [r1]
_081DF036:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DF050
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF0F0
	.align 2, 0
_081DF04C: .4byte 0x000002E2
_081DF050:
	movs r5, #0
	movs r7, #0
	movs r3, #0
	ldrh r6, [r4, #0x1a]
	cmp r5, r6
	bge _081DF0A6
	movs r0, #0xf0
	lsls r0, r0, #6
	mov ip, r0
_081DF062:
	cmp r3, #0
	bge _081DF070
	ldr r0, _081DF06C @ =0x0000FFFF
	b _081DF078
	.align 2, 0
_081DF06C: .4byte 0x0000FFFF
_081DF070:
	ldr r1, [r4, #0x44]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DF078:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0xb0
	lsls r1, r1, #6
	cmp r0, r1
	bne _081DF08E
	movs r0, #1
	b _081DF090
_081DF08E:
	movs r0, #0
_081DF090:
	cmp r0, #0
	beq _081DF0A0
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #0
	beq _081DF09E
	adds r7, #1
_081DF09E:
	adds r5, #1
_081DF0A0:
	adds r3, #1
	cmp r3, r6
	blt _081DF062
_081DF0A6:
	cmp r5, r6
	bne _081DF0D0
	cmp r5, r7
	bne _081DF0C0
	ldr r2, _081DF0BC @ =FUN_081df0f8
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_081dd9b8
	b _081DF0EE
	.align 2, 0
_081DF0BC: .4byte FUN_081df0f8
_081DF0C0:
	ldr r2, _081DF0CC @ =FUN_081df3f0
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_081dd9b8
	b _081DF0EE
	.align 2, 0
_081DF0CC: .4byte FUN_081df3f0
_081DF0D0:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _081DF0EE
	lsls r0, r0, #0x10
	movs r1, #0xb0
	lsls r1, r1, #0x16
	orrs r1, r0
	lsls r1, r1, #2
	lsrs r1, r1, #0x12
	adds r0, r4, #0
	adds r0, #0x42
	strh r1, [r0]
_081DF0EE:
	movs r0, #0
_081DF0F0:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df0f8
FUN_081df0f8: @ 0x081DF0F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF134
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _081DF14C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF124
	adds r1, r0, #0
	adds r1, #0x56
	movs r0, #1
	strb r0, [r1]
_081DF124:
	ldr r0, _081DF150 @ =0x000002DE
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DF134
	movs r1, #0
	bl Script_ExecById
_081DF134:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF154
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF22A
	.align 2, 0
_081DF14C: .4byte 0x03002C68
_081DF150: .4byte 0x000002DE
_081DF154:
	movs r7, #0
	movs r4, #0
	ldrh r6, [r5, #0x1a]
	cmp r7, r6
	bge _081DF1A4
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
_081DF164:
	cmp r4, #0
	bge _081DF170
	ldr r1, _081DF16C @ =0x0000FFFF
	b _081DF178
	.align 2, 0
_081DF16C: .4byte 0x0000FFFF
_081DF170:
	ldr r2, [r5, #0x44]
	lsls r1, r4, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF178:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF18E
	movs r1, #1
	b _081DF190
_081DF18E:
	movs r1, #0
_081DF190:
	cmp r1, #0
	beq _081DF19E
	movs r1, #0xff
	ands r1, r3
	cmp r1, #0xa5
	bne _081DF19E
	adds r7, #1
_081DF19E:
	adds r4, #1
	cmp r4, r6
	blt _081DF164
_081DF1A4:
	cmp r7, r6
	bne _081DF1BC
	ldr r2, _081DF1B8 @ =FUN_081df23c
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081dd9b8
	movs r0, #0
	b _081DF22A
	.align 2, 0
_081DF1B8: .4byte FUN_081df23c
_081DF1BC:
	adds r1, r5, #0
	adds r1, #0x25
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	beq _081DF22A
	adds r6, r5, #0
	adds r6, #0x26
	ldrb r1, [r6]
	cmp r1, #0
	bne _081DF222
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DF234 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #5
	bl FUN_0809c08c
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r4, r5, r1
	str r0, [r4]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #9
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r1, #1
	strb r1, [r6]
_081DF222:
	ldr r2, _081DF238 @ =0x000010A5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF22A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF234: .4byte 0x0000FFFF
_081DF238: .4byte 0x000010A5

	thumb_func_start FUN_081df23c
FUN_081df23c: @ 0x081DF23C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF2C0
	adds r0, r5, #0
	bl FUN_081dd9f0
	adds r0, r5, #0
	bl FUN_081de02c
	adds r0, r5, #0
	bl FUN_081ddc04
	ldr r0, _081DF2D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF2AC
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DF2AC
	ldr r2, _081DF2DC @ =0x030047E0
	ldrb r1, [r2, #6]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrb r2, [r2, #7]
	adds r0, r0, r2
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _081DF2E0 @ =0x000002CE
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _081DF2A4
	ldr r2, _081DF2E4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081DF2E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081DF2EC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
_081DF2A4:
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_081DF2AC:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x46
	bl FUN_081ddfb0
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
_081DF2C0:
	adds r0, r5, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DF2F0
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF38C
	.align 2, 0
_081DF2D8: .4byte 0x03002C68
_081DF2DC: .4byte 0x030047E0
_081DF2E0: .4byte 0x000002CE
_081DF2E4: .4byte 0x030046B8
_081DF2E8: .4byte 0x000003FF
_081DF2EC: .4byte 0x0203B400
_081DF2F0:
	ldr r0, [r5, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DF306
	movs r0, #1
	b _081DF308
_081DF306:
	movs r0, #0
_081DF308:
	cmp r0, #0
	beq _081DF324
	adds r0, r5, #0
	bl FUN_081dde98
	ldr r2, _081DF320 @ =FUN_081df398
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_081dd9b8
	movs r0, #0
	b _081DF38C
	.align 2, 0
_081DF320: .4byte FUN_081df398
_081DF324:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x48
	bl FUN_081ddb14
	movs r7, #0
	movs r6, #0
	ldrh r1, [r5, #0x1a]
	cmp r7, r1
	bge _081DF36C
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r4, r5, r2
_081DF342:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x48
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DF362
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_081ddfb0
	adds r7, #1
_081DF362:
	adds r4, #0x48
	adds r6, #1
	ldrh r1, [r5, #0x1a]
	cmp r6, r1
	blt _081DF342
_081DF36C:
	ldrh r2, [r5, #0x1a]
	cmp r7, r2
	bne _081DF38C
	ldr r1, _081DF394 @ =0x03002C68
	ldr r1, [r1]
	cmp r1, #0
	beq _081DF38C
	movs r2, #0x18
	ldrsh r1, [r1, r2]
	cmp r1, #0
	bne _081DF38C
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF38C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF394: .4byte 0x03002C68

	thumb_func_start FUN_081df398
FUN_081df398: @ 0x081DF398
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF3B8
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF3E4
_081DF3B8:
	ldr r1, [r4, #0x34]
	cmp r1, #0x77
	bls _081DF3E4
	movs r0, #0
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081dded4
	movs r1, #0xdd
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x38]
	adds r0, r4, #0
	bl FUN_081ddf44
	ldr r2, _081DF3EC @ =FUN_081deaf4
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_081dd9b8
_081DF3E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF3EC: .4byte FUN_081deaf4

	thumb_func_start FUN_081df3f0
FUN_081df3f0: @ 0x081DF3F0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF42C
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r4, r5, r1
	str r0, [r4]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xa
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
_081DF42C:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF444
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF454
_081DF444:
	ldr r1, [r5, #0x34]
	cmp r1, #0x77
	bls _081DF454
	ldr r2, _081DF45C @ =FUN_081df460
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_081dd9b8
_081DF454:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DF45C: .4byte FUN_081df460

	thumb_func_start FUN_081df460
FUN_081df460: @ 0x081DF460
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF48C
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DF484
	movs r1, #0
	bl Script_ExecById
_081DF484:
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
_081DF48C:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF4A4
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF534
_081DF4A4:
	movs r7, #0
	movs r5, #0
	ldrh r6, [r4, #0x1a]
	movs r1, #0x29
	adds r1, r1, r4
	mov r8, r1
	cmp r7, r6
	bge _081DF4FC
	movs r2, #0xf0
	lsls r2, r2, #6
	mov ip, r2
_081DF4BA:
	cmp r5, #0
	bge _081DF4C8
	ldr r1, _081DF4C4 @ =0x0000FFFF
	b _081DF4D0
	.align 2, 0
_081DF4C4: .4byte 0x0000FFFF
_081DF4C8:
	ldr r2, [r4, #0x44]
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF4D0:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF4E6
	movs r1, #1
	b _081DF4E8
_081DF4E6:
	movs r1, #0
_081DF4E8:
	cmp r1, #0
	beq _081DF4F6
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #1
	bne _081DF4F6
	adds r7, #1
_081DF4F6:
	adds r5, #1
	cmp r5, r6
	blt _081DF4BA
_081DF4FC:
	cmp r7, r6
	bne _081DF50A
	ldr r2, _081DF528 @ =FUN_081df540
	adds r0, r4, #0
	movs r1, #0x16
	bl FUN_081dd9b8
_081DF50A:
	mov r2, r8
	ldrb r1, [r2]
	cmp r1, #0
	beq _081DF534
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r2]
	cmp r1, #0x3b
	bls _081DF530
	ldr r2, _081DF52C @ =0x00001001
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
	b _081DF534
	.align 2, 0
_081DF528: .4byte FUN_081df540
_081DF52C: .4byte 0x00001001
_081DF530:
	adds r1, #1
	strb r1, [r2]
_081DF534:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df540
FUN_081df540: @ 0x081DF540
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r4, #0
	adds r1, #0x2a
	ldrb r1, [r1]
	cmp r1, #0
	beq _081DF55C
	ldr r2, _081DF564 @ =FUN_081df568
	adds r0, r4, #0
	movs r1, #0x17
	bl FUN_081dd9b8
_081DF55C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF564: .4byte FUN_081df568

	thumb_func_start FUN_081df568
FUN_081df568: @ 0x081DF568
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	movs r6, #0
	movs r5, #0
	ldrh r1, [r4, #0x1a]
	cmp r6, r1
	bge _081DF5C0
	movs r7, #0xf0
	lsls r7, r7, #6
_081DF57E:
	cmp r5, #0
	bge _081DF58C
	ldr r1, _081DF588 @ =0x0000FFFF
	b _081DF594
	.align 2, 0
_081DF588: .4byte 0x0000FFFF
_081DF58C:
	ldr r2, [r4, #0x44]
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF594:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	ands r1, r7
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF5A8
	movs r1, #1
	b _081DF5AA
_081DF5A8:
	movs r1, #0
_081DF5AA:
	cmp r1, #0
	beq _081DF5B8
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #2
	bne _081DF5B8
	adds r6, #1
_081DF5B8:
	adds r5, #1
	ldrh r1, [r4, #0x1a]
	cmp r5, r1
	blt _081DF57E
_081DF5C0:
	ldrh r1, [r4, #0x1a]
	cmp r6, r1
	bne _081DF5D8
	ldr r2, _081DF5D4 @ =FUN_081df604
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_081dd9b8
	b _081DF5F2
	.align 2, 0
_081DF5D4: .4byte FUN_081df604
_081DF5D8:
	ldr r1, [r4, #0x4c]
	adds r1, #2
	cmp r1, #1
	bls _081DF5E6
	ldr r1, [r4, #0x34]
	cmp r1, #0xb3
	bls _081DF5F2
_081DF5E6:
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF5FA
_081DF5F2:
	ldr r2, _081DF600 @ =0x00001002
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF5FA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF600: .4byte 0x00001002

	thumb_func_start FUN_081df604
FUN_081df604: @ 0x081DF604
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r4, #0
	adds r1, #0x2b
	ldrb r1, [r1]
	cmp r1, #0
	beq _081DF620
	ldr r2, _081DF628 @ =FUN_081df62c
	adds r0, r4, #0
	movs r1, #0x19
	bl FUN_081dd9b8
_081DF620:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF628: .4byte FUN_081df62c

	thumb_func_start FUN_081df62c
FUN_081df62c: @ 0x081DF62C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DF646
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #1
	strb r1, [r4, #0x1e]
_081DF646:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df64c
FUN_081df64c: @ 0x081DF64C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	ldr r0, _081DF664 @ =0x03002C68
	ldr r7, [r0]
	cmp r7, #0
	bne _081DF668
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF68E
	.align 2, 0
_081DF664: .4byte 0x03002C68
_081DF668:
	movs r5, #0
_081DF66A:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r4, r0, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r6
	bne _081DF686
	mov r0, r8
	adds r1, r6, #0
	bl FUN_081e1984
	movs r0, #0xff
	strb r0, [r4]
_081DF686:
	adds r5, #1
	cmp r5, #4
	ble _081DF66A
	movs r0, #0
_081DF68E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df698
FUN_081df698: @ 0x081DF698
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DF6AC @ =0x03002C68
	ldr r3, [r0]
	cmp r3, #0
	bne _081DF6B0
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF6D6
	.align 2, 0
_081DF6AC: .4byte 0x03002C68
_081DF6B0:
	movs r2, #0
	b _081DF6B6
_081DF6B4:
	adds r2, #1
_081DF6B6:
	cmp r2, #4
	bgt _081DF6D4
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r0, r3, r4
	adds r4, r0, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r1
	bne _081DF6B4
	adds r0, r5, #0
	bl FUN_081e1984
	movs r0, #0xff
	strb r0, [r4]
_081DF6D4:
	movs r0, #0
_081DF6D6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df6dc
FUN_081df6dc: @ 0x081DF6DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DF6F0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF6FA
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF718
	.align 2, 0
_081DF6F0: .4byte 0x03002C68
_081DF6F4:
	strb r5, [r1]
	movs r0, #1
	b _081DF718
_081DF6FA:
	movs r2, #0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r4, #1
	rsbs r4, r4, #0
_081DF706:
	adds r1, r3, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r4
	beq _081DF6F4
	adds r2, #1
	cmp r2, #4
	ble _081DF706
	movs r0, #0
_081DF718:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df720
FUN_081df720: @ 0x081DF720
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DF730 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF734
	movs r0, #0
	b _081DF754
	.align 2, 0
_081DF730: .4byte 0x03002C68
_081DF734:
	movs r2, #0
	movs r1, #0
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r3, r0, r5
_081DF73E:
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	bne _081DF74C
	adds r2, #1
_081DF74C:
	adds r1, #1
	cmp r1, #4
	ble _081DF73E
	adds r0, r2, #0
_081DF754:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df75c
FUN_081df75c: @ 0x081DF75C
	push {r4, lr}
	sub sp, #8
	bl Script_GetValue
	bl FUN_081df720
	adds r4, r0, #0
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df784
FUN_081df784: @ 0x081DF784
	push {r4, lr}
	sub sp, #8
	ldr r0, _081DF798 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF79C
	movs r4, #1
	rsbs r4, r4, #0
	b _081DF7A0
	.align 2, 0
_081DF798: .4byte 0x03002C68
_081DF79C:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
_081DF7A0:
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df7bc
FUN_081df7bc: @ 0x081DF7BC
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DF7DC @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF7E0
	lsls r0, r2, #1
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	b _081DF7E4
	.align 2, 0
_081DF7DC: .4byte 0x03002C68
_081DF7E0:
	movs r0, #1
	rsbs r0, r0, #0
_081DF7E4:
	pop {r1}
	bx r1

	thumb_func_start FUN_081df7e8
FUN_081df7e8: @ 0x081DF7E8
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DF808 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF80C
	lsls r0, r2, #1
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	b _081DF810
	.align 2, 0
_081DF808: .4byte 0x03002C68
_081DF80C:
	movs r0, #1
	rsbs r0, r0, #0
_081DF810:
	pop {r1}
	bx r1

	thumb_func_start FUN_081df814
FUN_081df814: @ 0x081DF814
	push {r4, lr}
	sub sp, #8
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _081DF860
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081DF858 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _081DF85C @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _081DF86A
	.align 2, 0
_081DF858: .4byte 0xFFFF0000
_081DF85C: .4byte 0x0000FFFF
_081DF860:
	ldr r1, _081DF88C @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_081DF86A:
	movs r0, #0x74
	movs r1, #4
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _081DF890
	mov r0, sp
	adds r1, r4, #0
	bl FUN_081df698
	b _081DF898
	.align 2, 0
_081DF88C: .4byte 0xFFFF0000
_081DF890:
	mov r0, sp
	adds r1, r4, #0
	bl FUN_081df64c
_081DF898:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df8a0
FUN_081df8a0: @ 0x081DF8A0
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DF8B8 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF8CE
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _081DF8BC
	movs r0, #1
	b _081DF8BE
	.align 2, 0
_081DF8B8: .4byte 0x03002C68
_081DF8BC:
	movs r0, #0
_081DF8BE:
	cmp r0, #0
	bne _081DF8CE
	adds r0, r1, #0
	adds r0, #0x24
	strb r2, [r0]
	movs r0, #1
	bl sound_fadeout_08240440
_081DF8CE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081df8d4
FUN_081df8d4: @ 0x081DF8D4
	push {lr}
	ldr r0, _081DF8EC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF8E6
	adds r1, r0, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
_081DF8E6:
	pop {r0}
	bx r0
	.align 2, 0
_081DF8EC: .4byte 0x03002C68

	thumb_func_start FUN_081df8f0
FUN_081df8f0: @ 0x081DF8F0
	push {lr}
	adds r1, r0, #0
	ldr r0, _081DF904 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF900
	adds r0, #0x21
	strb r1, [r0]
_081DF900:
	pop {r0}
	bx r0
	.align 2, 0
_081DF904: .4byte 0x03002C68

	thumb_func_start FUN_081df908
FUN_081df908: @ 0x081DF908
	push {lr}
	ldr r0, _081DF920 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF91A
	adds r1, r0, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
_081DF91A:
	pop {r0}
	bx r0
	.align 2, 0
_081DF920: .4byte 0x03002C68

	thumb_func_start FUN_081df924
FUN_081df924: @ 0x081DF924
	push {lr}
	ldr r0, _081DF93C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF936
	adds r1, r0, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
_081DF936:
	pop {r0}
	bx r0
	.align 2, 0
_081DF93C: .4byte 0x03002C68

	thumb_func_start FUN_081df940
FUN_081df940: @ 0x081DF940
	push {lr}
	ldr r0, _081DF958 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF952
	adds r1, r0, #0
	adds r1, #0x2b
	movs r0, #1
	strb r0, [r1]
_081DF952:
	pop {r0}
	bx r0
	.align 2, 0
_081DF958: .4byte 0x03002C68

	thumb_func_start FUN_081df95c
FUN_081df95c: @ 0x081DF95C
	push {lr}
	adds r1, r0, #0
	ldr r0, _081DF970 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF96C
	adds r0, #0x23
	strb r1, [r0]
_081DF96C:
	pop {r0}
	bx r0
	.align 2, 0
_081DF970: .4byte 0x03002C68

	thumb_func_start FUN_081df974
FUN_081df974: @ 0x081DF974
	push {lr}
	ldr r0, _081DF988 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF982
	movs r0, #1
	strb r0, [r1, #0x1e]
_081DF982:
	pop {r0}
	bx r0
	.align 2, 0
_081DF988: .4byte 0x03002C68

	thumb_func_start FUN_081df98c
FUN_081df98c: @ 0x081DF98C
	push {lr}
	ldr r0, _081DF9A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF99C
	ldrb r0, [r0, #0x1e]
	cmp r0, #0
	bne _081DF9A4
_081DF99C:
	movs r0, #0
	b _081DF9A6
	.align 2, 0
_081DF9A0: .4byte 0x03002C68
_081DF9A4:
	movs r0, #1
_081DF9A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df9ac
FUN_081df9ac: @ 0x081DF9AC
	push {r4, lr}
	sub sp, #0x20
	adds r2, r0, #0
	ldr r0, _081DF9FC @ =0x03002C68
	ldr r3, [r0]
	cmp r3, #0
	beq _081DF9F2
	movs r4, #0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	movs r4, #2
	ldrsh r0, [r2, r4]
	str r0, [sp, #4]
	movs r4, #4
	ldrsh r0, [r2, r4]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r1, _081DFA00 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #6
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	mov r0, sp
	str r0, [r1, #4]
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r0, [r0]
	bl Script_ExecById
_081DF9F2:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DF9FC: .4byte 0x03002C68
_081DFA00: .4byte 0xFFFF0000

	thumb_func_start FUN_081dfa04
FUN_081dfa04: @ 0x081DFA04
	push {lr}
	ldr r0, _081DFA14 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFA18
	ldrb r0, [r0, #0x1c]
	b _081DFA1A
	.align 2, 0
_081DFA14: .4byte 0x03002C68
_081DFA18:
	movs r0, #0
_081DFA1A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dfa20
FUN_081dfa20: @ 0x081DFA20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r6, [sp, #0x10]
	ldr r0, _081DFA50 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFA8E
	ldr r1, _081DFA54 @ =0x085AE3FA
	ldrb r0, [r1]
	str r0, [r5]
	ldrb r0, [r1, #1]
	str r0, [r2]
	ldrb r0, [r1, #2]
	str r0, [r3]
	ldrb r0, [r1, #3]
	str r0, [r6]
	cmp r4, #1
	beq _081DFA7C
	cmp r4, #1
	bgt _081DFA58
	cmp r4, #0
	beq _081DFA70
	b _081DFA8E
	.align 2, 0
_081DFA50: .4byte 0x03002C68
_081DFA54: .4byte 0x085AE3FA
_081DFA58:
	cmp r4, #2
	beq _081DFA62
	cmp r4, #3
	beq _081DFA88
	b _081DFA8E
_081DFA62:
	ldr r0, _081DFA6C @ =0x085AE3FE
	ldrb r0, [r0]
	str r0, [r5]
	b _081DFA8E
	.align 2, 0
_081DFA6C: .4byte 0x085AE3FE
_081DFA70:
	ldr r0, _081DFA78 @ =0x085AE3FE
	ldrb r0, [r0, #1]
	str r0, [r2]
	b _081DFA8E
	.align 2, 0
_081DFA78: .4byte 0x085AE3FE
_081DFA7C:
	ldr r0, _081DFA84 @ =0x085AE3FE
	ldrb r0, [r0, #2]
	str r0, [r3]
	b _081DFA8E
	.align 2, 0
_081DFA84: .4byte 0x085AE3FE
_081DFA88:
	ldr r0, _081DFA94 @ =0x085AE3FE
	ldrb r0, [r0, #3]
	str r0, [r6]
_081DFA8E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DFA94: .4byte 0x085AE3FE

	thumb_func_start FUN_081dfa98
FUN_081dfa98: @ 0x081DFA98
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081DFAFC @ =0x030001AC
	movs r1, #0
	str r1, [r0]
	ldrb r1, [r4, #0x1c]
	adds r6, r0, #0
	cmp r1, #4
	bls _081DFAB0
	ldr r1, _081DFB00 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081DFAB0:
	movs r0, #1
	str r0, [r6]
	ldrb r0, [r4, #0x1c]
	adds r1, r0, #0
	cmp r1, #2
	bls _081DFB24
	ldr r0, [r4, #0x44]
	bl FUN_08238da8
	str r0, [r4, #0x4c]
	movs r0, #2
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	bl FUN_08238e14
	str r0, [r4, #0x48]
	movs r0, #3
	str r0, [r6]
	ldrb r1, [r4, #0x1c]
	cmp r1, #5
	bls _081DFB08
	ldr r0, _081DFB04 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFB1A
	movs r2, #0x18
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _081DFB1A
	cmp r1, #0x16
	beq _081DFB1A
	cmp r1, #0x18
	beq _081DFB1A
	bl FUN_08238d84
	b _081DFB1A
	.align 2, 0
_081DFAFC: .4byte 0x030001AC
_081DFB00: .4byte 0x030047B8
_081DFB04: .4byte 0x03002C68
_081DFB08:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _081DFB1A
	cmp r1, #0x16
	beq _081DFB1A
	cmp r1, #0x18
	beq _081DFB1A
	bl FUN_08238d84
_081DFB1A:
	ldr r1, _081DFB80 @ =0x030001AC
	movs r0, #4
	str r0, [r1]
	adds r6, r1, #0
	ldrb r1, [r4, #0x1c]
_081DFB24:
	adds r5, r6, #0
	movs r0, #5
	str r0, [r5]
	adds r3, r1, #0
	cmp r3, #4
	bls _081DFBA0
	cmp r3, #0x16
	beq _081DFBA0
	cmp r3, #0x18
	beq _081DFBA0
	cmp r3, #0x19
	beq _081DFBA0
	movs r0, #6
	str r0, [r5]
	ldr r1, [r4, #0x4c]
	subs r0, #9
	cmp r1, r0
	bne _081DFB8C
	movs r2, #1
	ldr r1, _081DFB84 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #8
	str r0, [r5]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0xfe
	bhi _081DFB7A
	adds r0, #1
	strb r0, [r4, #0x1f]
	cmp r3, #4
	bls _081DFB7A
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bls _081DFB7A
	ldr r0, _081DFB88 @ =0x030047AC
	ldr r0, [r0]
	cmp r0, #0
	bne _081DFB7A
	adds r0, r4, #0
	bl FUN_081ddbdc
_081DFB7A:
	ldr r1, _081DFB80 @ =0x030001AC
	movs r0, #9
	b _081DFC0C
	.align 2, 0
_081DFB80: .4byte 0x030001AC
_081DFB84: .4byte 0x030044BC
_081DFB88: .4byte 0x030047AC
_081DFB8C:
	ldr r2, _081DFBDC @ =0x030044BC
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r4, #0x1f]
	movs r0, #0xa
	str r0, [r6]
_081DFBA0:
	ldr r5, _081DFBE0 @ =0x030001AC
	movs r0, #0xc
	str r0, [r5]
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, [r4, #0x34]
	adds r0, #1
	str r0, [r4, #0x34]
	movs r0, #0xe
	str r0, [r5]
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _081DFC08
	adds r0, r4, #0
	bl KillEntity
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	bne _081DFBE4
	movs r0, #0xf
	str r0, [r5]
	bl SoftReset_0823a928
	b _081DFC08
	.align 2, 0
_081DFBDC: .4byte 0x030044BC
_081DFBE0: .4byte 0x030001AC
_081DFBE4:
	ldr r2, _081DFBFC @ =0x000002E6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DFC00
	movs r0, #0x10
	str r0, [r5]
	ldrh r0, [r1]
	movs r1, #0
	bl Script_ExecById
	b _081DFC08
	.align 2, 0
_081DFBFC: .4byte 0x000002E6
_081DFC00:
	movs r0, #0x11
	str r0, [r5]
	bl SoftReset_0823a928
_081DFC08:
	ldr r1, _081DFC18 @ =0x030001AC
	movs r0, #0x12
_081DFC0C:
	str r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081DFC18: .4byte 0x030001AC

	thumb_func_start FUN_081dfc1c
FUN_081dfc1c: @ 0x081DFC1C
	push {lr}
	bl FUN_08238bf4
	ldr r1, _081DFC48 @ =FUN_0822db5c
	ldr r2, _081DFC4C @ =FUN_0822aaac
	ldr r3, _081DFC50 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	ldr r0, _081DFC54 @ =0x030044D0
	movs r3, #0
	str r3, [r0]
	ldr r2, _081DFC58 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _081DFC5C @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r2]
	ldr r0, _081DFC60 @ =0x03002C68
	str r3, [r0]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081DFC48: .4byte FUN_0822db5c
_081DFC4C: .4byte FUN_0822aaac
_081DFC50: .4byte FUN_0822f204
_081DFC54: .4byte 0x030044D0
_081DFC58: .4byte 0x030047A4
_081DFC5C: .4byte 0xFFFFF7FF
_081DFC60: .4byte 0x03002C68

	thumb_func_start FUN_081dfc64
FUN_081dfc64: @ 0x081DFC64
	push {r4, r5, r6, r7, lr}
	ldr r4, _081DFC74 @ =0x03002C68
	ldr r7, [r4]
	cmp r7, #0
	beq _081DFC78
	adds r0, r7, #0
	b _081DFE54
	.align 2, 0
_081DFC74: .4byte 0x03002C68
_081DFC78:
	movs r5, #0xbd
	lsls r5, r5, #2
	adds r0, r5, #0
	bl Malloc
	str r0, [r4]
	cmp r0, #0
	bne _081DFC8A
	b _081DFE28
_081DFC8A:
	adds r6, r0, #0
	adds r1, r5, #0
	bl ClearMemory
	ldr r2, _081DFDC4 @ =FUN_081dfc1c
	adds r0, r6, #0
	movs r1, #0
	bl SetEntityRoutine
	movs r4, #1
	strb r4, [r6, #0x14]
	strb r4, [r6, #0x16]
	movs r5, #0
	strh r7, [r6, #0x10]
	adds r0, r6, #0
	bl AddEntity
	ldr r0, _081DFDC8 @ =0x0300481C
	str r4, [r0]
	bl FUN_08238b04
	ldr r0, _081DFDCC @ =0x0000FFFF
	strh r0, [r6, #0x18]
	strb r5, [r6, #0x1e]
	adds r1, r6, #0
	adds r1, #0x6c
	str r1, [r6, #0x44]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r6, #0x48]
	str r0, [r6, #0x4c]
	adds r0, r6, #0
	adds r0, #0x50
	strb r5, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	movs r5, #0
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
	adds r2, r6, #0
	adds r2, #0x68
	movs r3, #0
_081DFCE8:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r0, r2, r5
	strb r3, [r0]
	adds r1, #2
	adds r5, #1
	cmp r5, #3
	ble _081DFCE8
	adds r0, r6, #0
	bl FUN_081de0dc
	adds r0, r6, #0
	bl FUN_081de090
	ldr r2, _081DFDD0 @ =FUN_081de214
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081dd9b8
	adds r1, r6, #0
	adds r1, #0x20
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x55
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081DFDD4 @ =0x000002EA
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x59
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081DFDD8 @ =0x000002E2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081DFDDC @ =0x000002DE
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x76
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x45
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081DFDE0 @ =0x000002E6
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #5
	strh r0, [r6, #0x30]
	strh r0, [r6, #0x32]
	ldr r1, _081DFDE4 @ =0x00001388
	movs r0, #0x4c
	bl Script_GetKeywordValue
	str r0, [r6, #0x3c]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081DFDE8
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #3
_081DFDB4:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _081DFDB4
	b _081DFE0E
	.align 2, 0
_081DFDC4: .4byte FUN_081dfc1c
_081DFDC8: .4byte 0x0300481C
_081DFDCC: .4byte 0x0000FFFF
_081DFDD0: .4byte FUN_081de214
_081DFDD4: .4byte 0x000002EA
_081DFDD8: .4byte 0x000002E2
_081DFDDC: .4byte 0x000002DE
_081DFDE0: .4byte 0x000002E6
_081DFDE4: .4byte 0x00001388
_081DFDE8:
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xab
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, #4
	adds r1, r6, r2
	ldr r0, _081DFE2C @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081DFE30 @ =0x0000FFFE
	strh r0, [r1]
_081DFE0E:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081DFE28
	bl FUN_0823d340
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DFE34
_081DFE28:
	movs r0, #0
	b _081DFE54
	.align 2, 0
_081DFE2C: .4byte 0x0000FFFF
_081DFE30: .4byte 0x0000FFFE
_081DFE34:
	movs r0, #0x53
	bl prepare_08231510
	cmp r0, #0
	beq _081DFE28
	bl FUN_0823d340
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	beq _081DFE28
	movs r0, #7
	bl FUN_0809c08c
_081DFE54:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dfe5c
FUN_081dfe5c: @ 0x081DFE5C
	push {lr}
	ldr r0, _081DFE70 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFE6A
	bl FUN_081dfa98
_081DFE6A:
	pop {r0}
	bx r0
	.align 2, 0
_081DFE70: .4byte 0x03002C68

	thumb_func_start FUN_081dfe74
FUN_081dfe74: @ 0x081DFE74
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r4, _081DFF04 @ =0x0000C091
	ldr r1, _081DFF08 @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r5, r7, r1
	str r0, [r5]
	ldr r1, _081DFF0C @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r6, r7, r2
	str r0, [r6]
	movs r0, #0xa
	str r0, [sp, #0xc]
	ldr r2, [r5]
	movs r4, #0
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0xc
	str r0, [sp, #0xc]
	ldr r2, [r6]
	str r4, [sp]
	str r5, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DFF10 @ =0x000092B3
	ldr r1, _081DFF14 @ =0x000026BB
	bl GetFile
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, #0x14
	str r0, [r1]
	ldr r1, _081DFF18 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DFF04: .4byte 0x0000C091
_081DFF08: .4byte 0x0000CD91
_081DFF0C: .4byte 0x0000A413
_081DFF10: .4byte 0x000092B3
_081DFF14: .4byte 0x000026BB
_081DFF18: .4byte 0x03004250

	thumb_func_start FUN_081dff1c
FUN_081dff1c: @ 0x081DFF1C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #2
	movs r1, #5
	movs r2, #0x1a
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x1a
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r5, #0
_081DFF4A:
	lsls r0, r5, #2
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r4, r4, r0
	ldr r0, [r4]
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r5, #1
	cmp r5, #1
	ble _081DFF4A
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dff7c
FUN_081dff7c: @ 0x081DFF7C
	push {r4, r5, lr}
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r5, r0, r1
	movs r4, #1
_081DFF86:
	ldm r5!, {r0}
	bl FUN_0804a210
	subs r4, #1
	cmp r4, #0
	bge _081DFF86
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dff98
FUN_081dff98: @ 0x081DFF98
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _081DFFB4 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_081DFFB4: .4byte 0x03003ED0

	thumb_func_start FUN_081dffb8
FUN_081dffb8: @ 0x081DFFB8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r7, #0x91
	movs r0, #0
	bl FUN_081dff98
	adds r6, r0, #0
	cmp r5, #0
	ble _081DFFFC
_081DFFD0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	adds r1, r0, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r6]
	adds r6, #2
	muls r0, r5, r0
	subs r4, r4, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	cmp r5, #0
	bgt _081DFFD0
_081DFFFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e0004
FUN_081e0004: @ 0x081E0004
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldr r1, _081E0064 @ =0x0000A47C
	adds r0, r6, #0
	bl FUN_0822b16c
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r4, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	movs r2, #0
	movs r3, #0
	strh r2, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #0x11
	orrs r0, r1
	str r0, [r4]
	ldr r1, _081E0068 @ =0x00000377
	adds r0, r5, r1
	strb r3, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r4, r5, r0
	str r2, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081E006C @ =0x05000002
	bl CpuSet
	movs r0, #0x79
	strh r0, [r4]
	ldr r1, _081E0070 @ =0x0000038E
	adds r5, r5, r1
	movs r0, #0x40
	strh r0, [r5]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E0064: .4byte 0x0000A47C
_081E0068: .4byte 0x00000377
_081E006C: .4byte 0x05000002
_081E0070: .4byte 0x0000038E

	thumb_func_start FUN_081e0074
FUN_081e0074: @ 0x081E0074
	push {lr}
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r0, r1
	bl FUN_0822a4e0
	pop {r0}
	bx r0

	thumb_func_start FUN_081e0084
FUN_081e0084: @ 0x081E0084
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081E00E8 @ =0x0000CB05
	ldr r1, _081E00EC @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenSpriteSetFile
	movs r7, #0
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x18
_081E00AE:
	lsls r1, r7, #1
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	strh r4, [r0]
	ldrh r2, [r0]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0x10
	bl FUN_0822f3fc
	cmp r0, #0
	bne _081E00DE
	adds r6, #0x60
	adds r7, #1
	cmp r7, #7
	ble _081E00AE
_081E00DE:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E00E8: .4byte 0x0000CB05
_081E00EC: .4byte 0x0000DCC1

	thumb_func_start FUN_081e00f0
FUN_081e00f0: @ 0x081E00F0
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0x40
	adds r0, #0x38
	movs r2, #0x80
	movs r1, #3
_081E00FC:
	strh r2, [r0]
	strh r4, [r0, #2]
	adds r0, #0x60
	subs r2, #8
	subs r1, #1
	cmp r1, #0
	bge _081E00FC
	movs r4, #0x78
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0x80
	movs r1, #3
_081E0116:
	strh r2, [r0]
	strh r4, [r0, #2]
	adds r0, #0x60
	subs r2, #8
	subs r1, #1
	cmp r1, #0
	bge _081E0116
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e012c
FUN_081e012c: @ 0x081E012C
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x20
	movs r2, #7
_081E0136:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081E0136
	pop {r0}
	bx r0

	thumb_func_start FUN_081e0148
FUN_081e0148: @ 0x081E0148
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #7
_081E0150:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E0150
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e0164
FUN_081e0164: @ 0x081E0164
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r2, #0
	lsls r7, r1, #2
	movs r2, #0
	ldr r0, _081E020C @ =0x000003E7
	cmp r5, r0
	ble _081E017E
	ldr r1, _081E0210 @ =0xFFFFFC18
_081E0176:
	adds r2, #1
	adds r5, r5, r1
	cmp r5, r0
	bgt _081E0176
_081E017E:
	lsls r4, r7, #1
	adds r0, r4, r7
	lsls r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r5, #0x63
	ble _081E01A8
_081E01A0:
	adds r2, #1
	subs r5, #0x64
	cmp r5, #0x63
	bgt _081E01A0
_081E01A8:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0xd8
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r5, #9
	ble _081E01CC
_081E01C4:
	adds r2, #1
	subs r5, #0xa
	cmp r5, #9
	bgt _081E01C4
_081E01CC:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x78
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	movs r2, #0
	cmp r5, #0
	ble _081E01F0
_081E01E8:
	adds r2, #1
	subs r5, #1
	cmp r5, #0
	bgt _081E01E8
_081E01F0:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x18
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E020C: .4byte 0x000003E7
_081E0210: .4byte 0xFFFFFC18

	thumb_func_start FUN_081e0214
FUN_081e0214: @ 0x081E0214
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	mov r8, r1
	ldr r0, _081E0298 @ =0x000003EA
	add r0, ip
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r7, r0, #2
	ldr r4, _081E029C @ =0x030046B4
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _081E02A0 @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	ldr r6, _081E02A4 @ =0x085B0200
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r3, #7
	ands r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	movs r2, #0x64
	muls r0, r2, r0
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ands r1, r3
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r7, r7, r0
	ldr r0, _081E02A8 @ =0x0000270F
	cmp r7, r0
	ble _081E0282
	adds r7, r0, #0
_081E0282:
	mov r0, ip
	mov r1, r8
	adds r2, r7, #0
	bl FUN_081e0164
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E0298: .4byte 0x000003EA
_081E029C: .4byte 0x030046B4
_081E02A0: .4byte 0x000003FF
_081E02A4: .4byte 0x085B0200
_081E02A8: .4byte 0x0000270F

	thumb_func_start FUN_081e02ac
FUN_081e02ac: @ 0x081E02AC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081E02E0 @ =0x000003EA
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081E02C6
	ldr r0, _081E02E4 @ =0x000002A5
	bl PlaySound_082406e0
_081E02C6:
	ldr r1, _081E02E8 @ =0x000003BA
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E02D8
	adds r0, r4, #0
	movs r1, #0
	bl FUN_081e0214
_081E02D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E02E0: .4byte 0x000003EA
_081E02E4: .4byte 0x000002A5
_081E02E8: .4byte 0x000003BA

	thumb_func_start FUN_081e02ec
FUN_081e02ec: @ 0x081E02EC
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E0320 @ =0x000003BA
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081E031A
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081E031A
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r1, #0
	movs r1, #0
	bl FUN_081e0164
	ldr r0, _081E0324 @ =0x00000167
	bl PlaySound_082406e0
_081E031A:
	pop {r0}
	bx r0
	.align 2, 0
_081E0320: .4byte 0x000003BA
_081E0324: .4byte 0x00000167

	thumb_func_start FUN_081e0328
FUN_081e0328: @ 0x081E0328
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081E033C @ =0x03002C68
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _081E0340
	movs r1, #1
	rsbs r1, r1, #0
	b _081E0344
	.align 2, 0
_081E033C: .4byte 0x03002C68
_081E0340:
	movs r0, #0x18
	ldrsh r1, [r1, r0]
_081E0344:
	ldr r0, [r4]
	cmp r0, #0
	bne _081E034E
	movs r0, #0
	b _081E035C
_081E034E:
	lsls r1, r1, #1
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
_081E035C:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r2, r3, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081E0384 @ =0x0000270F
	cmp r0, r1
	bls _081E0370
	strh r1, [r2]
_081E0370:
	ldrh r0, [r2]
	cmp r0, #0
	bne _081E0378
	strh r0, [r2]
_081E0378:
	ldr r1, [r4]
	cmp r1, #0
	bne _081E0388
	movs r1, #1
	rsbs r1, r1, #0
	b _081E038C
	.align 2, 0
_081E0384: .4byte 0x0000270F
_081E0388:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_081E038C:
	ldr r0, [r4]
	cmp r0, #0
	bne _081E0396
	movs r0, #0
	b _081E03A2
_081E0396:
	lsls r1, r1, #2
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
_081E03A2:
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r3, r1
	str r0, [r2]
	ldr r1, _081E03CC @ =0x0000270F
	cmp r0, r1
	ble _081E03B2
	str r1, [r2]
_081E03B2:
	ldr r0, [r2]
	ldr r1, _081E03D0 @ =0xFFFFD8F1
	cmp r0, r1
	bge _081E03BC
	str r1, [r2]
_081E03BC:
	ldr r2, _081E03D4 @ =0x000003BA
	adds r1, r3, r2
	movs r0, #0x5a
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E03CC: .4byte 0x0000270F
_081E03D0: .4byte 0xFFFFD8F1
_081E03D4: .4byte 0x000003BA

	thumb_func_start FUN_081e03d8
FUN_081e03d8: @ 0x081E03D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E049C @ =0x000003E9
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E0466
	adds r0, r6, #0
	bl FUN_081e012c
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r3, #0xf8
	lsls r3, r3, #2
	adds r4, r6, r3
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #6
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	bl FUN_081df908
	strb r5, [r7]
_081E0466:
	ldr r0, _081E04A0 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081E0474
	ldrb r1, [r0, #0x1c]
_081E0474:
	cmp r1, #0x16
	bne _081E0494
	ldr r1, _081E04A4 @ =FUN_081e04a8
	movs r2, #4
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r6, r3
	str r1, [r0]
	ldr r0, _081E049C @ =0x000003E9
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
_081E0494:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E049C: .4byte 0x000003E9
_081E04A0: .4byte 0x03002C68
_081E04A4: .4byte FUN_081e04a8

	thumb_func_start FUN_081e04a8
FUN_081e04a8: @ 0x081E04A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E0500 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E04E4
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #6
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r3, _081E0504 @ =0x000003EA
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E04E4:
	ldr r0, _081E0504 @ =0x000003EA
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0x3c
	bne _081E0538
	bl FUN_082413b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E050C
	ldr r1, _081E0508 @ =FUN_081e0660
	movs r2, #8
	b _081E0514
	.align 2, 0
_081E0500: .4byte 0x000003E9
_081E0504: .4byte 0x000003EA
_081E0508: .4byte FUN_081e0660
_081E050C:
	bl FUN_081df924
	ldr r1, _081E0530 @ =FUN_081e0544
	movs r2, #5
_081E0514:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _081E0534 @ =0x000003E9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	b _081E053C
	.align 2, 0
_081E0530: .4byte FUN_081e0544
_081E0534: .4byte 0x000003E9
_081E0538:
	adds r0, #1
	strh r0, [r1]
_081E053C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e0544
FUN_081e0544: @ 0x081E0544
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081E057C @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081E0556
	ldrb r1, [r0, #0x1c]
_081E0556:
	cmp r1, #0x18
	bne _081E0576
	ldr r1, _081E0580 @ =FUN_081e0588
	movs r2, #6
	movs r4, #0xf4
	lsls r4, r4, #2
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _081E0584 @ =0x000003E9
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
_081E0576:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E057C: .4byte 0x03002C68
_081E0580: .4byte FUN_081e0588
_081E0584: .4byte 0x000003E9

	thumb_func_start FUN_081e0588
FUN_081e0588: @ 0x081E0588
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08241400
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E05A0
	ldr r1, _081E059C @ =FUN_081e05cc
	movs r2, #7
	b _081E05A4
	.align 2, 0
_081E059C: .4byte FUN_081e05cc
_081E05A0:
	ldr r1, _081E05C4 @ =FUN_081e0660
	movs r2, #8
_081E05A4:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081E05C8 @ =0x000003E9
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E05C4: .4byte FUN_081e0660
_081E05C8: .4byte 0x000003E9

	thumb_func_start FUN_081e05cc
FUN_081e05cc: @ 0x081E05CC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081E0630 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E060A
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0804a2f8
	ldr r0, _081E0634 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r0, _081E0638 @ =0x000003EA
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E060A:
	ldr r1, _081E0638 @ =0x000003EA
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x78
	bne _081E0640
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E063C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _081E064A
	.align 2, 0
_081E0630: .4byte 0x000003E9
_081E0634: .4byte 0x000002AE
_081E0638: .4byte 0x000003EA
_081E063C: .4byte 0x0000FFFF
_081E0640:
	cmp r0, #0x8c
	bls _081E064A
	bl FUN_081df940
	b _081E0654
_081E064A:
	ldr r2, _081E065C @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E0654:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E065C: .4byte 0x000003EA

	thumb_func_start FUN_081e0660
FUN_081e0660: @ 0x081E0660
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E06B0 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E06A0
	bl FUN_08238bf4
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #8
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #5
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _081E06B4 @ =0x000003EA
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E06A0:
	ldr r2, _081E06B4 @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E06B8
	adds r0, #1
	strh r0, [r1]
	b _081E06C8
	.align 2, 0
_081E06B0: .4byte 0x000003E9
_081E06B4: .4byte 0x000003EA
_081E06B8:
	ldr r0, _081E06D0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E06D4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E06C8
	bl SoftReset_0823a928
_081E06C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E06D0: .4byte 0x030044E0
_081E06D4: .4byte 0x0000030F

	thumb_func_start FUN_081e06d8
FUN_081e06d8: @ 0x081E06D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _081E0794 @ =0x000003E9
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E06EA
	b _081E07EA
_081E06EA:
	adds r0, r5, #0
	bl FUN_081dff7c
	adds r0, r5, #0
	bl FUN_081e012c
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	movs r7, #0
	str r7, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r4, _081E0798 @ =0x030046A0
	ldr r0, [r4]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r2, r0, r3
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r6, r5, r0
	ldr r1, [r2]
	ldr r0, [r6]
	adds r1, r1, r0
	ldr r0, _081E079C @ =0x0000270F
	cmp r1, r0
	ble _081E0730
	adds r1, r0, #0
_081E0730:
	str r1, [r2]
	ldr r0, [r4]
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bge _081E073E
	str r7, [r1]
_081E073E:
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r2, #0xd
	movs r3, #2
	bl FUN_081dffb8
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #8
	str r1, [sp]
	movs r1, #1
	movs r2, #0xb
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	movs r3, #0xf5
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r6]
	cmp r0, #0
	bne _081E07A0
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0804a2f8
	b _081E07B6
	.align 2, 0
_081E0794: .4byte 0x000003E9
_081E0798: .4byte 0x030046A0
_081E079C: .4byte 0x0000270F
_081E07A0:
	cmp r0, #0
	ble _081E07AE
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0804a2f8
	b _081E07B6
_081E07AE:
	ldr r0, [r4]
	movs r1, #3
	bl FUN_0804a2f8
_081E07B6:
	movs r0, #0xf8
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, [r4]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	cmp r2, #0
	bge _081E07CC
	rsbs r2, r2, #0
_081E07CC:
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0804a3e4
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r3, _081E07FC @ =0x000003EA
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E0800 @ =0x000003E9
	adds r0, r5, r1
	strb r2, [r0]
_081E07EA:
	ldr r2, _081E07FC @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #9
	bhi _081E0804
	adds r0, #1
	strh r0, [r1]
	b _081E0832
	.align 2, 0
_081E07FC: .4byte 0x000003EA
_081E0800: .4byte 0x000003E9
_081E0804:
	ldr r0, _081E083C @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0840 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E0832
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _081E0844 @ =FUN_081e03d8
	movs r2, #3
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _081E0848 @ =0x000003E9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
_081E0832:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E083C: .4byte 0x030044E0
_081E0840: .4byte 0x0000030F
_081E0844: .4byte FUN_081e03d8
_081E0848: .4byte 0x000003E9

	thumb_func_start FUN_081e084c
FUN_081e084c: @ 0x081E084C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081E08A8 @ =0x000003E9
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081E086E
	ldr r3, _081E08AC @ =0x000003BE
	adds r1, r5, r3
	movs r3, #0
	movs r2, #0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081E08B0 @ =0x000003EA
	adds r0, r5, r1
	strh r2, [r0]
	strb r3, [r4]
_081E086E:
	ldr r3, _081E08B0 @ =0x000003EA
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0x3c
	bhi _081E087A
	b _081E09CA
_081E087A:
	movs r4, #0xef
	lsls r4, r4, #2
	adds r6, r5, r4
	ldrh r0, [r6]
	cmp r0, #0
	beq _081E0924
	ldr r1, _081E08AC @ =0x000003BE
	adds r7, r5, r1
	ldrh r4, [r7]
	subs r3, r0, r4
	cmp r3, #0
	bge _081E08BC
	adds r3, r3, r4
	ldr r2, _081E08B4 @ =0x030046A0
	ldr r1, [r2]
	ldr r4, _081E08B8 @ =0x00000912
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r6]
	subs r0, r0, r3
	b _081E08D0
	.align 2, 0
_081E08A8: .4byte 0x000003E9
_081E08AC: .4byte 0x000003BE
_081E08B0: .4byte 0x000003EA
_081E08B4: .4byte 0x030046A0
_081E08B8: .4byte 0x00000912
_081E08BC:
	ldr r2, _081E0910 @ =0x030046A0
	ldr r1, [r2]
	ldr r0, _081E0914 @ =0x00000912
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r1, [r7]
	subs r0, r0, r1
_081E08D0:
	strh r0, [r6]
	adds r3, r2, #0
	ldr r0, [r3]
	ldr r2, _081E0914 @ =0x00000912
	adds r1, r0, r2
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bge _081E08E6
	movs r0, #0
	strh r0, [r1]
_081E08E6:
	ldr r0, [r3]
	adds r2, r0, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _081E0918 @ =0x0000270F
	cmp r0, r1
	ble _081E08F6
	strh r1, [r2]
_081E08F6:
	ldr r3, _081E091C @ =0x000003EA
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081E0990
	ldr r0, _081E0920 @ =0x000002A5
	bl PlaySound_082406e0
	b _081E0990
	.align 2, 0
_081E0910: .4byte 0x030046A0
_081E0914: .4byte 0x00000912
_081E0918: .4byte 0x0000270F
_081E091C: .4byte 0x000003EA
_081E0920: .4byte 0x000002A5
_081E0924:
	ldr r0, _081E0958 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E095C @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E0990
	ldr r0, _081E0960 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r4, r0, r1
	cmp r0, #0
	bne _081E0940
	movs r4, #0
_081E0940:
	movs r0, #0xdd
	bl PlaySound_082406e0
	cmp r4, #0
	beq _081E0950
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E0968
_081E0950:
	ldr r1, _081E0964 @ =FUN_081e03d8
	movs r2, #3
	b _081E096C
	.align 2, 0
_081E0958: .4byte 0x030044E0
_081E095C: .4byte 0x0000030F
_081E0960: .4byte 0x03002C68
_081E0964: .4byte FUN_081e03d8
_081E0968:
	ldr r1, _081E0988 @ =FUN_081e06d8
	movs r2, #2
_081E096C:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r4, _081E098C @ =0x000003E9
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	b _081E09F8
	.align 2, 0
_081E0988: .4byte FUN_081e06d8
_081E098C: .4byte 0x000003E9
_081E0990:
	movs r2, #1
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E09A6
	movs r0, #1
	b _081E09A8
_081E09A6:
	movs r0, #0
_081E09A8:
	cmp r0, #0
	bne _081E09CA
	ldr r0, _081E0A00 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0A04 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E09CA
	ldr r4, _081E0A08 @ =0x000003BE
	adds r1, r5, r4
	ldrh r0, [r1]
	lsls r0, r0, #3
	strh r0, [r1]
	movs r1, #1
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081E09CA:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_081e0164
	ldr r0, _081E0A0C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _081E0A10 @ =0x00000912
	adds r0, r0, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081e0164
	ldr r0, _081E0A14 @ =0x000003EA
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E09F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E0A00: .4byte 0x030044E0
_081E0A04: .4byte 0x0000030F
_081E0A08: .4byte 0x000003BE
_081E0A0C: .4byte 0x030046A0
_081E0A10: .4byte 0x00000912
_081E0A14: .4byte 0x000003EA

	thumb_func_start FUN_081e0a18
FUN_081e0a18: @ 0x081E0A18
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E0A54 @ =0x000003E9
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E0A32
	ldr r1, _081E0A58 @ =0x000003EA
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E0A32:
	ldr r3, _081E0A5C @ =0x000003BA
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _081E0A64
	ldr r1, _081E0A60 @ =FUN_081e084c
	movs r2, #1
	adds r3, #0x16
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _081E0A54 @ =0x000003E9
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0x18
	adds r0, r4, r3
	strb r2, [r0]
	b _081E0A8A
	.align 2, 0
_081E0A54: .4byte 0x000003E9
_081E0A58: .4byte 0x000003EA
_081E0A5C: .4byte 0x000003BA
_081E0A60: .4byte FUN_081e084c
_081E0A64:
	ldr r0, _081E0A90 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0A94 @ =0x0000030B
	ands r0, r1
	cmp r0, #0
	beq _081E0A74
	movs r0, #1
	strh r0, [r2]
_081E0A74:
	adds r0, r4, #0
	bl FUN_081e02ac
	adds r0, r4, #0
	bl FUN_081e02ec
	ldr r0, _081E0A98 @ =0x000003EA
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E0A8A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E0A90: .4byte 0x030044E0
_081E0A94: .4byte 0x0000030B
_081E0A98: .4byte 0x000003EA

	thumb_func_start FUN_081e0a9c
FUN_081e0a9c: @ 0x081E0A9C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081E0AB4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081E0AC8
_081E0AB4:
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081E0AC6
	adds r0, r4, #0
	bl _call_via_r1
_081E0AC6:
	movs r0, #1
_081E0AC8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e0ad0
FUN_081e0ad0: @ 0x081E0AD0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dff7c
	adds r0, r4, #0
	bl FUN_081e0148
	adds r0, r4, #0
	bl FUN_081e0074
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e0aec
FUN_081e0aec: @ 0x081E0AEC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081E0B0C
	bl FUN_0823d340
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E0B26
_081E0B0C:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081E0B2C
	bl FUN_0823d340
	movs r3, #0xf6
	lsls r3, r3, #2
	adds r1, r4, r3
	str r0, [r1]
	cmp r0, #0
	bne _081E0B2C
_081E0B26:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E0BB6
_081E0B2C:
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081dfe74
	adds r0, r4, #0
	bl FUN_081dff1c
	adds r0, r4, #0
	bl FUN_081e0084
	adds r0, r4, #0
	bl FUN_081e00f0
	ldr r0, _081E0BC0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _081E0BC4 @ =0x00000912
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081e0164
	adds r0, r4, #0
	bl FUN_081e0004
	adds r0, r4, #0
	bl FUN_081e0328
	ldr r1, _081E0BC8 @ =FUN_081e0a18
	movs r2, #0
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081E0BCC @ =0x000003E9
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E0BD0 @ =0x0000FFFF
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #1
_081E0BB6:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E0BC0: .4byte 0x030046A0
_081E0BC4: .4byte 0x00000912
_081E0BC8: .4byte FUN_081e0a18
_081E0BCC: .4byte 0x000003E9
_081E0BD0: .4byte 0x0000FFFF

	thumb_func_start FUN_081e0bd4
FUN_081e0bd4: @ 0x081E0BD4
	push {r4, lr}
	movs r1, #0xfb
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E0C0C
	ldr r1, _081E0C04 @ =FUN_081e0a9c
	ldr r2, _081E0C08 @ =FUN_081e0ad0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e0aec
	cmp r0, #0
	bge _081E0C0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E0C0E
	.align 2, 0
_081E0C04: .4byte FUN_081e0a9c
_081E0C08: .4byte FUN_081e0ad0
_081E0C0C:
	adds r0, r4, #0
_081E0C0E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e0c14
FUN_081e0c14: @ 0x081E0C14
	ldr r1, _081E0C1C @ =0x030001B0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E0C1C: .4byte 0x030001B0

	thumb_func_start FUN_081e0c20
FUN_081e0c20: @ 0x081E0C20
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r7, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081E0C4E
	cmp r1, #0
	blt _081E0C4E
	ldr r0, _081E0C54 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081E0C4E
	ldr r0, _081E0C58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E0C5C
_081E0C4E:
	movs r6, #0
	b _081E0C6A
	.align 2, 0
_081E0C54: .4byte 0x030046A8
_081E0C58: .4byte 0x030046AC
_081E0C5C:
	ldr r0, _081E0C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r4
_081E0C6A:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0C80
	adds r0, #4
	b _081E0C8C
	.align 2, 0
_081E0C7C: .4byte 0x030046A4
_081E0C80:
	ldr r0, _081E0CA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0C8C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0CE4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0CCC
	adds r0, #4
	b _081E0CD8
	.align 2, 0
_081E0CA8: .4byte 0x030046A4
_081E0CAC:
	ldr r4, _081E0CC8 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r6, r6, r1
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	strh r0, [r7, #0x10]
	ldr r0, [r4]
	b _081E0E2A
	.align 2, 0
_081E0CC8: .4byte 0x030046A4
_081E0CCC:
	ldr r0, _081E0CFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0CD8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0CE4
	b _081E0EB2
_081E0CE4:
	movs r0, #0
	mov sb, r0
	ldr r1, _081E0CFC @ =0x030046A4
	mov r8, r1
_081E0CEC:
	mov r2, sb
	cmp r2, #1
	beq _081E0D46
	cmp r2, #1
	bgt _081E0D00
	cmp r2, #0
	beq _081E0D0E
	b _081E0EA6
	.align 2, 0
_081E0CFC: .4byte 0x030046A4
_081E0D00:
	mov r0, sb
	cmp r0, #2
	beq _081E0DC2
	cmp r0, #3
	bne _081E0D0C
	b _081E0E3C
_081E0D0C:
	b _081E0EA6
_081E0D0E:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0D20
	adds r0, #4
	b _081E0D2C
_081E0D20:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0D2C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081E0D38
	b _081E0EA6
_081E0D38:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _081E0DF6
	b _081E0DFA
_081E0D46:
	ldr r5, _081E0D64 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0D68
	adds r0, #4
	b _081E0D72
	.align 2, 0
_081E0D64: .4byte 0x030046A4
_081E0D68:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0D72:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081E0D7E
	b _081E0EA6
_081E0D7E:
	ldr r5, _081E0D9C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0DA0
	adds r0, #4
	b _081E0DAA
	.align 2, 0
_081E0D9C: .4byte 0x030046A4
_081E0DA0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0DAA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r6, r6, r1
	b _081E0E1C
_081E0DC2:
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0DD4
	adds r0, #4
	b _081E0DE0
_081E0DD4:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0DE0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0EA6
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0DFA
_081E0DF6:
	adds r0, #4
	b _081E0E06
_081E0DFA:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E06:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	adds r6, r4, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
_081E0E1C:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	strh r0, [r7, #0x10]
	mov r1, r8
	ldr r0, [r1]
_081E0E2A:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	strh r0, [r7, #0x14]
	b _081E0EB2
_081E0E3C:
	ldr r5, _081E0E58 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0E5C
	adds r0, #4
	b _081E0E66
	.align 2, 0
_081E0E58: .4byte 0x030046A4
_081E0E5C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E66:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0EA6
	ldr r5, _081E0E8C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0E90
	adds r0, #4
	b _081E0E9A
	.align 2, 0
_081E0E8C: .4byte 0x030046A4
_081E0E90:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E9A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	b _081E0CAC
_081E0EA6:
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	bgt _081E0EB2
	b _081E0CEC
_081E0EB2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e0ec0
FUN_081e0ec0: @ 0x081E0EC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldrh r0, [r0, #0x10]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081E0EF2
	cmp r1, #0
	blt _081E0EF2
	ldr r0, _081E0EF8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081E0EF2
	ldr r0, _081E0EFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E0F00
_081E0EF2:
	movs r6, #0
	b _081E0F0E
	.align 2, 0
_081E0EF8: .4byte 0x030046A8
_081E0EFC: .4byte 0x030046AC
_081E0F00:
	ldr r0, _081E0F34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r4
_081E0F0E:
	ldr r0, _081E0F38 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081E0F3C @ =0x00000934
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081E0F22
	b _081E10AA
_081E0F22:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0F60
	adds r0, #4
	b _081E0F6C
	.align 2, 0
_081E0F34: .4byte 0x030046A4
_081E0F38: .4byte 0x030046A0
_081E0F3C: .4byte 0x00000934
_081E0F40:
	ldr r4, _081E0F5C @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r6, r6, r1
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x10]
	ldr r0, [r4]
	b _081E1056
	.align 2, 0
_081E0F5C: .4byte 0x030046A4
_081E0F60:
	ldr r0, _081E0F90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0F6C:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081E0F78
	b _081E10AA
_081E0F78:
	movs r7, #0
	ldr r2, _081E0F90 @ =0x030046A4
	mov sb, r2
	mov sl, r1
_081E0F80:
	cmp r7, #1
	beq _081E0FCE
	cmp r7, #1
	bgt _081E0F94
	cmp r7, #0
	beq _081E0F9E
	b _081E10A2
	.align 2, 0
_081E0F90: .4byte 0x030046A4
_081E0F94:
	cmp r7, #2
	beq _081E1012
	cmp r7, #3
	beq _081E106A
	b _081E10A2
_081E0F9E:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0FB0
	adds r0, #4
	b _081E0FBC
_081E0FB0:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0FBC:
	ldrh r0, [r0, #2]
	mov r2, sl
	ands r0, r2
	cmp r0, #0
	bne _081E10A2
	adds r6, r4, #0
	mov r1, sb
	ldr r0, [r1]
	b _081E1040
_081E0FCE:
	ldr r5, _081E0FEC @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0FF0
	adds r0, #4
	b _081E0FFA
	.align 2, 0
_081E0FEC: .4byte 0x030046A4
_081E0FF0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0FFA:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	mov r2, sb
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r6, r6, r1
	b _081E1046
_081E1012:
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E1024
	adds r0, #4
	b _081E1030
_081E1024:
	mov r2, sb
	ldr r0, [r2]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E1030:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	adds r6, r4, #0
	mov r2, sb
	ldr r0, [r2]
_081E1040:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
_081E1046:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x10]
	mov r2, sb
	ldr r0, [r2]
_081E1056:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x14]
	b _081E10AA
_081E106A:
	ldr r5, _081E1088 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E108C
	adds r0, #4
	b _081E1096
	.align 2, 0
_081E1088: .4byte 0x030046A4
_081E108C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E1096:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	b _081E0F40
_081E10A2:
	adds r7, #1
	cmp r7, #3
	bgt _081E10AA
	b _081E0F80
_081E10AA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e10b8
FUN_081e10b8: @ 0x081E10B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_081e0ec0
	adds r0, r4, #0
	bl FUN_081e0c20
	ldrh r1, [r4, #0x10]
	ldr r0, _081E1110 @ =0xFFFFFF00
	adds r5, r0, #0
	ands r5, r1
	strh r5, [r4, #0x10]
	ldrh r1, [r4, #0x14]
	ands r0, r1
	strh r0, [r4, #0x14]
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _081E1120
	ldr r3, _081E1114 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081E1118 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _081E111C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x80
	movs r2, #0x7f
	ands r0, r2
	adds r1, r1, r0
	strh r1, [r4, #0x10]
	adds r2, r3, #0
	b _081E113C
	.align 2, 0
_081E1110: .4byte 0xFFFFFF00
_081E1114: .4byte 0x030046B8
_081E1118: .4byte 0x000003FF
_081E111C: .4byte 0x0203B400
_081E1120:
	ldr r2, _081E1158 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E115C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E1160 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, r5, r0
	strh r0, [r4, #0x10]
_081E113C:
	cmp r6, #2
	bgt _081E1164
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E115C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E1160 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	lsls r0, r6, #2
	adds r0, r0, r6
	b _081E117C
	.align 2, 0
_081E1158: .4byte 0x030046B8
_081E115C: .4byte 0x000003FF
_081E1160: .4byte 0x0203B400
_081E1164:
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E11B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E11BC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	subs r1, r6, #3
	lsls r0, r1, #2
	adds r0, r0, r1
_081E117C:
	lsls r0, r0, #4
	movs r1, #0x3f
	ands r2, r1
	adds r0, r0, r2
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
	strh r0, [r4, #0x14]
	adds r6, r4, #0
	adds r6, #0x10
	ldrh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E11B2
	cmp r1, #0
	blt _081E11B2
	ldr r0, _081E11C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E11B2
	ldr r0, _081E11C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E11C8
_081E11B2:
	movs r5, #0
	b _081E11D6
	.align 2, 0
_081E11B8: .4byte 0x000003FF
_081E11BC: .4byte 0x0203B400
_081E11C0: .4byte 0x030046A8
_081E11C4: .4byte 0x030046AC
_081E11C8:
	ldr r0, _081E11E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081E11D6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E11EC
	adds r0, #4
	b _081E11F8
	.align 2, 0
_081E11E8: .4byte 0x030046A4
_081E11EC:
	ldr r0, _081E120C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E11F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E1210
	cmp r2, #2
	beq _081E1214
	b _081E1218
	.align 2, 0
_081E120C: .4byte 0x030046A4
_081E1210:
	ldrb r0, [r6, #4]
	b _081E1216
_081E1214:
	ldrb r0, [r6]
_081E1216:
	subs r1, r1, r0
_081E1218:
	strh r1, [r4, #0x12]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1220
FUN_081e1220: @ 0x081E1220
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r0, #0
	strb r2, [r5]
	strb r0, [r5, #1]
	strb r0, [r5, #2]
	strb r0, [r5, #3]
	strh r0, [r5, #6]
	str r0, [r5, #0x20]
	adds r0, r5, #0
	adds r0, #0x24
	adds r3, #0x20
	adds r1, r3, #0
	movs r2, #1
	bl FUN_0822a470
	adds r4, r5, #0
	adds r4, #0x50
	adds r1, r5, #0
	adds r1, #0x40
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080136b4
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1260
FUN_081e1260: @ 0x081E1260
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0822a4e0
	adds r4, #0x50
	adds r0, r4, #0
	bl FUN_080138fc
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e127c
FUN_081e127c: @ 0x081E127C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	strb r5, [r4, #1]
	strb r5, [r4, #2]
	strb r5, [r4, #3]
	ldr r0, [r4, #0x24]
	movs r6, #1
	orrs r0, r6
	str r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x50
	bl FUN_080136b4
	str r5, [r4, #0x20]
	strh r5, [r4, #6]
	strb r6, [r4, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e12a4
FUN_081e12a4: @ 0x081E12A4
	push {lr}
	adds r2, r0, #0
	adds r2, #0x6c
	movs r3, #0
_081E12AC:
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r1
	bne _081E12B8
	adds r0, r2, #0
	b _081E12C2
_081E12B8:
	adds r3, #1
	adds r2, #0x90
	cmp r3, #4
	ble _081E12AC
	movs r0, #0
_081E12C2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e12c8
FUN_081e12c8: @ 0x081E12C8
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	adds r3, r1, #0
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq _081E12F4
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081E12F4
	adds r4, r1, #0
	movs r2, #0xc
	ldr r1, _081E12FC @ =0x03002BC0
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _081E1300
_081E12F4:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E1338
	.align 2, 0
_081E12FC: .4byte 0x03002BC0
_081E1300:
	str r4, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	ldr r1, _081E1340 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5, #0x1c]
	bl Script_ExecById
_081E1338:
	add sp, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E1340: .4byte 0xFFFF0000

	thumb_func_start FUN_081e1344
FUN_081e1344: @ 0x081E1344
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	ldr r5, [r0, #0x18]
	movs r0, #3
	ands r5, r0
	mov sl, r5
	adds r0, r5, #4
	cmp r5, r0
	bge _081E1426
	movs r0, #0x40
	adds r0, r0, r4
	mov sb, r0
	movs r1, #0x18
	adds r1, r1, r4
	mov ip, r1
_081E136E:
	movs r7, #3
	ands r7, r5
	lsls r2, r7, #2
	mov r0, r8
	adds r0, #0x5c
	adds r0, r0, r2
	ldr r3, [r0]
	cmp r3, #0
	beq _081E141C
	movs r0, #0xc
	ldr r1, _081E13EC @ =0x03002BC0
	adds r1, r2, r1
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _081E141C
	movs r1, #0x80
	lsls r1, r1, #0x15
	ldr r0, [r3, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081E141C
	lsls r0, r7, #3
	mov r6, r8
	adds r2, r0, r6
	adds r2, #0x3c
	mov r0, ip
	movs r6, #2
	ldrsh r1, [r0, r6]
	movs r6, #2
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	str r1, [sp]
	mov r0, sb
	movs r6, #2
	ldrsh r1, [r0, r6]
	movs r6, #0x2e
	ldrsh r0, [r3, r6]
	subs r0, r1, r0
	cmp r0, #0
	bge _081E13C2
	rsbs r0, r0, #0
_081E13C2:
	cmp r0, #0x7f
	bgt _081E13F0
	movs r0, #0x18
	ldrsh r1, [r4, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _081E13D6
	rsbs r0, r0, #0
_081E13D6:
	cmp r0, #0xe
	bgt _081E13F0
	movs r0, #0x18
	rsbs r0, r0, #0
	ldr r6, [sp]
	cmp r6, r0
	blt _081E13F0
	cmp r6, #4
	bgt _081E13F0
	movs r0, #1
	b _081E13F2
	.align 2, 0
_081E13EC: .4byte 0x03002BC0
_081E13F0:
	movs r0, #0
_081E13F2:
	cmp r0, #0
	beq _081E141C
	strb r7, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_081df6dc
	mov r0, r8
	adds r1, r4, #0
	bl FUN_081e12c8
	ldr r0, _081E1418 @ =FUN_081e169c
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	movs r0, #1
	strb r0, [r4, #4]
	b _081E1428
	.align 2, 0
_081E1418: .4byte FUN_081e169c
_081E141C:
	adds r5, #1
	mov r0, sl
	adds r0, #4
	cmp r5, r0
	blt _081E136E
_081E1426:
	movs r0, #0
_081E1428:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1438
FUN_081e1438: @ 0x081E1438
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r4, r2, #0
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _081E144E
	movs r0, #0
	strb r0, [r5, #4]
	movs r0, #1
	b _081E1450
_081E144E:
	movs r0, #0
_081E1450:
	cmp r0, #0
	beq _081E147C
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	adds r0, r5, #0
	adds r0, #0x50
	bl FUN_08013698
	ldr r0, [r5, #0x40]
	ldr r1, [r5, #0x44]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081e10b8
	ldr r0, _081E14E4 @ =0x00000276
	bl PlaySound_082406e0
_081E147C:
	ldrb r0, [r5, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r5, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	blt _081E14AA
	strb r2, [r5, #2]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E149E
	strb r2, [r5, #3]
_081E149E:
	ldrb r1, [r5, #3]
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _081E14A8
	adds r1, #4
_081E14A8:
	strh r1, [r5, #0x34]
_081E14AA:
	adds r0, r5, #0
	adds r0, #0x40
	adds r1, r5, #0
	adds r1, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r3, [r5, #6]
	movs r4, #6
	str r4, [sp]
	bl FUN_08237970
	ldr r2, _081E14E8 @ =0x085B0A08
	ldrh r0, [r5, #6]
	lsls r0, r0, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _081E14EC
	asrs r2, r0, #0xc
	b _081E14F2
	.align 2, 0
_081E14E4: .4byte 0x00000276
_081E14E8: .4byte 0x085B0A08
_081E14EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081E14F2:
	adds r1, r5, #0
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _081E1516
	ldr r0, _081E1520 @ =FUN_081e1524
	str r0, [r5, #0x20]
	movs r0, #0
	strh r0, [r5, #6]
	movs r0, #1
	strb r0, [r5, #4]
_081E1516:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E1520: .4byte FUN_081e1524

	thumb_func_start FUN_081e1524
FUN_081e1524: @ 0x081E1524
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r3, #4]
	cmp r0, #0
	beq _081E1532
	movs r0, #0
	strb r0, [r3, #4]
_081E1532:
	ldrb r0, [r3, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r3, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	blt _081E1560
	strb r2, [r3, #2]
	ldrb r0, [r3, #3]
	adds r0, #1
	strb r0, [r3, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E1554
	strb r2, [r3, #3]
_081E1554:
	ldrb r1, [r3, #3]
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _081E155E
	adds r1, #4
_081E155E:
	strh r1, [r3, #0x34]
_081E1560:
	ldr r2, _081E157C @ =0x085B0A08
	ldrh r0, [r3, #6]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081E1580
	asrs r1, r0, #0xc
	b _081E1586
	.align 2, 0
_081E157C: .4byte 0x085B0A08
_081E1580:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081E1586:
	ldrh r0, [r3, #0x12]
	adds r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x42
	strh r0, [r1]
	ldrh r0, [r3, #6]
	adds r0, #1
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _081E15AA
	ldr r0, _081E15B0 @ =FUN_081e15b4
	str r0, [r3, #0x20]
	movs r0, #0
	strh r0, [r3, #6]
	movs r0, #1
	strb r0, [r3, #4]
_081E15AA:
	pop {r0}
	bx r0
	.align 2, 0
_081E15B0: .4byte FUN_081e15b4

	thumb_func_start FUN_081e15b4
FUN_081e15b4: @ 0x081E15B4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081E15C8
	movs r0, #0
	strb r0, [r4, #4]
	movs r0, #1
	b _081E15CA
_081E15C8:
	movs r0, #0
_081E15CA:
	adds r5, r4, #0
	adds r5, #0x40
	cmp r0, #0
	beq _081E15FC
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_082342cc
	strb r0, [r4, #1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E15F4
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x50
	bl FUN_080136b4
	b _081E15FC
_081E15F4:
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
_081E15FC:
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r4, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	blt _081E162A
	strb r2, [r4, #2]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E161E
	strb r2, [r4, #3]
_081E161E:
	ldrb r1, [r4, #3]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _081E1628
	adds r1, #4
_081E1628:
	strh r1, [r4, #0x34]
_081E162A:
	adds r6, r4, #0
	adds r6, #0x18
	adds r2, r5, #0
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E164C
	asrs r0, r0, #8
	b _081E1652
_081E164C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1652:
	strh r0, [r6]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1664
	asrs r0, r0, #8
	b _081E166A
_081E1664:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E166A:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E167E
	asrs r1, r0, #8
	b _081E1684
_081E167E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E1684:
	subs r0, r3, r1
	strh r0, [r6, #2]
	adds r0, r3, r1
	strh r0, [r6, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_081e1344
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e169c
FUN_081e169c: @ 0x081E169C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081E16AE
	movs r0, #0
	strb r0, [r4, #4]
	movs r0, #1
	b _081E16B0
_081E16AE:
	movs r0, #0
_081E16B0:
	cmp r0, #0
	beq _081E16DE
	movs r0, #0
	strb r0, [r4, #1]
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldr r0, _081E16CC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081E16D0
	movs r0, #1
	rsbs r0, r0, #0
	b _081E16D4
	.align 2, 0
_081E16CC: .4byte 0x03002C68
_081E16D0:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_081E16D4:
	cmp r1, r0
	bne _081E16DE
	ldr r0, _081E1730 @ =0x00000275
	bl PlaySound_082406e0
_081E16DE:
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r4, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	blt _081E170C
	strb r2, [r4, #2]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E1700
	strb r2, [r4, #3]
_081E1700:
	ldrb r1, [r4, #3]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _081E170A
	adds r1, #4
_081E170A:
	strh r1, [r4, #0x34]
_081E170C:
	adds r1, r4, #0
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, #0x18
	strh r0, [r1]
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _081E172A
	adds r0, r4, #0
	bl FUN_081e127c
_081E172A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1730: .4byte 0x00000275

	thumb_func_start FUN_081e1734
FUN_081e1734: @ 0x081E1734
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #4
	mov ip, r0
	movs r6, #0
_081E173E:
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x5c
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081E17B2
	lsls r0, r6, #3
	adds r3, r0, r7
	adds r3, #0x3c
	adds r5, r1, #0
	adds r5, #0x2c
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1772
	asrs r0, r0, #8
	b _081E1778
_081E1772:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1778:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E178A
	asrs r0, r0, #8
	b _081E1790
_081E178A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1790:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E17A4
	asrs r1, r0, #8
	b _081E17AA
_081E17A4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E17AA:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_081E17B2:
	adds r6, #1
	cmp r6, ip
	blt _081E173E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e17c0
FUN_081e17c0: @ 0x081E17C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x6c
	movs r6, #0
_081E17CC:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _081E17EA
	cmp r7, #0
	bne _081E17DE
	adds r0, r5, #0
	bl FUN_081e1734
	movs r7, #1
_081E17DE:
	ldr r3, [r4, #0x20]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
_081E17EA:
	adds r6, #1
	adds r4, #0x90
	cmp r6, #4
	ble _081E17CC
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1800
FUN_081e1800: @ 0x081E1800
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x6c
_081E180A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081e1260
	cmp r0, #0
	bge _081E181C
	movs r0, #1
	rsbs r0, r0, #0
	b _081E182C
_081E181C:
	adds r4, #0x90
	adds r6, #1
	cmp r6, #4
	ble _081E180A
	movs r1, #0
	ldr r0, _081E1834 @ =0x030001B0
	str r1, [r0]
	movs r0, #0
_081E182C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E1834: .4byte 0x030001B0

	thumb_func_start FUN_081e1838
FUN_081e1838: @ 0x081E1838
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _081E1868 @ =0x030001B0
	str r7, [r0]
	movs r0, #0
	str r0, [r7, #0x18]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r7, #0x1c]
	adds r0, r7, #0
	adds r0, #0x20
	ldr r1, _081E186C @ =0x00002712
	bl FUN_0822b16c
	cmp r0, #0
	bne _081E1870
_081E1860:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E1934
	.align 2, 0
_081E1868: .4byte 0x030001B0
_081E186C: .4byte 0x00002712
_081E1870:
	ldr r0, _081E18E4 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r6, r0, r1
	cmp r0, #0
	bne _081E1880
	movs r6, #0
_081E1880:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x6c
_081E1886:
	adds r0, r6, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_081e1220
	cmp r0, #0
	blt _081E1860
	adds r4, #0x90
	adds r5, #1
	cmp r5, #4
	ble _081E1886
	movs r5, #0
	ldr r2, _081E18E8 @ =0x03002BE0
	mov r8, r2
	movs r0, #0x5c
	adds r0, r0, r7
	mov ip, r0
_081E18AC:
	lsls r1, r5, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	add r1, ip
	str r2, [r1]
	cmp r2, #0
	beq _081E192C
	lsls r0, r5, #3
	adds r3, r0, r7
	adds r3, #0x3c
	adds r6, r2, #0
	adds r6, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E18EC
	asrs r0, r0, #8
	b _081E18F2
	.align 2, 0
_081E18E4: .4byte 0x03002C68
_081E18E8: .4byte 0x03002BE0
_081E18EC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E18F2:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1904
	asrs r0, r0, #8
	b _081E190A
_081E1904:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E190A:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E191E
	asrs r1, r0, #8
	b _081E1924
_081E191E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E1924:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_081E192C:
	adds r5, #1
	cmp r5, #3
	ble _081E18AC
	movs r0, #0
_081E1934:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e1940
FUN_081e1940: @ 0x081E1940
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E197C
	ldr r1, _081E1974 @ =FUN_081e17c0
	ldr r2, _081E1978 @ =FUN_081e1800
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081e1838
	cmp r0, #0
	bge _081E197C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E197E
	.align 2, 0
_081E1974: .4byte FUN_081e17c0
_081E1978: .4byte FUN_081e1800
_081E197C:
	adds r0, r4, #0
_081E197E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1984
FUN_081e1984: @ 0x081E1984
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E19CC @ =0x030001B0
	ldr r0, [r0]
	cmp r0, #0
	beq _081E19D4
	bl FUN_081e12a4
	adds r3, r0, #0
	cmp r3, #0
	beq _081E19D4
	movs r0, #0xff
	strb r0, [r3]
	movs r2, #0
	strb r2, [r3, #1]
	strb r2, [r3, #2]
	strb r2, [r3, #3]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x40]
	str r1, [r3, #0x44]
	adds r1, r3, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #8]
	str r1, [r3, #0xc]
	ldr r0, _081E19D0 @ =FUN_081e1438
	str r0, [r3, #0x20]
	strh r2, [r3, #6]
	movs r0, #1
	strb r0, [r3, #4]
	movs r0, #0
	b _081E19D8
	.align 2, 0
_081E19CC: .4byte 0x030001B0
_081E19D0: .4byte FUN_081e1438
_081E19D4:
	movs r0, #1
	rsbs r0, r0, #0
_081E19D8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e19e0
FUN_081e19e0: @ 0x081E19E0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19e4
FUN_081e19e4: @ 0x081E19E4
	push {lr}
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	pop {r0}
	bx r0

	thumb_func_start FUN_081e19f0
FUN_081e19f0: @ 0x081E19F0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19f4
FUN_081e19f4: @ 0x081E19F4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19f8
FUN_081e19f8: @ 0x081E19F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19fc
FUN_081e19fc: @ 0x081E19FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	bl FUN_080478f0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_08047b8c
	movs r0, #0
	bl FUN_08047a28
	ldr r0, _081E1A3C @ =0x000026BB
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	adds r1, r4, #0
	adds r1, #0x61
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081E1A40 @ =0xFFFFFBFF
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1A3C: .4byte 0x000026BB
_081E1A40: .4byte 0xFFFFFBFF

	thumb_func_start FUN_081e1a44
FUN_081e1a44: @ 0x081E1A44
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081E1A88 @ =0x0000C091
	ldr r1, _081E1A8C @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x58]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1A88: .4byte 0x0000C091
_081E1A8C: .4byte 0x0000A413

	thumb_func_start FUN_081e1a90
FUN_081e1a90: @ 0x081E1A90
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_08047864
	movs r0, #0
	bl FUN_0822b644
	bl FUN_08237e98
	bl FUN_08237eb4
	adds r3, r0, #0
	ldr r2, _081E1AF0 @ =FUN_081e1cec
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r2, r4, #0
	adds r2, #0x69
	movs r0, #1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x6a
	movs r0, #0
	strb r0, [r1]
	adds r5, r1, #0
	cmp r3, #0
	bge _081E1AF8
	subs r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E1AF4 @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r3, [r4, #0x4c]
	movs r0, #1
	strb r0, [r2]
	movs r0, #5
	strb r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1B3A
	.align 2, 0
_081E1AF0: .4byte FUN_081e1cec
_081E1AF4: .4byte FUN_081e1f80
_081E1AF8:
	cmp r3, #0
	bne _081E1B0A
	movs r0, #0x20
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl FUN_08238114
	b _081E1B16
_081E1B0A:
	movs r0, #0x40
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl FUN_08238120
_081E1B16:
	str r0, [r4, #0x70]
	bl FUN_08238480
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6d
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x6c
	movs r1, #0
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
_081E1B3A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1b40
FUN_081e1b40: @ 0x081E1B40
	push {r4, lr}
	adds r4, r0, #0
	cmp r2, #0
	beq _081E1B58
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E1B60
_081E1B58:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #4
	strb r0, [r1]
_081E1B60:
	ldr r2, _081E1B8C @ =FUN_081e1ff8
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1B8C: .4byte FUN_081e1ff8

	thumb_func_start FUN_081e1b90
FUN_081e1b90: @ 0x081E1B90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1BA8
	movs r0, #1
	b _081E1BAA
_081E1BA8:
	movs r0, #0
_081E1BAA:
	adds r7, r0, #0
	cmp r7, #0
	bne _081E1C80
	movs r0, #0
	mov r8, r0
	bl FUN_0823812c
	adds r5, r0, #0
	cmp r5, #0
	beq _081E1BC8
	cmp r5, #1
	beq _081E1BE4
	adds r1, r6, #0
	adds r1, #0x6b
	b _081E1C0E
_081E1BC8:
	bl FUN_082380f4
	mov r8, r0
	bl FUN_08238114
	ldr r1, [r6, #0x70]
	cmp r1, r0
	beq _081E1BF4
	adds r4, r6, #0
	adds r4, #0x6b
	strb r5, [r4]
	bl FUN_08238114
	b _081E1C0A
_081E1BE4:
	bl FUN_082380d4
	mov r8, r0
	bl FUN_08238120
	ldr r1, [r6, #0x70]
	cmp r1, r0
	bne _081E1C00
_081E1BF4:
	adds r1, r6, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _081E1C0E
_081E1C00:
	adds r4, r6, #0
	adds r4, #0x6b
	strb r7, [r4]
	bl FUN_08238120
_081E1C0A:
	str r0, [r6, #0x70]
	adds r1, r4, #0
_081E1C0E:
	ldrb r0, [r1]
	cmp r0, #0xa
	bhi _081E1C2C
	mov r0, r8
	cmp r0, #0
	bne _081E1C30
	adds r1, r6, #0
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _081E1C38
_081E1C2C:
	movs r0, #1
	b _081E1C82
_081E1C30:
	adds r1, r6, #0
	adds r1, #0x6c
	movs r0, #0
	strb r0, [r1]
_081E1C38:
	bl FUN_08238094
	cmp r0, #0
	blt _081E1C2C
	bl FUN_0823812c
	cmp r0, #0
	blt _081E1C80
	bl FUN_0823812c
	adds r1, r6, #0
	adds r1, #0x6d
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r4, r1, #0
	cmp r0, r2
	beq _081E1C80
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1C6A
	movs r0, #1
	b _081E1C6C
_081E1C6A:
	movs r0, #0
_081E1C6C:
	cmp r0, #0
	bne _081E1C2C
	bl FUN_0823812c
	strb r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	orrs r0, r1
	str r0, [r6, #0x64]
_081E1C80:
	movs r0, #0
_081E1C82:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1c8c
FUN_081e1c8c: @ 0x081E1C8C
	push {lr}
	adds r2, r0, #0
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _081E1CAE
	adds r0, r2, #0
	bl FUN_08238538
	cmp r0, #0
	ble _081E1CA6
	movs r0, #1
	b _081E1CB2
_081E1CA6:
	cmp r0, #0
	blt _081E1CAE
	movs r0, #0
	b _081E1CB2
_081E1CAE:
	movs r0, #1
	rsbs r0, r0, #0
_081E1CB2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e1cb8
FUN_081e1cb8: @ 0x081E1CB8
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, [r4]
	cmp r0, #0
	blt _081E1CD0
	bl FUN_082384f4
	cmp r0, #0
	bne _081E1CDE
	movs r0, #1
	b _081E1CE4
_081E1CD0:
	adds r0, r2, #0
	movs r1, #0x10
	bl FUN_082384b0
	str r0, [r4]
	cmp r0, #0
	blt _081E1CE2
_081E1CDE:
	movs r0, #2
	b _081E1CE4
_081E1CE2:
	movs r0, #0
_081E1CE4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e1cec
FUN_081e1cec: @ 0x081E1CEC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1CFE
	movs r0, #0
	strb r0, [r1]
_081E1CFE:
	adds r0, r2, #0
	bl FUN_081e1d7c
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1d08
FUN_081e1d08: @ 0x081E1D08
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1D1A
	movs r0, #0
	strb r0, [r1]
_081E1D1A:
	movs r1, #1
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1D28
	movs r0, #1
	b _081E1D2A
_081E1D28:
	movs r0, #0
_081E1D2A:
	cmp r0, #0
	beq _081E1D72
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x50
	bl FUN_081e1cb8
	cmp r0, #1
	bne _081E1D72
	ldr r1, [r4, #0x78]
	cmp r1, #0
	beq _081E1D4A
	ldr r0, [r4, #0x74]
	bl _call_via_r1
_081E1D4A:
	movs r0, #0
	strh r0, [r4, #0x3c]
	subs r0, #2
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x50]
	ldr r2, _081E1D78 @ =FUN_081e1cec
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1D72:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1D78: .4byte FUN_081e1cec

	thumb_func_start FUN_081e1d7c
FUN_081e1d7c: @ 0x081E1D7C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	ldr r1, [r4, #0x64]
	bl FUN_081e1c8c
	cmp r0, #0
	beq _081E1D96
	cmp r0, #0
	ble _081E1E24
	cmp r0, #1
	beq _081E1D9E
	b _081E1E24
_081E1D96:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x50]
	b _081E1E24
_081E1D9E:
	ldrh r0, [r4, #0x3c]
	adds r1, r0, #0
	cmp r1, #6
	bne _081E1DAA
	movs r0, #1
	b _081E1DAC
_081E1DAA:
	movs r0, #0
_081E1DAC:
	cmp r0, #0
	beq _081E1DB4
	movs r0, #0x82
	b _081E1DF8
_081E1DB4:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bne _081E1DC0
	movs r0, #1
	b _081E1DC2
_081E1DC0:
	movs r0, #0
_081E1DC2:
	cmp r0, #0
	beq _081E1DCC
	movs r0, #0x81
	lsls r0, r0, #1
	b _081E1DF8
_081E1DCC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _081E1DD8
	movs r0, #1
	b _081E1DDA
_081E1DD8:
	movs r0, #0
_081E1DDA:
	cmp r0, #0
	beq _081E1DE8
	ldr r0, _081E1DE4 @ =0x00000202
	b _081E1DF8
	.align 2, 0
_081E1DE4: .4byte 0x00000202
_081E1DE8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _081E1DF4
	movs r0, #1
	b _081E1DF6
_081E1DF4:
	movs r0, #0
_081E1DF6:
	movs r0, #2
_081E1DF8:
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	ldr r2, _081E1E20 @ =FUN_081e1e2c
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	subs r0, #5
	str r0, [r4, #0x50]
	movs r0, #1
	b _081E1E26
	.align 2, 0
_081E1E20: .4byte FUN_081e1e2c
_081E1E24:
	movs r0, #0
_081E1E26:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1e2c
FUN_081e1e2c: @ 0x081E1E2C
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1E3E
	movs r0, #0
	strb r0, [r1]
_081E1E3E:
	movs r1, #2
	ldr r0, [r4, #0x64]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _081E1E5A
	movs r0, #1
	b _081E1E5C
_081E1E5A:
	movs r0, #0
_081E1E5C:
	cmp r0, #0
	beq _081E1EA0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #1
	strh r0, [r4, #0x3c]
	ldr r0, _081E1E98 @ =0x030046A0
	ldr r2, [r0]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x40]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x44]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x48]
_081E1E8C:
	ldr r2, _081E1E9C @ =FUN_081e1d08
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	b _081E1F10
	.align 2, 0
_081E1E98: .4byte 0x030046A0
_081E1E9C: .4byte FUN_081e1d08
_081E1EA0:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1EB2
	movs r0, #1
	b _081E1EB4
_081E1EB2:
	movs r0, #0
_081E1EB4:
	cmp r0, #0
	beq _081E1EDC
	ldr r1, _081E1ED4 @ =0xFFFFFEFF
	ands r1, r2
	str r1, [r4, #0x64]
	movs r0, #0
	strh r0, [r4, #0x3c]
	ldr r0, _081E1ED8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [r4, #0x40]
	b _081E1E8C
	.align 2, 0
_081E1ED4: .4byte 0xFFFFFEFF
_081E1ED8: .4byte 0x030046A0
_081E1EDC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E1EEA
	movs r0, #1
	b _081E1EEC
_081E1EEA:
	movs r0, #0
_081E1EEC:
	cmp r0, #0
	beq _081E1F34
	ldr r0, _081E1F2C @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r4, #0x64]
	movs r0, #2
	strh r0, [r4, #0x3c]
	bl FUN_08243104
	str r0, [r4, #0x40]
	bl FUN_08243140
	str r0, [r4, #0x44]
	ldr r2, _081E1F30 @ =FUN_081e1d08
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
_081E1F10:
	str r2, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1F74
	.align 2, 0
_081E1F2C: .4byte 0xFFFFFDFF
_081E1F30: .4byte FUN_081e1d08
_081E1F34:
	ldr r2, [r4, #0x7c]
	cmp r2, #0
	beq _081E1F44
	ldr r0, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x3c
	bl _call_via_r2
_081E1F44:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1F56
	movs r0, #1
	b _081E1F58
_081E1F56:
	movs r0, #0
_081E1F58:
	cmp r0, #0
	bne _081E1F74
	ldr r1, _081E1F7C @ =FUN_081e1cec
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	str r1, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1F74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1F7C: .4byte FUN_081e1cec

	thumb_func_start FUN_081e1f80
FUN_081e1f80: @ 0x081E1F80
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E1FD6
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl FUN_08047a28
	movs r0, #1
	bl FUN_080477e4
	movs r0, #1
	bl sound_fadeout_08240440
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E1FD6:
	adds r1, r5, #0
	adds r1, #0x62
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E1FE6
	adds r0, #1
	strh r0, [r1]
	b _081E1FF0
_081E1FE6:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r5, #0x64]
	orrs r0, r1
	str r0, [r5, #0x64]
_081E1FF0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1ff8
FUN_081e1ff8: @ 0x081E1FF8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E204E
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl FUN_08047a28
	movs r0, #1
	bl FUN_080477e4
	movs r0, #1
	bl sound_fadeout_08240440
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E204E:
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0x9c
	bne _081E2072
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E20D0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081E2072:
	ldrh r0, [r4]
	cmp r0, #0xb4
	bls _081E20C0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r5, #0
	adds r0, #0x80
	ldr r1, [r0]
	cmp r1, #0
	beq _081E20A0
	adds r0, r5, #0
	bl _call_via_r1
_081E20A0:
	bl FUN_0824172c
	ldr r0, _081E20D4 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E20BA
	movs r1, #0
	bl Script_ExecById
_081E20BA:
	adds r0, r5, #0
	bl KillEntity
_081E20C0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E20D0: .4byte 0x0000FFFF
_081E20D4: .4byte 0x0300481C

	thumb_func_start FUN_081e20d8
FUN_081e20d8: @ 0x081E20D8
	push {lr}
	adds r1, r0, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E20E8
	movs r0, #0
	strb r0, [r1]
_081E20E8:
	pop {r0}
	bx r0

	thumb_func_start FUN_081e20ec
FUN_081e20ec: @ 0x081E20EC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08241704
	ldr r1, _081E210C @ =0x0300481C
	movs r0, #1
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2110
	movs r0, #1
	b _081E2112
	.align 2, 0
_081E210C: .4byte 0x0300481C
_081E2110:
	movs r0, #0
_081E2112:
	cmp r0, #0
	bne _081E211C
	ldr r1, _081E2130 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081E211C:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E2134
	movs r0, #1
	b _081E2136
	.align 2, 0
_081E2130: .4byte 0x030047B8
_081E2134:
	movs r0, #0
_081E2136:
	cmp r0, #0
	beq _081E2148
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21A6
	adds r0, r4, #0
	bl _call_via_r1
	b _081E21A6
_081E2148:
	ldr r1, _081E215C @ =0x030047B8
	movs r0, #1
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081E2160
	movs r0, #1
	b _081E2162
	.align 2, 0
_081E215C: .4byte 0x030047B8
_081E2160:
	movs r0, #0
_081E2162:
	cmp r0, #0
	beq _081E21B0
	bl FUN_0823849c
	adds r0, r4, #0
	bl FUN_081e1b90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E21B0
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r2, _081E21AC @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	bl FUN_08237f54
_081E21A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E21BE
	.align 2, 0
_081E21AC: .4byte FUN_081e1f80
_081E21B0:
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21BC
	adds r0, r4, #0
	bl _call_via_r1
_081E21BC:
	movs r0, #1
_081E21BE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e21c4
FUN_081e21c4: @ 0x081E21C4
	push {lr}
	bl FUN_08237f54
	ldr r1, _081E21D8 @ =0x03002C6C
	movs r0, #0
	str r0, [r1]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081E21D8: .4byte 0x03002C6C

	thumb_func_start FUN_081e21dc
FUN_081e21dc: @ 0x081E21DC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	bl sound_082402f8
	movs r5, #1
	rsbs r5, r5, #0
	str r5, [r4, #0x50]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081E2200
	bl FUN_0823d340
	str r0, [r4, #0x54]
	cmp r0, #0
	beq _081E221C
_081E2200:
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0x6e
	movs r5, #0
	strh r0, [r1]
	ldr r0, _081E2224 @ =0x00001770
	movs r1, #1
	bl FUN_081d9d38
	cmp r0, #0
	bne _081E2228
_081E221C:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E226A
	.align 2, 0
_081E2224: .4byte 0x00001770
_081E2228:
	ldr r1, _081E2270 @ =FUN_081e1a90
	ldr r2, _081E2274 @ =FUN_081e1b40
	adds r0, r4, #0
	bl FUN_081d9d88
	adds r0, r4, #0
	bl FUN_081e1a44
	adds r0, r4, #0
	bl FUN_081e19fc
	ldr r0, _081E2278 @ =0x03002C6C
	str r4, [r0]
	str r5, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x80
	str r5, [r0]
	str r5, [r4, #0x78]
	str r5, [r4, #0x74]
	ldr r2, _081E227C @ =FUN_081e20d8
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #7
	strb r0, [r1]
	movs r0, #1
_081E226A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2270: .4byte FUN_081e1a90
_081E2274: .4byte FUN_081e1b40
_081E2278: .4byte 0x03002C6C
_081E227C: .4byte FUN_081e20d8

	thumb_func_start FUN_081e2280
FUN_081e2280: @ 0x081E2280
	push {r4, lr}
	ldr r0, _081E22B4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E22C2
	movs r0, #2
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E22C0
	ldr r1, _081E22B8 @ =FUN_081e20ec
	ldr r2, _081E22BC @ =FUN_081e21c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e21dc
	cmp r0, #0
	bge _081E22C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E22C2
	.align 2, 0
_081E22B4: .4byte 0x03002C6C
_081E22B8: .4byte FUN_081e20ec
_081E22BC: .4byte FUN_081e21c4
_081E22C0:
	adds r0, r4, #0
_081E22C2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e22c8
FUN_081e22c8: @ 0x081E22C8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [r5, #0x50]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081E22EA
	bl FUN_0823d340
	str r0, [r5, #0x54]
	cmp r0, #0
	bne _081E22EA
	adds r0, r4, #0
	b _081E2322
_081E22EA:
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x6e
	movs r4, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081e1a44
	adds r0, r5, #0
	bl FUN_081e19fc
	ldr r0, _081E2328 @ =0x03002C6C
	str r5, [r0]
	str r4, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0x80
	str r4, [r0]
	str r4, [r5, #0x78]
	str r4, [r5, #0x74]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_081e1a90
	movs r0, #1
_081E2322:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2328: .4byte 0x03002C6C

	thumb_func_start FUN_081e232c
FUN_081e232c: @ 0x081E232C
	push {r4, lr}
	ldr r0, _081E2360 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E236E
	movs r0, #2
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E236C
	ldr r1, _081E2364 @ =FUN_081e20ec
	ldr r2, _081E2368 @ =FUN_081e21c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e22c8
	cmp r0, #0
	bge _081E236C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E236E
	.align 2, 0
_081E2360: .4byte 0x03002C6C
_081E2364: .4byte FUN_081e20ec
_081E2368: .4byte FUN_081e21c4
_081E236C:
	adds r0, r4, #0
_081E236E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2374
FUN_081e2374: @ 0x081E2374
	ldr r1, _081E237C @ =0x03002C6C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E237C: .4byte 0x03002C6C

	thumb_func_start FUN_081e2380
FUN_081e2380: @ 0x081E2380
	push {lr}
	ldr r0, _081E2398 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E23A2
	movs r1, #3
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E239C
	movs r0, #1
	b _081E239E
	.align 2, 0
_081E2398: .4byte 0x03002C6C
_081E239C:
	movs r0, #0
_081E239E:
	cmp r0, #0
	bne _081E23A6
_081E23A2:
	movs r0, #0
	b _081E23A8
_081E23A6:
	movs r0, #1
_081E23A8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e23ac
FUN_081e23ac: @ 0x081E23AC
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E23C0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E23BC
	str r1, [r0, #0x74]
	str r1, [r0, #0x7c]
_081E23BC:
	pop {r0}
	bx r0
	.align 2, 0
_081E23C0: .4byte 0x03002C6C

	thumb_func_start FUN_081e23c4
FUN_081e23c4: @ 0x081E23C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E23E0 @ =0x03002C6C
	ldr r3, [r0]
	cmp r3, #0
	beq _081E23DA
	str r4, [r3, #0x7c]
	adds r0, r3, #0
	adds r0, #0x80
	str r1, [r0]
	str r2, [r3, #0x78]
_081E23DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E23E0: .4byte 0x03002C6C

	thumb_func_start FUN_081e23e4
FUN_081e23e4: @ 0x081E23E4
	push {lr}
	ldr r0, _081E23F4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E23F8
	movs r0, #1
	rsbs r0, r0, #0
	b _081E2412
	.align 2, 0
_081E23F4: .4byte 0x03002C6C
_081E23F8:
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2406
	movs r0, #1
	b _081E2408
_081E2406:
	movs r0, #0
_081E2408:
	cmp r0, #0
	bne _081E2410
	movs r0, #0
	b _081E2412
_081E2410:
	movs r0, #1
_081E2412:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e2418
FUN_081e2418: @ 0x081E2418
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E242C @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E2430
	adds r0, #0x60
	strb r1, [r0]
	movs r0, #0
	b _081E2434
	.align 2, 0
_081E242C: .4byte 0x03002C6C
_081E2430:
	movs r0, #1
	rsbs r0, r0, #0
_081E2434:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2438
FUN_081e2438: @ 0x081E2438
	push {lr}
	ldr r0, _081E2448 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E244C
	adds r0, #0x60
	ldrb r0, [r0]
	b _081E244E
	.align 2, 0
_081E2448: .4byte 0x03002C6C
_081E244C:
	movs r0, #0
_081E244E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e2454
FUN_081e2454: @ 0x081E2454
	push {lr}
	ldr r0, _081E2470 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E247A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2474
	movs r0, #1
	b _081E2476
	.align 2, 0
_081E2470: .4byte 0x03002C6C
_081E2474:
	movs r0, #0
_081E2476:
	cmp r0, #0
	bne _081E247E
_081E247A:
	movs r0, #0
	b _081E2480
_081E247E:
	movs r0, #1
_081E2480:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2484
FUN_081e2484: @ 0x081E2484
	push {lr}
	ldr r0, _081E24A0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E24AE
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24A4
	movs r0, #1
	b _081E24A6
	.align 2, 0
_081E24A0: .4byte 0x03002C6C
_081E24A4:
	movs r0, #0
_081E24A6:
	cmp r0, #0
	bne _081E24AE
	movs r0, #0
	b _081E24B0
_081E24AE:
	movs r0, #1
_081E24B0:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e24b4
FUN_081e24b4: @ 0x081E24B4
	push {lr}
	ldr r0, _081E24D0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E2506
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24D4
	movs r0, #1
	b _081E24D6
	.align 2, 0
_081E24D0: .4byte 0x03002C6C
_081E24D4:
	movs r0, #0
_081E24D6:
	cmp r0, #0
	bne _081E2506
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E250C @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	str r3, [r2, #0x4c]
	adds r1, r2, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2506:
	pop {r0}
	bx r0
	.align 2, 0
_081E250C: .4byte FUN_081e1f80

	thumb_func_start FUN_081e2510
FUN_081e2510: @ 0x081E2510
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081E2530 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E253E
	adds r3, r0, #0
	ldr r1, _081E2534 @ =0x00001003
	ldr r0, [r3, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2538
	movs r0, #1
	b _081E253A
	.align 2, 0
_081E2530: .4byte 0x03002C6C
_081E2534: .4byte 0x00001003
_081E2538:
	movs r0, #0
_081E253A:
	cmp r0, #0
	beq _081E2542
_081E253E:
	movs r0, #0
	b _081E25CE
_081E2542:
	cmp r4, #3
	bne _081E2558
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	ldr r0, [r5, #4]
	str r0, [r3, #0x44]
	ldr r0, [r5, #8]
_081E2552:
	str r0, [r3, #0x48]
_081E2554:
	strh r2, [r3, #0x3e]
	b _081E25AA
_081E2558:
	cmp r4, #4
	bne _081E256A
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0xc]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x10]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x14]
	b _081E2552
_081E256A:
	cmp r4, #5
	bne _081E257C
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0x18]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x1c]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x20]
	b _081E2552
_081E257C:
	cmp r4, #0xa
	bne _081E2588
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E2588:
	cmp r4, #0xb
	bne _081E2590
	strh r4, [r3, #0x3c]
	b _081E2554
_081E2590:
	cmp r4, #0xc
	bne _081E259C
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E259C:
	cmp r4, #6
	beq _081E25A8
	cmp r4, #7
	beq _081E25A8
	cmp r4, #8
	bne _081E25CC
_081E25A8:
	strh r4, [r3, #0x3c]
_081E25AA:
	ldr r2, _081E25D4 @ =FUN_081e1d08
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x64]
	ands r0, r1
	str r2, [r3, #0x4c]
	adds r0, r3, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r3, #0x64]
	orrs r0, r1
	str r0, [r3, #0x64]
_081E25CC:
	movs r0, #1
_081E25CE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E25D4: .4byte FUN_081e1d08

	thumb_func_start FUN_081e25d8
FUN_081e25d8: @ 0x081E25D8
	push {lr}
	ldr r0, _081E25EC @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E25E6
	bl KillEntity
_081E25E6:
	pop {r0}
	bx r0
	.align 2, 0
_081E25EC: .4byte 0x03002C6C

	thumb_func_start FUN_081e25f0
FUN_081e25f0: @ 0x081E25F0
	push {lr}
	ldr r0, _081E2608 @ =0x03002C6C
	ldr r2, [r0]
	cmp r2, #0
	beq _081E2604
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2604:
	pop {r0}
	bx r0
	.align 2, 0
_081E2608: .4byte 0x03002C6C

	thumb_func_start FUN_081e260c
FUN_081e260c: @ 0x081E260C
	push {lr}
	ldr r0, _081E2624 @ =0x03002C6C
	ldr r2, [r0]
	cmp r2, #0
	beq _081E2620
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2620:
	pop {r0}
	bx r0
	.align 2, 0
_081E2624: .4byte 0x03002C6C

	thumb_func_start FUN_081e2628
FUN_081e2628: @ 0x081E2628
	push {r4, r5, r6, lr}
	movs r1, #0xaf
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	ldr r3, _081E2730 @ =0x00000AF2
	adds r2, r0, r3
	movs r1, #1
	strh r1, [r2]
	ldr r6, _081E2734 @ =0x00000AF4
	adds r2, r0, r6
	movs r1, #2
	strh r1, [r2]
	ldr r1, _081E2738 @ =0x00000AF6
	adds r2, r0, r1
	movs r1, #3
	strh r1, [r2]
	ldr r2, _081E273C @ =0x00000AF8
	adds r1, r0, r2
	movs r5, #4
	strh r5, [r1]
	adds r3, #8
	adds r1, r0, r3
	movs r4, #5
	strh r4, [r1]
	adds r6, #8
	adds r2, r0, r6
	movs r1, #6
	strh r1, [r2]
	ldr r1, _081E2740 @ =0x00000AFE
	adds r2, r0, r1
	movs r1, #7
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #8
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #9
	strh r1, [r2]
	ldr r1, _081E2744 @ =0x00000B04
	adds r2, r0, r1
	movs r1, #0xb
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0xc
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0xd
	strh r1, [r2]
	ldr r1, _081E2748 @ =0x00000B0A
	adds r2, r0, r1
	movs r1, #0xe
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0xf
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x10
	strh r1, [r2]
	movs r1, #0xb1
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0x11
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x12
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x13
	strh r1, [r2]
	ldr r1, _081E274C @ =0x00000B16
	adds r2, r0, r1
	movs r1, #0x14
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x16
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x17
	strh r1, [r2]
	ldr r1, _081E2750 @ =0x00000B1C
	adds r2, r0, r1
	movs r1, #0x18
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x19
	strh r1, [r2]
	adds r6, #0x14
	adds r2, r0, r6
	movs r1, #0x15
	strh r1, [r2]
	movs r1, #0xb2
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0x3c
	strh r1, [r2]
	ldr r2, _081E2754 @ =0x00000B22
	adds r1, r0, r2
	movs r2, #0x41
	strh r2, [r1]
	adds r3, #6
	adds r1, r0, r3
	strh r2, [r1]
	subs r6, #8
	adds r3, r0, r6
	strh r2, [r3]
	adds r6, #2
	adds r1, r0, r6
	strh r2, [r1]
	ldr r2, _081E2758 @ =0x00000B2A
	adds r1, r0, r2
	strh r5, [r1]
	adds r6, #4
	adds r0, r0, r6
	strh r4, [r0]
	movs r0, #0x40
	strh r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E2730: .4byte 0x00000AF2
_081E2734: .4byte 0x00000AF4
_081E2738: .4byte 0x00000AF6
_081E273C: .4byte 0x00000AF8
_081E2740: .4byte 0x00000AFE
_081E2744: .4byte 0x00000B04
_081E2748: .4byte 0x00000B0A
_081E274C: .4byte 0x00000B16
_081E2750: .4byte 0x00000B1C
_081E2754: .4byte 0x00000B22
_081E2758: .4byte 0x00000B2A

	thumb_func_start FUN_081e275c
FUN_081e275c: @ 0x081E275C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081E27D8 @ =0x0000C091
	ldr r1, _081E27DC @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	str r0, [r6, #0x1c]
	ldr r1, _081E27E0 @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	str r0, [r6, #0x20]
	movs r4, #1
	str r4, [sp, #0xc]
	ldr r2, [r6, #0x1c]
	movs r5, #0
	str r5, [sp]
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #3
	str r0, [sp, #0xc]
	ldr r2, [r6, #0x20]
	str r5, [sp]
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081E27E4 @ =0x000092B3
	ldr r1, _081E27E8 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldr r1, _081E27EC @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E27D8: .4byte 0x0000C091
_081E27DC: .4byte 0x0000CD91
_081E27E0: .4byte 0x0000A413
_081E27E4: .4byte 0x000092B3
_081E27E8: .4byte 0x000026BB
_081E27EC: .4byte 0x03004250

	thumb_func_start FUN_081e27f0
FUN_081e27f0: @ 0x081E27F0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r4, _081E284C @ =0x0000CB05
	ldr r1, _081E2850 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081E2854 @ =0x00000AE8
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	bl OpenSpriteSetFile
	ldr r1, _081E2858 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081E285C @ =0x00000AEC
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x24
	adds r0, r5, r2
	bl OpenSpriteSetFile
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _081E2860 @ =0x05000002
	bl CpuSet
	movs r6, #0
_081E283A:
	cmp r6, #0xf
	bgt _081E2868
	movs r1, #0xaf
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r2, [r0]
	ldr r0, _081E2864 @ =0x00000AA8
	b _081E2910
	.align 2, 0
_081E284C: .4byte 0x0000CB05
_081E2850: .4byte 0x0000DCC1
_081E2854: .4byte 0x00000AE8
_081E2858: .4byte 0x0000B343
_081E285C: .4byte 0x00000AEC
_081E2860: .4byte 0x05000002
_081E2864: .4byte 0x00000AA8
_081E2868:
	cmp r6, #0x14
	bgt _081E28D4
	adds r0, r6, #0
	subs r0, #0x10
	cmp r0, #4
	bhi _081E28C8
	lsls r0, r0, #2
	ldr r1, _081E2880 @ =_081E2884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E2880: .4byte _081E2884
_081E2884: @ jump table
	.4byte _081E2898 @ case 0
	.4byte _081E28A0 @ case 1
	.4byte _081E28A8 @ case 2
	.4byte _081E28B0 @ case 3
	.4byte _081E28BC @ case 4
_081E2898:
	ldr r1, _081E289C @ =0x00000B18
	b _081E28BE
	.align 2, 0
_081E289C: .4byte 0x00000B18
_081E28A0:
	ldr r2, _081E28A4 @ =0x00000B1A
	b _081E28B2
	.align 2, 0
_081E28A4: .4byte 0x00000B1A
_081E28A8:
	ldr r1, _081E28AC @ =0x00000B1C
	b _081E28BE
	.align 2, 0
_081E28AC: .4byte 0x00000B1C
_081E28B0:
	ldr r2, _081E28B8 @ =0x00000B1E
_081E28B2:
	adds r0, r5, r2
	ldrh r2, [r0]
	b _081E28CA
	.align 2, 0
_081E28B8: .4byte 0x00000B1E
_081E28BC:
	ldr r1, _081E28C4 @ =0x00000B2E
_081E28BE:
	adds r0, r5, r1
	ldrh r2, [r0]
	b _081E28CA
	.align 2, 0
_081E28C4: .4byte 0x00000B2E
_081E28C8:
	movs r2, #0
_081E28CA:
	ldr r0, _081E28D0 @ =0x00000AA8
	b _081E2910
	.align 2, 0
_081E28D0: .4byte 0x00000AA8
_081E28D4:
	cmp r6, #0x15
	bgt _081E28EC
	lsls r1, r6, #1
	movs r2, #0xaf
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _081E28E8 @ =0x00000AC8
	b _081E292E
	.align 2, 0
_081E28E8: .4byte 0x00000AC8
_081E28EC:
	cmp r6, #0x19
	bgt _081E28F8
	ldr r1, _081E28F4 @ =0x00000B22
	b _081E290A
	.align 2, 0
_081E28F4: .4byte 0x00000B22
_081E28F8:
	cmp r6, #0x1a
	bgt _081E2904
	ldr r1, _081E2900 @ =0x00000B2A
	b _081E290A
	.align 2, 0
_081E2900: .4byte 0x00000B2A
_081E2904:
	cmp r6, #0x1b
	bgt _081E2920
	ldr r1, _081E2918 @ =0x00000B26
_081E290A:
	adds r0, r5, r1
	ldrh r2, [r0]
	ldr r0, _081E291C @ =0x00000AC8
_081E2910:
	adds r3, r5, r0
	lsls r1, r6, #1
	b _081E2930
	.align 2, 0
_081E2918: .4byte 0x00000B26
_081E291C: .4byte 0x00000AC8
_081E2920:
	lsls r1, r6, #1
	movs r2, #0xaf
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _081E295C @ =0x00000AA8
_081E292E:
	adds r3, r5, r0
_081E2930:
	adds r0, r1, r6
	lsls r0, r0, #5
	adds r0, #0x28
	adds r0, r5, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r6, #1
	cmp r6, #0x1b
	bgt _081E2952
	b _081E283A
_081E2952:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E295C: .4byte 0x00000AA8

	thumb_func_start FUN_081e2960
FUN_081e2960: @ 0x081E2960
	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
_081E2966:
	cmp r3, #0xf
	bls _081E296C
	b _081E2AF8
_081E296C:
	lsls r0, r3, #2
	ldr r1, _081E2978 @ =_081E297C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E2978: .4byte _081E297C
_081E297C: @ jump table
	.4byte _081E29BC @ case 0
	.4byte _081E29D2 @ case 1
	.4byte _081E29E8 @ case 2
	.4byte _081E29FE @ case 3
	.4byte _081E2A14 @ case 4
	.4byte _081E2A2A @ case 5
	.4byte _081E2A40 @ case 6
	.4byte _081E2A56 @ case 7
	.4byte _081E2A6C @ case 8
	.4byte _081E2A7C @ case 9
	.4byte _081E2A8C @ case 10
	.4byte _081E2A9C @ case 11
	.4byte _081E2AB2 @ case 12
	.4byte _081E2AC2 @ case 13
	.4byte _081E2AD2 @ case 14
	.4byte _081E2AE2 @ case 15
_081E29BC:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x58
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29D2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x50
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29E8:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x48
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29FE:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x40
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A14:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd8
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A2A:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd0
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A40:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc8
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A56:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc0
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A6C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x40
	b _081E2AF0
_081E2A7C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x38
	b _081E2AF0
_081E2A8C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x58
	b _081E2AF0
_081E2A9C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x48
	movs r2, #0x50
	strh r2, [r1]
	adds r0, #0x4a
	strh r2, [r0]
	b _081E2AF8
_081E2AB2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc0
	b _081E2AF0
_081E2AC2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xb8
	b _081E2AF0
_081E2AD2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd8
	b _081E2AF0
_081E2AE2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd0
_081E2AF0:
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x50
_081E2AF6:
	strh r1, [r0]
_081E2AF8:
	adds r3, #1
	cmp r3, #0xf
	bgt _081E2B00
	b _081E2966
_081E2B00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e2b08
FUN_081e2b08: @ 0x081E2B08
	ldr r1, [r0, #0x30]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x30]
	adds r3, r0, #0
	adds r3, #0x90
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	adds r3, #0x60
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xcc
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x8a
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xba
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xc6
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bx lr

	thumb_func_start FUN_081e2c14
FUN_081e2c14: @ 0x081E2C14
	adds r3, r0, #0
	ldr r0, [r3, #0x30]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
	adds r2, r3, #0
	adds r2, #0x90
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x60
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x84
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xfc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xae
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xba
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bx lr

	thumb_func_start FUN_081e2cdc
FUN_081e2cdc: @ 0x081E2CDC
	adds r3, r0, #0
	ldr r0, [r3, #0x30]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
	adds r2, r3, #0
	adds r2, #0x90
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x60
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x84
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xfc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xae
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xba
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bx lr

	thumb_func_start FUN_081e2d98
FUN_081e2d98: @ 0x081E2D98
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr

	thumb_func_start FUN_081e2dd8
FUN_081e2dd8: @ 0x081E2DD8
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xc6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr

	thumb_func_start FUN_081e2e24
FUN_081e2e24: @ 0x081E2E24
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _081E2E78 @ =0x00001590
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	ldr r2, _081E2E7C @ =0x00000E28
	adds r1, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	bl Textbox_LookupString
	movs r3, #0
	ldrb r1, [r0]
	cmp r1, #0
	beq _081E2E68
	cmp r1, #0x3c
	beq _081E2E68
	ldr r1, _081E2E80 @ =0x000015A4
	adds r5, r4, r1
	adds r2, r0, #0
_081E2E50:
	adds r1, r5, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E2E68
	cmp r3, #0xf
	bgt _081E2E68
	cmp r0, #0x3c
	bne _081E2E50
_081E2E68:
	ldr r2, _081E2E80 @ =0x000015A4
	adds r0, r4, r2
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E2E78: .4byte 0x00001590
_081E2E7C: .4byte 0x00000E28
_081E2E80: .4byte 0x000015A4

	thumb_func_start FUN_081e2e84
FUN_081e2e84: @ 0x081E2E84
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _081E2EA0
	bl FUN_0823d340
	ldr r2, _081E2ED4 @ =0x000015F0
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E2ED0
_081E2EA0:
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _081E2EB8
	bl FUN_0823d340
	ldr r2, _081E2ED8 @ =0x00001590
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E2ED0
_081E2EB8:
	movs r0, #0x59
	bl prepare_08231510
	cmp r0, #0
	beq _081E2EE0
	bl FUN_0823d340
	ldr r2, _081E2EDC @ =0x000015F4
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _081E2EE0
_081E2ED0:
	movs r0, #0
	b _081E2EE2
	.align 2, 0
_081E2ED4: .4byte 0x000015F0
_081E2ED8: .4byte 0x00001590
_081E2EDC: .4byte 0x000015F4
_081E2EE0:
	movs r0, #1
_081E2EE2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2ee8
FUN_081e2ee8: @ 0x081E2EE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	ldr r2, _081E2F00 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E2F04
	movs r0, #1
	b _081E2F06
	.align 2, 0
_081E2F00: .4byte 0x00001610
_081E2F04:
	movs r0, #0
_081E2F06:
	cmp r0, #0
	bne _081E2F24
	bl FUN_08049f5c
	bl FUN_08049e5c
	movs r2, #1
	ldr r0, _081E2F20 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081E32C8
	.align 2, 0
_081E2F20: .4byte 0x00001610
_081E2F24:
	ldr r1, _081E2F60 @ =0x00001616
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x16
	beq _081E2F36
	cmp r0, #0x13
	beq _081E2F36
	cmp r0, #0xa
	bne _081E2F6C
_081E2F36:
	ldr r2, _081E2F64 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	bne _081E2F44
	b _081E32C8
_081E2F44:
	bl FUN_08049e5c
	ldr r1, _081E2F68 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xa
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0xa
	b _081E32C6
	.align 2, 0
_081E2F60: .4byte 0x00001616
_081E2F64: .4byte 0x00001617
_081E2F68: .4byte 0x000015F0
_081E2F6C:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E2F8C
	ldrb r0, [r4]
	cmp r0, #2
	beq _081E2F8C
	cmp r0, #0x15
	beq _081E2F8C
	cmp r0, #8
	beq _081E2F8C
	cmp r0, #0x1d
	beq _081E2F8C
	cmp r0, #5
	bne _081E2FC0
_081E2F8C:
	ldr r2, _081E2FB8 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #7
	bne _081E2F9A
	b _081E32C8
_081E2F9A:
	bl FUN_08049e5c
	ldr r1, _081E2FBC @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #7
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #7
	b _081E32C6
	.align 2, 0
_081E2FB8: .4byte 0x00001617
_081E2FBC: .4byte 0x000015F0
_081E2FC0:
	bl FUN_081e23e4
	cmp r0, #0
	bne _081E2FCA
	b _081E3154
_081E2FCA:
	ldrb r0, [r4]
	cmp r0, #0
	beq _081E2FD2
	b _081E3184
_081E2FD2:
	ldr r2, _081E3018 @ =0x00001615
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E309C
	ldr r1, _081E301C @ =0x00000BB5
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, _081E3020 @ =0x00000BB4
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bgt _081E302C
	ldr r0, _081E3024 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bne _081E2FFC
	b _081E32C8
_081E2FFC:
	bl FUN_08049e5c
	ldr r1, _081E3028 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #5
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #5
	b _081E3182
	.align 2, 0
_081E3018: .4byte 0x00001615
_081E301C: .4byte 0x00000BB5
_081E3020: .4byte 0x00000BB4
_081E3024: .4byte 0x00001617
_081E3028: .4byte 0x000015F0
_081E302C:
	bl FUN_08243104
	cmp r0, #0
	bgt _081E3068
	ldr r2, _081E3060 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x14
	bne _081E3042
	b _081E32C8
_081E3042:
	bl FUN_08049e5c
	ldr r1, _081E3064 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x14
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x14
	b _081E3182
	.align 2, 0
_081E3060: .4byte 0x00001617
_081E3064: .4byte 0x000015F0
_081E3068:
	ldr r2, _081E3094 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bne _081E3076
	b _081E32C8
_081E3076:
	bl FUN_08049e5c
	ldr r1, _081E3098 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #3
	b _081E3182
	.align 2, 0
_081E3094: .4byte 0x00001617
_081E3098: .4byte 0x000015F0
_081E309C:
	bl FUN_08243140
	adds r4, r0, #0
	bl FUN_08243104
	subs r4, r4, r0
	cmp r4, #0
	bgt _081E30E0
	ldr r2, _081E30D8 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #6
	bne _081E30BA
	b _081E32C8
_081E30BA:
	bl FUN_08049e5c
	ldr r1, _081E30DC @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #6
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #6
	b _081E3182
	.align 2, 0
_081E30D8: .4byte 0x00001617
_081E30DC: .4byte 0x000015F0
_081E30E0:
	ldr r2, _081E3114 @ =0x00000BB4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E3120
	ldr r0, _081E3118 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x15
	bne _081E30F8
	b _081E32C8
_081E30F8:
	bl FUN_08049e5c
	ldr r1, _081E311C @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x15
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x15
	b _081E3182
	.align 2, 0
_081E3114: .4byte 0x00000BB4
_081E3118: .4byte 0x00001617
_081E311C: .4byte 0x000015F0
_081E3120:
	ldr r2, _081E314C @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #4
	bne _081E312E
	b _081E32C8
_081E312E:
	bl FUN_08049e5c
	ldr r1, _081E3150 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #4
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #4
	b _081E3182
	.align 2, 0
_081E314C: .4byte 0x00001617
_081E3150: .4byte 0x000015F0
_081E3154:
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E3184
	ldr r2, _081E31BC @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _081E3168
	b _081E32C8
_081E3168:
	bl FUN_08049e5c
	ldr r1, _081E31C0 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #2
_081E3182:
	strb r0, [r4]
_081E3184:
	ldr r2, _081E31C4 @ =0x00001616
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _081E3192
	cmp r0, #0xd
	bne _081E31C8
_081E3192:
	ldr r0, _081E31BC @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	bne _081E31A0
	b _081E32C8
_081E31A0:
	bl FUN_08049e5c
	ldr r1, _081E31C0 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xa
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0xa
	b _081E32C6
	.align 2, 0
_081E31BC: .4byte 0x00001617
_081E31C0: .4byte 0x000015F0
_081E31C4: .4byte 0x00001616
_081E31C8:
	cmp r0, #3
	bne _081E31E4
	ldr r2, _081E31DC @ =0x00001617
	adds r6, r5, r2
	movs r1, #0
	ldrsb r1, [r6, r1]
	ldr r0, _081E31E0 @ =0x0000161A
	adds r4, r5, r0
	b _081E3230
	.align 2, 0
_081E31DC: .4byte 0x00001617
_081E31E0: .4byte 0x0000161A
_081E31E4:
	cmp r0, #4
	bne _081E324C
	ldr r1, _081E321C @ =0x0000161A
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x11
	bne _081E3228
	ldr r2, _081E3220 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xf
	beq _081E32C8
	bl FUN_08049e5c
	ldr r1, _081E3224 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0xf
	b _081E32C6
	.align 2, 0
_081E321C: .4byte 0x0000161A
_081E3220: .4byte 0x00001617
_081E3224: .4byte 0x000015F0
_081E3228:
	ldr r2, _081E3248 @ =0x00001617
	adds r6, r5, r2
	movs r1, #0
	ldrsb r1, [r6, r1]
_081E3230:
	ldrb r0, [r4]
	adds r0, #0x19
	cmp r1, r0
	beq _081E32C8
	adds r0, r5, #0
	bl FUN_081e4544
	ldrb r0, [r4]
	adds r0, #0x19
	strb r0, [r6]
	b _081E32C8
	.align 2, 0
_081E3248: .4byte 0x00001617
_081E324C:
	cmp r0, #7
	bne _081E32C8
	ldr r0, _081E3290 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _081E3294 @ =0x000015E4
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _081E32A0
	ldr r0, _081E3298 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x10
	beq _081E32C8
	bl FUN_08049e5c
	ldr r1, _081E329C @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x10
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x10
	b _081E32C6
	.align 2, 0
_081E3290: .4byte 0x030046A0
_081E3294: .4byte 0x000015E4
_081E3298: .4byte 0x00001617
_081E329C: .4byte 0x000015F0
_081E32A0:
	ldr r2, _081E32D0 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x11
	beq _081E32C8
	bl FUN_08049e5c
	ldr r1, _081E32D4 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x11
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x11
_081E32C6:
	strb r0, [r4]
_081E32C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E32D0: .4byte 0x00001617
_081E32D4: .4byte 0x000015F0

	thumb_func_start FUN_081e32d8
FUN_081e32d8: @ 0x081E32D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r1, #4
	ldr r2, _081E32F4 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E32F8
	movs r0, #1
	b _081E32FA
	.align 2, 0
_081E32F4: .4byte 0x00001610
_081E32F8:
	movs r0, #0
_081E32FA:
	cmp r0, #0
	bne _081E3300
	b _081E3422
_081E3300:
	movs r6, #0
	ldr r0, _081E3430 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x91
	lsls r3, r3, #4
	adds r0, r0, r3
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r2, #0
	ldr r0, _081E3434 @ =0x000003E7
	adds r7, r5, #0
	adds r7, #0xe8
	movs r3, #0x88
	adds r3, r3, r5
	mov r8, r3
	movs r1, #0x28
	adds r1, r1, r5
	mov sb, r1
	cmp r4, r0
	ble _081E3332
	ldr r1, _081E3438 @ =0xFFFFFC18
_081E332A:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E332A
_081E3332:
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0x63
	ble _081E3352
_081E334A:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E334A
_081E3352:
	ldr r0, _081E343C @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #9
	ble _081E336E
_081E3366:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3366
_081E336E:
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0
	ble _081E338A
_081E3382:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3382
_081E338A:
	ldr r0, _081E343C @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, sb
	bl Sprite_LoadSprite
	ldr r1, _081E3440 @ =0x00000BB6
	adds r0, r5, r1
	ldrh r4, [r0]
	adds r2, r6, #0
	ldr r0, _081E3434 @ =0x000003E7
	cmp r4, r0
	ble _081E33B0
	ldr r1, _081E3438 @ =0xFFFFFC18
_081E33A8:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E33A8
_081E33B0:
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0x63
	ble _081E33D0
_081E33C8:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E33C8
_081E33D0:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #9
	ble _081E33F0
_081E33E8:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E33E8
_081E33F0:
	movs r1, #0x82
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0
	ble _081E3410
_081E3408:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3408
_081E3410:
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
_081E3422:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3430: .4byte 0x030046A0
_081E3434: .4byte 0x000003E7
_081E3438: .4byte 0xFFFFFC18
_081E343C: .4byte 0x00000AA8
_081E3440: .4byte 0x00000BB6

	thumb_func_start FUN_081e3444
FUN_081e3444: @ 0x081E3444
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #8
	ldr r2, _081E345C @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E3460
	movs r0, #1
	b _081E3462
	.align 2, 0
_081E345C: .4byte 0x00001610
_081E3460:
	movs r0, #0
_081E3462:
	cmp r0, #0
	bne _081E3468
	b _081E3582
_081E3468:
	movs r6, #0
	bl FUN_08243104
	adds r4, r0, #0
	movs r2, #0
	cmp r4, #9
	ble _081E347E
_081E3476:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3476
_081E347E:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0
	ble _081E349E
_081E3496:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3496
_081E349E:
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	bl FUN_08243140
	adds r4, r0, #0
	adds r2, r6, #0
	cmp r4, #9
	ble _081E34C4
_081E34BC:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E34BC
_081E34C4:
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0
	ble _081E34E4
_081E34DC:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E34DC
_081E34E4:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	ldr r1, _081E358C @ =0x00000BB4
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r2, r6, #0
	cmp r4, #9
	ble _081E350A
_081E3502:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3502
_081E350A:
	movs r3, #0xa1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0
	ble _081E352A
_081E3522:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3522
_081E352A:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	ldr r1, _081E3590 @ =0x00000BB5
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r2, r6, #0
	cmp r4, #9
	ble _081E3550
_081E3548:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3548
_081E3550:
	movs r3, #0xb9
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r2, r6, #0
	cmp r4, #0
	ble _081E3570
_081E3568:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3568
_081E3570:
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
_081E3582:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E3588: .4byte 0x00000AA8
_081E358C: .4byte 0x00000BB4
_081E3590: .4byte 0x00000BB5

	thumb_func_start FUN_081e3594
FUN_081e3594: @ 0x081E3594
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _081E367C @ =0x00000AA8
	adds r4, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	adds r0, r5, #0
	adds r0, #0xe8
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	adds r0, r5, #0
	adds r0, #0x88
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	adds r0, r5, #0
	adds r0, #0x28
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0x82
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl Sprite_LoadSprite
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E367C: .4byte 0x00000AA8

	thumb_func_start FUN_081e3680
FUN_081e3680: @ 0x081E3680
	adds r3, r0, #0
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x40
	strh r0, [r1]
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0x68
	strh r2, [r0]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x48
	strh r0, [r1]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r3, r1
	strh r2, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #0x50
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xaa
	strh r2, [r0]
	subs r1, #0x60
	movs r0, #0x58
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4a
	strh r2, [r0]
	ldr r0, [r3, #0x30]
	subs r2, #0x6a
	ands r0, r2
	str r0, [r3, #0x30]
	adds r1, #0x48
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	bx lr

	thumb_func_start FUN_081e36e8
FUN_081e36e8: @ 0x081E36E8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081e3680
	ldr r0, _081E370C @ =0x000015E2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081E3710 @ =0x000015BC
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x24
	bl ClearMemory
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E370C: .4byte 0x000015E2
_081E3710: .4byte 0x000015BC

	thumb_func_start FUN_081e3714
FUN_081e3714: @ 0x081E3714
	push {lr}
	ldr r1, _081E3748 @ =0x000015E7
	adds r2, r0, r1
	movs r1, #3
	strb r1, [r2]
	ldr r2, _081E374C @ =0x000015E8
	adds r1, r0, r2
	movs r2, #9
	strb r2, [r1]
	ldr r3, _081E3750 @ =0x000015E9
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _081E3754 @ =0x000015EC
	adds r0, r0, r1
	movs r1, #4
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_081E3748: .4byte 0x000015E7
_081E374C: .4byte 0x000015E8
_081E3750: .4byte 0x000015E9
_081E3754: .4byte 0x000015EC

	thumb_func_start FUN_081e3758
FUN_081e3758: @ 0x081E3758
	adds r2, r0, #0
	ldr r0, _081E3790 @ =0x000015EC
	adds r3, r2, r0
	ldr r1, _081E3794 @ =0x000015ED
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldrb r3, [r3]
	adds r0, r0, r3
	ldr r3, _081E3798 @ =0x000015EE
	adds r1, r2, r3
	ldrb r3, [r1]
	movs r1, #0x64
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _081E379C @ =0x000015EF
	adds r2, r2, r1
	ldrb r2, [r2]
	lsls r1, r2, #5
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	bx lr
	.align 2, 0
_081E3790: .4byte 0x000015EC
_081E3794: .4byte 0x000015ED
_081E3798: .4byte 0x000015EE
_081E379C: .4byte 0x000015EF

	thumb_func_start FUN_081e37a0
FUN_081e37a0: @ 0x081E37A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r2, #0
	ldr r0, _081E37F0 @ =0x000003E7
	cmp r4, r0
	ble _081E37BC
	ldr r1, _081E37F4 @ =0xFFFFFC18
_081E37B4:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E37B4
_081E37BC:
	ldr r1, _081E37F8 @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _081E3804
	ldr r3, _081E37FC @ =0x00001616
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3804
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r7, _081E3800 @ =0x00000AA8
	adds r1, r5, r7
	adds r3, r2, #0
	adds r3, #0xa
	lsls r3, r3, #1
	movs r6, #0xaf
	lsls r6, r6, #4
	adds r2, r5, r6
	adds r2, r2, r3
	ldrh r2, [r2]
	bl Sprite_LoadSprite
	b _081E381E
	.align 2, 0
_081E37F0: .4byte 0x000003E7
_081E37F4: .4byte 0xFFFFFC18
_081E37F8: .4byte 0x000015E6
_081E37FC: .4byte 0x00001616
_081E3800: .4byte 0x00000AA8
_081E3804:
	movs r7, #0xa4
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r3, _081E3868 @ =0x00000AA8
	adds r1, r5, r3
	lsls r3, r2, #1
	movs r6, #0xaf
	lsls r6, r6, #4
	adds r2, r5, r6
	adds r2, r2, r3
	ldrh r2, [r2]
	bl Sprite_LoadSprite
_081E381E:
	movs r2, #0
	adds r3, r5, #0
	adds r3, #0xe8
	adds r6, r5, #0
	adds r6, #0x88
	movs r7, #0x28
	adds r7, r7, r5
	mov r8, r7
	cmp r4, #0x63
	ble _081E383A
_081E3832:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E3832
_081E383A:
	ldr r1, _081E386C @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _081E3874
	ldr r7, _081E3870 @ =0x00001616
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3874
	ldr r0, _081E3868 @ =0x00000AA8
	adds r1, r5, r0
	adds r2, #0xa
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl Sprite_LoadSprite
	b _081E388A
	.align 2, 0
_081E3868: .4byte 0x00000AA8
_081E386C: .4byte 0x000015E6
_081E3870: .4byte 0x00001616
_081E3874:
	ldr r0, _081E38C8 @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl Sprite_LoadSprite
_081E388A:
	movs r2, #0
	cmp r4, #9
	ble _081E3898
_081E3890:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3890
_081E3898:
	ldr r1, _081E38CC @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081E38D4
	ldr r3, _081E38D0 @ =0x00001616
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E38D4
	ldr r7, _081E38C8 @ =0x00000AA8
	adds r1, r5, r7
	adds r2, #0xa
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r6, #0
	bl Sprite_LoadSprite
	b _081E38EA
	.align 2, 0
_081E38C8: .4byte 0x00000AA8
_081E38CC: .4byte 0x000015E6
_081E38D0: .4byte 0x00001616
_081E38D4:
	ldr r7, _081E3928 @ =0x00000AA8
	adds r1, r5, r7
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r6, #0
	bl Sprite_LoadSprite
_081E38EA:
	movs r2, #0
	cmp r4, #0
	ble _081E38F8
_081E38F0:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E38F0
_081E38F8:
	ldr r6, _081E392C @ =0x000015E6
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E3934
	ldr r7, _081E3930 @ =0x00001616
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3934
	ldr r0, _081E3928 @ =0x00000AA8
	adds r1, r5, r0
	adds r2, #0xa
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, r8
	bl Sprite_LoadSprite
	b _081E394A
	.align 2, 0
_081E3928: .4byte 0x00000AA8
_081E392C: .4byte 0x000015E6
_081E3930: .4byte 0x00001616
_081E3934:
	ldr r6, _081E3954 @ =0x00000AA8
	adds r1, r5, r6
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, r8
	bl Sprite_LoadSprite
_081E394A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3954: .4byte 0x00000AA8

	thumb_func_start FUN_081e3958
FUN_081e3958: @ 0x081E3958
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r1, #0
	cmp r0, #0
	bne _081E3968
	b _081E3CAC
_081E3968:
	adds r4, r0, #0
	ldrh r0, [r6]
	adds r1, r0, #0
	cmp r1, #0
	bne _081E3976
	movs r0, #1
	b _081E3978
_081E3976:
	movs r0, #0
_081E3978:
	cmp r0, #0
	beq _081E398C
	ldr r1, [r6, #4]
	ldr r2, _081E3988 @ =0x00000BB6
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #4
	b _081E3C9E
	.align 2, 0
_081E3988: .4byte 0x00000BB6
_081E398C:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _081E3998
	movs r0, #1
	b _081E399A
_081E3998:
	movs r0, #0
_081E399A:
	cmp r0, #0
	beq _081E39E8
	adds r1, r6, #4
	movs r3, #0
	ldrb r0, [r6, #4]
	ldr r5, _081E39E0 @ =0x00001610
	adds r5, r5, r4
	mov sb, r5
	cmp r0, #0
	beq _081E39C8
	ldr r7, _081E39E4 @ =0x00000BB8
	adds r5, r4, r7
	adds r2, r1, #0
_081E39B4:
	adds r0, r5, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E39C8
	cmp r3, #0xb
	ble _081E39B4
_081E39C8:
	ldr r1, _081E39E4 @ =0x00000BB8
	adds r0, r4, r1
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	movs r1, #2
	mov r2, sb
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _081E3CA8
	.align 2, 0
_081E39E0: .4byte 0x00001610
_081E39E4: .4byte 0x00000BB8
_081E39E8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne _081E39F4
	movs r0, #1
	b _081E39F6
_081E39F4:
	movs r0, #0
_081E39F6:
	cmp r0, #0
	beq _081E3A20
	ldr r1, [r6, #4]
	ldr r3, _081E3A14 @ =0x00000BB4
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, [r6, #8]
	ldr r5, _081E3A18 @ =0x00000BB5
	adds r0, r4, r5
	strb r1, [r0]
	movs r2, #8
	ldr r7, _081E3A1C @ =0x00001610
	adds r1, r4, r7
	b _081E3CA2
	.align 2, 0
_081E3A14: .4byte 0x00000BB4
_081E3A18: .4byte 0x00000BB5
_081E3A1C: .4byte 0x00001610
_081E3A20:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _081E3A2C
	movs r0, #1
	b _081E3A2E
_081E3A2C:
	movs r0, #0
_081E3A2E:
	cmp r0, #0
	beq _081E3A60
	ldr r0, [r6, #4]
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x80
	ldr r5, _081E3A5C @ =0x00001610
	adds r3, r4, r5
	ldr r2, [r3]
	orrs r2, r0
	str r2, [r3]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #4
	beq _081E3A52
	b _081E3CA8
_081E3A52:
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r2, r0
	str r2, [r3]
	b _081E3CA8
	.align 2, 0
_081E3A5C: .4byte 0x00001610
_081E3A60:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bne _081E3A6C
	movs r0, #1
	b _081E3A6E
_081E3A6C:
	movs r0, #0
_081E3A6E:
	cmp r0, #0
	beq _081E3B40
	ldr r1, [r6, #4]
	ldr r2, _081E3A84 @ =0x000015BC
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #0
	blt _081E3A88
	asrs r2, r1, #8
	b _081E3A8E
	.align 2, 0
_081E3A84: .4byte 0x000015BC
_081E3A88:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_081E3A8E:
	ldr r3, _081E3A9C @ =0x000015BD
	adds r0, r4, r3
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AA0
	asrs r2, r1, #0x10
	b _081E3AA6
	.align 2, 0
_081E3A9C: .4byte 0x000015BD
_081E3AA0:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r2, r0, #0
_081E3AA6:
	ldr r5, _081E3AB4 @ =0x000015BE
	adds r0, r4, r5
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AB8
	asrs r1, r1, #0x18
	b _081E3ABE
	.align 2, 0
_081E3AB4: .4byte 0x000015BE
_081E3AB8:
	rsbs r0, r1, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_081E3ABE:
	ldr r7, _081E3AD8 @ =0x000015BF
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, [r6, #8]
	movs r2, #0xae
	lsls r2, r2, #5
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #0
	blt _081E3ADC
	asrs r2, r1, #8
	b _081E3AE2
	.align 2, 0
_081E3AD8: .4byte 0x000015BF
_081E3ADC:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_081E3AE2:
	ldr r3, _081E3AF0 @ =0x000015C1
	adds r0, r4, r3
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AF4
	asrs r1, r1, #0x10
	b _081E3AFA
	.align 2, 0
_081E3AF0: .4byte 0x000015C1
_081E3AF4:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_081E3AFA:
	ldr r5, _081E3B10 @ =0x000015C2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, [r6, #0xc]
	ldr r7, _081E3B14 @ =0x000015C4
	adds r0, r4, r7
	strh r1, [r0]
	cmp r1, #0
	blt _081E3B18
	asrs r1, r1, #0x10
	b _081E3B1E
	.align 2, 0
_081E3B10: .4byte 0x000015C2
_081E3B14: .4byte 0x000015C4
_081E3B18:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_081E3B1E:
	ldr r2, _081E3B38 @ =0x000015C6
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #2]
	movs r3, #0xaf
	lsls r3, r3, #5
	adds r0, r4, r3
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r5, _081E3B3C @ =0x00001610
	adds r1, r4, r5
	b _081E3CA2
	.align 2, 0
_081E3B38: .4byte 0x000015C6
_081E3B3C: .4byte 0x00001610
_081E3B40:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne _081E3B4C
	movs r0, #1
	b _081E3B4E
_081E3B4C:
	movs r0, #0
_081E3B4E:
	cmp r0, #0
	beq _081E3B7C
	movs r7, #0xaf
	lsls r7, r7, #5
	adds r0, r4, r7
	ldrh r0, [r0]
	ldrh r1, [r6, #2]
	cmp r0, r1
	bne _081E3B9C
	adds r5, r6, #4
	movs r2, #0
	ldr r7, _081E3B78 @ =0x000015C8
	adds r3, r4, r7
_081E3B68:
	adds r0, r3, r2
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xb
	ble _081E3B68
	b _081E3CA8
	.align 2, 0
_081E3B78: .4byte 0x000015C8
_081E3B7C:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _081E3B88
	movs r0, #1
	b _081E3B8A
_081E3B88:
	movs r0, #0
_081E3B8A:
	cmp r0, #0
	beq _081E3C60
	movs r1, #0xaf
	lsls r1, r1, #5
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r6, #2]
	cmp r0, r2
	beq _081E3BA2
_081E3B9C:
	bl FUN_081e24b4
	b _081E3CAC
_081E3BA2:
	ldr r3, _081E3C3C @ =0x00001610
	adds r3, r3, r4
	mov sb, r3
	adds r3, r4, #0
	adds r2, r6, #4
	movs r5, #2
_081E3BAE:
	ldrb r1, [r2]
	ldr r7, _081E3C40 @ =0x000015D4
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	adds r3, #4
	subs r5, #1
	cmp r5, #0
	bge _081E3BAE
	ldr r0, _081E3C44 @ =0x00000E28
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _081E3C48 @ =0x000015BC
	adds r1, r1, r4
	mov r8, r1
	mov r1, ip
	mov r0, r8
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
	ldr r3, _081E3C4C @ =0x00000E04
	adds r0, r4, r3
	mov r2, r8
	ldm r2!, {r1, r5, r7}
	stm r0!, {r1, r5, r7}
	ldm r2!, {r3, r5, r7}
	stm r0!, {r3, r5, r7}
	ldm r2!, {r1, r3, r5}
	stm r0!, {r1, r3, r5}
	ldr r7, _081E3C50 @ =0x000014AC
	adds r0, r4, r7
	ldr r2, _081E3C54 @ =0x0000156C
	adds r1, r4, r2
	mov r3, ip
	ldrb r2, [r3]
	bl Sprite_LoadSprite
	ldr r5, _081E3C58 @ =0x000014B4
	adds r2, r4, r5
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r7, sb
	ldr r0, [r7]
	orrs r0, r1
	ldr r1, _081E3C5C @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r7]
	b _081E3CA8
	.align 2, 0
_081E3C3C: .4byte 0x00001610
_081E3C40: .4byte 0x000015D4
_081E3C44: .4byte 0x00000E28
_081E3C48: .4byte 0x000015BC
_081E3C4C: .4byte 0x00000E04
_081E3C50: .4byte 0x000014AC
_081E3C54: .4byte 0x0000156C
_081E3C58: .4byte 0x000014B4
_081E3C5C: .4byte 0xFFFFF7FF
_081E3C60:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bne _081E3C6C
	movs r0, #1
	b _081E3C6E
_081E3C6C:
	movs r0, #0
_081E3C6E:
	cmp r0, #0
	beq _081E3C80
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r0, _081E3C7C @ =0x00001610
	adds r1, r4, r0
	b _081E3CA2
	.align 2, 0
_081E3C7C: .4byte 0x00001610
_081E3C80:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bne _081E3C8C
	movs r0, #1
	b _081E3C8E
_081E3C8C:
	movs r0, #0
_081E3C8E:
	cmp r0, #0
	beq _081E3CA8
	ldr r1, [r6, #4]
	ldr r2, _081E3CB8 @ =0x000015E2
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
_081E3C9E:
	ldr r3, _081E3CBC @ =0x00001610
	adds r1, r4, r3
_081E3CA2:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E3CA8:
	movs r0, #0
	strh r0, [r6]
_081E3CAC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3CB8: .4byte 0x000015E2
_081E3CBC: .4byte 0x00001610

	thumb_func_start FUN_081e3cc0
FUN_081e3cc0: @ 0x081E3CC0
	movs r2, #0x80
	lsls r2, r2, #0xf
	ldr r1, _081E3CD0 @ =0x00001610
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_081E3CD0: .4byte 0x00001610

	thumb_func_start FUN_081e3cd4
FUN_081e3cd4: @ 0x081E3CD4
	push {lr}
	bl FUN_0824172c
	ldr r1, _081E3CE4 @ =0x0300481C
	movs r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081E3CE4: .4byte 0x0300481C

	thumb_func_start FUN_081e3ce8
FUN_081e3ce8: @ 0x081E3CE8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #2
	ldr r2, _081E3D00 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E3D04
	movs r0, #1
	b _081E3D06
	.align 2, 0
_081E3D00: .4byte 0x00001610
_081E3D04:
	movs r0, #0
_081E3D06:
	cmp r0, #0
	beq _081E3D62
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r7, r0
	ldr r0, [r5]
	ldr r1, _081E3D68 @ =0x000015F0
	adds r6, r7, r1
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r2, _081E3D6C @ =0x00001604
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r5]
	ldr r1, _081E3D70 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r1, _081E3D74 @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, [r5]
	bl FUN_0804a1f0
	ldr r0, [r4]
	bl FUN_0804a1f0
_081E3D62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3D68: .4byte 0x000015F0
_081E3D6C: .4byte 0x00001604
_081E3D70: .4byte 0x030046A0
_081E3D74: .4byte 0x00000BB8

	thumb_func_start FUN_081e3d78
FUN_081e3d78: @ 0x081E3D78
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x11
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081E3DDC @ =0x00001604
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081E3DE0 @ =0x00001608
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081E3DE4 @ =0x0000160C
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _081E3DE8 @ =0x00000BB8
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xc
	bl ClearMemory
	movs r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E3DDC: .4byte 0x00001604
_081E3DE0: .4byte 0x00001608
_081E3DE4: .4byte 0x0000160C
_081E3DE8: .4byte 0x00000BB8

	thumb_func_start FUN_081e3dec
FUN_081e3dec: @ 0x081E3DEC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r4, r0
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r1, _081E3E6C @ =0x00001604
	adds r6, r4, r1
	ldr r0, [r6]
	bl FUN_0804a210
	ldr r0, _081E3E70 @ =0x00001608
	adds r0, r0, r4
	mov r8, r0
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E3E74 @ =0x0000160C
	adds r4, r4, r1
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r5]
	movs r5, #2
	str r5, [sp]
	movs r1, #1
	movs r2, #4
	movs r3, #0xa
	bl FUN_0804a38c
	ldr r0, [r6]
	str r5, [sp]
	movs r1, #0x11
	movs r2, #4
	movs r3, #0xa
	bl FUN_0804a38c
	mov r1, r8
	ldr r0, [r1]
	str r5, [sp]
	movs r1, #2
	movs r2, #0x10
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0x1c
	bl FUN_0804a38c
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E3E6C: .4byte 0x00001604
_081E3E70: .4byte 0x00001608
_081E3E74: .4byte 0x0000160C

	thumb_func_start FUN_081e3e78
FUN_081e3e78: @ 0x081E3E78
	push {lr}
	ldr r2, _081E3E9C @ =0x0000161A
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, #0x81
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _081E3E98
	adds r0, r1, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E3EA0
_081E3E98:
	movs r0, #0
	b _081E3EA2
	.align 2, 0
_081E3E9C: .4byte 0x0000161A
_081E3EA0:
	movs r0, #1
_081E3EA2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e3ea8
FUN_081e3ea8: @ 0x081E3EA8
	push {r4, r5, lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r0, _081E3EFC @ =0x0000161A
	adds r4, r1, r0
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081E3F00 @ =0x0000161B
	adds r0, r1, r2
	strb r5, [r0]
	ldr r2, _081E3F04 @ =0x00000808
	adds r0, r1, r2
	ldrb r2, [r4]
	movs r3, #3
	ands r3, r2
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	adds r2, #0x90
	strh r2, [r0, #0x20]
	ldrb r3, [r4]
	lsrs r3, r3, #2
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	adds r2, #0x20
	strh r2, [r0, #0x22]
	ldr r2, [r0, #8]
	movs r3, #1
	orrs r2, r3
	str r2, [r0, #8]
	ldr r2, _081E3F08 @ =0x00000AC8
	adds r1, r1, r2
	str r5, [sp]
	movs r2, #0
	bl FUN_082370cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E3EFC: .4byte 0x0000161A
_081E3F00: .4byte 0x0000161B
_081E3F04: .4byte 0x00000808
_081E3F08: .4byte 0x00000AC8

	thumb_func_start FUN_081e3f0c
FUN_081e3f0c: @ 0x081E3F0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _081E3F9C @ =0x00001594
	adds r2, r7, r0
	movs r0, #0
	str r0, [r2]
	ldr r3, _081E3FA0 @ =0x00001598
	adds r1, r7, r3
	strb r0, [r1]
	ldr r0, _081E3FA4 @ =0x030046A0
	ldr r0, [r0]
	adds r6, r2, #0
	movs r2, #1
	mov sb, r2
	adds r5, r1, #0
	adds r4, r0, #0
	adds r4, #0x60
	movs r3, #0
	mov r8, r3
	movs r0, #3
	mov ip, r0
_081E3F3C:
	ldr r0, _081E3FA8 @ =0x00000868
	add r0, r8
	adds r2, r7, r0
	movs r1, #0
	ldrsh r3, [r4, r1]
	cmp r3, #0
	blt _081E3F74
	movs r1, #3
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r2, #0x20]
	asrs r1, r3, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r2, #0x22]
	mov r1, sb
	lsls r1, r3
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_081E3F74:
	ldr r0, [r2, #8]
	mov r3, sb
	orrs r0, r3
	str r0, [r2, #8]
	adds r4, #2
	movs r0, #0x60
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add ip, r1
	mov r2, ip
	cmp r2, #0
	bge _081E3F3C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3F9C: .4byte 0x00001594
_081E3FA0: .4byte 0x00001598
_081E3FA4: .4byte 0x030046A0
_081E3FA8: .4byte 0x00000868

	thumb_func_start FUN_081e3fac
FUN_081e3fac: @ 0x081E3FAC
	push {r4, r5, lr}
	movs r2, #0
	ldr r3, _081E3FDC @ =0x00001598
	adds r1, r0, r3
	ldrb r5, [r1]
	cmp r2, r5
	bge _081E3FD6
	movs r4, #2
	rsbs r4, r4, #0
	adds r3, r1, #0
	movs r5, #0x87
	lsls r5, r5, #4
	adds r1, r0, r5
_081E3FC6:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x60
	adds r2, #1
	ldrb r0, [r3]
	cmp r2, r0
	blt _081E3FC6
_081E3FD6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E3FDC: .4byte 0x00001598

	thumb_func_start FUN_081e3fe0
FUN_081e3fe0: @ 0x081E3FE0
	push {r4, r5, lr}
	movs r2, #0
	ldr r3, _081E4010 @ =0x00001598
	adds r1, r0, r3
	ldrb r5, [r1]
	cmp r2, r5
	bge _081E4008
	movs r4, #1
	adds r3, r1, #0
	movs r5, #0x87
	lsls r5, r5, #4
	adds r1, r0, r5
_081E3FF8:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	adds r2, #1
	ldrb r0, [r3]
	cmp r2, r0
	blt _081E3FF8
_081E4008:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4010: .4byte 0x00001598

	thumb_func_start FUN_081e4014
FUN_081e4014: @ 0x081E4014
	push {lr}
	sub sp, #0x18
	adds r1, r0, #0
	ldr r2, _081E404C @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r2, _081E4050 @ =0x0000150C
	adds r0, r1, r2
	adds r2, #0x60
	adds r1, r1, r2
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0xd0
	movs r3, #0x11
	bl FUN_0822f3fc
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_081E404C: .4byte 0xFFFF0000
_081E4050: .4byte 0x0000150C

	thumb_func_start FUN_081e4054
FUN_081e4054: @ 0x081E4054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	ldr r7, _081E4108 @ =0x00000BC4
	add r7, sl
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _081E410C @ =0x05000002
	bl CpuSet
	ldr r0, _081E4110 @ =0x0000CB05
	ldr r1, _081E4114 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	cmp r1, #0
	bne _081E4086
	b _081E41BE
_081E4086:
	ldr r0, _081E4118 @ =0x0000158C
	add r0, sl
	str r1, [r0]
	ldr r0, _081E411C @ =0x0000156C
	add r0, sl
	bl OpenSpriteSetFile
	movs r5, #0
	mov r8, r5
	ldr r6, _081E4120 @ =0x00000E86
	add r6, sl
	ldr r0, _081E4124 @ =0x00000E4C
	add r0, sl
	mov sb, r0
	adds r4, r7, #0
_081E40A4:
	movs r1, #3
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	mov r1, sp
	strh r0, [r1, #0x14]
	asrs r1, r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r2, sp
	strh r0, [r2, #0x16]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08242b14
	ldrb r2, [r4]
	movs r0, #1
	str r0, [sp]
	movs r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
	mov r0, sb
	ldr r3, _081E4128 @ =0x000009A8
	adds r1, r7, r3
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r0, r5, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E4130
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6]
	subs r0, #0x10
	adds r1, r7, r0
	add r1, r8
	ldr r0, _081E412C @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xb8
	lsls r2, r2, #7
	b _081E4142
	.align 2, 0
_081E4108: .4byte 0x00000BC4
_081E410C: .4byte 0x05000002
_081E4110: .4byte 0x0000CB05
_081E4114: .4byte 0x00005D04
_081E4118: .4byte 0x0000158C
_081E411C: .4byte 0x0000156C
_081E4120: .4byte 0x00000E86
_081E4124: .4byte 0x00000E4C
_081E4128: .4byte 0x000009A8
_081E412C: .4byte 0x03003584
_081E4130:
	ldr r0, _081E41D0 @ =0x000002DF
	strh r0, [r6]
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r7, r3
	add r1, r8
	ldr r0, _081E41D4 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _081E41D8 @ =0x00005BE0
_081E4142:
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r7, r3
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r0, #0x60
	add r8, r0
	adds r6, #0x60
	add sb, r0
	adds r4, #0x24
	adds r5, #1
	cmp r5, #0xf
	ble _081E40A4
	movs r0, #0x30
	mov r1, sp
	strh r0, [r1, #0x14]
	add r1, sp, #0x14
	movs r0, #0x48
	strh r0, [r1, #2]
	mov sb, r2
	ldr r2, _081E41DC @ =0x00000888
	adds r4, r7, r2
	movs r6, #0xc0
	lsls r6, r6, #3
	movs r3, #0
	mov r8, r3
	movs r5, #1
_081E4182:
	mov r0, sb
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r1, [sp, #8]
	add r2, sp, #0x14
	str r2, [sp, #0xc]
	adds r0, r4, #0
	ldr r3, _081E41E0 @ =0x000009A8
	adds r1, r7, r3
	movs r2, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r1, r1, r6
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E4182
	mov r0, sl
	bl FUN_081e4014
_081E41BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E41D0: .4byte 0x000002DF
_081E41D4: .4byte 0x03003584
_081E41D8: .4byte 0x00005BE0
_081E41DC: .4byte 0x00000888
_081E41E0: .4byte 0x000009A8

	thumb_func_start FUN_081e41e4
FUN_081e41e4: @ 0x081E41E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _081E428C @ =0x00000BC4
	adds r0, r0, r7
	mov r8, r0
	add r4, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081E4290 @ =0x05000002
	bl CpuSet
	ldr r0, _081E4294 @ =0x0000CB05
	ldr r1, _081E4298 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	mov sl, r4
	cmp r1, #0
	bne _081E421A
	b _081E432E
_081E421A:
	ldr r2, _081E429C @ =0x0000158C
	adds r0, r7, r2
	str r1, [r0]
	subs r2, #0x20
	adds r0, r7, r2
	bl OpenSpriteSetFile
	movs r5, #0
	mov sb, r5
	ldr r0, _081E42A0 @ =0x00000E86
	adds r6, r7, r0
	ldr r1, _081E42A4 @ =0x00000E4C
	adds r7, r7, r1
	mov r4, r8
_081E4236:
	movs r1, #3
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	mov r2, sl
	strh r0, [r2]
	asrs r1, r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	add r1, sp, #4
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08242b14
	ldrb r2, [r4]
	adds r0, r7, #0
	ldr r1, _081E42A8 @ =0x000009A8
	add r1, r8
	bl Sprite_LoadSprite
	adds r0, r5, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E42B0
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	add r1, sb
	ldr r0, _081E42AC @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xb8
	lsls r2, r2, #7
	b _081E42C2
	.align 2, 0
_081E428C: .4byte 0x00000BC4
_081E4290: .4byte 0x05000002
_081E4294: .4byte 0x0000CB05
_081E4298: .4byte 0x00005D04
_081E429C: .4byte 0x0000158C
_081E42A0: .4byte 0x00000E86
_081E42A4: .4byte 0x00000E4C
_081E42A8: .4byte 0x000009A8
_081E42AC: .4byte 0x03003584
_081E42B0:
	ldr r0, _081E4340 @ =0x000002DF
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	add r1, sb
	ldr r0, _081E4344 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _081E4348 @ =0x00005BE0
_081E42C2:
	adds r0, r0, r2
	str r0, [r1]
	movs r0, #0xa4
	lsls r0, r0, #2
	add r0, r8
	add r0, sb
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r0, #0x60
	add sb, r0
	adds r6, #0x60
	adds r7, #0x60
	adds r4, #0x24
	adds r5, #1
	cmp r5, #0xf
	ble _081E4236
	movs r0, #0x30
	mov r1, sl
	strh r0, [r1]
	add r1, sp, #4
	movs r0, #0x48
	strh r0, [r1, #2]
	ldr r4, _081E434C @ =0x00000888
	add r4, r8
	movs r6, #0xc0
	lsls r6, r6, #3
	movs r5, #1
_081E42FC:
	adds r0, r4, #0
	ldr r1, _081E4350 @ =0x000009A8
	add r1, r8
	movs r2, #0
	bl Sprite_LoadSprite
	movs r2, #0xa4
	lsls r2, r2, #2
	add r2, r8
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r2, sl
	ldrh r0, [r2]
	strh r0, [r4, #0x20]
	add r0, sp, #4
	ldrh r0, [r0, #2]
	strh r0, [r4, #0x22]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E42FC
_081E432E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4340: .4byte 0x000002DF
_081E4344: .4byte 0x03003584
_081E4348: .4byte 0x00005BE0
_081E434C: .4byte 0x00000888
_081E4350: .4byte 0x000009A8

	thumb_func_start FUN_081e4354
FUN_081e4354: @ 0x081E4354
	push {r4, lr}
	ldr r2, _081E4380 @ =0x00000E54
	adds r1, r0, r2
	ldr r3, _081E4384 @ =0x00000BC4
	adds r2, r0, r3
	movs r4, #2
	rsbs r4, r4, #0
	movs r3, #0xf
_081E4364:
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E4370
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
_081E4370:
	adds r1, #0x60
	adds r2, #0x24
	subs r3, #1
	cmp r3, #0
	bge _081E4364
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4380: .4byte 0x00000E54
_081E4384: .4byte 0x00000BC4

	thumb_func_start FUN_081e4388
FUN_081e4388: @ 0x081E4388
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _081E43CC @ =0x00000BC4
	adds r0, r0, r7
	mov sb, r0
	movs r6, #0
	movs r3, #0
	ldr r0, _081E43D0 @ =0x00000E86
	adds r5, r7, r0
	ldr r1, _081E43D4 @ =0x03003584
	mov r8, r1
	adds r0, #0xe
	adds r4, r7, r0
_081E43AC:
	adds r0, r6, #0
	str r3, [sp]
	bl FUN_08243180
	ldr r3, [sp]
	cmp r0, #0
	bne _081E43D8
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r5]
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #7
	b _081E43E2
	.align 2, 0
_081E43CC: .4byte 0x00000BC4
_081E43D0: .4byte 0x00000E86
_081E43D4: .4byte 0x03003584
_081E43D8:
	ldr r0, _081E4440 @ =0x000002DF
	strh r0, [r5]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, _081E4444 @ =0x00005BE0
_081E43E2:
	adds r0, r0, r1
	str r0, [r4]
	movs r0, #0xa4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	adds r4, #0x60
	adds r3, #0x60
	adds r5, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _081E43AC
	movs r0, #0x30
	mov r8, r0
	ldr r0, _081E4448 @ =0x00001454
	adds r1, r7, r0
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081E444C @ =0x00000E6E
	movs r4, #0x48
	movs r3, #1
	movs r6, #1
_081E4418:
	mov r0, r8
	strh r0, [r1, #0x18]
	adds r0, r2, r5
	strh r4, [r0]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	adds r2, #0x60
	subs r6, #1
	cmp r6, #0
	bge _081E4418
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4440: .4byte 0x000002DF
_081E4444: .4byte 0x00005BE0
_081E4448: .4byte 0x00001454
_081E444C: .4byte 0x00000E6E

	thumb_func_start FUN_081e4450
FUN_081e4450: @ 0x081E4450
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	ldr r0, _081E4480 @ =0x00000E54
	adds r1, r3, r0
	movs r2, #0x11
_081E445C:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081E445C
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4480: .4byte 0x00000E54

	thumb_func_start FUN_081e4484
FUN_081e4484: @ 0x081E4484
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _081E44AC @ =0x00000E4C
	adds r4, r6, r0
	movs r5, #0x11
_081E448E:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E448E
	ldr r1, _081E44B0 @ =0x0000150C
	adds r0, r6, r1
	bl FUN_0822f1c0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E44AC: .4byte 0x00000E4C
_081E44B0: .4byte 0x0000150C

	thumb_func_start FUN_081e44b4
FUN_081e44b4: @ 0x081E44B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x28
	movs r5, #0x1b
_081E44BC:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E44BC
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e44d0
FUN_081e44d0: @ 0x081E44D0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E4510 @ =0x00001604
	adds r0, r4, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E4514 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E4518 @ =0x0000160C
	adds r0, r4, r2
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #1
	ldr r2, _081E451C @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E4520
	movs r0, #1
	b _081E4522
	.align 2, 0
_081E4510: .4byte 0x00001604
_081E4514: .4byte 0x00001608
_081E4518: .4byte 0x0000160C
_081E451C: .4byte 0x00001610
_081E4520:
	movs r0, #0
_081E4522:
	cmp r0, #0
	beq _081E4538
	bl FUN_08049fa8
	ldr r0, _081E4540 @ =0x00001610
	adds r2, r4, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081E4538:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4540: .4byte 0x00001610

	thumb_func_start FUN_081e4544
FUN_081e4544: @ 0x081E4544
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _081E45AC @ =0x0000161A
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _081E45B0 @ =0x00000BC4
	adds r0, r0, r3
	adds r5, r4, r0
	ldr r1, _081E45B4 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r3, _081E45B8 @ =0x0000159C
	adds r2, r4, r3
	adds r1, r5, #0
	bl FUN_08094d30
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E45C8
	bl FUN_08049f5c
	bl FUN_08049e5c
	ldr r1, _081E45BC @ =0x00001590
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl FUN_08094d48
	adds r0, r5, #0
	bl FUN_08094e70
	adds r2, r0, #0
	ldr r3, _081E45C0 @ =0x0000150C
	adds r0, r4, r3
	ldr r1, [r0, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r0, #8]
	ldr r3, _081E45C4 @ =0x0000156C
	adds r1, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl Sprite_SetSprite
	b _081E45D8
	.align 2, 0
_081E45AC: .4byte 0x0000161A
_081E45B0: .4byte 0x00000BC4
_081E45B4: .4byte 0x00001608
_081E45B8: .4byte 0x0000159C
_081E45BC: .4byte 0x00001590
_081E45C0: .4byte 0x0000150C
_081E45C4: .4byte 0x0000156C
_081E45C8:
	bl FUN_08049e5c
	ldr r1, _081E45E0 @ =0x0000150C
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_081E45D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E45E0: .4byte 0x0000150C

	thumb_func_start FUN_081e45e4
FUN_081e45e4: @ 0x081E45E4
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _081E4600 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_081E4600: .4byte 0x03003ED0

	thumb_func_start FUN_081e4604
FUN_081e4604: @ 0x081E4604
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r7, #3
	movs r0, #3
	bl FUN_081e45e4
	adds r6, r0, #0
	cmp r5, #0
	ble _081E463C
_081E461C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	adds r1, r0, r7
	strh r1, [r6]
	adds r6, #2
	muls r0, r5, r0
	subs r4, r4, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	cmp r5, #0
	bgt _081E461C
_081E463C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e4644
FUN_081e4644: @ 0x081E4644
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x1c]
	movs r4, #0
	cmp r4, r6
	bge _081E4680
_081E465C:
	mov r0, r8
	adds r2, r0, r4
	ldr r0, [sp, #0x20]
	mov r1, sb
	bl FUN_081e45e4
	adds r2, r4, #1
	cmp r5, #0
	ble _081E467A
	adds r1, r5, #0
_081E4670:
	strh r7, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _081E4670
_081E467A:
	adds r4, r2, #0
	cmp r4, r6
	blt _081E465C
_081E4680:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e468c
FUN_081e468c: @ 0x081E468C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r7, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081E46B4
	ldr r1, _081E46AC @ =0x085AE404
	ldr r2, _081E46B0 @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0]
	b _081E46CA
	.align 2, 0
_081E46AC: .4byte 0x085AE404
_081E46B0: .4byte 0x0000161A
_081E46B4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E46E4
	ldr r1, _081E46D8 @ =0x085AE404
	ldr r2, _081E46DC @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #1]
_081E46CA:
	cmp r2, #0x10
	bne _081E4754
	ldr r1, _081E46E0 @ =0x0000161B
	adds r0, r3, r1
	strb r7, [r0]
	b _081E4748
	.align 2, 0
_081E46D8: .4byte 0x085AE404
_081E46DC: .4byte 0x0000161A
_081E46E0: .4byte 0x0000161B
_081E46E4:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081E4704
	ldr r1, _081E46FC @ =0x085AE404
	ldr r2, _081E4700 @ =0x0000161A
	adds r5, r3, r2
	ldrb r4, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r2, [r0, #2]
	b _081E471A
	.align 2, 0
_081E46FC: .4byte 0x085AE404
_081E4700: .4byte 0x0000161A
_081E4704:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081E473C
	ldr r1, _081E4730 @ =0x085AE404
	ldr r2, _081E4734 @ =0x0000161A
	adds r5, r3, r2
	ldrb r4, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r2, [r0, #3]
_081E471A:
	cmp r2, #0x10
	bne _081E4724
	ldr r1, _081E4738 @ =0x0000161B
	adds r0, r3, r1
	strb r4, [r0]
_081E4724:
	ldrb r0, [r5]
	cmp r0, #0x10
	bne _081E4748
	movs r7, #1
	b _081E4748
	.align 2, 0
_081E4730: .4byte 0x085AE404
_081E4734: .4byte 0x0000161A
_081E4738: .4byte 0x0000161B
_081E473C:
	ldr r2, _081E4744 @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	b _081E47BC
	.align 2, 0
_081E4744: .4byte 0x0000161A
_081E4748:
	cmp r2, #0x10
	bne _081E4754
	movs r0, #0x30
	strh r0, [r6]
	movs r0, #0x48
	b _081E47B8
_081E4754:
	cmp r2, #0x11
	bne _081E4760
	movs r0, #0x38
	strh r0, [r6]
	movs r0, #0x68
	b _081E47B8
_081E4760:
	cmp r7, #0
	beq _081E47A0
	ldr r0, _081E477C @ =0x0000161B
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E47A0
	cmp r0, #7
	beq _081E478A
	cmp r0, #7
	bgt _081E4780
	cmp r0, #4
	beq _081E478A
	b _081E47A0
	.align 2, 0
_081E477C: .4byte 0x0000161B
_081E4780:
	cmp r0, #8
	beq _081E4796
	cmp r0, #0xb
	beq _081E4796
	b _081E47A0
_081E478A:
	cmp r2, #0
	bne _081E4792
	movs r2, #4
	b _081E47A0
_081E4792:
	movs r2, #7
	b _081E47A0
_081E4796:
	cmp r2, #0
	bne _081E479E
	movs r2, #8
	b _081E47A0
_081E479E:
	movs r2, #0xb
_081E47A0:
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
_081E47B8:
	strh r0, [r6, #2]
	adds r0, r2, #0
_081E47BC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e47c4
FUN_081e47c4: @ 0x081E47C4
	mov ip, r0
	movs r1, #0xb4
	lsls r1, r1, #1
	add r1, ip
	movs r3, #0
	movs r0, #0x98
	strh r0, [r1]
	adds r0, #0xd2
	add r0, ip
	movs r2, #0x68
	strh r2, [r0]
	movs r1, #0x84
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0xa0
	strh r0, [r1]
	adds r0, #0x6a
	add r0, ip
	strh r2, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #0xa8
	strh r0, [r1]
	mov r0, ip
	adds r0, #0xaa
	strh r2, [r0]
	subs r1, #0x60
	movs r0, #0xb0
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	strh r2, [r0]
	mov r1, ip
	ldr r0, [r1, #0x30]
	subs r2, #0x6a
	ands r0, r2
	str r0, [r1, #0x30]
	adds r1, #0x90
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #1
	add r1, ip
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _081E4834 @ =0x000015E4
	add r0, ip
	strh r3, [r0]
	bx lr
	.align 2, 0
_081E4834: .4byte 0x000015E4

	thumb_func_start FUN_081e4838
FUN_081e4838: @ 0x081E4838
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	ldr r1, _081E4878 @ =0x000015E2
	adds r0, r5, r1
	ldrh r4, [r0]
	movs r6, #0
	movs r2, #0
	ldr r0, _081E487C @ =0x000003E7
	cmp r4, r0
	ble _081E4858
	ldr r1, _081E4880 @ =0xFFFFFC18
_081E4850:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E4850
_081E4858:
	cmp r2, r7
	bgt _081E4860
	cmp r6, #0
	ble _081E4888
_081E4860:
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r3, _081E4884 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r6, #1
	b _081E4896
	.align 2, 0
_081E4878: .4byte 0x000015E2
_081E487C: .4byte 0x000003E7
_081E4880: .4byte 0xFFFFFC18
_081E4884: .4byte 0x00000AA8
_081E4888:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E4896:
	adds r2, r7, #0
	cmp r4, #0x63
	ble _081E48A4
_081E489C:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E489C
_081E48A4:
	cmp r2, r7
	bgt _081E48AC
	cmp r6, #0
	ble _081E48C4
_081E48AC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r3, _081E48C0 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r6, #1
	b _081E48D0
	.align 2, 0
_081E48C0: .4byte 0x00000AA8
_081E48C4:
	adds r0, r5, #0
	adds r0, #0xf0
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E48D0:
	adds r2, r7, #0
	cmp r4, #9
	ble _081E48DE
_081E48D6:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E48D6
_081E48DE:
	cmp r2, r7
	bgt _081E48E6
	cmp r6, #0
	ble _081E4900
_081E48E6:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r3, _081E48FC @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	adds r6, #1
	b _081E490C
	.align 2, 0
_081E48FC: .4byte 0x00000AA8
_081E4900:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E490C:
	adds r2, r7, #0
	cmp r4, #0
	ble _081E491A
_081E4912:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E4912
_081E491A:
	cmp r2, r7
	bgt _081E4922
	cmp r6, #0
	blt _081E4938
_081E4922:
	adds r0, r5, #0
	adds r0, #0x28
	ldr r3, _081E4934 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl Sprite_LoadSprite
	b _081E4940
	.align 2, 0
_081E4934: .4byte 0x00000AA8
_081E4938:
	ldr r0, [r5, #0x30]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x30]
_081E4940:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e4948
FUN_081e4948: @ 0x081E4948
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x9f
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _081E4994 @ =0x00000A08
	adds r0, r4, r1
	movs r5, #0
	movs r3, #0
	strh r3, [r0]
	ldr r2, _081E4998 @ =0x00000A0A
	adds r0, r4, r2
	strh r3, [r0]
	ldr r6, _081E499C @ =0x000009E8
	adds r0, r4, r6
	adds r2, #0xbe
	adds r1, r4, r2
	ldr r6, _081E49A0 @ =0x00000B2A
	adds r2, r4, r6
	ldrh r2, [r2]
	str r3, [sp]
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _081E49A4 @ =0x00001623
	adds r4, r4, r0
	strb r5, [r4]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E4994: .4byte 0x00000A08
_081E4998: .4byte 0x00000A0A
_081E499C: .4byte 0x000009E8
_081E49A0: .4byte 0x00000B2A
_081E49A4: .4byte 0x00001623

	thumb_func_start FUN_081e49a8
FUN_081e49a8: @ 0x081E49A8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r2, #0
	ldr r6, _081E49C4 @ =0x03003584
	movs r0, #0xb3
	lsls r0, r0, #4
	adds r7, r4, r0
_081E49B6:
	cmp r2, #3
	bne _081E49C8
	ldr r0, [r6]
	movs r3, #0xa5
	lsls r3, r3, #7
	b _081E49CC
	.align 2, 0
_081E49C4: .4byte 0x03003584
_081E49C8:
	ldr r0, [r6]
	ldr r3, _081E4A4C @ =0x00005260
_081E49CC:
	adds r1, r0, r3
	lsls r0, r2, #5
	adds r5, r2, #1
	adds r2, r1, #0
	adds r1, r0, r7
	movs r3, #0xf
_081E49D8:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081E49D8
	adds r2, r5, #0
	cmp r2, #3
	ble _081E49B6
	movs r2, #0
	ldr r1, _081E4A50 @ =0x00000B62
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r3, _081E4A54 @ =0x00000B52
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _081E4A58 @ =0x00000B64
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _081E4A5C @ =0x00000B66
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r4, r1
	subs r3, #0x26
	adds r1, r4, r3
	str r1, [r0]
	movs r3, #0xf2
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r3, #0xb7
	lsls r3, r3, #4
	adds r1, r4, r3
	str r1, [r0]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xbb
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r2, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4A4C: .4byte 0x00005260
_081E4A50: .4byte 0x00000B62
_081E4A54: .4byte 0x00000B52
_081E4A58: .4byte 0x00000B64
_081E4A5C: .4byte 0x00000B66

	thumb_func_start FUN_081e4a60
FUN_081e4a60: @ 0x081E4A60
	push {lr}
	adds r3, r0, #0
	movs r1, #0xbb
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081E4A8C
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081E4A8C
	movs r2, #0x12
	cmp r0, #0x19
	bls _081E4A8C
	movs r2, #0xa
	cmp r0, #0x21
	bls _081E4A8C
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081E4A8C
	movs r2, #0x12
_081E4A8C:
	movs r0, #0xbb
	lsls r0, r0, #4
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081E4AA4
	movs r0, #0
	strh r0, [r1]
_081E4AA4:
	ldr r1, _081E4AB4 @ =0x00000B48
	adds r0, r3, r1
	strh r2, [r0]
	adds r1, #0x40
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_081E4AB4: .4byte 0x00000B48

	thumb_func_start FUN_081e4ab8
FUN_081e4ab8: @ 0x081E4AB8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r1, _081E4AD0 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081E4AD4
	movs r4, #1
	b _081E4AF6
	.align 2, 0
_081E4AD0: .4byte 0x030044E0
_081E4AD4:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081E4AE0
	movs r4, #2
	b _081E4AF6
_081E4AE0:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081E4AEC
	movs r4, #4
	b _081E4AF6
_081E4AEC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081E4AF6
	movs r4, #8
_081E4AF6:
	ldrh r3, [r1]
	movs r2, #0xf0
	ands r2, r3
	cmp r2, #0
	beq _081E4B56
	ldr r0, _081E4B18 @ =0x00001619
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0xb
	bls _081E4B50
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _081E4B1C
	movs r0, #1
	b _081E4B26
	.align 2, 0
_081E4B18: .4byte 0x00001619
_081E4B1C:
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _081E4B28
	movs r0, #2
_081E4B26:
	orrs r4, r0
_081E4B28:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081E4B36
	movs r0, #4
	b _081E4B40
_081E4B36:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081E4B42
	movs r0, #8
_081E4B40:
	orrs r4, r0
_081E4B42:
	ldr r0, _081E4B4C @ =0x00001619
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _081E4B5C
	.align 2, 0
_081E4B4C: .4byte 0x00001619
_081E4B50:
	adds r0, #1
	strb r0, [r2]
	b _081E4B5C
_081E4B56:
	ldr r1, _081E4B64 @ =0x00001619
	adds r0, r5, r1
	strb r2, [r0]
_081E4B5C:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E4B64: .4byte 0x00001619

	thumb_func_start FUN_081e4b68
FUN_081e4b68: @ 0x081E4B68
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _081E4B88 @ =0x0000162C
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	bne _081E4B90
	bl FUN_08241400
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E4B90
	ldr r0, _081E4B8C @ =FUN_081e6388
	movs r2, #0x18
	b _081E4B94
	.align 2, 0
_081E4B88: .4byte 0x0000162C
_081E4B8C: .4byte FUN_081e6388
_081E4B90:
	ldr r0, _081E4BAC @ =FUN_081e6458
	movs r2, #0x19
_081E4B94:
	str r0, [r4, #0x18]
	ldr r0, _081E4BB0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4BB4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4BAC: .4byte FUN_081e6458
_081E4BB0: .4byte 0x00001614
_081E4BB4: .4byte 0x00001616

	thumb_func_start FUN_081e4bb8
FUN_081e4bb8: @ 0x081E4BB8
	ldr r1, _081E4BD0 @ =FUN_081e6458
	movs r3, #0x19
	str r1, [r0, #0x18]
	ldr r1, _081E4BD4 @ =0x00001614
	adds r2, r0, r1
	movs r1, #1
	strb r1, [r2]
	ldr r1, _081E4BD8 @ =0x00001616
	adds r0, r0, r1
	strb r3, [r0]
	bx lr
	.align 2, 0
_081E4BD0: .4byte FUN_081e6458
_081E4BD4: .4byte 0x00001614
_081E4BD8: .4byte 0x00001616

	thumb_func_start FUN_081e4bdc
FUN_081e4bdc: @ 0x081E4BDC
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _081E4C00 @ =0x0000162C
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	beq _081E4C10
	ldr r0, _081E4C04 @ =FUN_081e64cc
	movs r2, #0x1c
	str r0, [r4, #0x18]
	ldr r0, _081E4C08 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4C0C @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	b _081E4C2C
	.align 2, 0
_081E4C00: .4byte 0x0000162C
_081E4C04: .4byte FUN_081e64cc
_081E4C08: .4byte 0x00001614
_081E4C0C: .4byte 0x00001616
_081E4C10:
	adds r0, r4, #0
	bl FUN_081e5290
	adds r0, r4, #0
	bl FUN_081e23ac
	ldr r0, _081E4C34 @ =FUN_081e3958
	ldr r1, _081E4C38 @ =FUN_081e3cd4
	ldr r2, _081E4C3C @ =FUN_081e3cc0
	bl FUN_081e23c4
	adds r0, r4, #0
	bl FUN_081e4d04
_081E4C2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4C34: .4byte FUN_081e3958
_081E4C38: .4byte FUN_081e3cd4
_081E4C3C: .4byte FUN_081e3cc0

	thumb_func_start FUN_081e4c40
FUN_081e4c40: @ 0x081E4C40
	ldr r1, _081E4C58 @ =FUN_081e64cc
	movs r3, #0x1c
	str r1, [r0, #0x18]
	ldr r1, _081E4C5C @ =0x00001614
	adds r2, r0, r1
	movs r1, #1
	strb r1, [r2]
	ldr r1, _081E4C60 @ =0x00001616
	adds r0, r0, r1
	strb r3, [r0]
	bx lr
	.align 2, 0
_081E4C58: .4byte FUN_081e64cc
_081E4C5C: .4byte 0x00001614
_081E4C60: .4byte 0x00001616

	thumb_func_start FUN_081e4c64
FUN_081e4c64: @ 0x081E4C64
	push {r4, lr}
	sub sp, #4
	str r1, [sp]
	ldr r1, _081E4C94 @ =0x00001610
	adds r4, r0, r1
	ldr r1, _081E4C98 @ =0xFFBFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r0, _081E4C9C @ =0x03002CF0
	ldr r2, [r0]
	mov r0, sp
	movs r1, #0xa
	bl FUN_081e2510
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E4CA0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4]
	orrs r0, r1
	b _081E4CA6
	.align 2, 0
_081E4C94: .4byte 0x00001610
_081E4C98: .4byte 0xFFBFFFFF
_081E4C9C: .4byte 0x03002CF0
_081E4CA0:
	ldr r1, _081E4CB0 @ =0xFFFBFFFF
	ldr r0, [r4]
	ands r0, r1
_081E4CA6:
	str r0, [r4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4CB0: .4byte 0xFFFBFFFF

	thumb_func_start FUN_081e4cb4
FUN_081e4cb4: @ 0x081E4CB4
	push {r4, r5, lr}
	adds r4, r2, #0
	ldr r2, _081E4CE4 @ =0x00001610
	adds r5, r0, r2
	ldr r3, _081E4CE8 @ =0xFFBFFFFF
	ldr r2, [r5]
	ands r2, r3
	str r2, [r5]
	ldr r2, _081E4CEC @ =0x0000161C
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r1, #0
	adds r1, r4, #0
	bl FUN_081e2510
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E4CF0
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5]
	orrs r0, r1
	b _081E4CF6
	.align 2, 0
_081E4CE4: .4byte 0x00001610
_081E4CE8: .4byte 0xFFBFFFFF
_081E4CEC: .4byte 0x0000161C
_081E4CF0:
	ldr r1, _081E4D00 @ =0xFFF7FFFF
	ldr r0, [r5]
	ands r0, r1
_081E4CF6:
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4D00: .4byte 0xFFF7FFFF

	thumb_func_start FUN_081e4d04
FUN_081e4d04: @ 0x081E4D04
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3dec
	ldr r1, _081E4D64 @ =0x00000BB4
	adds r0, r4, r1
	movs r1, #0x10
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3594
	ldr r1, [r4, #0x1c]
	movs r0, #3
	movs r2, #1
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E4D68
	adds r0, r4, #0
	bl FUN_081e2d98
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E4D6E
	.align 2, 0
_081E4D64: .4byte 0x00000BB4
_081E4D68:
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E4D6E:
	ldr r2, _081E4DC4 @ =0x00001615
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	subs r2, #5
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _081E4DC8 @ =0x000015BC
	adds r0, r4, r1
	movs r1, #0x34
	bl ClearMemory
	ldr r2, _081E4DCC @ =0x00000E04
	adds r0, r4, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r1, _081E4DD0 @ =0x00000E28
	adds r0, r4, r1
	movs r1, #0x24
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e41e4
	ldr r0, _081E4DD4 @ =FUN_081e8110
	movs r2, #2
	str r0, [r4, #0x18]
	ldr r0, _081E4DD8 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4DDC @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4DC4: .4byte 0x00001615
_081E4DC8: .4byte 0x000015BC
_081E4DCC: .4byte 0x00000E04
_081E4DD0: .4byte 0x00000E28
_081E4DD4: .4byte FUN_081e8110
_081E4DD8: .4byte 0x00001614
_081E4DDC: .4byte 0x00001616

	thumb_func_start FUN_081e4de0
FUN_081e4de0: @ 0x081E4DE0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3dec
	adds r0, r4, #0
	bl FUN_081e3ce8
	adds r0, r4, #0
	bl FUN_081e32d8
	adds r0, r4, #0
	bl FUN_081e3444
	ldr r1, [r4, #0x1c]
	movs r0, #3
	movs r2, #1
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E4E60
	ldr r0, _081E4E54 @ =FUN_081e7db4
	str r0, [r4, #0x18]
	ldr r0, _081E4E58 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4E5C @ =0x00001616
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_081e2d98
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E4E78
	.align 2, 0
_081E4E54: .4byte FUN_081e7db4
_081E4E58: .4byte 0x00001614
_081E4E5C: .4byte 0x00001616
_081E4E60:
	ldr r0, _081E4EC0 @ =FUN_081e7fd0
	movs r1, #1
	str r0, [r4, #0x18]
	ldr r2, _081E4EC4 @ =0x00001614
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E4E78:
	ldr r0, _081E4EC8 @ =0x00001615
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _081E4ECC @ =0x00001610
	adds r1, r4, r2
	movs r0, #0x3e
	str r0, [r1]
	ldr r1, _081E4ED0 @ =0x000015BC
	adds r0, r4, r1
	movs r1, #0x34
	bl ClearMemory
	ldr r2, _081E4ED4 @ =0x00000E04
	adds r0, r4, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r1, _081E4ED8 @ =0x00000E28
	adds r0, r4, r1
	movs r1, #0x24
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e4388
	adds r0, r4, #0
	bl FUN_081e49a8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4EC0: .4byte FUN_081e7fd0
_081E4EC4: .4byte 0x00001614
_081E4EC8: .4byte 0x00001615
_081E4ECC: .4byte 0x00001610
_081E4ED0: .4byte 0x000015BC
_081E4ED4: .4byte 0x00000E04
_081E4ED8: .4byte 0x00000E28

	thumb_func_start FUN_081e4edc
FUN_081e4edc: @ 0x081E4EDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r7, #0
	bl FUN_081e2960
	adds r0, r7, #0
	bl FUN_081e3dec
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r2, _081E4F18 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E4F1C
	movs r0, #1
	b _081E4F1E
	.align 2, 0
_081E4F18: .4byte 0x00001610
_081E4F1C:
	movs r0, #0
_081E4F1E:
	adds r6, r0, #0
	cmp r6, #0
	bne _081E4F26
	b _081E511C
_081E4F26:
	ldr r0, _081E50CC @ =FUN_081e7414
	movs r1, #4
	str r0, [r7, #0x18]
	ldr r2, _081E50D0 @ =0x00001614
	adds r0, r7, r2
	movs r2, #0
	mov sl, r2
	movs r2, #1
	strb r2, [r0]
	ldr r2, _081E50D4 @ =0x00001616
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r7, r0
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r1, _081E50D8 @ =0x00001604
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r5]
	ldr r1, _081E50DC @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r4, _081E50E0 @ =0x030046A0
	ldr r2, [r4]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #2
	bl FUN_0822c398
	mov r2, sl
	str r2, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_081e3ea8
	movs r0, #0x81
	lsls r0, r0, #4
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	ldr r1, _081E50E4 @ =0x00001619
	adds r0, r7, r1
	mov r2, sl
	strb r2, [r0]
	adds r1, #2
	adds r0, r7, r1
	movs r2, #0x11
	mov sb, r2
	mov r1, sb
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r2, _081E50E8 @ =0x000014B4
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E50EC @ =0x000014CC
	adds r1, r7, r0
	movs r0, #0x30
	strh r0, [r1]
	ldr r2, _081E50F0 @ =0x000014CE
	adds r1, r7, r2
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E50F4 @ =0x00000E28
	adds r0, r7, r1
	movs r1, #0x24
	bl ClearMemory
	ldr r2, _081E50F8 @ =0x00000E04
	adds r0, r7, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xfa
	lsls r1, r1, #2
	mov r2, sl
	str r2, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sl
	str r2, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	ldr r0, [r5]
	ldr r1, _081E50FC @ =0x000015F0
	adds r4, r7, r1
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
	adds r0, r7, #0
	bl FUN_081e3680
	ldr r2, _081E5100 @ =0x000015E2
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_081e37a0
	ldr r1, _081E5104 @ =0x0000161A
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	subs r1, #0x12
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081E5108 @ =0x00001590
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	bl FUN_08049f5c
	ldr r0, _081E510C @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	bl FUN_08049e5c
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r0, _081E5110 @ =0x00001617
	adds r1, r7, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _081E5114 @ =0x00001514
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xde
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_081e49a8
	ldr r0, _081E510C @ =0x00001610
	adds r1, r7, r0
	ldr r0, _081E5118 @ =0x0000860E
	b _081E5242
	.align 2, 0
_081E50CC: .4byte FUN_081e7414
_081E50D0: .4byte 0x00001614
_081E50D4: .4byte 0x00001616
_081E50D8: .4byte 0x00001604
_081E50DC: .4byte 0x00000BB8
_081E50E0: .4byte 0x030046A0
_081E50E4: .4byte 0x00001619
_081E50E8: .4byte 0x000014B4
_081E50EC: .4byte 0x000014CC
_081E50F0: .4byte 0x000014CE
_081E50F4: .4byte 0x00000E28
_081E50F8: .4byte 0x00000E04
_081E50FC: .4byte 0x000015F0
_081E5100: .4byte 0x000015E2
_081E5104: .4byte 0x0000161A
_081E5108: .4byte 0x00001590
_081E510C: .4byte 0x00001610
_081E5110: .4byte 0x00001617
_081E5114: .4byte 0x00001514
_081E5118: .4byte 0x0000860E
_081E511C:
	ldr r0, _081E5254 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r7, #0x18]
	ldr r0, _081E5258 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E525C @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldr r2, _081E5260 @ =0x00001610
	adds r1, r7, r2
	movs r4, #2
	rsbs r4, r4, #0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E5264 @ =0x00001604
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #3
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_081e3ea8
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xa5
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r1, _081E5268 @ =0x00001619
	adds r0, r7, r1
	strb r6, [r0]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r2, _081E526C @ =0x000014B4
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, _081E5270 @ =0x000014CC
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, _081E5274 @ =0x000014CE
	adds r1, r7, r0
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E5278 @ =0x0000161A
	adds r5, r7, r1
	strb r2, [r5]
	ldr r2, _081E527C @ =0x00001608
	adds r4, r7, r2
	ldr r0, [r4]
	subs r2, #0x78
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r7, #0
	bl FUN_081e4544
	ldrb r1, [r5]
	ldr r2, _081E5280 @ =0x00001617
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, _081E5284 @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xfa
	lsls r1, r1, #2
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r6, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	mov r2, r8
	ldr r0, [r2]
	ldr r2, _081E5288 @ =0x000015F0
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0
	bl FUN_0804a2f8
	mov r2, r8
	ldr r0, [r2]
	bl FUN_0804a1f0
	ldr r0, _081E5260 @ =0x00001610
	adds r1, r7, r0
	ldr r0, _081E528C @ =0x0001010E
_081E5242:
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5254: .4byte FUN_081e6f28
_081E5258: .4byte 0x00001614
_081E525C: .4byte 0x00001616
_081E5260: .4byte 0x00001610
_081E5264: .4byte 0x00001604
_081E5268: .4byte 0x00001619
_081E526C: .4byte 0x000014B4
_081E5270: .4byte 0x000014CC
_081E5274: .4byte 0x000014CE
_081E5278: .4byte 0x0000161A
_081E527C: .4byte 0x00001608
_081E5280: .4byte 0x00001617
_081E5284: .4byte 0x030046A0
_081E5288: .4byte 0x000015F0
_081E528C: .4byte 0x0001010E

	thumb_func_start FUN_081e5290
FUN_081e5290: @ 0x081E5290
	push {lr}
	ldr r2, _081E52A8 @ =0x00001628
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E52A2
	movs r1, #0
	bl Script_ExecById
_081E52A2:
	pop {r0}
	bx r0
	.align 2, 0
_081E52A8: .4byte 0x00001628

	thumb_func_start FUN_081e52ac
FUN_081e52ac: @ 0x081E52AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E5384 @ =0x000014AC
	adds r7, r6, r0
	ldr r1, _081E5388 @ =0x00001614
	adds r5, r6, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5342
	ldr r2, _081E538C @ =0x00001599
	adds r4, r6, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r3, _081E5390 @ =0x00000E4C
	adds r1, r1, r3
	adds r1, r6, r1
	adds r0, r7, #0
	movs r2, #0xd
	bl FUN_0822f588
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, _081E5394 @ =0x00000E86
	adds r0, r0, r1
	movs r2, #0
	mov r8, r2
	movs r2, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	strh r1, [r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, _081E5398 @ =0x00000E94
	adds r1, r6, r3
	adds r1, r1, r0
	ldr r0, _081E539C @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xb8
	lsls r3, r3, #7
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _081E53A0 @ =0x000015B4
	adds r1, r6, r0
	movs r0, #0x30
	strh r0, [r1]
	ldr r3, _081E53A4 @ =0x000015B6
	adds r1, r6, r3
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E53A8 @ =0x0000159A
	adds r0, r6, r1
	strh r2, [r0]
	ldr r0, _081E53AC @ =0x0000038A
	bl PlaySound_082406e0
	mov r2, r8
	strb r2, [r5]
_081E5342:
	ldr r3, _081E53B0 @ =0x000014CC
	adds r1, r6, r3
	ldr r0, _081E53A0 @ =0x000015B4
	adds r2, r6, r0
	adds r3, #0xce
	adds r4, r6, r3
	ldrh r3, [r4]
	movs r0, #5
	str r0, [sp]
	adds r0, r1, #0
	bl FUN_08237970
	ldrh r0, [r4]
	cmp r0, #0xb
	bls _081E53C0
	movs r0, #0x30
	strh r0, [r7, #0x20]
	movs r0, #0x48
	strh r0, [r7, #0x22]
	ldr r0, _081E53B4 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r6, #0x18]
	ldr r0, _081E5388 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E53B8 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	ldr r0, _081E53BC @ =0x00000111
	bl PlaySound_082406e0
	b _081E53D2
	.align 2, 0
_081E5384: .4byte 0x000014AC
_081E5388: .4byte 0x00001614
_081E538C: .4byte 0x00001599
_081E5390: .4byte 0x00000E4C
_081E5394: .4byte 0x00000E86
_081E5398: .4byte 0x00000E94
_081E539C: .4byte 0x03003584
_081E53A0: .4byte 0x000015B4
_081E53A4: .4byte 0x000015B6
_081E53A8: .4byte 0x0000159A
_081E53AC: .4byte 0x0000038A
_081E53B0: .4byte 0x000014CC
_081E53B4: .4byte FUN_081e6f28
_081E53B8: .4byte 0x00001616
_081E53BC: .4byte 0x00000111
_081E53C0:
	ldr r2, _081E53E0 @ =0x00000808
	adds r0, r6, r2
	ldr r3, _081E53E4 @ =0x00000AC8
	adds r1, r6, r3
	bl FUN_082372cc
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081E53D2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E53E0: .4byte 0x00000808
_081E53E4: .4byte 0x00000AC8

	thumb_func_start FUN_081e53e8
FUN_081e53e8: @ 0x081E53E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E5454
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r6, _081E543C @ =0x00001514
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r7, _081E5440 @ =0x00001624
	adds r0, r5, r7
	strb r2, [r0]
	ldr r0, _081E5444 @ =0x000014B4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E5448 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r5, #0x18]
	ldr r3, _081E544C @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _081E5450 @ =0x00001616
	adds r0, r5, r6
	strb r1, [r0]
	b _081E5634
	.align 2, 0
_081E543C: .4byte 0x00001514
_081E5440: .4byte 0x00001624
_081E5444: .4byte 0x000014B4
_081E5448: .4byte FUN_081e653c
_081E544C: .4byte 0x00001614
_081E5450: .4byte 0x00001616
_081E5454:
	ldr r7, _081E54D8 @ =0x00001614
	adds r7, r7, r5
	mov r8, r7
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E54F8
	ldr r1, _081E54DC @ =0x00001608
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E54E0 @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r6, #0xa5
	lsls r6, r6, #4
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r7, _081E54E4 @ =0x0000161C
	adds r1, r5, r7
	ldr r0, _081E54E8 @ =0x03002CF0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _081E54EC @ =0x00000E28
	adds r1, r5, r0
	adds r2, #0x85
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r5, r2
	adds r0, r1, #0
	ldr r3, _081E54F0 @ =0x00000BC4
	adds r2, r2, r3
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	adds r0, r5, #0
	movs r2, #3
	bl FUN_081e4cb4
	ldr r6, _081E54F4 @ =0x00001622
	adds r0, r5, r6
	movs r1, #0
	strb r4, [r0]
	mov r7, r8
	strb r1, [r7]
	b _081E5634
	.align 2, 0
_081E54D8: .4byte 0x00001614
_081E54DC: .4byte 0x00001608
_081E54E0: .4byte 0x00001514
_081E54E4: .4byte 0x0000161C
_081E54E8: .4byte 0x03002CF0
_081E54EC: .4byte 0x00000E28
_081E54F0: .4byte 0x00000BC4
_081E54F4: .4byte 0x00001622
_081E54F8:
	adds r0, r5, #0
	bl FUN_081e2ee8
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E550A
	b _081E5634
_081E550A:
	ldr r1, _081E5520 @ =0x00001622
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _081E557C
	cmp r0, #2
	bgt _081E5524
	cmp r0, #1
	beq _081E552A
	b _081E5634
	.align 2, 0
_081E5520: .4byte 0x00001622
_081E5524:
	cmp r0, #3
	beq _081E55CC
	b _081E5634
_081E552A:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081E5540 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E5544
	movs r0, #1
	b _081E5546
	.align 2, 0
_081E5540: .4byte 0x00001610
_081E5544:
	movs r0, #0
_081E5546:
	cmp r0, #0
	beq _081E555C
	ldr r3, _081E5558 @ =0x00000E28
	adds r1, r5, r3
	adds r0, r5, #0
	movs r2, #3
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E5558: .4byte 0x00000E28
_081E555C:
	ldr r6, _081E5574 @ =0x00000E28
	adds r1, r5, r6
	adds r0, r5, #0
	movs r2, #4
	bl FUN_081e4cb4
	ldr r7, _081E5578 @ =0x00001622
	adds r1, r5, r7
	movs r0, #2
	strb r0, [r1]
	b _081E5634
	.align 2, 0
_081E5574: .4byte 0x00000E28
_081E5578: .4byte 0x00001622
_081E557C:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081E5590 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E5594
	movs r0, #1
	b _081E5596
	.align 2, 0
_081E5590: .4byte 0x00001610
_081E5594:
	movs r0, #0
_081E5596:
	cmp r0, #0
	beq _081E55AC
	ldr r3, _081E55A8 @ =0x00000E28
	adds r1, r5, r3
	adds r0, r5, #0
	movs r2, #4
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E55A8: .4byte 0x00000E28
_081E55AC:
	ldr r6, _081E55C4 @ =0x00000E28
	adds r1, r5, r6
	adds r0, r5, #0
	movs r2, #5
	bl FUN_081e4cb4
	ldr r7, _081E55C8 @ =0x00001622
	adds r1, r5, r7
	movs r0, #3
	strb r0, [r1]
	b _081E5634
	.align 2, 0
_081E55C4: .4byte 0x00000E28
_081E55C8: .4byte 0x00001622
_081E55CC:
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r0, _081E55E4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E55E8
	movs r0, #1
	b _081E55EA
	.align 2, 0
_081E55E4: .4byte 0x00001610
_081E55E8:
	movs r0, #0
_081E55EA:
	cmp r0, #0
	beq _081E5600
	ldr r2, _081E55FC @ =0x00000E28
	adds r1, r5, r2
	adds r0, r5, #0
	movs r2, #5
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E55FC: .4byte 0x00000E28
_081E5600:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5610
	movs r0, #1
	b _081E5612
_081E5610:
	movs r0, #0
_081E5612:
	cmp r0, #0
	beq _081E5634
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5634
	ldr r0, _081E5640 @ =FUN_081e57f4
	movs r2, #0xa
	str r0, [r5, #0x18]
	ldr r3, _081E5644 @ =0x00001614
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081E5648 @ =0x00001616
	adds r0, r5, r6
	strb r2, [r0]
_081E5634:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5640: .4byte FUN_081e57f4
_081E5644: .4byte 0x00001614
_081E5648: .4byte 0x00001616

	thumb_func_start FUN_081e564c
FUN_081e564c: @ 0x081E564C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E56C0
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E56A8 @ =0x00001514
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E56AC @ =0x000014B4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E56B0 @ =0x00001624
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _081E56B4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r5, #0x18]
	ldr r3, _081E56B8 @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081E56BC @ =0x00001616
	adds r0, r5, r2
	strb r1, [r0]
	b _081E57E0
	.align 2, 0
_081E56A8: .4byte 0x00001514
_081E56AC: .4byte 0x000014B4
_081E56B0: .4byte 0x00001624
_081E56B4: .4byte FUN_081e653c
_081E56B8: .4byte 0x00001614
_081E56BC: .4byte 0x00001616
_081E56C0:
	ldr r3, _081E5720 @ =0x00001614
	adds r6, r5, r3
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E573C
	ldr r1, _081E5724 @ =0x00001608
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E5728 @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r2, _081E572C @ =0x0000161C
	adds r1, r5, r2
	ldr r0, _081E5730 @ =0x03002CF0
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xb
	bl FUN_081e4cb4
	ldr r3, _081E5734 @ =0x00001618
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, _081E5738 @ =0x00001622
	adds r0, r5, r1
	strb r4, [r0]
	strb r2, [r6]
	b _081E57E0
	.align 2, 0
_081E5720: .4byte 0x00001614
_081E5724: .4byte 0x00001608
_081E5728: .4byte 0x00001514
_081E572C: .4byte 0x0000161C
_081E5730: .4byte 0x03002CF0
_081E5734: .4byte 0x00001618
_081E5738: .4byte 0x00001622
_081E573C:
	adds r0, r5, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r3, _081E5758 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E575C
	movs r0, #1
	b _081E575E
	.align 2, 0
_081E5758: .4byte 0x00001610
_081E575C:
	movs r0, #0
_081E575E:
	cmp r0, #0
	beq _081E577C
	ldr r0, _081E5774 @ =0x000015E2
	adds r1, r5, r0
	ldr r2, _081E5778 @ =0x00001618
	adds r0, r5, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_081e4cb4
	b _081E57E0
	.align 2, 0
_081E5774: .4byte 0x000015E2
_081E5778: .4byte 0x00001618
_081E577C:
	ldr r3, _081E57A0 @ =0x00001622
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E57AC
	ldr r0, _081E57A4 @ =0x000015E2
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_081e4cb4
	ldr r2, _081E57A8 @ =0x00001618
	adds r1, r5, r2
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #2
	strb r0, [r4]
	b _081E57E0
	.align 2, 0
_081E57A0: .4byte 0x00001622
_081E57A4: .4byte 0x000015E2
_081E57A8: .4byte 0x00001618
_081E57AC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E57BC
	movs r0, #1
	b _081E57BE
_081E57BC:
	movs r0, #0
_081E57BE:
	cmp r0, #0
	beq _081E57E0
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E57E0
	ldr r0, _081E57E8 @ =FUN_081e57f4
	movs r2, #0xa
	str r0, [r5, #0x18]
	ldr r3, _081E57EC @ =0x00001614
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E57F0 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
_081E57E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E57E8: .4byte FUN_081e57f4
_081E57EC: .4byte 0x00001614
_081E57F0: .4byte 0x00001616

	thumb_func_start FUN_081e57f4
FUN_081e57f4: @ 0x081E57F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5824 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E580E
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081e4c64
	movs r0, #0
	strb r0, [r5]
_081E580E:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r3, _081E5828 @ =0x00001610
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E582C
	movs r0, #1
	b _081E582E
	.align 2, 0
_081E5824: .4byte 0x00001614
_081E5828: .4byte 0x00001610
_081E582C:
	movs r0, #0
_081E582E:
	cmp r0, #0
	beq _081E583C
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081e4c64
	b _081E58D6
_081E583C:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa
	bne _081E5868
	adds r1, #4
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _081E5860 @ =FUN_081e653c
	movs r2, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E5864 @ =0x00001614
	adds r0, r4, r3
	strb r1, [r0]
	b _081E58BA
	.align 2, 0
_081E5860: .4byte FUN_081e653c
_081E5864: .4byte 0x00001614
_081E5868:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5878
	movs r0, #1
	b _081E587A
_081E5878:
	movs r0, #0
_081E587A:
	cmp r0, #0
	beq _081E58D0
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	beq _081E58A2
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E589C
	movs r0, #1
	b _081E589E
_081E589C:
	movs r0, #0
_081E589E:
	cmp r0, #0
	beq _081E58D0
_081E58A2:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E58D0
	ldr r0, _081E58C4 @ =FUN_081e58dc
	movs r2, #0xc
	str r0, [r4, #0x18]
	ldr r3, _081E58C8 @ =0x00001614
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081E58BA:
	ldr r1, _081E58CC @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	b _081E58D6
	.align 2, 0
_081E58C4: .4byte FUN_081e58dc
_081E58C8: .4byte 0x00001614
_081E58CC: .4byte 0x00001616
_081E58D0:
	adds r0, r4, #0
	bl FUN_081e2ee8
_081E58D6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e58dc
FUN_081e58dc: @ 0x081E58DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081E5A6C @ =0x00001614
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E58F8
	b _081E5A48
_081E58F8:
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r2, _081E5A70 @ =0x00001610
	adds r1, r7, r2
	movs r3, #2
	rsbs r3, r3, #0
	mov sb, r3
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	movs r0, #0x14
	str r0, [sp]
	movs r6, #0
	str r6, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_0822bdb8
	adds r0, r7, #0
	bl FUN_081e47c4
	adds r0, r7, #0
	bl FUN_081e4838
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #4
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r4, r7, r0
	ldr r0, [r4]
	movs r5, #2
	str r5, [sp]
	movs r1, #0xd
	movs r2, #4
	movs r3, #0xa
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r1, _081E5A74 @ =0x000015F0
	adds r1, r1, r7
	mov r8, r1
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r2, _081E5A78 @ =0x00001604
	adds r4, r7, r2
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #0xd
	movs r2, #0xa
	movs r3, #0xa
	bl FUN_0804a38c
	ldr r0, [r4]
	mov r3, r8
	ldr r1, [r3]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r0, _081E5A7C @ =0x00001608
	adds r4, r7, r0
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #8
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E5A80 @ =0x00001590
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r3, _081E5A84 @ =0x00000E28
	adds r5, r7, r3
	ldr r1, _081E5A88 @ =0x0000159C
	adds r2, r7, r1
	adds r1, r5, #0
	bl FUN_08094d30
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r2, _081E5A8C @ =0x000014AC
	adds r0, r7, r2
	ldr r3, _081E5A90 @ =0x0000156C
	adds r1, r7, r3
	ldrb r2, [r5]
	bl Sprite_LoadSprite
	ldr r0, _081E5A94 @ =0x000014CC
	adds r1, r7, r0
	movs r5, #0
	movs r0, #0x20
	strh r0, [r1]
	ldr r2, _081E5A98 @ =0x000014CE
	adds r1, r7, r2
	movs r0, #0x38
	strh r0, [r1]
	ldr r3, _081E5A9C @ =0x000014B4
	adds r1, r7, r3
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r3, _081E5AA0 @ =0x0000160C
	adds r4, r7, r3
	ldr r0, [r4]
	mov r2, r8
	ldr r1, [r2]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xb
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r7, #0
	bl FUN_081e4948
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r7, r3
	strh r6, [r0]
	ldr r1, _081E5AA4 @ =0x0000162A
	adds r0, r7, r1
	strh r6, [r0]
	mov r2, sl
	strb r5, [r2]
_081E5A48:
	ldr r3, _081E5AA8 @ =0x000009E8
	adds r6, r7, r3
	ldr r0, _081E5AAC @ =0x00000AC8
	adds r0, r0, r7
	mov r8, r0
	adds r0, r6, #0
	mov r1, r8
	bl FUN_082372cc
	ldr r2, _081E5AA4 @ =0x0000162A
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E5AB0
	adds r0, #1
	strh r0, [r1]
	b _081E5C24
	.align 2, 0
_081E5A6C: .4byte 0x00001614
_081E5A70: .4byte 0x00001610
_081E5A74: .4byte 0x000015F0
_081E5A78: .4byte 0x00001604
_081E5A7C: .4byte 0x00001608
_081E5A80: .4byte 0x00001590
_081E5A84: .4byte 0x00000E28
_081E5A88: .4byte 0x0000159C
_081E5A8C: .4byte 0x000014AC
_081E5A90: .4byte 0x0000156C
_081E5A94: .4byte 0x000014CC
_081E5A98: .4byte 0x000014CE
_081E5A9C: .4byte 0x000014B4
_081E5AA0: .4byte 0x0000160C
_081E5AA4: .4byte 0x0000162A
_081E5AA8: .4byte 0x000009E8
_081E5AAC: .4byte 0x00000AC8
_081E5AB0:
	ldr r0, _081E5AE8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081E5AF8
	adds r0, r7, #0
	movs r1, #9
	bl FUN_081e4c64
	ldr r3, _081E5AEC @ =0x00001618
	adds r1, r7, r3
	movs r2, #0
	movs r0, #9
	strb r0, [r1]
	ldr r1, _081E5AF0 @ =0x00001624
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081E5AF4 @ =FUN_081e5d14
	movs r2, #0x10
	str r0, [r7, #0x18]
	subs r3, #4
	adds r1, r7, r3
	movs r0, #1
	b _081E5BB8
	.align 2, 0
_081E5AE8: .4byte 0x030044E0
_081E5AEC: .4byte 0x00001618
_081E5AF0: .4byte 0x00001624
_081E5AF4: .4byte FUN_081e5d14
_081E5AF8:
	ldr r2, _081E5B28 @ =0x00001623
	adds r5, r7, r2
	ldrb r0, [r5]
	cmp r0, #0
	bne _081E5B78
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081E5B30
	ldr r3, _081E5B2C @ =0x00000B2C
	adds r0, r7, r3
	ldrh r2, [r0]
	str r4, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #1
	bl FUN_082370cc
	movs r0, #1
	strb r0, [r5]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E5BEE
	.align 2, 0
_081E5B28: .4byte 0x00001623
_081E5B2C: .4byte 0x00000B2C
_081E5B30:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081E5BEE
	adds r0, r7, #0
	movs r1, #3
	bl FUN_081e4c64
	ldr r0, _081E5B6C @ =FUN_081e5c40
	movs r2, #0xd
	str r0, [r7, #0x18]
	ldr r0, _081E5B70 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5B74 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0x9f
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E5C24
	.align 2, 0
_081E5B6C: .4byte FUN_081e5c40
_081E5B70: .4byte 0x00001614
_081E5B74: .4byte 0x00001616
_081E5B78:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _081E5BD4
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _081E5BEE
	adds r0, r7, #0
	movs r1, #9
	bl FUN_081e4c64
	ldr r3, _081E5BC4 @ =0x00001618
	adds r1, r7, r3
	movs r0, #9
	strb r0, [r1]
	ldr r1, _081E5BC8 @ =0x00001624
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x9f
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r0, _081E5BCC @ =FUN_081e5d14
	movs r2, #0x10
	str r0, [r7, #0x18]
	subs r3, #4
	adds r1, r7, r3
	movs r0, #1
_081E5BB8:
	strb r0, [r1]
	ldr r1, _081E5BD0 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	b _081E5C24
	.align 2, 0
_081E5BC4: .4byte 0x00001618
_081E5BC8: .4byte 0x00001624
_081E5BCC: .4byte FUN_081e5d14
_081E5BD0: .4byte 0x00001616
_081E5BD4:
	ldr r2, _081E5C34 @ =0x00000B2A
	adds r0, r7, r2
	ldrh r2, [r0]
	str r4, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #1
	bl FUN_082370cc
	strb r4, [r5]
	movs r0, #0xdc
	bl PlaySound_082406e0
_081E5BEE:
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r7, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _081E5C24
	ldr r2, _081E5C38 @ =0x00001624
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081E5C3C @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r7, #0x18]
	subs r3, #0xc
	adds r0, r7, r3
	movs r2, #1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E5C24:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5C34: .4byte 0x00000B2A
_081E5C38: .4byte 0x00001624
_081E5C3C: .4byte FUN_081e653c

	thumb_func_start FUN_081e5c40
FUN_081e5c40: @ 0x081E5C40
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5C88 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5C6A
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081E5C8C @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	strb r0, [r5]
_081E5C6A:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5C90 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081E5C94
	movs r0, #1
	b _081E5C96
	.align 2, 0
_081E5C88: .4byte 0x00001614
_081E5C8C: .4byte 0x0000160C
_081E5C90: .4byte 0x00001610
_081E5C94:
	movs r0, #0
_081E5C96:
	cmp r0, #0
	beq _081E5CA4
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081e4c64
	b _081E5CFC
_081E5CA4:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5CFC
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081E5CBE
	movs r0, #1
	b _081E5CC0
_081E5CBE:
	movs r0, #0
_081E5CC0:
	cmp r0, #0
	beq _081E5CFC
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bne _081E5CDC
	ldr r0, _081E5CD8 @ =FUN_081e5dc8
	movs r2, #0xe
	b _081E5CEC
	.align 2, 0
_081E5CD8: .4byte FUN_081e5dc8
_081E5CDC:
	cmp r0, #9
	bne _081E5CFC
	ldr r0, _081E5D04 @ =0x00001624
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081E5D08 @ =FUN_081e653c
	movs r2, #0x11
_081E5CEC:
	str r0, [r4, #0x18]
	ldr r0, _081E5D0C @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5D10 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E5CFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E5D04: .4byte 0x00001624
_081E5D08: .4byte FUN_081e653c
_081E5D0C: .4byte 0x00001614
_081E5D10: .4byte 0x00001616

	thumb_func_start FUN_081e5d14
FUN_081e5d14: @ 0x081E5D14
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5D5C @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5D3E
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081E5D60 @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	strb r0, [r5]
_081E5D3E:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5D64 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081E5D68
	movs r0, #1
	b _081E5D6A
	.align 2, 0
_081E5D5C: .4byte 0x00001614
_081E5D60: .4byte 0x0000160C
_081E5D64: .4byte 0x00001610
_081E5D68:
	movs r0, #0
_081E5D6A:
	cmp r0, #0
	beq _081E5D80
	ldr r1, _081E5D7C @ =0x00001618
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_081e4c64
	b _081E5DB4
	.align 2, 0
_081E5D7C: .4byte 0x00001618
_081E5D80:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5DB4
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081E5D9A
	movs r0, #1
	b _081E5D9C
_081E5D9A:
	movs r0, #0
_081E5D9C:
	cmp r0, #0
	beq _081E5DB4
	ldr r0, _081E5DBC @ =FUN_081e653c
	movs r2, #0x11
	str r0, [r4, #0x18]
	ldr r0, _081E5DC0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5DC4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E5DB4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E5DBC: .4byte FUN_081e653c
_081E5DC0: .4byte 0x00001614
_081E5DC4: .4byte 0x00001616

	thumb_func_start FUN_081e5dc8
FUN_081e5dc8: @ 0x081E5DC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _081E5EF4 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E5DE0
	b _081E5FA8
_081E5DE0:
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r2, _081E5EF8 @ =0x00001610
	adds r2, r2, r7
	mov r8, r2
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E5EFC @ =0x00001604
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E5F00 @ =0x00001608
	adds r6, r7, r0
	ldr r0, [r6]
	bl FUN_0804a210
	ldr r1, _081E5F04 @ =0x0000160C
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_0804a210
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, [r7, #0x20]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #6
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E5F08 @ =0x000015F0
	adds r2, r2, r7
	mov sb, r2
	ldr r1, [r2]
	bl FUN_0804a240
	adds r0, r7, #0
	bl FUN_081e2e24
	ldr r1, _081E5F0C @ =0x00000E28
	adds r0, r7, r1
	ldr r2, _081E5F10 @ =0x0000159C
	adds r5, r7, r2
	adds r1, r5, #0
	bl FUN_08094c6c
	ldr r0, [r4]
	ldr r2, _081E5F14 @ =0x000015E2
	adds r1, r7, r2
	ldrh r2, [r1]
	movs r1, #0
	bl FUN_0804a3e4
	ldr r0, [r4]
	ldr r1, _081E5F18 @ =0x000015A4
	adds r2, r7, r1
	movs r1, #3
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #4
	adds r2, r5, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r1, _081E5F1C @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, [r6]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0xf
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r6]
	mov r2, sb
	ldr r1, [r2]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #0x12
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	movs r1, #0x80
	lsls r1, r1, #9
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5F20
	movs r0, #1
	b _081E5F22
	.align 2, 0
_081E5EF4: .4byte 0x00001614
_081E5EF8: .4byte 0x00001610
_081E5EFC: .4byte 0x00001604
_081E5F00: .4byte 0x00001608
_081E5F04: .4byte 0x0000160C
_081E5F08: .4byte 0x000015F0
_081E5F0C: .4byte 0x00000E28
_081E5F10: .4byte 0x0000159C
_081E5F14: .4byte 0x000015E2
_081E5F18: .4byte 0x000015A4
_081E5F1C: .4byte 0x00000BB8
_081E5F20:
	movs r0, #0
_081E5F22:
	cmp r0, #0
	beq _081E5F5C
	ldr r1, _081E5F40 @ =0x000015E2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E5F48
	ldr r2, _081E5F44 @ =0x0000160C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc
	bl FUN_0804a2f8
	b _081E5F88
	.align 2, 0
_081E5F40: .4byte 0x000015E2
_081E5F44: .4byte 0x0000160C
_081E5F48:
	ldr r1, _081E5F58 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x17
	bl FUN_0804a2f8
	b _081E5F88
	.align 2, 0
_081E5F58: .4byte 0x0000160C
_081E5F5C:
	ldr r2, _081E5F74 @ =0x000015E2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E5F7C
	ldr r1, _081E5F78 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xd
	bl FUN_0804a2f8
	b _081E5F88
	.align 2, 0
_081E5F74: .4byte 0x000015E2
_081E5F78: .4byte 0x0000160C
_081E5F7C:
	ldr r2, _081E5FC0 @ =0x0000160C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x18
	bl FUN_0804a2f8
_081E5F88:
	ldr r1, _081E5FC0 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a1f0
	adds r0, r7, #0
	movs r1, #7
	bl FUN_081e4c64
	ldr r0, _081E5FC4 @ =0x00000123
	bl PlaySound_082406e0
	ldr r2, _081E5FC8 @ =0x00001614
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_081E5FA8:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5FCC @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E5FD0
	movs r0, #1
	b _081E5FD2
	.align 2, 0
_081E5FC0: .4byte 0x0000160C
_081E5FC4: .4byte 0x00000123
_081E5FC8: .4byte 0x00001614
_081E5FCC: .4byte 0x00001610
_081E5FD0:
	movs r0, #0
_081E5FD2:
	cmp r0, #0
	beq _081E5FE0
	adds r0, r7, #0
	movs r1, #7
	bl FUN_081e4c64
	b _081E6022
_081E5FE0:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5FF0
	movs r0, #1
	b _081E5FF2
_081E5FF0:
	movs r0, #0
_081E5FF2:
	cmp r0, #0
	beq _081E6022
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #7
	bne _081E6022
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6022
	ldr r0, _081E6030 @ =FUN_081e603c
	movs r2, #0xf
	str r0, [r7, #0x18]
	ldr r0, _081E6034 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6038 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
_081E6022:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E6030: .4byte FUN_081e603c
_081E6034: .4byte 0x00001614
_081E6038: .4byte 0x00001616

	thumb_func_start FUN_081e603c
FUN_081e603c: @ 0x081E603C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E6068 @ =0x00001614
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E6056
	ldr r1, _081E606C @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E6056:
	ldr r0, _081E606C @ =0x0000162A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E6070
	adds r0, #1
	strh r0, [r1]
	b _081E60A8
	.align 2, 0
_081E6068: .4byte 0x00001614
_081E606C: .4byte 0x0000162A
_081E6070:
	ldr r0, _081E60B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E60B4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E60A8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081e4c64
	ldr r1, _081E60B8 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E60BC @ =FUN_081e60c8
	movs r2, #0x16
	str r0, [r4, #0x18]
	ldr r0, _081E60C0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E60C4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E60A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E60B0: .4byte 0x030044E0
_081E60B4: .4byte 0x0000030F
_081E60B8: .4byte 0x00001608
_081E60BC: .4byte FUN_081e60c8
_081E60C0: .4byte 0x00001614
_081E60C4: .4byte 0x00001616

	thumb_func_start FUN_081e60c8
FUN_081e60c8: @ 0x081E60C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E60FC @ =0x00001614
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E60E0
	ldr r0, _081E6100 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
_081E60E0:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E6104 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E6108
	movs r0, #1
	b _081E610A
	.align 2, 0
_081E60FC: .4byte 0x00001614
_081E6100: .4byte 0x00001617
_081E6104: .4byte 0x00001610
_081E6108:
	movs r0, #0
_081E610A:
	cmp r0, #0
	beq _081E6118
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081e4c64
	b _081E6164
_081E6118:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6128
	movs r0, #1
	b _081E612A
_081E6128:
	movs r0, #0
_081E612A:
	cmp r0, #0
	beq _081E6164
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #8
	bne _081E6164
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6164
	ldr r1, _081E616C @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E6170 @ =FUN_081e617c
	movs r2, #0x17
	str r0, [r4, #0x18]
	ldr r0, _081E6174 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6178 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6164:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E616C: .4byte 0x0000160C
_081E6170: .4byte FUN_081e617c
_081E6174: .4byte 0x00001614
_081E6178: .4byte 0x00001616

	thumb_func_start FUN_081e617c
FUN_081e617c: @ 0x081E617C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E6248 @ =0x00001614
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E6210
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldr r1, _081E624C @ =0x00001610
	adds r2, r6, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, [r6, #0x20]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r2, _081E6250 @ =0x0000160C
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r3, _081E6254 @ =0x000015F4
	adds r1, r6, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #6
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	bl FUN_081e25f0
	movs r0, #1
	bl sound_fadeout_08240440
	ldr r4, _081E6258 @ =0x0000162A
	adds r0, r6, r4
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
_081E6210:
	ldr r0, _081E6258 @ =0x0000162A
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x3b
	bne _081E622C
	bl FUN_081e25d8
	movs r2, #0x80
	lsls r2, r2, #0xe
	ldr r3, _081E624C @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E622C:
	ldrh r0, [r4]
	cmp r0, #0x3c
	beq _081E6234
	b _081E636A
_081E6234:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r4, _081E624C @ =0x00001610
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E625C
	movs r0, #1
	b _081E625E
	.align 2, 0
_081E6248: .4byte 0x00001614
_081E624C: .4byte 0x00001610
_081E6250: .4byte 0x0000160C
_081E6254: .4byte 0x000015F4
_081E6258: .4byte 0x0000162A
_081E625C:
	movs r0, #0
_081E625E:
	cmp r0, #0
	beq _081E62AC
	ldr r1, _081E6298 @ =0x00000E28
	adds r0, r6, r1
	bl FUN_08242b88
	ldr r3, _081E629C @ =0x030046A0
	ldr r0, [r3]
	movs r4, #0x91
	lsls r4, r4, #4
	adds r2, r0, r4
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r4, _081E62A0 @ =0x000015E2
	adds r0, r6, r4
	ldrh r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081E6286
	movs r1, #0
_081E6286:
	strh r1, [r2]
	ldr r0, [r3]
	ldr r2, _081E62A4 @ =0x0000091A
	adds r1, r0, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #1
	ldr r2, _081E62A8 @ =0x0000270F
	b _081E62E6
	.align 2, 0
_081E6298: .4byte 0x00000E28
_081E629C: .4byte 0x030046A0
_081E62A0: .4byte 0x000015E2
_081E62A4: .4byte 0x0000091A
_081E62A8: .4byte 0x0000270F
_081E62AC:
	ldr r4, _081E6310 @ =0x00001599
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl FUN_08242c08
	ldr r4, _081E6314 @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r3, r0, r1
	ldr r2, _081E6318 @ =0x000015E2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r0, [r3, r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r2, _081E631C @ =0x0000270F
	cmp r0, r2
	ble _081E62D8
	adds r0, r2, #0
_081E62D8:
	strh r0, [r3]
	ldr r0, [r4]
	ldr r3, _081E6320 @ =0x00000918
	adds r1, r0, r3
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r0, #1
_081E62E6:
	cmp r0, r2
	ble _081E62EC
	adds r0, r2, #0
_081E62EC:
	strh r0, [r1]
	bl FUN_082413b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6330
	ldr r0, _081E6324 @ =FUN_081e6458
	movs r2, #0x19
	str r0, [r6, #0x18]
	ldr r0, _081E6328 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E632C @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	b _081E6374
	.align 2, 0
_081E6310: .4byte 0x00001599
_081E6314: .4byte 0x030046A0
_081E6318: .4byte 0x000015E2
_081E631C: .4byte 0x0000270F
_081E6320: .4byte 0x00000918
_081E6324: .4byte FUN_081e6458
_081E6328: .4byte 0x00001614
_081E632C: .4byte 0x00001616
_081E6330:
	movs r0, #0x96
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_081d9d38
	cmp r0, #0
	bne _081E6360
	ldr r0, _081E6354 @ =FUN_081e6458
	movs r2, #0x19
	str r0, [r6, #0x18]
	ldr r3, _081E6358 @ =0x00001614
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r4, _081E635C @ =0x00001616
	adds r0, r6, r4
	strb r2, [r0]
	b _081E6374
	.align 2, 0
_081E6354: .4byte FUN_081e6458
_081E6358: .4byte 0x00001614
_081E635C: .4byte 0x00001616
_081E6360:
	ldr r1, _081E637C @ =FUN_081e4b68
	ldr r2, _081E6380 @ =FUN_081e4bb8
	adds r0, r6, #0
	bl FUN_081d9d88
_081E636A:
	ldr r0, _081E6384 @ =0x0000162A
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E6374:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E637C: .4byte FUN_081e4b68
_081E6380: .4byte FUN_081e4bb8
_081E6384: .4byte 0x0000162A

	thumb_func_start FUN_081e6388
FUN_081e6388: @ 0x081E6388
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _081E63AC @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6410
	movs r2, #1
	ldr r0, _081E63B0 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E63B4
	movs r0, #1
	b _081E63B6
	.align 2, 0
_081E63AC: .4byte 0x00001614
_081E63B0: .4byte 0x00001610
_081E63B4:
	movs r0, #0
_081E63B6:
	cmp r0, #0
	beq _081E63CC
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081E63CC:
	ldr r1, _081E63FC @ =0x0000160C
	adds r4, r5, r1
	ldr r0, [r4]
	ldr r2, _081E6400 @ =0x000015F4
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0804a2f8
	ldr r0, _081E6404 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r0, _081E6408 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E640C @ =0x00001614
	adds r0, r5, r1
	strb r2, [r0]
	b _081E6448
	.align 2, 0
_081E63FC: .4byte 0x0000160C
_081E6400: .4byte 0x000015F4
_081E6404: .4byte 0x000002AE
_081E6408: .4byte 0x0000162A
_081E640C: .4byte 0x00001614
_081E6410:
	ldr r2, _081E6434 @ =0x0000162A
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _081E6448
	movs r0, #0xc8
	lsls r0, r0, #1
	movs r1, #0
	bl FUN_081d9d38
	cmp r0, #0
	bne _081E6438
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_081e4c40
	b _081E6448
	.align 2, 0
_081E6434: .4byte 0x0000162A
_081E6438:
	ldr r1, _081E6450 @ =FUN_081e4bdc
	ldr r2, _081E6454 @ =FUN_081e4c40
	adds r0, r5, #0
	bl FUN_081d9d88
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081E6448:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6450: .4byte FUN_081e4bdc
_081E6454: .4byte FUN_081e4c40

	thumb_func_start FUN_081e6458
FUN_081e6458: @ 0x081E6458
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E64A8 @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E6496
	ldr r2, _081E64AC @ =0x0000160C
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #0x18
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #5
	bl FUN_0804a2f8
	ldr r0, _081E64B0 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
	bl FUN_081e260c
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081E6496:
	ldr r2, _081E64B0 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E64B4
	adds r0, #1
	strh r0, [r1]
	b _081E64C2
	.align 2, 0
_081E64A8: .4byte 0x00001614
_081E64AC: .4byte 0x0000160C
_081E64B0: .4byte 0x0000162A
_081E64B4:
	movs r2, #0x80
	lsls r2, r2, #0x10
	ldr r0, _081E64C8 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E64C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E64C8: .4byte 0x00001610

	thumb_func_start FUN_081e64cc
FUN_081e64cc: @ 0x081E64CC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E6518 @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E6508
	ldr r2, _081E651C @ =0x0000160C
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #0x18
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r0, _081E6520 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
	bl FUN_081e260c
_081E6508:
	ldr r2, _081E6520 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E6524
	adds r0, #1
	strh r0, [r1]
	b _081E6532
	.align 2, 0
_081E6518: .4byte 0x00001614
_081E651C: .4byte 0x0000160C
_081E6520: .4byte 0x0000162A
_081E6524:
	movs r2, #0x80
	lsls r2, r2, #0x10
	ldr r0, _081E6538 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E6532:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E6538: .4byte 0x00001610

	thumb_func_start FUN_081e653c
FUN_081e653c: @ 0x081E653C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _081E6584 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E654E
	b _081E664A
_081E654E:
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, [r7, #0x20]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r1, #1
	ldr r2, _081E6588 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E658C
	movs r0, #1
	b _081E658E
	.align 2, 0
_081E6584: .4byte 0x00001614
_081E6588: .4byte 0x00001610
_081E658C:
	movs r0, #0
_081E658E:
	cmp r0, #0
	beq _081E65A8
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _081E6660 @ =0x00001610
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081E65A8:
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E6664 @ =0x00001604
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E6668 @ =0x00001608
	adds r5, r7, r0
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r1, _081E666C @ =0x0000160C
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #6
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E6670 @ =0x000015F0
	adds r6, r7, r2
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xe
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r0, [r5]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0xf
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5]
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0x12
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #5
	bl FUN_081e4c64
	ldr r0, _081E6674 @ =0x00001614
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
_081E664A:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E6660 @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E6678
	movs r0, #1
	b _081E667A
	.align 2, 0
_081E6660: .4byte 0x00001610
_081E6664: .4byte 0x00001604
_081E6668: .4byte 0x00001608
_081E666C: .4byte 0x0000160C
_081E6670: .4byte 0x000015F0
_081E6674: .4byte 0x00001614
_081E6678:
	movs r0, #0
_081E667A:
	cmp r0, #0
	beq _081E6688
	adds r0, r7, #0
	movs r1, #5
	bl FUN_081e4c64
	b _081E66CA
_081E6688:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6698
	movs r0, #1
	b _081E669A
_081E6698:
	movs r0, #0
_081E669A:
	cmp r0, #0
	beq _081E66CA
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _081E66CA
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E66CA
	ldr r0, _081E66D4 @ =FUN_081e66e0
	movs r2, #0x12
	str r0, [r7, #0x18]
	ldr r0, _081E66D8 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E66DC @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
_081E66CA:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E66D4: .4byte FUN_081e66e0
_081E66D8: .4byte 0x00001614
_081E66DC: .4byte 0x00001616

	thumb_func_start FUN_081e66e0
FUN_081e66e0: @ 0x081E66E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E670C @ =0x00001614
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E66FA
	ldr r1, _081E6710 @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E66FA:
	ldr r0, _081E6710 @ =0x0000162A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E6714
	adds r0, #1
	strh r0, [r1]
	b _081E674C
	.align 2, 0
_081E670C: .4byte 0x00001614
_081E6710: .4byte 0x0000162A
_081E6714:
	ldr r0, _081E6754 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E6758 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E674C
	adds r0, r4, #0
	movs r1, #6
	bl FUN_081e4c64
	ldr r1, _081E675C @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E6760 @ =FUN_081e676c
	movs r2, #0x13
	str r0, [r4, #0x18]
	ldr r0, _081E6764 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6768 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E674C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E6754: .4byte 0x030044E0
_081E6758: .4byte 0x0000030F
_081E675C: .4byte 0x00001608
_081E6760: .4byte FUN_081e676c
_081E6764: .4byte 0x00001614
_081E6768: .4byte 0x00001616

	thumb_func_start FUN_081e676c
FUN_081e676c: @ 0x081E676C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E67A0 @ =0x00001614
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E6784
	ldr r0, _081E67A4 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
_081E6784:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E67A8 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E67AC
	movs r0, #1
	b _081E67AE
	.align 2, 0
_081E67A0: .4byte 0x00001614
_081E67A4: .4byte 0x00001617
_081E67A8: .4byte 0x00001610
_081E67AC:
	movs r0, #0
_081E67AE:
	cmp r0, #0
	beq _081E67BC
	adds r0, r4, #0
	movs r1, #6
	bl FUN_081e4c64
	b _081E680A
_081E67BC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E67CC
	movs r0, #1
	b _081E67CE
_081E67CC:
	movs r0, #0
_081E67CE:
	cmp r0, #0
	beq _081E680A
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #6
	bne _081E680A
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E680A
	ldr r1, _081E6800 @ =0x00001624
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6804
	cmp r0, #1
	bne _081E680A
	adds r0, r4, #0
	bl FUN_081e4de0
	b _081E680A
	.align 2, 0
_081E6800: .4byte 0x00001624
_081E6804:
	adds r0, r4, #0
	bl FUN_081e4edc
_081E680A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e6810
FUN_081e6810: @ 0x081E6810
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E6890 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E6838
	ldr r1, _081E6894 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r3, _081E6898 @ =0x00001514
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r5]
_081E6838:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E68AC
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6898 @ =0x00001514
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E689C @ =0x000014B4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E68A0 @ =0x00001624
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _081E68A4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E6890 @ =0x00001614
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081E68A8 @ =0x00001616
	adds r0, r4, r2
	strb r1, [r0]
	b _081E6A06
	.align 2, 0
_081E6890: .4byte 0x00001614
_081E6894: .4byte 0x00001608
_081E6898: .4byte 0x00001514
_081E689C: .4byte 0x000014B4
_081E68A0: .4byte 0x00001624
_081E68A4: .4byte FUN_081e653c
_081E68A8: .4byte 0x00001616
_081E68AC:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r3, _081E68E0 @ =0x00000808
	adds r0, r4, r3
	ldr r2, _081E68E4 @ =0x00000AC8
	adds r1, r4, r2
	bl FUN_082372cc
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E68CA
	b _081E6A06
_081E68CA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r3, _081E68E8 @ =0x00001610
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E68EC
	movs r0, #1
	b _081E68EE
	.align 2, 0
_081E68E0: .4byte 0x00000808
_081E68E4: .4byte 0x00000AC8
_081E68E8: .4byte 0x00001610
_081E68EC:
	movs r0, #0
_081E68EE:
	cmp r0, #0
	bne _081E68F4
	b _081E6A06
_081E68F4:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #4
	beq _081E6904
	b _081E6A06
_081E6904:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6914
	movs r0, #1
	b _081E6916
_081E6914:
	movs r0, #0
_081E6916:
	cmp r0, #0
	beq _081E69A8
	ldr r0, _081E695C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _081E6960 @ =0x000015E4
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r1, r0
	blt _081E696C
	ldr r0, _081E6964 @ =0x00001617
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0x10
	beq _081E6A06
	bl FUN_08049e5c
	ldr r1, _081E6968 @ =0x000015F0
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x10
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x10
	b _081E6992
	.align 2, 0
_081E695C: .4byte 0x030046A0
_081E6960: .4byte 0x000015E4
_081E6964: .4byte 0x00001617
_081E6968: .4byte 0x000015F0
_081E696C:
	ldr r2, _081E699C @ =0x00001617
	adds r5, r4, r2
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0x11
	beq _081E6A06
	bl FUN_08049e5c
	ldr r3, _081E69A0 @ =0x000015F0
	adds r0, r4, r3
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x11
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x11
_081E6992:
	strb r0, [r5]
	ldr r0, _081E69A4 @ =FUN_081e6b5c
	movs r2, #7
	b _081E69F6
	.align 2, 0
_081E699C: .4byte 0x00001617
_081E69A0: .4byte 0x000015F0
_081E69A4: .4byte FUN_081e6b5c
_081E69A8:
	bl FUN_08049e5c
	ldr r2, _081E6A0C @ =0x0000161A
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _081E69F2
	adds r0, r4, #0
	bl FUN_081e4544
	ldrb r0, [r5]
	adds r0, #0x19
	ldr r3, _081E6A10 @ =0x00001617
	adds r1, r4, r3
	strb r0, [r1]
	ldr r1, _081E6A14 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a1f0
	ldrb r1, [r5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r2, _081E6A18 @ =0x00000BC4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E69F2
	ldr r3, _081E6A1C @ =0x00001514
	adds r0, r4, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E69F2:
	ldr r0, _081E6A20 @ =FUN_081e7414
	movs r2, #4
_081E69F6:
	str r0, [r4, #0x18]
	ldr r0, _081E6A24 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6A28 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6A06:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6A0C: .4byte 0x0000161A
_081E6A10: .4byte 0x00001617
_081E6A14: .4byte 0x00001608
_081E6A18: .4byte 0x00000BC4
_081E6A1C: .4byte 0x00001514
_081E6A20: .4byte FUN_081e7414
_081E6A24: .4byte 0x00001614
_081E6A28: .4byte 0x00001616

	thumb_func_start FUN_081e6a2c
FUN_081e6a2c: @ 0x081E6A2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E6AA0 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E6A54
	ldr r1, _081E6AA4 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r3, _081E6AA8 @ =0x00001514
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r5]
_081E6A54:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E6ABC
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6AA8 @ =0x00001514
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E6AAC @ =0x00001624
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _081E6AB0 @ =0x000014B4
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6AB4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E6AA0 @ =0x00001614
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081E6AB8 @ =0x00001616
	adds r0, r4, r2
	strb r1, [r0]
	b _081E6B42
	.align 2, 0
_081E6AA0: .4byte 0x00001614
_081E6AA4: .4byte 0x00001608
_081E6AA8: .4byte 0x00001514
_081E6AAC: .4byte 0x00001624
_081E6AB0: .4byte 0x000014B4
_081E6AB4: .4byte FUN_081e653c
_081E6AB8: .4byte 0x00001616
_081E6ABC:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r3, _081E6AEC @ =0x00000808
	adds r0, r4, r3
	ldr r2, _081E6AF0 @ =0x00000AC8
	adds r1, r4, r2
	bl FUN_082372cc
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6B42
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r3, _081E6AF4 @ =0x00001610
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E6AF8
	movs r0, #1
	b _081E6AFA
	.align 2, 0
_081E6AEC: .4byte 0x00000808
_081E6AF0: .4byte 0x00000AC8
_081E6AF4: .4byte 0x00001610
_081E6AF8:
	movs r0, #0
_081E6AFA:
	cmp r0, #0
	beq _081E6B42
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bne _081E6B42
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_081e4544
	ldr r3, _081E6B48 @ =0x0000161A
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #0x19
	ldr r2, _081E6B4C @ =0x00001617
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #0x12
	adds r0, r4, r3
	ldr r0, [r0]
	bl FUN_0804a1f0
	ldr r0, _081E6B50 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r4, #0x18]
	ldr r0, _081E6B54 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6B58 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6B42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6B48: .4byte 0x0000161A
_081E6B4C: .4byte 0x00001617
_081E6B50: .4byte FUN_081e6f28
_081E6B54: .4byte 0x00001614
_081E6B58: .4byte 0x00001616

	thumb_func_start FUN_081e6b5c
FUN_081e6b5c: @ 0x081E6B5C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _081E6B80 @ =0x00001614
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6C3A
	movs r2, #0x80
	lsls r2, r2, #0xa
	ldr r3, _081E6B84 @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6B88
	movs r0, #1
	b _081E6B8A
	.align 2, 0
_081E6B80: .4byte 0x00001614
_081E6B84: .4byte 0x00001610
_081E6B88:
	movs r0, #0
_081E6B8A:
	adds r3, r0, #0
	cmp r3, #0
	bne _081E6C32
	movs r4, #0xea
	lsls r4, r4, #3
	adds r2, r6, r4
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r5, #0xed
	lsls r5, r5, #3
	adds r1, r6, r5
	movs r5, #0
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, _081E6C90 @ =0x0000076A
	adds r0, r6, r1
	strh r3, [r0]
	ldr r2, _081E6C94 @ =0x000015E6
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _081E6C98 @ =0x000015E2
	adds r4, r6, r3
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldrh r1, [r4]
	ldr r2, _081E6C9C @ =0x000015E4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _081E6CA0 @ =0x00001619
	adds r0, r6, r3
	strb r5, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	ldrh r1, [r4]
	movs r2, #0
	ldr r0, _081E6CA4 @ =0x000003E7
	cmp r1, r0
	ble _081E6BF0
	ldr r3, _081E6CA8 @ =0xFFFFFC18
_081E6BE8:
	adds r2, #1
	adds r1, r1, r3
	cmp r1, r0
	bgt _081E6BE8
_081E6BF0:
	ldr r4, _081E6CAC @ =0x000015EF
	adds r0, r6, r4
	strb r2, [r0]
	movs r2, #0
	cmp r1, #0x63
	ble _081E6C04
_081E6BFC:
	adds r2, #1
	subs r1, #0x64
	cmp r1, #0x63
	bgt _081E6BFC
_081E6C04:
	ldr r5, _081E6CB0 @ =0x000015EE
	adds r0, r6, r5
	strb r2, [r0]
	movs r2, #0
	cmp r1, #9
	ble _081E6C18
_081E6C10:
	adds r2, #1
	subs r1, #0xa
	cmp r1, #9
	bgt _081E6C10
_081E6C18:
	ldr r3, _081E6CB4 @ =0x000015ED
	adds r0, r6, r3
	strb r2, [r0]
	movs r2, #0
	cmp r1, #0
	ble _081E6C2C
_081E6C24:
	adds r2, #1
	subs r1, #1
	cmp r1, #0
	bgt _081E6C24
_081E6C2C:
	ldr r4, _081E6CB8 @ =0x000015EC
	adds r0, r6, r4
	strb r2, [r0]
_081E6C32:
	ldr r5, _081E6CBC @ =0x00001614
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
_081E6C3A:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E6CD4
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r6, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r4, _081E6CC0 @ =0x00001514
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6CC4 @ =0x000014B4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E6CC8 @ =0x00001624
	adds r0, r6, r1
	strb r2, [r0]
	ldr r0, _081E6CCC @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r6, #0x18]
	ldr r3, _081E6CBC @ =0x00001614
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _081E6CD0 @ =0x00001616
	adds r0, r6, r4
	strb r1, [r0]
	b _081E6F20
	.align 2, 0
_081E6C90: .4byte 0x0000076A
_081E6C94: .4byte 0x000015E6
_081E6C98: .4byte 0x000015E2
_081E6C9C: .4byte 0x000015E4
_081E6CA0: .4byte 0x00001619
_081E6CA4: .4byte 0x000003E7
_081E6CA8: .4byte 0xFFFFFC18
_081E6CAC: .4byte 0x000015EF
_081E6CB0: .4byte 0x000015EE
_081E6CB4: .4byte 0x000015ED
_081E6CB8: .4byte 0x000015EC
_081E6CBC: .4byte 0x00001614
_081E6CC0: .4byte 0x00001514
_081E6CC4: .4byte 0x000014B4
_081E6CC8: .4byte 0x00001624
_081E6CCC: .4byte FUN_081e653c
_081E6CD0: .4byte 0x00001616
_081E6CD4:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r5, _081E6CEC @ =0x00001610
	adds r1, r6, r5
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6CF0
	movs r0, #1
	b _081E6CF2
	.align 2, 0
_081E6CEC: .4byte 0x00001610
_081E6CF0:
	movs r0, #0
_081E6CF2:
	adds r5, r0, #0
	cmp r5, #0
	beq _081E6D28
	ldr r0, _081E6D18 @ =FUN_081e6810
	movs r2, #0x15
	str r0, [r6, #0x18]
	ldr r0, _081E6D1C @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6D20 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, _081E6D24 @ =0xFFFFF7FF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	b _081E6F20
	.align 2, 0
_081E6D18: .4byte FUN_081e6810
_081E6D1C: .4byte 0x00001614
_081E6D20: .4byte 0x00001616
_081E6D24: .4byte 0xFFFFF7FF
_081E6D28:
	adds r0, r6, #0
	bl FUN_081e4ab8
	adds r1, r0, #0
	ldr r3, _081E6D58 @ =0x000015E6
	adds r2, r6, r3
	ldrb r4, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E6D68
	ldr r1, _081E6D5C @ =0x000015EC
	adds r0, r6, r1
	adds r1, r0, r4
	ldr r2, _081E6D60 @ =0x000015E8
	adds r0, r6, r2
	adds r0, r0, r4
	ldrb r2, [r1]
	ldrb r0, [r0]
	cmp r2, r0
	blo _081E6D64
	strb r5, [r1]
	b _081E6D94
	.align 2, 0
_081E6D58: .4byte 0x000015E6
_081E6D5C: .4byte 0x000015EC
_081E6D60: .4byte 0x000015E8
_081E6D64:
	adds r0, r2, #1
	b _081E6D92
_081E6D68:
	movs r3, #2
	ands r3, r1
	cmp r3, #0
	beq _081E6DB4
	ldr r5, _081E6D88 @ =0x000015EC
	adds r0, r6, r5
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	bne _081E6D90
	ldr r2, _081E6D8C @ =0x000015E8
	adds r0, r6, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	b _081E6D92
	.align 2, 0
_081E6D88: .4byte 0x000015EC
_081E6D8C: .4byte 0x000015E8
_081E6D90:
	subs r0, #1
_081E6D92:
	strb r0, [r1]
_081E6D94:
	adds r0, r6, #0
	bl FUN_081e3758
	ldr r3, _081E6DB0 @ =0x000015E4
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r6, #0
	bl FUN_081e37a0
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E6DE8
	.align 2, 0
_081E6DB0: .4byte 0x000015E4
_081E6DB4:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081E6DD4
	ldr r5, _081E6DCC @ =0x000015E7
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r4, r0
	blo _081E6DD0
	strb r3, [r2]
	b _081E6DE8
	.align 2, 0
_081E6DCC: .4byte 0x000015E7
_081E6DD0:
	adds r0, r4, #1
	b _081E6DE6
_081E6DD4:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E6DE8
	cmp r4, #0
	bne _081E6DE4
	movs r0, #3
	b _081E6DE6
_081E6DE4:
	subs r0, r4, #1
_081E6DE6:
	strb r0, [r2]
_081E6DE8:
	ldr r1, _081E6E88 @ =0x000015E6
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, r4
	beq _081E6E1A
	lsls r1, r1, #3
	movs r0, #0x18
	subs r0, r0, r1
	movs r2, #0xed
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _081E6E8C @ =0x0000076A
	adds r0, r6, r3
	strh r2, [r0]
	ldr r4, _081E6E90 @ =0x000015E4
	adds r0, r6, r4
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_081e37a0
	movs r0, #0xdc
	bl PlaySound_082406e0
_081E6E1A:
	ldr r0, _081E6E94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r4, #1
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081E6E32
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E6EB6
_081E6E32:
	ldr r0, _081E6E98 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x91
	lsls r5, r5, #4
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, _081E6E90 @ =0x000015E4
	adds r2, r6, r5
	ldrh r1, [r2]
	cmp r0, r1
	blt _081E6EAC
	ldr r0, _081E6E9C @ =FUN_081e7414
	movs r1, #4
	str r0, [r6, #0x18]
	adds r5, #0x30
	adds r0, r6, r5
	strb r4, [r0]
	ldr r4, _081E6EA0 @ =0x00001616
	adds r0, r6, r4
	strb r1, [r0]
	movs r5, #0xea
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldrh r1, [r2]
	ldr r2, _081E6EA4 @ =0x000015E2
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldr r1, _081E6EA8 @ =0xFFFDFFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E6F20
	.align 2, 0
_081E6E88: .4byte 0x000015E6
_081E6E8C: .4byte 0x0000076A
_081E6E90: .4byte 0x000015E4
_081E6E94: .4byte 0x030044E0
_081E6E98: .4byte 0x030046A0
_081E6E9C: .4byte FUN_081e7414
_081E6EA0: .4byte 0x00001616
_081E6EA4: .4byte 0x000015E2
_081E6EA8: .4byte 0xFFFDFFFF
_081E6EAC:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E6F14
_081E6EB6:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E6F14
	ldr r0, _081E6F00 @ =FUN_081e7414
	movs r1, #4
	str r0, [r6, #0x18]
	ldr r5, _081E6F04 @ =0x00001614
	adds r0, r6, r5
	strb r4, [r0]
	ldr r2, _081E6F08 @ =0x00001616
	adds r0, r6, r2
	strb r1, [r0]
	movs r4, #0xea
	lsls r4, r4, #3
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	subs r5, #0x32
	adds r4, r6, r5
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldrh r1, [r4]
	ldr r2, _081E6F0C @ =0x000015E4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, _081E6F10 @ =0xFFFDFFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E6F20
	.align 2, 0
_081E6F00: .4byte FUN_081e7414
_081E6F04: .4byte 0x00001614
_081E6F08: .4byte 0x00001616
_081E6F0C: .4byte 0x000015E4
_081E6F10: .4byte 0xFFFDFFFF
_081E6F14:
	adds r0, r6, #0
	bl FUN_081e2ee8
	adds r0, r6, #0
	bl FUN_081e4a60
_081E6F20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e6f28
FUN_081e6f28: @ 0x081E6F28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _081E6F54 @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E6F3E
	b _081E7090
_081E6F3E:
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, _081E6F58 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6F5C
	movs r0, #1
	b _081E6F5E
	.align 2, 0
_081E6F54: .4byte 0x00001614
_081E6F58: .4byte 0x00001610
_081E6F5C:
	movs r0, #0
_081E6F5E:
	adds r4, r0, #0
	cmp r4, #0
	bne _081E7056
	adds r0, r5, #0
	bl FUN_081e2b08
	movs r0, #0x14
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_0822bdb8
	ldr r1, [r5, #0x1c]
	movs r0, #3
	movs r2, #3
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0x81
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_081e3fac
	adds r0, r5, #0
	bl FUN_081e4354
	ldr r1, _081E70CC @ =0x0000161A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081E70D0 @ =0x00001608
	adds r4, r5, r2
	ldr r0, [r4]
	ldr r3, _081E70D4 @ =0x00001590
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r5, #0
	bl FUN_081e4544
	ldr r0, _081E70D8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	ldr r1, _081E70DC @ =0x0000270F
	cmp r0, r1
	ble _081E6FEC
	adds r0, r1, #0
_081E6FEC:
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r6, #0
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, _081E70D8 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r2, #0x63
	cmp r0, #0x63
	bgt _081E7010
	adds r2, r0, #0
_081E7010:
	str r6, [sp]
	adds r0, r2, #0
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r2, _081E70E0 @ =0x000015F0
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r3, _081E70E4 @ =0x00001599
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081E70E8 @ =0x00001619
	adds r0, r5, r1
	strb r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_081E7056:
	ldr r2, _081E70E4 @ =0x00001599
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _081E7074
	movs r3, #0xf6
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E7074:
	ldr r1, _081E70EC @ =0x00001617
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2ee8
	ldr r2, _081E70F0 @ =0x0000162A
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	ldr r3, _081E70F4 @ =0x00001614
	adds r0, r5, r3
	strb r1, [r0]
_081E7090:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E7108
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E70F8 @ =0x00001514
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E70FC @ =0x00001624
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _081E7100 @ =0x000014B4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7104 @ =FUN_081e653c
	movs r1, #0x11
	b _081E7378
	.align 2, 0
_081E70CC: .4byte 0x0000161A
_081E70D0: .4byte 0x00001608
_081E70D4: .4byte 0x00001590
_081E70D8: .4byte 0x030046A0
_081E70DC: .4byte 0x0000270F
_081E70E0: .4byte 0x000015F0
_081E70E4: .4byte 0x00001599
_081E70E8: .4byte 0x00001619
_081E70EC: .4byte 0x00001617
_081E70F0: .4byte 0x0000162A
_081E70F4: .4byte 0x00001614
_081E70F8: .4byte 0x00001514
_081E70FC: .4byte 0x00001624
_081E7100: .4byte 0x000014B4
_081E7104: .4byte FUN_081e653c
_081E7108:
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r3, _081E7120 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E7124
	movs r0, #1
	b _081E7126
	.align 2, 0
_081E7120: .4byte 0x00001610
_081E7124:
	movs r0, #0
_081E7126:
	cmp r0, #0
	beq _081E7158
	ldr r0, _081E7148 @ =FUN_081e6a2c
	movs r2, #8
	str r0, [r5, #0x18]
	ldr r0, _081E714C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7150 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, _081E7154 @ =0xFFFFCFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	b _081E7400
	.align 2, 0
_081E7148: .4byte FUN_081e6a2c
_081E714C: .4byte 0x00001614
_081E7150: .4byte 0x00001616
_081E7154: .4byte 0xFFFFCFFF
_081E7158:
	adds r0, r5, #0
	bl FUN_081e2ee8
	ldr r2, _081E717C @ =0x00000808
	adds r0, r5, r2
	ldr r3, _081E7180 @ =0x00000AC8
	adds r1, r5, r3
	bl FUN_082372cc
	ldr r0, _081E7184 @ =0x0000162A
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _081E7188
	adds r0, #1
	strh r0, [r1]
	b _081E7400
	.align 2, 0
_081E717C: .4byte 0x00000808
_081E7180: .4byte 0x00000AC8
_081E7184: .4byte 0x0000162A
_081E7188:
	ldr r1, _081E71B0 @ =0x0000161A
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e4ab8
	adds r1, r0, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E71B8
	asrs r0, r4, #2
	cmp r0, #0
	bne _081E71B4
	movs r0, #3
	ands r0, r4
	adds r4, r0, #0
	adds r4, #0xc
	b _081E7214
	.align 2, 0
_081E71B0: .4byte 0x0000161A
_081E71B4:
	subs r4, #4
	b _081E7214
_081E71B8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E71D8
	asrs r0, r4, #2
	cmp r0, #3
	bne _081E71CA
	ands r4, r0
	b _081E71CC
_081E71CA:
	adds r4, #4
_081E71CC:
	ldr r3, _081E71D4 @ =0x00001619
	adds r1, r5, r3
	b _081E7218
	.align 2, 0
_081E71D4: .4byte 0x00001619
_081E71D8:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081E71FC
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	bne _081E71F0
	movs r0, #0xfc
	ands r0, r4
	adds r4, r0, #3
	b _081E71F2
_081E71F0:
	subs r4, #1
_081E71F2:
	ldr r0, _081E71F8 @ =0x00001619
	adds r1, r5, r0
	b _081E7218
	.align 2, 0
_081E71F8: .4byte 0x00001619
_081E71FC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E721C
	movs r0, #3
	ands r0, r4
	cmp r0, #3
	bne _081E7212
	movs r0, #0xfc
	ands r4, r0
	b _081E7214
_081E7212:
	adds r4, #1
_081E7214:
	ldr r2, _081E7254 @ =0x00001619
	adds r1, r5, r2
_081E7218:
	movs r0, #0
	strb r0, [r1]
_081E721C:
	ldr r3, _081E7258 @ =0x0000161A
	adds r7, r5, r3
	ldrb r0, [r7]
	cmp r4, r0
	beq _081E7264
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r2, _081E725C @ =0x00000828
	adds r1, r5, r2
	strh r0, [r1]
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, _081E7260 @ =0x0000082A
	adds r1, r5, r3
	strh r0, [r1]
	strb r4, [r7]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E7400
	.align 2, 0
_081E7254: .4byte 0x00001619
_081E7258: .4byte 0x0000161A
_081E725C: .4byte 0x00000828
_081E7260: .4byte 0x0000082A
_081E7264:
	ldr r0, _081E7310 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	mov r8, r0
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _081E7334
	adds r0, r5, #0
	bl FUN_081e3e78
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7284
	b _081E73BA
_081E7284:
	ldr r1, _081E7314 @ =0x00001599
	adds r2, r5, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _081E72BC
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r5, r0
	ldr r3, _081E7318 @ =0x00000E86
	adds r0, r0, r3
	ldr r1, _081E731C @ =0x000002DF
	strh r1, [r0]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r3, #0xe
	adds r1, r5, r3
	adds r1, r1, r0
	ldr r0, _081E7320 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _081E7324 @ =0x00005BE0
	adds r0, r0, r3
	str r0, [r1]
_081E72BC:
	ldrb r0, [r7]
	strb r0, [r2]
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r3, _081E7328 @ =0x00000A68
	adds r1, r5, r3
	strh r0, [r1]
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r0, #0xa5
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _081E732C @ =FUN_081e52ac
	movs r1, #6
	str r0, [r5, #0x18]
	ldr r2, _081E7330 @ =0x00001614
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	adds r2, #2
	b _081E7382
	.align 2, 0
_081E7310: .4byte 0x030044E0
_081E7314: .4byte 0x00001599
_081E7318: .4byte 0x00000E86
_081E731C: .4byte 0x000002DF
_081E7320: .4byte 0x03003584
_081E7324: .4byte 0x00005BE0
_081E7328: .4byte 0x00000A68
_081E732C: .4byte FUN_081e52ac
_081E7330: .4byte 0x00001614
_081E7334:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E73A4
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_081e4c64
	ldr r3, _081E7388 @ =0x00001618
	adds r1, r5, r3
	movs r0, #0xa
	strb r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r2, _081E738C @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r3, _081E7390 @ =0x000014B4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r1, _081E7394 @ =0x00001624
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, _081E7398 @ =FUN_081e5d14
	movs r1, #0x10
_081E7378:
	str r0, [r5, #0x18]
	ldr r3, _081E739C @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081E73A0 @ =0x00001616
_081E7382:
	adds r0, r5, r2
	strb r1, [r0]
	b _081E7400
	.align 2, 0
_081E7388: .4byte 0x00001618
_081E738C: .4byte 0x00001514
_081E7390: .4byte 0x000014B4
_081E7394: .4byte 0x00001624
_081E7398: .4byte FUN_081e5d14
_081E739C: .4byte 0x00001614
_081E73A0: .4byte 0x00001616
_081E73A4:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E7400
	ldr r3, _081E73C4 @ =0x00001599
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _081E73C8
_081E73BA:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E7400
	.align 2, 0
_081E73C4: .4byte 0x00001599
_081E73C8:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	str r6, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0x19
	movs r1, #0x10
	movs r2, #5
	movs r3, #1
	bl FUN_081e4644
	ldr r0, _081E740C @ =FUN_081e53e8
	movs r1, #9
	str r0, [r5, #0x18]
	ldr r2, _081E7410 @ =0x00001614
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7400:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E740C: .4byte FUN_081e53e8
_081E7410: .4byte 0x00001614

	thumb_func_start FUN_081e7414
FUN_081e7414: @ 0x081E7414
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r1, _081E7444 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E742E
	b _081E75C2
_081E742E:
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r3, _081E7448 @ =0x00001610
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081E744C
	movs r0, #1
	b _081E744E
	.align 2, 0
_081E7444: .4byte 0x00001614
_081E7448: .4byte 0x00001610
_081E744C:
	movs r0, #0
_081E744E:
	adds r6, r0, #0
	cmp r6, #0
	beq _081E7456
	b _081E7596
_081E7456:
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r0, #0x14
	str r0, [sp]
	str r6, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_0822bdb8
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #2
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0x81
	lsls r0, r0, #4
	adds r5, r7, r0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r4, _081E7618 @ =0x030046A0
	ldr r0, [r4]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xfa
	lsls r1, r1, #2
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r6, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r3, _081E761C @ =0x000015F0
	adds r3, r3, r7
	mov sl, r3
	ldr r1, [r3]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r1, _081E7620 @ =0x000015E2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_081e37a0
	adds r0, r7, #0
	bl FUN_081e36e8
	adds r0, r7, #0
	bl FUN_081e3714
	adds r0, r7, #0
	bl FUN_081e49a8
	ldr r2, _081E7624 @ =0x00001599
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _081E7628 @ =0x00001619
	adds r0, r7, r3
	strb r6, [r0]
	ldr r1, _081E762C @ =0x0000161B
	adds r0, r7, r1
	strb r6, [r0]
	adds r2, #0x87
	adds r1, r7, r2
	ldr r0, _081E7630 @ =0x0000FFFF
	strh r0, [r1]
	adds r3, #1
	adds r1, r7, r3
	movs r0, #0x11
	strb r0, [r1]
	ldr r1, _081E7634 @ =0x00001608
	adds r0, r7, r1
	ldr r0, [r0]
	subs r2, #0x90
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	bl FUN_08049e5c
	mov r3, sl
	ldr r0, [r3]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r0, _081E7638 @ =0x00001617
	adds r1, r7, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _081E763C @ =0x00001514
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081E7596:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r2, _081E7640 @ =0x0000162A
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _081E7644 @ =0x00001614
	adds r0, r7, r3
	strb r2, [r0]
	ldr r1, _081E7638 @ =0x00001617
	adds r0, r7, r1
	strb r2, [r0]
	adds r0, r7, #0
	bl FUN_081e2ee8
_081E75C2:
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa
	bne _081E7654
	movs r0, #0x81
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r3, _081E763C @ =0x00001514
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r3, #0x60
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E7648 @ =0x00001624
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081E764C @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r7, #0x18]
	ldr r3, _081E7644 @ =0x00001614
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _081E7650 @ =0x00001616
	adds r0, r7, r2
	strb r1, [r0]
	b _081E78B2
	.align 2, 0
_081E7618: .4byte 0x030046A0
_081E761C: .4byte 0x000015F0
_081E7620: .4byte 0x000015E2
_081E7624: .4byte 0x00001599
_081E7628: .4byte 0x00001619
_081E762C: .4byte 0x0000161B
_081E7630: .4byte 0x0000FFFF
_081E7634: .4byte 0x00001608
_081E7638: .4byte 0x00001617
_081E763C: .4byte 0x00001514
_081E7640: .4byte 0x0000162A
_081E7644: .4byte 0x00001614
_081E7648: .4byte 0x00001624
_081E764C: .4byte FUN_081e653c
_081E7650: .4byte 0x00001616
_081E7654:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _081E766C @ =0x00001610
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081E7670
	movs r0, #1
	b _081E7672
	.align 2, 0
_081E766C: .4byte 0x00001610
_081E7670:
	movs r0, #0
_081E7672:
	cmp r0, #0
	beq _081E76A8
	ldr r0, _081E7698 @ =FUN_081e6810
	movs r2, #0x15
	str r0, [r7, #0x18]
	ldr r0, _081E769C @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E76A0 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _081E76A4 @ =0xFFFFF7FF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081E78B2
	.align 2, 0
_081E7698: .4byte FUN_081e6810
_081E769C: .4byte 0x00001614
_081E76A0: .4byte 0x00001616
_081E76A4: .4byte 0xFFFFF7FF
_081E76A8:
	adds r0, r7, #0
	bl FUN_081e2ee8
	ldr r3, _081E76D0 @ =0x00000808
	adds r0, r7, r3
	ldr r2, _081E76D4 @ =0x00000AC8
	adds r1, r7, r2
	bl FUN_082372cc
	adds r0, r7, #0
	bl FUN_081e4a60
	ldr r3, _081E76D8 @ =0x0000162A
	adds r1, r7, r3
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _081E76DC
	adds r0, #1
	strh r0, [r1]
	b _081E78B2
	.align 2, 0
_081E76D0: .4byte 0x00000808
_081E76D4: .4byte 0x00000AC8
_081E76D8: .4byte 0x0000162A
_081E76DC:
	adds r0, r7, #0
	bl FUN_081e4ab8
	adds r2, r0, #0
	adds r0, r7, #0
	add r1, sp, #0x10
	bl FUN_081e468c
	adds r1, r0, #0
	ldr r0, _081E7738 @ =0x0000161A
	adds r4, r7, r0
	ldrb r2, [r4]
	cmp r1, r2
	beq _081E77B8
	strb r1, [r4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bne _081E7744
	ldr r3, _081E773C @ =0x00001608
	adds r0, r7, r3
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E7740 @ =0x00001514
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _081E77A0
	.align 2, 0
_081E7738: .4byte 0x0000161A
_081E773C: .4byte 0x00001608
_081E7740: .4byte 0x00001514
_081E7744:
	ldr r1, _081E77A8 @ =0x00001608
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a1f0
	ldrb r1, [r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r2, _081E77AC @ =0x00000BC4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E7770
	ldr r3, _081E77B0 @ =0x00001514
	adds r0, r7, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E7770:
	movs r0, #0x81
	lsls r0, r0, #4
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r3, _081E77B4 @ =0x00000828
	adds r2, r7, r3
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_081e2ee8
_081E77A0:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E78B2
	.align 2, 0
_081E77A8: .4byte 0x00001608
_081E77AC: .4byte 0x00000BC4
_081E77B0: .4byte 0x00001514
_081E77B4: .4byte 0x00000828
_081E77B8:
	ldr r0, _081E77EC @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r5, #1
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _081E77FC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bne _081E78B2
	ldr r0, _081E77F0 @ =FUN_081e6b5c
	movs r1, #7
	str r0, [r7, #0x18]
	ldr r2, _081E77F4 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _081E77F8 @ =0x00001616
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E78B2
	.align 2, 0
_081E77EC: .4byte 0x030044E0
_081E77F0: .4byte FUN_081e6b5c
_081E77F4: .4byte 0x00001614
_081E77F8: .4byte 0x00001616
_081E77FC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E7874
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_081e4c64
	ldr r0, _081E785C @ =0x00001618
	adds r1, r7, r0
	movs r0, #0xa
	strb r0, [r1]
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r3, _081E7860 @ =0x00001514
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, _081E7864 @ =0x000014B4
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r2, #0xde
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r3, _081E7868 @ =0x00001624
	adds r0, r7, r3
	strb r5, [r0]
	ldr r0, _081E786C @ =FUN_081e5d14
	movs r1, #0x10
	str r0, [r7, #0x18]
	ldr r2, _081E7870 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	subs r3, #0xe
	adds r0, r7, r3
	strb r1, [r0]
	b _081E78B2
	.align 2, 0
_081E785C: .4byte 0x00001618
_081E7860: .4byte 0x00001514
_081E7864: .4byte 0x000014B4
_081E7868: .4byte 0x00001624
_081E786C: .4byte FUN_081e5d14
_081E7870: .4byte 0x00001614
_081E7874:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081E78B2
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	str r4, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0x19
	movs r1, #0x10
	movs r2, #5
	movs r3, #1
	bl FUN_081e4644
	ldr r0, _081E78C4 @ =FUN_081e564c
	movs r1, #0xb
	str r0, [r7, #0x18]
	ldr r2, _081E78C8 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _081E78CC @ =0x00001616
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E78B2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E78C4: .4byte FUN_081e564c
_081E78C8: .4byte 0x00001614
_081E78CC: .4byte 0x00001616

	thumb_func_start FUN_081e78d0
FUN_081e78d0: @ 0x081E78D0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E79B0 @ =0x00001614
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E799A
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldr r1, _081E79B4 @ =0x00001610
	adds r2, r6, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_081e3fe0
	adds r0, r6, #0
	bl FUN_081e4450
	adds r0, r6, #0
	bl FUN_081e2b08
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r0, r6, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E79B8 @ =0x00001604
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E79BC @ =0x00001608
	adds r0, r6, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E79C0 @ =0x0000160C
	adds r4, r6, r0
	ldr r0, [r4]
	bl FUN_0804a210
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, [r6, #0x20]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E79C4 @ =0x000015F0
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0x16
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_081e4c64
	movs r0, #1
	bl sound_fadeout_08240440
	ldr r1, _081E79C8 @ =0x0000162A
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
_081E799A:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E79B4 @ =0x00001610
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E79CC
	movs r0, #1
	b _081E79CE
	.align 2, 0
_081E79B0: .4byte 0x00001614
_081E79B4: .4byte 0x00001610
_081E79B8: .4byte 0x00001604
_081E79BC: .4byte 0x00001608
_081E79C0: .4byte 0x0000160C
_081E79C4: .4byte 0x000015F0
_081E79C8: .4byte 0x0000162A
_081E79CC:
	movs r0, #0
_081E79CE:
	cmp r0, #0
	beq _081E79DC
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_081e4c64
	b _081E7A22
_081E79DC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E79EC
	movs r0, #1
	b _081E79EE
_081E79EC:
	movs r0, #0
_081E79EE:
	cmp r0, #0
	beq _081E7A22
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7A22
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7A22
	bl FUN_081e25f0
	ldr r0, _081E7A2C @ =FUN_081e7a38
	movs r2, #0x1b
	str r0, [r6, #0x18]
	ldr r0, _081E7A30 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7A34 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
_081E7A22:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E7A2C: .4byte FUN_081e7a38
_081E7A30: .4byte 0x00001614
_081E7A34: .4byte 0x00001616

	thumb_func_start FUN_081e7a38
FUN_081e7a38: @ 0x081E7A38
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081E7AAC @ =0x00001614
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E7A54
	ldr r1, _081E7AB0 @ =0x0000162A
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E7A54:
	ldr r0, _081E7AB0 @ =0x0000162A
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x24
	bne _081E7A76
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E7AB4 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081E7A76:
	ldrh r0, [r4]
	cmp r0, #0x3c
	bls _081E7AB8
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7ABC
	adds r0, r5, #0
	bl FUN_081e3cd4
	adds r0, r5, #0
	bl KillEntity
	b _081E7ABC
	.align 2, 0
_081E7AAC: .4byte 0x00001614
_081E7AB0: .4byte 0x0000162A
_081E7AB4: .4byte 0x0000FFFF
_081E7AB8:
	adds r0, #1
	strh r0, [r4]
_081E7ABC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e7ac4
FUN_081e7ac4: @ 0x081E7AC4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E7B1C @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E7AEA
	ldr r0, _081E7B20 @ =0x0000162A
	adds r1, r5, r0
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E7B24 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	strb r4, [r6]
_081E7AEA:
	adds r0, r5, #0
	bl FUN_081e2ee8
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xb
	bne _081E7B30
	ldr r0, _081E7B28 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r5, #0x18]
	ldr r0, _081E7B1C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7B2C @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7BEA
	.align 2, 0
_081E7B1C: .4byte 0x00001614
_081E7B20: .4byte 0x0000162A
_081E7B24: .4byte 0x00001618
_081E7B28: .4byte FUN_081e78d0
_081E7B2C: .4byte 0x00001616
_081E7B30:
	adds r0, r5, #0
	bl FUN_081e4a60
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E7B4C @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E7B50
	movs r0, #1
	b _081E7B52
	.align 2, 0
_081E7B4C: .4byte 0x00001610
_081E7B50:
	movs r0, #0
_081E7B52:
	cmp r0, #0
	beq _081E7B68
	ldr r1, _081E7B64 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	b _081E7BEA
	.align 2, 0
_081E7B64: .4byte 0x00001618
_081E7B68:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xd
	bne _081E7BEA
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E7B86
	movs r0, #1
	b _081E7B88
_081E7B86:
	movs r0, #0
_081E7B88:
	cmp r0, #0
	beq _081E7BEA
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7BEA
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E7BBC @ =0x00001604
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E7BC0
	movs r0, #1
	b _081E7BC2
	.align 2, 0
_081E7BBC: .4byte 0x00001604
_081E7BC0:
	movs r0, #0
_081E7BC2:
	cmp r0, #0
	beq _081E7BD0
	ldr r0, _081E7BCC @ =FUN_081e6f28
	movs r2, #3
	b _081E7BD4
	.align 2, 0
_081E7BCC: .4byte FUN_081e6f28
_081E7BD0:
	ldr r0, _081E7BF0 @ =FUN_081e7414
	movs r2, #4
_081E7BD4:
	str r0, [r5, #0x18]
	ldr r0, _081E7BF4 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7BF8 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7BEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E7BF0: .4byte FUN_081e7414
_081E7BF4: .4byte 0x00001614
_081E7BF8: .4byte 0x00001616

	thumb_func_start FUN_081e7bfc
FUN_081e7bfc: @ 0x081E7BFC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _081E7C54 @ =0x00001614
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E7C22
	ldr r2, _081E7C58 @ =0x0000162A
	adds r1, r6, r2
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _081E7C5C @ =0x00001618
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_081e4c64
	strb r4, [r5]
_081E7C22:
	adds r0, r6, #0
	bl FUN_081e2ee8
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7C68
	ldr r0, _081E7C60 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r6, #0x18]
	ldr r3, _081E7C54 @ =0x00001614
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7C64 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7D9E
	.align 2, 0
_081E7C54: .4byte 0x00001614
_081E7C58: .4byte 0x0000162A
_081E7C5C: .4byte 0x00001618
_081E7C60: .4byte FUN_081e78d0
_081E7C64: .4byte 0x00001616
_081E7C68:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r3, _081E7C80 @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E7C84
	movs r0, #1
	b _081E7C86
	.align 2, 0
_081E7C80: .4byte 0x00001610
_081E7C84:
	movs r0, #0
_081E7C86:
	cmp r0, #0
	beq _081E7C9C
	ldr r1, _081E7C98 @ =0x00001618
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_081e4c64
	b _081E7D9E
	.align 2, 0
_081E7C98: .4byte 0x00001618
_081E7C9C:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081E7CAC
	movs r0, #1
	b _081E7CAE
_081E7CAC:
	movs r0, #0
_081E7CAE:
	cmp r0, #0
	beq _081E7D9E
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7D9E
	ldr r2, _081E7D34 @ =0x0000162E
	adds r0, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	bne _081E7D50
	ldr r0, _081E7D38 @ =FUN_081e7414
	movs r2, #4
	str r0, [r6, #0x18]
	ldr r0, _081E7D3C @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7D40 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r3, _081E7D44 @ =0x00001604
	adds r5, r6, r3
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r0, [r4]
	ldr r1, _081E7D48 @ =0x00000BB8
	adds r2, r6, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r5]
	ldr r1, _081E7D4C @ =0x030046A0
	ldr r2, [r1]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r2, r2, r3
	movs r1, #2
	bl FUN_0804a40c
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E7D9E
	.align 2, 0
_081E7D34: .4byte 0x0000162E
_081E7D38: .4byte FUN_081e7414
_081E7D3C: .4byte 0x00001614
_081E7D40: .4byte 0x00001616
_081E7D44: .4byte 0x00001604
_081E7D48: .4byte 0x00000BB8
_081E7D4C: .4byte 0x030046A0
_081E7D50:
	cmp r2, #1
	bne _081E7D9E
	ldr r0, _081E7DA4 @ =FUN_081e6f28
	movs r1, #3
	str r0, [r6, #0x18]
	ldr r3, _081E7DA8 @ =0x00001614
	adds r0, r6, r3
	strb r2, [r0]
	ldr r2, _081E7DAC @ =0x00001616
	adds r0, r6, r2
	strb r1, [r0]
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r3, #0xb0
	lsls r3, r3, #5
	adds r0, r6, r3
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E7DB0 @ =0x00001604
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7D9E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E7DA4: .4byte FUN_081e6f28
_081E7DA8: .4byte 0x00001614
_081E7DAC: .4byte 0x00001616
_081E7DB0: .4byte 0x00001604

	thumb_func_start FUN_081e7db4
FUN_081e7db4: @ 0x081E7DB4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E7E00 @ =0x00001614
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E7DCE
	ldr r1, _081E7E04 @ =0x0000162A
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E7DCE:
	adds r0, r5, #0
	bl FUN_081e32d8
	adds r0, r5, #0
	bl FUN_081e2ee8
	adds r0, r5, #0
	bl FUN_081e4a60
	ldr r2, _081E7E04 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E7E08
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	beq _081E7DFE
	b _081E7FAE
_081E7DFE:
	b _081E7E26
	.align 2, 0
_081E7E00: .4byte 0x00001614
_081E7E04: .4byte 0x0000162A
_081E7E08:
	ldr r0, _081E7E44 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _081E7E26
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7E54
_081E7E26:
	ldr r0, _081E7E48 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r5, #0x18]
	ldr r0, _081E7E4C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7E50 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7FAE
	.align 2, 0
_081E7E44: .4byte 0x030044E0
_081E7E48: .4byte FUN_081e78d0
_081E7E4C: .4byte 0x00001614
_081E7E50: .4byte 0x00001616
_081E7E54:
	ldr r2, _081E7E88 @ =0x00001615
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _081E7EF8
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _081E7E8C
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	strb r3, [r4]
	b _081E7F20
	.align 2, 0
_081E7E88: .4byte 0x00001615
_081E7E8C:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081E7E96
	b _081E7FAE
_081E7E96:
	ldr r2, _081E7EE0 @ =0x00000BB5
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r2, #1
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	ble _081E7F4C
	bl FUN_08243104
	cmp r0, #0
	ble _081E7F4C
	bl FUN_08049e5c
	ldr r1, _081E7EE4 @ =0x00001618
	adds r0, r5, r1
	strb r6, [r0]
	movs r2, #0x80
	lsls r2, r2, #9
	ldr r0, _081E7EE8 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7EEC @ =FUN_081e7ac4
	movs r2, #5
	str r0, [r5, #0x18]
	ldr r0, _081E7EF0 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7EF4 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	b _081E7FAE
	.align 2, 0
_081E7EE0: .4byte 0x00000BB5
_081E7EE4: .4byte 0x00001618
_081E7EE8: .4byte 0x00001610
_081E7EEC: .4byte FUN_081e7ac4
_081E7EF0: .4byte 0x00001614
_081E7EF4: .4byte 0x00001616
_081E7EF8:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _081E7F28
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strb r6, [r4]
_081E7F20:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E7FAE
_081E7F28:
	movs r6, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E7FAE
	bl FUN_08243140
	adds r4, r0, #0
	bl FUN_08243104
	subs r4, r4, r0
	cmp r4, #0
	ble _081E7F4C
	ldr r2, _081E7F58 @ =0x00000BB4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E7F5C
_081E7F4C:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E7FAE
	.align 2, 0
_081E7F58: .4byte 0x00000BB4
_081E7F5C:
	bl FUN_08049e5c
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, _081E7FB4 @ =0x00000BB8
	adds r2, r5, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r2, _081E7FB8 @ =0x00001604
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, _081E7FBC @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r2, _081E7FC0 @ =0x00001618
	adds r0, r5, r2
	strb r6, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	ldr r0, _081E7FC4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7FC8 @ =FUN_081e7ac4
	movs r1, #5
	str r0, [r5, #0x18]
	ldr r2, _081E7FCC @ =0x00001614
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_081E7FAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E7FB4: .4byte 0x00000BB8
_081E7FB8: .4byte 0x00001604
_081E7FBC: .4byte 0x030046A0
_081E7FC0: .4byte 0x00001618
_081E7FC4: .4byte 0x00001610
_081E7FC8: .4byte FUN_081e7ac4
_081E7FCC: .4byte 0x00001614

	thumb_func_start FUN_081e7fd0
FUN_081e7fd0: @ 0x081E7FD0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E8014 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E7FF0
	movs r0, #1
	bl sound_fadeout_08240440
	ldr r1, _081E8018 @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r5]
_081E7FF0:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r2, _081E8018 @ =0x0000162A
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E801C
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E8090
	b _081E8036
	.align 2, 0
_081E8014: .4byte 0x00001614
_081E8018: .4byte 0x0000162A
_081E801C:
	ldr r0, _081E8054 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081E8036
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r4, r2
	ldrh r1, [r0]
	lsls r0, r1, #0x10
	cmp r1, #0xb
	bne _081E8064
_081E8036:
	ldr r0, _081E8058 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r4, #0x18]
	ldr r0, _081E805C @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E8060 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E8090
	.align 2, 0
_081E8054: .4byte 0x030044E0
_081E8058: .4byte FUN_081e78d0
_081E805C: .4byte 0x00001614
_081E8060: .4byte 0x00001616
_081E8064:
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081E8090
	ldr r2, _081E8098 @ =0x0000162E
	adds r0, r4, r2
	strh r1, [r0]
	bl FUN_08049e5c
	ldr r0, _081E809C @ =0x00001618
	adds r1, r4, r0
	movs r0, #0xd
	strb r0, [r1]
	ldr r0, _081E80A0 @ =FUN_081e7bfc
	movs r2, #0x1d
	str r0, [r4, #0x18]
	ldr r0, _081E80A4 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E80A8 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E8090:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E8098: .4byte 0x0000162E
_081E809C: .4byte 0x00001618
_081E80A0: .4byte FUN_081e7bfc
_081E80A4: .4byte 0x00001614
_081E80A8: .4byte 0x00001616

	thumb_func_start FUN_081e80ac
FUN_081e80ac: @ 0x081E80AC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E80D8 @ =0x00001614
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E80BE
	movs r0, #0
	strb r0, [r1]
_081E80BE:
	bl FUN_081e2454
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E80FC
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E80DC
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E80E2
	.align 2, 0
_081E80D8: .4byte 0x00001614
_081E80DC:
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E80E2:
	ldr r0, _081E8104 @ =FUN_081e8110
	movs r2, #2
	str r0, [r4, #0x18]
	ldr r0, _081E8108 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E810C @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_081e275c
_081E80FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E8104: .4byte FUN_081e8110
_081E8108: .4byte 0x00001614
_081E810C: .4byte 0x00001616

	thumb_func_start FUN_081e8110
FUN_081e8110: @ 0x081E8110
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081E819C @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E817C
	adds r0, r5, #0
	bl FUN_081e2960
	adds r0, r5, #0
	movs r1, #0
	movs r2, #6
	bl FUN_081e4cb4
	ldr r0, _081E81A0 @ =0x00001618
	adds r1, r5, r0
	movs r3, #0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _081E81A4 @ =0x00001610
	adds r2, r5, r1
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb1
	lsls r0, r0, #5
	adds r1, r5, r0
	ldr r0, _081E81A8 @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _081E81AC @ =0x00001625
	adds r0, r5, r1
	strb r3, [r0]
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E816E
	movs r0, #0xa8
	bl sound_08240960
	cmp r0, #0
	bne _081E816E
	movs r0, #0xa8
	bl sound_08240264
_081E816E:
	adds r0, r5, #0
	bl FUN_081e49a8
	ldr r0, _081E819C @ =0x00001614
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081E817C:
	adds r0, r5, #0
	bl FUN_081e2ee8
	adds r0, r5, #0
	bl FUN_081e4a60
	movs r2, #2
	ldr r0, _081E81A4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E81B0
	movs r0, #1
	b _081E81B2
	.align 2, 0
_081E819C: .4byte 0x00001614
_081E81A0: .4byte 0x00001618
_081E81A4: .4byte 0x00001610
_081E81A8: .4byte 0x0000FFFF
_081E81AC: .4byte 0x00001625
_081E81B0:
	movs r0, #0
_081E81B2:
	cmp r0, #0
	beq _081E81FC
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E81C4
	movs r0, #1
	b _081E81C6
_081E81C4:
	movs r0, #0
_081E81C6:
	adds r6, r0, #0
	cmp r6, #0
	bne _081E8230
	adds r0, r5, #0
	bl FUN_081e3ce8
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #7
	bl FUN_081e4cb4
	ldr r0, _081E81F4 @ =0x00001618
	adds r1, r5, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _081E81F8 @ =0x00001625
	adds r0, r5, r1
	strb r6, [r0]
	b _081E83DA
	.align 2, 0
_081E81F4: .4byte 0x00001618
_081E81F8: .4byte 0x00001625
_081E81FC:
	ldr r0, _081E822C @ =0x00001625
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x77
	bls _081E8230
	bl FUN_081e24b4
	adds r0, r5, #0
	bl FUN_081e44d0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	adds r0, r5, #0
	bl KillEntity
	b _081E83DA
	.align 2, 0
_081E822C: .4byte 0x00001625
_081E8230:
	movs r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E823E
	movs r0, #1
	b _081E8240
_081E823E:
	movs r0, #0
_081E8240:
	cmp r0, #0
	beq _081E8280
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8252
	movs r0, #1
	b _081E8254
_081E8252:
	movs r0, #0
_081E8254:
	cmp r0, #0
	bne _081E8280
	adds r0, r5, #0
	bl FUN_081e32d8
	movs r1, #0x20
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #8
	bl FUN_081e4cb4
	ldr r0, _081E827C @ =0x00001618
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	b _081E83DA
	.align 2, 0
_081E827C: .4byte 0x00001618
_081E8280:
	movs r1, #8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E828E
	movs r0, #1
	b _081E8290
_081E828E:
	movs r0, #0
_081E8290:
	cmp r0, #0
	beq _081E82CC
	movs r1, #0x40
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E82A2
	movs r0, #1
	b _081E82A4
_081E82A2:
	movs r0, #0
_081E82A4:
	cmp r0, #0
	bne _081E82CC
	adds r0, r5, #0
	bl FUN_081e3444
	movs r1, #0x40
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0xc
	bl FUN_081e4c64
	ldr r0, _081E82C8 @ =0x00001618
	adds r1, r5, r0
	movs r0, #0xc
	strb r0, [r1]
	b _081E83DA
	.align 2, 0
_081E82C8: .4byte 0x00001618
_081E82CC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E82DC
	movs r0, #1
	b _081E82DE
_081E82DC:
	movs r0, #0
_081E82DE:
	cmp r0, #0
	beq _081E82F4
	ldr r1, _081E82F0 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	b _081E83DA
	.align 2, 0
_081E82F0: .4byte 0x00001618
_081E82F4:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8304
	movs r0, #1
	b _081E8306
_081E8304:
	movs r0, #0
_081E8306:
	cmp r0, #0
	beq _081E8320
	ldr r1, _081E831C @ =0x00001618
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_081e4cb4
	b _081E83DA
	.align 2, 0
_081E831C: .4byte 0x00001618
_081E8320:
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E832E
	movs r0, #1
	b _081E8330
_081E832E:
	movs r0, #0
_081E8330:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8342
	movs r0, #1
	b _081E8344
_081E8342:
	movs r0, #0
_081E8344:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0x40
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8356
	movs r0, #1
	b _081E8358
_081E8356:
	movs r0, #0
_081E8358:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xc
	bne _081E83DA
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E837A
	movs r0, #1
	b _081E837C
_081E837A:
	movs r0, #0
_081E837C:
	cmp r0, #0
	beq _081E83DA
	bl FUN_081e2380
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081E83DA
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E83BC
	ldr r0, _081E83B0 @ =FUN_081e7db4
	str r0, [r5, #0x18]
	ldr r0, _081E83B4 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E83B8 @ =0x00001616
	adds r0, r5, r1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2d98
	b _081E83D4
	.align 2, 0
_081E83B0: .4byte FUN_081e7db4
_081E83B4: .4byte 0x00001614
_081E83B8: .4byte 0x00001616
_081E83BC:
	ldr r0, _081E83E0 @ =FUN_081e7fd0
	movs r4, #1
	str r0, [r5, #0x18]
	ldr r1, _081E83E4 @ =0x00001614
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2dd8
_081E83D4:
	ldr r1, _081E83E8 @ =0x0000162C
	adds r0, r5, r1
	strh r4, [r0]
_081E83DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E83E0: .4byte FUN_081e7fd0
_081E83E4: .4byte 0x00001614
_081E83E8: .4byte 0x0000162C

	thumb_func_start FUN_081e83ec
FUN_081e83ec: @ 0x081E83EC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0x10
	ldr r2, _081E8404 @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E8408
	movs r0, #1
	b _081E840A
	.align 2, 0
_081E8404: .4byte 0x00001610
_081E8408:
	movs r0, #0
_081E840A:
	cmp r0, #0
	bne _081E8414
	ldr r1, _081E8434 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081E8414:
	bl FUN_081e2484
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E8454
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r2, _081E8438 @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E843C
	movs r0, #1
	b _081E843E
	.align 2, 0
_081E8434: .4byte 0x030047B8
_081E8438: .4byte 0x00001610
_081E843C:
	movs r0, #0
_081E843E:
	cmp r0, #0
	bne _081E8454
	adds r0, r4, #0
	bl FUN_081e44d0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081E8462
_081E8454:
	ldr r1, [r4, #0x18]
	cmp r1, #0
	beq _081E8460
	adds r0, r4, #0
	bl _call_via_r1
_081E8460:
	movs r0, #1
_081E8462:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8468
FUN_081e8468: @ 0x081E8468
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081e44d0
	adds r0, r4, #0
	bl FUN_081e44b4
	adds r0, r4, #0
	bl FUN_081e4484
	bl FUN_081e2484
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _081E84AC
	movs r0, #0
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	bl FUN_0824172c
	ldr r0, _081E84B4 @ =0x0300481C
	str r5, [r0]
	ldr r0, _081E84B8 @ =0x00001626
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E84AC
	movs r1, #0
	bl Script_ExecById
_081E84AC:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E84B4: .4byte 0x0300481C
_081E84B8: .4byte 0x00001626

	thumb_func_start FUN_081e84bc
FUN_081e84bc: @ 0x081E84BC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081e2628
	adds r0, r4, #0
	bl FUN_081e27f0
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e3f0c
	adds r0, r4, #0
	bl FUN_081e4054
	ldr r1, _081E8550 @ =0x00001615
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081E8554 @ =0x00001610
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081E8558 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081e2e84
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081E855C @ =0x00001628
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _081E8560 @ =0x00001626
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081e23ac
	ldr r0, _081E8564 @ =FUN_081e3958
	ldr r1, _081E8568 @ =FUN_081e3cd4
	ldr r2, _081E856C @ =FUN_081e3cc0
	bl FUN_081e23c4
	adds r0, r4, #0
	bl FUN_081e3d78
	adds r0, r4, #0
	bl FUN_081e2b08
	ldr r0, _081E8570 @ =FUN_081e80ac
	movs r2, #0x14
	str r0, [r4, #0x18]
	ldr r0, _081E8574 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E8578 @ =0x00001616
	adds r4, r4, r1
	strb r2, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E8550: .4byte 0x00001615
_081E8554: .4byte 0x00001610
_081E8558: .4byte 0x00001617
_081E855C: .4byte 0x00001628
_081E8560: .4byte 0x00001626
_081E8564: .4byte FUN_081e3958
_081E8568: .4byte FUN_081e3cd4
_081E856C: .4byte FUN_081e3cc0
_081E8570: .4byte FUN_081e80ac
_081E8574: .4byte 0x00001614
_081E8578: .4byte 0x00001616

	thumb_func_start FUN_081e857c
FUN_081e857c: @ 0x081E857C
	push {r4, lr}
	ldr r1, _081E85A8 @ =0x00001630
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E85B4
	ldr r1, _081E85AC @ =FUN_081e83ec
	ldr r2, _081E85B0 @ =FUN_081e8468
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e84bc
	cmp r0, #0
	bge _081E85B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E85B6
	.align 2, 0
_081E85A8: .4byte 0x00001630
_081E85AC: .4byte FUN_081e83ec
_081E85B0: .4byte FUN_081e8468
_081E85B4:
	adds r0, r4, #0
_081E85B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e85bc
FUN_081e85bc: @ 0x081E85BC
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e85c0
FUN_081e85c0: @ 0x081E85C0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r2, _081E864C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081E8650 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x44
	ldr r2, _081E8654 @ =0x00002101
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _081E8658 @ =0x00008020
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _081E865C @ =FUN_081e85bc
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E864C: .4byte 0xFFFF0000
_081E8650: .4byte 0x0000FFFF
_081E8654: .4byte 0x00002101
_081E8658: .4byte 0x00008020
_081E865C: .4byte FUN_081e85bc

	thumb_func_start FUN_081e8660
FUN_081e8660: @ 0x081E8660
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e8664
FUN_081e8664: @ 0x081E8664
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r6, #0
	adds r0, r6, #0
	adds r0, #0x9c
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081E8682
	movs r2, #0
	cmp r0, #0x28
	ble _081E8682
	movs r2, #1
_081E8682:
	adds r4, r6, #0
	adds r4, #0x9c
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _081E86AC @ =0x085AE44C
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081E86B4
	ldr r1, [r5]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081E86B0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081E86B2
	.align 2, 0
_081E86AC: .4byte 0x085AE44C
_081E86B0:
	orrs r1, r2
_081E86B2:
	str r1, [r5]
_081E86B4:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x5a
	ble _081E86DE
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r6, #0
	adds r0, #0x97
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	adds r1, r6, #0
	adds r1, #0x96
	movs r0, #0
	strb r0, [r1]
_081E86DE:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e86ec
FUN_081e86ec: @ 0x081E86EC
	push {r4, r5, lr}
	adds r4, r1, #0
	bl FUN_081e8664
	adds r5, r4, #0
	adds r5, #0x44
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8710
FUN_081e8710: @ 0x081E8710
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r7, #0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	adds r4, r7, #0
	adds r4, #0x2c
	movs r1, #0x20
	adds r0, r7, #0
	adds r0, #0x94
	movs r2, #0
	ldrsh r0, [r0, r2]
	ands r0, r1
	cmp r0, #0
	beq _081E8744
	movs r0, #1
	b _081E8746
_081E8744:
	movs r0, #0
_081E8746:
	cmp r0, #0
	bne _081E874E
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_081E874E:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E877A
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081E8782
_081E877A:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8782:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E87A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E87AE
_081E87A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E87AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081E87E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E882E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E87F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E87EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E8808
	.align 2, 0
_081E87E8: .4byte 0x0000FFFF
_081E87EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E8806
_081E87F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E8806
	strh r1, [r4, #8]
	movs r2, #1
	b _081E8808
_081E8806:
	movs r2, #0
_081E8808:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E8830
	movs r0, #1
	strb r0, [r4, #7]
	b _081E8830
_081E882E:
	movs r2, #0
_081E8830:
	cmp r2, #0
	beq _081E886A
	adds r1, r7, #0
	adds r1, #0x9c
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r4, r7, #0
	adds r4, #0x97
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0
	mov r3, r8
	ldr r0, [r3, #0x38]
	bics r0, r1
	str r0, [r3, #0x38]
	adds r0, r7, #0
	adds r0, #0x96
	strb r2, [r0]
	adds r0, r6, #0
	bl FUN_0822a4e0
	movs r0, #0xff
	strb r0, [r4]
	b _081E8A2A
_081E886A:
	movs r2, #0x20
	adds r1, r7, #0
	adds r1, #0x94
	movs r3, #0
	ldrsh r0, [r1, r3]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081E8880
	movs r0, #1
	b _081E8882
_081E8880:
	movs r0, #0
_081E8882:
	movs r1, #0x1c
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #0
	beq _081E888E
	b _081E8A16
_081E888E:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	mov r2, sp
	adds r3, r7, #0
	adds r3, #0x3c
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7, #0x3c]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r7, #0x3e]
	subs r0, #1
	strh r0, [r7, #0x3e]
	mov r5, r8
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E88E4
	cmp r1, #0
	blt _081E88E4
	ldr r0, _081E88E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E88E4
	ldr r0, _081E88EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E88F0
_081E88E4:
	movs r4, #0
	b _081E88FE
	.align 2, 0
_081E88E8: .4byte 0x030046A8
_081E88EC: .4byte 0x030046AC
_081E88F0:
	ldr r0, _081E8910 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E88FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E8914
	adds r0, #4
	b _081E8920
	.align 2, 0
_081E8910: .4byte 0x030046A4
_081E8914:
	ldr r0, _081E8934 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E8920:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E8938
	cmp r2, #2
	beq _081E893C
	b _081E8940
	.align 2, 0
_081E8934: .4byte 0x030046A4
_081E8938:
	ldrb r0, [r5, #4]
	b _081E893E
_081E893C:
	ldrb r0, [r5]
_081E893E:
	subs r1, r1, r0
_081E8940:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E896E
	cmp r1, #0
	blt _081E896E
	ldr r0, _081E8974 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E896E
	ldr r0, _081E8978 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E897C
_081E896E:
	movs r4, #0
	b _081E898A
	.align 2, 0
_081E8974: .4byte 0x030046A8
_081E8978: .4byte 0x030046AC
_081E897C:
	ldr r0, _081E899C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E898A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E89A0
	adds r0, #4
	b _081E89AC
	.align 2, 0
_081E899C: .4byte 0x030046A4
_081E89A0:
	ldr r0, _081E89C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E89AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E89C4
	cmp r2, #2
	beq _081E89C8
	b _081E89CC
	.align 2, 0
_081E89C0: .4byte 0x030046A4
_081E89C4:
	ldrb r0, [r5, #4]
	b _081E89CA
_081E89C8:
	ldrb r0, [r5]
_081E89CA:
	subs r1, r1, r0
_081E89CC:
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r3, #0x1e
	ldrsh r1, [r6, r3]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _081E89EE
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge _081E8A16
_081E89EE:
	ldrh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x3c]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	adds r3, r7, #0
	adds r3, #0x40
	ldrh r0, [r6, #0x20]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x20
	orrs r0, r1
	mov r1, sl
	strh r0, [r1]
	strh r2, [r7, #0x3c]
	strh r2, [r7, #0x3e]
	strh r2, [r3]
_081E8A16:
	adds r4, r7, #0
	adds r4, #0x44
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081E8A2A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e8a3c
FUN_081e8a3c: @ 0x081E8A3C
	push {r4, r5, r6, lr}
	mov ip, r0
	movs r2, #0
	movs r5, #1
	mov r3, ip
	adds r3, #0xd3
	mov r4, ip
	adds r4, #0x3c
_081E8A4C:
	adds r0, r5, #0
	lsls r0, r2
	mov r6, ip
	ldr r1, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8A5E
	movs r0, #1
	b _081E8A60
_081E8A5E:
	movs r0, #0
_081E8A60:
	cmp r0, #0
	bne _081E8A74
	adds r0, r5, #0
	lsls r0, r2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #0x38]
	strb r2, [r3]
	adds r0, r4, #0
	b _081E8A80
_081E8A74:
	adds r3, #0xa0
	adds r4, #0xa0
	adds r2, #1
	cmp r2, #3
	ble _081E8A4C
	movs r0, #0
_081E8A80:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8a88
FUN_081e8a88: @ 0x081E8A88
	push {lr}
	bl FUN_081e8a3c
	cmp r0, #0
	bne _081E8A94
	movs r0, #0
_081E8A94:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8a98
FUN_081e8a98: @ 0x081E8A98
	push {lr}
	adds r1, r0, #0
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bgt _081E8AB0
	cmp r1, #1
	blt _081E8AB0
	movs r0, #1
	b _081E8AB2
_081E8AB0:
	movs r0, #0
_081E8AB2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8ab8
FUN_081e8ab8: @ 0x081E8AB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	adds r7, r1, #0
	mov sb, r2
	adds r5, r3, #0
	cmp r4, #0
	bne _081E8AD0
	b _081E8C42
_081E8AD0:
	bl FUN_081e8a88
	adds r6, r0, #0
	cmp r6, #0
	bne _081E8ADC
	b _081E8C42
_081E8ADC:
	adds r1, r6, #0
	adds r1, #0x98
	adds r0, r7, #0
	adds r0, #8
	str r0, [r1]
	subs r1, #2
	movs r0, #0
	mov r8, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x94
	mov r1, r8
	strh r1, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x2c]
	ldr r3, [sp, #0x30]
	bl FUN_081e85c0
	adds r5, r6, #0
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
	ldrb r0, [r7, #5]
	bl FUN_081e8a98
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r5, #0
	adds r2, #0x2c
	ldr r1, [r4, #0x34]
	str r0, [sp]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r2, sb
	ldrb r0, [r2, #4]
	cmp r0, #3
	bls _081E8B4C
	mov r3, r8
	strh r3, [r5, #0x3c]
	strh r3, [r5, #0x3e]
	adds r0, r5, #0
	adds r0, #0x40
	strh r3, [r0]
	b _081E8C38
_081E8B4C:
	mov r1, sb
	ldr r0, [r1, #0x38]
	add r2, sp, #4
	adds r4, r5, #0
	adds r4, #0x1c
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r2, r5, #0
	adds r2, #0x86
	strb r0, [r2]
	ldr r3, _081E8BA8 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081E8BAC
	asrs r0, r0, #0xc
	b _081E8BB2
	.align 2, 0
_081E8BA8: .4byte 0x085B0A08
_081E8BAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E8BB2:
	strh r0, [r6, #0x3c]
	ldr r1, _081E8BD0 @ =0x085B0A08
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081E8BD4
	asrs r0, r0, #0xc
	b _081E8BDA
	.align 2, 0
_081E8BD0: .4byte 0x085B0A08
_081E8BD4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E8BDA:
	adds r4, r6, #0
	adds r4, #0x40
	strh r0, [r4]
	movs r2, #0
	movs r7, #0
	movs r3, #0x3c
	ldrsh r0, [r6, r3]
	cmp r0, #0
	beq _081E8BFC
	add r0, sp, #4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x3c
	ldrsh r1, [r6, r2]
	bl Div
	adds r2, r0, #0
_081E8BFC:
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #0
	beq _081E8C18
	add r0, sp, #4
	movs r1, #4
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r4, r3]
	str r2, [sp, #0xc]
	bl Div
	adds r7, r0, #0
	ldr r2, [sp, #0xc]
_081E8C18:
	cmp r2, r7
	ble _081E8C28
	cmp r2, #0
	blt _081E8C24
	asrs r0, r2, #1
	b _081E8C36
_081E8C24:
	rsbs r0, r2, #0
	b _081E8C32
_081E8C28:
	cmp r7, #0
	blt _081E8C30
	asrs r0, r7, #1
	b _081E8C36
_081E8C30:
	rsbs r0, r7, #0
_081E8C32:
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081E8C36:
	strh r0, [r6, #0x3e]
_081E8C38:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
_081E8C42:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8c50
FUN_081e8c50: @ 0x081E8C50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _081E8C78 @ =0x085AE450
	mov r8, r0
	adds r5, r6, #0
	adds r5, #0xd2
	adds r4, r6, #0
	adds r4, #0x3c
_081E8C66:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8C7C
	movs r0, #1
	b _081E8C7E
	.align 2, 0
_081E8C78: .4byte 0x085AE450
_081E8C7C:
	movs r0, #0
_081E8C7E:
	cmp r0, #0
	beq _081E8C92
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081E8C92:
	adds r5, #0xa0
	adds r4, #0xa0
	adds r7, #1
	cmp r7, #3
	ble _081E8C66
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8ca8
FUN_081e8ca8: @ 0x081E8CA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x3c
_081E8CB2:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8CC2
	movs r0, #1
	b _081E8CC4
_081E8CC2:
	movs r0, #0
_081E8CC4:
	cmp r0, #0
	beq _081E8CCE
	adds r0, r4, #0
	bl FUN_0822a4e0
_081E8CCE:
	adds r4, #0xa0
	adds r5, #1
	cmp r5, #3
	ble _081E8CB2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8ce0
FUN_081e8ce0: @ 0x081E8CE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081E8D00 @ =0x0000E74B
	bl FUN_0822b16c
	ldr r0, _081E8D04 @ =0x0000922E
	ldr r1, _081E8D08 @ =0x0000871C
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E8D00: .4byte 0x0000E74B
_081E8D04: .4byte 0x0000922E
_081E8D08: .4byte 0x0000871C

	thumb_func_start FUN_081e8d0c
FUN_081e8d0c: @ 0x081E8D0C
	push {r4, lr}
	movs r1, #0xaf
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E8D44
	ldr r1, _081E8D3C @ =FUN_081e8c50
	ldr r2, _081E8D40 @ =FUN_081e8ca8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e8ce0
	cmp r0, #0
	bge _081E8D44
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E8D46
	.align 2, 0
_081E8D3C: .4byte FUN_081e8c50
_081E8D40: .4byte FUN_081e8ca8
_081E8D44:
	adds r0, r4, #0
_081E8D46:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8d4c
FUN_081e8d4c: @ 0x081E8D4C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	ldrh r1, [r5, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081E8D62
	b _081E8E72
_081E8D62:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _081E8D6E
	b _081E8E72
_081E8D6E:
	movs r1, #0xf
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _081E8E2A
	ldrb r2, [r2, #2]
	ldr r0, [r5, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081E8DC4
	adds r2, #0x20
	movs r0, #0xff
	ands r2, r0
	cmp r2, #0
	blt _081E8D94
	asrs r0, r2, #6
	b _081E8D9A
_081E8D94:
	rsbs r0, r2, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8D9A:
	adds r2, r0, #0
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081E8DB2
	asrs r0, r1, #6
	b _081E8DB8
_081E8DB2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8DB8:
	subs r0, r2, r0
	cmp r0, #0
	bge _081E8DC0
	rsbs r0, r0, #0
_081E8DC0:
	cmp r0, #2
	bne _081E8DC8
_081E8DC4:
	movs r0, #1
	b _081E8DCA
_081E8DC8:
	movs r0, #0
_081E8DCA:
	cmp r0, #0
	beq _081E8E72
	movs r0, #3
	strb r0, [r3]
	adds r1, r3, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	cmp r0, #0
	blt _081E8E14
	asrs r0, r0, #5
	b _081E8E1A
_081E8E14:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E1A:
	strh r0, [r6, #0x22]
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	b _081E8E72
_081E8E2A:
	movs r0, #3
	strb r0, [r3]
	adds r0, r3, #0
	adds r0, #0xe6
	strh r4, [r0]
	add r2, sp, #8
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	cmp r0, #0
	blt _081E8E6A
	asrs r0, r0, #5
	b _081E8E70
_081E8E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E70:
	strh r0, [r6, #0x22]
_081E8E72:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e8e7c
FUN_081e8e7c: @ 0x081E8E7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	adds r5, r7, #0
	adds r5, #0x14
	ldr r2, _081E8F14 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081E8F18 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0xea
	ldrh r1, [r0]
	ldr r2, _081E8F1C @ =0x00002301
	str r4, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _081E8F20 @ =0x00004010
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x10
	bl FUN_082364f8
	adds r1, r7, #0
	adds r1, #0x80
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081E8F24 @ =FUN_081e8d4c
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_0823651c
	ldrb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0x56
	strb r1, [r0]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E8F14: .4byte 0xFFFF0000
_081E8F18: .4byte 0x0000FFFF
_081E8F1C: .4byte 0x00002301
_081E8F20: .4byte 0x00004010
_081E8F24: .4byte FUN_081e8d4c

	thumb_func_start FUN_081e8f28
FUN_081e8f28: @ 0x081E8F28
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e8f2c
FUN_081e8f2c: @ 0x081E8F2C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081E8F7A
	ldr r0, [r5, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #3
	strh r0, [r1]
	ldrb r1, [r5]
	movs r0, #7
	ands r0, r1
	strb r0, [r5]
	ldrb r0, [r5, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r1, [r6, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #2
	bl FUN_08237040
_081E8F7A:
	adds r1, r5, #0
	adds r1, #0xee
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bgt _081E8F94
	ldr r0, [r5, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x64]
	b _081E8F98
_081E8F94:
	subs r0, r2, #1
	strh r0, [r1]
_081E8F98:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8fa0
FUN_081e8fa0: @ 0x081E8FA0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r3, #0x90
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	adds r5, r3, #0
	adds r4, r0, #0
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E8FE2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081E8FEA
_081E8FE2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8FEA:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E900E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081E9016
_081E900E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9016:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E904C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E9084
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9050
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9046
	ldrb r0, [r4, #5]
_081E9046:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9060
	.align 2, 0
_081E904C: .4byte 0x0000FFFF
_081E9050:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9060
	strh r1, [r4, #8]
_081E9060:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9084
	movs r0, #1
	strb r0, [r4, #7]
_081E9084:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e908c
FUN_081e908c: @ 0x081E908C
	adds r0, #0xf0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e9094
FUN_081e9094: @ 0x081E9094
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	ldr r0, _081E9110 @ =0x030001B4
	ldr r7, [r0]
	cmp r7, #0
	bne _081E90A8
	b _081E91C6
_081E90A8:
	mov r0, r8
	cmp r0, #0
	bne _081E90B0
	b _081E91C6
_081E90B0:
	mov r4, r8
	adds r4, #0x90
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, r8
	ldrb r0, [r1, #2]
	mov r5, sp
	adds r5, #5
	add r1, sp, #4
	adds r2, r5, #0
	bl FUN_081e978c
	mov r6, r8
	adds r6, #0xcc
	ldr r1, [r7, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl FUN_08237040
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9114
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081E911C
	.align 2, 0
_081E9110: .4byte 0x030001B4
_081E9114:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E911C:
	str r0, [r4]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9140
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081E9148
_081E9140:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9148:
	str r0, [r4]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081E9180 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081E91B8
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9184
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081E9178
	ldrb r0, [r6, #5]
_081E9178:
	subs r0, #1
	strh r0, [r6, #8]
	b _081E9194
	.align 2, 0
_081E9180: .4byte 0x0000FFFF
_081E9184:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081E9194
	strh r1, [r6, #8]
_081E9194:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E91B8
	movs r0, #1
	strb r0, [r6, #7]
_081E91B8:
	mov r0, r8
	adds r0, #0xe8
	movs r1, #0
	strh r1, [r0]
	movs r0, #2
	mov r1, r8
	strb r0, [r1]
_081E91C6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e91d4
FUN_081e91d4: @ 0x081E91D4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081E91F8 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E91F2
	cmp r5, #0
	beq _081E91F2
	adds r0, r5, #0
	adds r0, #0xe4
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #0
	bge _081E91FC
_081E91F2:
	movs r0, #0
	b _081E924C
	.align 2, 0
_081E91F8: .4byte 0x030001B4
_081E91FC:
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E9210
	movs r0, #1
	b _081E9212
_081E9210:
	movs r0, #0
_081E9212:
	cmp r0, #0
	beq _081E924A
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E924A
	adds r0, r5, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x90
	bl FUN_0822a4e0
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r7]
	adds r1, r5, #0
	adds r1, #0xe8
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
	b _081E924C
_081E924A:
	adds r0, r5, #0
_081E924C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9254
FUN_081e9254: @ 0x081E9254
	push {r4, r5, r6, r7, lr}
	ldr r0, _081E9278 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E92C4
	ldr r0, [r6, #0x38]
	cmp r0, #0
	beq _081E92C4
	movs r7, #0
_081E9266:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E927C
	movs r0, #1
	b _081E927E
	.align 2, 0
_081E9278: .4byte 0x030001B4
_081E927C:
	movs r0, #0
_081E927E:
	cmp r0, #0
	beq _081E92BE
	movs r0, #0xf4
	muls r0, r7, r0
	adds r0, #0x3c
	adds r5, r6, r0
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E92BE
	adds r0, r5, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x90
	bl FUN_0822a4e0
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
_081E92BE:
	adds r7, #1
	cmp r7, #0xb
	ble _081E9266
_081E92C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e92cc
FUN_081e92cc: @ 0x081E92CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _081E9380 @ =0x030001B4
	ldr r0, [r0]
	mov sb, r0
	adds r5, r6, #0
	adds r5, #0xbc
	adds r7, r6, #0
	adds r7, #0x64
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081E932A
	ldrh r1, [r6, #0xc]
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #4]
	ldrh r0, [r6, #0xe]
	ldrh r3, [r6, #6]
	adds r0, r0, r3
	strh r0, [r6, #6]
	ldrh r0, [r6, #0x10]
	ldrh r2, [r6, #8]
	adds r0, r0, r2
	strh r0, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x80
	strh r1, [r0]
	ldrh r0, [r6, #6]
	adds r1, r6, #0
	adds r1, #0x82
	strh r0, [r1]
	ldrh r1, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x84
	strh r1, [r0]
_081E932A:
	adds r0, r6, #0
	bl FUN_081e97cc
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	mov r3, sb
	ldr r1, [r3, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9384
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E938C
	.align 2, 0
_081E9380: .4byte 0x030001B4
_081E9384:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E938C:
	str r0, [r6, #0x64]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E93B0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E93B8
_081E93B0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E93B8:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E93F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _081E9428
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E93F4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E93E8
	ldrb r0, [r5, #5]
_081E93E8:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9404
	.align 2, 0
_081E93F0: .4byte 0x0000FFFF
_081E93F4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9404
	strh r1, [r5, #8]
_081E9404:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9428
	movs r0, #1
	strb r0, [r5, #7]
_081E9428:
	adds r0, r6, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r8, r0
	cmp r1, #1
	bne _081E9438
	b _081E953E
_081E9438:
	adds r7, r6, #0
	adds r7, #0x90
	adds r4, r6, #0
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov ip, r7
	cmp r1, r0
	beq _081E9474
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _081E9480
_081E9474:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081E9480:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E94A2
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E94AA
_081E94A2:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E94AA:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E94E4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E952A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E94EE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E94E8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9504
	.align 2, 0
_081E94E4: .4byte 0x0000FFFF
_081E94E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9502
_081E94EE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9502
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9504
_081E9502:
	movs r2, #0
_081E9504:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E952C
	movs r0, #1
	strb r0, [r4, #7]
	b _081E952C
_081E952A:
	movs r2, #0
_081E952C:
	cmp r2, #0
	beq _081E953E
	mov r3, ip
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r0, r8
	strh r1, [r0]
_081E953E:
	adds r5, r6, #0
	adds r5, #0xec
	ldrh r0, [r5]
	cmp r0, #0
	beq _081E955E
	adds r4, r6, #0
	adds r4, #0x14
	adds r1, r6, #0
	adds r1, #0xdc
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081E955E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	adds r0, r6, #0
	bl FUN_081e9d04
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9596
	adds r1, r6, #0
	adds r1, #0xf0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081E9582
	subs r0, r2, #1
	b _081E958C
_081E9582:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
_081E958C:
	strh r0, [r1]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_081e8f2c
_081E9596:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e95a4
FUN_081e95a4: @ 0x081E95A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081E9648 @ =0x030001B4
	ldr r0, [r0]
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xe6
	ldrh r0, [r6]
	cmp r0, #0
	beq _081E95F0
	ldrb r0, [r5, #2]
	mov r2, sp
	adds r2, #5
	add r1, sp, #4
	bl FUN_081e978c
	adds r0, r5, #0
	adds r0, #0xbc
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	adds r2, r5, #0
	adds r2, #0x80
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	strh r4, [r6]
_081E95F0:
	adds r1, r5, #0
	adds r1, #0x80
	ldrh r0, [r5, #0xc]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0xe]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0x10]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r7, r5, #0
	adds r7, #0x64
	adds r4, r5, #0
	adds r4, #0xbc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov ip, r7
	cmp r1, r0
	beq _081E964C
	ldr r0, [r5, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9654
	.align 2, 0
_081E9648: .4byte 0x030001B4
_081E964C:
	ldr r0, [r5, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9654:
	str r0, [r5, #0x64]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9678
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E9680
_081E9678:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9680:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E96B8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E96FE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E96C2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E96BC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E96D8
	.align 2, 0
_081E96B8: .4byte 0x0000FFFF
_081E96BC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E96D6
_081E96C2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E96D6
	strh r1, [r4, #8]
	movs r2, #1
	b _081E96D8
_081E96D6:
	movs r2, #0
_081E96D8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9700
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9700
_081E96FE:
	movs r2, #0
_081E9700:
	cmp r2, #0
	beq _081E9736
	mov r0, ip
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x90
	bl FUN_0822a4e0
	adds r4, r5, #0
	adds r4, #0xe4
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	movs r1, #0xf4
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strb r0, [r5]
_081E9736:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e9744
FUN_081e9744: @ 0x081E9744
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081E974C:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081E975E
	movs r0, #1
	b _081E9760
_081E975E:
	movs r0, #0
_081E9760:
	cmp r0, #0
	bne _081E977C
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0xe4
	strb r2, [r1]
	b _081E9784
_081E977C:
	adds r2, #1
	cmp r2, #0xb
	ble _081E974C
	movs r0, #0
_081E9784:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e978c
FUN_081e978c: @ 0x081E978C
	push {lr}
	adds r3, r0, #0
	asrs r0, r3, #5
	adds r3, r0, #3
	movs r0, #7
	ands r3, r0
	cmp r3, #6
	beq _081E97B4
	cmp r3, #6
	bgt _081E97A6
	cmp r3, #5
	beq _081E97AC
	b _081E97C2
_081E97A6:
	cmp r3, #7
	beq _081E97BC
	b _081E97C2
_081E97AC:
	movs r0, #3
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97B4:
	movs r0, #2
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97BC:
	movs r0, #1
	strb r0, [r1]
	b _081E97C6
_081E97C2:
	strb r3, [r1]
	movs r0, #0
_081E97C6:
	strb r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_081e97cc
FUN_081e97cc: @ 0x081E97CC
	push {lr}
	mov ip, r0
	mov r3, ip
	adds r3, #0xdc
	mov r2, ip
	adds r2, #0x80
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	mov r1, ip
	ldrb r0, [r1, #2]
	lsrs r0, r0, #5
	cmp r0, #7
	bhi _081E98E4
	lsls r0, r0, #2
	ldr r1, _081E97FC @ =_081E9800
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E97FC: .4byte _081E9800
_081E9800: @ jump table
	.4byte _081E9820 @ case 0
	.4byte _081E983E @ case 1
	.4byte _081E985C @ case 2
	.4byte _081E987A @ case 3
	.4byte _081E9886 @ case 4
	.4byte _081E9892 @ case 5
	.4byte _081E989A @ case 6
	.4byte _081E98B8 @ case 7
_081E9820:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x40
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E983E:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E985C:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E987A:
	ldrh r0, [r2]
	subs r0, #0x60
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	b _081E98C8
_081E9886:
	ldrh r0, [r2]
	subs r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x20
	b _081E98C8
_081E9892:
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r3]
	b _081E98C4
_081E989A:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	b _081E98E2
_081E98B8:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	strh r0, [r3, #2]
_081E98C4:
	ldrh r0, [r2, #4]
	subs r0, #0x60
_081E98C8:
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	strh r0, [r1]
	ldrh r0, [r2, #4]
	subs r0, #0x10
	adds r1, #2
_081E98E2:
	strh r0, [r1]
_081E98E4:
	pop {r0}
	bx r0

	thumb_func_start FUN_081e98e8
FUN_081e98e8: @ 0x081E98E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	add r3, sp, #0x14
	ldr r2, _081E9914 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E9918
	asrs r1, r0, #0xc
	b _081E991E
	.align 2, 0
_081E9914: .4byte 0x085B0A08
_081E9918:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081E991E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E993A
	asrs r0, r0, #0xc
	b _081E9940
_081E993A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E9940:
	strh r0, [r3, #4]
	ldr r0, _081E9968 @ =0x00000309
	str r0, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #0
	add r2, sp, #0x14
	adds r3, r4, #0
	bl FUN_081e996c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081E9968: .4byte 0x00000309

	thumb_func_start FUN_081e996c
FUN_081e996c: @ 0x081E996C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #8]
	mov r8, r1
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, _081E9998 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E999C
	bl FUN_081e9cac
	mov sb, r0
	cmp r0, #0
	bne _081E999E
_081E9992:
	movs r0, #0
	b _081E9B7C
	.align 2, 0
_081E9998: .4byte 0x030001B4
_081E999C:
	mov sb, r0
_081E999E:
	mov r0, sb
	bl FUN_081e9744
	adds r6, r0, #0
	cmp r6, #0
	beq _081E9992
	adds r7, r6, #0
	adds r7, #0x64
	adds r5, r6, #0
	adds r5, #0x90
	mov r4, sb
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r6, #0x64]
	movs r1, #1
	mov sl, r1
	orrs r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r1, r6, #0
	adds r1, #0xec
	movs r0, #0
	strh r0, [r1]
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	mov r0, r8
	cmp r0, #0
	beq _081E9A0C
	ldrh r0, [r0]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	mov r2, r8
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	ldrh r0, [r2, #4]
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
_081E9A0C:
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	movs r0, #0xff
	strb r0, [r6, #1]
	mov r0, sp
	ldrb r0, [r0, #0x10]
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0xea
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	adds r1, #6
	ldr r0, [sp, #0x44]
	strh r0, [r1]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r6, #4]
	str r1, [r6, #8]
	adds r2, r6, #0
	adds r2, #0xac
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r5]
	mov r1, sl
	orrs r0, r1
	str r0, [r5]
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	adds r5, r6, #0
	adds r5, #0xbc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_08236fac
	adds r0, r6, #0
	adds r0, #0xcc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl FUN_08237040
	mov r8, r7
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081E9AB4
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9ABC
_081E9AB4:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9ABC:
	str r0, [r6, #0x64]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9AE2
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081E9AEC
_081E9AE2:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9AEC:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E9B24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081E9B5C
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9B28
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E9B1E
	ldrb r0, [r5, #5]
_081E9B1E:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9B38
	.align 2, 0
_081E9B24: .4byte 0x0000FFFF
_081E9B28:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9B38
	strh r1, [r5, #8]
_081E9B38:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9B5C
	movs r0, #1
	strb r0, [r5, #7]
_081E9B5C:
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	ldr r3, [sp, #0x40]
	bl FUN_081e8e7c
	adds r0, r6, #0
	bl FUN_081e97cc
	movs r0, #1
	strb r0, [r6]
	strb r0, [r7, #7]
	adds r1, r6, #0
	adds r1, #0x97
	strb r0, [r1]
	adds r0, r6, #0
_081E9B7C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e9b8c
FUN_081e9b8c: @ 0x081E9B8C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	mov r2, sp
	ldr r1, _081E9BC8 @ =0x082523E8
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	ldr r1, _081E9BCC @ =0x030047A4
	ldr r2, _081E9BD0 @ =0x030047A0
	ldr r1, [r1]
	ldr r2, [r2]
	orrs r1, r2
	ands r1, r3
	cmp r1, #0
	bne _081E9BC4
	movs r2, #4
	ldr r1, _081E9BD4 @ =0x03002BC0
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	bne _081E9BC4
	ldr r1, [r6, #0x38]
	cmp r1, #0
	bne _081E9BD8
_081E9BC4:
	movs r0, #0
	b _081E9C1C
	.align 2, 0
_081E9BC8: .4byte 0x082523E8
_081E9BCC: .4byte 0x030047A4
_081E9BD0: .4byte 0x030047A0
_081E9BD4: .4byte 0x03002BC0
_081E9BD8:
	movs r5, #0
_081E9BDA:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9BEA
	movs r1, #1
	b _081E9BEC
_081E9BEA:
	movs r1, #0
_081E9BEC:
	cmp r1, #0
	beq _081E9C16
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	ldrb r1, [r4]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r1, [r4, #0x1a]
	ldr r3, _081E9C24 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r4, #0x1a]
_081E9C16:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9BDA
_081E9C1C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C24: .4byte 0x0000FFFB

	thumb_func_start FUN_081e9c28
FUN_081e9c28: @ 0x081E9C28
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081E9C2E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9C3E
	movs r1, #1
	b _081E9C40
_081E9C3E:
	movs r1, #0
_081E9C40:
	cmp r1, #0
	beq _081E9C5E
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	adds r0, r4, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r4, #0x90
	adds r0, r4, #0
	bl FUN_0822a4e0
_081E9C5E:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9C2E
	ldr r2, _081E9C70 @ =0x030001B4
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C70: .4byte 0x030001B4

	thumb_func_start FUN_081e9c74
FUN_081e9c74: @ 0x081E9C74
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	ldr r1, _081E9C9C @ =0x00002D41
	bl FUN_0822b16c
	ldr r0, _081E9CA0 @ =0x0000922E
	ldr r1, _081E9CA4 @ =0x0000D6C8
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x18]
	ldr r1, _081E9CA8 @ =0x030001B4
	str r4, [r1]
	movs r1, #0
	str r1, [r4, #0x38]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C9C: .4byte 0x00002D41
_081E9CA0: .4byte 0x0000922E
_081E9CA4: .4byte 0x0000D6C8
_081E9CA8: .4byte 0x030001B4

	thumb_func_start FUN_081e9cac
FUN_081e9cac: @ 0x081E9CAC
	push {r4, lr}
	ldr r0, _081E9CE0 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E9CF2
	ldr r1, _081E9CE4 @ =0x00000BAC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E9CF0
	ldr r1, _081E9CE8 @ =FUN_081e9b8c
	ldr r2, _081E9CEC @ =FUN_081e9c28
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e9c74
	cmp r0, #0
	bge _081E9CF0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E9CF2
	.align 2, 0
_081E9CE0: .4byte 0x030001B4
_081E9CE4: .4byte 0x00000BAC
_081E9CE8: .4byte FUN_081e9b8c
_081E9CEC: .4byte FUN_081e9c28
_081E9CF0:
	adds r0, r4, #0
_081E9CF2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e9cf8
FUN_081e9cf8: @ 0x081E9CF8
	ldr r1, _081E9D00 @ =0x030001B4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E9D00: .4byte 0x030001B4

	thumb_func_start FUN_081e9d04
FUN_081e9d04: @ 0x081E9D04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081E9D1C
	adds r0, r6, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #4
	bls _081E9DAC
_081E9D1C:
	adds r0, r6, #0
	adds r0, #0x82
	movs r1, #0
	ldrsh r7, [r0, r1]
	adds r5, r6, #0
	adds r5, #0xdc
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E9D4C
	cmp r1, #0
	blt _081E9D4C
	ldr r0, _081E9D50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E9D4C
	ldr r0, _081E9D54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E9D58
_081E9D4C:
	movs r4, #0
	b _081E9D66
	.align 2, 0
_081E9D50: .4byte 0x030046A8
_081E9D54: .4byte 0x030046AC
_081E9D58:
	ldr r0, _081E9D78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E9D66:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E9D7C
	adds r0, #4
	b _081E9D88
	.align 2, 0
_081E9D78: .4byte 0x030046A4
_081E9D7C:
	ldr r0, _081E9D9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E9D88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E9DA0
	cmp r2, #2
	beq _081E9DA4
	b _081E9DA8
	.align 2, 0
_081E9D9C: .4byte 0x030046A4
_081E9DA0:
	ldrb r0, [r5, #4]
	b _081E9DA6
_081E9DA4:
	ldrb r0, [r5]
_081E9DA6:
	subs r1, r1, r0
_081E9DA8:
	cmp r7, r1
	blo _081E9DB0
_081E9DAC:
	movs r0, #0
	b _081E9DBC
_081E9DB0:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
_081E9DBC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9dc4
FUN_081e9dc4: @ 0x081E9DC4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e9dc8
FUN_081e9dc8: @ 0x081E9DC8
	push {r4, r5, r6, r7, lr}
	mov ip, r1
	movs r2, #0xb
	ldrsb r2, [r1, r2]
	movs r1, #0x2c
	muls r1, r2, r1
	adds r1, #0x1c
	adds r6, r0, r1
	mov r3, ip
	ldr r1, [r3]
	ldr r2, [r3, #4]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	ldr r5, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r5, r1
	str r5, [r6]
	movs r1, #0xb
	ldrsb r1, [r3, r1]
	lsls r1, r1, #4
	adds r4, r1, r0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9E24
	movs r0, #4
	orrs r5, r0
	b _081E9E2A
_081E9E24:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
_081E9E2A:
	str r5, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9E4E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E9E56
_081E9E4E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9E56:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E9E90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E9ED6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9E9A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9E94
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9EB0
	.align 2, 0
_081E9E90: .4byte 0x0000FFFF
_081E9E94:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9EAE
_081E9E9A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9EAE
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9EB0
_081E9EAE:
	movs r2, #0
_081E9EB0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9ED8
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9ED8
_081E9ED6:
	movs r2, #0
_081E9ED8:
	cmp r2, #0
	beq _081E9EE2
	movs r0, #2
	mov r3, ip
	strb r0, [r3, #0xa]
_081E9EE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e9ee8
FUN_081e9ee8: @ 0x081E9EE8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r4, r0
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r5, #0xa]
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0xc
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0xb]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e9f28
FUN_081e9f28: @ 0x081E9F28
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r4, r2, r0
	movs r5, #1
	mov ip, r3
_081E9F38:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E9F48
	movs r0, #1
	b _081E9F4A
_081E9F48:
	movs r0, #0
_081E9F4A:
	cmp r0, #0
	bne _081E9F64
	movs r0, #0x87
	lsls r0, r0, #2
	add r0, ip
	adds r0, r2, r0
	strb r3, [r0, #0xb]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _081E9F70
_081E9F64:
	movs r0, #0xc
	add ip, r0
	adds r3, #1
	cmp r3, #7
	ble _081E9F38
	movs r0, #0
_081E9F70:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9f78
FUN_081e9f78: @ 0x081E9F78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, r1
	str r2, [sp, #4]
	cmp r0, #0
	beq _081E9F96
	ldr r0, _081E9F9C @ =0x030001B8
	ldr r6, [r0]
	cmp r6, #0
	bne _081E9FA0
_081E9F96:
	movs r0, #1
	rsbs r0, r0, #0
	b _081EA01E
	.align 2, 0
_081E9F9C: .4byte 0x030001B8
_081E9FA0:
	movs r7, #0
	cmp r7, r8
	bge _081EA01C
	movs r0, #1
	mov sl, r0
	lsls r3, r3, #0x10
	str r3, [sp, #8]
_081E9FAE:
	adds r0, r6, #0
	bl FUN_081e9f28
	adds r5, r0, #0
	cmp r5, #0
	beq _081E9F96
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	adds r4, r1, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r6, r4
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5]
	str r1, [r5, #4]
	adds r0, r4, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	lsls r0, r0, #4
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, [r6, #0x18]
	movs r2, #0
	str r2, [sp]
	ldr r3, [sp, #8]
	lsrs r2, r3, #0x10
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r4, #0xc]
	ldr r1, [sp, #0x2c]
	bl FUN_0822b20c
	ldr r0, [r4]
	mov r1, sl
	orrs r0, r1
	str r0, [r4]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r4, #7]
	strb r1, [r5, #0xa]
	adds r7, #1
	cmp r7, r8
	blt _081E9FAE
_081EA01C:
	movs r0, #0
_081EA01E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea030
FUN_081ea030: @ 0x081EA030
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EA08A
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r4, r6, r1
	ldr r0, _081EA068 @ =0x085AE45C
	mov r8, r0
_081EA056:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA06C
	movs r0, #1
	b _081EA06E
	.align 2, 0
_081EA068: .4byte 0x085AE45C
_081EA06C:
	movs r0, #0
_081EA06E:
	cmp r0, #0
	beq _081EA082
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EA082:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA056
_081EA08A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea098
FUN_081ea098: @ 0x081EA098
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	adds r0, #4
	adds r4, r6, r0
_081EA0A8:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA0B8
	movs r0, #1
	b _081EA0BA
_081EA0B8:
	movs r0, #0
_081EA0BA:
	cmp r0, #0
	beq _081EA0CE
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r6, r0
	bl FUN_0822a4e0
_081EA0CE:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA0A8
	movs r1, #0
	ldr r0, _081EA0E4 @ =0x030001B8
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA0E4: .4byte 0x030001B8

	thumb_func_start FUN_081ea0e8
FUN_081ea0e8: @ 0x081EA0E8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _081EA108 @ =0x0000863A
	bl FUN_0822b16c
	ldr r0, _081EA10C @ =0x0000922E
	ldr r1, _081EA110 @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081EA108: .4byte 0x0000863A
_081EA10C: .4byte 0x0000922E
_081EA110: .4byte 0x0000931E

	thumb_func_start FUN_081ea114
FUN_081ea114: @ 0x081EA114
	push {lr}
	bl FUN_081ea0e8
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea120
FUN_081ea120: @ 0x081EA120
	push {r4, r5, lr}
	ldr r5, _081EA15C @ =0x030001B8
	ldr r0, [r5]
	cmp r0, #0
	bne _081EA16A
	movs r1, #0x9f
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _081EA168
	ldr r1, _081EA160 @ =FUN_081ea030
	ldr r2, _081EA164 @ =FUN_081ea098
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_081ea114
	cmp r0, #0
	bge _081EA168
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA16A
	.align 2, 0
_081EA15C: .4byte 0x030001B8
_081EA160: .4byte FUN_081ea030
_081EA164: .4byte FUN_081ea098
_081EA168:
	adds r0, r4, #0
_081EA16A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea170
FUN_081ea170: @ 0x081EA170
	ldr r1, _081EA178 @ =0x030001B8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EA178: .4byte 0x030001B8

	thumb_func_start FUN_081ea17c
FUN_081ea17c: @ 0x081EA17C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea180
FUN_081ea180: @ 0x081EA180
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea184
FUN_081ea184: @ 0x081EA184
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r7, [sp, #0x38]
	ldr r2, _081EA210 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081EA214 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _081EA218 @ =0x00002001
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081EA21C @ =FUN_081ea180
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EA210: .4byte 0xFFFF0000
_081EA214: .4byte 0x0000FFFF
_081EA218: .4byte 0x00002001
_081EA21C: .4byte FUN_081ea180

	thumb_func_start FUN_081ea220
FUN_081ea220: @ 0x081EA220
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081EA228:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x34]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081EA23A
	movs r0, #1
	b _081EA23C
_081EA23A:
	movs r0, #0
_081EA23C:
	cmp r0, #0
	bne _081EA258
	movs r0, #0xd4
	muls r0, r2, r0
	adds r0, #0x38
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x34]
	adds r1, r0, #0
	adds r1, #0xd3
	strb r2, [r1]
	b _081EA260
_081EA258:
	adds r2, #1
	cmp r2, #7
	ble _081EA228
	movs r0, #0
_081EA260:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea268
FUN_081ea268: @ 0x081EA268
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r7, r1, #0
	mov sb, r7
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldrh r0, [r7, #0x34]
	ldrh r1, [r7, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x36]
	ldrh r2, [r7, #0x2e]
	adds r0, r1, r2
	strh r0, [r7, #0x2e]
	ldrh r0, [r7, #0x38]
	ldrh r2, [r7, #0x30]
	adds r0, r0, r2
	strh r0, [r7, #0x30]
	subs r1, #1
	strh r1, [r7, #0x36]
	movs r0, #0x1e
	ldrsh r6, [r7, r0]
	adds r5, r7, #0
	adds r5, #0x1c
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081EA2D4
	cmp r1, #0
	blt _081EA2D4
	ldr r0, _081EA2D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EA2D4
	ldr r0, _081EA2DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EA2E0
_081EA2D4:
	movs r4, #0
	b _081EA2EE
	.align 2, 0
_081EA2D8: .4byte 0x030046A8
_081EA2DC: .4byte 0x030046AC
_081EA2E0:
	ldr r0, _081EA300 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081EA2EE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081EA304
	adds r0, #4
	b _081EA310
	.align 2, 0
_081EA300: .4byte 0x030046A4
_081EA304:
	ldr r0, _081EA324 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EA310:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EA328
	cmp r2, #2
	beq _081EA32C
	b _081EA330
	.align 2, 0
_081EA324: .4byte 0x030046A4
_081EA328:
	ldrb r0, [r5, #4]
	b _081EA32E
_081EA32C:
	ldrb r0, [r5]
_081EA32E:
	subs r1, r1, r0
_081EA330:
	cmp r6, r1
	blo _081EA33E
	mov r1, sb
	movs r2, #0x1e
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _081EA424
_081EA33E:
	movs r0, #0xeb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r5, r7, #0
	adds r5, #0xd3
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r7, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	mov r0, sb
	bl FUN_0822a4e0
	adds r0, r7, #0
	adds r0, #0x8c
	bl FUN_080138fc
	movs r0, #0xff
	strb r0, [r5]
	adds r0, r7, #0
	adds r0, #0xd0
	strh r4, [r0]
	subs r0, #4
	str r4, [r0]
	ldr r5, _081EA40C @ =0xFFFF0000
	ldr r4, [sp, #0xc]
	ands r4, r5
	ldr r6, _081EA410 @ =0x0000FFF4
	orrs r4, r6
	str r4, [sp, #0xc]
	ldr r0, _081EA414 @ =0x0203B400
	mov ip, r0
	ldr r1, _081EA418 @ =0x030046B8
	mov sl, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r2, _081EA41C @ =0x000003FF
	mov r8, r2
	ands r1, r2
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	movs r0, #7
	mov sb, r0
	mov r0, sb
	ands r2, r0
	lsls r2, r2, #0x10
	ldr r3, _081EA420 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r6
	str r0, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ands r2, r5
	movs r4, #0x18
	orrs r2, r4
	str r2, [sp, #0x14]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	mov r0, sl
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	mov r1, sb
	ands r0, r1
	adds r0, #3
	lsls r0, r0, #0x10
	ands r3, r2
	orrs r3, r0
	str r3, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r4
	str r0, [r1, #4]
	adds r2, r7, #0
	adds r2, #0x2c
	str r1, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x1f
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
	b _081EA43A
	.align 2, 0
_081EA40C: .4byte 0xFFFF0000
_081EA410: .4byte 0x0000FFF4
_081EA414: .4byte 0x0203B400
_081EA418: .4byte 0x030046B8
_081EA41C: .4byte 0x000003FF
_081EA420: .4byte 0x0000FFFF
_081EA424:
	adds r4, r7, #0
	adds r4, #0x3c
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081EA43A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ea44c
FUN_081ea44c: @ 0x081EA44C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081EA46E
	movs r2, #0
	cmp r0, #0x28
	ble _081EA46E
	movs r2, #1
_081EA46E:
	adds r4, r5, #0
	adds r4, #0xcc
	ldr r0, [r4]
	ldr r1, _081EA498 @ =0x085AE468
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	adds r7, r4, #0
	cmp r0, #0
	bne _081EA4A0
	ldr r1, [r6]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081EA49C
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EA49E
	.align 2, 0
_081EA498: .4byte 0x085AE468
_081EA49C:
	orrs r1, r2
_081EA49E:
	str r1, [r6]
_081EA4A0:
	ldr r0, [r7]
	cmp r0, #0x5a
	ble _081EA4E4
	movs r0, #0xd3
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r5, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x8c
	bl FUN_080138fc
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	strh r4, [r0]
	str r4, [r7]
	b _081EA4E8
_081EA4E4:
	adds r0, #1
	str r0, [r7]
_081EA4E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ea4f4
FUN_081ea4f4: @ 0x081EA4F4
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _081EA518
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081EA51E
_081EA518:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081EA51E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ea524
FUN_081ea524: @ 0x081EA524
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	ldr r6, [sp, #0x24]
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	bl FUN_081ea688
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea540
FUN_081ea540: @ 0x081EA540
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	mov sl, r1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldrh r1, [r1, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r7, _081EA670 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sl
	ldrh r1, [r0, #0xc]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r6, sp, #0xc
	ldr r0, [sp, #0x10]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _081EA674 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081EA678 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r0, r0, r2
	ldrh r4, [r0]
	movs r0, #0x3f
	ands r4, r0
	adds r4, #0x1e
	adds r0, r6, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0xc]
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #2
	bl Div
	ldr r1, [r5]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	str r1, [r5]
	lsls r1, r1, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #7
	ands r1, r2
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _081EA680 @ =0x0000FFFF
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x30
	ble _081EA60A
	adds r0, r7, #0
	ands r0, r2
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA60A:
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081EA622
	ldr r0, [sp, #0xc]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA622:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0x30
	ble _081EA634
	ldr r0, [sp, #0x10]
	ands r0, r7
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA634:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bge _081EA646
	ldr r0, [sp, #0x10]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA646:
	ldr r2, [sp, #0x18]
	str r2, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	str r0, [sp, #8]
	mov r0, sb
	mov r1, sl
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	bl FUN_081ea688
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA670: .4byte 0xFFFF0000
_081EA674: .4byte 0x030046B8
_081EA678: .4byte 0x000003FF
_081EA67C: .4byte 0x0203B400
_081EA680: .4byte 0x0000FFFF
_081EA684: .4byte 0x0000FFD0

	thumb_func_start FUN_081ea688
FUN_081ea688: @ 0x081EA688
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r2
	mov sl, r3
	ldr r0, _081EA740 @ =0x030001BC
	ldr r7, [r0]
	cmp r7, #0
	bne _081EA6AC
	bl FUN_081ea820
	adds r7, r0, #0
	cmp r7, #0
	beq _081EA748
_081EA6AC:
	adds r0, r7, #0
	bl FUN_081ea220
	adds r6, r0, #0
	cmp r6, #0
	beq _081EA748
	adds r0, #0xd2
	movs r4, #0
	movs r1, #1
	mov sb, r1
	mov r2, sb
	strb r2, [r0]
	mov r2, sp
	adds r2, #5
	adds r0, r5, #0
	add r1, sp, #4
	bl FUN_081ea4f4
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0xd0
	strh r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0x8c
	adds r1, r6, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_0801385c
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	strh r0, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, _081EA744 @ =0x00000243
	bl FUN_0822b20c
	ldr r0, [r6]
	mov r1, sb
	orrs r0, r1
	str r0, [r6]
	movs r0, #2
	strb r0, [r6, #7]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	adds r0, r6, #0
	mov r1, sl
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl FUN_081ea184
	adds r0, r6, #0
	adds r0, #0xd3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _081EA74C
	.align 2, 0
_081EA740: .4byte 0x030001BC
_081EA744: .4byte 0x00000243
_081EA748:
	movs r0, #1
	rsbs r0, r0, #0
_081EA74C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea75c
FUN_081ea75c: @ 0x081EA75C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x38
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _081EA7AA
	movs r4, #0
	ldr r7, _081EA780 @ =0x085AE46C
_081EA76E:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA784
	movs r0, #1
	b _081EA786
	.align 2, 0
_081EA780: .4byte 0x085AE46C
_081EA784:
	movs r0, #0
_081EA786:
	cmp r0, #0
	beq _081EA7A4
	movs r0, #0xd4
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EA7A4:
	adds r4, #1
	cmp r4, #7
	ble _081EA76E
_081EA7AA:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea7b4
FUN_081ea7b4: @ 0x081EA7B4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081EA7BA:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA7CA
	movs r0, #1
	b _081EA7CC
_081EA7CA:
	movs r0, #0
_081EA7CC:
	cmp r0, #0
	beq _081EA7E8
	movs r0, #0xd4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r6, r4
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x8c
	adds r0, r4, #0
	bl FUN_080138fc
_081EA7E8:
	adds r5, #1
	cmp r5, #7
	ble _081EA7BA
	ldr r1, _081EA7FC @ =0x030001BC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EA7FC: .4byte 0x030001BC

	thumb_func_start FUN_081ea800
FUN_081ea800: @ 0x081EA800
	push {lr}
	movs r1, #0
	str r1, [r0, #0x34]
	ldr r1, _081EA818 @ =0x030001BC
	str r0, [r1]
	adds r0, #0x18
	ldr r1, _081EA81C @ =0x000084EE
	bl FUN_0822b16c
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081EA818: .4byte 0x030001BC
_081EA81C: .4byte 0x000084EE

	thumb_func_start FUN_081ea820
FUN_081ea820: @ 0x081EA820
	push {r4, lr}
	ldr r0, _081EA858 @ =0x030001BC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EA866
	movs r1, #0xdb
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EA864
	ldr r1, _081EA85C @ =FUN_081ea75c
	ldr r2, _081EA860 @ =FUN_081ea7b4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081ea800
	cmp r0, #0
	bge _081EA864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA866
	.align 2, 0
_081EA858: .4byte 0x030001BC
_081EA85C: .4byte FUN_081ea75c
_081EA860: .4byte FUN_081ea7b4
_081EA864:
	adds r0, r4, #0
_081EA866:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea86c
FUN_081ea86c: @ 0x081EA86C
	ldr r1, _081EA874 @ =0x030001BC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EA874: .4byte 0x030001BC

	thumb_func_start FUN_081ea878
FUN_081ea878: @ 0x081EA878
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea87c
FUN_081ea87c: @ 0x081EA87C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081EA8D4 @ =0x030001C0
	ldr r4, [r0]
	ldrb r1, [r5, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081EA892
	b _081EA9E0
_081EA892:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _081EA8DC
	movs r3, #0x97
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _081EA8DC
	adds r1, r4, #0
	adds r1, #0x18
	ldr r0, _081EA8D8 @ =0x085AE478
	ldrb r2, [r0, #0x12]
_081EA8C4:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #2
	bl FUN_082370cc
	b _081EAA04
	.align 2, 0
_081EA8D4: .4byte 0x030001C0
_081EA8D8: .4byte 0x085AE478
_081EA8DC:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081EA900
	ldr r0, _081EA938 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081EA900
	movs r0, #0xd4
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081EA900:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #1
	bne _081EA940
	adds r3, #8
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081EA940
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _081EA93C @ =0x085AE478
	movs r4, #0x95
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r4, #0
	ldrsh r2, [r2, r4]
	adds r0, r0, r2
	adds r0, r0, r3
	ldrb r2, [r0]
	b _081EA8C4
	.align 2, 0
_081EA938: .4byte 0x030047A4
_081EA93C: .4byte 0x085AE478
_081EA940:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r2, r2, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bne _081EA9C4
	movs r0, #0x9b
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r1, #0
	ldrsh r0, [r7, r1]
	ldr r3, _081EA9BC @ =0x0000052C
	adds r2, r4, r3
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_0822f1c0
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ands r4, r0
	adds r6, r5, #0
	adds r6, #0x60
	cmp r4, #0
	beq _081EA9A4
	adds r0, r6, #0
	bl FUN_08002a58
_081EA9A4:
	adds r0, r6, #0
	bl FUN_0823b284
	ldr r0, _081EA9C0 @ =0x0000FFFF
	strh r0, [r7]
	movs r2, #0x99
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #1
	b _081EAA06
	.align 2, 0
_081EA9BC: .4byte 0x0000052C
_081EA9C0: .4byte 0x0000FFFF
_081EA9C4:
	adds r1, r4, #0
	adds r1, #0x18
	ldr r0, _081EA9DC @ =0x085AE478
	adds r0, r2, r0
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #2
	bl FUN_082370cc
	b _081EA9EA
	.align 2, 0
_081EA9DC: .4byte 0x085AE478
_081EA9E0:
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	bl FUN_082372cc
_081EA9EA:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #1
	bne _081EAA04
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_081EAA04:
	movs r0, #0
_081EAA06:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081eaa10
FUN_081eaa10: @ 0x081EAA10
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081ea87c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081EAA4E
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne _081EAA42
	adds r4, r5, #0
	adds r4, #0xd8
	adds r1, r5, #0
	adds r1, #0xd0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081EAA42:
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081EAA4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081eaa54
FUN_081eaa54: @ 0x081EAA54
	bx lr
	.align 2, 0

	thumb_func_start FUN_081eaa58
FUN_081eaa58: @ 0x081EAA58
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	ldr r1, _081EAA8C @ =0x0000052C
	adds r1, r1, r0
	mov sb, r1
	adds r6, r0, #0
	adds r6, #0x9c
	movs r2, #0xba
	lsls r2, r2, #1
	adds r5, r0, r2
	adds r4, r0, #0
	adds r4, #0x3c
	movs r0, #1
	mov r8, r0
_081EAA7A:
	mov r1, r8
	lsls r1, r7
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081EAA90
	movs r0, #1
	b _081EAA92
	.align 2, 0
_081EAA8C: .4byte 0x0000052C
_081EAA90:
	movs r0, #0
_081EAA92:
	cmp r0, #0
	beq _081EAAB4
	adds r0, r4, #0
	bl FUN_0822f1c0
	ldrh r1, [r5]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _081EAAAC
	adds r0, r6, #0
	bl FUN_08002a58
_081EAAAC:
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_0823b284
_081EAAB4:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, #1
	cmp r7, #3
	ble _081EAA7A
	movs r1, #0
	ldr r0, _081EAAD8 @ =0x030001C0
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EAAD8: .4byte 0x030001C0

	thumb_func_start FUN_081eaadc
FUN_081eaadc: @ 0x081EAADC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x3c
	ldr r1, _081EAB34 @ =0x0000052C
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EAB6C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EAB38 @ =0x030047A4
	ldr r1, _081EAB3C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EAB6C
	movs r1, #4
	ldr r0, _081EAB40 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081EAB6C
	movs r6, #0
	ldr r0, _081EAB34 @ =0x0000052C
	adds r7, r3, r0
	ldr r1, _081EAB44 @ =0x085AE48C
	mov r8, r1
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r5, r3, r0
_081EAB22:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EAB48
	movs r0, #1
	b _081EAB4A
	.align 2, 0
_081EAB34: .4byte 0x0000052C
_081EAB38: .4byte 0x030047A4
_081EAB3C: .4byte 0x030047A0
_081EAB40: .4byte 0x03002BC0
_081EAB44: .4byte 0x085AE48C
_081EAB48:
	movs r0, #0
_081EAB4A:
	cmp r0, #0
	beq _081EAB5E
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081EAB5E:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #3
	ble _081EAB22
_081EAB6C:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081eab78
FUN_081eab78: @ 0x081EAB78
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _081EAB9C @ =0x0000052C
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x3c
	movs r6, #0x9e
	lsls r6, r6, #1
_081EAB8A:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081EABA0
	movs r0, #1
	b _081EABA2
	.align 2, 0
_081EAB9C: .4byte 0x0000052C
_081EABA0:
	movs r0, #0
_081EABA2:
	cmp r0, #0
	bne _081EABBC
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	adds r0, r2, #0
	b _081EABC6
_081EABBC:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #3
	ble _081EAB8A
	movs r0, #0
_081EABC6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081eabcc
FUN_081eabcc: @ 0x081EABCC
	bx lr
	.align 2, 0

	thumb_func_start FUN_081eabd0
FUN_081eabd0: @ 0x081EABD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r3, #0
	cmp r5, #0
	bne _081EAC30
	cmp r2, #1
	beq _081EABFC
	cmp r2, #1
	bgt _081EABEC
	cmp r2, #0
	beq _081EABF2
	b _081EAC0E
_081EABEC:
	cmp r2, #2
	beq _081EAC04
	b _081EAC0E
_081EABF2:
	ldr r0, _081EABF8 @ =0x085AE498
	b _081EAC06
	.align 2, 0
_081EABF8: .4byte 0x085AE498
_081EABFC:
	ldr r0, _081EAC00 @ =0x085AE4A0
	b _081EAC06
	.align 2, 0
_081EAC00: .4byte 0x085AE4A0
_081EAC04:
	ldr r0, _081EAC28 @ =0x085AE4A8
_081EAC06:
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
_081EAC0E:
	ldr r3, _081EAC2C @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x14]
	add r0, sp, #0xc
	ldrh r2, [r0, #4]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r5, #0x40
	b _081EAC7E
	.align 2, 0
_081EAC28: .4byte 0x085AE4A8
_081EAC2C: .4byte 0xFFFF0000
_081EAC30:
	cmp r2, #1
	beq _081EAC4C
	cmp r2, #1
	bgt _081EAC3E
	cmp r2, #0
	beq _081EAC44
	b _081EAC6C
_081EAC3E:
	cmp r2, #2
	beq _081EAC54
	b _081EAC6C
_081EAC44:
	ldr r2, _081EAC48 @ =0x085AE498
	b _081EAC56
	.align 2, 0
_081EAC48: .4byte 0x085AE498
_081EAC4C:
	ldr r2, _081EAC50 @ =0x085AE4A0
	b _081EAC56
	.align 2, 0
_081EAC50: .4byte 0x085AE4A0
_081EAC54:
	ldr r2, _081EACD4 @ =0x085AE4A8
_081EAC56:
	ldr r3, _081EACD8 @ =0xFFFF0000
	ldrh r1, [r2, #2]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #4]
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r2]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x10]
_081EAC6C:
	add r0, sp, #0xc
	ldr r2, _081EACD8 @ =0xFFFF0000
	ldrh r0, [r0]
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
_081EAC7E:
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r2, _081EACDC @ =0x00002101
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _081EACE0 @ =0x00200004
	str r0, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r7, #0
	ldr r2, [sp, #0x30]
	movs r3, #0x40
	bl FUN_082364f8
	adds r1, r6, #0
	adds r1, #0xd0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081EACE4 @ =FUN_081eabcc
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r5, [r0]
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EACD4: .4byte 0x085AE4A8
_081EACD8: .4byte 0xFFFF0000
_081EACDC: .4byte 0x00002101
_081EACE0: .4byte 0x00200004
_081EACE4: .4byte FUN_081eabcc

	thumb_func_start FUN_081eace8
FUN_081eace8: @ 0x081EACE8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081EAD4C @ =0x030001C0
	ldr r5, [r0]
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r4, r4, r0
	movs r1, #0x95
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r6, #0
	strh r4, [r0]
	subs r1, #2
	adds r0, r7, r1
	strh r3, [r0]
	adds r1, #4
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	adds r5, #0x18
	str r1, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0xc]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0xd
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _081EAD50 @ =0x085AE478
	ldrb r2, [r0, #0x12]
	str r6, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #2
	bl FUN_082370cc
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EAD4C: .4byte 0x030001C0
_081EAD50: .4byte 0x085AE478

	thumb_func_start FUN_081ead54
FUN_081ead54: @ 0x081EAD54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	str r1, [sp, #8]
	mov sb, r2
	mov sl, r3
	ldr r0, [sp, #0x2c]
	mov r8, r0
	ldr r5, [sp, #0x44]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EADA4 @ =0x030047A4
	ldr r1, _081EADA8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EADA0
	movs r1, #4
	ldr r0, _081EADAC @ =0x03002BC0
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081EADA0
	ldr r0, _081EADB0 @ =0x030001C0
	ldr r0, [r0]
	cmp r0, #0
	beq _081EADA0
	bl FUN_081eab78
	adds r7, r0, #0
	cmp r7, #0
	bne _081EADB4
_081EADA0:
	movs r0, #0
	b _081EAED8
	.align 2, 0
_081EADA4: .4byte 0x030047A4
_081EADA8: .4byte 0x030047A0
_081EADAC: .4byte 0x03002BC0
_081EADB0: .4byte 0x030001C0
_081EADB4:
	adds r2, r7, #0
	adds r2, #0xd0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r1, sb
	strh r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x40]
	strh r0, [r1]
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #1
	mov sb, r1
	mov r1, sb
	strh r1, [r0]
	adds r6, r7, #0
	adds r6, #0x60
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823b400
	adds r4, r7, #0
	adds r4, #0xa4
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823b46c
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	mov r0, sb
	ands r5, r0
	cmp r5, #0
	beq _081EAEB6
	mov r1, sl
	cmp r1, #0
	bne _081EAE74
	mov r0, r8
	cmp r0, #1
	beq _081EAE54
	cmp r0, #1
	bgt _081EAE3E
	cmp r0, #0
	beq _081EAE46
	b _081EAEB0
_081EAE3E:
	mov r1, r8
	cmp r1, #2
	beq _081EAE60
	b _081EAEB0
_081EAE46:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE50 @ =0x085AE498
	adds r0, #0x20
	b _081EAE66
	.align 2, 0
_081EAE50: .4byte 0x085AE498
_081EAE54:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE5C @ =0x085AE4A0
	adds r0, #0x64
	b _081EAE66
	.align 2, 0
_081EAE5C: .4byte 0x085AE4A0
_081EAE60:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE70 @ =0x085AE4A8
	adds r0, #0xc8
_081EAE66:
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #0xc]
	b _081EAEB0
	.align 2, 0
_081EAE70: .4byte 0x085AE4A8
_081EAE74:
	mov r0, r8
	cmp r0, #1
	beq _081EAE98
	cmp r0, #1
	bgt _081EAE84
	cmp r0, #0
	beq _081EAE8C
	b _081EAEB0
_081EAE84:
	mov r1, r8
	cmp r1, #2
	beq _081EAEA4
	b _081EAEB0
_081EAE8C:
	ldrh r0, [r6, #8]
	ldr r1, _081EAE94 @ =0x085AE498
	adds r0, #0x20
	b _081EAEAA
	.align 2, 0
_081EAE94: .4byte 0x085AE498
_081EAE98:
	ldrh r0, [r6, #8]
	ldr r1, _081EAEA0 @ =0x085AE4A0
	adds r0, #0x64
	b _081EAEAA
	.align 2, 0
_081EAEA0: .4byte 0x085AE4A0
_081EAEA4:
	ldrh r0, [r6, #8]
	ldr r1, _081EAEE8 @ =0x085AE4A8
	adds r0, #0xc8
_081EAEAA:
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #8]
_081EAEB0:
	adds r0, r6, #0
	bl FUN_08002a48
_081EAEB6:
	ldr r0, [sp, #0x38]
	str r0, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	adds r0, r7, #0
	mov r1, sl
	mov r2, r8
	ldr r3, [sp, #0x34]
	bl FUN_081eabd0
	adds r0, r7, #0
	mov r1, sl
	mov r2, r8
	ldr r3, [sp, #0x30]
	bl FUN_081eace8
	adds r0, r7, #0
_081EAED8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EAEE8: .4byte 0x085AE4A8

	thumb_func_start FUN_081eaeec
FUN_081eaeec: @ 0x081EAEEC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081EAF1C @ =0x0000CB05
	ldr r1, _081EAF20 @ =0x00001BC7
	bl GetFile
	str r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x18
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, [r4, #0x38]
	bl OpenSpriteSetFile
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081EAF1C: .4byte 0x0000CB05
_081EAF20: .4byte 0x00001BC7

	thumb_func_start FUN_081eaf24
FUN_081eaf24: @ 0x081EAF24
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081EAF60 @ =0x030001C0
	str r4, [r0]
	adds r0, r4, #0
	bl FUN_081eaeec
	ldr r0, _081EAF64 @ =0x0000FFFF
	adds r5, r0, #0
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r3, #0x9e
	lsls r3, r3, #1
	movs r2, #3
_081EAF42:
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r1, r1, r3
	subs r2, #1
	cmp r2, #0
	bge _081EAF42
	movs r1, #0
	ldr r2, _081EAF68 @ =0x0000052C
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081EAF60: .4byte 0x030001C0
_081EAF64: .4byte 0x0000FFFF
_081EAF68: .4byte 0x0000052C

	thumb_func_start FUN_081eaf6c
FUN_081eaf6c: @ 0x081EAF6C
	push {r4, lr}
	ldr r0, _081EAFA4 @ =0x030001C0
	ldr r0, [r0]
	cmp r0, #0
	bne _081EAF9E
	movs r1, #0xa6
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EAF9E
	ldr r1, _081EAFA8 @ =FUN_081eaadc
	ldr r2, _081EAFAC @ =FUN_081eaa58
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081eaf24
	cmp r0, #0
	bge _081EAF9E
	adds r0, r4, #0
	bl KillEntity
_081EAF9E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081EAFA4: .4byte 0x030001C0
_081EAFA8: .4byte FUN_081eaadc
_081EAFAC: .4byte FUN_081eaa58

	thumb_func_start FUN_081eafb0
FUN_081eafb0: @ 0x081EAFB0
	ldr r1, _081EAFB8 @ =0x030001C0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EAFB8: .4byte 0x030001C0
