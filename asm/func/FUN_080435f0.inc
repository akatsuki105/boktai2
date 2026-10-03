	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043604
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #4
	strb r0, [r4, #5]
_08043604:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08043640
	ldr r1, _08043624 @ =0x00000217
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _0804362C
	ldr r1, _08043628 @ =0x00000227
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r0, #1
	b _08043632
	.align 2, 0
_08043624: .4byte 0x00000217
_08043628: .4byte 0x00000227
_0804362C:
	movs r0, #1
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
_08043632:
	strb r0, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl EntityMsgBox_EndWait
_08043640:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
