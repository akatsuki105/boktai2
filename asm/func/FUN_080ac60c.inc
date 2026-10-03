	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _080AC634 @ =0x0000A854
	bl Registry_Find
	adds r4, r0, #0
	cmp r4, #0
	bne _080AC62C
	bl Entity080ac574_Create
	adds r4, r0, #0
_080AC62C:
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0x4e
	b _080AC640
	.align 2, 0
_080AC634: .4byte 0x0000A854
_080AC638:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #3
	bgt _080AC68E
_080AC640:
	ldrh r0, [r1]
	cmp r0, #0
	bne _080AC638
	cmp r2, #3
	bgt _080AC68E
	lsls r0, r2, #6
	adds r1, r4, r0
	mov ip, r1
	adds r1, #0x4c
	strh r5, [r1]
	adds r3, r4, #0
	adds r3, #0x40
	adds r3, r3, r0
	ldr r1, [r6]
	ldr r2, [r6, #4]
	str r1, [r3]
	str r2, [r3, #4]
	mov r1, ip
	adds r1, #0x54
	strh r7, [r1]
	adds r1, #2
	mov r2, r8
	strh r2, [r1]
	mov r2, ip
	adds r2, #0x4e
	movs r1, #1
	strh r1, [r2]
	adds r2, r4, #0
	adds r2, #0x18
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, #0x18
	adds r0, r4, r0
	bl FUN_080ac3d4
_080AC68E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
