	push {lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r3, _081B8DB0 @ =0x0000065C
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B8DB4
	movs r0, #1
	b _081B8DB6
	.align 2, 0
_081B8DB0: .4byte 0x0000065C
_081B8DB4:
	movs r0, #0
_081B8DB6:
	cmp r0, #0
	bne _081B8DEA
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B8DEA
	ldr r0, _081B8DF0 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B8DEA
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081B8DEA
	adds r0, r2, #0
	bl GolemLink_TargetPlayerTile
_081B8DEA:
	pop {r0}
	bx r0
	.align 2, 0
_081B8DF0: .4byte 0x03002BE0
