	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	movs r6, #0
	movs r5, #0
	ldrh r1, [r4, #0x1a]
	cmp r6, r1
	bge _081DF5C0
	movs r7, #0xf0
	lsls r7, r7, #6
_081DF57E:
	cmp r5, #0
	bge _081DF58C
	ldr r1, _081DF588 @ =0x0000FFFF
	b _081DF594
	.align 2, 0
_081DF588: .4byte 0x0000FFFF
_081DF58C:
	ldr r2, [r4, #0x44]
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF594:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	ands r1, r7
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF5A8
	movs r1, #1
	b _081DF5AA
_081DF5A8:
	movs r1, #0
_081DF5AA:
	cmp r1, #0
	beq _081DF5B8
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #2
	bne _081DF5B8
	adds r6, #1
_081DF5B8:
	adds r5, #1
	ldrh r1, [r4, #0x1a]
	cmp r5, r1
	blt _081DF57E
_081DF5C0:
	ldrh r1, [r4, #0x1a]
	cmp r6, r1
	bne _081DF5D8
	ldr r2, _081DF5D4 @ =FUN_081df604
	adds r0, r4, #0
	movs r1, #0x18
	bl Entity9A9F_SetState
	b _081DF5F2
	.align 2, 0
_081DF5D4: .4byte FUN_081df604
_081DF5D8:
	ldr r1, [r4, #0x4c]
	adds r1, #2
	cmp r1, #1
	bls _081DF5E6
	ldr r1, [r4, #0x34]
	cmp r1, #0xb3
	bls _081DF5F2
_081DF5E6:
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF5FA
_081DF5F2:
	ldr r2, _081DF600 @ =0x00001002
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF5FA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF600: .4byte 0x00001002
