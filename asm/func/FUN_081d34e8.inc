	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D3508 @ =0x03000194
	movs r3, #0
	movs r6, #1
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0xd0
	movs r4, #0xc6
	lsls r4, r4, #1
_081D34FC:
	ldrh r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _081D350C
	movs r0, #1
	b _081D350E
	.align 2, 0
_081D3508: .4byte 0x03000194
_081D350C:
	movs r0, #0
_081D350E:
	cmp r0, #0
	beq _081D3522
	movs r7, #0xab
	lsls r7, r7, #1
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r5
	bne _081D3522
	movs r0, #1
	b _081D352E
_081D3522:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, #0xb
	ble _081D34FC
	movs r0, #0
_081D352E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
