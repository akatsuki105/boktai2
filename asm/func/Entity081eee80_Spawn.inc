	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	adds r7, r3, #0
	cmp r0, #0
	bne _081EEC8C
	b _081EEDBC
_081EEC8C:
	ldr r0, _081EED40 @ =0x030001D8
	ldr r4, [r0]
	cmp r4, #0
	bne _081EECA0
	bl Entity081eee80_Create
	adds r4, r0, #0
	cmp r4, #0
	bne _081EECA0
	b _081EEDBC
_081EECA0:
	adds r0, r4, #0
	bl Entity081eee80_FindFreeElem
	adds r6, r0, #0
	cmp r6, #0
	bne _081EECAE
	b _081EEDBC
_081EECAE:
	adds r5, r6, #0
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Setup
	movs r2, #0
	strh r2, [r5, #0x10]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	mov r0, sb
	strb r0, [r5, #7]
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #1
	strb r0, [r1]
	strh r2, [r5, #0x38]
	adds r0, r5, #0
	adds r0, #0x34
	strb r7, [r0]
	ldr r4, _081EED44 @ =0x0203B400
	ldr r2, _081EED48 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _081EED4C @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	add r0, sl
	adds r1, r5, #0
	adds r1, #0x35
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #1
	strh r0, [r5, #0x36]
	adds r3, r5, #0
	adds r3, #0x2c
	ldr r2, _081EED50 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _081EED54
	asrs r1, r0, #0xc
	b _081EED5A
	.align 2, 0
_081EED40: .4byte 0x030001D8
_081EED44: .4byte 0x0203B400
_081EED48: .4byte 0x030046B8
_081EED4C: .4byte 0x000003FF
_081EED50: .4byte gSineTable
_081EED54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081EED5A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081EED7C @ =gSineTable
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _081EED80
	asrs r0, r0, #0xc
	b _081EED86
	.align 2, 0
_081EED7C: .4byte gSineTable
_081EED80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081EED86:
	strh r0, [r3, #4]
	ldr r2, _081EEDCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081EEDD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081EEDD4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r6, #0x2e]
	adds r1, r6, #0
	adds r1, #0x3d
	ldr r0, [sp, #0x24]
	strb r0, [r1]
	ldr r0, [sp, #0x28]
	cmp r0, #0
	ble _081EEDBC
	ldr r0, [r5, #0xc]
	ldr r2, [sp, #0x28]
	ldr r3, _081EEDD8 @ =0x00000113
	adds r1, r2, r3
	bl Video_SetAuxSpritePltt
_081EEDBC:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EEDCC: .4byte 0x030046B8
_081EEDD0: .4byte 0x000003FF
_081EEDD4: .4byte 0x0203B400
_081EEDD8: .4byte 0x00000113
