	push {r4, r5, lr}
	ldr r2, _080AF550 @ =0x000006AC
	adds r1, r0, r2
	ldr r5, [r1]
	bl FUN_080af4f8
	adds r3, r0, #0
	cmp r3, #0
	bne _080AF558
	b _080AF59C
	.align 2, 0
_080AF550: .4byte 0x000006AC
_080AF554:
	adds r0, r3, #0
	b _080AF5A0
_080AF558:
	ldr r2, _080AF5A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF5AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF5B0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	adds r1, r3, #0
	bl Mod
	adds r2, r0, #0
	movs r3, #0
	ldrb r0, [r5, #0x1e]
	cmp r3, r0
	bge _080AF59C
	adds r4, r0, #0
	ldr r0, _080AF5B4 @ =0x00000BE8
	adds r1, r5, r0
_080AF584:
	ldr r0, [r1]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080AF594
	cmp r2, #0
	beq _080AF554
	subs r2, #1
_080AF594:
	adds r1, #4
	adds r3, #1
	cmp r3, r4
	blt _080AF584
_080AF59C:
	movs r0, #1
	rsbs r0, r0, #0
_080AF5A0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AF5A8: .4byte 0x030046B8
_080AF5AC: .4byte 0x000003FF
_080AF5B0: .4byte 0x0203B400
_080AF5B4: .4byte 0x00000BE8
