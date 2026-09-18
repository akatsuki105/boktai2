	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
_081D0D8A:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7, #0x68]
	ands r0, r1
	cmp r0, #0
	beq _081D0D9A
	movs r0, #1
	b _081D0D9C
_081D0D9A:
	movs r0, #0
_081D0D9C:
	cmp r0, #0
	beq _081D0DD4
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x38
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081D0DCE
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_081D0DCE:
	adds r0, r5, #0
	bl Free
_081D0DD4:
	adds r6, #1
	cmp r6, #0xb
	ble _081D0D8A
	ldr r1, _081D0DE8 @ =0x03000188
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D0DE8: .4byte 0x03000188
