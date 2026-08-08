	push {r4, lr}
	adds r2, r0, #0
	ldr r3, _08066804 @ =0x0000043A
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _080667FC
	ldr r4, _08066808 @ =0x00000446
	adds r0, r2, r4
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080667D6
	subs r4, #4
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #7
	bne _080667D6
	movs r3, #1
_080667D6:
	cmp r3, #0
	bne _080667FC
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r4, r2, r0
	adds r0, r1, #2
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _080667FC
	adds r0, r2, #0
	bl FUN_08066794
	ldrh r0, [r4]
	subs r0, #0x64
	strh r0, [r4]
_080667FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08066804: .4byte 0x0000043A
_08066808: .4byte 0x00000446
