	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080EC90E
	cmp r0, #0x19
	bne _080EC91E
_080EC90E:
	movs r2, #1
	ldr r0, _080EC924 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080EC928 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
_080EC91E:
	pop {r0}
	bx r0
	.align 2, 0
_080EC924: .4byte 0x030046A0
_080EC928: .4byte 0x00000934
