	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r2, _080C0730 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0x84
	orrs r0, r1
	ldr r1, _080C0734 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xe
	adds r4, r0, #0
	orrs r4, r1
	ands r5, r2
	movs r0, #0xd6
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080C0738 @ =0x0000A8E7
	bl Video_GetAuxSprite
	movs r7, #0
	movs r6, #0x94
	lsls r6, r6, #2
	add r6, r8
_080C0718:
	adds r0, r6, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x11
	bl AuxSprite_Add
	cmp r7, #1
	bgt _080C073C
	adds r0, r7, #3
	b _080C073E
	.align 2, 0
_080C0730: .4byte 0xFFFF0000
_080C0734: .4byte 0x0000FFFF
_080C0738: .4byte 0x0000A8E7
_080C073C:
	adds r0, r7, #5
_080C073E:
	strh r0, [r6, #0x10]
	str r4, [r6, #0x1c]
	str r5, [r6, #0x20]
	movs r0, #1
	strb r0, [r6, #7]
	adds r1, r4, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C076C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r6, #0x2c
	adds r7, #1
	cmp r7, #5
	ble _080C0718
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C076C: .4byte 0xFFFF0000
