	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819F3F8 @ =0x0000073C
	adds r4, r0, r1
	movs r5, #3
_0819F3DC:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0819F3E8
	adds r0, r4, #0
	bl AuxSprite_Remove
_0819F3E8:
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0819F3DC
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819F3F8: .4byte 0x0000073C
