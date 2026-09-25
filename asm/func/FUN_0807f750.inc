	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldrh r0, [r2, #0x34]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r2, #0x38]
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _0807F786
	adds r0, r3, #0
	adds r0, #0xf4
	ldr r1, [r0]
	adds r0, r2, #0
	movs r2, #5
	bl FUN_0822dafc
_0807F786:
	pop {r0}
	bx r0
	.align 2, 0
