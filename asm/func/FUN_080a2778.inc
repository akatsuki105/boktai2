	push {r4, lr}
	adds r4, r0, #0
	bl Coffin_GetPos
	adds r3, r0, #0
	cmp r3, #0
	beq _080A27FC
	ldr r0, _080A27F0 @ =0x03002C00
	ldr r1, [r0]
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _080A27FC
	ldr r2, _080A27F4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080A27FC
	movs r0, #2
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080A27AE
	rsbs r1, r1, #0
_080A27AE:
	cmp r1, #0xff
	bgt _080A27FC
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r0, #4
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9c
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	movs r0, #0xbe
	lsls r0, r0, #1
	cmp r2, r0
	bgt _080A27FC
	cmp r1, r0
	bgt _080A27FC
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r1, _080A27F8 @ =0x00023410
	cmp r0, r1
	bgt _080A27FC
	movs r0, #1
	b _080A27FE
	.align 2, 0
_080A27F0: .4byte 0x03002C00
_080A27F4: .4byte 0x000001F5
_080A27F8: .4byte 0x00023410
_080A27FC:
	movs r0, #0
_080A27FE:
	pop {r4}
	pop {r1}
	bx r1
