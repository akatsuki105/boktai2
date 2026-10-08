	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl EntityCC28_DrawHP
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl EntityCC28_DrawEne
	ldr r6, _08095D10 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08095D30
	ldr r1, _08095D14 @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _08095D18 @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r6, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08095D42
	ldr r1, _08095D1C @ =0x00000F41
	adds r0, r5, r1
	ldrb r6, [r0]
	cmp r6, #0
	bne _08095D42
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #1
	bls _08095D42
	ldr r0, _08095D20 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r0, _08095D24 @ =0x00000D98
	adds r2, r5, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r4, [r4]
	cmp r0, r4
	blt _08095CE0
	strb r6, [r2]
_08095CE0:
	ldr r0, _08095D28 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r5, r0
	ldr r2, _08095D2C @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080954a8
	adds r0, r5, #0
	bl FUN_0808de30
	b _08095D42
	.align 2, 0
_08095D10: .4byte 0x030044E0
_08095D14: .4byte 0x00001444
_08095D18: .4byte 0x00001E64
_08095D1C: .4byte 0x00000F41
_08095D20: .4byte 0x0000010B
_08095D24: .4byte 0x00000D98
_08095D28: .4byte 0x030046A0
_08095D2C: .4byte 0x00000D9C
_08095D30:
	adds r0, r5, #0
	movs r1, #0
	bl weapon_08095820
	ldr r1, _08095D48 @ =FUN_08095ae8
	adds r0, r5, #0
	movs r2, #0
	bl EntityCC28_SetState
_08095D42:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095D48: .4byte FUN_08095ae8
