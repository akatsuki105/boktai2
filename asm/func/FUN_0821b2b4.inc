	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r5, r2, #0
	mov r6, sb
	adds r7, r1, #0
	movs r0, #0
	mov r8, r0
_0821B2C8:
	ldrb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0821B34E
	cmp r0, #0
	blt _0821B30C
	ldrb r0, [r5]
	cmp r0, #0x3c
	bne _0821B2EA
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	b _0821B34A
_0821B2EA:
	cmp r0, #0xa
	bne _0821B2F4
	mov r6, sb
	adds r7, #2
	b _0821B34A
_0821B2F4:
	ldrb r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_0822eb30
	adds r6, #1
	b _0821B34A
_0821B30C:
	ldrb r1, [r5]
	movs r0, #0x7f
	ands r0, r1
	adds r5, #1
	ldrb r1, [r5]
	lsls r4, r0, #8
	orrs r4, r1
	bl FUN_0822e860
	cmp r4, r0
	blo _0821B326
	adds r6, #2
	b _0821B34A
_0821B326:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_0822ebb8
	adds r6, #2
	mov r0, r8
	cmp r0, #1
	bne _0821B34A
	adds r5, #1
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
_0821B34A:
	adds r5, #1
	b _0821B2C8
_0821B34E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
