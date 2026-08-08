	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x40
	ldrh r0, [r6, #0x3e]
	cmp r0, #0
	beq _080DE3AA
	movs r7, #0
	movs r5, #0
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r3, r6, r0
	adds r4, r3, #0
	mov ip, r1
_080DE364:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DE374
	movs r0, #1
	b _080DE376
_080DE374:
	movs r0, #0
_080DE376:
	cmp r0, #0
	beq _080DE39C
	ldrh r0, [r3]
	cmp r0, #0
	beq _080DE386
	subs r0, #1
	strh r0, [r3]
	b _080DE39C
_080DE386:
	cmp r7, #5
	bgt _080DE39C
	movs r0, #3
	strh r0, [r4]
	mov r2, ip
	adds r2, #0xf4
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	adds r7, #1
_080DE39C:
	adds r3, #0xfc
	adds r4, #0xfc
	movs r0, #0xfc
	add ip, r0
	adds r5, #1
	cmp r5, #0x17
	ble _080DE364
_080DE3AA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
