	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	str r1, [sp]
	mov sb, r3
	ldr r0, _0807F4CC @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	bne _0807F4D0
	movs r0, #0
	b _0807F544
	.align 2, 0
_0807F4CC: .4byte 0x03002BF8
_0807F4D0:
	ldr r6, [r0, #0x18]
	movs r0, #0
	mov sl, r0
	adds r7, r2, #0
	muls r7, r2, r7
	cmp r6, #0
	beq _0807F542
	movs r0, #0x80
	lsls r0, r0, #1
	mov r1, sb
	subs r1, r0, r1
	str r1, [sp, #4]
_0807F4E8:
	ldr r0, [r6, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807F53C
	ldr r2, [r6]
	movs r3, #8
	ldrsh r1, [r2, r3]
	mov r4, r8
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r5, r1, r0
	movs r4, #0xc
	ldrsh r1, [r2, r4]
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r4, r1, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	ldr r2, [sp]
	ldr r3, _0807F554 @ =0xFFFFFF00
	adds r1, r2, r3
	subs r1, r0, r1
	movs r0, #0xff
	ands r1, r0
	cmp r1, sb
	ble _0807F52A
	ldr r0, [sp, #4]
	cmp r1, r0
	blt _0807F53C
_0807F52A:
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, r7
	bge _0807F53C
	adds r7, r0, #0
	mov sl, r6
_0807F53C:
	ldr r6, [r6, #0xc]
	cmp r6, #0
	bne _0807F4E8
_0807F542:
	mov r0, sl
_0807F544:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807F554: .4byte 0xFFFFFF00
