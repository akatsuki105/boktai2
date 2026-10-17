	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ceba8
	adds r2, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r4, r4, r0
	ldrh r3, [r4]
	cmp r3, r2
	bge _080CEC4C
	ldr r0, _080CEC48 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _080CEC42
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, [r1]
	adds r0, r0, r3
	str r0, [r1]
_080CEC42:
	movs r0, #0
	b _080CEC64
	.align 2, 0
_080CEC48: .4byte 0x03002C68
_080CEC4C:
	ldr r0, _080CEC6C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _080CEC60
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_080CEC60:
	ldrh r0, [r4]
	subs r0, r0, r2
_080CEC64:
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CEC6C: .4byte 0x03002C68
