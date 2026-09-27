	push {r4, r5, r6, r7, lr}
	ldr r0, _081D5180 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D51D4
	adds r4, r0, #0
	ldr r0, _081D5184 @ =0x000012AC
	adds r5, r4, r0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D51D4
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D5190
	b _081D51D4
	.align 2, 0
_081D5180: .4byte 0x03000194
_081D5184: .4byte 0x000012AC
_081D5188:
	adds r0, r4, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	b _081D51D8
_081D5190:
	movs r3, #0
	ldr r6, [r5]
	movs r7, #0x10
	adds r2, r4, #0
	adds r2, #0xd0
	adds r1, r4, #0
	adds r1, #0x1c
	movs r5, #0xc6
	lsls r5, r5, #1
_081D51A2:
	movs r0, #1
	lsls r0, r3
	ands r0, r6
	cmp r0, #0
	beq _081D51B0
	movs r0, #1
	b _081D51B2
_081D51B0:
	movs r0, #0
_081D51B2:
	cmp r0, #0
	beq _081D51CA
	adds r4, r1, #0
	ldrh r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _081D51C4
	movs r0, #1
	b _081D51C6
_081D51C4:
	movs r0, #0
_081D51C6:
	cmp r0, #0
	bne _081D5188
_081D51CA:
	adds r2, r2, r5
	adds r1, r1, r5
	adds r3, #1
	cmp r3, #0xb
	ble _081D51A2
_081D51D4:
	movs r0, #1
	rsbs r0, r0, #0
_081D51D8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
