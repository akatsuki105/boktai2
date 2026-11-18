	push {lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081C2394 @ =0x0000065C
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C2398
	movs r0, #1
	b _081C239A
	.align 2, 0
_081C2394: .4byte 0x0000065C
_081C2398:
	movs r0, #0
_081C239A:
	cmp r0, #0
	bne _081C23EC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C23EC
	adds r1, #0x58
	adds r0, r3, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C23DA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C23C2
	adds r2, r0, #0
_081C23C2:
	cmp r2, #0
	blt _081C23DA
	ldr r1, _081C23F0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C23EC
_081C23DA:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _081C23EC
	adds r0, r3, #0
	bl GolemLink_TargetPlayerTile
_081C23EC:
	pop {r0}
	bx r0
	.align 2, 0
_081C23F0: .4byte 0x03002BE0
