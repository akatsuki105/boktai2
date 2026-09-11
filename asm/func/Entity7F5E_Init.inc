	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b4414
	adds r0, r4, #0
	bl FUN_080b4454
	adds r0, r4, #0
	bl FUN_080b4490
	adds r0, r4, #0
	bl FUN_080b4740
	movs r0, #0x65
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080B47C0
	bl Script_GetValue
	ldr r2, _080B47BC @ =0x000005DC
	adds r1, r4, r2
	str r0, [r1]
	b _080B47C6
	.align 2, 0
_080B47BC: .4byte 0x000005DC
_080B47C0:
	ldr r2, _080B47D4 @ =0x000005DC
	adds r0, r4, r2
	str r1, [r0]
_080B47C6:
	adds r0, r4, #0
	bl FUN_080b3b74
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B47D4: .4byte 0x000005DC
