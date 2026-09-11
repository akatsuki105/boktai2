	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r0, _08017A70 @ =0x03000070
	str r5, [r0]
	strh r1, [r5, #0x18]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x1a]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x1c]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08017A74
	bl Script_GetValue
	strb r0, [r5, #0x1e]
	bl Script_GetValue
	b _08017A7A
	.align 2, 0
_08017A70: .4byte 0x03000070
_08017A74:
	movs r0, #0
	strb r0, [r5, #0x1e]
	movs r0, #0xa0
_08017A7A:
	strb r0, [r5, #0x1f]
	movs r0, #0x73
	movs r1, #8
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r4, #0
	strh r4, [r5, #0x26]
	movs r0, #0x6f
	movs r1, #2
	bl VM_GetKeywordValue
	strh r0, [r5, #0x20]
	strh r4, [r5, #0x22]
	movs r0, #0x69
	movs r1, #5
	bl VM_GetKeywordValue
	adds r1, r0, #0
	strh r1, [r5, #0x24]
	strh r4, [r5, #0x2c]
	movs r1, #1
	str r1, [r5, #0x28]
	movs r2, #0
	ldr r1, _08017B00 @ =0x0000011F
	mov sl, r1
	movs r1, #0x7f
	mov sb, r1
	ldr r1, _08017B04 @ =0x085B0A08
	mov r8, r1
	movs r1, #0xff
	mov ip, r1
	adds r6, r5, #0
	adds r6, #0x2e
_08017ABE:
	movs r4, #0
	lsls r1, r2, #3
	adds r5, r2, #1
	adds r1, r1, r2
	lsls r3, r1, #6
_08017AC8:
	adds r1, r4, #0
	mov r2, sb
	ands r1, r2
	mov r2, ip
	ands r1, r2
	lsls r1, r1, #1
	add r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r7, r1
	asrs r1, r1, #0xc
	adds r2, r6, r3
	strh r1, [r2]
	adds r3, #2
	adds r4, #1
	cmp r4, sl
	ble _08017AC8
	adds r2, r5, #0
	cmp r2, #0
	ble _08017ABE
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017B00: .4byte 0x0000011F
_08017B04: .4byte 0x085B0A08
