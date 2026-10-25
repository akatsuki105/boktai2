	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080ca4dc
	adds r2, r4, #0
	adds r2, #0x98
	ldrh r1, [r2]
	str r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CA6C8
	movs r0, #0x80
	lsls r0, r0, #9
	orrs r1, r0
	str r1, [r2]
	ldr r0, _080CA74C @ =0x0000029E
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080CA6C8:
	ldr r1, _080CA750 @ =0x0000191C
	adds r5, r4, r1
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080CA6E0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x10
	bl FUN_080c4a40
_080CA6E0:
	ldrh r1, [r5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080CA6F4
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0x10
	bl FUN_080c4a40
_080CA6F4:
	ldr r2, _080CA754 @ =0x000025E4
	adds r5, r4, r2
	ldrh r1, [r5]
	cmp r1, #0
	beq _080CA728
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080CA722
	ldr r3, _080CA758 @ =0x000025D8
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _080CA75C @ =0x000025DC
	adds r2, r4, r0
	subs r3, #3
	adds r0, r4, r3
	ldrb r3, [r0]
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
	adds r0, r4, #0
	bl FUN_080c3db4
_080CA722:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
_080CA728:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x50]
	str r1, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0x54
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CA74C: .4byte 0x0000029E
_080CA750: .4byte 0x0000191C
_080CA754: .4byte 0x000025E4
_080CA758: .4byte 0x000025D8
_080CA75C: .4byte 0x000025DC
