	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, _0819BCC0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BCC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BCC6
	.align 2, 0
_0819BCC0: .4byte 0x0000046D
_0819BCC4:
	movs r0, #0
_0819BCC6:
	cmp r0, #0
	beq _0819BCD2
	ldr r0, _0819BD1C @ =0x00000CBB
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
_0819BCD2:
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r0, r2, r1
	adds r1, r3, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819BD16
	adds r0, r5, #0
	bl FUN_0819fca4
	ldr r4, _0819BD20 @ =FUN_0819cc04
	movs r3, #0x33
	ldr r0, _0819BD24 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819BD28 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0819BD16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819BD1C: .4byte 0x00000CBB
_0819BD20: .4byte FUN_0819cc04
_0819BD24: .4byte 0x0000046D
_0819BD28: .4byte 0x0000046B
