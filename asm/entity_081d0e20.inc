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
	bl Entity081d0e20_Create
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
	bl VM_SeekToKeyword
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
	bl VM_GetKeywordValue
	adds r4, r5, #0
	adds r4, #0x88
	strh r0, [r4]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x8a
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToKeyword
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
	bl VM_GetKeywordValue
	strh r0, [r7]
	movs r0, #0x41
	bl VM_SeekToKeyword
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
	bl VM_GetKeywordValue
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
	bl Video_SetActorSpritePltt
	b _081D09C8
	.align 2, 0
_081D09BC: .4byte 0x00000282
_081D09C0:
	ldr r1, _081D0A14 @ =0x00000283
	mov r0, sb
	bl Video_SetActorSpritePltt
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
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
	adds r4, r0, #0
	cmp r4, #0
	blt _081D0C2C
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
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
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
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

	thumb_func_start Entity081d0e20_Update
Entity081d0e20_Update: @ 0x081D0CF0
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

	thumb_func_start Entity081d0e20_Destroy
Entity081d0e20_Destroy: @ 0x081D0D84
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

	thumb_func_start Entity081d0e20_Init
Entity081d0e20_Init: @ 0x081D0DEC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	ldr r1, _081D0E10 @ =0x0000A945
	bl Video_GetActorSprite
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

	thumb_func_start Entity081d0e20_Create
Entity081d0e20_Create: @ 0x081D0E20
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
	ldr r1, _081D0E58 @ =Entity081d0e20_Update
	ldr r2, _081D0E5C @ =Entity081d0e20_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081d0e20_Init
	cmp r0, #0
	bge _081D0E60
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D0E62
	.align 2, 0
_081D0E54: .4byte 0x03000188
_081D0E58: .4byte Entity081d0e20_Update
_081D0E5C: .4byte Entity081d0e20_Destroy
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
