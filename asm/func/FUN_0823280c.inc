	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _08232844 @ =0x030046A4
	ldr r4, [r0]
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _08232880
	adds r5, r0, #0
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232840
	cmp r1, #0
	blt _08232840
	ldr r0, _08232848 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232840
	ldr r0, _0823284C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232850
_08232840:
	movs r0, #0
	b _0823285C
	.align 2, 0
_08232844: .4byte 0x030046A4
_08232848: .4byte 0x030046A8
_0823284C: .4byte 0x030046AC
_08232850:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
_0823285C:
	strh r0, [r3, #6]
	strh r0, [r3, #4]
	ldrh r0, [r3, #6]
	lsls r0, r0, #2
	adds r0, #0xc
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r2, #0xf
	ands r2, r1
	strb r2, [r3, #9]
	ldrb r1, [r0]
	lsrs r1, r1, #4
	strb r1, [r3, #0xb]
	ldrh r0, [r0, #2]
	strh r0, [r3, #0xe]
	strb r2, [r3, #8]
	strb r1, [r3, #0xa]
	strh r0, [r3, #0xc]
_08232880:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
