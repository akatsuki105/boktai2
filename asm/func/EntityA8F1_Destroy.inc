	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0x50
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0xa0
	bl AuxSprite_Remove
	adds r4, r6, #0
	adds r4, #0xe8
	movs r5, #2
_080A3530:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A3530
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080A354A:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A354A
	adds r0, r7, #0
	bl MsgQueue_Unregister
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
