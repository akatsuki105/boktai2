	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _080526E8
	movs r0, #0
	strb r0, [r5, #0x1d]
_080526E8:
	ldr r0, _08052728 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _0805272C @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _080526F8
	movs r0, #0x80
	str r0, [r5, #0x18]
_080526F8:
	ldr r1, [r5, #0x18]
	cmp r1, #0x40
	bhi _08052738
	movs r2, #0x28
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	lsrs r4, r0, #6
	ldr r0, _08052730 @ =0x0000270F
	cmp r4, r0
	bls _0805270E
	adds r4, r0, #0
_0805270E:
	cmp r4, #0
	beq _0805273C
	adds r0, r1, #0
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _0805273C
	ldr r0, _08052734 @ =0x000002A5
	bl PlaySound_082406e0
	b _0805273C
	.align 2, 0
_08052728: .4byte 0x030044E0
_0805272C: .4byte 0x0000030F
_08052730: .4byte 0x0000270F
_08052734: .4byte 0x000002A5
_08052738:
	movs r0, #0x28
	ldrsh r4, [r5, r0]
_0805273C:
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r3, r5, r2
	adds r2, r4, #0
	ldr r0, _08052750 @ =0x0000270F
	cmp r2, r0
	ble _08052754
	adds r2, r0, #0
	b _0805275A
	.align 2, 0
_08052750: .4byte 0x0000270F
_08052754:
	cmp r2, #0
	bge _0805275A
	movs r2, #0
_0805275A:
	adds r1, r5, #0
	adds r1, #0x30
	movs r4, #0
	str r4, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x60
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r0, r3, #0
	movs r3, #4
	bl FUN_082376a4
	ldr r0, [r5, #0x18]
	cmp r0, #0x7f
	bls _0805278A
	movs r0, #4
	strb r0, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r4, [r5, #0x18]
	b _0805278E
_0805278A:
	adds r0, #1
	str r0, [r5, #0x18]
_0805278E:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
