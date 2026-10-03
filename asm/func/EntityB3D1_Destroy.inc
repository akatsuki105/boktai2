	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x20
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0x6c
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0xb8
	bl AuxSprite_Remove
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r4, #4
_080C0576:
	adds r0, r5, #0
	bl MainSprite_Remove
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080C0576
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r4, #6
_080C058C:
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _080C058C
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r4, #5
_080C05A2:
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _080C05A2
	movs r0, #0
	ldr r1, _080C05C4 @ =0x03000158
	str r0, [r1]
	ldr r0, _080C05C8 @ =0x0000023E
	bl sound_08240740
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C05C4: .4byte 0x03000158
_080C05C8: .4byte 0x0000023E
