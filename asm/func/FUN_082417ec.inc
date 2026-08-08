	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08241850 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _082418B6
	ldr r0, _08241854 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0824182C
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0824182C
	adds r0, r4, #0
	bl FUN_08241774
	lsls r0, r0, #1
	cmp r0, #0xa
	ble _08241826
	movs r0, #0xa
_08241826:
	bl FUN_082417cc
	adds r4, r0, #0
_0824182C:
	ldr r0, _08241858 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0824185C
	adds r0, r4, #0
	bl FUN_08241774
	cmp r0, #1
	bgt _0824187A
	movs r0, #2
	bl FUN_082417dc
	b _08241878
	.align 2, 0
_08241850: .4byte 0x030047A4
_08241854: .4byte 0x03002BE0
_08241858: .4byte 0x030046A0
_0824185C:
	ldr r2, _082418A0 @ =0x000002B2
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0824187A
	adds r0, r4, #0
	bl FUN_08241774
	cmp r0, #2
	ble _0824187A
	movs r0, #2
	bl FUN_082417cc
_08241878:
	adds r4, r0, #0
_0824187A:
	ldr r0, _082418A4 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _08241886
	movs r1, #1
_08241886:
	cmp r1, #0
	beq _082418A8
	adds r0, r4, #0
	bl FUN_08241774
	adds r0, #4
	cmp r0, #0xa
	ble _08241898
	movs r0, #0xa
_08241898:
	bl FUN_082417cc
	adds r4, r0, #0
	b _082418B6
	.align 2, 0
_082418A0: .4byte 0x000002B2
_082418A4: .4byte 0x03002B80
_082418A8:
	movs r1, #0
	cmp r0, #2
	bne _082418B0
	movs r1, #1
_082418B0:
	cmp r1, #0
	beq _082418B6
	movs r4, #0
_082418B6:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
