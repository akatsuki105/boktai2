	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r1, #0
	ldr r3, _080C3898 @ =0x00001904
	adds r1, r0, r3
	ldr r3, _080C389C @ =0x000025BE
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r1, [r1]
	adds r5, r1, r0
	cmp r2, #0x1f
	ble _080C38A8
	ldr r1, _080C38A0 @ =0x03004250
	ldr r2, _080C38A4 @ =0x04000010
	adds r0, r5, #0
	bl CpuSet
	b _080C38FC
	.align 2, 0
_080C3898: .4byte 0x00001904
_080C389C: .4byte 0x000025BE
_080C38A0: .4byte 0x03004250
_080C38A4: .4byte 0x04000010
_080C38A8:
	adds r4, r2, #0
	movs r0, #0
	movs r1, #0x1f
	mov r8, r1
	ldr r3, _080C3908 @ =0x03004250
	mov sb, r3
_080C38B4:
	movs r6, #0
	lsls r7, r0, #5
	adds r0, #1
	mov ip, r0
_080C38BC:
	ldrh r0, [r5]
	movs r2, #0x1f
	ands r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x15
	mov r3, r8
	ands r1, r3
	lsrs r0, r0, #0x1a
	ands r0, r3
	adds r3, r2, #0
	muls r3, r4, r3
	asrs r3, r3, #5
	adds r2, r1, #0
	muls r2, r4, r2
	asrs r2, r2, #5
	muls r0, r4, r0
	asrs r0, r0, #5
	lsls r1, r6, #1
	adds r1, r1, r7
	add r1, sb
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r3
	strh r0, [r1]
	adds r5, #2
	adds r6, #1
	cmp r6, #0xf
	ble _080C38BC
	mov r0, ip
	cmp r0, #1
	ble _080C38B4
_080C38FC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3908: .4byte 0x03004250
