	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0822AB1C @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r1, _0822AB20 @ =0x00000401
	str r1, [sp, #0xc]
	cmp r0, #0
	beq _0822AACC
	ldr r2, _0822AB24 @ =0x00000201
	str r2, [sp, #0xc]
_0822AACC:
	ldr r1, _0822AB28 @ =0x03003560
	ldr r0, _0822AB2C @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	bne _0822AADE
	b _0822AC80
_0822AADE:
	ldr r1, [r5]
	adds r0, r1, #0
	ldr r3, [sp, #0xc]
	ands r0, r3
	cmp r0, #0
	beq _0822AAEC
	b _0822AC78
_0822AAEC:
	ldr r6, [r5, #0xc]
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _0822ABA4
	mov r7, sp
	movs r0, #0x1c
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	mov r1, r8
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822AB30
	asrs r0, r0, #8
	b _0822AB36
	.align 2, 0
_0822AB1C: .4byte 0x03002CF0
_0822AB20: .4byte 0x00000401
_0822AB24: .4byte 0x00000201
_0822AB28: .4byte 0x03003560
_0822AB2C: .4byte 0x03003530
_0822AB30:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AB36:
	strh r0, [r7]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822AB48
	asrs r0, r0, #8
	b _0822AB4E
_0822AB48:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AB4E:
	adds r4, r0, #0
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0822AB64
	asrs r0, r0, #8
	b _0822AB6A
_0822AB64:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AB6A:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0822ABA0 @ =0x030047C8
	ldrh r0, [r7]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r7]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r7, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r7, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sl, r1
	movs r1, #2
	ldrsh r3, [r0, r1]
	mov sb, r3
	movs r3, #4
	ldrsh r2, [r0, r3]
	str r2, [sp, #8]
	b _0822ABB6
	.align 2, 0
_0822ABA0: .4byte 0x030047C8
_0822ABA4:
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	mov sl, r0
	movs r3, #0x1e
	ldrsh r2, [r5, r3]
	mov sb, r2
	movs r1, #0x20
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
_0822ABB6:
	ldr r1, [r5]
	movs r0, #0x40
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	bne _0822AC6C
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _0822AC1C
	movs r0, #0xa
	ldrsb r0, [r6, r0]
	movs r2, #8
	ldrsb r2, [r5, r2]
	muls r0, r2, r0
	asrs r3, r0, #6
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	movs r1, #9
	ldrsb r1, [r5, r1]
	muls r0, r1, r0
	asrs r0, r0, #6
	mov r8, r0
	ldrb r0, [r6, #8]
	muls r0, r2, r0
	asrs r0, r0, #6
	mov ip, r0
	ldrb r0, [r6, #9]
	muls r0, r1, r0
	asrs r7, r0, #6
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0822AC02
	mov r2, sl
	adds r0, r2, r3
	mov r3, ip
	b _0822AC04
_0822AC02:
	mov r0, sl
_0822AC04:
	subs r2, r0, r3
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq _0822AC16
	mov r0, sb
	add r0, r8
	subs r1, r0, r7
	b _0822AC56
_0822AC16:
	mov r3, sb
	mov r0, r8
	b _0822AC54
_0822AC1C:
	ldrb r1, [r6, #8]
	mov ip, r1
	ldrb r7, [r6, #9]
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0822AC34
	movs r0, #0xa
	ldrsb r0, [r6, r0]
	add r0, sl
	subs r2, r0, r1
	b _0822AC3C
_0822AC34:
	movs r0, #0xa
	ldrsb r0, [r6, r0]
	mov r3, sl
	subs r2, r3, r0
_0822AC3C:
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq _0822AC4E
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	add r0, sb
	subs r1, r0, r7
	b _0822AC56
_0822AC4E:
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	mov r3, sb
_0822AC54:
	subs r1, r3, r0
_0822AC56:
	cmp r2, #0xf0
	bgt _0822AC78
	cmp r1, #0xb4
	bgt _0822AC78
	mov r3, ip
	adds r0, r2, r3
	cmp r0, #0
	blt _0822AC78
	adds r0, r1, r7
	cmp r0, #0
	blt _0822AC78
_0822AC6C:
	adds r0, r5, #0
	mov r1, sl
	mov r2, sb
	ldr r3, [sp, #8]
	bl FUN_0822a574
_0822AC78:
	ldr r5, [r5, #0x28]
	cmp r5, #0
	beq _0822AC80
	b _0822AADE
_0822AC80:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
