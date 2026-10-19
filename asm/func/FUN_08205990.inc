	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x20
	bl FUN_080412fc
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _082059B0
	ldrb r0, [r5, #6]
	cmp r0, #0x10
	bhi _082059B0
	ldr r0, _082059B8 @ =0x00000402
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
_082059B0:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082059B8: .4byte 0x00000402
