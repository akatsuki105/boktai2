	push {lr}
	adds r2, r0, #0
	ldr r0, _08223D54 @ =0x00000F44
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08223D64
	ldr r3, _08223D58 @ =0x00000F54
	adds r0, r2, r3
	str r1, [r0]
	ldr r0, _08223D5C @ =0x030047E0
	ldrb r0, [r0, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08223D60
	movs r0, #0x90
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08223D64
	.align 2, 0
_08223D54: .4byte 0x00000F44
_08223D58: .4byte 0x00000F54
_08223D5C: .4byte 0x030047E0
_08223D60:
	bl GetHour
_08223D64:
	pop {r0}
	bx r0
