	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08241B38 @ =0x03002BE0
	ldr r3, [r0]
	adds r6, r0, #0
	cmp r3, #0
	bne _08241AD0
	b _08241CD0
_08241AD0:
	ldr r0, _08241B3C @ =0x030047A4
	ldr r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	beq _08241AE0
	b _08241CD0
_08241AE0:
	movs r2, #0x80
	lsls r2, r2, #2
	ands r2, r1
	cmp r2, #0
	bne _08241AF0
	ldr r0, [r3, #0x1c]
	cmp r0, #2
	bne _08241B64
_08241AF0:
	ldr r7, _08241B40 @ =0x030046A0
	ldr r0, [r7]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r3, r0, r6
	ldr r2, [r3]
	ldr r5, _08241B44 @ =0x0000752F
	cmp r2, r5
	bgt _08241B4C
	movs r1, #0x94
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08241B12
	b _08241CCA
_08241B12:
	ldrh r1, [r4, #0x24]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _08241B1E
	b _08241CCA
_08241B1E:
	ldrh r0, [r4, #0x1e]
	adds r0, r2, r0
	str r0, [r3]
	cmp r0, r5
	bgt _08241B2A
	b _08241CCA
_08241B2A:
	ldr r0, [r7]
	adds r0, r0, r6
	ldr r1, _08241B48 @ =0x00007530
	str r1, [r0]
	bl SetOverheatTime
	b _08241CCA
	.align 2, 0
_08241B38: .4byte 0x03002BE0
_08241B3C: .4byte 0x030047A4
_08241B40: .4byte 0x030046A0
_08241B44: .4byte 0x0000752F
_08241B48: .4byte 0x00007530
_08241B4C:
	ldr r2, _08241B60 @ =0x00000942
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #2
	bgt _08241B5A
	b _08241CCA
_08241B5A:
	bl SetOverheatTime
	b _08241CCA
	.align 2, 0
_08241B60: .4byte 0x00000942
_08241B64:
	ldr r0, _08241B70 @ =0x030044E0
	ldrh r0, [r0]
	cmp r0, #0
	beq _08241B74
	strh r2, [r4, #0x26]
	b _08241B80
	.align 2, 0
_08241B70: .4byte 0x030044E0
_08241B74:
	ldrh r1, [r4, #0x26]
	ldr r0, _08241C04 @ =0x00000383
	cmp r1, r0
	bhi _08241B80
	adds r0, r1, #1
	strh r0, [r4, #0x26]
_08241B80:
	ldr r0, _08241C08 @ =0x030046A0
	ldr r3, [r0]
	movs r7, #0x94
	lsls r7, r7, #4
	adds r1, r3, r7
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r5, r0, #0
	cmp r1, #0
	bgt _08241B96
	b _08241CC4
_08241B96:
	ldrh r1, [r4, #0x24]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _08241BA2
	b _08241CC4
_08241BA2:
	ldrh r1, [r4, #0x26]
	ldr r0, _08241C04 @ =0x00000383
	cmp r1, r0
	bhi _08241C9C
	movs r7, #0xec
	lsls r7, r7, #1
	adds r1, r3, r7
	ldr r2, [r1]
	ldr r0, _08241C0C @ =0x7FFFFFFE
	cmp r2, r0
	bgt _08241BCA
	ldr r7, _08241C10 @ =0x00000942
	adds r0, r3, r7
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r2, r0
	cmp r0, #0
	bge _08241BC8
	ldr r0, _08241C14 @ =0x7FFFFFFF
_08241BC8:
	str r0, [r1]
_08241BCA:
	ldr r2, [r5]
	movs r7, #0xef
	lsls r7, r7, #2
	adds r0, r2, r7
	ldr r1, [r0]
	ldr r0, _08241C18 @ =0x0000270E
	cmp r1, r0
	bgt _08241C52
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08241C1C
	ldr r6, _08241C10 @ =0x00000942
	adds r0, r2, r6
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r0, #5
	lsls r0, r0, #1
	ldrh r7, [r4, #0x28]
	adds r0, r0, r7
	b _08241C2C
	.align 2, 0
_08241C04: .4byte 0x00000383
_08241C08: .4byte 0x030046A0
_08241C0C: .4byte 0x7FFFFFFE
_08241C10: .4byte 0x00000942
_08241C14: .4byte 0x7FFFFFFF
_08241C18: .4byte 0x0000270E
_08241C1C:
	ldr r1, _08241CD8 @ =0x00000942
	adds r0, r2, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r0, #5
	ldrh r2, [r4, #0x28]
	adds r0, r0, r2
_08241C2C:
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x28]
	lsrs r2, r0, #4
	lsls r1, r2, #4
	subs r0, r0, r1
	strh r0, [r4, #0x28]
	ldr r0, [r5]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, [r0]
	adds r1, r1, r2
	str r1, [r0]
	ldr r2, _08241CDC @ =0x0000270F
	cmp r1, r2
	ble _08241C52
	ldr r0, [r5]
	adds r0, r0, r3
	str r2, [r0]
_08241C52:
	ldr r3, [r5]
	movs r6, #0xf0
	lsls r6, r6, #1
	adds r1, r3, r6
	ldr r2, [r1]
	ldr r0, _08241CE0 @ =0x7FFFFFFE
	cmp r2, r0
	bgt _08241C82
	ldr r7, _08241CD8 @ =0x00000942
	adds r0, r3, r7
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r2, r0
	cmp r0, #0
	bge _08241C72
	ldr r0, _08241CE4 @ =0x7FFFFFFF
_08241C72:
	str r0, [r1]
	ldr r1, [r5]
	movs r6, #0xf2
	lsls r6, r6, #1
	adds r1, r1, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08241C82:
	ldrh r1, [r4, #0x24]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0
	bne _08241C9C
	ldr r0, _08241CE8 @ =0x030046A0
	ldr r0, [r0]
	ldr r7, _08241CD8 @ =0x00000942
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl RotItem
_08241C9C:
	ldr r6, _08241CE8 @ =0x030046A0
	ldr r0, [r6]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r2, r0, r5
	ldr r1, [r2]
	ldr r3, _08241CEC @ =0x0000752F
	cmp r1, r3
	bgt _08241CC4
	ldrh r0, [r4, #0x1e]
	adds r0, r1, r0
	str r0, [r2]
	cmp r0, r3
	ble _08241CC4
	ldr r0, [r6]
	adds r0, r0, r5
	ldr r1, _08241CF0 @ =0x00007530
	str r1, [r0]
	bl SetOverheatTime
_08241CC4:
	adds r0, r4, #0
	bl overheat_08241a04
_08241CCA:
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x24]
_08241CD0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08241CD8: .4byte 0x00000942
_08241CDC: .4byte 0x0000270F
_08241CE0: .4byte 0x7FFFFFFE
_08241CE4: .4byte 0x7FFFFFFF
_08241CE8: .4byte 0x030046A0
_08241CEC: .4byte 0x0000752F
_08241CF0: .4byte 0x00007530
