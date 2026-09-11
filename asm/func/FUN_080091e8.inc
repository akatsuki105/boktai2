	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x50
	ldr r1, _0800921C @ =0x0000A850
	adds r0, r6, #0
	bl Video_GetActorSprite
	cmp r0, #0
	beq _08009220
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #1
	strh r0, [r4, #0x10]
	adds r1, r5, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	movs r0, #0
	b _08009224
	.align 2, 0
_0800921C: .4byte 0x0000A850
_08009220:
	movs r0, #1
	rsbs r0, r0, #0
_08009224:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
