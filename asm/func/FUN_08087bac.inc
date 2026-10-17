	push {lr}
	adds r2, r0, #0
	ldr r0, _08087BF0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08087BFE
	ldr r1, _08087BF4 @ =0x000003A2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08087BFE
	adds r1, #0x12
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08087BFE
	subs r1, #0x30
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087BFE
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08087BF8
	subs r0, #1
	strh r0, [r1]
	b _08087BFE
	.align 2, 0
_08087BF0: .4byte 0x030047A4
_08087BF4: .4byte 0x000003A2
_08087BF8:
	adds r0, r2, #0
	bl FUN_080860cc
_08087BFE:
	pop {r0}
	bx r0
	.align 2, 0
