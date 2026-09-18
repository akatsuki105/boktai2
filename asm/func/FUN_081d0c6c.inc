	push {r4, lr}
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	bl Entity081d0e20_FindElem
	adds r2, r0, #0
	cmp r2, #0
	beq _081D0CE6
	cmp r4, #0
	beq _081D0C94
	cmp r4, #1
	beq _081D0CC0
	b _081D0CE6
_081D0C94:
	adds r3, r2, #0
	adds r3, #0xb8
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _081D0CE6
	movs r0, #0x40
	orrs r0, r1
	ldr r1, _081D0CBC @ =0x0000FFDF
	ands r0, r1
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb6
	movs r0, #6
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	b _081D0CE6
	.align 2, 0
_081D0CBC: .4byte 0x0000FFDF
_081D0CC0:
	adds r3, r2, #0
	adds r3, #0xb8
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _081D0CE6
	movs r0, #0x20
	orrs r0, r1
	ldr r1, _081D0CEC @ =0x0000FFBF
	ands r0, r1
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb6
	movs r0, #3
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xba
	strb r4, [r0]
_081D0CE6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D0CEC: .4byte 0x0000FFBF
