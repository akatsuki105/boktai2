	push {lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823D73A
	bl VM_GetPC
	cmp r0, #0
	beq _0823D73A
	bl VM_ParseStringRef
	bl Textbox_LookupString
	ldr r2, _0823D740 @ =0x030047D8
	ldrb r1, [r0, #1]
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	ldr r3, _0823D744 @ =0x00000FFF
	adds r0, r3, #0
	ands r1, r0
	strh r1, [r2]
_0823D73A:
	pop {r0}
	bx r0
	.align 2, 0
_0823D740: .4byte 0x030047D8
_0823D744: .4byte 0x00000FFF
