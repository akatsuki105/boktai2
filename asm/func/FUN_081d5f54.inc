	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldrb r1, [r0, #6]
	cmp r1, #0x80
	ble _081D5F68
	ldr r0, _081D5F64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081D5F76
	.align 2, 0
_081D5F64: .4byte 0xFFFFFF00
_081D5F68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081D5F76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081D5F76:
	adds r5, r1, #0
	cmp r5, #0
	bne _081D5F8C
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081D5F8C
	b _081D60C0
_081D5F8C:
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r3, _081D5FBC @ =0x085B0A08
	mov r0, ip
	ldrb r2, [r0, #6]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r0, #0
	blt _081D5FC0
	asrs r0, r0, #0xc
	b _081D5FC6
	.align 2, 0
_081D5FBC: .4byte 0x085B0A08
_081D5FC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FC6:
	adds r2, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D5FE4
	asrs r0, r0, #0xc
	b _081D5FEA
_081D5FE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FEA:
	adds r7, r2, r0
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D600A
	asrs r0, r0, #0xc
	b _081D600E
_081D600A:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D600E:
	adds r3, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D6034
	asrs r2, r0, #0xc
	b _081D603A
_081D6034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D603A:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r0, r0, r7
	mov r1, ip
	strh r0, [r1, #0x1c]
	movs r1, #0x8c
	lsls r1, r1, #1
	add r1, ip
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x20]
	movs r1, #0x8e
	lsls r1, r1, #1
	add r1, ip
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _081D6080
	cmp r5, #0
	ble _081D6076
	mov r1, ip
	ldrb r0, [r1, #6]
	subs r0, #1
	strb r0, [r1, #6]
	b _081D60C0
_081D6076:
	mov r2, ip
	ldrb r0, [r2, #6]
	adds r0, #1
	strb r0, [r2, #6]
	b _081D60C0
_081D6080:
	mov r3, ip
	ldrb r0, [r3, #6]
	adds r0, r2, r0
	strb r0, [r3, #6]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _081D609A
	cmp r5, r0
	ble _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	b _081D60C0
_081D609A:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r5, r0
	bge _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _081D60B2
	asrs r1, r0, #1
	b _081D60B8
_081D60B2:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081D60B8:
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
_081D60C0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
