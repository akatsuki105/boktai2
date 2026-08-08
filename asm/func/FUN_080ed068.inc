	push {r4, r5, r6, lr}
	bl FUN_080ef840
	ldr r0, _080ED0AC @ =0x03002C60
	ldr r5, [r0]
	ldr r4, [r5, #4]
	cmp r4, #0
	beq _080ED0A6
	movs r6, #0x80
	lsls r6, r6, #5
_080ED07C:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080ED09E
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
_080ED09E:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	cmp r4, #0
	bne _080ED07C
_080ED0A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ED0AC: .4byte 0x03002C60
