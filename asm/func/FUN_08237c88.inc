	push {r4, r5, r6, lr}
	ldr r0, _08237CCC @ =0x04000120
	ldrh r0, [r0]
	adds r3, r0, #0
	ldr r0, _08237CD0 @ =0x04000124
	ldrh r0, [r0]
	adds r2, r0, #0
	ldr r0, _08237CD4 @ =0x04000126
	ldrh r0, [r0]
	adds r4, r0, #0
	movs r5, #0
	ldr r0, _08237CD8 @ =0x030046D0
	strh r3, [r0]
	ldr r0, _08237CDC @ =0x04000128
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08237CB8
	ldr r0, _08237CE0 @ =0x0000FFFF
	cmp r2, r0
	bne _08237CC2
	cmp r4, r2
	beq _08237CF4
_08237CB8:
	ldr r0, _08237CE0 @ =0x0000FFFF
	cmp r2, r0
	bne _08237CC2
	cmp r4, r2
	beq _08237CE8
_08237CC2:
	ldr r1, _08237CE4 @ =0x030046D4
	movs r0, #7
	rsbs r0, r0, #0
	b _08237D8A
	.align 2, 0
_08237CCC: .4byte 0x04000120
_08237CD0: .4byte 0x04000124
_08237CD4: .4byte 0x04000126
_08237CD8: .4byte 0x030046D0
_08237CDC: .4byte 0x04000128
_08237CE0: .4byte 0x0000FFFF
_08237CE4: .4byte 0x030046D4
_08237CE8:
	ldr r1, _08237CF0 @ =0x030046D4
	movs r0, #8
	rsbs r0, r0, #0
	b _08237D8A
	.align 2, 0
_08237CF0: .4byte 0x030046D4
_08237CF4:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r3
	ldr r6, _08237D9C @ =0x03000790
	cmp r0, #0
	beq _08237D1E
	cmp r3, r4
	beq _08237D1E
	ldr r1, _08237DA0 @ =0x030007A0
	ldr r2, _08237DA4 @ =0x03000788
	ldr r0, [r2]
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #1
	movs r1, #0x3f
	ands r0, r1
	str r0, [r2]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_08237D1E:
	ldr r0, [r6]
	cmp r0, #0x3e
	ble _08237D2A
	movs r0, #0x80
	lsls r0, r0, #7
	orrs r5, r0
_08237D2A:
	ldr r6, _08237DA8 @ =0x0300079C
	ldr r4, [r6]
	cmp r4, #0
	ble _08237D5A
	movs r0, #0x80
	lsls r0, r0, #7
	ands r3, r0
	cmp r3, #0
	bne _08237D5A
	ldr r0, _08237DAC @ =0x030007E0
	ldr r2, _08237DB0 @ =0x03000798
	ldr r1, [r2]
	adds r0, r1, r0
	ldrb r0, [r0]
	orrs r5, r0
	adds r1, #1
	movs r0, #0x3f
	ands r1, r0
	str r1, [r2]
	subs r0, r4, #1
	str r0, [r6]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r5, r0
_08237D5A:
	ldr r0, _08237DB4 @ =0x0000FFFF
	cmp r5, r0
	bne _08237D64
	movs r5, #0x80
	lsls r5, r5, #8
_08237D64:
	ldr r0, _08237DB8 @ =0x0400012A
	strh r5, [r0]
	ldr r2, _08237DBC @ =0x030046CC
	ldr r1, [r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08237D8C
	ldr r0, _08237DC0 @ =0x04000128
	ldrh r0, [r0]
	lsrs r0, r0, #4
	movs r1, #3
	ands r0, r1
	str r0, [r2]
	cmp r0, #1
	beq _08237D8C
	ldr r1, _08237DC4 @ =0x030046D4
	movs r0, #5
	rsbs r0, r0, #0
_08237D8A:
	str r0, [r1]
_08237D8C:
	ldr r1, _08237DC8 @ =0x030046C8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08237D9C: .4byte 0x03000790
_08237DA0: .4byte 0x030007A0
_08237DA4: .4byte 0x03000788
_08237DA8: .4byte 0x0300079C
_08237DAC: .4byte 0x030007E0
_08237DB0: .4byte 0x03000798
_08237DB4: .4byte 0x0000FFFF
_08237DB8: .4byte 0x0400012A
_08237DBC: .4byte 0x030046CC
_08237DC0: .4byte 0x04000128
_08237DC4: .4byte 0x030046D4
_08237DC8: .4byte 0x030046C8
