	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	bl Script_GetValue
	adds r6, r0, #0
	ldr r7, _0823D118 @ =0x030046A4
	ldr r0, [r7]
	ldr r5, [r0, #4]
	cmp r5, #0
	beq _0823D1CE
	movs r0, #4
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r6, r0
	blt _0823D120
	ldr r1, _0823D11C @ =0xFFFF0000
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	b _0823D192
	.align 2, 0
_0823D118: .4byte 0x030046A4
_0823D11C: .4byte 0xFFFF0000
_0823D120:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823D164 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	movs r0, #4
	ldrsh r1, [r5, r0]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r4, sp
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D168
	adds r0, #4
	b _0823D172
	.align 2, 0
_0823D164: .4byte 0xFFFF0000
_0823D168:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0823D172:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0823D186
	cmp r2, #2
	beq _0823D18A
	b _0823D18E
_0823D186:
	ldrb r0, [r4, #4]
	b _0823D18C
_0823D18A:
	ldrb r0, [r4]
_0823D18C:
	subs r1, r1, r0
_0823D18E:
	mov r0, sp
	strh r1, [r0, #2]
_0823D192:
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	mov r5, sp
	movs r0, #2
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r1, #4
	ldrsh r2, [r5, r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
_0823D1CE:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
