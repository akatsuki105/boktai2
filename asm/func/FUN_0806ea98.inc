	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r3, #0x80
	lsls r3, r3, #0xb
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sb, r0
	ldr r0, _0806EAC8 @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	bne _0806EACC
	movs r0, #0
	b _0806EB2C
	.align 2, 0
_0806EAC8: .4byte 0x03002BF8
_0806EACC:
	ldr r6, [r0, #0x18]
	movs r2, #0
	mov r8, r2
	cmp r6, #0
	beq _0806EB2A
_0806EAD6:
	ldr r0, [r6, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0806EB24
	ldr r2, [r6]
	movs r4, #8
	ldrsh r1, [r2, r4]
	movs r4, #0x2c
	ldrsh r0, [r7, r4]
	subs r5, r1, r0
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r7, r2]
	subs r4, r1, r0
	adds r0, r5, #0
	adds r1, r4, #0
	str r3, [sp]
	bl FUN_0823785c
	ldr r1, _0806EB3C @ =0xFFFFFF00
	add r1, sb
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	subs r0, #0x21
	ldr r3, [sp]
	cmp r0, #0xbe
	bls _0806EB24
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, r3
	bge _0806EB24
	adds r3, r0, #0
	mov r8, r6
_0806EB24:
	ldr r6, [r6, #0xc]
	cmp r6, #0
	bne _0806EAD6
_0806EB2A:
	mov r0, r8
_0806EB2C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806EB3C: .4byte 0xFFFFFF00
