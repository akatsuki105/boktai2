	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x1e]
	cmp r1, #2
	bhi _0800286C
	ldrh r1, [r4, #0x24]
	cmp r1, #2
	beq _0800285E
	cmp r1, #2
	bgt _08002846
	cmp r1, #1
	beq _08002850
	b _08002898
_08002846:
	cmp r1, #3
	beq _08002850
	cmp r1, #4
	beq _0800285E
	b _08002898
_08002850:
	ldrh r1, [r4, #0x24]
	cmp r1, #1
	beq _08002858
	movs r1, #3
_08002858:
	strh r1, [r4, #0x1e]
	movs r1, #0
	b _0800287A
_0800285E:
	ldrh r1, [r4, #0x24]
	cmp r1, #2
	beq _08002866
	movs r1, #4
_08002866:
	strh r1, [r4, #0x1e]
	movs r1, #0
	b _0800287A
_0800286C:
	ldrh r2, [r4, #0x24]
	cmp r2, #3
	beq _08002876
	cmp r2, #4
	bne _08002898
_08002876:
	movs r1, #0
	strh r2, [r4, #0x1e]
_0800287A:
	strh r1, [r4, #0x20]
	ldrh r1, [r4, #0x26]
	strh r1, [r4, #0x22]
	ldr r3, _080028A8 @ =0x03004464
	ldrh r2, [r4, #0x2a]
	lsls r2, r2, #5
	ldrh r1, [r4, #0x28]
	orrs r2, r1
	ldrh r1, [r4, #0x2c]
	lsls r1, r1, #0xa
	orrs r2, r1
	strh r2, [r3]
	ldr r2, _080028AC @ =0x03004490
	ldrh r1, [r4, #0x2e]
	strh r1, [r2]
_08002898:
	ldrh r1, [r4, #0x1e]
	cmp r1, #2
	beq _080028C2
	cmp r1, #2
	bgt _080028B0
	cmp r1, #1
	beq _080028BA
	b _080028C8
	.align 2, 0
_080028A8: .4byte 0x03004464
_080028AC: .4byte 0x03004490
_080028B0:
	cmp r1, #3
	beq _080028BA
	cmp r1, #4
	beq _080028C2
	b _080028C8
_080028BA:
	adds r0, r4, #0
	bl FUN_08002788
	b _080028C8
_080028C2:
	adds r0, r4, #0
	bl FUN_08002744
_080028C8:
	movs r1, #0
	strh r1, [r4, #0x24]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
