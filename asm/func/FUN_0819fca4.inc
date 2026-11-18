	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r1, _0819FCE4 @ =0x00000A64
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819FCDE
	ldr r0, _0819FCE8 @ =0x00000BA8
	adds r4, r6, r0
	movs r5, #2
_0819FCBE:
	adds r0, r4, #0
	bl Hitbox_Unregister
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0819FCBE
	ldr r1, _0819FCEC @ =0x00000CBC
	adds r0, r6, r1
	bl ParticleShadow_Remove
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r0, r6, r1
	bl AuxSprite_Remove
_0819FCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819FCE4: .4byte 0x00000A64
_0819FCE8: .4byte 0x00000BA8
_0819FCEC: .4byte 0x00000CBC
