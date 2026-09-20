	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	bne _0821B082
	adds r0, r4, #0
	adds r0, #0x38
	bl MainSprite_Remove
	b _0821B08A
_0821B082:
	adds r0, r4, #0
	adds r0, #0x98
	bl AuxSprite_Remove
_0821B08A:
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl AuxSprite_Remove
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
