	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _081DA82C @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA84A
	cmp r0, #1
	bgt _081DA830
	cmp r0, #0
	beq _081DA836
	b _081DA870
	.align 2, 0
_081DA82C: .4byte 0x00000286
_081DA830:
	cmp r0, #2
	beq _081DA858
	b _081DA870
_081DA836:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r4, #0xa4
	lsls r4, r4, #2
	adds r0, r3, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	b _081DA872
_081DA84A:
	ldr r1, _081DA854 @ =0x085AE160
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	b _081DA860
	.align 2, 0
_081DA854: .4byte 0x085AE160
_081DA858:
	ldr r1, _081DA86C @ =0x085AE168
	movs r4, #0xa2
	lsls r4, r4, #2
	adds r0, r3, r4
_081DA860:
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	b _081DA872
	.align 2, 0
_081DA86C: .4byte 0x085AE168
_081DA870:
	movs r2, #0
_081DA872:
	adds r2, #0xb6
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r4, #0x88
	lsls r4, r4, #2
	adds r1, r3, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
