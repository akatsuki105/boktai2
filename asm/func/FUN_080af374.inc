	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _080AF3A2
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r2, r4, r1
	adds r1, #0x58
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080AF3E0 @ =0x0000061A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_080AF3A2:
	cmp r5, #2
	bne _080AF3C2
	ldrh r0, [r3]
	cmp r0, #2
	beq _080AF3C2
	ldr r1, _080AF3E4 @ =0x000006AC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080adf50
	ldr r0, _080AF3E8 @ =0x03002C58
	ldr r0, [r0]
	ldr r3, _080AF3EC @ =0x0000133E
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
_080AF3C2:
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r2, r4, r0
	movs r1, #0
	strh r5, [r2]
	ldr r3, _080AF3F0 @ =0x0000067A
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0
	bne _080AF3F4
	adds r0, r4, #0
	bl FUN_080af2f4
	b _080AF3FA
	.align 2, 0
_080AF3E0: .4byte 0x0000061A
_080AF3E4: .4byte 0x000006AC
_080AF3E8: .4byte 0x03002C58
_080AF3EC: .4byte 0x0000133E
_080AF3F0: .4byte 0x0000067A
_080AF3F4:
	adds r0, r4, #0
	bl FUN_080af334
_080AF3FA:
	pop {r4, r5}
	pop {r0}
	bx r0
