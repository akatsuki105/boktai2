	push {lr}
	ldr r0, _080A04FC @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A04DE
	ldr r0, _080A0500 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A04DE
	movs r1, #1
_080A04DE:
	cmp r1, #0
	bne _080A04F6
	ldr r0, _080A0504 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04F6
	cmp r0, #3
	bne _080A0508
_080A04F6:
	movs r0, #1
	b _080A050A
	.align 2, 0
_080A04FC: .4byte 0x03002B8C
_080A0500: .4byte 0x03002B60
_080A0504: .4byte 0x03002BE0
_080A0508:
	movs r0, #0
_080A050A:
	pop {r1}
	bx r1
	.align 2, 0
