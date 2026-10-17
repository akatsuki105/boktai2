	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, [r5, #0x1c]
	cmp r1, #1
	bne _080D78D4
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r3, [r6, #6]
	ands r0, r3
	cmp r0, #0
	beq _080D78AC
	movs r0, #0x46
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ands r1, r2
	cmp r1, #0
	beq _080D78D4
	movs r0, #0xfe
	ands r0, r2
	mov r1, ip
	strb r0, [r1]
_080D78AC:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r3, r0
	cmp r3, #0
	beq _080D78CA
	adds r3, r4, #0
	adds r3, #0x46
	ldrb r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D78D4
	movs r0, #2
	orrs r0, r1
	strb r0, [r3]
_080D78CA:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_080d7558
_080D78D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
