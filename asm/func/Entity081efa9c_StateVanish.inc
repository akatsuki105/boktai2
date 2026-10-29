	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r2, r5, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EF604
	movs r1, #0
	strb r1, [r2]
	adds r0, r5, #0
	adds r0, #0xb8
	strh r1, [r0]
_081EF604:
	adds r4, r5, #0
	adds r4, #0xb8
	ldrh r1, [r4]
	adds r0, r5, #0
	movs r2, #0x3c
	movs r3, #0x28
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081EF65C
	ldr r0, _081EF654 @ =0x030001DC
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0xbd
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _081EF658 @ =0x00000838
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xba
	strh r4, [r0]
	adds r0, #0xc
	strh r4, [r0]
	b _081EF662
	.align 2, 0
_081EF654: .4byte 0x030001DC
_081EF658: .4byte 0x00000838
_081EF65C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081EF662:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
