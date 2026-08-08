	push {lr}
	adds r2, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r3, r1, #0
	ldrh r0, [r2, #0xc]
	cmp r0, r1
	beq _082370BC
	ldrb r0, [r2, #6]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r2, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _082370BA
	movs r0, #1
	strb r0, [r2, #7]
_082370BA:
	strh r3, [r2, #0xc]
_082370BC:
	pop {r0}
	bx r0
  .align 2, 0
