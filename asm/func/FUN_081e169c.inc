	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081E16AE
	movs r0, #0
	strb r0, [r4, #4]
	movs r0, #1
	b _081E16B0
_081E16AE:
	movs r0, #0
_081E16B0:
	cmp r0, #0
	beq _081E16DE
	movs r0, #0
	strb r0, [r4, #1]
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldr r0, _081E16CC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081E16D0
	movs r0, #1
	rsbs r0, r0, #0
	b _081E16D4
	.align 2, 0
_081E16CC: .4byte 0x03002C68
_081E16D0:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_081E16D4:
	cmp r1, r0
	bne _081E16DE
	ldr r0, _081E1730 @ =0x00000275
	bl PlaySound_082406e0
_081E16DE:
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r4, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	blt _081E170C
	strb r2, [r4, #2]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E1700
	strb r2, [r4, #3]
_081E1700:
	ldrb r1, [r4, #3]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _081E170A
	adds r1, #4
_081E170A:
	strh r1, [r4, #0x34]
_081E170C:
	adds r1, r4, #0
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, #0x18
	strh r0, [r1]
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _081E172A
	adds r0, r4, #0
	bl FUN_081e127c
_081E172A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1730: .4byte 0x00000275
