	push {lr}
	adds r3, r0, #0
	movs r0, #0x88
	lsls r0, r0, #2
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _080FA794
	subs r0, #1
	strh r0, [r2]
	b _080FA79A
_080FA794:
	ldr r2, _080FA7A0 @ =0x0000021E
	adds r0, r3, r2
	strh r1, [r0]
_080FA79A:
	pop {r0}
	bx r0
	.align 2, 0
_080FA7A0: .4byte 0x0000021E
