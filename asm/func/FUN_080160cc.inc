	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	bl AuxSprite_Remove
	ldr r0, _0801610C @ =0x03002B44
	ldr r0, [r0]
	cmp r0, #0
	beq _080160E4
	adds r1, r4, #0
	bl FUN_080160b0
_080160E4:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080160F4
	bl Hitbox_Unregister
	ldr r0, [r4, #0x18]
	bl Free
_080160F4:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080160FE
	bl Free
_080160FE:
	adds r0, r4, #0
	bl Free
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801610C: .4byte 0x03002B44
