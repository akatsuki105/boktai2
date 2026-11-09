	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08132D4C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132D50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08132D52
	.align 2, 0
_08132D4C: .4byte 0x0000046D
_08132D50:
	movs r0, #0
_08132D52:
	cmp r0, #0
	beq _08132D74
	adds r0, r5, #0
	movs r1, #8
	bl Enemy_PlayAnim
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08132D74
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_08132D74:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _08132D90
	ldr r2, _08132DDC @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl Enemy_SetEmote
_08132D90:
	ldr r1, _08132DE0 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08132DD6
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _08132DD6
	ldr r3, _08132DE4 @ =FUN_08132df0
	movs r2, #6
	ldr r0, _08132DE8 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08132DEC @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_08132DD6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08132DDC: .4byte 0x000001DF
_08132DE0: .4byte 0x00000466
_08132DE4: .4byte FUN_08132df0
_08132DE8: .4byte 0x0000046D
_08132DEC: .4byte 0x0000046B
