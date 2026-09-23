	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _080191B2
	adds r0, r5, #0
	bl BgPlttBlender_SavePltt
_080191B2:
	movs r6, #0
	ldr r0, [r5, #0x18]
	cmp r6, r0
	bhs _080191D2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r4, r5, r0
_080191C0:
	adds r0, r5, #0
	adds r1, r4, #0
	bl BgPlttBlender_UpdateSlot
	adds r4, #0x14
	adds r6, #1
	ldr r0, [r5, #0x18]
	cmp r6, r0
	blo _080191C0
_080191D2:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
