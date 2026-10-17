	push {r4, r5, lr}
	adds r5, r0, #0
	bl MapItemManager_Ensure
	adds r1, r0, #0
	cmp r1, #0
	bne _08007784
	movs r0, #1
	rsbs r0, r0, #0
	b _080077A2
_08007784:
	ldr r2, [r1, #0x28]
	cmp r2, #0
	beq _080077A2
_0800778A:
	adds r1, r2, #0
	adds r1, #0xb8
	ldr r4, [r1]
	ldrb r1, [r2, #5]
	cmp r1, r5
	bne _0800779C
	adds r0, r2, #0
	bl MapItem_Free
_0800779C:
	adds r2, r4, #0
	cmp r2, #0
	bne _0800778A
_080077A2:
	pop {r4, r5}
	pop {r1}
	bx r1
