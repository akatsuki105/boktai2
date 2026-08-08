	push {r4, r5, lr}
	bl FUN_082410e8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0823AE04
	ldr r5, _0823AE0C @ =gUnkPtr_030047a8
	ldr r0, [r5]
	cmp r0, #0
	beq _0823ADEC
	movs r1, #0x28
	bl ClearMemory
_0823ADEC:
	movs r1, #5
	ldr r0, _0823AE10 @ =0x030046A0
	ldr r0, [r0]
	strh r1, [r0, #0x12]
	movs r1, #0xe6
	ldr r0, [r5]
	str r1, [r0, #4]
	strb r4, [r0, #8]
	ldr r0, [r5]
	strb r4, [r0, #9]
	ldr r0, [r5]
	strb r4, [r0, #0xa]
_0823AE04:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823AE0C: .4byte gUnkPtr_030047a8
_0823AE10: .4byte 0x030046A0
