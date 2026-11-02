	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x88
	adds r4, r0, #0
	adds r4, #0x1c
	movs r6, #0x2f
_081EE754:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _081EE762
	adds r0, r4, #0
	bl AuxSprite_Remove
_081EE762:
	adds r5, #0x70
	adds r4, #0x70
	subs r6, #1
	cmp r6, #0
	bge _081EE754
	movs r1, #0
	ldr r0, _081EE77C @ =0x030001D0
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EE77C: .4byte 0x030001D0
