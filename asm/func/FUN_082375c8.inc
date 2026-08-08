	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	cmp r5, r3
	bgt _082375DC
	movs r0, #0
	cmp r5, r2
	ble _082375DC
	movs r0, #1
_082375DC:
	ldr r1, _08237604 @ =0x085B0A00
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	cmp r0, #0
	bne _0823760C
	ldr r1, [r4]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08237608
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _0823760A
	.align 2, 0
_08237604: .4byte 0x085B0A00
_08237608:
	orrs r1, r2
_0823760A:
	str r1, [r4]
_0823760C:
	cmp r5, #0x3c
	bgt _08237614
	movs r0, #0
	b _0823761E
_08237614:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_0823761E:
	pop {r4, r5}
	pop {r1}
	bx r1
